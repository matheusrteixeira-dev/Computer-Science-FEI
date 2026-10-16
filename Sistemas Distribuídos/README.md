# Sistemas Distribuídos (Distributed Systems)

Python labs on parallel speedup and on communication between processes.

| Lab | Description |
| --- | --- |
| [Lab 02](Lab%2002) | Counts the primes in `dataset/data.csv` serially and with a thread pool. Reports the mean time over 50 runs, the speedup and the Karp–Flatt serial fraction, and plots the results (`main.py`, `prime.py`, `plot.py`). |
| [Lab 04](Lab%2004) | Three-process pipeline. Process 1 (HTTP client) sends a code and `n` to Process 2 (Flask), which validates the request and forwards it over TCP to Process 3. Process 3 computes the key: the product of the n-th prime below and the n-th prime above the code. `Testes/` holds the load-test scripts, `Logs/` their outputs. |
| [Lab 05](Lab%2005) | Same system as Lab 04 (resubmitted for the following lab). |

## Running

```bash
pip install numpy sympy matplotlib flask requests
python "Lab 02/main.py"
```

For Lab 04, start the processes in this order, each in its own terminal:

```bash
python process_3.py
python process_2.py
python process_1.py 10000001 15000
```
