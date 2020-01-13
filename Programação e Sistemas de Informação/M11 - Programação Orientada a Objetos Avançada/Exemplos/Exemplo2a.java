
//
// Copyright (c) Carlos Tojal 2020
// Exemplo3
//

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

public class Exemplo2a {
    public static void main(String[] args) {
        List<String> listaDeNomes = new ArrayList<String>();
        listaDeNomes.add("Gustavo");
        listaDeNomes.add("Maria");
        listaDeNomes.add("José");
        listaDeNomes.add("João");
        listaDeNomes.add("Ana");
        Iterator<String> iteratorDeNomes = listaDeNomes.iterator();
        List<String> listaConvertidaDoIterator = new ArrayList<>();
        iteratorDeNomes.forEachRemaining(n -> listaConvertidaDoIterator.add(n));
        iteratorDeNomes.forEachRemaining(listaConvertidaDoIterator::add);
        listaConvertidaDoIterator.forEach(System.out::println);
    }
}
