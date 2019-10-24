
//
// Copyright (c) Carlos Tojal (15-10-2019)
// ExProposto
// Motor.java
//

// 8

public class Motor {

    int potencia;

    public Motor(int potencia) {
        if(potencia > 0 && potencia <=100)
            this.potencia = potencia;
        else if(potencia > 100)
            this.potencia = 100;
        else 
            this.potencia = 1;
    }
}
