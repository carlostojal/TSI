
//
// Copyright (c) Carlos Tojal 2020
// FT4
// UtilizaDataInputOutputStream1.java
//

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.FileNotFoundException;
import java.io.IOException;

public class UtilizaDataInputOutputStream1 {
    static FileOutputStream fos;
    static DataOutputStream dos;

    public static void main(String[] args) {
        float j = 0.5f;
        try {
            fos = new FileOutputStream("Floats.txt");
            dos = new DataOutputStream(fos);
            for(int i = 0; i < 3; i++) {
                System.out.println(i + j);
                dos.writeFloat(j + i);
            }
        } catch(FileNotFoundException fnfe) {
            System.out.println("Ficheiro não encontrado.");
        } catch(IOException ioe) {
            System.out.println("Não foi possível ler o ficheiro.");
        }
    }
}
