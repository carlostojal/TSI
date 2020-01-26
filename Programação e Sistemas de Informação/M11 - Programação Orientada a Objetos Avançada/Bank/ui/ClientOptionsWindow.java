
//
// Copyright (c) Carlos Tojal 2020
// Bank
// ListClientAccountsWindow.java
//

package ui;

import java.util.ArrayList;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.GridLayout;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JOptionPane;
import javax.swing.JButton;
import java.lang.Exception;

import structures.Client;
import ui.ListClientAccountsWindow;
import ui.CreateClientAccountWindow;

public class ClientOptionsWindow {
    // Attributes
    private Client client;
    private JFrame frame;
    private JPanel panel;
    private JButton list_accounts;
    private JButton create_account;

    // Constructor
    public ClientOptionsWindow(Client client) {
        frame = new JFrame("Client Options - Bank");
        panel = new JPanel(new GridLayout(1, 2));
        list_accounts = new JButton("List Accounts");
        create_account = new JButton("Create Account");

        this.client = client;

        panel.add(list_accounts);
        panel.add(create_account);
        frame.add(panel);

        frame.setSize(400, 500);
        frame.setResizable(false);
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);

        list_accounts.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                new ListClientAccountsWindow(client, (byte) 1);
                frame.setVisible(false);
            }
        });

        create_account.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                new CreateClientAccountWindow(client);
                frame.setVisible(false);
            }
        });
    }
}
