#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "client.h"

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
                //printf("selected Client 1\n");
                newClient();
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

void newClient(){
    char nom[150];
    int nomSet = 0;
    char prenom[150];
    int prenomSet = 0;
    char job[150];
    int jobSet = 0;
    char cellphone[150];
    int cellphoneSet = 0;
    
    clearScreen();
    printf("------ Nouveau Client ------\n\n");
    
    while(nomSet == 0){
        printf("Insérez le nom : ");
        scanf("%s", nom);
        
        if(nom != ""){
            nomSet = 1;
        }
        printf("\n");
    }
    
    while(prenomSet == 0){
        printf("Insérez le prenom : ");
        scanf("%s", prenom);
        
        if(prenom != ""){
            prenomSet = 1;
        }
        printf("\n");
    }
    
     while(jobSet == 0){
        printf("Insérez la profession : ");
        scanf("%s", job);
        
        if(job != ""){
            jobSet = 1;
        }
        printf("\n");
    }
    
     while(cellphoneSet == 0){
        printf("Insérez le numéro de téléphone : ");
        scanf("%s", cellphone);
        
        printf("Size of Cellphone = %zu\n", strlen(cellphone));
        if(strlen(cellphone) != 10){
            printf("Le telephone n'a pas 10 chiffres \n");
        }
        if(strlen(cellphone) == 10){
            cellphoneSet = 1;
        }
        printf("\n");
    }
    printf("\n");
    printf("Nom : %s \n", nom);
    printf("Prenom : %s \n", prenom);
    printf("Profession : %s \n", job);
    printf("Telephone: %s \n", cellphone);
    
    FILE *clientfile = readClientFile();
    int numberOfline = getTotalLineNumbers(clientfile);
    printf("Number of Lines : %d", numberOfline);
    int strsize = strlen(nom) + strlen(prenom) + strlen(job) + strlen(cellphone) + 5;
    char str[strsize];
    
    char buff[12];

    sprintf(buff, "%d", numberOfline);
    
    //printf("buff == %s",buff);
    strcat(str, buff);
    //free(buff);
    
    strcat(str, ",");
    strcat(str, nom);
    strcat(str, ",");
    strcat(str, prenom);
    strcat(str, ",");
    strcat(str, job);
    strcat(str, ",");
    strcat(str, cellphone);
    strcat(str, "\n");
    
    printf("\n str = %s",str);
    fwrite(str , 1 , sizeof(str) , clientfile );
}


FILE * readClientFile(){
        char ch;
        FILE *clientfile;
        clientfile = fopen("db/clients.csv", "r+");
        
        while( ( ch = fgetc(clientfile) ) != EOF )
        printf("%c",ch);
        return clientfile;
}

int getTotalLineNumbers(FILE *file){
    int lines = 0;
    char ch;
    while(!feof(file))
    {
      ch = fgetc(file);
      if(ch == '\n')
      {
        lines++;
      }
    }
    return lines;
}