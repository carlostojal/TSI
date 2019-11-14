
//
// Carlos Tojal 11-11-2019
// FT1
// Funcionario.java
//

public class Funcionario {

	// Atributos
	private int codigoFuncionario;		
	private String nomeFuncionario;
	private final float vencimentoBase = 500.0f; // esta variável não pode ser alterada devido ao modificador "final"
	private float comissao;

	// Getters e setters
	public int getCodigoFuncionario() {
		return codigoFuncionario;
	}

	public void setCodigoFuncionario(int codigoFuncionario) {
		this.codigoFuncionario = codigoFuncionario;
	}

	public String getNomeFuncionario() {
		return nomeFuncionario;
	}

	public void setNomeFuncionario(String nomeFuncionario) {
		this.nomeFuncionario = nomeFuncionario;
	}

	public float getVencimentoBase() {
		return vencimentoBase;
	}

	public float getComissao() {
		return comissao;
	}

	public void setComissao(float comissao) {
		this.comissao = comissao;
	}

	// Construtor
	public Funcionario() {
	}
}
