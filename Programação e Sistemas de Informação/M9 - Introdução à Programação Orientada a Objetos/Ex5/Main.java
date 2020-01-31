
//
// Copyright (c) Carlos Tojal (24-10-2019)
// Ex5
// MainWindow.java
//

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int opt;

        do {
            opt = menu();
            switch(opt) {
                case 1:
                    new ConstroiRetangulo();
                    break;
                case 2:
                    new ConstroiTriangulo();
                    break;
                case 3:
                    new ConstroiCirculo();
                    break;
            }
        } while(opt > 0);
    }

    public static int menu() {
        Scanner scanner = new Scanner(System.in);
        int opt;
        do {
            System.out.println("\n** Ex5 **\n");
            System.out.println("1. Retangulo");
            System.out.println("2. Triangulo");
            System.out.println("3. Circulo");
            System.out.println("0. Sair\n");
            System.out.print("Opcao: ");
            opt = scanner.nextInt();
        }while(opt < 0 || opt > 3);
        return opt;
    }
}