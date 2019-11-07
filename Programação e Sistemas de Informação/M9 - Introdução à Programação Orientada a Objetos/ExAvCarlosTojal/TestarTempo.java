
//
// Carlos Tojal 04-11-2019
// ExAvCarlosTojal
// TestarTempo.java
//

import java.text.DecimalFormat;

public class TestarTempo {

    // Função principal
    public static void main(String[] args) {

        int opt = new Login().menu();
        switch(opt) {
            case 1:
                new Login().fazerLogin();
                break;
            case 2:
                new Login().fazerRegisto();
                new Login().fazerLogin();
                break;
        }

        if(opt > 0) {
            Atleta atleta = new Atleta("Pedro Miguéis", 351912340762L, "Portuguesa");
            DadosFisicos dadosFisicos = new DadosFisicos();
            double result;
            atleta.setNumeroCamisa(7);
            atleta.setPosicao("Centroavante");
            atleta.setStatus(false);
            dadosFisicos.setPeso(98f);
            dadosFisicos.setAltura(1.88f);
            dadosFisicos.setIdade(25);
            atleta.setDadosFisicos(dadosFisicos);
            DecimalFormat df = new DecimalFormat("0.00");

            atleta.exibirDados();
            atleta.getDadosFisicos().exibirDados();

            result = dadosFisicos.calcularImc(atleta.getDadosFisicos().getPeso(), atleta.getDadosFisicos().getAltura());

            if(result <= 18.5)
                System.out.println("O IMC do atleta e de: " + df.format(result) + "<= 18,5 - Jogador tem peso abaixo da normalidade.");
            else if(result > 18.5 && result <= 25)
                System.out.println("O IMC do atleta e de: " + df.format(result) + ">15,5 e <= 25 - Jogador tem peso dentro da normalidade.");
            else if(result >25 && result <= 30)
                System.out.println("O IMC do atleta e de: " + df.format(result) + "> 25 e <= 30 - Jogador tem peso acima da normalidade.");
            else
                System.out.println("O IMC do atleta e de: " + df.format(result) + "> 30 - Jogador está obeso.");

            int alteraStatus = atleta.alteraStatus();

            if(alteraStatus == -1) {
                if(result <= 25) {
                    System.out.println("Jogador nao pode ser titular.");
                    System.out.println("O seu peso esta abaixo da normalidade.");
                } else if(result > 25 && result <= 30) {
                    System.out.println("Jogador nao pode ser titular.");
                    System.out.println("O seu peso esta acima da normalidade.");
                } else {
                    System.out.println("Jogador nao pode ser titular.");
                    System.out.println("O seu peso esta completamente fora da normalidade, obeso!");
                }
            } else {
                System.out.println("O atleta agora e titular.");
            }
        }
    }
}