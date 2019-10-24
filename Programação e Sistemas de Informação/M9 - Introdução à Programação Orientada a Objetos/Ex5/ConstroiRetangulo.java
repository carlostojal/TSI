
//
// Copyright (c) Carlos Tojal (24-10-2019)
// Ex5
// ConstroiRetangulo.java
//

import java.util.Scanner;

public class ConstroiRetangulo {
    Retangulo retangulo;
    Coordenada extremo1, extremo2;

    public ConstroiRetangulo() {
        Scanner scanner = new Scanner(System.in);
        double x, y;

        System.out.println("\n** Retangulo **\n");

        System.out.println("Extremo 1");
        System.out.print("X: ");
        x = scanner.nextDouble();
        System.out.print("Y: ");
        y = scanner.nextDouble();
        extremo1 = new Coordenada(x, y);

        System.out.println("\nExtremo 2");
        System.out.print("X: ");
        x = scanner.nextDouble();
        System.out.print("Y: ");
        y = scanner.nextDouble();
        extremo2 = new Coordenada(x, y);

        retangulo = new Retangulo(extremo1, extremo2);

        System.out.println("\nBase: " + retangulo.calcularBase());
        System.out.println("Altura: " + retangulo.calcularAltura());
        System.out.println("Perimetro: " + retangulo.calcularPerimetro());
        System.out.println("Area: " + retangulo.calcularArea());

        desenhaRetangulo();
    }

    public void desenhaRetangulo() {
        System.out.print("\n ");
        for(int x = 0; x < retangulo.calcularBase(); x++)
            System.out.print(" - ");
        System.out.println("");
        for(int y = 0; y < retangulo.calcularAltura(); y++) {
            System.out.print("|");
            for(int x = 0; x < retangulo.calcularBase() * 3; x++) {
                System.out.print(" ");
            }
            System.out.println("|");
        }
        System.out.print(" ");
        for(int x = 0; x < retangulo.calcularBase(); x++)
            System.out.print(" - ");
        System.out.println("");
    }
}