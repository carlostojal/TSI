
//
// Copyright (c) Carlos Tojal 2020
// FT3
// ConversorTemperaturaVersaoAvancada.java
//

import java.awt.GridLayout;
import java.awt.FlowLayout;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JRadioButton;
import javax.swing.ButtonGroup;
import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.JButton;
import javax.swing.JOptionPane;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.event.ItemListener;
import java.awt.event.ItemEvent;

public class ConversorTemperaturaVersaoAvancada implements ActionListener, ItemListener {
    JFrame janela = new JFrame();
    JLabel rotulo1 = new JLabel("Tipo de conversão: ");
    JRadioButton botaoRadio1 = new JRadioButton("ºC->ºF");
    JRadioButton botaoRadio2 = new JRadioButton("ºF->ºC");
    ButtonGroup grupo = new ButtonGroup();
    JPanel painel = new JPanel();
    JLabel rotulo2 = new JLabel("Valor a converter: ");
    JTextField caixaTexto1 = new JTextField(5);
    JButton botao1 = new JButton("Converter");

    private ConversorTemperaturaVersaoAvancada() {
        janela.setTitle("Conversor Temperatura");
        janela.setSize(300, 125);
        janela.setLocation(50, 50);
        janela.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        janela.setLayout(new GridLayout(3, 2));
        janela.add(rotulo1);
        painel.setLayout(new GridLayout(1, 2));
        painel.add(botaoRadio1);
        painel.add(botaoRadio2);
        janela.add(painel);
        janela.add(rotulo2);
        janela.add(caixaTexto1);
        janela.add(botao1);

        grupo.add(botaoRadio1);
        grupo.add(botaoRadio2);
        botaoRadio1.addItemListener(this);
        botaoRadio2.addItemListener(this);
        botao1.addActionListener(this);

        janela.setVisible(true);
    }

    public static void main(String[] args) {
        new ConversorTemperaturaVersaoAvancada();
    }

    public void actionPerformed(ActionEvent e) {
        double resultado;
        String mensagem = "";

        if(e.getSource() == botao1) {
            if(botaoRadio1.isSelected()) {
                resultado = Double.parseDouble(caixaTexto1.getText()) * 9 / 5 + 32;
                mensagem = Double.toString(resultado) + "ºF";
            } else if(botaoRadio2.isSelected()) {
                resultado = Double.parseDouble(caixaTexto1.getText()) - 32 * 5 / 9;
                mensagem = Double.toString(resultado) + "ºC";
            } else {
                mensagem = "Não selecionou nenhuma opção!";
            }
        }

        JOptionPane.showMessageDialog(null, mensagem);
    }

    public void itemStateChanged(ItemEvent e) {
        if(e.getSource() == botaoRadio1) {
            if(e.getStateChange() == ItemEvent.SELECTED)
                JOptionPane.showMessageDialog(null, "ºC->ºF");
        }
        if(e.getSource() == botaoRadio2) {
            if(e.getStateChange() == ItemEvent.SELECTED)
                JOptionPane.showMessageDialog(null, "ºF->ºC");
        }
    }
}


