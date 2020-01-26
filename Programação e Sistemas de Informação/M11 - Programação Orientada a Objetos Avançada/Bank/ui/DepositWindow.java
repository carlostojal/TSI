
//
// Copyright (c) Carlos Tojal 2020
// Bank
// DepositWindow.java
//

package ui;

import javax.swing.JOptionPane;
import java.lang.NumberFormatException;
import java.lang.Exception;

import structures.Account;
import structures.AccountMovement;
import management.AccountManagement;

public class DepositWindow {
    // Attributes
    boolean success = true;
    AccountMovement accountMovement;
    AccountManagement accountManagement;

    // Constructor
    public DepositWindow(Account account) {
        accountMovement = new AccountMovement();
        accountMovement.setType((byte) 1);
        accountManagement = new AccountManagement();
        accountMovement.setAccount_id(account.getId());
        do {
            try {
                accountMovement.setValue(Double.parseDouble(JOptionPane.showInputDialog("Value to deposit: ")));
            } catch (NumberFormatException e) {
                success = false;
                System.out.println("[ERROR] Invalid value input.");
                JOptionPane.showMessageDialog(null, "Invalid value input.", "Error", JOptionPane.ERROR_MESSAGE);
            }
            if(accountMovement.getValue() > 0) {
                account.deposit(accountMovement.getValue());
            } else {
                success = false;
                System.out.println("[ERROR] Only positive values are allowed.");
                JOptionPane.showMessageDialog(null, "Only positive values are allowed.", "Error", JOptionPane.ERROR_MESSAGE);
            }
        }while(!success);
        account.getAccountMovements().add(accountMovement);
        accountManagement.registerAccountMovement(accountMovement);
        account.setAccountMovements(account.getAccountMovements());
    }
}