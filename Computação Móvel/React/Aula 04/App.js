// Aula 04 - Calculadora em React Native (Expo).
// Cada operação é encapsulada em uma classe com o método calcula(a, b).
import React from 'react';
import { View } from 'react-native';

import Botao from './components/Botao';
import Display from './components/Display';
import Divisao from './Divisao';
import estilos from './estilo';
import Multiplicacao from './Multiplicacao';
import Soma from './Soma';
import Subtracao from './Subtracao';

class App extends React.Component {
  constructor(props) {
    super(props);
    this.state = {
      num1: undefined,
      num2: undefined,
      texto: '',
      operacao: null,
    };
  }

  /** Guarda o primeiro operando e a operação escolhida, e limpa o visor. */
  selecionarOperacao(operacao) {
    this.setState({
      num1: parseInt(this.state.texto, 10),
      operacao,
      texto: '',
    });
  }

  /** Lê o segundo operando e exibe o resultado da operação. */
  resultado() {
    if (!this.state.operacao) {
      return;
    }
    const num2 = parseInt(this.state.texto, 10);
    this.setState({
      num2,
      texto: String(this.state.operacao.calcula(this.state.num1, num2)),
    });
  }

  /** Limpa o visor. */
  clear() {
    this.setState({ texto: '' });
  }

  /** Acrescenta um dígito ao visor. */
  pressionar(num) {
    this.setState({ texto: this.state.texto + String(num) });
  }

  render() {
    return (
      <View style={estilos.container}>
        <Display>{this.state.texto}</Display>
        <View style={estilos.subcontainer}>
          <Botao onPress={() => this.pressionar(7)}>7</Botao>
          <Botao onPress={() => this.pressionar(8)}>8</Botao>
          <Botao onPress={() => this.pressionar(9)}>9</Botao>
          <Botao onPress={() => this.selecionarOperacao(new Multiplicacao())}>*</Botao>
        </View>
        <View style={estilos.subcontainer}>
          <Botao onPress={() => this.pressionar(4)}>4</Botao>
          <Botao onPress={() => this.pressionar(5)}>5</Botao>
          <Botao onPress={() => this.pressionar(6)}>6</Botao>
          <Botao onPress={() => this.selecionarOperacao(new Divisao())}>/</Botao>
        </View>
        <View style={estilos.subcontainer}>
          <Botao onPress={() => this.pressionar(1)}>1</Botao>
          <Botao onPress={() => this.pressionar(2)}>2</Botao>
          <Botao onPress={() => this.pressionar(3)}>3</Botao>
          <Botao onPress={() => this.selecionarOperacao(new Subtracao())}>-</Botao>
        </View>
        <View style={estilos.subcontainer}>
          <Botao onPress={() => this.clear()}>C</Botao>
          <Botao onPress={() => this.pressionar(0)}>0</Botao>
          <Botao onPress={() => this.resultado()}>=</Botao>
          <Botao onPress={() => this.selecionarOperacao(new Soma())}>+</Botao>
        </View>
      </View>
    );
  }
}

export default App;
