/** Abre a página que exibe a imagem ampliada de número `numero` (1 a 3). */
function ampliarImagem(numero) {
    window.location.href = `/pagina${numero + 1}`;
}

/** Retorna à página principal. */
function voltar() {
    alert("Você clicou no botão");
    window.location.href = "/pagina1";
}
