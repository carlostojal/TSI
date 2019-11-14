
//
// Carlos Tojal 14-11-2019
// Ex1
// TesteBuzinar2.java
//

import java.util.Scanner;

public class TesteBuzinar2 {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		String input;
		Carro carro;
		boolean sucesso = false;
		
		System.out.print("Tipo de carro: ");
		input = scanner.nextLine();

		if(input.equals("citadino")){
			carro = new Citadino();
			sucesso = true;
		}
		else if(input.equals("familiar")) {
			carro = new Familiar();
			sucesso = true;
		}
		else if(input.equals("jipe")) {
			carro = new Jipe();
			sucesso = true;
		}
		else {
			carro = new Carro();
			System.out.println("Tipo inválido.");
		}
		
		if(sucesso) {
			if(carro instanceof Citadino)
				((Citadino)carro).ligarACManual();
			else if(carro instanceof Familiar)
				((Familiar)carro).desligarAirbagPassageiro();
			else if(carro instanceof Jipe)
				((Jipe)carro).ligarTracao4x4();
		}
	}
}
