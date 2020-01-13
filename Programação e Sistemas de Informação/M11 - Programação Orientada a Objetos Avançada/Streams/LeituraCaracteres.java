
//
// Copyright (c) Carlos Tojal 2020
// Streams
// LeituraCaracteres.java
//

import java.io.FileReader;
import java.io.FileWriter;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;

public class LeituraCaracteres {
    public static void main(String[] args) {
        try {
            FileWriter fw = new FileWriter("Strings.txt");
            BufferedWriter bw = new BufferedWriter(fw);

            for(int i = 1; i < 10; i++) {
                bw.write(i + "a linha");
                bw.newLine();
            }

            bw.close();
            /* Neste caso, o FileReader não pode ser utilizado sozinho porque
            nenhum dos seus métodos read devolve Strings */
            FileReader fr = new FileReader("Strings.txt");
            BufferedReader br = new BufferedReader(fr);

            while(br.ready())
                System.out.print((char)br.read());

            br.close();
        } catch(IOException e) {
            System.out.println("Erro");
        }
    }
}
