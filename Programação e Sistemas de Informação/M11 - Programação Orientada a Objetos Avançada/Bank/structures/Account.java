
//
// Copyright (c) Carlos Tojal 2020
// Bank
// Account.java
//

package structures;

public class Account {
    // Attributes
    private String id;
    private double balance;

    // Constructors
    public Account() {
        this.id = "AccountID";
        this.balance = 0.00;
    }

    public Account(String id, double balance) {
        this.id = id;
        this.balance = balance;
    }

    // Getters and setters
    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
    }

    public double getBalance() {
        return balance;
    }

    public void setBalance(double balance) {
        this.balance = balance;
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