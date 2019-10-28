
//
// Copyright (c) Carlos Tojal (24-10-2019)
// Ex6
// ConstroiCirculo.java
//

public class ConstroiCirculo {
    public static void main(String[] args) {
        Circulo circulo1 = new Circulo(1.0, 1.0, 5.0);
        Circulo circulo2 = new Circulo(5.0, 2.0, 3.0);

        System.out.println("\nCirculo 1");
        System.out.println("Raio: " + circulo1.getRaio());
        System.out.println("Perimetro: " + circulo1.calcularPerimetro());
        System.out.println("Area: " + circulo1.calcularArea());

        System.out.println("\nCirculo 2");
        System.out.println("Raio: " + circulo2.getRaio());
        System.out.println("Perimetro: " + circulo2.calcularPerimetro());
        System.out.println("Area: " + circulo2.calcularArea());

        circulo2.aumentarRaio(2.0);

        System.out.println("\nCirculo 2");
        System.out.println("Raio: " + circulo2.getRaio());
        System.out.println("Perimetro: " + circulo2.calcularPerimetro());
        System.out.println("Area: " + circulo2.calcularArea());
        System.out.println("E maior: " + circulo2.verificarRaio(circulo1));
    }
}
