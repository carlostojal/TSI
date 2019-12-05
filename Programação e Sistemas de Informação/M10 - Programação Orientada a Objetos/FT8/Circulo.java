
// 
// Carlos Tojal 05-12-2019
// FT8
// Circulo.java
//

public class Circulo extends FormaGeometrica {
    
    private double coord_x, coord_y;
    private double raio;

    public double getCoordX() {
        return coord_x;
    }

    public double getCoordY() {
        return coord_y;
    }

    public double getRaio() {
        return raio;
    }

    public void setCoordX(double coord_x) {
        this.coord_x = coord_x;
    }

    public void setCoordY(double coord_y) {
        this.coord_y = coord_y;
    }

    public void setRaio(double raio) {
        this.raio = raio;
    }

    public Circulo() {
    }
}
