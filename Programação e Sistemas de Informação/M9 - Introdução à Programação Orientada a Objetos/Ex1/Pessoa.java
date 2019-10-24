
//
// Copyright (c) Carlos Tojal (10-10-2019)
// Ex1
// Pessoa.java
//

public class Pessoa {
    //Atributos da classe Pessoa
    String nome;
    char genero;
    int idade;

    //Construtores da classe
    public Pessoa() {
    }

    public Pessoa(String nome, char genero) {
        this.nome = nome;
        this.genero = genero;
    }

    public Pessoa(String nome, char genero, int idade) {
        this(nome, genero);
        this.idade = idade;
    }

    //Métodos
    void falar() {
        System.out.println("Blá, Blá, Blá...");
    }
}