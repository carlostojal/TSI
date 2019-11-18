
//
// Carlos Tojal 18-11-2019
// Empresa
// Funcionario.java
//

package Principal.Funcionario;

public class Funcionario {
    private String nome;
    private double salario;
 
    public String getNome() {
        return nome;
    }
 
    public void setNome(String nome) {
        this.nome = nome;
    }
 
    public double getSalario() {
        return salario;
    }
 
    public void setSalario(double salario) {
        this.salario = salario;
    }
     
    public double calculaBonificacao(){
        return this.salario * 0.1;
    }
 
}
