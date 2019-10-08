
/**
 * Este programa serve para explicar a estrutura de controlo condicional.
 * 
 * @author (seu nome) 
 * @version (número de versão ou data)
 */

/** A partir de 3 notas fornecidas de um aluno, informe se ele foi aprovado,
 * ficou de recuperação ou foi reprovado.
 * A média de aprovação é >= 7.0;
 * a média de recuperação é >= 5.0 e < 7.0; e
 * a média do reprovado é < 5.0
 */

//Estrutura de Controlo Condicional:
/**if(condition)
 *  statement;
 * else if(condition)
 *  statement;
 * else if(condition)
 *  statement;
 * ...
 * else
 *  statement;
 */

import java.util.Scanner;

public class Principal {
    public static void main(String[] args) {
        double total = 0;
        double media = 0;

        for(int i = 0; i < 3; i++) {
            System.out.print((i+1)+" nota: ");
            total += new Scanner(System.in).nextDouble();
        }

        media = total / 3;

        System.out.println("\nA média do aluno é " + media);

        if(media >= 7)
            System.out.println("Aprovado");
        else if(media >= 5 && media <= 7)
            System.out.println("Recuperação");
        else
            System.out.println("Reprovado");
    }
}
