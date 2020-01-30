
//
// Copyright (c) Carlos Tojal 2020
// Bank
// ListAccountMovementsWindow.java
//

package ui;

import java.util.ArrayList;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowEvent;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.GridLayout;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JLabel;
import javax.swing.JList;
import javax.swing.JScrollPane;
import javax.swing.ListSelectionModel;
import javax.swing.JOptionPane;
import java.lang.Exception;

import structures.Account;
import structures.Client;
import management.AccountManagement;
import management.ClientManagement;

public class ListAccountMovementsWindow {
    // Attributes
    private Client client;
    private ArrayList<Client> clients;
    private ArrayList<String> options;
    private ClientManagement clientManagement;
    private JFrame frame;
    private JPanel panel;
    private JLabel label;
    private JList<String> list;

    // Constructor
    public ListAccountMovementsWindow(Account account) {
        frame = new JFrame("List Account Movements - Bank");
        panel = new JPanel(new GridLayout(1, 1));

        label = new JLabel("No movements in this account.");

        if(account.getAccountMovements().size() > 0) {
            options = new ArrayList<String>();

            for (int i = 0; i < account.getAccountMovements().size(); i++) {
                String output = "";
                output += account.getAccountMovements().get(i).getType() == 1 ? "DEPOSIT - " : "WITHDRAW - ";
                output += account.getAccountMovements().get(i).getValue();
                options.add(output);
            }

            list = new JList<String>((String[]) options.toArray(new String[0]));
            JScrollPane scrollPane = new JScrollPane(list);

            panel.add(scrollPane);
        } else {
            panel.add(label);
        }

        frame.add(panel);

        frame.setSize(400, 500);
        frame.setResizable(false);
        frame.setLocationRelativeTo(null);
        frame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        frame.setVisible(true);
    }
}