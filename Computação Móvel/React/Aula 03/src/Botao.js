import React, { Component } from 'react';

/** Botão da calculadora: exibe o conteúdo filho e chama a função recebida em `clique`. */
class Botao extends Component {
  render() {
    return (
      <input
        style={{ backgroundColor: 'blue', width: 40, fontSize: '18pt', color: 'white' }}
        type="button"
        value={this.props.children}
        onClick={this.props.clique}
      />
    );
  }
}

export default Botao;
