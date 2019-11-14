
//
// Carlos Tojal 14-11-2019
// Ex1
// Condutor.java
// 

public class Condutor {
	
    private String nome;
    private int idade;
    private int destreza;

    /** Os modificadores de acesso são padrões de visibilidade de acessos
     * às classes, atributos e métodos: default, private, public e protected.
     * protected - ele é praticamente igual ao default, com a diferença de que se
     * uma classe (mesmo que esteja fora do package) estende da classe com o
     * atributo protected, a classe terá acesso a ele.
     * Então o acesso é por pacote e por herança.

     Através deles aplica-se uma regra da orientação a objetos chamada encapsulamento , que
     consiste que os atributos de uma classe não podem ser acedidos diretamente.
     Não devem criar get/set para todos os atributos indiscriminadamente,
     pois existem atributos que não precisam/devem ser alterados.
     Pode-se por exemplo passar alguns atributos nos construtores da classe,
     e assim esses ficarem sem os setters, e terem apenas os gets para recuperar
     o valor.
     O método getter é utilizado para recuperar alguma informação,
     geralmente utilizado para trazer informação de algum atributo,
     sem ter que utilizar o atributo explicitamente.
     Então chamamos através de métodos. Eis aí um dos princípios de 00.
     Método setter é utilizado para definir um valor dentro de um objeto,
     de uma variável.
     */

    public Condutor() {
    }

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

    public int getDestreza() {
        return destreza;
    }

    public void setDestreza(int destreza) {
	}
}
