
//
// Carlos Tojal 04-11-2019
// ExAvCarlosTojal
// DadosFisicos.java
//

public class DadosFisicos {

    // Atributos
    private float peso;
    private float altura;
    private int idade;

    // Getters e setters
    public float getPeso() {
        return peso;
    }

    public void setPeso(float peso) {
        this.peso = peso;
    }

    public float getAltura() {
        return altura;
    }

    public void setAltura(float altura) {
        this.altura = altura;
    }

    public int getIdade() {
        return idade;
    }

    public void setIdade(int idade) {
        this.idade = idade;
    }

    // Construtores
    public DadosFisicos() {
        peso = 0f;
        altura = 0f;
        idade = 0;
    }

    // Métodos 
    public double calcularImc(float peso, float altura) {
        return peso / (altura * altura);
    }

    public void exibirDados() {
        System.out.println("Peso: " + peso);
        System.out.println("Altura: " + altura);
        System.out.println("Idade: " + idade);
    }
}