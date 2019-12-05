
//
// Carlos Tojal 05-10-2019
// FT10
// CartaoEscola.java
//

public class CartaoEscola extends CartaoTitular {

    // Construtores
    public CartaoEscola() {
    }

    public CartaoEscola(int numero, String nomeTitular, double saldo) {
        super.setNumero(numero);
        super.setNomeTitular(nomeTitular);
        super.setSaldo(saldo);
    }

    public void debito(double valor) {
        super.setSaldo(super.getSaldo() - valor);
    }

    public void credito(double valor) {
        super.setSaldo(super.getSaldo() + valor);
    }

    public void detalhesConta() {
        System.out.println("\nNumero: " + super.getNumero() + "\nSaldo: " + super.getSaldo());
    }

    public void transferirSaldo(CartaoTitular cartao) {
        cartao.setSaldo(super.getSaldo());
        super.setSaldo(0.0);
    }
}
