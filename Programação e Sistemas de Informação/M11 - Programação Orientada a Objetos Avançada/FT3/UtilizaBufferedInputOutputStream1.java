
//
// Copyright (c) Carlos Tojal 2020
// FT3
// UtilizaBufferedInputOutputStream1.java
//

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.FileNotFoundException;
import java.io.IOException;

public class UtilizaBufferedInputOutputStream1 {
    static FileInputStream fis;
    static FileOutputStream fos;
    static BufferedInputStream bis;
    static BufferedOutputStream bos;
    static int conteudo;
    public static void main(String[] args) {
        try {
            fis = new FileInputStream("Imagem1.jpg");
            bis = new BufferedInputStream(fis);
            fos = new FileOutputStream("Imagem3.jpg");
            bos = new BufferedOutputStream(fos);
            while((conteudo=bis.read()) != -1)
                bos.write(conteudo);
            fis.close();
            bis.close();
            fos.close();
            bos.close();
        } catch(FileNotFoundException fnfe) {
            System.out.println("Ficheiro não encontrado.");
        } catch(IOException ioe) {
            System.out.println("Não foi possível ler o ficheiro.");
        }
    }
}
