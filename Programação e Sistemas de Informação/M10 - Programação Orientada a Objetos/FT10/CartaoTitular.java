
//
// Carlos Tojal 05-10-2019
// FT10
// CartaoTitular.java
//

public abstract class CartaoTitular implements FerramentasCartao {

    // Atributos 
    private int numero;
    private String nomeTitular;
    private double saldo;

    // Getters e Setters
    public int getNumero() {
        return numero;
    }

    public String getNomeTitular() {
        return nomeTitular;
    }

    public double getSaldo() {
        return saldo;
    }

    public void setNumero(int numero) {
        this.numero = numero;
    }

    public void setNomeTitular(String nomeTitular) {
        this.nomeTitular = nomeTitular;
    }

    public void setSaldo(double saldo) {
        this.saldo = saldo;
    }
    
    // Construtor
    public CartaoTitular() {
        setNumero(1000);
    }
    
    public void debito(double valor) {
    }

    public void credito(double valor) {
    }

    public void detalhesConta() {
    }

    public void transferirSaldo(CartaoTitular cartao) {
    }

    // Métodos
    public void cancelarConta() {
        setNomeTitular("-- CONTA CANCELADA --");
        setSaldo(0.0);
    }
}
