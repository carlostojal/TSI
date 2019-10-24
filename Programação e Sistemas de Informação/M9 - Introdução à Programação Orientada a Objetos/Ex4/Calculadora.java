
//
// Copyright (c) Carlos Tojal (24-10-2019)
// Ex4
// Calculadora.java
//

public class Calculadora {

    //Atributos
    private double op1, op2;

    //Construtor
    public Calculadora() {
    }

    //Getters e Setters
    public void setOp1(double op1) {
        this.op1 = op1;
    }
    public void setOp2(double op2) {
        this.op2 = op2;
    }

    //Métodos
    public double soma() {
        return op1 + op2;
    }
}