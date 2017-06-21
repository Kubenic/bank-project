#include <stdio.h>
#include <stdlib.h>

void clientMenu(){
    int clientExit = 0;
    int clientDefaultSelection;
    clearScreen();
    printf(" ---- Menu Clients ----\n\n");
    
    printf("Que voulez-vous faire ?\n");
    printf("-- 0 : Retounez en arrière\n");
    printf("-- 1 : Ajouter un client\n");
    printf("-- 2 : Modifier un client\n");
    printf("-- 3 : Supprimer un client\n");
    printf("-- 4 : Rechercher un client\n");

    printf("\n\n");
    printf("Selectionnez un chiffre parmis les propositions : ");
    scanf("%d", &clientDefaultSelection);
    printf("\n");
    
    while(clientExit == 0){
        switch(clientDefaultSelection){
            case 1:
                printf("selected Client 1\n");
                clientExit = 1;
                break;
            case 2:
                printf("selected Client 2\n");
                clientExit = 1;
                break;
            case 3:
                printf("selected Client 3\n");
                clientExit = 1;
                break;
            case 4:
                printf("selected Client 4\n");
                clientExit = 1;
                break;
            case 0:
                defaultMenu();
                clientExit = 1;
                break;
            default:
                printf("Selectionnez un chiffre parmis les propositions : ");
                scanf("%d", &clientDefaultSelection);
                printf("\n");
                break;
        }
    }
}