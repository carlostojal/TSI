
//
// Copyright (c) Carlos Tojal 2020
// Container_Component
// UsaJLabel.java
//

import javax.swing.JFrame;
import javax.swing.JLabel;

public class UsaJLabel {
    public static void main(String[] args) {
        JFrame janela = new JFrame();
        janela.setTitle("JPanel");
        janela.setSize(350, 150);
        janela.setLocationRelativeTo(null);
        // janela.setLocation(50, 50);
        janela.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JLabel rotulo = new JLabel("Escreva o seu nome: ");
        janela.add(rotulo);
        janela.setVisible(true);
    }
}
