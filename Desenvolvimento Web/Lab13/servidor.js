// Lab13 - Biblioteca: cadastro, busca e exclusão de livros por autor com Express, EJS e MongoDB
// (enunciado em ../images/lab10.png).
const path = require('path');
const express = require('express');
const mongoose = require('mongoose');

const PORTA = 8080;
const app = express();

mongoose.connect('mongodb://localhost/Ex01', { useNewUrlParser: true, useUnifiedTopology: true });

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

/** Renderiza a página de mensagem genérica. */
function mostraMensagem(resp, mensagem) {
    resp.render('mensagem', { mensagem });
}

/** Busca os autores distintos e renderiza a view informada com a lista, ou uma mensagem se não houver livros. */
function renderizaComAutores(resp, view) {
    Livro.distinct('autor', (erro, autores) => {
        if (erro || autores.length === 0) {
            mostraMensagem(resp, 'Nenhum livro encontrado!');
        } else {
            resp.render(view, { autores });
        }
    });
}

app.get(['/', '/principal'], (req, resp) => {
    resp.render('principal');
});

// Cadastro
app.get('/cadastra', (req, resp) => {
    resp.render('cadastra');
});

app.post('/cadastra', (req, resp) => {
    const { titulo, autor } = req.body;

    new Livro({ titulo, autor }).save((erro) => {
        mostraMensagem(resp, erro ? 'Erro ao cadastrar o livro.' : 'Livro cadastrado!');
    });
});

// Busca por autor
app.get('/buscar', (req, resp) => {
    renderizaComAutores(resp, 'busca');
});

app.post('/buscar', (req, resp) => {
    Livro.find({ autor: req.body.autor }, (erro, livros) => {
        if (erro || livros.length === 0) {
            mostraMensagem(resp, 'Nenhum livro encontrado!');
        } else {
            resp.render('listagem', { livros });
        }
    });
});

// Exclusão por autor
app.get('/deleta', (req, resp) => {
    renderizaComAutores(resp, 'deleta');
});

app.post('/deletar', (req, resp) => {
    Livro.deleteMany({ autor: req.body.autor }, (erro, resultado) => {
        if (erro || resultado.deletedCount === 0) {
            mostraMensagem(resp, 'Nenhum livro encontrado!');
        } else {
            mostraMensagem(resp, `${resultado.deletedCount} livro(s) excluído(s)!`);
        }
    });
});

app.listen(PORTA, () => console.log(`Servidor rodando em http://localhost:${PORTA}`));
