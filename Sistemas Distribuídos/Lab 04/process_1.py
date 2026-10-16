"""Executa o Processo 1: python process_1.py <code> <n>"""

import sys

from ProcessOne import ProcessOne

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Uso: python process_1.py <code> <n>")
        sys.exit(1)

    process = ProcessOne(sys.argv[1], sys.argv[2])
    process.send_message()
    process.wait_callback()
