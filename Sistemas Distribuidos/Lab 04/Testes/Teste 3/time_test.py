"""Teste 3: envia requisições com parâmetros aleatórios durante 5 segundos."""

import random
import sys
import time
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[2]))  # pasta com ProcessOne.py

from ProcessOne import ProcessOne  # noqa: E402

DURACAO_SEGUNDOS = 5

if __name__ == "__main__":
    fim = time.time() + DURACAO_SEGUNDOS

    while time.time() < fim:
        n = random.randint(5001, 15000)
        code = random.randint(10_000_001, 20_000_000)
        process = ProcessOne(str(code), str(n))
        process.send_message()
        process.wait_callback()
