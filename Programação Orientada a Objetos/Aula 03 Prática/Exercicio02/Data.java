package Exercicio02;

/**
 * Data que pode ser criada e exibida em três formatos:
 * I. MM/DD/AAAA; II. "Mês DD, AAAA"; III. "DDD AAAA" (dia do ano).
 *
 * @author Matheus Teixeira
 */
public class Data {
    private static final String[] NOMES_MESES = {"Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho",
                "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};

    private int dia;
    private int mes;
    private int ano;

    public Data() {
    }

    /** Formato I: mês, dia e ano numéricos. */
    public Data(int mes, int dia, int ano) {
        setAno(ano);
        setMes(mes);
        setDia(dia);
    }

    /** Formato II: nome do mês, dia e ano. */
    public Data(String mes, int dia, int ano) {
        setAno(ano);
        setMes(mesValue(mes));
        setDia(dia);
    }

    /** Formato III: dia do ano (1 a 365/366) e ano. */
    public Data(int diaDoAno, int ano) {
        setAno(ano);
        int restante = diaDoAno;
        int m = 1;
        while (m < 12 && restante > diasNoMes(m)) {
            restante -= diasNoMes(m);
            m++;
        }
        setMes(m);
        setDia(restante);
    }

    public boolean isBissexto() {
        return (ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0;
    }

    /** Quantidade de dias do mês (1 a 12) no ano desta data. */
    public int diasNoMes(int mes) {
        return switch (mes) {
            case 2 -> isBissexto() ? 29 : 28;
            case 4, 6, 9, 11 -> 30;
            default -> 31;
        };
    }

    /** Número do mês correspondente ao nome (1 a 12), ou 1 se o nome for inválido. */
    public static int mesValue(String mes) {
        for (int i = 0; i < NOMES_MESES.length; i++) {
            if (NOMES_MESES[i].equalsIgnoreCase(mes.trim())) {
                return i + 1;
            }
        }
        return 1;
    }

    /** Soma dos dias dos meses 1 até mes (inclusive). */
    public int totalDia(int mes) {
        int soma = 0;
        for (int m = 1; m <= mes; m++) {
            soma += diasNoMes(m);
        }
        return soma;
    }

    public static String stringMes(int mes) {
        return NOMES_MESES[mes - 1];
    }

    public void printAll() {
        System.out.println("=================================");
        System.out.printf("I. %02d/%02d/%04d%n", this.mes, this.dia, this.ano);
        System.out.printf("II. %s %d, %d%n", stringMes(this.mes), this.dia, this.ano);
        System.out.printf("III. %03d %d%n", totalDia(this.mes - 1) + this.dia, this.ano);
    }

    public void setDia(int dia) {
        this.dia = (dia > 0 && dia <= diasNoMes(this.mes)) ? dia : 1;
    }

    public void setMes(int mes) {
        this.mes = (mes > 0 && mes <= 12) ? mes : 1;
    }

    public void setAno(int ano) {
        this.ano = (ano > 0) ? ano : 2000;
    }

    public int getDia() {
        return dia;
    }

    public int getMes() {
        return mes;
    }

    public int getAno() {
        return ano;
    }

    public void exibeData() {
        System.out.println("=================================");
        System.out.printf("Data: %02d/%02d/%04d%n", dia, mes, ano);
        System.out.println("=================================");
    }
}
