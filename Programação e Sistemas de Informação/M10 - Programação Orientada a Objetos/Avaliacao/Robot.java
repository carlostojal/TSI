
// 
// Carlos Tojal e Frederico Bento 21-11-2019
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
    private int maxSpeed;
    private int currentSpeed;

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

    public int getPower() {
        return power;
    }

    public byte getStatus() {
        return status;
    }

    public int getMaxSpeed() {
        return maxSpeed;
    }

    public int getCurrentSpeed() {
        return currentSpeed;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setSpeed(double speed) {
        this.speed = speed;
    }

    public void setMaxSpeed(int speed) {
	this.maxSpeed = speed;
    }

    // Construtores
    public Robot() {
	this.power = 100;
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
        "Status: " + this.status + "\n" +
        "Power: " + this.getPower() + "%";
    }

    public void show() {
        System.out.println(this.toString());
    }

    public void stop() {
        this.currentSpeed = 0;
        if(this.temperature - 10 >= 0)
            this.temperature -= 10; 
        this.status = 4;
    }

    public void speedUp(int speed) {
        if(this.speed + speed <= this.maxSpeed && this.power > 0) {
            this.speed += speed;
            this.temperature += (speed * 0.5);
            this.status = 2;
        }
    }

    public void speedUp() {
        if(this.speed + (this.currentSpeed * 0.1) <= this.maxSpeed && this.power > 0) {
            double speed = this.speed * 0.1;
            this.speed += speed;
            this.temperature += 0.5;
	    this.power -= 5;
            this.status = 2;
        }
    }
    
    public void speedDown(int speed) {
        if(this.currentSpeed - speed >= 0) {
            this.currentSpeed -= speed;
            this.temperature -= (speed * 0.5);
            if(this.currentSpeed == 0)
                this.status = 4;
        }
    }

    public void breaking() {
        this.currentSpeed -= (this.currentSpeed * 0.1);
        if(this.currentSpeed <= 0) {
            this.currentSpeed = 0;
            this.status = 4;
        }
    }

    public void standBy() {
        this.currentSpeed = 0;
        this.temperature = 0.0;
        this.status = 1;
    }

    public void exploring() {
        if(this.status == 4) 
            this.status = 3;
        this.temperature += 20.0;
    }

    public void returning() {
        if(this.status == 2) {
            this.status = 5;
	    this.power = 100; // carrega a bateria quando retorna
	}
    }
}
