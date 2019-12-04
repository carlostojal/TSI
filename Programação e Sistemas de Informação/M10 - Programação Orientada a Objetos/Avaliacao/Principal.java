//
// Carlos Tojal Frederio Bento  28-11-2019
// Avaliacao
// Principal.java
//

import java.util.Scanner;
import java.util.ArrayList;

public class Principal {
    public static void main(String[] args) {
        int op = 0;
        ArrayList<Robot> robo = new ArrayList<Robot>();
        String nomeRobo, tipoRobot;
		int maxSpeed;
        Scanner sc = new Scanner(System.in);
        do{
            System.out.println("\n** Robots **\n");
            System.out.println("1 - Criar um novo Robo");
            System.out.println("2 - Selecionar Robo");
            System.out.println("0 - Sair\n");
            System.out.print("Opção: ");
            op = sc.nextInt();
            sc.nextLine(); //manda fora o buffer
            if(op==1){
                Robot robot;
                System.out.print("\nQual será o nome do robo?? ");
                nomeRobo = sc.nextLine();
				System.out.print("Velocidade maxima: ");
				maxSpeed = sc.nextInt();
				sc.nextLine();
				System.out.print("Tipo de robot: ");
				tipoRobot = sc.nextLine();
				if(tipoRobot.equals("androide"))
			    	robot = new Androide();
				else if(tipoRobot.equals("zoomorfico"))
			    	robot = new Zoomorfico();
				else
			    	robot = new Robot();
            	robot.setName(nomeRobo);
				robot.setMaxSpeed(maxSpeed);
				robot.setSpeed(1.0); // pois não é possível incrementar 10% a 0
                robo.add(robot);
            } else if(op==2) {
				int subopt;
				Robot robot = selecionarRobo(robo);
				do {
			    	System.out.println("\n** Robot " + robot.getName() + " **\n");
			    	System.out.println("1. Listar");
			    	System.out.println("2. Parar");
			    	System.out.println("3. Acelerar");
			    	System.out.println("4. Abrandar");
			    	System.out.println("5. Travar");
			    	System.out.println("6. Standby");
			    	System.out.println("7. Explorar");
			    	System.out.println("8. Retornar");
			    	System.out.println("0. Voltar");
			    	System.out.print("\nOpcao: ");
			    	subopt = sc.nextInt();
			    	switch(subopt) {
						case 1:
							listarRobot(robot);
							break;
						case 2:
							robot.stop();
							break;
						case 3:
							robot.speedUp();
							break;
						case 4:
							System.out.print("\nValor a desacelerar: ");
							int x = sc.nextInt();
							robot.speedDown(x);
							break;
						case 5:
							robot.breaking();
							break;
						case 6:
							robot.standBy();
							break;
						case 7:
							robot.exploring();
							break;
						case 8:
							robot.returning();
							break;
			    	}
				}while(subopt != 0);
            }
        }while(op != 0);
    }

    public static void listarRobot(Robot robot) {
	robot.show();
	System.out.print("Tipo: ");
	if(robot instanceof Androide)
	    System.out.println("Androide");
	else if(robot instanceof Zoomorfico)
	    System.out.println("Zoomorfico");
	else
	    System.out.println("Generico");
    }

    public static Robot selecionarRobo(ArrayList<Robot> robots) {
        Scanner sc = new Scanner(System.in);
        int num;
        listarRobots(robots);
        System.out.print("\nNumero: ");
        num = sc.nextInt();
		return robots.get(num - 1);
    }

    public static void listarRobots(ArrayList<Robot> robots) {
        System.out.println("\n** Listagem de robots **\n");
        for(int i = 0; i < robots.size(); i++) 
            System.out.println((i + 1) + ": " + robots.get(i).getName());
    }
}
