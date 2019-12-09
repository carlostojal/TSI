
//
// Carlos Tojal e Frederio Bento 05-12-2019
// Avaliacao
// Principal.java
//

import java.util.Scanner;
import java.util.ArrayList;

public class Principal {
    public static void main(String[] args) {
        int op = 0;
        ArrayList<Robot> robots = new ArrayList<Robot>();
        String nomeRobot, tipoRobot;
        int maxSpeed;
        Scanner sc = new Scanner(System.in);
        do{
            System.out.println("\n** Robots **\n");
            System.out.println("1 - Listar robots");
            System.out.println("2 - Criar um novo Robot");
            if(robots.size() > 0)
                System.out.println("3 - Selecionar Robot");
            System.out.println("4 - Eliminar Robot");
            System.out.println("0 - Sair\n");
            System.out.print("Opção: ");
            op = sc.nextInt();
            sc.nextLine(); //manda fora o buffer
            if(op == 1) {
                listarRobots(robots);
            }
            else if(op == 2){
                Robot robot;
                System.out.print("\nQual será o nome do robot?? ");
                nomeRobot = sc.nextLine();
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
                    	robot.setName(nomeRobot);
        				robot.setMaxSpeed(maxSpeed);
        				robot.setSpeed(1.0); // pois não é possível incrementar 10% a 0
                robots.add(robot);
            } else if(op == 3 && robots.size() > 0) {
        				int subopt;
        				Robot robot = selecionarRobo(robots);
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
            } else if(op == 4) {
                eliminarRobot(robots);
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
        int num = 0;
        do {
            listarRobots(robots);
            System.out.print("\nNumero: ");
            num = sc.nextInt();
            if(num > robots.size() || num < 1)
                System.out.println("Opcao invalida.");
        } while(num > robots.size());
        		return robots.get(num - 1);
    }

    public static void eliminarRobot(ArrayList<Robot> robots) {
        Scanner sc = new Scanner(System.in);
        int num;
        listarRobots(robots);
        System.out.print("\nNumero: ");
        num = sc.nextInt();
		    robots.remove(num - 1);
    }

    public static void listarRobots(ArrayList<Robot> robots) {
        System.out.println("\n** Listagem de robots **\n");
        if(robots.size() == 0)
            System.out.println("Lista vazia.");
        else {
            for(int i = 0; i < robots.size(); i++)
                System.out.println((i + 1) + ": " + robots.get(i).getName());
        }
    }
}
