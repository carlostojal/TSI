
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

        carro1.setMatricula("11-AA-11");
        carro2.setMatricula("22-BB-22");

        Condutor condutor1 = new Condutor();
        Condutor condutor2 = new Condutor();

        condutor1.setNome("António");
        condutor1.setIdade(25);
        condutor1.setDestreza(75);

        condutor2.setNome("Manuel");
        condutor2.setIdade(27);
        condutor2.setDestreza(80);

        carro1.setCondutor(condutor1);
        carro2.setCondutor(condutor2);

        if(!carro1.isLigado())
            carro1.ligar();
        if(!carro2.isLigado())
            carro2.ligar();

        carro1.acelerar();
        carro2.acelerar();
        carro1.acelerar();
        carro2.travar(5);
        carro1.acelerar();
        carro1.acelerar();
        carro1.travar(50);
        carro2.acelerar();

        System.out.println("Velocidade do carro1: " + carro1.getVelocidadeAtual());
        System.out.println("Velocidade do carro2: " + carro2.getVelocidadeAtual());

        carro1.desligar();
        carro2.desligar();
    }
}
