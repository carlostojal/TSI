//
// Carlos Tojal (29-10-2019)
// ExProposto2
// Carro.java
//

public class Carro {
    //Atributos
    private String cor;
    private int n_portas;
    private int max_pessoas;
    private int ano_fabrico;
    private int ano_modelo;
    private String marca;
    private String modelo;
    private int n_pessoas;
    private int peso_carro;
    private double km;
    private double consumo;
    private double litros;
    private boolean ligado;

    //Getters e setters
    public String getCor() {
        return cor;
    }

    public void setCor(String cor) {
        this.cor = cor;
    }

    public String getNportas() {
        return n_portas;
    }

    public void setNportas(int n_portas) {
        this.n_portas = n_portas;
    }

    public int getMaxPessoas() {
        return max_pessoas;
    }

    public void setMaxPessoas(int max_pessoas) {
        this.max_pessoas = max_pessoas;
    }

    public int getAnoFabrico() {
        return ano_fabrico;
    } 

    public void setAnoFabrico(int ano_fabrico) {
        this.ano_fabrico = ano_fabrico;
    }

    public int getAnoModelo() {
        return ano_modelo;
    }

    public void setAnoModelo(int ano_modelo) {
        this.ano_modelo = ano_modelo;
    }

    public String getMarca() {
        return marca;
    }

    public void setMarca(String marca) {
        this.marca = marca;
    }

    public String getModelo() {
        return modelo;
    }

    public void setModelo(String modelo) {
        this.modelo = modelo;
    }

    public int getNpessoas() {
        return n_pessoas;
    }

    public void setNpessoas(int n_pessoas) {
        this.n_pessoas = n_pessoas;
    }

    public double getPesoCarro() {
        return peso_carro;
    }

    public void setPesoCarro(double peso_carro) {
        this.peso_carro = peso_carro;
    }

    public double getKm() {
        return km;
    }

    public void setKm(double km) {
        this.km = km;
    }

    public double getConsumo() {
        return consumo;
    }

    public void setConsumo(double consumo) {
        this.consumo = consumo;
    }

    public double getLitros() {
        return litros;
    }

    public void setLitros(double litros) {
        this.litros = litros;
    }

    public boolean isLigado() {
        return ligado;
    }

    //Construtores
    public Carro() {
    }

    public Carro(String cor, int n_portas, int ano_fabrico, int ano_modelo, String marca, String modelo) {
        this.cor = cor;
        this.n_portas = n_portas;
        this.ano_fabrico = ano_fabrico;
        this.ano_modelo = ano_modelo;
        this.marca = marca;
        this.modelo = modelo;
    }

    public Carro(String cor, int n_portas, int ano_fabrico, int ano_modelo, String marca, String modelo, int n_pessoas, int peso_carro) {
        this.cor = cor;
        this.n_portas = n_portas;
        this.ano_fabrico = ano_fabrico;
        this.ano_modelo = ano_modelo;
        this.marca = marca;
        this.modelo = modelo;
        this.n_pessoas = n_pessoas;
        this.peso_carro = peso_carro;
    }

    public Carro(String cor, int n_portas, int ano_fabrico, int ano_modelo, String marca, String modelo, int n_pessoas, double peso_carro, double consumo, double km, double litros) {
        this.cor = cor;
        this.n_portas = n_portas;
        this.ano_fabrico = ano_fabrico;
        this.ano_modelo = ano_modelo;
        this.marca = marca;
        this.modelo = modelo;
        this.n_pessoas = n_pessoas;
        this.peso_carro = peso_carro;
        this.consumo = consumo;
        this.km = km;
        this.litros = litros;
    }

    //Métodos
    public void acelerar() {

    }

    public void travar() {
        
    }

    public void ligar() {
        if(getNpessoas() > 0 && getLitros() > 0)
            this.ligado = true;
    }

    public void pessoasDentro(int n_pessoas) {
        this.n_pessoas = n_pessoas;
    }

    public void velocidade(double velocidade) {
        
    }
}