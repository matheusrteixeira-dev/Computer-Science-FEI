package Control;

import Model.Animal;
import Model.Cachorro;
import Model.Cliente;
import Model.Gato;
import Model.Veterinario;
import java.util.ArrayList;

/**
 * Controlador que mantém em memória os clientes (com seus animais) e os veterinários.
 * A interface gráfica deve usar uma única instância para que os dados persistam entre ações.
 *
 * @author Matheus Teixeira
 */
public class PeopleController {
    private ArrayList<Cliente> clientes = new ArrayList<>();
    private ArrayList<Veterinario> veterinarios = new ArrayList<>();

    public void createClients(Cliente c) {
        clientes.add(c);
    }

    public void createVeterinary(Veterinario v) {
        veterinarios.add(v);
    }

    /** Índice do cliente com o ID informado, ou -1 se não existir. */
    public int retornoIndexClient(int id) {
        for (int i = 0; i < clientes.size(); i++) {
            if (clientes.get(i).getID() == id) {
                return i;
            }
        }
        return -1;
    }

    /**
     * Cadastra um animal para o cliente idDono.
     *
     * @return true se o dono existir e o tipo for "Cachorro" ou "Gato"
     */
    public boolean createPet(int idDono, int id, int idade, String nome, String tipo, String raca) {
        int indiceDono = retornoIndexClient(idDono);
        if (indiceDono < 0) {
            return false;
        }

        Animal animal;
        if ("Cachorro".equals(tipo)) {
            animal = new Cachorro(id, idade, nome, tipo, raca);
        } else if ("Gato".equals(tipo)) {
            animal = new Gato(id, idade, nome, tipo, raca);
        } else {
            return false;
        }

        clientes.get(indiceDono).insertAnimal(animal);
        return true;
    }

    public ArrayList<Cliente> getClientes() {
        return clientes;
    }

    public void setClientes(ArrayList<Cliente> clientes) {
        this.clientes = clientes;
    }

    public ArrayList<Veterinario> getVeterinarios() {
        return veterinarios;
    }

    public void setVeterinarios(ArrayList<Veterinario> veterinarios) {
        this.veterinarios = veterinarios;
    }
}
