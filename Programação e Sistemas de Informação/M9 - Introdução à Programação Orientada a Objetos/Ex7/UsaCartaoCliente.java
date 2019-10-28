
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

        cartao1.verPontos();
        cartao2.verPontos();

        cartao1.creditar(45.5);

        cartao1.verPontos();
        cartao2.verPontos();

        cartao2.transferir(cartao1);

        cartao1.verPontos();
        cartao2.verPontos();

        cartao2.debitar(20);

        cartao1.verPontos();
        cartao2.verPontos();
    }
}