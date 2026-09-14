"""Processo 1 (cliente): envia código e n ao Processo 2 via HTTP e exibe a chave calculada."""

import requests

URL_PROCESSO_2 = "http://localhost:5000/processo2"


class ProcessOne:
    def __init__(self, code="10000001", n="15000"):
        self.code = code
        self.n = n
        self.response = None

    def send_message(self):
        """Envia a requisição GET ao Processo 2 e guarda a resposta."""
        resposta = requests.get(URL_PROCESSO_2, params={"code": self.code, "n": self.n})
        self.response = resposta.text

    def wait_callback(self):
        """Exibe a resposta no formato "chave&tempo" (ou a mensagem de erro recebida)."""
        if not self.response:
            return

        partes = self.response.split("&")
        if len(partes) == 2:
            print(f"Key: {partes[0]}")
            print(f"Tempo: {partes[1]}")
        else:
            print(self.response)
