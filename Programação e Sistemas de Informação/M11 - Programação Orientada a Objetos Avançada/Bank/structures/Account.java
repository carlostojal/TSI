
//
// Copyright (c) Carlos Tojal 2020
// Bank
// Account.java
//

package structures;

import java.util.ArrayList;

import structures.AccountMovement;

public class Account {
    // Attributes
    private String client_id;
    private String id;
    private double balance;
    private ArrayList<AccountMovement> accountMovements;

    // Constructors
    public Account() {
        this.client_id = "ClientID";
        this.id = "AccountID";
        this.balance = 0.00;
        this.accountMovements = new ArrayList<AccountMovement>();
    }

    public Account(String client_id, String id, double balance) {
        this.client_id = client_id;
        this.id = id;
        this.balance = balance;
        this.accountMovements = new ArrayList<AccountMovement>();
    }

    public Account(String client_id, String id, double balance, ArrayList<AccountMovement> accountMovements) {
        this.client_id = client_id;
        this.id = id;
        this.balance = balance;
        this.accountMovements = accountMovements;
    }

    // Getters and setters
    public String getClient_id() {
        return client_id;
    }

    public void setClient_id(String client_id) {
        this.client_id = client_id;
    }

    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
    }

    public double getBalance() {
        return balance;
    }

    public ArrayList<AccountMovement> getAccountMovements() {
        return accountMovements;
    }

    public void setAccountMovements(ArrayList<AccountMovement> accountMovements) {
        this.accountMovements = accountMovements;
    }

    // Methods
    public void deposit(double value) {
        if(value > 0)
            this.balance += value;
    }

    public void withdraw(double value) {
        if(value > 0) {
            if((this.balance - value) >= 0)
                this.balance -= value;
        }
    }
}