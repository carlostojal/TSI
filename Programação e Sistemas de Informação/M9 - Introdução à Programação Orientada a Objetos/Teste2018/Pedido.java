
/*
* Copyright (c) Carlos Tojal 2019
* Teste2018
* Pedido.java
*/

import java.util.Scanner;

public class Pedido {
    private int cod_pedido;
    private String nome_cliente;
    private String desc_pedido;
    float preco_pedido;

    public Pedido(int cod_pedido, String nome_cliente, String desc_pedido) {
        this.cod_pedido = cod_pedido;
        this.nome_cliente = nome_cliente;
        this.desc_pedido = desc_pedido;
    }

    public String getNome() {
        return nome_cliente;
    }

    public void setNome(String nome_cliente) {
        this.nome_cliente = nome_cliente;
    }

    public String getDesc() {
        return desc_pedido;
    }

    public void setDesc(String desc_pedido) {
        this.desc_pedido = desc_pedido;
    }

    public void mostrarPedido() {
        System.out.println("\n\n** Mostrar pedido nº " + this.cod_pedido + " **\n");
        System.out.println("Nome: " + getNome());
        System.out.println("Descrição: " + getDesc() + "\n");
    }

    public void modificarPedido() {
        String nome;
        String descricao;
        Scanner scanner = new Scanner(System.in);

        System.out.println("\n\n** Modificar pedido nº " + this.cod_pedido + " **\n");
        System.out.print("Nome: ");
        setNome(scanner.nextLine());
        System.out.print("Descrição: ");
        setDesc(scanner.nextLine());
    }
}