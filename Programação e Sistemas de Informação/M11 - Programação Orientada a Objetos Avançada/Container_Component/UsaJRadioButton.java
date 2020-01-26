
import javax.swing.JFrame;
import javax.swing.JRadioButton;
import java.awt.FlowLayout;

public class UsaJRadioButton {
    public static void main(String[] args) {
        JFrame janela = new JFrame();
        janela.setTitle("JRadioButton");
        janela.setSize(350,150);
        janela.setLocation(50,50);
        janela.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        janela.setLayout(new FlowLayout());
        JRadioButton botaoRadio1 = new JRadioButton("Branco");
        JRadioButton botaoRadio2 = new JRadioButton("Preto");
        JRadioButton botaoRadio3 = new JRadioButton("Amarelo");

        janela.add(botaoRadio1);
        janela.add(botaoRadio2);
        janela.add(botaoRadio3);
        janela.setVisible(true);
    }
}