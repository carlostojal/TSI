
//
// Carlos Tojal 26-11-2019
// FT3
// JardimZoologico.java
//

import java.util.Scanner;

public class JardimZoologico {
    
    public static void main(String[] args) {
        
        Animal[] jaula = new Animal[4];
        Animal[] gaiola = new Animal[3];
        Animal[] aquario = new Animal[3];

        Scanner s = new Scanner(System.in);
        ConstrutorGenericoAnimal construtorGenericoAnimal = new ConstrutorGenericoAnimal();

        for(int i = 0; i < 4; i++) {
            System.out.println("Insira o tipo de animal: ");
            String tipoAnimal = s.nextLine();
            jaula[i] = construtorGenericoAnimal.criarAnimal(tipoAnimal);
        }

        for(int i = 0; i < 4; i++) {
            jaula[i].emitirSom();
            if(jaula[i] instanceof Cao)
                ((Cao)jaula[i]).correr();
            else if(jaula[i] instanceof Cavalo) 
                ((Cavalo)jaula[i]).correr();
            else if(jaula[i] instanceof Macaco)
                ((Macaco)jaula[i]).subirArvores();
            else if(jaula[i] instanceof Ovelha)
                ((Ovelha)jaula[i]).pastar();
        }

        for(int j = 0; j < 3; j++) {
            System.out.print("Insira o tipo de animal: ");
            String tipoAnimal = s.nextLine();
            gaiola[j] = construtorGenericoAnimal.criarAnimal(tipoAnimal);
        }

        for(int j = 0; j < 3; j++) {
            gaiola[j].emitirSom();
            if(gaiola[j] instanceof Canario)
                ((Canario)gaiola[j]).voar();
            else if(gaiola[j] instanceof Pato)
                ((Pato)gaiola[j]).voar();
            else if(gaiola[j] instanceof Papagaio)
                ((Papagaio)gaiola[j]).voar();
        }

        for(int n = 0; n < 3; n++) {
            System.out.print("Insira o tipo de animal: ");
            String tipoAnimal = s.nextLine();
            aquario[n] = construtorGenericoAnimal.criarAnimal(tipoAnimal);
        }

        for(int n = 0; n < 3; n++) {
            aquario[n].emitirSom();
            if(aquario[n] instanceof Salmao)
                ((Salmao)aquario[n]).nadar();
            else if(aquario[n] instanceof Atum)
                ((Atum)aquario[n]).nadar();
            else if(aquario[n] instanceof Bacalhau)
                ((Bacalhau)aquario[n]).nadar();
        }
    }
}
