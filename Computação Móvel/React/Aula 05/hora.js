import React from 'react';
import { Text } from 'react-native';

import estilos from './estilo';

/** Exibe a hora e registra no console cada etapa do ciclo de vida do componente. */
class Hora extends React.Component {
  constructor(props) {
    super(props);
    console.log('constructor chamado');
  }

  componentDidMount() {
    console.log('componentDidMount chamado');
  }

  shouldComponentUpdate() {
    console.log('shouldComponentUpdate chamado');
    return true;
  }

  componentDidUpdate() {
    console.log('componentDidUpdate chamado');
  }

  componentWillUnmount() {
    console.log('componentWillUnmount chamado');
  }

  render() {
    return <Text style={estilos.texto}>{this.props.children}</Text>;
  }
}

export default Hora;
