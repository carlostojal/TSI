
//
// Copyright (c) Carlos Tojal 2020
// FT8
// UtilizaRandomAccessFile.java
//

import java.io.File;
import java.io.RandomAccessFile;
import java.io.IOException;
import java.lang.Exception;

public class UtilizaRandomAccessFile {
    public static void main(String[] args) {
        int [] arr = new int[] {1, 2, 3, 4, 5, 6, 7, 8};
        try {
            File f = new File("numeros.txt");
            RandomAccessFile raf = new RandomAccessFile(f, "rw");
            for (int i = 0; i < 8; i++)
                raf.write(arr[i]);
            System.out.println("Posicao no ficheiro: " + raf.getFilePointer() + " bytes");
            raf.seek(16);
            raf.seek(20);
            System.out.println(raf.read());
            raf.close();
        } catch(IOException ioe) {
            System.out.println("Erro na escrita do ficheiro.");
        } catch(Exception e) {
            System.out.println("Erro.");
        }
    }
}