/**Ler um vetor A com 10 elementos inteiros correspondentes às idades de um grupo.
 Escreva um programa que determine e escreva a menor e a maior das idades e as suas
 respetivas posições.*/

import java.util.Scanner;

public class IdadeAdulta {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int arr_size = 10;
        int ages[] = new int[arr_size];
        int smallest = 150, biggest = 0;
        int smallest_position = 0, biggest_position = 0;

        for(int i = 0; i < arr_size; i++) {
            do {
                System.out.print("Idade do " + (i+1) + " elemento: ");
                ages[i] = scanner.nextInt();
            }while(ages[i] < 0 || ages[i] > 150);
            if(ages[i] < smallest) {
                smallest = ages[i];
                smallest_position = i + 1;
            }
            else if(ages[i] > biggest) {
                biggest = ages[i];
                biggest_position = i + 1;
            }
        }

        System.out.println("O elemento com maior idade é o " + biggest_position + " com " + biggest + " anos.");
        System.out.println("O elemento com menor idade é o " + smallest_position + " com " + smallest + " anos.");
    }
}