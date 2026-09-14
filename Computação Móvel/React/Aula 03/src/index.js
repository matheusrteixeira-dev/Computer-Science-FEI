// Aula 03 - Calculadora em React com componentes de classe.
// Cada operação é encapsulada em uma classe com o método calcula(a, b).
import React from 'react';
import ReactDOM from 'react-dom';

import Botao from './Botao';
import Divisao from './Divisao';
import Multiplicacao from './Multiplicacao';
import Soma from './Soma';
import Subtracao from './Subtracao';

import './index.css';

class App extends React.Component {
  constructor(props) {
    super(props);
    this.state = {
      texto: '',
      numero1: undefined,
      numero2: undefined,
      operacao: undefined,
    };
  }

  /** Limpa o visor. */
  clear() {
    this.setState({ texto: '' });
  }

  /** Acrescenta um dígito ao visor. */
  pressionar(num) {
    this.setState({ texto: this.state.texto + String(num) });
  }

  /** Guarda o primeiro operando e a operação escolhida, e limpa o visor. */
  selecionarOperacao(operacao) {
    this.setState({
      numero1: parseInt(this.state.texto, 10),
      operacao,
      texto: '',
    });
  }

  /** Lê o segundo operando e exibe o resultado da operação. */
  resultado() {
    if (!this.state.operacao) {
      return;
    }
    const numero2 = parseInt(this.state.texto, 10);
    this.setState({
      numero2,
      texto: String(this.state.operacao.calcula(this.state.numero1, numero2)),
    });
  }

  render() {
    return (
      <div className="center">
        <h1>Calculadora</h1>
        <table>
          <tbody>
            <tr>
              <td colSpan={4}>
                <input
                  style={{ width: 170, fontSize: '18pt' }}
                  type="text"
                  value={this.state.texto}
                  readOnly
                />
              </td>
            </tr>
            <tr>
              <td><Botao clique={() => this.pressionar(7)}>7</Botao></td>
              <td><Botao clique={() => this.pressionar(8)}>8</Botao></td>
              <td><Botao clique={() => this.pressionar(9)}>9</Botao></td>
              <td><Botao clique={() => this.selecionarOperacao(new Divisao())}>/</Botao></td>
            </tr>
            <tr>
              <td><Botao clique={() => this.pressionar(4)}>4</Botao></td>
              <td><Botao clique={() => this.pressionar(5)}>5</Botao></td>
              <td><Botao clique={() => this.pressionar(6)}>6</Botao></td>
              <td><Botao clique={() => this.selecionarOperacao(new Multiplicacao())}>X</Botao></td>
            </tr>
            <tr>
              <td><Botao clique={() => this.pressionar(1)}>1</Botao></td>
              <td><Botao clique={() => this.pressionar(2)}>2</Botao></td>
              <td><Botao clique={() => this.pressionar(3)}>3</Botao></td>
              <td><Botao clique={() => this.selecionarOperacao(new Subtracao())}>-</Botao></td>
            </tr>
            <tr>
              <td><Botao clique={() => this.clear()}>C</Botao></td>
              <td><Botao clique={() => this.pressionar(0)}>0</Botao></td>
              <td><Botao clique={() => this.resultado()}>=</Botao></td>
              <td><Botao clique={() => this.selecionarOperacao(new Soma())}>+</Botao></td>
            </tr>
          </tbody>
        </table>
      </div>
    );
  }
}

ReactDOM.render(<App />, document.getElementById('root'));
