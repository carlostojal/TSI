
//
// Copyright (c) Carlos Tojal (24-10-2019)
// Ex5
// Circulo.java
//

import java.lang.Math;

public class Circulo {
    private double r;

    public double getRaio() {
        return r;
    }
    
    public Circulo() {
    }

    public Circulo(double r) {
        this.r = r;
    }

    public double calcularDiametro() {
        return 2 * getRaio();
    }

    public double calcularPerimetro() {
        return 2 * Math.PI * r;
    }

    public double calcularArea() {
        return Math.PI * (r * r);
    }
}