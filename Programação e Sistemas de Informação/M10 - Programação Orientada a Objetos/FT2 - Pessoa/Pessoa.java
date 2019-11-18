
//
// Carlos Tojal 18-11-2019
// FT2
// Pessoa.java
//

public class Pessoa {
	// Atributos
	private String nome;
	private String morada;
	private int idade;
	private char genero;
	private long contato;

	// Getters
	public String getNome() {
		return nome;
	}

	public String getMorada() {
		return morada;
	}

	public int getIdade() {
		return idade;
	}

	public char getGenero() {
		return genero;
	}

	public long getContato() {
		return contato;
	}

	// Setters
	public void setNome(String nome) {
		this.nome = nome;
	}
	
	public void setMorada(String morada) {
		this.morada = morada;
	}

	public void setIdade(int idade) {
		this.idade = idade;
	}

	public void setGenero(char genero) {
		this.genero = genero;
	}
	
	public void setContato(long contato) {
		this.contato = contato;
	}

	// Construtores
	public Pessoa() {
	}

	public Pessoa(String nome, String morada, int idade, char genero, long contato) {
		this.nome = nome;
		this.morada = morada;
		this.idade = idade;
		this.genero = genero;
		this.contato = contato;
	}

	// Métodos
	public void falar() {
		System.out.println("Sou uma pessoa.");
	}

	public void falar(String frase) {
		System.out.println(frase);
	}

	public String toString() {
		return "Olá! EU sou do género " + genero + ", chamo-me " + nome + " tenho " + idade + " anos, moro em " + morada + " e o meu contacto é " + contato:
	}
}
