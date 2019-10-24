
//
// Copyright (c) Carlos Tojal (24-10-2019)
// Ex5
// Triangulo.java
//

import java.lang.Math;

public class Triangulo {
    private double b;
    private double a;

    public double getBase() {
        return b;
    }

    public double getAltura() {
        return a;
    }
    
    public Triangulo() {
    }

    public Triangulo(double b, double a) {
        this.b = b;
        this.a = a;
    }

    public double calcularHipotenusa() {
        return Math.sqrt((b * b) + (a * a)); //teorema de pitágoras
    }

    public double calcularPerimetro() {
        return b + a + calcularHipotenusa();
    }

    public double calcularArea() {
        return (b * a) / 2;
    }
}