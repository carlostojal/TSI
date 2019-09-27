package myservice;

//
// Copyright © Carlos Tojal (carlostojal)
// API.java
// MyAPI
// APIs
// github.com/carlostojal/TSI
//

// APIs do sistema responsáveis pela comunicação em rede
import java.net.Socket;
import java.net.UnknownHostException;

// APIs do sistema responsáveis pelo input/output
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class API {
    private Socket socket; // objeto responsável pela comunicação em rede a baixo nível
    private BufferedReader in; // objeto que vai ler os dados enviados pelo serviço
    
    // Método que faz a ligação ao endereço IPv4 e porta fornecidos como argumento
    public Socket connect(String address, int port) {
        try {
            socket = new Socket(address, port);
        } catch (UnknownHostException e) {
            
        } catch (IOException e) {
            
        }
        return socket;
    }
    
    //Método que recebe a primeira mensagem enviada pelo serviço após o último recebimento pela API (primeira linha da lista de recebimentos)
    // (este método)
    public String loadMessage(Socket socket) {
        String message = "";
        try {
            in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            message = in.readLine(); // leitura da linha
        } catch (IOException e) { // em caso de erro ao tentar ler (a conexão deixou de estar disponível)
            return "Erro ao aceder ao serviço.";
        }
        return message;
    }
}
