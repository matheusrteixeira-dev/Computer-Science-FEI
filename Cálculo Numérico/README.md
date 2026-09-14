# Cálculo Numérico (Numerical Methods)

Python scripts for the numerical methods course. Each activity is organized into functions (one per exercise) and runs from the command line.

| Activity | Topics |
| --- | --- |
| [Atividade 01](Atividade%2001) | Introduction to NumPy, Matplotlib and SymPy: plots, symbolic derivatives, integrals and limits, matrix operations. |
| [Atividade 02](Atividade%2002) | Linear systems: inverse matrix vs. `numpy.linalg.solve` vs. SymPy; rank analysis of an underdetermined system. |
| [Atividade 03](Atividade%2003) | Roots of nonlinear equations: tabulation, graphical method, `fsolve`, symbolic Newton–Raphson, polynomial roots. |
| [Atividade 04](Atividade%2004) | Applied linear systems (mixture and investment problems) and Newton–Raphson with a tolerance criterion. |
| [Atividade 05](Atividade%2005) | Least-squares linear regression, implemented by hand and with scikit-learn. |
| [Atividade 06](Atividade%2006) | Simple and multiple linear regression; concrete compressive strength dataset evaluated with R². |
| [Atividade 07](Atividade%2007) | Exponential fitting, Lagrange interpolation and numerical integration (trapezoidal rule vs. adaptive quadrature). |
| [Atividade 08](Atividade%2008) | Ordinary differential equations: Euler's method, analytical solution with SymPy and `odeint`. |
| [Atividade 09](Atividade%2009) | Review exercises: trapezoidal rule vs. `quad`, Euler's method, interpolation and area from measured profiles. |
| [Atividade 10](Atividade%2010) | Correlation analysis and linear regression on the Wine Quality (red wine) dataset. |
| [Atividade 11](Atividade%2011) | Spectral analysis with the FFT: sampled cosines, aliasing above the Nyquist frequency, spectrogram of a short audio clip. |

## Running

```bash
pip install numpy scipy sympy matplotlib pandas seaborn scikit-learn
python "Atividade 07/atividade07.py"
```

The data files (`concrete_data.csv`, `winequality-red.csv`, `musica.wav`) are read from the script's own folder.
