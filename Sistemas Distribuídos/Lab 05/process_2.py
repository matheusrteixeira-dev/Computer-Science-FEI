"""Executa o Processo 2: servidor Flask na porta 5000 (rota /processo2?code=...&n=...)."""

from flask import Flask, request

from ProcessTwo import ProcessTwo

app = Flask(__name__)


@app.route("/processo2")
def processo2():
    return ProcessTwo().get_message(request)


if __name__ == "__main__":
    app.run(port=5000)
