
//
// Copyright (c) Carlos Tojal 2020
// FT9
// UtilizaFile2.java
//

import java.io.File;
import java.io.IOException;
import java.lang.Exception;

public class UtilizaFile2 {
    public static void main(String[] args) {
        try {
            File f1 = new File("Inteiros.txt");
            File f2, f3, f4, f5;
            if (f1.exists()) {
                f2 = new File("NumsInteiros.txt");
                f1.renameTo(f2);
                f1.delete();
            }
            f3 = new File("LingProg");
            f3.mkdir();
            if (f3.exists()) {
                f4 = new File("LingProg" + File.separatorChar + "Modulo11.txt");
                f5 = new File("LingProg" + File.separatorChar + "Modulo12.txt");
                f4.createNewFile();
                f5.createNewFile();
            }
            String[] list = f3.list();
            for(String filename: list)
                System.out.println(filename);
        } catch(IOException ioe) {
            System.out.println("Erro no acesso aos diretorios e/ou ficheiros.");
        } catch(Exception e) {
            System.out.println("Erro.");
        }
    }
}