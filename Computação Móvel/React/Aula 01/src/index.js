// Aula 01 - Primeiro contato com React: página estática escrita em JSX.
import React from 'react';
import ReactDOM from 'react-dom';

const pagina = (
  <section style={{ display: 'flex', flexDirection: 'column' }}>
    <header style={{ backgroundColor: 'beige' }}>
      <h1>CC4670 - Computação Móvel</h1>
      <h2>React</h2>
      <h3>Biblioteca JavaScript para criar interfaces com o usuário</h3>
      <p>Primeira Aula</p>
    </header>

    <div style={{ backgroundColor: 'yellow' }}>
      <h1>Vamos utilizar:</h1>
      <ul>
        <li><h2>HTML</h2></li>
        <li><h2>CSS</h2></li>
        <li><h2>JavaScript</h2></li>
      </ul>
    </div>
  </section>
);

ReactDOM.render(pagina, document.getElementById('root'));
