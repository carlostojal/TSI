
import java.util.ArrayList;
import java.util.Iterator;

//
// Copyright (c) Carlos Tojal 2020
// Agenda
// GestorAgenda.java
//

public class GestorAgenda {

    // Construtor
    public GestorAgenda() {
    }

    // Métodos
    public void adicionarContato(Contato contato, ArrayList<Contato> agenda) {
        if(!agenda.contains(contato))
            agenda.add(contato);
        else
            System.out.println("O contato já existe na agenda.");
    }

    public void listarContato(Contato contato) {
        System.out.println("\n\n** Contato **");
        System.out.println("Nome: " + contato.getNome());
        System.out.println("Telefone: " + contato.getTelefone());
        System.out.println("Email: " + contato.getEmail());
    }

    public void listarAgenda(ArrayList<Contato> agenda) {
        for(int i = 0; i < agenda.size(); i++) {
            listarContato(agenda.get(i));
        }
    }
}
