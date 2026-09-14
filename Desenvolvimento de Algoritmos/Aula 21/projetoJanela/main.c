/*
 * Aula 21 - Interface gráfica com a biblioteca IUP: janela com duas caixas de texto
 * e um botão que abre uma nova janela.
 * Baseado no projeto de exemplo (CLion + IUP) fornecido pelo professor da disciplina.
 */
#include <iup.h>
#include <stdlib.h>

/* Callback do botão: abre uma nova janela com uma caixa de texto. */
int abreNovaJanela(Ihandle *botao) {
    (void) botao;
    Ihandle *nova = IupDialog(IupText(NULL));
    IupShow(nova);
    return IUP_DEFAULT;
}

int main(int argc, char **argv) {
    IupOpen(&argc, &argv);

    Ihandle *cxTexto1 = IupText(NULL);
    Ihandle *cxTexto2 = IupText(NULL);
    Ihandle *btnOk = IupButton("Clique Aqui", NULL);
    IupSetCallback(btnOk, "ACTION", (Icallback) abreNovaJanela);

    IupSetAttribute(cxTexto1, "EXPAND", "YES");
    IupSetAttribute(cxTexto2, "EXPAND", "YES");
    IupSetAttribute(cxTexto2, "MULTILINE", "YES");

    Ihandle *grupo = IupVbox(cxTexto1, cxTexto2, btnOk, NULL);
    Ihandle *janela = IupDialog(grupo);
    IupShow(janela);

    IupMainLoop();

    IupClose();
    return EXIT_SUCCESS;
}
