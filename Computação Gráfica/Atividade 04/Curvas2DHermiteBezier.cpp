/**
 * @file    Curvas2DHermiteBezier.cpp
 * @brief   Plotagem interativa de curvas 2D em OpenGL (freeglut):
 *            - uma parábola simples (exemplo de plotagem de curva);
 *            - uma curva de Hermite de grau 3, com tangentes fixas e dois pontos clicados;
 *            - uma curva de Bézier de grau 3, com quatro pontos de controle clicados.
 * @note    Baseado em código-base fornecido pelo professor da disciplina (aula de 04/09/2020).
 *
 * Controles:
 *   botão esquerdo  - adiciona um ponto
 *   botão direito   - limpa os pontos
 *   B / H / P       - alterna entre Bézier, Hermite e parábola
 *   ESC             - encerra o programa
 */

#include <GL/freeglut.h>

#include <cstdlib>

// Domínio cartesiano usado pela parábola e pelos eixos.
const GLfloat MAIORX = 200.0f;
const GLfloat MENORX = -200.0f;
const GLfloat MAIORY = 200.0f;
const GLfloat MENORY = -200.0f;

// Domínio cartesiano usado pelas curvas de Bézier e Hermite (coincide com os pixels da janela).
const GLfloat MAIORX_CURVAS = 400.0f;
const GLfloat MENORX_CURVAS = 0.0f;
const GLfloat MAIORY_CURVAS = 400.0f;
const GLfloat MENORY_CURVAS = 0.0f;

// Dimensões e posição inicial da janela.
const int LARGURA_JANELA = 400;
const int ALTURA_JANELA = 400;
const int POSICAO_X = 250;
const int POSICAO_Y = 150;

// Tangentes de entrada e saída da curva de Hermite.
const GLfloat TANG1_X = 10.0f;
const GLfloat TANG1_Y = -145.0f;
const GLfloat TANG2_X = 10.0f;
const GLfloat TANG2_Y = -185.0f;

// Número de segmentos usados para discretizar as curvas (t varia de 0 a 1).
const int NUM_SEGMENTOS = 100;

enum class Modo { Bezier, Hermite, Parabola };

Modo modoAtual = Modo::Bezier;

GLfloat B[4][2]; // pontos de controle da curva de Bézier
GLfloat P[2][4]; // pontos e tangentes da curva de Hermite: {x, y, tx, ty}

bool capturandoPontos = false; // true quando há um clique pendente de ser registrado
int totalPontos = 0;           // total de pontos registrados na curva atual
GLfloat bx, by;                // coordenadas do último clique

void Inicializa();
void AlteraTamanhoJanela(GLsizei w, GLsizei h);
void Teclado(unsigned char key, int x, int y);
void Desenha();
void Mouse(int button, int state, int x, int y);

GLfloat multiplicaMatrizes(const GLfloat T[4], const GLfloat H[4][4], const GLfloat M[4]);
void DesenhaParabola();
void DesenhaHermiteGrau3();
void DesenhaBezierGrau3();
void DesenhaEixos();
void DesenhaPontosDeControle(GLfloat pontos[][2], int n);

int main(int argc, char **argv) {
    glutInit(&argc, argv);

    // Buffer único e cores RGB: o desenho é 2D e sem animação.
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(POSICAO_X, POSICAO_Y);
    glutInitWindowSize(LARGURA_JANELA, ALTURA_JANELA);
    glutCreateWindow("Curvas de Bezier e Hermite");

    glutDisplayFunc(Desenha);
    glutReshapeFunc(AlteraTamanhoJanela);
    glutKeyboardFunc(Teclado);
    glutMouseFunc(Mouse);

    Inicializa();
    glutMainLoop();

    return 0;
}

/// Callback de desenho: delega para a curva selecionada.
void Desenha() {
    glClear(GL_COLOR_BUFFER_BIT);

    switch (modoAtual) {
    case Modo::Bezier:
        DesenhaBezierGrau3();
        break;
    case Modo::Hermite:
        DesenhaHermiteGrau3();
        break;
    case Modo::Parabola:
        DesenhaEixos();
        DesenhaParabola();
        break;
    }

    glFlush();
}

/// Desenha os eixos cartesianos no domínio [MENORX, MAIORX] x [MENORY, MAIORY].
void DesenhaEixos() {
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex2f(0.0f, MENORY);
    glVertex2f(0.0f, MAIORY);
    glVertex2f(MENORX, 0.0f);
    glVertex2f(MAIORX, 0.0f);
    glEnd();
}

/// Desenha os @p n pontos de controle em vermelho.
void DesenhaPontosDeControle(GLfloat pontos[][2], int n) {
    glColor3f(1.0f, 0.0f, 0.0f);
    glPointSize(5.0f);
    glBegin(GL_POINTS);
    for (int i = 0; i < n; i++) {
        glVertex2f(pontos[i][0], pontos[i][1]);
    }
    glEnd();
}

/**
 * Curva de Hermite de grau 3: dois pontos fornecidos pelo mouse e tangentes fixas.
 * Cada coordenada é calculada por T * H * G, com G = {P1, P2, R1, R2}.
 */
void DesenhaHermiteGrau3() {
    const GLfloat H[4][4] = {{2.0f, -2.0f, 1.0f, 1.0f},
                             {-3.0f, 3.0f, -2.0f, -1.0f},
                             {0.0f, 0.0f, 1.0f, 0.0f},
                             {1.0f, 0.0f, 0.0f, 0.0f}};

    if (capturandoPontos && totalPontos < 2) {
        bool pontoNovo = totalPontos == 0 || P[totalPontos - 1][0] != bx || P[totalPontos - 1][1] != by;
        if (pontoNovo) {
            P[totalPontos][0] = bx;
            P[totalPontos][1] = by;
            P[totalPontos][2] = totalPontos == 0 ? TANG1_X : TANG2_X;
            P[totalPontos][3] = totalPontos == 0 ? TANG1_Y : TANG2_Y;
            totalPontos++;
        }
    }

    GLfloat pontos[2][2];
    for (int i = 0; i < totalPontos; i++) {
        pontos[i][0] = P[i][0];
        pontos[i][1] = P[i][1];
    }
    DesenhaPontosDeControle(pontos, totalPontos);

    if (totalPontos == 2) {
        const GLfloat G[2][4] = {{P[0][0], P[1][0], P[0][2], P[1][2]},
                                 {P[0][1], P[1][1], P[0][3], P[1][3]}};

        glColor3f(0.0f, 0.0f, 1.0f);
        glBegin(GL_LINE_STRIP);
        for (int i = 0; i <= NUM_SEGMENTOS; i++) {
            GLfloat t = static_cast<GLfloat>(i) / NUM_SEGMENTOS;
            GLfloat T[4] = {t * t * t, t * t, t, 1.0f};
            glVertex2f(multiplicaMatrizes(T, H, G[0]), multiplicaMatrizes(T, H, G[1]));
        }
        glEnd();
    }
}

/// Curva de Bézier de grau 3: quatro pontos de controle fornecidos pelo mouse.
void DesenhaBezierGrau3() {
    const GLfloat H[4][4] = {{-1.0f, 3.0f, -3.0f, 1.0f},
                             {3.0f, -6.0f, 3.0f, 0.0f},
                             {-3.0f, 3.0f, 0.0f, 0.0f},
                             {1.0f, 0.0f, 0.0f, 0.0f}};

    if (capturandoPontos && totalPontos < 4) {
        bool pontoNovo = totalPontos == 0 || B[totalPontos - 1][0] != bx || B[totalPontos - 1][1] != by;
        if (pontoNovo) {
            B[totalPontos][0] = bx;
            B[totalPontos][1] = by;
            totalPontos++;
        }
    }

    DesenhaPontosDeControle(B, totalPontos);

    if (totalPontos == 4) {
        const GLfloat G[2][4] = {{B[0][0], B[1][0], B[2][0], B[3][0]},
                                 {B[0][1], B[1][1], B[2][1], B[3][1]}};

        glColor3f(0.0f, 0.0f, 1.0f);
        glBegin(GL_LINE_STRIP);
        for (int i = 0; i <= NUM_SEGMENTOS; i++) {
            GLfloat t = static_cast<GLfloat>(i) / NUM_SEGMENTOS;
            GLfloat T[4] = {t * t * t, t * t, t, 1.0f};
            glVertex2f(multiplicaMatrizes(T, H, G[0]), multiplicaMatrizes(T, H, G[1]));
        }
        glEnd();
    }
}

/// Desenha a parábola y = a*x^2 + b*x + c para x em [-50, 50].
void DesenhaParabola() {
    const GLfloat passo = 0.2f; // discretização
    const GLfloat a = 0.03f;    // coeficiente de x^2
    const GLfloat b = 0.0f;     // coeficiente de x
    const GLfloat c = -20.0f;   // termo independente

    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_STRIP);
    for (GLfloat x = -50.0f; x <= 50.0f; x += passo) {
        glVertex2f(x, a * x * x + b * x + c);
    }
    glEnd();
}

/// Callback de redimensionamento: mantém a proporção entre a janela e o domínio das curvas.
void AlteraTamanhoJanela(GLsizei w, GLsizei h) {
    if (h == 0) {
        h = 1; // evita divisão por zero
    }

    GLfloat largura = static_cast<GLfloat>(w);
    GLfloat altura = static_cast<GLfloat>(h);

    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if (modoAtual == Modo::Parabola) {
        if (largura <= altura) {
            gluOrtho2D(MENORX, MAIORX, MENORY * altura / largura, MAIORY * altura / largura);
        } else {
            gluOrtho2D(MENORX * largura / altura, MAIORX * largura / altura, MENORY, MAIORY);
        }
    } else {
        if (largura <= altura) {
            gluOrtho2D(MENORX_CURVAS, MAIORX_CURVAS, MENORY_CURVAS * altura / largura,
                       MAIORY_CURVAS * altura / largura);
        } else {
            gluOrtho2D(MENORX_CURVAS * largura / altura, MAIORX_CURVAS * largura / altura,
                       MENORY_CURVAS, MAIORY_CURVAS);
        }
    }
}

/// Callback de teclado: troca a curva exibida ou encerra o programa.
void Teclado(unsigned char key, int, int) {
    switch (key) {
    case 27: // ESC
        exit(0);
    case 'b':
    case 'B':
        modoAtual = Modo::Bezier;
        break;
    case 'h':
    case 'H':
        modoAtual = Modo::Hermite;
        break;
    case 'p':
    case 'P':
        modoAtual = Modo::Parabola;
        break;
    default:
        return;
    }

    totalPontos = 0;
    capturandoPontos = false;
    AlteraTamanhoJanela(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
    glutPostRedisplay();
}

/// Inicializa a cor de fundo como branca.
void Inicializa() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

/// Callback de mouse: botão esquerdo registra um ponto; botão direito limpa os pontos.
void Mouse(int button, int state, int x, int y) {
    if (state != GLUT_DOWN) {
        return;
    }

    switch (button) {
    case GLUT_LEFT_BUTTON:
        // O eixo y da janela cresce para baixo; o do OpenGL, para cima.
        bx = static_cast<GLfloat>(x);
        by = static_cast<GLfloat>(glutGet(GLUT_WINDOW_HEIGHT) - y);
        capturandoPontos = true;
        break;
    case GLUT_RIGHT_BUTTON:
        capturandoPontos = false;
        totalPontos = 0;
        break;
    default:
        break;
    }

    glutPostRedisplay();
}

/// Calcula o produto escalar T * (H * M) para uma coordenada da curva.
GLfloat multiplicaMatrizes(const GLfloat T[4], const GLfloat H[4][4], const GLfloat M[4]) {
    GLfloat HM[4];
    for (int i = 0; i < 4; i++) {
        HM[i] = 0.0f;
        for (int j = 0; j < 4; j++) {
            HM[i] += H[i][j] * M[j];
        }
    }

    GLfloat resultado = 0.0f;
    for (int i = 0; i < 4; i++) {
        resultado += T[i] * HM[i];
    }
    return resultado;
}
