
//
// Carlos Tojal 12-11-2019
// FT1
// CalculaVencimento.java 
//

import java.util.Scanner;

public class CalculaVencimento {
	
	public static void main(String[] args) {

		Scanner s = new Scanner(System.in);
		
		System.out.print("Insira as habilita��es liter�rias: ");
		String habilitacoesLiterarias = s.nextLine();

		System.out.print("Insira o cargo: ");
		String cargo = s.nextLine();

		Funcionario funcionario;
		Comissao comissao;

		if(habilitacoesLiterarias.equals("sem estudos")) 
			funcionario = new Funcionario();
		else if(habilitacoesLiterarias.equals("3 ciclo"))
			funcionario = new TerceiroCiclo();
		else if(habilitacoesLiterarias.equals("secundario"))
			funcionario = new Secundario();
		else
			funcionario = new Superior();
		
		if(cargo.equals("gerente"))
			comissao = new Gerente();
		else if(cargo.equals("supervisor"))
			comissao = new Supervisor();
		else 
			comissao = new Vendedor();

		System.out.println("Vencimento sem comiss�o: " + funcionario.getVencimentoBase());
		System.out.println("Comiss�o: " + comissao.getComissao());

		funcionario.setComissao(comissao.getComissao());

		System.out.println("Vencimento com comiss�o: " + funcionario.calculaVencimento());
	}

	/** A refer�ncia super est� dispon�vel em todos os m�todos de inst�ncia duma
	* subclasse. No acesso a atributos e chamadas de m�todos, a refer�ncia super 
	* funciona como uma refer�ncia vista como uma inst�ncia da superclasse.
	* A chamada do super.m�todo usa sempre a implementa��o do m�todo da superclasse
	* (definido ou herdado). */
}
