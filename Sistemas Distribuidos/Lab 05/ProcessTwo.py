"""Processo 2 (intermediário): valida a requisição HTTP e a repassa ao Processo 3 via socket TCP."""

import socket

PORTA_PROCESSO_3 = 4003
CODIGO_MINIMO = 10_000_000
N_MINIMO, N_MAXIMO = 5000, 15000


class ProcessTwo:
    @staticmethod
    def validate_message(data_msg):
        """Valida [code, n]; retorna "code&n" ou uma mensagem iniciada por "Error"."""
        if len(data_msg) < 2:
            return "Error: Number of args is invalid"

        code, n = int(data_msg[0]), int(data_msg[1])
        if code <= CODIGO_MINIMO:
            return f"Error: Invalid code -> code > {CODIGO_MINIMO}"
        if not N_MINIMO < n <= N_MAXIMO:
            return f"Error: Invalid n -> {N_MINIMO} < n <= {N_MAXIMO}"
        return f"{code}&{n}"

    @staticmethod
    def wait_response(conexao):
        """Aguarda a resposta do Processo 3."""
        while True:
            dados = conexao.recv(1024)
            if dados:
                resposta = dados.decode()
                print("Resposta do servidor:", resposta)
                return resposta

    def get_message(self, request):
        """Trata a requisição Flask: valida os parâmetros e consulta o Processo 3."""
        try:
            inputs = [int(request.args.get("code")), int(request.args.get("n"))]
        except (TypeError, ValueError):
            return "Error: code and n must be integers"

        mensagem = ProcessTwo.validate_message(inputs)
        if mensagem.startswith("Error"):
            return mensagem

        with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as conexao:
            conexao.connect((socket.gethostname(), PORTA_PROCESSO_3))
            conexao.sendall(mensagem.encode("utf-8"))
            return self.wait_response(conexao)
