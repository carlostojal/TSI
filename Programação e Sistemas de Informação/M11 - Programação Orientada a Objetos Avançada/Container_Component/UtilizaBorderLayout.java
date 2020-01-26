
import java.awt.BorderLayout;
import javax.swing.JFrame;
import javax.swing.JButton;

public class UtilizaBorderLayout {
    public static void main(String[] args) {
        JFrame janela = new JFrame();
        janela.setTitle("BorderLayout");
        janela.setSize(350,150);
        janela.setLocation(50,50);
        janela.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        janela.setLayout(new BorderLayout());
        JButton botaoNorte = new JButton("Norte");
        JButton botaoSul = new JButton("Sul");
        JButton botaoOeste = new JButton("Oeste");
        JButton botaoEste = new JButton("Este");
        JButton botaoCentro = new JButton("Centro");

        janela.add("North", botaoNorte);
        janela.add("South", botaoSul);
        janela.add("West", botaoOeste);
        janela.add("East", botaoEste);
        janela.add("Center", botaoCentro);
        janela.setVisible(true);
    }
}