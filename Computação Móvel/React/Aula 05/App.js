// Aula 05 - Relógio em React Native (Expo): estado, temporizadores e ciclo de vida.
// A hora é exibida pelo componente Hora durante os primeiros 10 segundos; depois disso
// o componente é desmontado, o que permite observar componentWillUnmount no console.
import React from 'react';
import { ImageBackground, Text, View } from 'react-native';

import estilos from './estilo';
import Hora from './hora';

const SEGUNDOS_EXIBINDO_HORA = 10;

class App extends React.Component {
  constructor(props) {
    super(props);
    this.state = {
      data: new Date(),
      cont: 0,
    };
  }

  /** Atualiza a data e incrementa o contador de segundos. */
  tick() {
    this.setState((estadoAnterior) => ({
      data: new Date(),
      cont: estadoAnterior.cont + 1,
    }));
  }

  componentDidMount() {
    this.timer = setInterval(() => this.tick(), 1000);
  }

  componentWillUnmount() {
    clearInterval(this.timer);
  }

  render() {
    const { data, cont } = this.state;

    return (
      <ImageBackground style={estilos.imagem} source={require('./assets/relogio.png')}>
        <View style={estilos.container}>
          {cont < SEGUNDOS_EXIBINDO_HORA && <Hora>{data.toLocaleTimeString()}</Hora>}
          <Text style={estilos.texto}>
            {data.getDate()}/{data.getMonth() + 1}/{data.getFullYear()}
          </Text>
        </View>
      </ImageBackground>
    );
  }
}

export default App;
