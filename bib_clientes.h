#ifndef BIB_CLIENTES_H
#define BIB_CLIENTES_H
#define TAM_CARD 51
#define TAM_CLI 20

#define CLIENTE 1
#define FUNCIONARIO 2
#define ADMINISTRATIVO 3

#define CARDAPIO 1
#define ATENDENTE 2
#define PEDIR_CONTA 3
#define VOLTA 4

#define CARTAO 1
#define DINHEIRO 2


struct cardapio {
    char item[51];
    int preco;
};

typedef struct cardapio Cardapio;

struct cliente {
    int id;
    int conta;
};

typedef struct cliente Cliente;

/*A funcao menu_principal_cliente() imprime o
//menu principal do modulo de clientes*/
void menu_principal_cliente();


/*Atribui os itens do cardapio */
void preenche_cardapio(Cardapio *card, int tam);

/* */
Cardapio* inicia_cardapio(int tam);

/* */
void imprime_cardapio(Cardapio *card, int tam);

/* */
void termina_cardapio(Cardapio *card);

/* */
Cliente* inicia_clientes(int tam);

/* */
void cria_cliente(Cliente *cli, int tam, int id);

/* */
void escolhe_cardapio(Cardapio *card, int tam, Cliente *cli, int id, char *escolha);

/* */
void opt_pagamento();

/* */
float pag_cartao (float conta, float par);

/* */
float pag_dinheiro(float t,float cont);


#endif // BIB_CLIENTES_H

