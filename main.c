#include <stdio.h>
#include <stdlib.h>
#include "client.h"

void defaultMenu();
void clearScreen();

int main(int argc, char *argv[]){
    
    defaultMenu();  
    
    return 0;
}

void clearScreen(){
    if (system( "cls" )) system( "clear" );
    if (system( "clear" )) system( "cls" );
}
void defaultMenu(){
    int defaultSelection;
    int exit = 0;
    clearScreen();
    printf("---- Bienvenue -----\n\n");
    
    printf("Que voulez-vous faire ?\n");
    printf("-- 0 : Quitter\n");
    printf("-- 1 : Clients\n");
    printf("-- 2 : Comptes\n");
    printf("-- 3 : Opérations\n");
    printf("-- 4 : Historique\n");
    printf("-- 5 : Administration\n");
    printf("\n\n");
    printf("Selectionnez un chiffre parmis les propositions : ");
    scanf("%d", &defaultSelection);
    printf("\n");
    
    while(exit == 0){
        switch(defaultSelection){
            case 1:
                //printf("selected 1\n");
                system ("clear");
                clientMenu();
                exit = 1;
                break;
            case 2:
                printf("selected 2\n");
                exit = 1;
                break;
            case 3:
                printf("selected 3\n");
                exit = 1;
                break;
            case 4:
                printf("selected 4\n");
                exit = 1;
                break;
            case 5:
                printf("selected 5\n");
                exit = 1;
                break;
            case 0:
                exit = 1;
                clearScreen();
                break;
            default:
                printf("Selectionnez un chiffre parmis les propositions : ");
                scanf("%d", &defaultSelection);
                printf("\n");
                break;
        }
    }

}