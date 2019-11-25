
// 
// Carlos Tojal 25-11-2019
// FT3
// Animal.java
//

public class Animal implements EmitirSom {

    // Atributos
    protected String nome;
    private int idade;
    private double peso;
    private double comprimento;

    // Getters e setters
    public String getNome() {
        return nome;
    }

    public int getIdade() {
        return idade;
    }

    public double getPeso() {
        return peso;
    }

    public double getComprimento() {
        return comprimento;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public void setIdade(int idade) {
        this.idade = idade;
    }

    public void setPeso(double peso) {
        this.peso = peso;
    }

    public void setComprimento(double comprimento) {
        this.comprimento = comprimento;
    }

    // Construtores
    public Animal() {
    }

    public Animal(String nome, int idade, double peso, double comprimento) {
        this.nome = nome;
        this.idade = idade;
        this.peso = peso;
        this.comprimento = comprimento;
    }

    public void emitirSom() {
        System.out.println("Som do animal");
    }

    public void crescer(double peso, double comprimento) {
        peso += peso * 0.01;
        comprimento += comprimento * 0.01;
    }
}
