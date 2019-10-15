
//
// Copyright (c) Carlos Tojal (15-10-2019)
// ExProposto
// CarroCorrida.java
//

// 1 - a)

public class CarroCorrida {
    private String numeroIdentificacao;
    private int velocidadeAtual = 0;
    private int velocidadeMaxima = 200;
    private Piloto piloto; // 1 - c)
    private boolean ligado = false;
    Motor motor;

    public CarroCorrida() {

    }

    // Getters e Setters
    public String getNumeroIdentificacao() {
        return numeroIdentificacao;
    }

    public void setNumeroIdentificacao(String numeroIdentificacao) {
        this.numeroIdentificacao = numeroIdentificacao;
    }

    public int getVelocidadeAtual() {
        return velocidadeAtual;
    }

    public Piloto getPiloto() {
        return piloto;
    }

    public void setPiloto(Piloto piloto) {
        this.piloto = piloto;
    }

    // Métodos
    void ligar() {
        System.out.println("VRUUUMMMMMMMMM");
        ligado = true;
    }

    void desligar() {
        System.out.println("MMMMMMMMMMMMMMM");
    }

    void travar(int intensidadeTravagem) {
        if(isLigado()) {
            if(intensidadeTravagem > velocidadeMaxima) {
                intensidadeTravagem = velocidadeMaxima;
            }
            else {
                if(intensidadeTravagem < 0)
                    intensidadeTravagem = 0;
            }
            velocidadeAtual -= intensidadeTravagem;
            if(velocidadeAtual > velocidadeMaxima)
                velocidadeAtual = velocidadeMaxima;
            else if(velocidadeAtual < 0) {
                velocidadeAtual = 0;
            }
        }
    }

    void acelerar() {
        if(isLigado()) {
            if(velocidadeAtual + 10 + piloto.getDestreza() * 0.1 + motor.potencia * 0.1 <= velocidadeMaxima)
                velocidadeAtual += 10 + piloto.getDestreza() * 0.1 + motor.potencia * 0.1; // 1 - c)
        }
    }

    public boolean isLigado() {
        return ligado;
    }
}
