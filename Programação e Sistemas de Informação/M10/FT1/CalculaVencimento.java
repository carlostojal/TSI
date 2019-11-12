
//
// Carlos Tojal 12-11-2019
// FT1
// CalculaVencimento.java 
//

import java.util.Scanner;

public class CalculaVencimento {
	
	public static void main(String[] args) {

		Scanner s = new Scanner(System.in);
		
		System.out.print("Insira as habilitações literárias: ");
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

		System.out.println("Vencimento sem comissão: " + funcionario.getVencimentoBase());
		System.out.println("Comissão: " + comissao.getComissao());

		funcionario.setComissao(comissao.getComissao());

		System.out.println("Vencimento com comissão: " + funcionario.calculaVencimento());
	}

	/** A referência super está disponível em todos os métodos de instância duma
	* subclasse. No acesso a atributos e chamadas de métodos, a referência super 
	* funciona como uma referência vista como uma instância da superclasse.
	* A chamada do super.método usa sempre a implementação do método da superclasse
	* (definido ou herdado). */
}
