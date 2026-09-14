package Model;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Matheus Teixeira
 */
public class File {
    private String nome, sobrenome, cpf, idade, sexo;

    public File(String nome, String sobrenome, String cpf, String idade, String sexo) {
        this.nome = nome;
        this.sobrenome = sobrenome;
        this.cpf = cpf;
        this.idade = idade;
        this.sexo = sexo;
    }

    public File() {
    }

    public void addDataToFile() {
        try {
            FileWriter file = new FileWriter("usuarios.txt", true);
            PrintWriter pr = new PrintWriter(file);
            pr.println("Nome: " + nome + " sobrenome: " + sobrenome + " idade: " + idade + " cpf: " + cpf + " sexo: " + sexo);
            file.close();
        } catch (IOException ex) {
            Logger.getLogger(File.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

    /** Retorna as linhas do arquivo que contêm o CPF informado (ou uma mensagem, se não houver). */
    public ArrayList<String> findUser(String cpf) {
        ArrayList<String> encontrados = new ArrayList<>();
        try (BufferedReader br = new BufferedReader(new FileReader("usuarios.txt"))) {
            String linha;
            while ((linha = br.readLine()) != null) {
                for (String palavra : linha.split(" ")) {
                    if (palavra.equals(cpf)) {
                        encontrados.add(linha);
                        break;
                    }
                }
            }
        } catch (IOException ex) {
            encontrados.add("Ocorreu um erro na leitura do arquivo");
            return encontrados;
        }
        if (encontrados.isEmpty()) {
            encontrados.add("Nenhum usuario encontrado com este cpf");
        }
        return encontrados;
    }
}
