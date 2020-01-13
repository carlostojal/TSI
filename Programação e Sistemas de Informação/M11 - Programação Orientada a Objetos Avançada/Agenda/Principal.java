
//
// Copyright (c) Carlos Tojal 2020
// Agenda
// Principal.java
//

import java.util.ArrayList;

public class Principal {
    static ArrayList<Contato> agenda = new ArrayList<Contato>();
    static Menus menus = new Menus();
    static GestorAgenda gestorAgenda = new GestorAgenda();
    public static void main(String[] args) {
        int opt;
        do {
            opt = menus.menu();
            switch(opt) {
                case 1:
                    menus.menuAdicionarContato(agenda);
                    break;
                case 2:
                    gestorAgenda.listarAgenda(agenda);
                    break;
                case 3:
                    menus.menuRemoverContato(agenda);
                    break;
            }
        }while(opt > 0);
    }
}
