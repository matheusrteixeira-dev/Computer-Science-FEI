// Prova - Cadastro e listagem de idosos com Express, EJS e MongoDB (Mongoose).
const path = require('path');
const express = require('express');
const mongoose = require('mongoose');

const PORTA = 8080;
const app = express();

mongoose.connect('mongodb://localhost/exe1', { useNewUrlParser: true, useUnifiedTopology: true });

const idosoSchema = new mongoose.Schema({
    nome: String,
    endereco: String,
    idade: Number,
});
const Idoso = mongoose.model('idosos', idosoSchema);

app.set('view engine', 'ejs');
app.set('views', path.join(__dirname, 'views'));

app.use(express.urlencoded({ extended: false }));
app.use(express.json());

// Formulário de cadastro
app.get(['/', '/index'], (req, resp) => {
    resp.render('index');
});

// Grava o cadastro e exibe os dados informados
app.post('/index', (req, resp) => {
    const { nome, endereco, idade } = req.body;

    new Idoso({ nome, endereco, idade }).save((erro) => {
        if (erro) {
            console.error(erro);
        }
        resp.render('cadastra', {
            mensagem: erro ? 'Usuário não cadastrado' : 'Usuário cadastrado',
            nome,
            endereco,
            idade,
        });
    });
});

// Lista todos os cadastros
app.get('/lista', (req, resp) => {
    Idoso.find((erro, idosos) => {
        if (erro) {
            console.error(erro);
        }
        resp.render('lista', { idosos: idosos || [] });
    });
});

app.listen(PORTA, () => console.log(`Servidor rodando em http://localhost:${PORTA}`));
