
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
		System.out.println("Tração desligado!");
	}

	public void buzinar() {
		super.buzinar();
		System.out.println("Buzina do jipe");
	}

	public String toString() {
		return "Matrícula: " + super.getMatricula() + "\n" +
		"Velocidade atual: " + super.getVelocidadeAtual() + "\n" +
		"Velocidade máxima: " + super.getVelocidadeMaxima();
	}
}
