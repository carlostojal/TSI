
//
// Copyright (c) Carlos Tojal 2020
// Bank
// AccountManagement.java
//

package management;

import java.util.ArrayList;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.lang.Exception;

import structures.Client;
import structures.Account;
import structures.AccountMovement;

public class AccountManagement {
    // Constructor
    public AccountManagement() {

    }

    // Methods
    public void loadAccountMovements(Account account) {
        ArrayList<AccountMovement> movements = new ArrayList<AccountMovement>();
        String raw;
        AccountMovement movement = new AccountMovement();
        File f;
        FileReader fr;
        BufferedReader br;
        // Loads client accounts
        try {
            f = new File("account_movements.csv");
            fr = new FileReader(f);
            br = new BufferedReader(fr);
            while ((raw = br.readLine()) != null) {
                if (account.getId().equals(raw.split(";")[0])) {
                    String account_id = raw.split(";")[0];
                    double value = Double.parseDouble(raw.split(";")[1]);
                    byte type = (byte) Integer.parseInt(raw.split(";")[2]);
                    account.getAccountMovements().add(new AccountMovement(account_id, value, type));
                    account.setAccountMovements(account.getAccountMovements());
                    if(type == 1)
                        account.deposit(value);
                    else
                        account.withdraw(value);
                }
            }
            fr.close();
            br.close();
        } catch(FileNotFoundException e) {
            System.out.println("[ERROR] File \"accounts.csv\" was not found.");
            // e.printStackTrace();
        } catch(IOException e) {
            System.out.println("[ERROR] Couldn't load file \"accounts.csv\".");
            // e.printStackTrace();
        } catch(Exception e) {
            System.out.println("[ERROR] An error has occurred.");
            // e.printStackTrace();
        }
    }

    public void registerAccountMovement(AccountMovement accountMovement) {
        File f;
        FileWriter fw;
        BufferedWriter bw;
        try {
            fw = new FileWriter("account_movements.csv", true);
            bw = new BufferedWriter(fw);
            bw.newLine();
            bw.write(accountMovement.getAccount_id() + ";" + accountMovement.getValue() + ";" + accountMovement.getType());
            bw.close();
        } catch(FileNotFoundException e) {
            System.out.println("[ERROR] File \"account_movements.csv\" was not found.");
            // e.printStackTrace();
        } catch(IOException e) {
            System.out.println("[ERROR] Couldn't load file \"account_movements.csv\".");
            // e.printStackTrace();
        } catch(Exception e) {
            System.out.println("[ERROR] An error has occurred.");
            // e.printStackTrace();
        }
    }

    public void loadAccounts(ArrayList<Client> clients) {
        ArrayList<Account> accounts = new ArrayList<Account>();
        String raw;
        Account account = new Account();
        File f;
        FileReader fr;
        BufferedReader br;
        // Loads client accounts
        try {
            f = new File("accounts.csv");
            fr = new FileReader(f);
            br = new BufferedReader(fr);
            while ((raw = br.readLine()) != null) {
                for (int i = 0; i < clients.size(); i++) {
                    if (clients.get(i).getId().equals(raw.split(";")[0])) {
                        String client_id = raw.split(";")[0];
                        String id = raw.split(";")[1];
                        clients.get(i).getAccounts().add(new Account(client_id, id, 0.0));
                        // load last added account movements
                        loadAccountMovements(clients.get(i).getAccounts().get(clients.get(i).getAccounts().size() - 1));
                        clients.get(i).setAccounts(clients.get(i).getAccounts());
                    }
                }
            }
            fr.close();
            br.close();
        } catch(FileNotFoundException e) {
            System.out.println("[ERROR] File \"accounts.csv\" was not found.");
            // e.printStackTrace();
        } catch(IOException e) {
            System.out.println("[ERROR] Couldn't load file \"accounts.csv\".");
            // e.printStackTrace();
        } catch(Exception e) {
            System.out.println("[ERROR] An error has occurred.");
            // e.printStackTrace();
        }
    }

    public void registerAccount(Account account) {
        File f;
        FileWriter fw;
        BufferedWriter bw;
        try {
            fw = new FileWriter("accounts.csv", true);
            bw = new BufferedWriter(fw);
            bw.newLine();
            bw.write(account.getClient_id() + ";" + account.getId());
            bw.close();
        } catch(FileNotFoundException e) {
            System.out.println("[ERROR] File \"accounts.csv\" was not found.");
            // e.printStackTrace();
        } catch(IOException e) {
            System.out.println("[ERROR] Couldn't load file \"accounts.csv\".");
            // e.printStackTrace();
        } catch(Exception e) {
            System.out.println("[ERROR] An error has occurred.");
            // e.printStackTrace();
        }
    }
}