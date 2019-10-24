
//
// Copyright (c) Carlos Tojal (24-10-2019)
// Ex5
// ConstroiTriangulo.java
//

import java.util.Scanner;

public class ConstroiTriangulo {

    public ConstroiTriangulo() {
        Scanner scanner = new Scanner(System.in);
        Triangulo triangulo;
        double b, a;

        System.out.println("\n** Triangulo **\n");

        System.out.print("Base: ");
        b = scanner.nextDouble();
        System.out.print("Altura: ");
        a = scanner.nextDouble();

        triangulo = new Triangulo(b, a);

        System.out.println("\nBase: " + triangulo.getBase());
        System.out.println("Altura: " + triangulo.getAltura());
        System.out.println("Perimetro: " + triangulo.calcularPerimetro());
        System.out.println("Area: " + triangulo.calcularArea());
    }
}