
//
// Carlos Tojal (29-10-2019)
// ExProposto2
// Condutor.java
//

public class Condutor {
    private String nome;
    private int idade;
    private boolean carta_conducao;

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public int getIdade() {
        return idade;
    }

    public void setIdade(int idade) {
        this.idade = idade;
    }

    public boolean getCarta() {
        return carta_conducao;
    }

    public void setCarta(boolean carta_conducao) {
        this.carta_conducao = carta_conducao;
    }

    public Condutor() {
    }

    public Condutor(String nome, int idade, boolean carta_conducao) {
        this.nome = nome;
        this.idade = idade;
        this.carta_conducao = carta_conducao;
    }

    public boolean temCarta() {
        return carta_conducao;
    }
}