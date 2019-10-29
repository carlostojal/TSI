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
        Condutor Condutor = new Condutor();

        System.out.println("\n** Exercicio Proposto 2\n");
        System.out.print("Cor: ");
        carro.setCor(scanner.nextLine());
        System.out.print("Marca: ");
        carro.setMarca(scanner.nextLine());
        System.out.println("Ano fabrico: ");
        carro.setAnoFabrico(scanner.nextInt());
        System.out.println("Modelo: ");
        carro.setModelo(scanner.nextLine());
    }
}
