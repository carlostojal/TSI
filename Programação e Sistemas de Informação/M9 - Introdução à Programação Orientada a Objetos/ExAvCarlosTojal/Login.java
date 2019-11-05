
//
// Carlos Tojal 04-11-2019
// ExAvCarlosTojal
// Login.java
//

import java.util.Scanner;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;

public class Login {
    private Utilizador utilizador;

    public Utilizador getUtilizador() {
        return utilizador;
    }

    public void setUtilizador(Utilizador utilizador) {
        this.utilizador = utilizador;
    }

    public Login() {
    }

    public int menu() {
        int opt;
        Scanner scanner = new Scanner(System.in);
        do {
            System.out.println("\n** ExAvCarlosTojal **\n");
            System.out.println("1. Login");
            System.out.println("2. Registo");
            System.out.println("0. Sair\n");
            System.out.print("Opcao: ");
            opt = scanner.nextInt();
        }while(opt < 0 || opt > 2);
        return opt;
    }

    public void fazerLogin() {
        Scanner scanner = new Scanner(System.in);
        String login, senha;
        boolean sucesso = false;
        do {
            System.out.println("\n** Login ExAvCarlosTojal **\n");
            System.out.print("Login: ");
            login = scanner.nextLine();
            System.out.print("Senha: ");
            senha = scanner.nextLine();

            Utilizador utilizadorLogin = new Utilizador();
            utilizadorLogin.setLogin(login);
            utilizadorLogin.setSenha(senha);

            setUtilizador(utilizadorLogin);

            Utilizador[] utilizadores = new Utilizador().obterUtilizadores();

            for(int i = 0; i < 10 && utilizadores[i] != null; i++) {
                if(utilizadorLogin.getLogin().equals(utilizadores[i].getLogin()) && utilizadorLogin.getSenha().equals(utilizadores[i].getSenha())) {
                    sucesso = true;
                    break;
                }
            }
        }while(!sucesso);
    }

    public void fazerRegisto() {
        Scanner scanner = new Scanner(System.in);
        BufferedWriter bw = null;
        String login, senha;
        System.out.println("\n** Registo ExAvCarlosTojal\n");
        System.out.print("Login: ");
        login = scanner.nextLine();
        System.out.print("Senha: ");
        senha = scanner.nextLine();

        try {
            bw = new BufferedWriter(new FileWriter("login.csv", true));
            bw.write(login + "; " + senha+"\n");
            bw.close();
        } catch(IOException e) {
            e.printStackTrace();
        }
    }
}