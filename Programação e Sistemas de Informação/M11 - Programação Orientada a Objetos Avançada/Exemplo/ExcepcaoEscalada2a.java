
//
// Copyright (c) Carlos Tojal 2019
// Exemplo1
// ExcepcaoEscalada2a.java
//

public class ExcepcaoEscalada2a {
    public static void main(String[] args) {
        int n = 0;
        try {
            n = System.in.read();
        } catch(Exception e) {
            e.printStackTrace();
        } finally {
            System.out.println("n=='a'" + (n=='a'));
            System.out.println("n=" + n);
        }
    }
}
