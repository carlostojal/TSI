
//
// Copyright (c) Carlos Tojal (14-10-2019)
// Ex2
// Carro.java
//

public class Carro {
    // Atributos da classe Carro
    String matricula;
    int velocidadeAtual = 0;
    int velocidadeMaxima = 200;
    Condutor condutor;

    // Construtor da classe atual
    public Carro() {
    }

    // Métodos
    void ligar() {
        System.out.println("VRUUUMMMMMMMMM");
    }

    void desligar() {
        System.out.println("MMMMMMMMMMMMMMM");
    }

    void travar(int intensidadeTravagem) {
        if(intensidadeTravagem > velocidadeMaxima) {
            intensidadeTravagem = velocidadeMaxima;
        }
        else {
            if(intensidadeTravagem < 0)
                intensidadeTravagem = 0;
        }
        velocidadeAtual -= intensidadeTravagem;
        if(velocidadeAtual > velocidadeMaxima)
            velocidadeAtual = velocidadeMaxima;
        else if(velocidadeAtual < 0) {
            velocidadeAtual = 0;
        }
    }

    void acelerar() {
        if(velocidadeAtual + 10 + condutor.destreza * 0.1 <= velocidadeMaxima)
            velocidadeAtual += 10 + condutor.destreza * 0.1;
    }
}
