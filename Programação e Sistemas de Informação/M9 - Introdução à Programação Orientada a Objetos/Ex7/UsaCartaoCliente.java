
//
// Copyright (c) Carlos Tojal (24-10-2019)
// Ex7
// UsaCartaoCliente.java
//

public class UsaCartaoCliente {
    public static void main(String[] args) {

        CartaoCliente cartao1 = new CartaoCliente();
        cartao1.setNcartao(1234);
        cartao1.setTitular("Carlos Tojal");

        CartaoCliente cartao2 = new CartaoCliente(5678, "Frederico Bento");

        System.out.println("\nPrimeira listagem");
        cartao1.verPontos();
        cartao2.verPontos();

        System.out.println("\nA creditar 45.5 pontos no cartao " + cartao1.getNcartao());
        cartao1.creditar(45.5);

        System.out.println("\nSegunda listagem");
        cartao1.verPontos();
        cartao2.verPontos();

        System.out.println("\nA transferir os pontos do cartao " + cartao1.getNcartao() +" para o cartao " + cartao2.getNcartao());
        cartao2.transferir(cartao1);

        System.out.println("\nTerceira listagem");
        cartao1.verPontos();
        cartao2.verPontos();

        System.out.println("\nA debitar 20 pontos do cartao " + cartao2.getNcartao());
        cartao2.debitar(20);

        System.out.println("\nQuarta listagem");
        cartao1.verPontos();
        cartao2.verPontos();
    }
}