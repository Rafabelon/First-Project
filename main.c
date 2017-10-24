#include <stdio.h>
#include "bib_clientes.h"



/* a funcao func_inicia demonstra a mensagem inicial
//do programa */
void func_inicia();

/*A funcao menu_principal() imprime o menu principal*/
void menu_principal();

/*A funcao switch_menu() sera utilizada para devolver o
//valor da escolha do usuario nos menus do sistema*/
int switch_menu(int n);

int main() {
    int c, opt_cli, qtd_clientes;
    int opt, opt1, conta, par;
    float troco;
    char escolha[51];
    opt = 0;
    opt1 = 0;
    conta = 0;

    qtd_clientes = 1;

    Cardapio *card = inicia_cardapio(TAM_CARD);
    Cliente *cli = inicia_clientes(TAM_CLI);


    func_inicia();
    menu_principal();
    preenche_cardapio(card, TAM_CARD);

    scanf("%d", &c);
    while (c > 3) {
        printf("Opcao Invalida!\n");
        printf("Escolha entre 1 e 3...\n");
        scanf("%d", &c);
    }
    if (c == CLIENTE) {
        while (opt_cli != VOLTA) {
            cria_cliente(cli, TAM_CLI, qtd_clientes);
            menu_principal_cliente();
            scanf("%d", &opt_cli);
            if (opt_cli == CARDAPIO) {
                printf("B\n");
                imprime_cardapio(card, TAM_CARD);

                while (opt != 2) {
                    scanf(" %[^\n]s", escolha); /* para ler strings com
                    //espaco utiliza " %[^\n]s lembrando q o espaco depois da "
                    //serve para limpar p buffer do teclado e o simbolo ^ nega \n que
                    // quebra a linha */
                    printf("%s\n", escolha);
                    //setbuf(stdin, NULL);
                    escolhe_cardapio(card, TAM_CARD, cli, qtd_clientes, escolha);
                    printf("Deseja algo mas?\n");
                    printf("(1) Sim.\n");
                    printf("(2) Nao.\n");
                    scanf("%d", &opt);
                    conta = cli[qtd_clientes].conta;
                }
            } else if (opt_cli == ATENDENTE) {
                printf("Um de nossos atendentes ira para a mesa %d\n", qtd_clientes);
            } else if (opt_cli == PEDIR_CONTA) {
                printf("O valor da sua conta eh  de R$ %d\n", conta);
                opt_pagamento();
                scanf("%d", &opt1);
                if (opt1 == CARTAO) {
                    printf("Em quantas vezes deseja pagar?\n");
                    scanf("%d", &par);
                    while (par > 12) {
                        printf("Parcelamento maximo e de 12x\n");
                        printf("Porvafor escolha um numero de parcelas validas\n");
                        scanf("%d", &par);
                    }
                    printf("A sua conta de R$ %d sera paga com cartao em %d parcelas de R$ %.2f\n", conta, par, pag_cartao(conta, par));
                } else if (opt1 == DINHEIRO) {
                    printf("Valor da sua conta eh de R$ %d\n", conta);
                    printf("Troco para quanto?\n");
                    scanf("%f", &troco);
                    printf("O seu troco eh R$ %.2f\n", pag_dinheiro(troco, conta));
                }
            }
        }
        if (opt_cli == VOLTA)
            return main();
        qtd_clientes++;
    }
    termina_cardapio(card);
    return 0;
}

void func_inicia() {
    printf("***************************************\n");
    printf("Seja Bem Vindo ao restaurante My_rest!!\n");
    printf("***************************************\n");\
    printf("\n");
}

void menu_principal() {
    printf("Favor escolha uma opcao.\n");
    printf("\n");
    printf("(1) Clientes.\n");
    printf("(2) Funcionarios.\n");
    printf("(3) Administrativo.\n");
}

int switch_menu(int n) {
    switch (n) {
    case 1:
        return 1;
        break;
    case 2:
        return 2;
        break;
    case 3:
        return 3;
        break;
    case 4:
        return 4;
        break;
    }
    return 0;
}


