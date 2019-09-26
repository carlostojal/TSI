
//
// Copyright (c) Carlos Tojal (carlostojal)
// MainScreen.java
// MyApp
// APIs
// github.com/carlostojal/TSI
//

// Elementos da interface gráfica
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JTextArea;
import javax.swing.JButton;
import javax.swing.JScrollPane;

// APIs do sistema Windows (Abstract Windows Toolkit)
import java.awt.Font;
import java.awt.Color;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

// API do sistema para comunicação em rede a baixo nível (Sockets)
import java.net.Socket;

// A minha API "MyAPI", que comunica com o meu serviço "MyService"
import myapi.MyAPI;

public class MainScreen {
    // Declaração dos objetos da interface gráfica
    private JFrame frame;
    private JPanel panel;
    private JTextArea textArea;
    private boolean isConnected;
    private String message;
    private Socket socket;
    
    // Construtor da classe atual (executado aquando da instanciação do respetivo objeto)
    public MainScreen() {
        message = "";
        isConnected = false;
        
        // Criação da interface gráfica
        frame = new JFrame();
        panel = new JPanel(new GridLayout(1, 1));
        
        textArea = new JTextArea();
        textArea.setEditable(false);
        
        JScrollPane scroll = new JScrollPane (textArea, JScrollPane.VERTICAL_SCROLLBAR_ALWAYS, JScrollPane.HORIZONTAL_SCROLLBAR_ALWAYS);
        
        panel.add(scroll);
        
        frame.setTitle("Ecrã Principal - MyApp");
        frame.setSize(500, 400);
        frame.add(panel);
        
        // Torna visível a "JFrame", que contém já o "JPanel", que por sua vez contém todos os elementos da interface gráfica
        frame.setVisible(true);
        
        // Execução do método "connect()", pertencente à minha API
        socket = new MyAPI().connect("192.168.56.1", 555); // recebe o endereço IPv4 e porta na qual corre o serviço
        if(socket.isConnected()) {
            isConnected = true;
            textArea.setText(textArea.getText()+"\n[MyAPI] Conectou ao serviço MyService com sucesso.");
        } else {
            textArea.setText(textArea.getText()+"\n[MyAPI] O serviço MyService está inacessível.");
        }
        
        if(isConnected) {
            loadMessages();
        }
    }
    
    // Método que continuamente tenta obter mensagens do serviço
    public void loadMessages() {
        while(!message.equals("exit")) {
            // Execução do método "loadMessage()" da minha API, que retorna a última mensagem enviada pelo serviço
            String message = new MyAPI().loadMessage(socket);
            //Adição da última mensagem à área de texto
            textArea.setText(textArea.getText()+"\n[MyService] "+message);
        }
        textArea.setText(textArea.getText()+"\n[MyAPI] O serviço MyService foi encerrado.");
    }
}
