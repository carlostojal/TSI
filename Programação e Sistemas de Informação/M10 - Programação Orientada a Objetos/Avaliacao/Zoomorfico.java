
// 
// Carlos Tojal e Frederico Bento 28-11-2019
// Avaliacao
// Zoomorfico.java
//

public class Zoomorfico extends TiposRobots {
    public void speedUp() {
        super.speedUp();
        System.out.println("Temperatura: " + super.getTemperature());
    }
}
