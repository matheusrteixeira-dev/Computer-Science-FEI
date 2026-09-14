// Aula 06 - Navegação por abas (React Navigation) e persistência local com AsyncStorage.
// A aba "Cadastro" grava pares usuário/senha; a aba "Login" verifica as credenciais gravadas.
// Observação: no Expo SDK 39, AsyncStorage ainda é exportado por 'react-native'; em versões
// mais recentes, use o pacote '@react-native-async-storage/async-storage'.
import * as React from 'react';
import { AsyncStorage, Button, Text, TextInput, View } from 'react-native';
import { NavigationContainer } from '@react-navigation/native';
import { createBottomTabNavigator } from '@react-navigation/bottom-tabs';
import { MaterialCommunityIcons } from '@expo/vector-icons';

import estilos from './estilo';

/** Tela de login: compara a senha digitada com a gravada para o usuário. */
class Login extends React.Component {
  constructor(props) {
    super(props);
    this.state = {
      user: undefined,
      password: undefined,
    };
  }

  leitura() {
    AsyncStorage.getItem(this.state.user, (erro, senha) => {
      if (!erro && senha !== null) {
        alert(senha === this.state.password ? 'Logado' : 'Senha incorreta');
      } else {
        alert('Usuário não encontrado');
      }
    });
  }

  render() {
    return (
      <View style={estilos.container}>
        <Text>Login</Text>
        <Text>Usuário:</Text>
        <TextInput
          style={estilos.caixa}
          autoCapitalize="none"
          onChangeText={(texto) => this.setState({ user: texto })}
        />
        <Text>Senha:</Text>
        <TextInput
          style={estilos.caixa}
          secureTextEntry
          onChangeText={(texto) => this.setState({ password: texto })}
        />
        <Button title="Login" onPress={() => this.leitura()} />
      </View>
    );
  }
}

/** Tela de cadastro: grava o par usuário/senha no armazenamento local. */
class Cadastro extends React.Component {
  constructor(props) {
    super(props);
    this.state = {
      user: undefined,
      password: undefined,
    };
  }

  gravar() {
    AsyncStorage.setItem(this.state.user, this.state.password, (erro) => {
      if (!erro) {
        alert('Usuário cadastrado');
      }
    });
  }

  render() {
    return (
      <View style={estilos.container}>
        <Text>Cadastro</Text>
        <Text>Usuário:</Text>
        <TextInput
          style={estilos.caixa}
          autoCapitalize="none"
          onChangeText={(texto) => this.setState({ user: texto })}
        />
        <Text>Senha:</Text>
        <TextInput
          style={estilos.caixa}
          secureTextEntry
          onChangeText={(texto) => this.setState({ password: texto })}
        />
        <Button title="Cadastrar" onPress={() => this.gravar()} />
      </View>
    );
  }
}

const Tab = createBottomTabNavigator();

export default class App extends React.Component {
  render() {
    return (
      <NavigationContainer>
        <Tab.Navigator>
          <Tab.Screen
            name="Login"
            component={Login}
            options={{
              tabBarLabel: 'Login',
              tabBarIcon: ({ color, size }) => (
                <MaterialCommunityIcons name="home" color={color} size={size} />
              ),
            }}
          />
          <Tab.Screen
            name="Cadastro"
            component={Cadastro}
            options={{
              tabBarLabel: 'Cadastro',
              tabBarIcon: ({ color, size }) => (
                <MaterialCommunityIcons name="account-details" color={color} size={size} />
              ),
            }}
          />
        </Tab.Navigator>
      </NavigationContainer>
    );
  }
}
