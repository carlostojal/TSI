
//
// Carlos Tojal (29-10-2019)
// ExProposto2
// Motor.java
//

public class Motor {
    private int potencia;

    public int getPotencia() {
        return potencia;
    }

    public void setPotencia(int potencia) {
        this.potencia = potencia;
    }

    public Motor() {
    }

    public Motor(int potencia) {
        if(potencia < 90)
            this.potencia = potencia = 90;
        else if(potencia > 220)
            this.potencia = 220;
        else
            this.potencia = potencia;
    }
}
