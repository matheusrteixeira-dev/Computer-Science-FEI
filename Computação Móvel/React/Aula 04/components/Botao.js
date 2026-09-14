import React from 'react';
import { Text, TouchableOpacity } from 'react-native';

import estilos from '../estilo';

/** Botão da calculadora: exibe o conteúdo filho e chama `onPress` ao ser tocado. */
class Botao extends React.Component {
  render() {
    return (
      <TouchableOpacity style={estilos.botao} onPress={this.props.onPress}>
        <Text style={estilos.texto}>{this.props.children}</Text>
      </TouchableOpacity>
    );
  }
}

export default Botao;
