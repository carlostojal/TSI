
//
// Copyright (c) Carlos Tojal 2020
// FT9
// UtilizaFile1.java
//

import java.io.File;
import java.io.IOException;
import java.lang.Exception;

public class UtilizaFile1 {
    public static void main(String[] args) {
        File file = new File(".." + File.separatorChar + "FT9" + File.separatorChar + "UtilizaFile1.java");
        if(file.exists()) {
            System.out.println("Nome: " + file.getName());
            System.out.println("Diretorio: " + file.getParent());
            System.out.println("Diretorio completo: " + file.getAbsoluteFile().getParent());
        } else {
            System.out.println("O ficheiro especificado nao existe");
        }
    }
}