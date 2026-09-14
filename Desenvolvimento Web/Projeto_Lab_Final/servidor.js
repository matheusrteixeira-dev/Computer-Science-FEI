// Projeto final de laboratório - Sistema de biblioteca com cadastro/login de usuários e
// cadastro de livros, usando Express, EJS e MongoDB (Mongoose).
const path = require('path');
const express = require('express');
const mongoose = require('mongoose');

const PORTA = 8080;
const app = express();

mongoose.connect('mongodb://localhost/banco', { useNewUrlParser: true, useUnifiedTopology: true });

// Observação: por se tratar de um projeto didático, a senha é armazenada em texto puro.
// Em uma aplicação real ela deveria ser armazenada com hash (por exemplo, bcrypt).
const usuarioSchema = new mongoose.Schema({
    login: String,
    senha: String,
    nome: String,
});
const Usuario = mongoose.model('usuarios', usuarioSchema);

const livroSchema = new mongoose.Schema({
    titulo: String,
    autor: String,
});
const Livro = mongoose.model('livros', livroSchema);

app.set('view engine', 'ejs');
app.set('views', path.join(__dirname, 'views'));

app.use(express.urlencoded({ extended: false }));
app.use(express.json());
app.use(express.static(path.join(__dirname, 'public')));

// Login
app.get(['/', '/login'], (requisicao, resp) => {
    resp.render('login');
});

app.post('/login', (requisicao, resp) => {
    const { login, senha } = requisicao.body;

    Usuario.findOne({ login, senha }, (erro, usuario) => {
        if (erro) {
            console.error(erro);
            resp.render('login', { mensagem: 'Erro ao consultar o banco de dados.' });
        } else if (usuario) {
            resp.render('home', { nome: usuario.nome });
        } else {
            resp.render('login', { mensagem: 'Login incorreto' });
        }
    });
});

// Cadastro de usuários
app.get('/cadastra', (requisicao, resp) => {
    resp.render('cadastra');
});

app.post('/cadastra', (requisicao, resp) => {
    const { login, senha, nome } = requisicao.body;

    new Usuario({ login, senha, nome }).save((erro) => {
        if (erro) {
            console.error(erro);
        }
        resp.render('cadastra', { mensagem: erro ? 'Algo deu errado...' : 'Usuário cadastrado!' });
    });
});

// Cadastro de livros (disponível na página inicial após o login)
app.post('/cadastraLivro', (requisicao, resp) => {
    const { titulo, autor, nome } = requisicao.body;

    new Livro({ titulo, autor }).save((erro) => {
        if (erro) {
            console.error(erro);
        }
        resp.render('home', {
            nome,
            mensagem: erro ? 'Erro ao cadastrar o livro.' : 'Livro cadastrado!',
        });
    });
});

app.listen(PORTA, () => console.log(`Servidor rodando em http://localhost:${PORTA}`));
