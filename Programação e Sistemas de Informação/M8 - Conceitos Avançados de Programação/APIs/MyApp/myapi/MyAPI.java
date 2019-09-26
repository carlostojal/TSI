package myapi;

//
// Copyright © Carlos Tojal (carlostojal)
// MyAPI.java
// MyAPI
// APIs
// github.com/carlostojal/TSI
//

import java.net.Socket;
import java.net.UnknownHostException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class MyAPI
{
    private Socket socket;
    private BufferedReader in;
    
    public Socket connect(String address, int port) {
        try {
            socket = new Socket(address, port);
        } catch (UnknownHostException e) {
            
        } catch (IOException e) {
            
        }
        
        return socket;
    }
    
    public String loadMessage(Socket socket) {
        String message = "";
        
        try {
            in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            
            message = in.readLine();
        } catch (IOException e) {
            return "Erro ao aceder ao serviço.";
        }
        
        return message;
    }
}
