package main;

import navioMercante.NavioMercante;
import portaAvioes.PortaAvioes;
import cruzador.Cruzador;

/**
 * Aula 05 - Exercício 4: hierarquia de navios (enunciado em ../../../../images/lab05_04.png).
 *
 * @author Matheus Teixeira
 */
public class Main {
    public static void main(String[] args) {
        NavioMercante navioMercante = new NavioMercante(100, 0, 5, "Navio Cargueiro");
        navioMercante.exibirInfoGeral();
        navioMercante.carregamento(50);
        System.out.println("Carga Atual: " + navioMercante.getCarga());

        PortaAvioes portaAvioes = new PortaAvioes(10, 100, 100, 5, "Navioptero");
        portaAvioes.exibirInfoGeral();
        portaAvioes.exibirArmas();
        portaAvioes.poderDeFogo();

        Cruzador cruzador = new Cruzador(10, 100, 100, 5, "Cruzavio");
        cruzador.exibirInfoGeral();
        cruzador.exibirArmas();
        cruzador.poderDeFogo();
    }
}
