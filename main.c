#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"
#include "vars.h"

int main()
{
    init();
    int c;
    char str[1024];
    struct clients *clientlist = malloc(sizeof(struct clients));
    clientlist->numclients = 0;
    loaddata(clientlist,sizeof(*clientlist));
    printf("Bem vindo(a) ao QuemPoupaTem!\n\n");
    while (1)
    {
        printf("Selecione:\n1. Novo cliente\n2. Apaga cliente\n3. Listar clientes\n4. Débito\n5. Depósito\n6. Extrato\n7. Transferência Entre Contas\n0. Sair");
        while (1)
        {
            c = intinput("\n-> ");
            if (c >= 0 && c <= 7)
            {
                break;
            }
            printf("\nSelecione uma opção válida.\n");
        }
        switch (c)
        {
        case 1:
            newclient(str, clientlist->clients,clientlist->numclients);
            clientlist->numclients++;
            break;
        case 2:
            deleteclient(str,clientlist->numclients,clientlist->clients);
            clientlist->numclients--;
            break;
        case 3:
            listclients(clientlist->numclients, clientlist->clients);
            break;
        case 4:
            debito(str,clientlist->clients,clientlist->numclients);
            break;
        case 5:
            deposito(str,clientlist->clients,clientlist->numclients);
            break;
        case 6:
            showextr(str,clientlist->clients,clientlist->numclients);
            break;
        case 7:
            transfer(str,clientlist->clients,clientlist->numclients);
            break;
        case 0:
            printf("Até Logo!\n");
            savedata(clientlist,sizeof(*clientlist));
            free(clientlist);
            return 0;
        default:
            break;
        }
        savedata(clientlist,sizeof(*clientlist));
    }
    // Não é pro código vir pra esse return
    return 1;
}
