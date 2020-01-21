
//
// Copyright (c) Carlos Tojal 2020
// Container_Component
// UsaJFrame.java
//

import javax.swing.JFrame;

public class UsaJFrame {
    public static void main(String[] args) {
        JFrame janela = new JFrame();
        janela.setTitle("JFrame");
        janela.setSize(350, 150);
        janela.setLocation(50, 50);
        janela.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        janela.setVisible(true);
    }
}
