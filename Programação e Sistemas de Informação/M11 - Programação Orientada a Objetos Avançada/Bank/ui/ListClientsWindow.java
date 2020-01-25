
//
// Copyright (c) Carlos Tojal 2020
// Bank
// ListClientsWindow.java
//

package ui;

import java.util.ArrayList;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowEvent;
import java.awt.GridLayout;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JList;
import javax.swing.JScrollPane;
import javax.swing.ListSelectionModel;
import javax.swing.JOptionPane;
import java.lang.NumberFormatException;
import java.lang.Exception;

import structures.Client;
import management.ClientManagement;

public class ListClientsWindow {
    // Attributes
    private ArrayList<Client> clients;
    private ArrayList<String> options;
    private ClientManagement clientManagement;
    private JFrame frame;
    private JPanel panel;
    private JList<String> list;

    // Constructor
    public ListClientsWindow() {
        frame = new JFrame("List Clients - Bank");
        panel = new JPanel(new GridLayout(7, 1));

        clientManagement = new ClientManagement();
        clients = clientManagement.loadClients();
        options = new ArrayList<String>();

        for(int i = 0; i < clients.size(); i++) {
            options.add(clients.get(i).getId() + " (" + clients.get(i).getUsername() + ")");
            System.out.println(options.get(i));
        }

        list = new JList<String>((String[])options.toArray());

        panel.add(list);
        frame.add(panel);

        frame.setSize(400, 500);
        frame.setResizable(false);
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);
    }
}
