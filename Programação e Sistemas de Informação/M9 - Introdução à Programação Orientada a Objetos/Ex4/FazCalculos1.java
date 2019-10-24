
//
// Copyright (c) Carlos Tojal (24-10-2019)
// Ex4
// FazCalculos1.java
//

public class FazCalculos1 {
    public static void main(String[] args) {
        Calculadora calculadora = new Calculadora();
        calculadora.setOp1(2.7);
        calculadora.setOp2(3.5);

        System.out.println("\nSoma: " + calculadora.soma());
        System.out.println("Subtração: " + calculadora.subtracao());
        System.out.println("Multiplicação: " + calculadora.multiplicacao());
        System.out.println("Divisão: " + calculadora.divisao());
    }
}