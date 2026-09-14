// Lab09 - Cadastro de usuários em memória com Express e EJS (enunciado em ../images/lab09.png).
const path = require('path');
const express = require('express');

const PORTA = 8080;
const app = express();

// Usuários cadastrados (mantidos apenas em memória).
let lista = [];

app.set('view engine', 'ejs');
app.set('views', path.join(__dirname, 'views'));

app.use(express.urlencoded({ extended: false }));
app.use(express.json());
app.use(express.static(path.join(__dirname, 'public')));

app.get(['/', '/index'], (requisicao, resp) => {
    resp.render('index');
});

// Adiciona um usuário à lista e exibe todos os cadastrados.
app.post('/lista', (requisicao, resp) => {
    const { login, nome, senha } = requisicao.body;
    lista.push({ login, nome, senha });
    resp.render('lista', { lista });
});

// Limpa a lista e volta ao formulário de cadastro.
app.get('/limpa', (requisicao, resp) => {
    lista = [];
    resp.render('index');
});

app.listen(PORTA, () => console.log(`Servidor rodando em http://localhost:${PORTA}`));
