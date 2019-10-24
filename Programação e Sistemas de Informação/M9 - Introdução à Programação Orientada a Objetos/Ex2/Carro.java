
//
// Copyright (c) Carlos Tojal (14-10-2019)
// Ex2
// Carro.java
//

public class Carro {
    // Atributos da classe Carro
    private String matricula;
    private int velocidadeAtual = 0;
    private int velocidadeMaxima = 200;
    private Condutor condutor;
    private boolean ligado = false;

    // Construtor da classe atual
    public Carro() {
    }

    public String getMatricula() {
        return matricula;
    }

    public void setMatricula(String matricula) {
        this.matricula = matricula;
    }

    public int getVelocidadeAtual() {
        return velocidadeAtual;
    }

    public void setVelocidadeAtual(int velocidadeAtual) {
        this.velocidadeAtual = velocidadeAtual;
    }

    public int getVelocidadeMaxima() {
        return velocidadeMaxima;
    }

    public void setVelocidadeMaxima(int velocidadeMaxima) {
        this.velocidadeMaxima = velocidadeMaxima;
    }

    public Condutor getCondutor() {
        return condutor;
    }

    public void setCondutor(Condutor condutor) {
        this.condutor = condutor;
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

    void acelerar() {
        if(velocidadeAtual + 10 + condutor.getDestreza() * 0.1 <= velocidadeMaxima)
            velocidadeAtual += 10 + condutor.getDestreza() * 0.1;
    }

    public boolean isLigado() {
        return ligado;
    }
}
