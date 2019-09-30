public class Main
{
    Car car = new Car(); //instanciação do objeto "car"
    public static void main(String[] args) {
        System.out.println("The car brand is "+car.getBrand());
        System.out.println("It's from "+car.getYear());
        System.out.println("It's "+car.getColor());
        System.out.println("And it sounds like "+car.getSound());
    }
}
