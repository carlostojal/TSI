
/*
* Copyright (c) Carlos Tojal 2019
* TesteIntermedio2018
* Almoco.java
*/

public class Almoco {
    private String descricao;
    private float preco;

    public Almoco(String descricao, float preco) {
        this.descricao = descricao;
        this.preco = preco;
    }

    public String getDescricao() {
        return descricao;
    }

    public void setDescricao(String descricao) {
        this.descricao = descricao;
    }

    public float getPreco() {
        return preco;
    }

    public void setPreco(float preco) {
        this.preco = preco;
    }
}