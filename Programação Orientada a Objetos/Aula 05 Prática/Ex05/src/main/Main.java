package main;

import savingAccount.SavingAccount;
import checkingAccount.CheckingAccount;

/**
 * Aula 05 - Exercício 5: contas poupança e corrente derivadas de uma conta base.
 *
 * @author Matheus Teixeira
 */
public class Main {
    public static void main(String[] args) {
        SavingAccount save = new SavingAccount(1.22, 5000);
        CheckingAccount check = new CheckingAccount(1, 1000);

        save.credit(1000);
        save.getBalance();
        save.debit(6000);
        save.getBalance();

        check.credit(1000);
        check.getBalance();
        check.debit(5000);
        check.getBalance();
    }
}
