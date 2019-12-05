
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

        cartaoPontos.detalhesConta();
        cartaoEscola.detalhesConta();
        cartaoPontos1.detalhesConta();
        cartaoEscola1.detalhesConta();

        cartaoPontos.credito(45.5);
        cartaoEscola1.credito(50.0);

        cartaoPontos.detalhesConta();
        cartaoEscola.detalhesConta();
        cartaoPontos1.detalhesConta();
        cartaoEscola1.detalhesConta();

        cartaoPontos.transferirSaldo(cartaoPontos1);
        cartaoEscola1.transferirSaldo(cartaoEscola);

        cartaoPontos.detalhesConta();
        cartaoEscola.detalhesConta();
        cartaoPontos1.detalhesConta();
        cartaoEscola1.detalhesConta();

        cartaoPontos1.debito(20.0);

        cartaoPontos.detalhesConta();
        cartaoEscola.detalhesConta();
        cartaoPontos1.detalhesConta();
        cartaoEscola1.detalhesConta();
    }
}
