
//
// Copyright (c) Carlos Tojal 2019
// Exemplo1
// DivZero.java
//

public class DivZero {
    public static void main(String[] args) {
        int a = 1, b = 0;
        System.out.println(a/b);
        System.out.println("Divisão por zero");
        System.out.println("Fim do programa");
    }
}

/*
public class DivZero {
    public static void main(String[] args) {
        int a = 1, b = 0;
        try {
            System.out.println(a/b);
        } catch(Exception e) {
            System.out.println("Divisão por zero");
        }
        System.out.println("Fim do programa");
    }
}*/
