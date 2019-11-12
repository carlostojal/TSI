
//
// Carlos Tojal 12-11-2019
// FT1
// Superior.java
//

public class Superior extends Secundario {
	
	// Atributos
	private String universidade;

	// Getters e setters
	public String getUniversidade() {
		return universidade;
	}

	public void setUniversidade(String universidade) {
		this.universidade = universidade;
	}

	// Métodos
	public float getVencimentoBase() {
		return (2 * super.getVencimentoBase());
	}

	public float calculaVencimento() {
		return this.getVencimentoBase() + super.getComissao();
	}
}
