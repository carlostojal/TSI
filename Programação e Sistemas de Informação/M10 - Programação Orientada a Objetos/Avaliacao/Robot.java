
// 
// Carlos Tojal 21-11-2019
// Avaliacao
// Robot.java
//

public class Robot {
    
    // Atributos
    private String name;
    private double speed;
    private double temperature;
    private byte status;
    private int power;

    // Getters e setters
    public String getName() {
        return name;
    }

    public double getSpeed() {
        return speed;
    }

    public double getTemperature() {
        return temperature;
    }

    public byte getStatus() {
        return status;
    }

    public int getPower() {
        return power;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setSpeed(double speed) {
        this.speed = speed;
    }

    public void setTemperature(double temperature) {
        this.temperature = temperature;
    }

    public void setStatus(byte status) {
        this.status = status;
    }
    
    public void setPower(int power) {
        this.power = power;
    }

    // Construtores
    public Robot() {
    }

    public Robot(String name) {
        this.name = name;
    }

    public Robot(String name, double speed, double temperature, byte status, int power) {
        this.name = name;
        this.speed = speed;
        this.temperature = temperature;
        this.status = status;
        this.power = power;
    }

    // Métodos
    public String toString() {
        return "Name: " + this.getName() + "\n" +
        "Speed: " + this.getSpeed() + "\n" +
        "Temperature: " + this.getTemperature() + "\n" +
        "Status: " + this.getStatus() + "\n" +
        "Power: " + this.getPower() + "%";
    }

    public void show() {
        System.out.println(this.toString());
    }
}
