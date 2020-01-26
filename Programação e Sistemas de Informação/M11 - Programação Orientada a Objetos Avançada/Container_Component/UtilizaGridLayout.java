
import java.awt.GridLayout;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JTextField;
import javax.swing.JComboBox;
import javax.swing.JButton;

public class UtilizaGridLayout {
    public static void main(String[] args) {
        JFrame janela = new JFrame();
        janela.setTitle("GridLayout");
        janela.setSize(350,150);
        janela.setLocation(50,50);
        janela.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        janela.setLayout(new GridLayout(3,2));
        JLabel rotulo1 = new JLabel("Seleccione um fruto: ");
        JTextField caixaTexto = new JTextField(10);
        JLabel rotulo2 = new JLabel ("Seleccione uma bebida: ");
        JComboBox<String> caixaCombinacao = new JComboBox<String>();
        caixaCombinacao.addItem("Água");
        caixaCombinacao.addItem("Leite");
        caixaCombinacao.addItem("Vinho");
        JButton botao = new JButton("OK");

        janela.add(rotulo1);
        janela.add(caixaTexto);
        janela.add(rotulo2);
        janela.add(caixaCombinacao);
        janela.add(botao);
        janela.setVisible(true);
    }
}