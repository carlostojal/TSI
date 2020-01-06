
//
// Copyright (c) Carlos Tojal 2019
// Exemplo1
// TesteCatch.java
//

public class TesteCatch {
    public static void main(String[] args) {
        int a;
        try {
            a = Integer.parseInt("123a");
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
