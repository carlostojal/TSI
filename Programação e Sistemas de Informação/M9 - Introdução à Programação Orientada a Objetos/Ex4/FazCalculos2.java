
//
// Copyright (c) Carlos Tojal (24-10-2019)
// Ex4
// FazCalculos2.java
//

import java.util.Scanner;

public class FazCalculos2 {
    public static void main(String[] args) {
        Calculadora calculadora = new Calculadora();
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("1 Numero: ");
        double op1 = scanner.nextDouble();

        System.out.print("2 Numero: ");
        double op2 = scanner.nextDouble();

        System.out.println("\nSoma: " + calculadora.soma(op1, op2));
        System.out.println("Subtração: " + calculadora.subtracao(op1, op2));
        System.out.println("Multiplicação: " + calculadora.multiplicacao(op1, op2));
        System.out.println("Divisão: " + calculadora.divisao(op1, op2));
    }
}