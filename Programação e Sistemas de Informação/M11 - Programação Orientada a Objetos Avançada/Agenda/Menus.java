
//
// Copyright (c) Carlos Tojal 2020
// Agenda
// Menus.java
//

import java.util.ArrayList;
import java.util.Scanner;

public class Menus {

    // Construtor
    public Menus() {
    }

    public int menu() {
        Scanner scanner = new Scanner(System.in);
        int opt = 0;
        do {
            System.out.println("\n** Agenda **\n");
            System.out.println("1. Adicionar Contato");
            System.out.println("2. Listar Contatos");
            System.out.println("3. Remover Contato");
            System.out.println("0. Sair\n");
            System.out.print("Opção: ");
            opt = scanner.nextInt();
        } while(opt < 0 || opt > 3);
        return opt;
    }

    public void menuAdicionarContato(ArrayList<Contato> agenda) {
        Scanner scanner = new Scanner(System.in);
        GestorAgenda gestorAgenda = new GestorAgenda();
        Contato contato = new Contato();
        System.out.println("\n** Adicionar Contato **\n");
        System.out.print("Nome: ");
        contato.setNome(scanner.nextLine());
        System.out.print("Telefone: ");
        contato.setTelefone(scanner.nextLine());
        System.out.print("Email: ");
        contato.setEmail(scanner.nextLine());
        gestorAgenda.adicionarContato(contato, agenda);
    }

    public void menuRemoverContato(ArrayList<Contato> agenda) {
        GestorAgenda gestorAgenda = new GestorAgenda();
        String query;
        boolean found = false;
        gestorAgenda.listarAgenda(agenda);
        System.out.println("\nTelefone ou email a remover: ");
        query = new Scanner(System.in).nextLine();
        for(int i = 0; i < agenda.size(); i++) {
            if(String.valueOf(agenda.get(i).getTelefone()).equals(query) || agenda.get(i).getEmail().equals(query)) {
                agenda.remove(agenda.get(i));
                found = true;
            }
        }
        if(found)
            System.out.println("Contato removido com sucesso.");
        else
            System.out.println("Contato não encontrado.");
    }
}
