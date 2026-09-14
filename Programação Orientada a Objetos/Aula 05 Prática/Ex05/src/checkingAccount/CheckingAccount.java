package checkingAccount;

import account.Account;

/**
 * Conta corrente que cobra uma taxa por transação.
 *
 * @author Matheus Teixeira
 */
public class CheckingAccount extends Account{
    protected double taxaTransacao;

    public CheckingAccount(double taxaTransacao, double saldo) {
        super(saldo);
        this.taxaTransacao = taxaTransacao;
    }

    @Override
    public void credit(double valor) {
        this.saldo -= this.saldo * (this.taxaTransacao/100);
        this.saldo+=valor;
    }

    @Override
    public void debit(double valor) {
        if (this.saldo - (valor + (this.saldo * (this.taxaTransacao/100))) >= 0) {
            this.saldo-=(valor + (this.saldo * (this.taxaTransacao/100)));
        } else {
            System.out.println("Impossível realizar a operação, saldo insuficiente...");
        }
    }
}
