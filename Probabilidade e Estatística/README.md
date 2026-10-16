# Probabilidade e Estatística (Probability and Statistics)

Python scripts for descriptive and inferential statistics.

| File | Description |
| --- | --- |
| [`histograma.py`](histograma.py) | Descriptive statistics: measures of central tendency and dispersion, histograms, box plots, grouped (class) data and min-max normalization of the Iris dataset. |
| [`Atividade03.py`](Atividade03.py) | Probability exercises with the binomial and normal distributions. |
| [`notebook_conjunta.py`](notebook_conjunta.py) | Joint distribution of two variables: mean, standard deviation, covariance and correlation. |
| [`Teste_Normalidade.py`](Teste_Normalidade.py) | Normality tests (Shapiro–Wilk on Iris; D'Agostino–Pearson on `mtcars.csv`) and hypothesis testing. |

## Running

```bash
pip install numpy scipy pandas matplotlib seaborn scikit-learn
python histograma.py
```

`Teste_Normalidade.py` looks for `mtcars.csv` in the same folder and skips that test if the file is missing (the dataset is available from R's `datasets` package).
