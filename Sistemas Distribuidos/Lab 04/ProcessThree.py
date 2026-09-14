"""Processo 3 (servidor TCP): calcula a chave = (n-ésimo primo abaixo do código) x (n-ésimo primo acima)."""

import socket
import time

import sympy

PORTA = 4003


class ProcessThree:
    def __init__(self):
        self.s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.conexao = None

    @staticmethod
    def get_all_primes(data_msg):
        """Recebe [code, n] e retorna "chave&tempo_em_segundos"."""
        code = int(data_msg[0])
        n = int(data_msg[1])

        print("Código inicial:", code)
        print("N:", n)

        inicio = time.time()
        primo_depois = sympy.nextprime(code, ith=n)

        # Percorre os números abaixo do código até encontrar o n-ésimo primo.
        primo_antes = code
        for _ in range(n):
            primo_antes = sympy.prevprime(primo_antes)

        fim = time.time()
        return f"{primo_antes * primo_depois}&{fim - inicio}"

    def get_message(self):
        """Lê uma requisição da conexão atual, calcula a chave e envia a resposta."""
        while True:
            dados = self.conexao.recv(1024)
            if dados:
                mensagem = dados.decode()
                print("Mensagem recebida:", mensagem)

                resposta = self.get_all_primes(mensagem.split("&"))
                print("Key:", resposta)

                self.conexao.sendall(resposta.encode("utf-8"))
                break

    def wait_client(self):
        """Aceita conexões indefinidamente, atendendo uma requisição por conexão."""
        self.s.bind((socket.gethostname(), PORTA))
        self.s.listen()
        print(f"Aguardando conexões na porta {PORTA}...")
        while True:
            self.conexao, endereco = self.s.accept()
            print("Cliente conectado:", endereco)
            with self.conexao:
                self.get_message()
