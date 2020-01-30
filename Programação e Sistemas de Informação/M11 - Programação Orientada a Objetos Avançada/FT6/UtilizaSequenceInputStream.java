
//
// Copyright (c) Carlos Tojal 2020
// FT6
// UtilizaSequenceInputStream.java
//

import java.io.File;
import java.io.InputStream;
import java.io.FileInputStream;
import java.io.SequenceInputStream;
import java.io.FileWriter;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.FileNotFoundException;
import java.lang.Exception;

public class UtilizaSequenceInputStream {
    public static void main(String[] args) {
        File f;
        InputStream is1;
        InputStream is2;
        SequenceInputStream sis;
        FileWriter fw;
        BufferedWriter bw;
        double num = 0;
        try {
            is1 = new FileInputStream("Inteiros1.txt");
            is2 = new FileInputStream("Inteiros2.txt");
            sis = new SequenceInputStream(is1, is2);
            num = sis.read();
            sis.close();
        } catch (IOException ioe) {
            System.out.println("Erro na leitura.");
        } catch (Exception e) {
            System.out.println("Erro.");
        }

        try {
            f = new File("Inteiros1e2.txt");
            fw = new FileWriter(f);
            bw = new BufferedWriter(fw);
            bw.write(String.valueOf(num));
            bw.close();
        } catch (IOException ioe) {
            System.out.println("Erro na escrita.");
        } catch (Exception e) {
            System.out.println("Erro.");
        }
    }
}