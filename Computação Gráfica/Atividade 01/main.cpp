/**
 * @file    main.cpp
 * @brief   Programa OpenGL básico: projeção ortográfica 2D de um triângulo com freeglut.
 * @note    Baseado no código de demonstração fornecido pelo professor da disciplina.
 */

#include <GL/freeglut.h>

// Dimensões iniciais da janela (em pixels).
const int LARGURA = 400;
const int ALTURA = 400;

/// Callback de desenho: limpa a tela e desenha um triângulo vermelho.
void Desenha() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glColor3d(1, 0, 0);
    glBegin(GL_TRIANGLES);
    glVertex2d(0, 100);
    glVertex2d(-100, -100);
    glVertex2d(100, -100);
    glEnd();

    // Troca os buffers (modo de buffer duplo).
    glutSwapBuffers();
}

/// Define a cor de fundo da janela como branca.
void Inicializa() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

/// Callback de redimensionamento: ajusta a viewport e a projeção ortográfica 2D.
void AjusteDeJanela(GLsizei w, GLsizei h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-200, 200, -200, 200);
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(LARGURA, ALTURA);
    glutInitWindowPosition(10, 10);
    glutCreateWindow("Triangulo");
    glutDisplayFunc(Desenha);
    glutReshapeFunc(AjusteDeJanela);
    Inicializa();
    glutMainLoop();
    return 0;
}
