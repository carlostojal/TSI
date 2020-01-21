
//
// Copyright (c) Carlos Tojal 2020
// Container_Component
// UsaJPanel.java
//

import javax.swing.JFrame;
import javax.swing.JPanel;

public class UsaJPanel {
    public static void main(String[] args) {
        JFrame janela = new JFrame();
        janela.setTitle("JPanel");
        janela.setSize(350, 150);
        janela.setLocationRelativeTo(null);
        // janela.setLocation(50, 50);
        janela.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JPanel painel = new JPanel();
        janela.add(painel);
        janela.setVisible(true);
    }
}
