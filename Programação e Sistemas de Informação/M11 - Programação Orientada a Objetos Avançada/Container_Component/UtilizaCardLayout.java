
import java.awt.BorderLayout;
import java.awt.GridLayout;
import java.awt.CardLayout;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JLabel;
import javax.swing.JButton;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class UtilizaCardLayout implements ActionListener {
    JFrame janela = new JFrame();
    JPanel painelBotoes = new JPanel();
    JButton botao1 = new JButton("Painel 1");
    JButton botao2 = new JButton("Painel 2");
    JPanel painelRotulo1 = new JPanel();
    JPanel painelRotulo2 = new JPanel();
    JLabel rotulo1 = new JLabel("Painel 1");
    JLabel rotulo2 = new JLabel("Painel 2");
    JPanel painelRotulos = new JPanel();

    public static void main(String[] args) {
        new UtilizaCardLayout();
    }

    private UtilizaCardLayout() {
        janela.setTitle("Primeira aplicação gráfica - CardLayout");
        janela.setSize(350, 150);
        janela.setLocation(50, 50);
        janela.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        janela.setLayout(new BorderLayout());
        painelBotoes.setLayout(new GridLayout(1, 2));

        painelBotoes.add(botao1);
        painelBotoes.add(botao2);
        painelRotulo1.add(rotulo1);
        painelRotulo2.add(rotulo2);
        painelRotulos.setLayout(new CardLayout());
        painelRotulos.add(painelRotulo1, "p1");
        painelRotulos.add(painelRotulo2, "p2");
        janela.add("North", painelBotoes);
        janela.add("South", painelRotulos);
        botao1.addActionListener(this);
        botao2.addActionListener(this);
        janela.setVisible(true);
    }

    public void actionPerformed(ActionEvent e) {
        CardLayout cl = (CardLayout) painelRotulos.getLayout();
        if (e.getSource() == botao1)
            cl.show(painelRotulos, "p1");
        if (e.getSource() == botao2)
            cl.show(painelRotulos, "p2");
    }
}