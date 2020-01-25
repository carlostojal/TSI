
//
// Copyright (c) Carlos Tojal 2020
// Bank
// RegisterClientWindow.java
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
import javax.swing.JPasswordField;
import javax.swing.JButton;
import javax.swing.JOptionPane;
import java.lang.NumberFormatException;
import java.lang.Exception;

import structures.Client;
import management.ClientManagement;

public class RegisterClientWindow {
    // Attributes
    private Client client;
    private ArrayList<Client> clients;
    private ClientManagement clientManagement;
    private JFrame frame;
    private JPanel panel;
    private JLabel name_label;
    private JTextField name;
    private JLabel username_label;
    private JTextField username;
    private JLabel pin_label;
    private JTextField pin;
    private JButton register;

    // Constructor
    public RegisterClientWindow() {
        frame = new JFrame("Register Client - Bank");
        panel = new JPanel(new GridLayout(7, 1));
        name_label = new JLabel("Name: ");
        name = new JTextField();
        username_label = new JLabel("Username: ");
        username = new JTextField();
        pin_label = new JLabel("Pin: ");
        pin = new JPasswordField();
        register = new JButton("Register");

        panel.add(name_label);
        panel.add(name);
        panel.add(username_label);
        panel.add(username);
        panel.add(pin_label);
        panel.add(pin);
        panel.add(register);
        frame.add(panel);

        frame.setSize(400, 500);
        frame.setResizable(false);
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);

        register.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                boolean inputSuccess = true;
                client = new Client();
                clientManagement = new ClientManagement();
                clients = clientManagement.loadClients();
                client.setId(clientManagement.generateId());
                client.setName(name.getText());
                client.setUsername(username.getText());
                client.setAccess_level((byte) 1);
                try {
                    client.setPin(Integer.parseInt(pin.getText()));
                } catch(NumberFormatException nfe) {
                    inputSuccess = false;
                    System.out.println("[ERROR] Invalid pin input.");
                    JOptionPane.showMessageDialog(null, "Invalid pin input.", "Error", JOptionPane.ERROR_MESSAGE);
                }
                if(inputSuccess) {
                    clientManagement.registerClient(client);
                    JOptionPane.showMessageDialog(null, "Client registered successfully.", "Success", JOptionPane.INFORMATION_MESSAGE);
                    frame.setVisible(false);
                }
            }
        });
    }

    // Getters
    public Client getClient() {
        return client;
    }
}