
// 
// Carlos Tojal 05-12-2019
// FT8
// Retangulo.java
//

public class Retangulo extends FormaGeometrica {
    
    private double coord_x, coord_y;
    private double comprimento, altura;

    public double getCoordX() {
        return coord_x;
    }

    public double getCoordY() {
        return coord_y;
    }

    public double getComprimento() {
        return comprimento;
    }

    public double getAltura() {
        return altura;
    }

    public void setCoordX(double coord_x) {
        this.coord_x = coord_x;
    }

    public void setCoordY(double coord_y) {
        this.coord_y = coord_y;
    }

    public void setComprimento(double comprimento) {
        this.comprimento = comprimento;
    }

    public void setAltura(double altura) {
        this.altura = altura;
    }

    public Retangulo() {
    }
}
