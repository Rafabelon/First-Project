#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "bib_clientes.h"



void menu_principal_cliente() {
    printf("******Clientes******\n");
    printf("(1) Cardapio.\n");
    printf("(2) Chamar Atendente.\n");
    printf("(3) Pedir a Conta.\n");
    printf("(4) Voltar.\n");
}

Cardapio* inicia_cardapio(int tam) {
    int i;
    Cardapio *card = malloc(tam * sizeof(Cardapio));

    for (i = 0; i < tam; i++) {
        strcpy(card[i].item, "");
        card[i].preco = -1;
    }
    return card;
}

void termina_cardapio(Cardapio *card) {
    free(card);
}

Cliente* inicia_clientes(int tam) {
    int i;
    Cliente *cli = malloc(tam * sizeof(Cliente));

    for (i = 0; i < tam; i++) {
        cli[i].id = -1;
        cli[i].conta = -1;
    }
    return cli;
}

void cria_cliente(Cliente *cli, int tam, int id) {
    cli[id].id = id;
    cli[id].conta = 0;
}

void preenche_cardapio(Cardapio *card, int tam) {


    strcpy (card[0].item,"PALMITO ASSADO");
    card[0].preco = 36;
    strcpy (card[1].item, "ISCAS DE FRALDINHA");
    card[1].preco = 33;
    strcpy (card[2].item, "MINI PASTEIS DE CARNE");
    card[2].preco = 16;
    strcpy (card[3].item, "CESTA DE BATATAS FRITAS");
    card[3].preco = 19;
    strcpy (card[4].item, "BATATAS FRITAS COM MOLHO DE QUEIJOS");
    card[4].preco = 26;
    strcpy (card[5].item, "PENNE COM MOLHO DO CHEF");
    card[5].preco = 37;
    strcpy (card[6].item, "PENNE COM PEITO DE FRANGO");
    card[6].preco = 35;
    strcpy (card[7].item, "PENNE A PRIMAVERA");
    card[7].preco = 37;
    strcpy (card[8].item, "PICANHA SUPER PREMIUM - 350G");
    card[8].preco = 63;
    strcpy (card[9].item, "CORDEIRO URUGUAYO");
    card[9].preco = 65;
    strcpy (card[10].item, "COSTELINHA DE 800G");
    card[10].preco = 59;
    strcpy (card[11].item, "HAMBURGER BOVINO - 180G");
    card[11].preco = 34;
    strcpy (card[12].item, "HAMBURGER DE CORDEIRO - 180G");
    card[12].preco = 41;
}

void imprime_cardapio(Cardapio *card, int tam){
    int i;
    for (i = 0; i < tam; i++) {
        if (card[i].preco > 0)
            printf("%s valor %d\n", card[i].item, card[i].preco);
    }

}

void escolhe_cardapio(Cardapio *card, int tam, Cliente *cli, int id, char *escolha) {
    int i;
    for (i = 0; i < tam; i++) {
        if (strcmp(escolha, card[i].item) == 0) {
            cli[id].conta = cli[id].conta + card[i].preco;
        }
    }
}

void opt_pagamento() {
    printf("Selecione a opcao de Pagamaneto.\n");
    printf("(1) Cartao de credito.\n");
    printf("(2) Dinheiro.\n");
}

float pag_cartao(float conta, float par) {
    float parcela;

    parcela = conta / par;
    return parcela;
}

float pag_dinheiro(float t,float cont) {
    float troco;

    troco = t - cont;
    return troco;
}




