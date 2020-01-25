
//
// Copyright (c) Carlos Tojal 2020
// Bank
// AccountManagement.java
//

package management;

import java.util.ArrayList;
import java.io.File;
import java.io.FileReader;
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.lang.Exception;

import structures.Client;
import structures.Account;

public class AccountManagement {
    // Constructor
    public AccountManagement() {

    }

    // Methods
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
                        String id = raw.split(";")[1];
                        double value = Double.parseDouble(raw.split(";")[2]);
                        clients.get(i).getAccounts().add(new Account(id, value));
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
}