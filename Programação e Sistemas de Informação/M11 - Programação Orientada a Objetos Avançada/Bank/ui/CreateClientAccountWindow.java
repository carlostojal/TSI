
//
// Copyright (c) Carlos Tojal 2020
// Bank
// CreateClientAccountWindow.java
//

package ui;

import java.util.ArrayList;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowEvent;
import java.awt.GridLayout;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JLabel;
import javax.swing.JTextField;
import javax.swing.JButton;
import javax.swing.JOptionPane;
import java.lang.NumberFormatException;
import java.lang.Exception;

import structures.Client;
import structures.Account;
import management.ClientManagement;
import management.AccountManagement;

public class CreateClientAccountWindow {
    // Attributes
    private Client client;
    private Account account;
    private ClientManagement clientManagement;
    private AccountManagement accountManagement;
    private JFrame frame;
    private JPanel panel;
    private JLabel id_label;
    private JTextField id;
    private JLabel name_label;
    private JTextField name;
    private JButton confirm;

    // Constructor
    public CreateClientAccountWindow(Client client) {
        frame = new JFrame("Create Client Account - Bank");
        panel = new JPanel(new GridLayout(5, 1));
        id_label = new JLabel("Account ID: ");
        id = new JTextField();
        name_label = new JLabel("Client Name: ");
        name = new JTextField();
        confirm = new JButton("Confirm");

        this.client = client;

        clientManagement = new ClientManagement();
        accountManagement = new AccountManagement();
        account = new Account(client.getId(), clientManagement.generateId(), 0.00);

        id.setText(account.getId());
        id.setEditable(false);
        name.setText(client.getName());
        name.setEditable(false);

        panel.add(id_label);
        panel.add(id);
        panel.add(name_label);
        panel.add(name);
        panel.add(confirm);;
        frame.add(panel);

        frame.setSize(400, 500);
        frame.setResizable(false);
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);

        confirm.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                accountManagement.registerAccount(account);
                JOptionPane.showMessageDialog(null, "Account created successfully.", "Success", JOptionPane.INFORMATION_MESSAGE);
                frame.setVisible(false);
            }
        });
    }
}