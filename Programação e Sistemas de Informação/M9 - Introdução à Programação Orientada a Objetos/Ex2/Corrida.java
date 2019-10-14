
//
// Copyright (c) Carlos Tojal (14-10-2019)
// Ex1
// Corrida.java
//

public class Corrida {

    // Construtor
    public Corrida() {

    }

    // Métodos
    public static void main(String[] args) {
        Carro carro1 = new Carro();
        Carro carro2 = new Carro();

        carro1.matricula = "11-AA-11";
        carro2.matricula = "22-BB-22";

        Condutor condutor1 = new Condutor();
        Condutor condutor2 = new Condutor();

        condutor1.nome = "António";
        condutor1.idade = 25;
        condutor1.destreza = 75;

        condutor2.nome = "Manuel";
        condutor2.idade = 27;
        condutor2.destreza = 65;

        carro1.condutor = condutor1;
        carro2.condutor = condutor2;

        carro1.ligar();
        carro2.ligar();

        carro1.acelerar();
        carro2.acelerar();
        carro1.acelerar();
        carro2.travar(10);
        carro1.acelerar();
        carro1.acelerar();
        carro1.travar(5);
        carro2.acelerar();

        System.out.println("Velocidade do carro1: " + carro1.velocidadeAtual);
        System.out.println("Velocidade do carro2: " + carro2.velocidadeAtual);

        carro1.desligar();
        carro2.desligar();
    }
}
