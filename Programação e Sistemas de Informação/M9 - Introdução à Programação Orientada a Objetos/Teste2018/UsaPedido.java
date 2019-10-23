
/*
* Copyright (c) Carlos Tojal 2019
* Teste2018
* UsaPedido.java
*/

public class UsaPedido {
    public static void main(String[] args) {
        Pedido pedido1 = new Pedido(1, "Frederico", "Hambúrguer");
        Pedido pedido2 = new Pedido(2, "Alexandre", "Salada");

        pedido1.mostrarPedido();
        pedido2.mostrarPedido();        

        pedido1.modificarPedido();
        pedido2.modificarPedido();

        pedido1.mostrarPedido();
        pedido2.mostrarPedido();
    }
}