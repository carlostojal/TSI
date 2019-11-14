
//
// Carlos Tojal 12-11-2019
// FT1
// Secundario.java
//

public class Secundario extends TerceiroCiclo {
	
	// Métodos
	public float getVencimentoBase() {
		return ((super.getVencimentoBase() * 2) * 0.5f);
	}

	public float calculaVencimento() {
		return this.getVencimentoBase() + super.getComissao();	
	}
}
