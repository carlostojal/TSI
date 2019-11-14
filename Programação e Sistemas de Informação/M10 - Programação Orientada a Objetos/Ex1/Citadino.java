
//
// Carlos Tojal 14-11-2019
// Ex1
// Citadino.java
//

public class Citadino extends Carro {

	public Citadino() {
		Condutor condutor = new Condutor();
		super.setMatricula("11-22-CC");
		super.setVelocidadeAtual(50);
		super.setVelocidadeMaxima(120);
		super.setCondutor(condutor);
	}

	public void ligarACManual() {
		System.out.println("AC ligado!");
	}

	public void buzinar() {
		super.buzinar();
		System.out.println("Buzina do citadino");
	}

	public String toString() {
		return "Matrícula: " + super.getMatricula() + "\n" +
		"Velocidade atual: " + super.getVelocidadeAtual() + "\n" +
		"Velocidade máxima: " + super.getVelocidadeMaxima();
	}
}
