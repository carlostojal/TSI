
//
// Carlos Tojal 14-11-2019
// Ex9Livro
// Professor.java
//

public class Professor extends Pessoa {
	
	private String grupo;
	private int escalao;

	public String getGrupo() {
		return grupo;
	}

	public int getEscalao() {
		return escalao;
	}

	public Professor() {
	}

	public Professor(String nome, char genero, int idade, String grupo, int escalao) {
		super.setNome(nome);
		super.setGenero(genero);
		super.setIdade(idade);
		this.grupo = grupo;
		this.escalao = escalao;
	}

	public void falar() {
		super.falar();
		System.out.println("e sou um Professor");
	}
}
