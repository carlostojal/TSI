
//
// Copyright (c) Carlos Tojal 2020
// Bank
// MainWindow.java
//

package ui;

import javax.swing.UIManager;
import javax.swing.UnsupportedLookAndFeelException;
import java.lang.Exception;

import structures.Client;
import ui.LoginWindow;
import ui.ControlPanel;

public class MainWindow {

    // Attributes
    private Client client;

    // Constructor
    public MainWindow() {
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

        client = new LoginWindow().getClient();
        new ControlPanel(client);
    }
}