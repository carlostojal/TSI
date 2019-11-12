
//
// Carlos Tojal 12-11-2019
// FT1
// TerceiroCiclo.java
//

public class TerceiroCiclo extends Funcionario {
	
	// Atributos
	private String escola;

	// Getters e setters
	public String getEscola() {
		return escola;
	}

	public void setEscola() {
		this.escola = escola;
	}

	// Métodos
	public float getVencimentoBase() {
		return ((2 * super.getVencimentoBase()) * 0.1f);
	}

	public float calculaVencimento() {
		return this.getVencimentoBase() + super.getComissao();
	}
}
