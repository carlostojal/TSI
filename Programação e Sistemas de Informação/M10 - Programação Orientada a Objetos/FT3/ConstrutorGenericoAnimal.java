
//
// Carlos Tojal 26-11-2019
// FT3
// ConstrutorGenericoAnimal.java
//

public class ConstrutorGenericoAnimal {
    
    public Animal criarAnimal(String tipoAnimal) {
        if(tipoAnimal.equals("cao"))
            return new Cao();
        else if(tipoAnimal.equals("cavalo"))
            return new Cavalo();
        else if(tipoAnimal.equals("macaco"))
            return new Macaco();
        else if(tipoAnimal.equals("pato"))
            return new Pato();
        else 
            return new Animal();
    }
}
