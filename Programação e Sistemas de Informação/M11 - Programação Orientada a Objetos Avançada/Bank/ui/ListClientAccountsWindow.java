
//
// Copyright (c) Carlos Tojal 2020
// Bank
// ListClientAccountsWindow.java
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
import javax.swing.JList;
import javax.swing.JScrollPane;
import javax.swing.ListSelectionModel;
import javax.swing.JOptionPane;
import java.lang.Exception;

import structures.Client;
import management.ClientManagement;

public class ListClientAccountsWindow {
    // Attributes
    private Client client;
    private ArrayList<Client> clients;
    private ArrayList<String> options;
    private ClientManagement clientManagement;
    private JFrame frame;
    private JPanel panel;
    private JList<String> list;

    // Constructor
    public ListClientAccountsWindow(Client client, byte action) {
        frame = new JFrame("List Client Accounts - Bank");
        panel = new JPanel(new GridLayout(1, 1));

        this.client = client;
        clientManagement = new ClientManagement();
        clients = clientManagement.loadClients();
        options = new ArrayList<String>();

        for(int i = 0; i < client.getAccounts().size(); i++)
            options.add(client.getAccounts().get(i).getId() + " - " + client.getAccounts().get(i).getBalance());

        list = new JList<String>((String[])options.toArray(new String[0]));
        JScrollPane scrollPane = new JScrollPane(list);

        // 1 - list movements; 2 - deposit; 3 - withdraw
        list.addMouseListener(new MouseAdapter() {
            public void mouseClicked(MouseEvent evt) {
                JList list = (JList) evt.getSource();
                if(evt.getClickCount() == 2) {
                    int index = list.locationToIndex(evt.getPoint());
                    if(action == 1)
                        new ListAccountMovementsWindow(client.getAccounts().get(index));
                    else if(action == 2)
                        new DepositWindow(client.getAccounts().get(index));
                    else
                        new WithdrawWindow(client.getAccounts().get(index));
                    frame.dispose();
                }
            }
        });

        panel.add(scrollPane);
        frame.add(panel);

        frame.setSize(400, 500);
        frame.setResizable(false);
        frame.setLocationRelativeTo(null);
        frame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        frame.setVisible(true);
    }
}