
//
// Copyright (c) Carlos Tojal 2020
// FT7
// UtilizaFileReaderWriter.java
//

import java.io.Reader;
import java.io.FileReader;
import java.io.BufferedReader;
import java.io.Writer;
import java.io.FileWriter;
import java.io.BufferedWriter;
import java.io.IOException;
import java.lang.Exception;

public class UtilizaFileReaderWriter {
    public static void main(String[] args) {
        Writer w;
        BufferedWriter bw;
        Reader r;
        BufferedReader br;
        try {
            w = new FileWriter("Strings.txt");
            bw = new BufferedWriter(w);
            for(int i = 0; i < 5; i++)
                bw.write(String.valueOf(i+1) + " linha\n");
            bw.close();
        } catch(IOException ioe) {
            System.out.println("Erro na escrita do ficheiro.");
        } catch(Exception e) {
            System.out.println("Erro.");
        }

        try {
            String line;
            r = new FileReader("Strings.txt");
            br = new BufferedReader(r);
            while((line = br.readLine()) != null)
                System.out.println(line);
        } catch(IOException ioe) {
            System.out.println("Erro na leitura do ficheiro.");
        } catch(Exception e) {
            System.out.println("Erro.");
        }
    }
}