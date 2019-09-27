
//
// Copyright (c) Carlos Tojal (carlostojal)
// MainScreen.java
// MyApp
// APIs
// github.com/carlostojal/TSI
//

// Código do ecrã principal da app

// Elementos da interface gráfica
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JTextArea;
import javax.swing.JButton;
import javax.swing.JScrollPane;

// Package que comunica com API do sistema para criação e gestão de janelas e respetivos eventos (Abstract Windows Toolkit)
import java.awt.Font;
import java.awt.Color;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

// Package que comunica com o sistema através de uma API para 
// permitir comunicação em rede
import java.net.Socket; // Socket é uma classe que permite comunicação em rede a baixo nível
// através do protocolo de rede TCP/IP (vai ser utilizado pela nossa API para comunicar com o serviço)

// A minha API, que comunica com o meu serviço "MyService"
import myservice.API;

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
        // Inicialização dos atributos
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
        
        // Torna visível a "JFrame", que contém já o "JPanel", que por sua vez contém todos os elementos da interface gráfica (comunica com
        // o sistema através de uma API do sistema, para permitir que a janela apareça)
        frame.setVisible(true);
        
        // Execução do método "connect()", pertencente à minha API (inicializa o atributo "socket")
        socket = new API().connect("192.168.56.1", 555); // recebe o endereço IPv4 e porta na qual corre o serviço
        if(socket.isConnected()) {
            isConnected = true;
            textArea.setText(textArea.getText()+"\n[MyService API] Conectou ao serviço MyService com sucesso.");
        } else {
            textArea.setText(textArea.getText()+"\n[MyService API] O serviço MyService está inacessível.");
        }
        
        if(isConnected) {
            loadMessages();
        }
    }
    
    // Método que continuamente tenta obter mensagens do serviço
    public void loadMessages() {
        while(!message.equals("exit")) {
            // Execução do método "loadMessage()" da minha API, que retorna a última mensagem enviada pelo serviço
            String message = new API().loadMessage(socket);
            //Adição da última mensagem à área de texto
            textArea.setText(textArea.getText()+"\n[MyService] "+message);
        }
        textArea.setText(textArea.getText()+"\n[MyAPI] O serviço MyService foi encerrado.");
    }
}
