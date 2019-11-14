
//
// Carlos Tojal 14-11-2019
// Ex1
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
    public void ligar() {
        System.out.println("VRUUUMMMMMMMMM");
        ligado = true;
    }

    public void desligar() {
		ligado = false;
	}

	public void buzinar() {
		System.out.println("Buzina do carro");
	}
}
