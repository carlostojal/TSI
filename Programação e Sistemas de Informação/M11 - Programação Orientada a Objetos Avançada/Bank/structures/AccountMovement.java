
//
// Copyright (c) Carlos Tojal 2020
// Bank
// AccountMovement.java
//

package structures;

public class AccountMovement {
    // Attributes
    private String account_id;
    private double value;
    private byte type; // 1 - deposit; 2 - withdraw

    // Constructors
    public AccountMovement() {
        this.account_id = "AccountID";
        this.value = 0.00;
        this.type = 1;
    }

    public AccountMovement(String account_id, double value, byte type) {
        this.account_id = account_id;
        this.value = value;
        this.type = type;
    }

    // Getters and setters
    public String getAccount_id() {
        return account_id;
    }

    public void setAccount_id(String account_id) {
        this.account_id = account_id;
    }

    public double getValue() {
        return value;
    }

    public void setValue(double value) {
        this.value = value;
    }

    public byte getType() {
        return type;
    }

    public void setType(byte type) {
        this.type = type;
    }
}