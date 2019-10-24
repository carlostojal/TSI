
//
// Copyright (c) Carlos Tojal (22-10-2019)
// Ex3
// Contador.java
//

public class Contador {
    private int num;

    public int getNum() {
        return num;
    }

    public void setNum(int num) {
        this.num = num;
    }

    public Contador() {
    }

    public Contador(int num) {
        this.num = num;
    }

    public void incNum() {
        num++;
    }

    public void decNum() {
        num--;
    }

    public void mostrarNum() {
        System.out.println("Número: " + num);
    }
}