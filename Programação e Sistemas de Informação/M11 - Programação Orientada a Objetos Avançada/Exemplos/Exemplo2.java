
//
// Copyright (c) Carlos Tojal 2020
// Exemplo2
//

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

// For-Each consiste num ciclo for adaptado a collections.
// Percorre todos os elementos de qualquer collection do framework "Collection".

public class Exemplo2 {
    public static void main(String[] args) {
        List<String> listaDeNomes = new ArrayList<String>();
        listaDeNomes.add("Gustavo");
        listaDeNomes.add("Maria");
        listaDeNomes.add("José");
        listaDeNomes.add("João");
        listaDeNomes.add("Ana");
        Iterator<String> iteratorDeNomes = listaDeNomes.iterator();
        List<String> listaConvertidaDoIterator = new ArrayList<>();
        while(iteratorDeNomes.hasNext()) {
            listaConvertidaDoIterator.add(iteratorDeNomes.next());
        }
        listaConvertidaDoIterator.forEach(System.out::println);
    }
}
