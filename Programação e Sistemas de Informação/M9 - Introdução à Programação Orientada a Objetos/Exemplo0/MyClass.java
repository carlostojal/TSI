
/**
 * Este programa serve para explicar o método main. 
 * 
 * @author Carlos Tojal
 * @version (03-10-2019)
 */

public class MyClass {
    
    /**Método main()
     * No Java (e em outras linguagens também) o main é o ponto de entrada da aplicação.
     * É o método que a JRE procura para executar a aplicação.
     * Por isso, em alguns tipos de aplicação (como Swing ou console) é obrigatório tê-lo implementado.
     * Qualquer código dentro do método main () será executado.
     * Não precisa entender as palavras-passe antes e depois do main.
     * Por enquanto, lembre-de de que todo programa Java possui um nome de classe
     * que deve corresponder ao nome do arquivo e que todo o programa deve conter o método main ().*/
     
     /** static - Define o método como estático, isso quer dizer que a classe não precisa ser
      * instanciada para chamar este método.
      * void - É tipo de retorno do método. Este tipo de retorno significa vazio/nada,
      * o método que não dá retorno nenhum. Os métodos podem retornar qualquer tipo do seu projeto,
      * até mesmo criados por si.
      * main - É o nome do método. Todo e qualquer método precisa ter um nome.
      * Os nomes são definidos pelo programador e geralmente seguem algum padrão convencional definido
      * previamente pela linguagem ou pela comunidade, embora isso seja opcional.*/
     
    // variáveis de instância - substitua o exemplo abaixo pelo seu próprio
    private int x;

    /**
     * Construtor para objetos da classe MyClass
     */
    public MyClass() {
    }
    
    public static void main(String[] args) {
        System.out.println("Hello World");
    }
}
