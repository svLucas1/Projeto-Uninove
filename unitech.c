Andrey Alexandre Araujo - RA 3025102409
Arthur Rogati Mendes - RA 3025102644
Fábio Dos Santos Souza - RA 3025103958
Felipe de Oliveira Fernandes da Silva - RA 3025103441
Gabriel Cardoso Cruz - RA 3025101870
Lucas de Araújo Silva - RA 3025103716
Ygor Caragilescov de Barros - RA 3025103546
    
#include <stdio.h>
#include <string.h>

#define MAX 100

// Estruturas de Cliente e Servico
struct Cliente {
    int id;
    char nome[50];
};

struct Servico {
    int id;
    char nome[50];
    float preco;
};

// Funcao para cadastrar cliente
void cadastrarCliente(struct Cliente clientes[], int *total) {
    printf("\nNome do cliente: ");
    scanf(" %[^\n]", clientes[*total].nome);

    clientes[*total].id = *total + 1;
    (*total)++;

    printf("Cliente cadastrado com sucesso!\n");
}

// Funcao para listar clientes
void listarClientes(struct Cliente clientes[], int total) {
    printf("\n--- Lista de Clientes ---\n");
    for(int i = 0; i < total; i++) {
        printf("ID: %d | Nome: %s\n", clientes[i].id, clientes[i].nome);
    }
}

// Funcao para cadastrar servico
void cadastrarServico(struct Servico servicos[], int *total) {
    printf("\nNome do servico: ");
    scanf(" %[^\n]", servicos[*total].nome);

    printf("Preco: ");
    scanf("%f", &servicos[*total].preco);
    
    int c;
while ((c = getchar()) != '\n' && c != EOF);

    servicos[*total].id = *total + 1;
    (*total)++;

    printf("Servico cadastrado!\n");
}

// Funcao para listar servico
void listarServicos(struct Servico servicos[], int total) {
    printf("\n--- Lista de Servicos ---\n");
    for(int i = 0; i < total; i++) {
        printf("ID: %d | Nome: %s | Preco: %.2f\n",
               servicos[i].id,
               servicos[i].nome,
               servicos[i].preco);
    }
}

// Funcao para registrar venda
void registrarVenda(struct Cliente clientes[], int totalClientes,
                    struct Servico servicos[], int totalServicos) {

    int idCliente, idServico;

    printf("\nDigite o ID do cliente: ");
    scanf("%d", &idCliente);

    printf("Digite o ID do servico: ");
    scanf("%d", &idServico);
    
    int c;
while ((c = getchar()) != '\n' && c != EOF);

    if(idCliente > 0 && idCliente <= totalClientes && idServico > 0 && idServico <= totalServicos) {
        printf("\nVenda registrada!\n");
        printf("Cliente: %s\n", clientes[idCliente - 1].nome);
        printf("Servico: %s\n", servicos[idServico - 1].nome);
        printf("Valor: %.2f\n", servicos[idServico - 1].preco);
    } else {
        printf("Erro: Cliente ou servico invalido!\n");
    }
}

// Programa principal
int main() {

    struct Cliente clientes[MAX];
    struct Servico servicos[MAX];

    int totalClientes = 0;
    int totalServicos = 0;

    int opcao;

    do {
        printf("\n=== SISTEMA UNITECH ===\n");
        printf("1 - Cadastrar Cliente\n");
        printf("2 - Listar Clientes\n");
        printf("3 - Cadastrar Servico\n");
        printf("4 - Listar Servicos\n");
        printf("5 - Registrar Venda\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        
        int c;
while ((c = getchar()) != '\n' && c != EOF);

        switch(opcao) {
            case 1:
                cadastrarCliente(clientes, &totalClientes);
                break;

            case 2:
                listarClientes(clientes, totalClientes);
                break;

            case 3:
                cadastrarServico(servicos, &totalServicos);
                break;

            case 4:
                listarServicos(servicos, totalServicos);
                break;

            case 5:
                registrarVenda(clientes, totalClientes, servicos, totalServicos);
                break;

            case 0:
                printf("Encerrando sistema...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while(opcao != 0);

    return 0;
}