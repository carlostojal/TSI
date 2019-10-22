
//
// Copyright (c) Carlos Tojal (22-10-2019)
// Ex3
// UsaContador1.java
//

public class UsaContador1 {
    public static void main(String[] args) {
        Contador contador = new Contador();
        contador.setNum(0);
        contador.incNum();
        contador.mostrarNum();
        contador.incNum();
        contador.mostrarNum();
        contador.decNum();
        contador.mostrarNum();
        contador.decNum();
        contador.mostrarNum();
    }
}