
/**
 * Determine qual é a idade que o utilizador faz no ano atual.
 * Para isso, solicite o ano de nascimento do utilizador e o ano atual
 *
 * @author Carlos Tojal
 * @version 03-10-2019
 */

import java.util.Scanner;

/**A classe Scanner é usada para obter a entrada do utilizador e pode ser encontrada no pacote
 * java.util. Para usar a classe Scanner, crie um objeto da classe e use qualquer um dos métodos
 * disponíveis encontrados na documentação da classe Scanner. No exemplo, usaremos o método
 * nextInt() para ler inteiros, se fosse nextLine() seria usado para ler Strings.*/

public class Principal {

    public static void main(String[] args) {
        Scanner reader = new Scanner(System.in);
        int nascimento;
        int ano;

        System.out.println("\n** Cálculo de idade **\n");
        System.out.print("Ano de nascimento: ");
        nascimento = reader.nextInt();
        System.out.print("Ano atual: ");
        ano = reader.nextInt();

        System.out.println("\nFaz/fez " + (ano - nascimento) + " anos.");
    }
}
