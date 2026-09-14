import React from 'react';
import { Text, View } from 'react-native';

import estilos from '../estilo';

/** Visor da calculadora. */
class Display extends React.Component {
  render() {
    return (
      <View style={estilos.display}>
        <Text style={estilos.texto}>{this.props.children}</Text>
      </View>
    );
  }
}

export default Display;
