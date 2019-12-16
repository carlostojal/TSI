
//
// Copyright (c) Carlos Tojal 2019
// Exemplo1
// TesteCatch1.java
//

public class TesteCatch1 {
    public static void main(String[] args) {
        int[] a = new int[6];
        try {
            a[8] = 12;
        } catch(NumberFormatException nfe) {
            System.out.println("NumberFormatException");
        } catch(ArithmeticException ae) {
            System.out.println("ArithmeticExcetion");
        } catch(ArrayIndexOutOfBoundsException aioobe) {
            System.out.println("ArrayIndexOutOfBoundsException");
        } catch(Exception e) {
            System.out.println("Bloco Exception");
        } finally {
            System.out.println("Bloco Finally");
        }
        System.out.println("Fim do programa");
    }
}
