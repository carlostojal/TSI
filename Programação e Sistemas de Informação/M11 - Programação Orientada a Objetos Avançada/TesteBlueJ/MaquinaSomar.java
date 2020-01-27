
//
// Copyright (c) Carlos Tojal 2020
// Teste
// MaquinaSomar.java
//

import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.GridLayout;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JLabel;
import javax.swing.JTextField;
import javax.swing.JButton;
import javax.swing.JOptionPane;
import java.io.FileWriter;
import java.io.BufferedWriter;
import java.io.IOException;
import java.lang.NumberFormatException;
import java.lang.Exception;

public class MaquinaSomar {
    public static void main(String[] args) {

        JFrame frame = new JFrame("Máquina de somar");
        frame.setSize(300, 150);
        frame.setLocationRelativeTo(null);

        JPanel panel = new JPanel(new GridLayout(3, 2));

        JLabel numero_1_label = new JLabel("Primeiro número");
        JTextField numero_1 = new JTextField();
        JLabel numero_2_label = new JLabel("Segundo número");
        JTextField numero_2 = new JTextField();
        JButton somar = new JButton("Somar");

        panel.add(numero_1_label);
        panel.add(numero_1);
        panel.add(numero_2_label);
        panel.add(numero_2);
        panel.add(somar);

        frame.add(panel);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        somar.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                double n1 = 0.0, n2 = 0.0, res = 0.0;
                boolean success = true;
                try {
                    n1 = Double.parseDouble(numero_1.getText());
                    n2 = Double.parseDouble(numero_2.getText());
                    res = n1 + n2;
                } catch(NumberFormatException nfe) {
                    success = false;
                    JOptionPane.showMessageDialog(null, "Introdução inválida.", "Erro", JOptionPane.ERROR_MESSAGE);
                }
                if(success) {
                    JOptionPane.showMessageDialog(null, n1 + " + " + n2 + " = " + res, "Resultado", JOptionPane.INFORMATION_MESSAGE);
                    try {
                        FileWriter fileWriter = new FileWriter("resultado.txt");
                        BufferedWriter bufferedWriter = new BufferedWriter(fileWriter);
                        bufferedWriter.write(String.valueOf(n1) + " + " + String.valueOf(n2) + " = " + String.valueOf(res));
                        bufferedWriter.close();
                    } catch(IOException ioe) {
                        JOptionPane.showMessageDialog(null, "Erro na escrita do ficheiro.", "Erro", JOptionPane.ERROR_MESSAGE);
                    }
                }
            }
        });

        frame.setVisible(true);
    }
}
