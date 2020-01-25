
//
// Copyright (c) Carlos Tojal 2020
// Bank
// ControlPanel.java
//

package ui;

import java.util.ArrayList;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.GridLayout;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JLabel;
import javax.swing.JButton;
import javax.swing.JOptionPane;

import structures.Client;
import management.ClientManagement;

public class ControlPanel {
    // Attributes
    private Client client;
    private ArrayList<Client> clients;
    private ClientManagement clientManagement;
    private JFrame frame;
    private JPanel panel;
    private JLabel title;
    private JButton register_client;
    private JButton list_clients;
    private JButton view_data;
    private JButton deposit;
    private JButton withdraw;

    // Constructor
    public ControlPanel(Client client) {
        this.client = client;
        clientManagement = new ClientManagement();
        clients = clientManagement.loadClients();
        frame = new JFrame("Bank");
        panel = new JPanel(new GridLayout(5, 2));
        title = new JLabel("Welcome, " + client.getName());
        register_client = new JButton("Register client");
        list_clients = new JButton("List clients");
        view_data = new JButton("View data");
        deposit = new JButton("Deposit");
        withdraw = new JButton("Withdraw");

        panel.add(title);
        if(client.getAccess_level() == 2) {
            panel.add(register_client);
            panel.add(list_clients);
        }
        panel.add(view_data);
        panel.add(deposit);
        panel.add(withdraw);

        frame.add(panel);

        frame.setSize(600, 450);
        frame.setResizable(false);
        frame.setLocationRelativeTo(null);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);

        register_client.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                new RegisterClientWindow();
            }
        });

        list_clients.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                new ListClientsWindow();
            }
        });

        view_data.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e) {
                String data = "";
                data += "Client ID: " + client.getId() + "\n";
                data += "Name: " + client.getName() + "\n";
                data += "Username: " + client.getUsername() + "\n";
                data += "PIN: " + client.getPin() + "\n";
                data += "Access level: " + client.getAccess_level() + "\n";
                data += "Number of accounts: " + client.getAccounts().size();
                JOptionPane.showMessageDialog(null, data, "Client data", JOptionPane.PLAIN_MESSAGE);
            }
        });
    }
}