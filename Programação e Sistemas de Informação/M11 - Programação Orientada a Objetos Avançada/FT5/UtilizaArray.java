
//
// Copyright (c) Carlos Tojal 2020
// FT5
// UtilizaArray.java
//

import java.util.ArrayList;
import java.lang.IndexOutOfBoundsException;

public class UtilizaArray {
    public static void main(String[] args) {
        ArrayList<Integer> arr = new ArrayList<Integer>();
        arr.add(Integer.valueOf(2));
        arr.add(4);
        arr.add(6);
        arr.add(8);
        arr.add(10);
        // System.out.println(arr.get(2));
        try {
            System.out.println(arr.get(5));
        } catch(IndexOutOfBoundsException ioobe) {
            System.out.println("O indice passado como parametro num dos metodos que esta a utilizar esta fora dos limites");
        }

    }
}
