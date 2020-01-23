
//
// Copyright (c) Carlos Tojal 2020
// SistemaBancario
// Banco.java
//

public class Banco
{
    private int senha;
    private double saldo,levantamento,cpmf,limite;
    private String nome,sobrenome, genero;

    public Banco(String nom, String sobre)
    {
        this.nome = nome;
        this.sobrenome= sobre;
    }
    public Banco(int sen)
    {
        this.senha = sen;
    }
    public Banco(double sald, double lev, double cp, double lm)
    {
        if (sald > 0.00 && lev > 0.00)
            this.saldo = sald;
        this.levantamento = lev;
        this.cpmf = cp;
        this.limite = lm;
    }

    public void setNome(String n)
    {
        this.nome = n;
    }

    public void setSobre(String s)
    {
        this.sobrenome = s;
    }

    public void setGenero(String g) {
        this.genero = g;
    }

    public void setSaldo(double sa)
    {
        this.saldo = sa;
    }

    public void setLevantamento(double lev)
    {
        this.levantamento = lev;
    }

    public void setCpmf(double cm)
    {
        this.cpmf = cm;
    }

    public void setLimite(double lt)
    {
        this.limite = lt;
    }

    public void setSenha(int sh)
    {
        this.senha = sh;
    }

//exibe o valor armazenado no set

    public String getNome()
    {
        return nome;
    }

    public String getSobre()
    {
        return sobrenome;
    }

    public String getGenero() {
        return genero;
    }

    public double getSald()
    {
        return saldo;
    }

    public double getLevantamento()
    {
        return levantamento;
    }

    public double getCpmf()
    {
        return cpmf;
    }

    public double getLimite()
    {
        return limite;
    }

    public int getSenha()
    {
        return senha;
    }

}