// Desenho com a API Canvas 2D (enunciado em ../images/lab05.png).

const canvas = document.getElementById("canvas");
const ctx = canvas.getContext("2d");

const TAMANHO_QUADRADO = 30;

/** Desenha um quadrado colorido em cada canto do canvas. */
function desenharQuadrados() {
    ctx.clearRect(0, 0, canvas.width, canvas.height);

    const direita = canvas.width - TAMANHO_QUADRADO;
    const inferior = canvas.height - TAMANHO_QUADRADO;

    ctx.fillStyle = "red";
    ctx.fillRect(0, 0, TAMANHO_QUADRADO, TAMANHO_QUADRADO);

    ctx.fillStyle = "blue";
    ctx.fillRect(direita, 0, TAMANHO_QUADRADO, TAMANHO_QUADRADO);

    ctx.fillStyle = "yellow";
    ctx.fillRect(0, inferior, TAMANHO_QUADRADO, TAMANHO_QUADRADO);

    ctx.fillStyle = "green";
    ctx.fillRect(direita, inferior, TAMANHO_QUADRADO, TAMANHO_QUADRADO);
}

/** Traça um segmento de reta de (x1, y1) até (x2, y2) na cor informada. */
function desenharSegmento(cor, x1, y1, x2, y2) {
    ctx.beginPath();
    ctx.strokeStyle = cor;
    ctx.moveTo(x1, y1);
    ctx.lineTo(x2, y2);
    ctx.stroke();
}

/** Desenha as diagonais, a linha horizontal central e a borda do canvas. */
function desenharLinhas() {
    desenharSegmento("red", 0, 0, 300, 300);
    desenharSegmento("blue", 0, 300, 300, 0);
    desenharSegmento("green", 0, 150, 300, 150);

    ctx.strokeStyle = "black";
    ctx.strokeRect(0, 0, canvas.width, canvas.height);
}

/** Desenha um semicírculo central e dois círculos amarelos. */
function desenharArcos() {
    ctx.strokeStyle = "green";
    ctx.fillStyle = "yellow";

    // Semicírculo central (de 0 a PI radianos)
    ctx.beginPath();
    ctx.arc(150, 150, 50, 0, Math.PI);
    ctx.stroke();

    // Círculo da esquerda
    ctx.beginPath();
    ctx.arc(40, 100, 15, 0, 2 * Math.PI);
    ctx.stroke();
    ctx.fill();

    // Círculo da direita
    ctx.beginPath();
    ctx.arc(260, 100, 15, 0, 2 * Math.PI);
    ctx.stroke();
    ctx.fill();
}

/** Escreve o título no canvas. */
function escrever() {
    ctx.fillStyle = "black";
    ctx.font = "22px Arial";
    ctx.fillText("Desenvolvimento Web", 40, 45);
}

function main() {
    desenharQuadrados();
    desenharLinhas();
    desenharArcos();
    escrever();
}

requestAnimationFrame(main);
