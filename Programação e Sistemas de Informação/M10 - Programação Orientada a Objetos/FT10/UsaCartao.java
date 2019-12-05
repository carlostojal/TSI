
//
// Carlos Tojal 05-10-2019
// FT10
// UsaCartao.java
//

public class UsaCartao {

    public static void main(String[] args) {

        CartaoPontos cartaoPontos = new CartaoPontos();
        cartaoPontos.setNumero(123);
        cartaoPontos.setNomeTitular("Titular1");
        cartaoPontos.setSaldo(50.0);

        CartaoEscola cartaoEscola = new CartaoEscola();
        cartaoEscola.setNumero(456);
        cartaoPontos.setNomeTitular("Titular2");
        cartaoPontos.setSaldo(30.0);

        CartaoPontos cartaoPontos1 = new CartaoPontos(789, "Titular3", 70.0);
        
        CartaoEscola cartaoEscola1 = new CartaoEscola(101, "Titular4", 90.0);

        verDados(cartaoPontos, cartaoEscola, cartaoPontos1, cartaoEscola1);

        cartaoPontos.credito(45.5);
        cartaoEscola1.credito(50.0);

        verDados(cartaoPontos, cartaoEscola, cartaoPontos1, cartaoEscola1);

        cartaoPontos.transferirSaldo(cartaoPontos1);
        cartaoEscola1.transferirSaldo(cartaoEscola);

        verDados(cartaoPontos, cartaoEscola, cartaoPontos1, cartaoEscola1);

        cartaoPontos1.debito(20.0);
        
        verDados(cartaoPontos, cartaoEscola, cartaoPontos1, cartaoEscola1);
    }

    public static void verDados(CartaoTitular cartao1, CartaoTitular cartao2, CartaoTitular cartao3, CartaoTitular cartao4) {
        System.out.println("\n** Cartao 1 **");
        System.out.println("Numero: " + cartao1.getNumero());
        System.out.println("Nome: " + cartao1.getNomeTitular());
        System.out.println("Saldo: " + cartao1.getSaldo());

        System.out.println("\n** Cartao 2 **");
        System.out.println("Numero: " + cartao2.getNumero());
        System.out.println("Nome: " + cartao2.getNomeTitular());
        System.out.println("Saldo: " + cartao2.getSaldo());

        System.out.println("\n** Cartao 3 **");
        System.out.println("Numero: " + cartao3.getNumero());
        System.out.println("Nome: " + cartao3.getNomeTitular());
        System.out.println("Saldo: " + cartao3.getSaldo());

        System.out.println("\n** Cartao 4 **");
        System.out.println("Numero: " + cartao4.getNumero());
        System.out.println("Nome: " + cartao4.getNomeTitular());
        System.out.println("Saldo: " + cartao4.getSaldo());
    }
}
