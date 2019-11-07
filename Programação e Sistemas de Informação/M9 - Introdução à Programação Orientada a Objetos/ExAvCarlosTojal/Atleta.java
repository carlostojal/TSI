
//
// Carlos Tojal 04-11-2019
// ExAvCarlosTojal
// Atleta.java
//

public class Atleta {

    // Atributos
    private String nome;
    private long contacto;
    private String nacionalidade;
    private int numeroCamisa;
    private String posicao;
    private boolean status;
    private DadosFisicos dadosFisicos;

    // Getters e setters
    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public long getContacto() {
        return contacto;
    }

    public void setContacto(long contacto) {
        this.contacto = contacto;
    }

    public String getNacionalidade() {
        return nacionalidade;
    }

    public void setNacionalidade(String nacionalidade) {
        this.nacionalidade = nacionalidade;
    }

    public int getNumeroCamisa() {
        return numeroCamisa;
    }

    public void setNumeroCamisa(int numeroCamisa) {
        this.numeroCamisa = numeroCamisa;
    }

    public String getPosicao() {
        return posicao;
    }

    public void setPosicao(String posicao) {
        this.posicao = posicao;
    }

    public boolean getStatus() {
        return status;
    }

    public void setStatus(boolean status) {
        this.status = status;
    }

    public DadosFisicos getDadosFisicos() {
        return dadosFisicos;
    }

    public void setDadosFisicos(DadosFisicos dadosFisicos) {
        this.dadosFisicos = dadosFisicos;
    }

    // Construtores
    public Atleta() {
        nome = "";
        contacto = 351967848721L;
        nacionalidade = "Portuguesa";
        numeroCamisa = 0;
        posicao = "";
        status = false;
    }

    public Atleta(String nome, long contacto, String nacionalidade) {
        this.nome = nome;
        this.contacto = contacto;
        this.nacionalidade = nacionalidade;
    }

    public Atleta(int numeroCamisa, String posicao) {
        this.numeroCamisa = numeroCamisa;
        this.posicao = posicao;
    }

    // Métodos
    public int alteraStatus() {
        double imc = getDadosFisicos().calcularImc(getDadosFisicos().getPeso(), getDadosFisicos().getAltura());
        /*
        if(imc < 18.5)
            return -1;
        else if(imc >= 18.5 && imc < 25) {
            status = true;
            return 0;
        }
        else if(imc >= 25 && imc <= 30)
            return -1;
        else
            return -1;
        */

        if(imc >= 18.5 && imc < 25) {
            status = true;
            return 0;
        } else {
            return -1;
        }
    }

    public void exibirDados() {
        System.out.println("\n** Atleta **\n");
        System.out.println("Nome: " + getNome());
        System.out.println("Contato: " + getContacto());
        System.out.println("Nacionalidade: " + getNacionalidade());
        System.out.println("Numero da Camisa: " + getNumeroCamisa());
        System.out.println("Posicao: " + getPosicao());
        System.out.println("Status: " + getStatus());
    }
}