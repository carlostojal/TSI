
//
// Copyright (c) Carlos Tojal 2020
// Bank
// ClientManagement.java
//

package management;

import java.util.ArrayList;
import java.util.Random;
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
import management.AccountManagement;

public class ClientManagement {
    // Constructor
    public ClientManagement() {

    }

    // Methods
    public String generateId() {
        int leftLimit = 48; // number 0
        int rightLimit = 57; // letter 9
        int targetStringLength = 8;
        Random random = new Random();
        StringBuilder buffer = new StringBuilder(targetStringLength);
        for (int i = 0; i < targetStringLength; i++) {
            int randomLimitedInt = leftLimit + (int)
                    (random.nextFloat() * (rightLimit - leftLimit + 1));
            buffer.append((char) randomLimitedInt);
        }
        String generatedString = buffer.toString();
        return generatedString;
    }

    public ArrayList<Client> loadClients() {
        AccountManagement accountManagement = new AccountManagement();
        ArrayList<Client> clients = new ArrayList<Client>();
        ArrayList<Account> accounts = new ArrayList<Account>();
        String raw;
        Client client = new Client();
        File f;
        FileReader fr;
        BufferedReader br;
        // Loads clients
        try {
            f = new File("clients.csv");
            fr = new FileReader(f);
            br = new BufferedReader(fr);
            while ((raw = br.readLine()) != null) {
                client.setId(raw.split(";")[0]);
                client.setName(raw.split(";")[1]);
                client.setUsername(raw.split(";")[2]);
                client.setPin(Integer.parseInt(raw.split(";")[3]));
                client.setAccounts(new ArrayList<Account>());
                client.setAccess_level(Byte.parseByte(raw.split(";")[4]));
                clients.add(client);
            }
            fr.close();
            br.close();
            // Loads client accounts
            accountManagement.loadAccounts(clients);
        } catch(FileNotFoundException e) {
            System.out.println("[ERROR] File \"clients.csv\" was not found.");
            // e.printStackTrace();
        } catch(IOException e) {
            System.out.println("[ERROR] Couldn't load file \"clients.csv\".");
            // e.printStackTrace();
        } catch(Exception e) {
            System.out.println("[ERROR] An error has occurred.");
            // e.printStackTrace();
        }
        return clients;
    }

    public void registerClient(Client client) {
        File f;
        FileWriter fw;
        BufferedWriter bw;
        try {
            fw = new FileWriter("clients.csv", true);
            bw = new BufferedWriter(fw);
            bw.newLine();
            bw.write(client.getId() + ";" + client.getName() + ";" + client.getUsername() + ";" + client.getPin() + ";" + client.getAccess_level());
            bw.close();
        } catch(FileNotFoundException e) {
            System.out.println("[ERROR] File \"clients.csv\" was not found.");
            // e.printStackTrace();
        } catch(IOException e) {
            System.out.println("[ERROR] Couldn't load file \"clients.csv\".");
            // e.printStackTrace();
        } catch(Exception e) {
            System.out.println("[ERROR] An error has occurred.");
            // e.printStackTrace();
        }
    }
}