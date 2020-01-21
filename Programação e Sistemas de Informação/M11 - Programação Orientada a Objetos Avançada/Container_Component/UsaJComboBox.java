
//
// Copyright (c) Carlos Tojal 2020
// Container_Component
// UsaJComboBox.java
//

import javax.swing.JFrame;
import javax.swing.JComboBox;
import javax.swing.JLabel;
import java.awt.FlowLayout;

public class UsaJComboBox {
    public static void main(String[] args) {
        JFrame janela = new JFrame();
        janela.setTitle("JComboBox");
        janela.setSize(350, 150);
        janela.setLocationRelativeTo(null);
        // janela.setLocation(50, 50);
        janela.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        janela.setLayout(new FlowLayout());
        JLabel rotulo = new JLabel("Escreva o seu nome: ");
        JComboBox caixaCombinacao = new JComboBox();
        janela.add(rotulo);
        caixaCombinacao.addItem("Branco");
        caixaCombinacao.addItem("Preto");
        caixaCombinacao.addItem("Amarelo");
        janela.add(caixaCombinacao);
        janela.setVisible(true);
    }
}
