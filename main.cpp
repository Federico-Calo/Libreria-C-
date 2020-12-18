#include <stdio.h>
#include <stdlib.h>
#include<string.h>

FILE *paf;
struct libri{
    char nome[50];
    char cognome[50];
    char titolo[150];
    char editrice[50];
};
struct libri elenco[300];
void crearefile();
void aggiornarefile();
void eliminarelibro();
void aggiungerelibro();
void visualizzarefile();
void ordinarefile();
int main()
{
    int scelta;
    do{
        do{
            printf("\n\t\t----------------------------------------------");
            printf("\n\t\t\tInserire scelta \n\n\t\t\t 1- Creare libreria\n\t\t\t 2-Aggiornare libreria\n\t\t\t 3-Eliminare libro\n\t\t\t 4-Aggiungere libro\n\t\t\t 5-Visualizza libreria\n\t\t\t 6-Ordina libreria\n\t\t\t 7-Termina operazione\n\n");
            printf("\t\t----------------------------------------------\n");
            fflush(stdin);
            scanf("%d",&scelta);
        }while(scelta!=1 && scelta!=2 && scelta!=3 && scelta!=4 && scelta!=5 &&scelta!=6 && scelta!=7);

        switch(scelta)
        {
            case 1:
                system("CLS");
                crearefile();
                break;
            case 2:
                system("CLS");
                aggiornarefile();
                break;
            case 3:
                system("CLS");
                eliminarelibro();
                break;
            case 4:
                system("CLS");
                aggiungerelibro();
                break;
            case 5:
                system("CLS");
                visualizzarefile();
                break;
            case 6:
                system("CLS");
                ordinarefile();
                break;
        }
    }while(scelta!=7);
    return 0;
}

void crearefile()
{
    int scelta=1;
    char nome[50], cognome[50], titolo[150], editrice[50];
    paf=fopen("Elenco.txt","w");
    if(paf==NULL)
        printf("\n Impossibile creare il file\n");
    else
    {
        while(scelta==1)
        {
            printf("\n Inserire il titolo del libro\n");
            fflush(stdin);
            scanf("%s",titolo);
            printf("\n Inserire il nome dell'autore\n");
            fflush(stdin);
            scanf("%s",nome);
            printf("\n Inserire il cognome dell'autore\n");
            fflush(stdin);
            scanf("%s",cognome);
            printf("\n Inserire la casa editrice\n");
            fflush(stdin);
            scanf("%s",editrice);
            fprintf(paf,"%s %s %s %s\n",titolo,nome,cognome,editrice);
            do{
                printf("\n Inserire 1 per continuare 2 per terminare l'inserimento\n");
                fflush(stdin);
                scanf("%d",&scelta);
            }while(scelta!=1 && scelta!=2);
        }

    }
    fclose(paf);
}

void aggiornarefile()
{
    int numl=0;
    int i;
    char nome[50],cognome[50],titolo[150],nome1[50],cognome1[50],titolo1[150],editrice[50],editrice1[50];
    paf=fopen("Elenco.txt","r");
    if(paf==NULL)
        printf("\n impossibile aprire il file\n");
    else
    {
        while(fscanf(paf,"%s %s %s %s",elenco[numl].titolo,elenco[numl].nome,elenco[numl].cognome,elenco[numl].editrice)!=EOF)
            numl++;
        printf("\n inserire il nuovo nome dell'autore \n");
        fflush(stdin);
        scanf("%s",nome);
        printf("\n inserire il nuovo cognome dell'autore\n");
        fflush(stdin);
        scanf("%s",cognome);
        printf("\n inserire il nuovo titolo del libro\n");
        fflush(stdin);
        scanf("%s",titolo);
        printf("\n inserire la nuova casa editrice del libro\n");
        fflush(stdin);
        scanf("%s",editrice);
        printf("\n inserire il nome dell'autore che bisogna sostituire\n");
        fflush(stdin);
        scanf("%s",nome1);
        printf("\n inserire il  cognome dell'autore che bisogna sostituire\n");
        fflush(stdin);
        scanf("%s",cognome1);
        printf("\n inserire il  titolo del libro che bisogna sostituire\n");
        fflush(stdin);
        scanf("%s",titolo1);
        printf("\n inserire la casa editrice del libro\n");
        fflush(stdin);
        scanf("%s",editrice1);
        int trovato=0;
        i=0;
        while(i<numl && trovato==0)
        {
            if(strcmp(nome1,elenco[i].nome)==0 && strcmp(cognome1,elenco[i].cognome)==0 && strcmp(titolo1,elenco[i].titolo)==0 && strcmp(editrice1,elenco[i].editrice)==0)
            {
                strcpy(elenco[i].nome,nome);
                strcpy(elenco[i].cognome,cognome);
                strcpy(elenco[i].titolo,titolo);
                strcpy(elenco[i].editrice,editrice);
                trovato=1;
            }
            i++;
        }
        if(trovato==0)
            printf("\n Autore o libro non presente nell'elenco o errore di battitura\n");
        fclose(paf);
        paf=fopen("Elenco.txt","w");
        i=0;
        while(i<numl)
        {
            fprintf(paf,"%s %s %s %s\n",elenco[i].titolo,elenco[i].nome,elenco[i].cognome,elenco[i].editrice);
            i++;
        }
    }
    fclose(paf);
}

void eliminarelibro()
{
    paf=fopen("Elenco.txt","r");
    char nome[50],cognome[50],titolo[150],editrice[50];
    int i,numl=0,trovato=0;
    while(fscanf(paf,"%s %s %s %s",elenco[numl].titolo,elenco[numl].nome,elenco[numl].cognome,elenco[numl].editrice)!=EOF)
            numl++;
    printf("\n inserire il nome dell'autore che si vuole cancellare \n");
    fflush(stdin);
    scanf("%s",nome);
    printf("\n inserire il cognome dell'autore che si vuole cancellare\n");
    fflush(stdin);
    scanf("%s",cognome);
    printf("\n inserire il titolo del libro che si vuole cancellare\n");
    fflush(stdin);
    scanf("%s",titolo);
     printf("\n inserire la casa editrice del libro che si vuole cancellare\n");
    fflush(stdin);
    scanf("%s",editrice);
    i=0;
    while(i<numl && trovato==0)
    {
        if(strcmp(nome,elenco[i].nome)==0 && strcmp(cognome,elenco[i].cognome)==0 && strcmp(titolo,elenco[i].titolo)==0 && strcmp(editrice,elenco[i].editrice)==0)
        {
             strcpy(elenco[i].nome,"Deleted");
             strcpy(elenco[i].cognome,"Deleted");
             strcpy(elenco[i].titolo,"Deleted");
             strcpy(elenco[i].editrice,"Deleted");
             trovato=1;
        }
        i++;

    }
    if(trovato==0)
            printf("\n Autore o libro non presente nell'elenco o errore di battitura\n");
    fclose(paf);
    paf=fopen("Elenco.txt","w");
    i=0;
    while(i<numl)
    {
        fprintf(paf,"%s %s %s %s\n",elenco[i].titolo,elenco[i].nome,elenco[i].cognome,elenco[i].editrice);
        i++;
    }
    fclose(paf);
}

void aggiungerelibro()
{
    char nome[50],cognome[50],titolo[150], editrice[50];
    int scelta=1;
    paf=fopen("Elenco.txt","a");
    if(paf==NULL)
        printf("\n Il file non può essere aperto\n");
    else
    {
        while(scelta==1)
        {
            printf("\n Inserire il titolo che si vuole aggiungere alla lista\n");
            fflush(stdin);
            scanf("%s",titolo);
            printf("\n Inserire il nome dell'autore\n");
            fflush(stdin);
            scanf("%s",nome);
            printf("\n Inserire il cognome dell'autore\n");
            fflush(stdin);
            scanf("%s",cognome);
            printf("\n Inserire la casa editrice del libro\n");
            fflush(stdin);
            scanf("%s",editrice);
            fprintf(paf,"%s %s %s %s\n",titolo,nome,cognome,editrice);
            do{
                printf("\n Inserire 1 per continjare 2 per terminare l'inserimento\n");
                fflush(stdin);
                scanf("%d",&scelta);
            }while(scelta!=1 && scelta!=2);
        }
    }
    fclose(paf);
}

void visualizzarefile()
{
    char nome[50],cognome[50],titolo[150],editrice[50];
    paf=fopen("Elenco.txt","r");
    if(paf==NULL)
        printf("\n Impossibile aprire file\n");
    else
    {
        while(!feof(paf))
        {
            fscanf(paf,"%s %s %s %s", titolo,nome,cognome,editrice);
            if(!feof(paf))
                printf("\n %s %s %s %s\n",titolo, nome,cognome,editrice);
        }
    }
    fclose(paf);
}

void ordinarefile()
{
    paf=fopen("Elenco.txt","r");
    int numl=0,i,j;
    while(fscanf(paf,"%s %s %s %s",elenco[numl].titolo,elenco[numl].nome,elenco[numl].cognome,elenco[numl].editrice)!=EOF)
            numl++;
    char x[150];
    i=0;
    while(i<numl-1)
    {
        j=i+1;
        while(j<numl)
        {
            if(strcmp(elenco[i].titolo,elenco[j].titolo)>0)
            {
                strcpy(x,elenco[i].titolo);
                strcpy(elenco[i].titolo,elenco[j].titolo);
                strcpy(elenco[j].titolo,x);
                strcpy(x,elenco[i].nome);
                strcpy(elenco[i].nome,elenco[j].nome);
                strcpy(elenco[j].nome,x);
                strcpy(x,elenco[i].cognome);
                strcpy(elenco[i].cognome,elenco[j].cognome);
                strcpy(elenco[j].cognome,x);
                strcpy(x,elenco[i].editrice);
                strcpy(elenco[i].editrice,elenco[j].editrice);
                strcpy(elenco[j].editrice,x);
            }
            j++;
        }
        i++;
    }
    fclose(paf);
    paf=fopen("Elenco.txt","w");
    if(paf==NULL)
        printf("\n Impossibile aprire file\n");
    else
    {
         i=0;
        while(i<numl)
        {
            fprintf(paf,"%s %s %s %s\n",elenco[i].titolo,elenco[i].nome,elenco[i].cognome,elenco[i].editrice);
            i++;
        }
        fclose(paf);
    }
}
