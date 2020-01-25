
//
// Copyright (c) Carlos Tojal 2020
// Bank
// Client.java
//

package structures;

import java.util.ArrayList;

public class Client {
    // Attributes
    private String id;
    private String name;
    private String username;
    private int pin;
    private ArrayList<Account> accounts;
    private byte access_level; // 1 - client; 2 - bank employee

    // Constructors
    public Client() {
        this.id = "1234";
        this.name = "ClientName";
        this.accounts = new ArrayList<Account>();
    }

    public Client(String id, String name, ArrayList<Account> accounts) {
        this.id = id;
        this.name = name;
        this.accounts = accounts;
    }

    // Getters and setters
    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getUsername() {
        return username;
    }

    public void setUsername(String username) {
        this.username = username;
    }

    public int getPin() {
        return pin;
    }

    public void setPin(int pin) {
        this.pin = pin;
    }

    public ArrayList<Account> getAccounts() {
        return accounts;
    }

    public void setAccounts(ArrayList<Account> accounts) {
        this.accounts = accounts;
    }

    public byte getAccess_level() {
        return access_level;
    }

    public void setAccess_level(byte access_level) {
        this.access_level = access_level;
    }
}