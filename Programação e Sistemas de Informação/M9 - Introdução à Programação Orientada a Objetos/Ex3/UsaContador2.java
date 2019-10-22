
//
// Copyright (c) Carlos Tojal (22-10-2019)
// Ex3
// UsaContador2.java
//

import java.util.Scanner;

public class UsaContador2 {
    public static void main(String[] args) {
        Contador contador = new Contador(0);
        while (contador.getNum() <= 5) {
            System.out.println("Carregue na tecla «ENTER» para retirar uma senha");
            Scanner scanner = new Scanner(System.in);
            scanner.nextLine();
            contador.incNum();
            contador.mostrarNum();
            if (contador.getNum() == 3) {
                System.out.println("Carregue com mais papel.");
            }
        }
    }
}