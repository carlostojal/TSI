
//
// Carlos Tojal 05-10-2019
// FT10
// UsaCartao1.java
//

import java.util.Scanner;

public class UsaCartao1 {
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String tipoCartao;
        CartaoTitular cartao = new CartaoPontos();
        
        System.out.print("Tipo de cartao: ");
        tipoCartao = sc.nextLine();
        if(tipoCartao.equals("CP") || tipoCartao.equals("cp"))
            cartao = new CartaoPontos(12345, "Tiburcio Miquelino", 43.0);
        else if(tipoCartao.equals("CE") || tipoCartao.equals("ce"))
            cartao = new CartaoEscola(54321, "Maria Antonieta", 55.5);
        
        verDados(cartao);
    }

    public static void verDados(CartaoTitular cartao) {
        System.out.println("\nNumero de conta: " + cartao.getNumero());
        System.out.println("Nome: " + cartao.getNomeTitular());
        System.out.println("Saldo: " + cartao.getSaldo());
    }
}
