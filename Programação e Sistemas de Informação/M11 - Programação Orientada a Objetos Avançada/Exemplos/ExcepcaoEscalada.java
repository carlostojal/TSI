
//
// Copyright (c) Carlos Tojal 2019
// Exemplo1
// ExcepcaoEscalada.java
//

public class ExcepcaoEscalada {
    public static void metodoComErro() {
        System.out.println(3 / 0);
    }

    public static void main(String[] args) {
        try {
            metodoComErro();
        } catch(RuntimeException rte) {
            rte.printStackTrace();
        }
        System.out.println("Fim do Programa");
    }
}
