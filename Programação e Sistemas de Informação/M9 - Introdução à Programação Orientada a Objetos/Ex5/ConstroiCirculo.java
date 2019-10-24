
//
// Copyright (c) Carlos Tojal (24-10-2019)
// Ex5
// ConstroiCirculo.java
//

import java.util.Scanner;

public class ConstroiCirculo {
    Circulo circulo;

    public ConstroiCirculo() {
        Scanner scanner = new Scanner(System.in);
        double r;

        System.out.println("\n** Circulo **\n");

        System.out.print("Raio: ");
        r = scanner.nextDouble();

        circulo = new Circulo(r);

        System.out.println("\nPerimetro: " + circulo.calcularPerimetro());
        System.out.println("Area: " + circulo.calcularArea());
    }
}