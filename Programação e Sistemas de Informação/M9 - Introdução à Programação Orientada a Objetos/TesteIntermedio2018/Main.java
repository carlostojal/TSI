
/*
* Copyright (c) Carlos Tojal 2019
* TesteIntermedio2018
* MainWindow.java
*/

import java.util.Scanner;

public class Main {
    static Almoco[] almocos = new Almoco[4];

    public static void main(String[] args) {
        int opt;
        almocos[0] = new Almoco("Sandes de presunto/leitão/salmão", 3.00f);
        almocos[1] = new Almoco("Salada Multicor", 2.50f);
        almocos[2] = new Almoco("Sopa", 1.50f);
        almocos[3] = new Almoco("Tudo", 6.00f);

        opt = menu();

        /*
        switch(opt) {
            case 1:
                System.out.println("\n" + almocos[0].getDescricao() + " - " + almocos[0].getPreco());
                break;
            case 2:
                System.out.println("\n" + almocos[1].getDescricao() + " - " + almocos[1].getPreco());
                break;
            case 3:
                System.out.println("\n" + almocos[2].getDescricao() + " - " + almocos[2].getPreco());
                break;
            case 4:
                System.out.println("\n" + almocos[3].getDescricao() + " - " + almocos[3].getPreco());
                break;
        }*/

        System.out.println("\n" + almocos[opt-1].getDescricao() + " - " + almocos[opt-1].getPreco());
    }

    public static int menu() {
        Scanner scanner = new Scanner(System.in);
        int opt;
        do {
            System.out.println("\n** Almoços **\n");
            for(int i = 0; i < 4; i++) {
                System.out.println((i + 1) + " - " + almocos[i].getDescricao());
            }
            System.out.print("Opção: ");
            opt = scanner.nextInt();
            if(opt < 1 || opt > 4)
                System.out.println("Erro: opção inválida.");
        }while(opt < 1 || opt > 4);
        return opt;
    }
}