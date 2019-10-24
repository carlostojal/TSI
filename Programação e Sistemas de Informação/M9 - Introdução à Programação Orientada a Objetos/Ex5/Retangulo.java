
//
// Copyright (c) Carlos Tojal (24-10-2019)
// Ex5
// Retangulo.java
//

public class Retangulo {
    private Coordenada extremo1;
    private Coordenada extremo2;
    
    public Retangulo() {
    }

    public Retangulo(Coordenada extremo1, Coordenada extremo2) {
        this.extremo1 = extremo1;
        this.extremo2 = extremo2;
    }

    public double calcularBase() {
        return extremo2.getX() - extremo1.getX();
    }

    public double calcularAltura() {
        return extremo2.getY() - extremo1.getY();
    }

    public double calcularPerimetro() {
        return (2 * calcularBase()) + (2 * calcularAltura());
    }

    public double calcularArea() {
        return calcularBase() * calcularAltura();
    }
}