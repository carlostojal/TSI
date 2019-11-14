
//
// Carlos Tojal 14-11-2019
// Ex1
// Jipe.java
//

public class Jipe extends Carro {

	public Jipe() {
		Condutor condutor = new Condutor();
		super.setMatricula("11-22-JJ");
		super.setVelocidadeAtual(40);
		super.setVelocidadeMaxima(90);
		super.setCondutor(condutor);
	}

	public void ligarTracao4x4() {
		System.out.println("Tra��o desligado!");
	}

	public void buzinar() {
		super.buzinar();
		System.out.println("Buzina do jipe");
	}

	public String toString() {
		return "Matr�cula: " + super.getMatricula() + "\n" +
		"Velocidade atual: " + super.getVelocidadeAtual() + "\n" +
		"Velocidade m�xima: " + super.getVelocidadeMaxima();
	}
}
