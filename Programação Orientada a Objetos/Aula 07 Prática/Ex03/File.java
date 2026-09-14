package Ex03;

import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

/**
 * Saída em arquivo (output.txt).
 *
 * @author Matheus Teixeira
 */
public class File implements Output {
    @Override
    public void print(String text) {
        try (PrintWriter escrita = new PrintWriter(new FileWriter("output.txt"))) {
            escrita.println(text);
            System.out.println("Texto gravado em output.txt");
        } catch (IOException e) {
            System.err.println("Erro ao gravar o arquivo: " + e.getMessage());
        }
    }
}
