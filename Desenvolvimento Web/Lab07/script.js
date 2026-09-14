// Cadastro de alunos com cálculo da nota final (enunciado em ../images/lab06.png).

/** Lê o formulário, cria um objeto aluno e adiciona uma linha à tabela. */
function cadastrar() {
    const aluno = {
        nome: document.getElementById("nome").value,
        lab: parseFloat(document.getElementById("lab").value),
        projeto: parseFloat(document.getElementById("projeto").value),
        prova: parseFloat(document.getElementById("prova").value),

        /** Média ponderada: lab (peso 1), projeto (peso 2) e prova (peso 3). */
        calculaNota() {
            return (this.lab + 2 * this.projeto + 3 * this.prova) / 6;
        },

        /** Insere o aluno como uma nova linha da tabela. */
        imprime() {
            const linha = document.querySelector("#tabela tbody").insertRow();
            const valores = [this.nome, this.projeto, this.prova, this.lab, this.calculaNota().toFixed(2)];
            for (const valor of valores) {
                // textContent evita a interpretação de HTML digitado pelo usuário.
                linha.insertCell().textContent = valor;
            }
        },
    };

    aluno.imprime();
}
