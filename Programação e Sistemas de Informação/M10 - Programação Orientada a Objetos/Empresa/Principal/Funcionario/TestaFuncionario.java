
//
// Carlos Tojal 18-11-2019
// Empresa
// TestaFuncionario.java
//

package Principal.Funcionario;

public class TestaFuncionario {
 
    public static void main(String[] args) {
        Funcionario funcionario = new Funcionario();
        funcionario.setNome("Thiago");
        funcionario.setSalario(2500);
         
        System.out.println(funcionario.getNome());
        System.out.println(funcionario.getSalario());
 
    }
}
