
//
// Carlos Tojal 14-11-2019
// Ex9Livro
// Aluno.java
//

public class Aluno extends Pessoa {
	
	private int numero;
	private String turma;

	public int getNumero() {
		return numero;
	}

	public void setNumero(int numero) {
		this.numero = numero;
	}

	public String getTurma() {
		return turma;
	}

	public void setTurma(String turma) {
		this.turma = turma;
	}

	public Aluno() {
	}

	public Aluno(String nome, char genero, int idade, int numero, String turma) {
		super.setNome(nome);
		super.setGenero(genero);
		super.setIdade(idade);
		this.setNumero(numero);
		this.setTurma(turma);
	}

	public void falar() {
		super.falar();
		System.out.println("e sou um Aluno");
	}
}
