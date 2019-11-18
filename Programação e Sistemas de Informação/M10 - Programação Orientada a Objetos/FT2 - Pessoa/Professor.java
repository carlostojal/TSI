
//
// Carlos Tojal 18-11-2019
// FT2
// Professor.java
//

public class Professor extends Pessoa {
	// Atributos
	private String grupo_docencia;
	private int escalao;

	// Getters
	public int getGrupoDocencia() {
		return grupo_docencia;
	}
	
	public int getEscalao() {
		return escalao;
	}
	
	// Construtor
	public Professor() {
	}

	public Professor(String nome, String morada, int idade, char genero, long contato, String grupo_docencia, int escalao) {
		super(nome, morada, idade, genero, contato);
		this.grupo_docencia = grupo_docencia;
		this.escalao = escalao;
	}

	public void falar() {
		super.falar();
		System.out.println("E sou um professor.");
	}
}
