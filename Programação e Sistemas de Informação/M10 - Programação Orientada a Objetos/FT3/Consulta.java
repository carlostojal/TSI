
// 
// Carlos Tojal 26-11-2019
// FT3
// Consulta.java
//

import java.util.Scanner;

public class Consulta {

    public static void main(String[] args) {
        
        Veterinario veterinario = new Veterinario();

        Scanner s = new Scanner(System.in);
        System.out.print("Insira o tipo de animal: ");
        String tipoAnimal = s.nextLine();

        Animal animal;
        if(tipoAnimal.equals("atum"))
            animal = new Atum();
        else if(tipoAnimal.equals("bacalhau"))
            animal = new Bacalhau();
        else if(tipoAnimal.equals("canario"))
            animal = new Canario();
        else if(tipoAnimal.equals("cao"))
            animal = new Cao();
        else if(tipoAnimal.equals("cavalo"))
            animal = new Cavalo();
        else if(tipoAnimal.equals("macaco"))
            animal = new Macaco();
        else if(tipoAnimal.equals("ovelha"))
            animal = new Ovelha();
        else if(tipoAnimal.equals("papagaio"))
            animal = new Papagaio();
        else if(tipoAnimal.equals("pato"))
            animal = new Pato();
        else if(tipoAnimal.equals("salmao"))
            animal = new Salmao();
        else {
            System.out.println("Animal invalido!");
            animal = new Animal();
        }
        veterinario.examinar(animal);
    }
}
