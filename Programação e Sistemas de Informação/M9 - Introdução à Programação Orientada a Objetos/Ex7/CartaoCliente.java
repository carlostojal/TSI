
//
// Copyright (c) Carlos Tojal (24-10-2019)
// Ex7
// CartaoCliente.java
//

public class CartaoCliente {
    private int n_cartao;
    private String titular;
    private double n_pontos = 0;

    public int getNcartao() {
        return this.n_cartao;
    }

    public void setNcartao(int n_cartao) {
        this.n_cartao = n_cartao;
    }

    public String getTitular() {
        return this.titular;
    }

    public void setTitular(String titular) {
        this.titular = titular;
    }

    public double getNpontos() {
        return this.n_pontos;
    }

    public void setNpontos(double n_pontos) {
        this.n_pontos = n_pontos;
    } 

    public CartaoCliente() {
    }

    public CartaoCliente(int n_cartao, String titular) {
        this.n_cartao = n_cartao;    
        this.titular = titular;
    }

    public void creditar(double pontos) {
        this.n_pontos += pontos;
    }

    public void debitar(int pontos) {
        if(pontos <= this.n_pontos)
            this.n_pontos -= pontos;
    }

    public void transferir(CartaoCliente cartao) {
        this.n_pontos += cartao.getNpontos(); //transfere os pontos do cartão passado como argumento
        cartao.setNpontos(0); //reinicializa o cartão passado como argumento
    }

    public void verPontos() {
        System.out.println("Cartao " + this.getNcartao() + " (" + this.getTitular() + "): " + this.n_pontos + " pontos");
    }
}