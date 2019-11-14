
//
// Carlos Tojal 14-11-2019
// Ex1
// Familiar.java
//

public class Familiar extends Carro {

	public Familiar() {
		Condutor condutor = new Condutor();
		super.setMatricula("11-22-FF");
		super.setVelocidadeAtual(100);
		super.setVelocidadeMaxima(130);
		super.setCondutor(condutor);
	}

	public void desligarAirbagPassageiro() {
		System.out.println("Airbag desligado!");
	}

	public void buzinar() {
		super.buzinar();
		System.out.println("Buzina do familiar");
	}
	
	public String toString() {
		return "Matrícula: " + super.getMatricula() + "\n" +
		"Velocidade atual: " + super.getVelocidadeAtual() + "\n" +
		"Velocidade máxima: " + super.getVelocidadeMaxima();
	}
}
