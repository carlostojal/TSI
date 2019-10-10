
//
// Copyright (c) Carlos Tojal (10-10-2019)
// Ex1
// UsaPessoa.java
//

import java.util.Scanner;

public class UsaPessoa {
    public UsaPessoa() {
    }

    public static void main(String[] args) {
        Pessoa pessoa1 = new Pessoa();

        pessoa1.nome = "Camila";
        pessoa1.genero = 'F';
        pessoa1.idade = 12;

        System.out.println("O objeto pessoa1 chama-se " + pessoa1.nome + ". É do sexo " + pessoa1.genero + " com " + pessoa1.idade + " e diz o seguinte: ");

        pessoa1.falar();


        Pessoa pessoa2 = new Pessoa();

        pessoa2.nome = "Martim";
        pessoa2.genero = 'M';
        pessoa2.idade = 14;

        System.out.println("O objeto pessoa2 chama-se " + pessoa2.nome + ". É do sexo " + pessoa2.genero + " com " + pessoa2.idade + " e diz o seguinte: ");

        pessoa2.falar();


        Pessoa pessoa3;

        Scanner s = new Scanner(System.in);

        System.out.print("Insira o nome da pessoa3: ");
        String n = s.nextLine();

        System.out.print("Insira o género da pessoa3: ");
        String gen = s.nextLine();
        char g = gen.charAt(0);

        System.out.print("Insira a idade da pessoa3: ");
        int i = s.nextInt();

        pessoa3 = new Pessoa(n, g, i);

        System.out.println("O objeto pessoa3 chama-se " + pessoa3.nome + ". É do sexo " + pessoa3.genero + " com " + pessoa3.idade + " e diz o seguinte: ");
        pessoa3.falar();
    }
}