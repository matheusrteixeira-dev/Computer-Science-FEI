// Lab11 - Cadastro, login e listagem de usuários com Express, EJS e MongoDB (Mongoose)
// (enunciado em ../images/lab09.png).
const path = require('path');
const express = require('express');
const mongoose = require('mongoose');

const PORTA = 8080;
const app = express();

mongoose.connect('mongodb://localhost/usuarios', { useNewUrlParser: true, useUnifiedTopology: true });

// Observação: por se tratar de um exercício didático, a senha é armazenada em texto puro.
// Em uma aplicação real ela deveria ser armazenada com hash (por exemplo, bcrypt).
const usuarioSchema = new mongoose.Schema({
    nome: String,
    login: String,
    senha: String,
});
const Usuario = mongoose.model('Usuarios', usuarioSchema);

app.set('view engine', 'ejs');
app.set('views', path.join(__dirname, 'views'));

app.use(express.urlencoded({ extended: false }));
app.use(express.json());
app.use(express.static(path.join(__dirname, 'public')));

app.get(['/', '/index'], (requisicao, resp) => {
    resp.render('index');
});

// Cadastro
app.get('/cadastro', (requisicao, resp) => {
    resp.render('cadastro');
});

app.post('/cadastro', (requisicao, resp) => {
    const { login, nome, senha } = requisicao.body;

    new Usuario({ login, nome, senha }).save((erro) => {
        if (erro) {
            console.error(erro);
            resp.render('cadastro', { mensagem: 'Erro ao cadastrar o usuário.' });
        } else {
            resp.render('cadastro', { mensagem: 'Usuário cadastrado!' });
        }
    });
});

// Login
app.get('/login', (requisicao, resp) => {
    resp.render('login');
});

app.post('/login', (requisicao, resp) => {
    const { login, senha } = requisicao.body;

    Usuario.findOne({ login, senha }, (erro, usuario) => {
        if (erro) {
            console.error(erro);
            resp.render('login', { mensagem: 'Erro ao consultar o banco de dados.' });
        } else {
            resp.render('login', { mensagem: usuario ? 'Acertou!' : 'Errou!' });
        }
    });
});

// Listagem
app.get('/lista', (requisicao, resp) => {
    Usuario.find((erro, usuarios) => {
        if (erro) {
            console.error(erro);
        }
        resp.render('lista', { usuarios: usuarios || [] });
    });
});

app.listen(PORTA, () => console.log(`Servidor rodando em http://localhost:${PORTA}`));
