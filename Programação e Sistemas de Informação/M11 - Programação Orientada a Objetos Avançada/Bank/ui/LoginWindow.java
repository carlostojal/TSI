
//
// Copyright (c) Carlos Tojal 2020
// Bank
// LoginWindow.java
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
import javax.swing.UIManager;
import javax.swing.UnsupportedLookAndFeelException;
import java.lang.NumberFormatException;
import java.lang.Exception;

import structures.Client;
import management.ClientManagement;

public class LoginWindow {
    // Attributes
    private Client client;
    private ArrayList<Client> clients;
    private ClientManagement clientManagement;
    private JFrame frame;
    private JPanel panel;
    private JLabel username_label;
    private JTextField username;
    private JLabel pin_label;
    private JTextField pin;
    private JButton login;

    // Constructor
    public LoginWindow() {
        try {
            UIManager.setLookAndFeel(UIManager.getSystemLookAndFeelClassName());
            System.out.println("[MESSAGE] Set system look and feel.");
        } catch(UnsupportedLookAndFeelException e) {
            System.out.println("[ERROR] System look and feel not supported.");
        } catch(ClassNotFoundException e) {
            System.out.println("[ERROR] System look and feel not found.");
        } catch(InstantiationException e) {
            System.out.println("[ERROR] Error setting system look and feel.");
        } catch(IllegalAccessException e) {
            System.out.println("[ERROR] Couldn't access system look and feel.");
        }

        clientManagement = new ClientManagement();
        clients = clientManagement.loadClients();

        frame = new JFrame("Login - Bank");
        panel = new JPanel(new GridLayout(5, 1));
        username_label = new JLabel("Username: ");
        username = new JTextField();
        pin_label = new JLabel("PIN: ");
        pin = new JPasswordField();
        login = new JButton("Login");

        panel.add(username_label);
        panel.add(username);
        panel.add(pin_label);
        panel.add(pin);
        panel.add(login);
        frame.add(panel);

        frame.setSize(400, 300);
        frame.setResizable(false);
        frame.setLocationRelativeTo(null);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);

        login.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                boolean inputSuccess = true;
                client = new Client();
                client.setUsername(username.getText());
                try {
                    client.setPin(Integer.parseInt(pin.getText()));
                } catch(NumberFormatException nfe) {
                    inputSuccess = false;
                    System.out.println("[ERROR] Invalid PIN input.");
                    JOptionPane.showMessageDialog(null, "Invalid PIN input.", "Error", JOptionPane.ERROR_MESSAGE);
                }
                if(inputSuccess) {
                    if(login(client, clients)) {
                        System.out.println("[MESSAGE] Login successful.");
                        frame.setVisible(false);
                        new ControlPanel(client);
                    } else {
                        System.out.println("[MESSAGE] Invalid username or password.");
                        JOptionPane.showMessageDialog(null, "Invalid username or password.", "Error", JOptionPane.ERROR_MESSAGE);
                    }
                }
            }
        });
    }

    // Getters
    public Client getClient() {
        return client;
    }

    // Methods
    public boolean login(Client client, ArrayList<Client> clients) {
        boolean success = false;
        for(int i = 0; i < clients.size(); i++) {
            if(clients.get(i).getUsername().equals(client.getUsername()) && clients.get(i).getPin() == client.getPin()) {
                this.client = clients.get(i);
                success = true;
                return success;
            }
        }
        return success;
    }
}