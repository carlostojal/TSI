# Teste M6
## Teoria
### 1. Identifique quais as informações verdadeiras e quais as falsas
a) Em C, o termo typedef é obrigatório na definição de uma estrutura - Falso

b) Em C, uma estrutura pode incluir um ponteiro para si própria - Verdadeiro

c) Se o nó de uma lista apontar o nó seguinte, estamos perante uma lista dupla - Falso

d) O apontador que indica o próximo nó de um elemento que está em último é sempre NULL - Falso

e) Se prox for um apontador para uma estrutura ptr da qual faz parte, podemos aceder ao nó anterior fazendo ptr->prox - Verdadeiro

f) Numa lista circular não existe o conceito de último elemento - Falsa

### 2. Justifique as afirmações que considerou falsas na questão anterior
a) Em C, o termo typedef é facultativo, mas o termo struct é obrigatório.

c) Se o nó de uma lista apontar apenas o nó seguinte, estamos perante uma lista simples.

d) O apontador que indica o próximo elemento de um nó que está em último é sempre NULL quando se trata de uma lista circular ou dupla.

f) Numa lista circular, o último elemento é o que tem como seu sucessor o header.

### 3. Considerando a estrutura seguinte:
`typedef struct Mod6s
{
    struct Mod6s *next;
    int v1,v2;
}Mod6;
`

#### a) Implemente uma função que permita mostrar uma listagem da estrutura Mod6s, respeitando o seguinte protótipo.
`int mostra_lista(Mod6 *ptr);`
`int mostra_lista(Mod6 *ptr)
{
    Mod6 *p;
    for(p=ptr->next;p!=NULL;p=p->next)
    {
        printf("\nv1 = %d",p->v1);
        printf("\nv2 = %d",p->v2);
    }
    return 0;
}
