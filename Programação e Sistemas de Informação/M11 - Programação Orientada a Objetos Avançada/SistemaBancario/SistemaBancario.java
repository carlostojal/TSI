import javax.swing.JOptionPane;
import java.lang.Exception;
import java.lang.NumberFormatException;

//
// Copyright (c) Carlos Tojal 2020
// SistemaBancario
// SistemaBancario.java
//

public class SistemaBancario
{
    public static void main(String args[])
    {


        Banco objtlimite = new Banco(0.00, 1.00, 5.00, 0.50);

        Banco objtnome = new Banco("a", "b");

        Banco objtsobre = new Banco("c", "d");

        Banco objtsaldo = new Banco(0.00, 1.00, 5.00, 0.50);

        Banco objtlevantamento = new Banco(0.00, 1.00, 5.00, 0.50);

        Banco objtcpmf = new Banco(0.00, 1.00, 5.00, 0.50);

        Banco obtjsenha = new Banco("456", "8521");

        String name = JOptionPane.showInputDialog("Digite o seu nome");
        objtnome.setNome(name);

        String sobre = JOptionPane.showInputDialog("Digite o seu sobrenome");
        objtsobre.setSobre(sobre);

        String genero;
        do {
            genero = JOptionPane.showInputDialog("Digite o seu genero (masculino/feminino)");
            objtsobre.setGenero(genero);
            if(!genero.equals("masculino") && !genero.equals("feminino"))
                JOptionPane.showMessageDialog(null, "Genero indisponível.", "Genero indisponível", JOptionPane.ERROR_MESSAGE);
        } while(!genero.equals("masculino") && !genero.equals("feminino"));

        String senha = JOptionPane.showInputDialog("Digite sua senha para acesso");
        int se = Integer.parseInt(senha);
        obtjsenha.setSenha(se);

        String textoAviso = "Dados registados com sucesso! ";
        if(genero.equals("masculino"))
            textoAviso += "Sr. ";
        else
            textoAviso += "Sra. ";
        textoAviso += name;
        String aviso = String.format(textoAviso);
        String aviso2 =  String.format("ID: %s\nSenha: %s ", name, senha);

        JOptionPane.showMessageDialog(null, aviso);
        JOptionPane.showMessageDialog(null, aviso2);


//valida dados

        String id = JOptionPane.showInputDialog("Digite sua id");
        String ss = JOptionPane.showInputDialog("Digite sua senha");

        int sh = Integer.parseInt(ss);


        if (id != name && se != sh){
            JOptionPane.showMessageDialog(null, "Dados Inválidos");
        }
        else
        {
            String deposito;
            boolean numeroInvalido = false;
            double dep = 0.00;

            do {
                deposito = JOptionPane.showInputDialog("Faca um deposito na conta");
                try {
                    dep = Double.parseDouble(deposito);
                } catch (NumberFormatException nfe) {
                    JOptionPane.showMessageDialog(null, "Valor invalido.", "Erro", JOptionPane.ERROR_MESSAGE);
                    numeroInvalido = true;
                }
            }while(numeroInvalido);

            if (dep < 20.00)
            {
                JOptionPane.showMessageDialog(null, "De acordo com o contrato valor invalido para deposito");
            }
            else {
                JOptionPane.showMessageDialog(null, "Obrigado por realizar um deposito");

                dep = dep;
                objtsaldo.setSaldo(dep);

                double limit;
                limit = dep * (2);
                objtlimite.setLimite(limit);

                String avisolimite = String.format("Seu limite para emprestimos e: E%.2f", objtlimite.getLimite() );

                JOptionPane.showMessageDialog(null, avisolimite);

                String levantamento;
                numeroInvalido = false;
                double lev = 0.00;

                do {
                    levantamento = JOptionPane.showInputDialog("Realize um levantamento ");
                    try {
                        lev = Double.parseDouble(levantamento);
                    } catch (NumberFormatException nfe) {
                        JOptionPane.showMessageDialog(null, "Valor invalido.", "Erro", JOptionPane.ERROR_MESSAGE);
                        numeroInvalido = true;
                    }
                }while(numeroInvalido);

                if (lev > dep) {
                    JOptionPane.showMessageDialog(null, "Saldo Insuficiente");
                }
                else {
                    lev = lev;
                    objtlevantamento.setLevantamento(lev);

                    double r;
                    r = dep - lev;

                    double cpm = (lev * 2) / 100;

                    objtcpmf.setCpmf(cpm);

                    double set = r - cpm;

                    objtsaldo.setSaldo(set);

                    limit = set * (2);
                    objtlimite.setLimite(limit);
                    int cont = 785236;
                    String exibi = String.format("Numero da Conta %s\nSaldo E%.2f\nLevantamento realizado E%.2f\nLimite para emprestimo E%.2f\nValor de CPMF E%.2f\n\nSistema Desenvolvido por Carlos Tojal Version 1.1", cont, objtsaldo.getSald(), objtlevantamento.getLevantamento(), objtlimite.getLimite(), objtcpmf.getCpmf());

                    JOptionPane.showMessageDialog(null, exibi);
                }
            }
        }

    }
}