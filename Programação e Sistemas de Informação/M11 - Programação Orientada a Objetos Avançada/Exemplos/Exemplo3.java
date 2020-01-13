
//
// Copyright (c) Carlos Tojal 2020
// Exemplo3
//

import java.util.ArrayList;

public class Exemplo3 {
    public static void main(String[] args) {
        ArrayList<String> books = new ArrayList<String>();
        books.add("C");
        books.add("Java");
        books.add("PHP");

        for(String obj: books) {
            System.out.println(obj);
            books.add("C++");
        } 
    }
}
