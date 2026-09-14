package savingAccount;

import account.Account;

/**
 * Conta poupança que rende juros sobre o saldo.
 *
 * @author Matheus Teixeira
 */
public class SavingAccount extends Account{
    protected double taxaJuros; // em porcentagem

    public SavingAccount(double taxaJuros, double saldo) {
        super(saldo);
        this.taxaJuros = taxaJuros;
    }

    public double calculateInterest() {
        return this.saldo * (this.taxaJuros / 100);
    }
}
