
//
// Copyright (c) Carlos Tojal (24-10-2019)
// Ex4
// FazCalculos1.java
//

public class FazCalculos1 {
    public static void main(String[] args) {
        Calculadora calculadora = new Calculadora();

        System.out.println("\nSoma: " + calculadora.soma(2.7, 3.5));
        System.out.println("Subtração: " + calculadora.subtracao(2.7, 3.5));
        System.out.println("Multiplicação: " + calculadora.multiplicacao(2.7, 3.5));
        System.out.println("Divisão: " + calculadora.divisao(2.7, 3.5));
    }
}