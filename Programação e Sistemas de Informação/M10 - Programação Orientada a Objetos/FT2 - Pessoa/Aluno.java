
//
// Carlos Tojal 18-11-2019
// FT2
// Aluno.java
//

public class Aluno extends Pessoa {

	// Atributos
	private int num_aluno;
	private String turma;

	// Getters
	public int getNumAluno() {
		return num_aluno;
	}

	public String getTurma() {
		return turma;
	}

	// Construtor
	public Aluno() {
	}

	public Aluno(String nome, String morada, int idade, char genero, long contato, int num_aluno, String turma) {
		super(nome, morada, idade, genero, contato);
		this.num_aluno = num_aluno;
		this.turma = turma;
	}

	// Método
	public void falar() {
		super.falar();
		System.out.println("E sou um aluno.");
	}
}
