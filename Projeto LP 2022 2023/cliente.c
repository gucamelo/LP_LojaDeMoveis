/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file_header.c to edit this template
 */



#include "cliente.h"
#include "encomenda.h"
#include "input.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

int procurarCliente(Clientes clientes, int id) {
    int i;

    for (i = 0; i < clientes.total; i++) {
        if (clientes.clientes[i].id == id) {
            return i;
        }
    }
    return -1;
}

void adicionarCliente(Clientes *clientes) {

    listarClientes(*clientes);

    printf("Crirar Cliente:\n");
    int id = obterInt("Insira o Id do cliente que pertende criar: ");

    if (procurarCliente(*clientes, id) == -1) {

        if ((*clientes).total == (*clientes).maxClientes) {
            (*clientes).maxClientes += 3;
            (*clientes).clientes = (Cliente*) realloc((*clientes).clientes, ((*clientes).maxClientes) * sizeof (Cliente));
        }



        (*clientes).clientes[(*clientes).total].id = id;
        (*clientes).clientes[(*clientes).total].estado = 1;

        char buffer[SIZE_BUFFER];

        lerString(buffer, SIZE_BUFFER, "Nome: ");
        (*clientes).clientes[(*clientes).total].nome = malloc((strlen(buffer) + 1) * sizeof (char));
        strcpy((*clientes).clientes[(*clientes).total].nome, buffer);

        lerString(buffer, SIZE_BUFFER, "Nif: ");
        (*clientes).clientes[(*clientes).total].nif = malloc((strlen(buffer) + 1) * sizeof (char));
        strcpy((*clientes).clientes[(*clientes).total].nif, buffer);

        lerString(buffer, SIZE_BUFFER, "Morada: ");
        (*clientes).clientes[(*clientes).total].morada = malloc((strlen(buffer) + 1) * sizeof (char));
        strcpy((*clientes).clientes[(*clientes).total].morada, buffer);

        lerString(buffer, SIZE_BUFFER, "Telefone: ");
        (*clientes).clientes[(*clientes).total].telefone = malloc((strlen(buffer) + 1) * sizeof (char));
        strcpy((*clientes).clientes[(*clientes).total].telefone, buffer);

        lerString(buffer, SIZE_BUFFER, "Email: ");
        (*clientes).clientes[(*clientes).total].email = malloc((strlen(buffer) + 1) * sizeof (char));
        strcpy((*clientes).clientes[(*clientes).total].email, buffer);

        lerString(buffer, SIZE_BUFFER, "Pais: ");
        (*clientes).clientes[(*clientes).total].pais = malloc((strlen(buffer) + 1) * sizeof (char));
        strcpy((*clientes).clientes[(*clientes).total].pais, buffer);

        (*clientes).total++;
    } else {
        printf("O cliente já existe!!");
    }
}

void libertarMemcliente(Clientes *clientes) {
    int i;

    if (clientes->total > 0) {

        for (i = 0; i < clientes->total; i++) {

            free(clientes->clientes[i].nome);
            free(clientes->clientes[i].nif);
            free(clientes->clientes[i].morada);
            free(clientes->clientes[i].telefone);
            free(clientes->clientes[i].email);
            free(clientes->clientes[i].pais);

        }
        free(clientes->clientes);

    } else {
        printf("Não existem clientes criados!!\n");
    }
}

void imprimirCliente(Cliente cliente) {
    printf("\nId:%d\nNome:%s\nNif:%s\nMorada:%s\nTelefone:%s\nEmai:%s\nPaís:%s\n", cliente.id, cliente.nome,
            cliente.nif, cliente.morada,
            cliente.telefone, cliente.email,
            cliente.pais);
    if (cliente.estado == 1) {
        printf("Estado: ativo\n");
    } else if (cliente.estado == 0) {
        printf("Estado: desativo\n");
    }
}

void listarClientes(Clientes clientes) {
    int i;

    if (clientes.total > 0) {
        for (i = 0; i < clientes.total; i++) {
            imprimirCliente(clientes.clientes[i]);
        }
    } else {
        printf("Não existem clientes criados!!\n");
    }
}

void atualizarDadosCliente(Cliente *cliente) {
    int escolha;
    char buffer[SIZE_BUFFER];

    do {
        printf("1- Nome\n");
        printf("2- Nif\n");
        printf("3- Morada\n");
        printf("4- Telefone\n");
        printf("5- Email\n");
        printf("6- Pais\n");
        printf("0- Voltar\n");
        escolha = obterInt("\nEscolha uma opção!\n");
        switch (escolha) {
            case 0:
                fflush(stdin);
                system("clear");
                break;
            case 1:
                lerString(buffer, SIZE_BUFFER, "Nome: ");
                cliente->nome = realloc(cliente->nome, (strlen(buffer) + 1) * sizeof (char));
                strcpy(cliente->nome, buffer);
                break;
            case 2:
                lerString(buffer, SIZE_BUFFER, "Nif: ");
                cliente->nif = realloc(cliente->nif, (strlen(buffer) + 1) * sizeof (char));
                strcpy(cliente->nif, buffer);
                break;

            case 3:
                lerString(buffer, SIZE_BUFFER, "Morada: ");
                cliente->morada = realloc(cliente->morada, (strlen(buffer) + 1) * sizeof (char));
                strcpy(cliente->morada, buffer);
                break;

            case 4:
                lerString(buffer, SIZE_BUFFER, "Telefone: ");
                cliente->telefone = realloc(cliente->telefone, (strlen(buffer) + 1) * sizeof (char));
                strcpy(cliente->telefone, buffer);
                break;

            case 5:
                lerString(buffer, SIZE_BUFFER, "Email: ");
                cliente->email = realloc(cliente->email, (strlen(buffer) + 1) * sizeof (char));
                strcpy(cliente->email, buffer);
                break;

            case 6:
                lerString(buffer, SIZE_BUFFER, "Pais: ");
                cliente->pais = realloc(cliente->pais, (strlen(buffer) + 1) * sizeof (char));
                strcpy(cliente->pais, buffer);
                break;
            default:
                printf("Opção inválida\n");
                printf("Prima ENTER para voltar ao menu\n");
                fflush(stdin);
                system("clear");
                break;
        }
    } while (escolha != 0);

}

void editarCliente(Clientes * clientes) {
    listarClientes(*clientes);

    printf("Editar dados do cliente:\n");
    int id = procurarCliente(*clientes, obterInt("Insira o Id do cliente que pertende alterar: "));

    if (id != -1) {
        atualizarDadosCliente(&(*clientes).clientes[id]);

    } else {
        printf("Cliente não existe!!\n");
    }
}

void eliminarCliente(Clientes *clientes, Encomendas encomenda) {
    int i, k;
    listarClientes(*clientes);

    printf("Eliminar Cliente:\n");
    int id = procurarCliente(*clientes, obterInt("Insira o Id que pertende eliminar: "));


    if (id != -1) {

        if (encomenda.totalEncomendas > 0) {
            for (i = 0; i < encomenda.totalEncomendas; i++) {
                if (clientes->clientes[id].id == encomenda.encomendas[i].idCliente) {
                    clientes->clientes[id].estado = 0;
                    return;
                }
            }
        }
        
        strcpy(clientes->clientes[id].nome, clientes->clientes[clientes->total - 1].nome);
        strcpy(clientes->clientes[id].email, clientes->clientes[clientes->total - 1].email);
        strcpy(clientes->clientes[id].morada, clientes->clientes[clientes->total - 1].morada);
        strcpy(clientes->clientes[id].telefone, clientes->clientes[clientes->total - 1].telefone);
        strcpy(clientes->clientes[id].pais, clientes->clientes[clientes->total - 1].pais);
        strcpy(clientes->clientes[id].nif, clientes->clientes[clientes->total - 1].nif);
        clientes->clientes[id].id = clientes->clientes[clientes->total - 1].id;
        clientes->clientes[id].estado = clientes->clientes[clientes->total - 1].estado;
        
            free(clientes->clientes[clientes->total - 1].nome);
            free(clientes->clientes[clientes->total - 1].nif);
            free(clientes->clientes[clientes->total - 1].morada);
            free(clientes->clientes[clientes->total - 1].telefone);
            free(clientes->clientes[clientes->total - 1].email);
            free(clientes->clientes[clientes->total - 1].pais);

        clientes->total--;

    } else {
        printf("Cliente não existe!!\n");
    }
}


//Não esta a escrever no ficheiro

void writeClientes(Clientes clientes) {
    FILE *fp;
    int i;
    fp = fopen("Lista_Clientes.csv", "w");
    if (fp == NULL) {
        printf("Erro ao abrir o ficheiro!!\n");
        return;
    }
    fprintf(fp, "id;nome;nif;morada;telefone;email;pais;estado");
    for (i = 0; i < clientes.total; i++) {
        fprintf(fp, "\n%d;%s;%s;%s;%s;%s;%s;%d"
                , clientes.clientes[i].id
                , clientes.clientes[i].nome
                , clientes.clientes[i].nif
                , clientes.clientes[i].morada
                , clientes.clientes[i].telefone
                , clientes.clientes[i].email
                , clientes.clientes[i].pais
                , clientes.clientes[i].estado);

    }
    fclose(fp);
}

 
void readClientes(Clientes * clientes) {
    FILE *fp;
    char **dados;
    fp = fopen("Lista_Clientes.csv", "r");

    if (fp == NULL) {
        puts("Erro ao abrir o ficheiro");
        return;
    }
    int i = 0;


    char buffer[1024];
    dados = (char**) malloc(sizeof (char*) * 8);

    while (fgets(buffer, 1024, fp)) {


        dados[0] = NULL;
        dados[1] = NULL;
        dados[2] = NULL;
        dados[3] = NULL;
        dados[4] = NULL;
        dados[5] = NULL;
        dados[6] = NULL;
        dados[7] = NULL;

        char *column = strtok(buffer, ";");
        int k = 0;

        while (column) {
            dados[k++] = column;
            column = strtok(NULL, ";");
        }
        if (i != 0) {

            if (dados[7] != NULL) {

                //Perigo!!!!!!!!
                if ((*clientes).total == (*clientes).maxClientes) {
                    (*clientes).maxClientes += 3;
                    (*clientes).clientes = (Cliente*) realloc((*clientes).clientes, ((*clientes).maxClientes) * sizeof (Cliente));
                }

                (*clientes).clientes[(*clientes).total].id = atoi(dados[0]);
                (*clientes).clientes[(*clientes).total].nome = malloc((strlen(dados[1]) + 1) * sizeof (char));
                strcpy((*clientes).clientes[(*clientes).total].nome, dados[1]);
                (*clientes).clientes[(*clientes).total].nif = malloc((strlen(dados[2]) + 1) * sizeof (char));
                strcpy((*clientes).clientes[(*clientes).total].nif, dados[2]);
                (*clientes).clientes[(*clientes).total].morada = malloc((strlen(dados[3]) + 1) * sizeof (char));
                strcpy((*clientes).clientes[(*clientes).total].morada, dados[3]);
                (*clientes).clientes[(*clientes).total].telefone = malloc((strlen(dados[4]) + 1) * sizeof (char));
                strcpy((*clientes).clientes[(*clientes).total].telefone, dados[4]);
                (*clientes).clientes[(*clientes).total].email = malloc((strlen(dados[5]) + 1) * sizeof (char));
                strcpy((*clientes).clientes[(*clientes).total].email, dados[5]);
                (*clientes).clientes[(*clientes).total].pais = malloc((strlen(dados[6]) + 1) * sizeof (char));
                strcpy((*clientes).clientes[(*clientes).total].pais, dados[6]);
                (*clientes).clientes[(*clientes).total].estado = atoi(dados[7]);
                (*clientes).total++;
            }

        }
        i++;

    }
    free(dados);
    fclose(fp);
}

void clienteMaisGastador(Clientes clientes, Encomendas encomendas){
    int i;
    float totalGasto[clientes.total], maisGasto = 0;
    int maisGastador = 0; 

    for(i = 0; i < clientes.total; i++){
        totalGasto[i] = 0;
    }

    for(i = 0; i < encomendas.totalEncomendas; i++){
         totalGasto[(encomendas.encomendas[i].idCliente) - 1] += encomendas.encomendas[i].totalPagar;
    }

    for(i = 0; i < clientes.total; i++){
        if(totalGasto[i] > maisGasto){
            maisGasto = totalGasto[i];
            maisGastador = i;
        }
    }

    printf("Cliente que mais gastou: %s\n", clientes.clientes[maisGastador].nome);
    printf("Total gasto: %f\n", maisGasto);
    printf("Id: %d\n", clientes.clientes[maisGastador].id);
    printf("Morada: %s\n", clientes.clientes[maisGastador].morada);
    printf("Email: %s\n", clientes.clientes[maisGastador].email);
    printf("Telefone: %s\n", clientes.clientes[maisGastador].telefone);
    printf("Pais: %s\n", clientes.clientes[maisGastador].pais);

}
