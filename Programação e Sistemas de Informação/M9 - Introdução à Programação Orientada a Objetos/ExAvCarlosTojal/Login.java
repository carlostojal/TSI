
//
// Carlos Tojal 04-11-2019
// ExAvCarlosTojal
// Login.java
//

import java.util.Scanner;

public class Login {
    private Utilizador utilizador;

    public Utilizador getUtilizador() {
        return utilizador;
    }

    public void setUtilizador(Utilizador utilizador) {
        this.utilizador = utilizador;
    }

    public void fazerLogin() {
        Scanner scanner = new Scanner(System.in);
        String login, senha;

        do {
            System.out.println("\n** ExAvCarlosTojal **\n");
            System.out.print("Login: ");
            login = scanner.nextLine();
            System.out.print("Senha: ");
            senha = scanner.nextLine();
        }while(login != utilizador.getLogin() || senha != utilizador.getSenha());
    }
}