
//
// Copyright (c) Carlos Tojal 2020
// FT3
// UtilizaFileOutputStream2.java
//

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.FileNotFoundException;
import java.io.IOException;

public class UtilizaFileInputOutputStream2 {
    static FileInputStream fis;
    static FileOutputStream fos;
    static int conteudo;
    public static void main(String[] args) {
        try {
            fis = new FileInputStream("Caracteres1.txt");
            fos = new FileOutputStream("Caracteres2.txt");
            while((conteudo=fis.read()) != -1)
                fos.write(conteudo);
            fis.close();
            fos.close();
        } catch(FileNotFoundException fnfe) {
            System.out.println("Ficheiro não encontrado.");
        } catch(IOException ioe) {
            System.out.println("Não foi possível ler o ficheiro.");
        }
    }
}
