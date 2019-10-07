public class Variaveis {
    /**
     * Crie uma variável chama myNum do tipo int e atribua o valor 5
     */
    int mynum = 5; //Integer (whole number)

    /**
     * Pode declarar uma variável sem atribuir o valor e atrubuir o valor posteriormente:
     * int myNum;
     * myNum = 5;
     */
    int x = 5;
    int y = 6;
    float myFloatNum = 5.99f;   //Floating point number
    char myLetter = 'D';        //Character
    boolean myBool = true;      //Boolean
    String myText = "Hello";    //String
    String firstName = "John";
    String lastName = "Smith";
    String fullName = firstName + lastName;
    /**Data types are divided into two groups:
     * Primitive data types - includes byte, short, int, long, float, double, boolean and char
     * Non-primitive data types - such as String, Arrays and Classes
     */

    /**In Java, there are two types of casting:
     * Widening Casting (automatically) - converting a smaller type to a larger type size
     * byte -> short -> char -> int -> long -> float -> double
     *
     * Narrowing Casting (manually) - converting a larger type to a smaller size type
     * double -> float -> long -> int -> char -> short -> byte
     */

    /**
     * Construtor para objetos da classe Variaveis
     */
    public Variaveis() {
        System.out.println(fullName);
    }

    public static void main(String[] args) {
        /**Quando há cálculos não se pode colucar o método main como static*/
        int x = 5;
        int y = 6;
        System.out.println(x + y); //Print the value of x + y
        System.out.println(x + " and " + y + " is " + (x+y));
    }

    public int sampleMethod(int x , int y) {
        return x + y;
    }
}
