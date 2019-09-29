
//
// Copyright (c) Carlos Tojal (carlostojal)
// MainScreen.java
// ButtonExample
// github.com/carlostojal/TSI
//

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JButton;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.GridLayout;

public class MainScreen {
    private JFrame frame;
    private JPanel panel;
    private JButton button;
    
    public MainScreen() {
        frame = new JFrame();
        panel = new JPanel(new GridLayout(1,1));
        
        button = new JButton("Clica-me");
        
        panel.add(button);
        
        frame.add(panel);
        
        frame.setTitle("Exemplo de Botão");
        frame.setSize(500, 300);
        frame.setVisible(true);
        
        button.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                // Código a ser executado quando o botão é clicado
            }
        });
    }
}
