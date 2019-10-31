
//
// Carlos Tojal (31-10-2019)
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
        System.out.print("Ano de fabrico: ");
        carro.setAnoFabrico(Integer.valueOf(scanner.nextLine()));
        System.out.print("Modelo: ");
        carro.setModelo(scanner.nextLine());

        carro.setLitros(8750);
        carro.setKm(120000);
        carro.pessoasDentro(30);
        carro.setNportas(5);
        carro.setPesoCarro(300);
        motor.setPotencia(200);
        carro.setMotor(motor);

        carro.ligar();

        System.out.println("\nCor: " + carro.getCor());
        System.out.println("Marca: " + carro.getMarca());
        System.out.println("Ano de fabrico: " + carro.getAnoFabrico());
        System.out.println("Modelo: " + carro.getModelo());
        System.out.println("Litros de combustivel: " + carro.getLitros());
        System.out.println("Km do carro: " + carro.getKm());
        System.out.println("Pessoas no carro: " + carro.getNpessoas());
        System.out.println("Numero de portas: " + carro.getNportas());
        System.out.println("Peso no carro: " + carro.getPesoCarro());
        System.out.println("Potencia: " + carro.getMotor().getPotencia());

        if(condutor1.temCarta()) {
            System.out.println("");
            System.out.println("Velocidade atual: " + carro.getVelocidade());
            carro.acelerar();
            System.out.println("Velocidade atual: " + carro.getVelocidade());
            carro.travar(5);
            System.out.println("Velocidade atual: " + carro.getVelocidade());
            carro.acelerar();
            System.out.println("Velocidade atual: " + carro.getVelocidade());
        } else {
            System.out.println("Condutor nao tem carta.");
        }

        carro.desligar();
    }
}
