
/**
 * Este programa serve para rever as estruturas de controlo
 * 
 * @author Carlos Tojal
 * @version (03/10/2019)
 */

/**switch (expression) {
 *  case value1:
 *      statement sequence;
 *      break;
 *  case value2:
 *      statement sequence;
 *      break;
 *  ...
 *
 *  case valueN:
 *      statement sequence;
 *      break;
 */

import java.util.Scanner;

public class Principal {
    public static void main(String[] args) {
        //DATAS
        int dia, mes, ano, maxDia = 0;
        String nomeMes;

        System.out.print("Informe o dia de nascimento: ");
        dia = new Scanner(System.in).nextInt();
        System.out.print("Informe o mês de nascimento: ");
        mes = new Scanner(System.in).nextInt();
        System.out.print("Informe o ano de nascimento: ");
        ano = new Scanner(System.in).nextInt();

        while(mes > 12 || mes <= 0) {
            System.out.println("Mês inválido.");
            System.out.print("Informe o mês de nascimento: ");
        }

        //verificação dos dias
        if(mes % 2 == 0) { //meses de 28/29/30 dias
            if(mes == 2) { //fevereiro
                if(ano % 400 == 0 || (ano % 100 != 0 && ano % 4 == 0)) { //anos bissextos
                    while(dia < 1 || dia > 29) {
                        System.out.println("Dia inválido.");
                        System.out.print("Informe o dia: ");
                        dia = new Scanner(System.in).nextInt();
                        mes = 0;
                    }
                }
                else { //anos simples
                    while(dia < 1 || dia > 28) {
                        System.out.println("Dia inválido.");
                        System.out.print("Informe o dia: ");
                        dia = new Scanner(System.in).nextInt();
                    }
                }
            }
            else { //todos os outros meses de 30 dias
                while(dia < 1 || dia > 30) {
                    System.out.println("Dia invalido.");
                    System.out.print("Informe o dia: ");
                    dia = new Scanner(System.in).nextInt();
                }
            }
        }
        else { //meses de 31 dias
            while(dia < 1 || dia > 31) {
                System.out.println("Dia inválido.");
                System.out.print("Informe o dia: ");
                dia = new Scanner(System.in).nextInt();
            }
        }

        //cálculo do signo
        switch(mes) {
            case 3:
                if(dia >= 21)
                    System.out.println("O seu signo é carneiro.");
                else
                    System.out.println("O seu signo é peixes.");
                break;
            case 4:
                if(dia >= 20)
                    System.out.println("O seu signo é touro.");
                else
                    System.out.println("O seu signo é carneiro.");
                break;
            case 5:
                if(dia >= 21)
                    System.out.println("O seu signo é gémeos.");
                else
                    System.out.println("O seu signo é touro.");
                break;
            case 6:
                if(dia >= 22)
                    System.out.println("O seu signo é caranguejo.");
                else
                    System.out.println("O seu signo é gémeos.");
                break;
            case 7:
                if(dia >= 23)
                    System.out.println("O seu signo é leão.");
                else
                    System.out.println("O seu signo é caranguejo.");
                break;
            case 8:
                if(dia >= 23)
                    System.out.println("O seu signo é virgem.");
                else
                    System.out.println("O seu signo é leão.");
                break;
            case 9:
                if(dia >= 23)
                    System.out.println("O seu signo é balança.");
                else
                    System.out.println("O seu signo é virgem.");
                break;
            case 10:
                if(dia >= 23)
                    System.out.println("O seu signo é escorpião.");
                else
                    System.out.println("O seu signo é balança.");
                break;
            case 11:
                if(dia >= 22)
                    System.out.println("O seu signo é sagitário.");
                else
                    System.out.println("O seu signo é escorpião.");
                break;
            case 12:
                if(dia >= 22)
                    System.out.println("O seu signo é capricórnio.");
                else
                    System.out.println("O seu signo é sagitário.");
                break;
            case 1:
                if(dia >= 20)
                    System.out.println("O seu signo é aquário.");
                else
                    System.out.println("O seu signo é capricórnio.");
                break;
            case 2:
                if(dia >= 19)
                    System.out.println("O seu signo é peixes.");
                else
                    System.out.println("O seu signo é aquário.");
        }
    }
}
