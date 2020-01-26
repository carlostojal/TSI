
import javax.swing.JFrame;
import javax.swing.JCheckBox;
import java.awt.FlowLayout;

public class UsaJCheckBox {
    public static void main(String[] args) {
        JFrame janela = new JFrame();
        janela.setTitle("JCheckBox");
        janela.setSize(350,150);
        janela.setLocation(50,50);
        janela.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        janela.setLayout(new FlowLayout());
        JCheckBox caixaVerificacao1 = new JCheckBox("Branco");
        JCheckBox caixaVerificacao2 = new JCheckBox("Preto");
        JCheckBox caixaVerificacao3 = new JCheckBox("Amarelo");

        janela.add(caixaVerificacao1);
        janela.add(caixaVerificacao2);
        janela.add(caixaVerificacao3);
        janela.setVisible(true);
    }
}