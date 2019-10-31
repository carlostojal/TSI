
//
// Carlos Tojal (29-10-2019)
// ExProposto2
// CarroPasseio.java
//

import java.util.Scanner;

public class CarroPasseio {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Carro carro = new Carro();
        Condutor condutor1 = new Condutor("Fred", 17, true);
        Motor motor = new Motor();

        System.out.println("\n** Exercicio Proposto 2\n");
        System.out.print("Cor: ");
        carro.setCor(scanner.nextLine());
        System.out.print("Marca: ");
        carro.setMarca(scanner.nextLine());
        System.out.print("Ano fabrico: ");
        carro.setAnoFabrico(Integer.valueOf(scanner.nextLine()));
        System.out.print("Modelo: ");
        carro.setModelo(scanner.nextLine());

        carro.setLitros(8750);
        carro.pessoasDentro(30);
        motor.setPotencia(200);
        carro.setMotor(motor);

        carro.ligar();

        if(condutor1.temCarta()) {
            System.out.println(carro.getVelocidade());
            carro.acelerar();
            System.out.println(carro.getVelocidade());
            carro.travar(5);
            System.out.println(carro.getVelocidade());
            carro.acelerar();
            System.out.println(carro.getVelocidade());
        } else {
            System.out.println("Condutor nao tem carta.");
        }

        carro.desligar();
    }
}
