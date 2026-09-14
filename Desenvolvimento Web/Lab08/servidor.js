// Lab08 - Servidor Express que entrega páginas HTML estáticas (enunciado em ../images/lab08.png).
const path = require('path');
const express = require('express');

const PORTA = 8080;
const app = express();

// Conteúdo estático (CSS, JavaScript e imagens).
app.use(express.static(path.join(__dirname, 'public')));

app.get('/', (requisicao, resp) => resp.redirect('/pagina1'));

// Rotas /pagina1 a /pagina4: cada uma entrega o arquivo HTML correspondente.
for (let numero = 1; numero <= 4; numero++) {
    app.get(`/pagina${numero}`, (requisicao, resp) => {
        resp.sendFile(path.join(__dirname, 'views', `pagina${numero}.html`));
    });
}

app.listen(PORTA, () => console.log(`Servidor rodando em http://localhost:${PORTA}`));
