#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// declarações de funções e procedimentos

// operacionais
void limpa_buffer();
void tela_espera();
void limpa_tela();

// menus
void boas_vindas();
void menu_principal();
void despedida();

// lista
void iniciando_lista(char lista[][2][100], int tamanho_lista);
void adicionar_itens(char lista[][2][100], int tamanho_lista, char *categoria, char *item);
int  listar_itens(char lista[][2][100], int tamanho_lista);
void remover_itens(char lista[][2][100], int tamanho_lista, int indice);


int main() {

    char lista[10][2][100];
    int tamanho_lista = 10;
    char op_user;

    iniciando_lista(lista, tamanho_lista);
    boas_vindas();

    do {
        limpa_tela();
        menu_principal();
        printf("Escolha uma opcao: ");
        op_user = getchar();
        limpa_buffer();

        switch (op_user) {

            case '1': {
                limpa_tela();
                char nome_tarefa[100];
                char categoria_tarefa[100];

                printf("---------------------------------------\n");
                printf("           ADICIONAR TAREFA\n");
                printf("---------------------------------------\n\n");

                printf("  Nome da tarefa: ");
                fgets(nome_tarefa, 100, stdin);
                nome_tarefa[strcspn(nome_tarefa, "\n")] = '\0';
                putchar('\n');

                printf("---------------------------------------\n\n");
                printf("  Categoria: ");
                fgets(categoria_tarefa, 100, stdin);
                categoria_tarefa[strcspn(categoria_tarefa, "\n")] = '\0';
                putchar('\n');

                adicionar_itens(lista, tamanho_lista, categoria_tarefa, nome_tarefa);

                printf("---------------------------------------\n");
                printf("          TAREFA ADICIONADA!\n");
                printf("---------------------------------------\n\n");
                printf("  Digite enter...");
                tela_espera();
                break;
            }

            case '2': {
                limpa_tela();
                printf("---------------------------------------\n");
                printf("             SUAS TAREFAS\n");
                printf("---------------------------------------\n\n");

                listar_itens(lista, tamanho_lista);

                putchar('\n');
                printf("  Digite enter...");
                tela_espera();
                break;
            }

            case '3': {
                limpa_tela();
                printf("---------------------------------------\n");
                printf("            REMOVER TAREFA\n");
                printf("---------------------------------------\n\n");

                if (!listar_itens(lista, tamanho_lista)) {
                    putchar('\n');
                    printf("  Digite enter...");
                    tela_espera();
                    break;
                }

                putchar('\n');
                printf("---------------------------------------\n");

                char entrada[10];
                int indice;

                printf("  Digite o numero da tarefa: ");
                fgets(entrada, sizeof(entrada), stdin);
                indice = atoi(entrada) - 1;

                if (indice < 0 || indice >= tamanho_lista || lista[indice][0][0] == '\0') {
                    printf("\n  Numero invalido.\n\n");
                    printf("  Digite enter...");
                    tela_espera();
                    break;
                }

                // confirmação
                limpa_tela();
                printf("---------------------------------------\n");
                printf("            REMOVER TAREFA\n");
                printf("---------------------------------------\n\n");
                printf("  Tarefa selecionada:\n\n");
                printf("  > %s  [%s]\n\n", lista[indice][1], lista[indice][0]);
                printf("  Tem certeza que deseja remover?\n");
                printf("  1. Sim, remover\n");
                printf("  2. Nao, voltar\n\n");
                printf("---------------------------------------\n");
                printf("  Escolha uma opcao: ");

                char confirmacao = getchar();
                limpa_buffer();

                if (confirmacao == '1') {
                    remover_itens(lista, tamanho_lista, indice);
                    limpa_tela();
                    printf("---------------------------------------\n");
                    printf("            REMOVER TAREFA\n");
                    printf("---------------------------------------\n\n");
                    printf("  Tarefa removida com sucesso!\n\n");
                } else {
                    printf("\n  Operacao cancelada.\n\n");
                }

                printf("  Digite enter...");
                tela_espera();
                break;
            }

            case '0':
                break;

            default: {
                printf("=======================================\n");
                printf("       DIGITE UMA OPCAO VALIDA!\n");
                printf("=======================================\n\n");
                printf("  Digite enter...");
                tela_espera();
            }
        }

    } while (op_user != '0');

    limpa_tela();
    despedida();

    return 0;
}


// operacionais

void limpa_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void tela_espera() {
    while (getchar() != '\n');
}

void limpa_tela() {
    system("clear");
}


// menus

void boas_vindas() {
    printf("=======================================\n");
    printf("       BEM-VINDO AO TODO LIST\n");
    printf("=======================================\n\n");
    printf("  Gerencie suas tarefas de forma\n");
    printf("  simples e rapida pelo terminal.\n\n");
    printf("  Pressione ENTER para continuar...");
    tela_espera();
}

void menu_principal() {
    printf("---------------------------------------\n");
    printf("           MENU PRINCIPAL\n");
    printf("---------------------------------------\n\n");
    printf("  1. Adicionar tarefa\n");
    printf("  2. Listar tarefas\n");
    printf("  3. Remover tarefa\n");
    printf("  0. Sair\n\n");
    printf("---------------------------------------\n");
}

void despedida() {
    printf("=======================================\n");
    printf("              ATE LOGO!\n");
    printf("=======================================\n\n");
    printf("            Volte sempre!\n\n");
}


// lista

void iniciando_lista(char lista[][2][100], int tamanho_lista) {
    for (int i = 0; i < tamanho_lista; i++) {
        memset(lista[i][0], 0, 100);
        memset(lista[i][1], 0, 100);
    }
}

void adicionar_itens(char lista[][2][100], int tamanho_lista, char *categoria, char *item) {
    for (int i = 0; i < tamanho_lista; i++) {
        if (lista[i][0][0] == '\0') {
            strncpy(lista[i][0], categoria, 99);
            strncpy(lista[i][1], item, 99);
            lista[i][0][99] = '\0';
            lista[i][1][99] = '\0';
            return;
        }
    }
    printf("\n  Lista cheia! Remova uma tarefa antes de adicionar.\n");
}

int listar_itens(char lista[][2][100], int tamanho_lista) {
    int encontrado = 0;
    for (int i = 0; i < tamanho_lista; i++) {
        if (lista[i][0][0] == '\0')
            continue;
        printf("  %d. %s  [%s]\n", (i + 1), lista[i][1], lista[i][0]);
        encontrado = 1;
    }
    if (!encontrado) {
        printf("  Nenhuma tarefa cadastrada.\n");
        return 0;
    }
    return 1;
}

void remover_itens(char lista[][2][100], int tamanho_lista, int indice) {
    memset(lista[indice][0], 0, 100);
    memset(lista[indice][1], 0, 100);
}