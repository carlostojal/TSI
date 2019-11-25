
//
// Carlos Tojal 25-11-2019
// FT3
// Mamifero.java
//

public abstract class Mamifero extends Animal {
    
    // Construtor
    public Mamifero() {
    }

    // Metodos
    public void crescer(double peso, double comprimento) {
        peso += peso * 0.01;
        comprimento += comprimento * 0.01;
    }
}
