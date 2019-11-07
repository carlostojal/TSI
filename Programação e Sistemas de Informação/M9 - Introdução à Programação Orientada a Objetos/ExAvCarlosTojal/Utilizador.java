
//
// Carlos Tojal 04-11-2019
// ExAvCarlosTojal
// Utilizador.java
//

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class Utilizador {
    // Atributos
    private String login;
    private String senha;

    // Getters e setters
    public String getLogin() {
        return login;
    }

    public void setLogin(String login) {
        this.login = login;
    }

    public String getSenha() {
        return senha;
    }

    public void setSenha(String senha) {
        this.senha = senha;
    }

    // Construtor
    public Utilizador() {
    }

    // Métodos
    public Utilizador[] obterUtilizadores() {
        BufferedReader br;
        String line = "";
        Utilizador[] utilizadores = new Utilizador[10];
        int i = 0;
        try {
            br = new BufferedReader(new FileReader("login.csv"));
            while(line != null && i < 10) {
                line = br.readLine();
                if(line != null && !line.equals("")) {
                    utilizadores[i] = new Utilizador();
                    utilizadores[i].setLogin(line.split("; ")[0]);
                    utilizadores[i].setSenha(line.split("; ")[1]);
                }
                i++;
            }
        } catch(IOException e) {
            e.printStackTrace();
        }
        return utilizadores;
    }
}