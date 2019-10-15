
//
// Copyright (c) Carlos Tojal (15-10-2019)
// ExProposto
// Corrida.java
//

// 1 - d)

public class Corrida {

    public Corrida() {
    }

    // Métodos
    public static void main(String[] args) {
        CarroCorrida carroEquipa1 = new CarroCorrida();
        CarroCorrida carroEquipa2 = new CarroCorrida();

        // 10
        carroEquipa1.motor = new Motor(50);
        carroEquipa2.motor = new Motor(100);

        carroEquipa1.setNumeroIdentificacao("11-AA-11");
        carroEquipa2.setNumeroIdentificacao("22-BB-22");

        Piloto piloto1 = new Piloto();
        Piloto piloto2 = new Piloto();

        piloto1.setNome("António");
        piloto1.setIdade(25);
        piloto1.setDestreza(75); // 2

        piloto2.setNome("Manuel");
        piloto2.setIdade(27);
        piloto2.setDestreza(80); // 2

        carroEquipa1.setPiloto(piloto1);
        carroEquipa2.setPiloto(piloto2);

        if(!carroEquipa1.isLigado())
            carroEquipa1.ligar();
        if(!carroEquipa2.isLigado())
            carroEquipa2.ligar();

        // 2
        carroEquipa1.acelerar();
        carroEquipa2.acelerar();
        carroEquipa1.acelerar();
        carroEquipa2.travar(5);
        carroEquipa1.acelerar();
        carroEquipa1.acelerar();
        carroEquipa1.travar(60);
        carroEquipa2.acelerar();

        // carroEquipa2.velocidadeAtual = 300.0f; // 3
        /* Esta linha atribui o valor de 300.0 (float) ao atributo velocidadeAtual
        * do objeto carroEquipa2

        System.out.println("Velocidade do carroEquipa1: " + carroEquipa1.getVelocidadeAtual());
        System.out.println("Velocidade do carroEquipa2: " + carroEquipa2.getVelocidadeAtual());

        carroEquipa1.desligar();
        carroEquipa2.desligar();
    }
}
