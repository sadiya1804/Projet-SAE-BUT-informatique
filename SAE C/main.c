
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


typedef struct Client Client;
struct Client
{
    char prenom[20];
    char nom[20];
    char ville[20];
    char code_postal[20];
    char num_tel[20];
    char email[30];
    char profession[20];
};



void Ajout_client();
void affiche_clients(char nom_fichier[20]);
void supprimer_clients(char prenom[20],char nom[20]);
Client recup_donnees(char ligne[100]);
void ajout_caractere(char chaine[100],char caractere);
void modifier_clients(char prenom[20],char nom[30]);
void menu_affiche();
void tri(char type[30]);
char* lower(char* chaineAConvertir);
int taille_annuaire(char nom_fichier[30]);
void QuickSort(Client tab[6000],int debut,int fin,char type[20]);
void affiche_manquant(char nom_fichier[30]);
void filtre();





int main() // referend
{
    printf("ANNUAIRE NUMERIQUE\n\n");
    int mainExit=0,exit=0,i=0;
    char commande[3],nom[20],prenom[20],cara;
    printf("MENU PRINCIPAL\n");
    while(mainExit==0)
    {
        printf("\nQue voulez vous faire ?\n");
        scanf("%199s",commande);
        if(strcmp(commande,"exit")==0)
        {
            mainExit=1;
        }
        else if(strcmp(commande,"Ajout")==0)
        {
            Ajout_client();
        }
      /*  else if(strcmp(commande,"help")==0)
        {
            help();
        } */
        else if(strcmp(commande,"affiche")==0)
        {
            printf("\nMENU AFFICHER\n");
            while(exit==0)
            {
                printf("\nQue voulez vous faire ? \n");
                scanf("%199s",commande);
                if(strcmp(commande,"help")==0)
                {
                    menu_affiche();
                }
                else if(strcmp(commande,"retour")==0)
                {
                    exit=1;
                }
                else if(strcmp(commande,"normal")==0)
                {
                    system("cls");
                    affiche_clients("fichier.csv");
                }
                else if(strcmp(commande,"nom")==0)
                {
                    system("cls");
                    tri("nom");
                    affiche_clients("fichier.csv");
                }
                else if(strcmp(commande,"prenom")==0)
                {
                    system("cls");
                    tri("prenom");
                    affiche_clients("fichier.csv");
                }
                else if(strcmp(commande,"codepostal")==0)
                {
                    system("cls");
                    tri("codepostal");
                    affiche_clients("fichier.csv");
                }
                else if(strcmp(commande,"profession")==0)
                {
                    system("cls");
                    tri("profession");
                    affiche_clients("fichier.csv");
                }
                else if(strcmp(commande,"donneesManquantes")==0)
                {
                    system("cls");
                    affiche_manquant("fichier.csv");
                }
            }
            exit=0;
        }
        else if(strcmp(commande,"supprimer")==0)
        {
            printf("Donnez le prenom du client a supprimer\n");
            fgets(prenom,sizeof(prenom),stdin);
            fgets(prenom,sizeof(prenom),stdin);
            i=0;
            cara=prenom[0];
            while(cara!='\n')
            {
                i++;
                cara=prenom[i];
            }
            prenom[i]='\0';
            printf("Donnez le nom du client a supprimer\n");
            fgets(nom,sizeof(nom),stdin);
            i=0;
            cara=nom[0];
            while(cara!='\n')
            {
                i++;
                cara=nom[i];
            }
            nom[i]='\0';
            supprimer_clients(prenom,nom);
        }
        else if(strcmp(commande,"modifier")==0)
        {
            printf("Donnez le prenom du client a modifier\n");
            fgets(prenom,sizeof(prenom),stdin);
            fgets(prenom,sizeof(prenom),stdin);
            i=0;
            cara=prenom[0];
            while(cara!='\n')
            {
                i++;
                cara=prenom[i];
            }
            prenom[i]='\0';
            printf("Donnez le nom du client a modifier\n");
            fgets(nom,sizeof(nom),stdin);
            i=0;
            cara=nom[0];
            while(cara!='\n')
            {
                i++;
                cara=nom[i];
            }
            nom[i]='\0';
            modifier_clients(prenom,nom);
        }
        else if(strcmp(commande,"recherche")==0)
        {
            filtre();
        }
    }


    return 0;
}

/**
*\fn void add_client()
*\brief programme qui permet d'ajouter un client
*/

void Ajout_client() // referend Mohamed AIT EL HADJ
{
    char confirmer[5],cara;
    Client client;
    int exit=0,i=0;
    FILE* fichier = NULL;
    fichier = fopen("fichier.csv","a");

    if(fichier!=NULL)
    {
        while(exit==0)
        {
            printf("Entrez son prenom :\n");
            fgets(client.prenom,sizeof(client.prenom),stdin);
            fgets(client.prenom,sizeof(client.prenom),stdin);
            cara=client.prenom[0];
            while(cara!='\n')
            {
                i++;
                cara=client.prenom[i];
            }
            client.prenom[i]='\0';
            printf("Entrez son nom :\n");
            fgets(client.nom,sizeof(client.nom),stdin);
            i=0;
            cara=client.nom[0];
            while(cara!='\n')
            {
                i++;
                cara=client.nom[i];
            }
            client.nom[i]='\0';
            printf("Entrez sa ville :\n");
            fgets(client.ville,sizeof(client.ville),stdin);
            i=0;
            cara=client.ville[0];
            while(cara!='\n')
            {
                i++;
                cara=client.ville[i];
            }
            client.ville[i]='\0';
            printf("Entrez son code postal :\n");
            fgets(client.code_postal,sizeof(client.code_postal),stdin);
            i=0;
            cara=client.code_postal[0];
            while(cara!='\n')
            {
                i++;
                cara=client.code_postal[i];
            }
            client.code_postal[i]='\0';
            printf("entrez son numero de telephone :\n");
            fgets(client.num_tel,sizeof(client.num_tel),stdin);
            i=0;
            cara=client.num_tel[0];
            while(cara!='\n')
            {
                i++;
                cara=client.num_tel[i];
            }
            client.num_tel[i]='\0';
            printf("Entrez son email :\n");
            fgets(client.email,sizeof(client.email),stdin);
            i=0;
            cara=client.email[0];
            while(cara!='\n')
            {
                i++;
                cara=client.email[i];
            }
            client.email[i]='\0';
            printf("Notez son metier :\n");
            fgets(client.profession,sizeof(client.profession),stdin);
            i=0;
            cara=client.profession[0];
            while(cara!='\n')
            {
                i++;
                cara=client.profession[i];
            }
            client.profession[i]='\0';
            printf("\nNouveau client:\nPrenom: %s\nNom: %s\nVille: %s\nCode Postal: %s\nNumero de telephone: %s\nEmail: %s\nprofession: %s\n",client.prenom,client.nom,client.ville,client.code_postal,client.num_tel,client.email,client.profession);
            printf("\nVoulez vous confirmez (O/N)\n");
            scanf("%4s",confirmer);
            if(strcmp(confirmer,"O")==0)
            {
                fprintf(fichier,"%s,%s,%s,%s,%s,%s,%s\n",client.prenom,client.nom,client.ville,client.code_postal,client.num_tel,client.email,client.profession);
                exit=1;
                printf("Client ajoute avec succes\n");
            }
        }
        fclose(fichier);
    }
    else
    {
        printf("Impossible d'ouvrir le fichier\n");
    }



}

/**
*\fn void affiche_clients(char nom_fichier[TAILLE_PETIT])
*\brief programme qui affiche tous les clients d'un annuaire
*\param nom_fichier est une chaine de caractere
*/

void affiche_clients(char nom_fichier[30]) // referend
{
    float temps;
    clock_t t1,t2;
    t1=clock();
    Client client;
    FILE* fichier = NULL;
    char ligne[100];
    fichier = fopen(nom_fichier,"r");
    if(fichier != NULL)
    {
        while(fgets(ligne,100,fichier)!=NULL)
        {
            client = recup_donnees(ligne);
            printf("Prenom: %s,Nom: %s,Ville: %s,Code postal: %s,Num: %s,email: %s,metier: %s\n",client.prenom,client.nom,client.ville,client.code_postal,client.num_tel,client.email,client.profession);
        }

        fclose(fichier);
    }
    else
    {
        printf("Impossible d'ouvrir ce fichier");
    }
    t2=clock();
    temps=(float)(t2-t1)/CLOCKS_PER_SEC;
    printf("\n\nTemps: %f\n",temps);
}

/**
*\fn void help()
*\brief programme qui affiche les commandes disponibles
*/


void help() // referend Thomas FERREIRA
{
    printf("\nCommandes disponibles\n");
    printf("---------------------\n");
    printf("add : Ajoute un client dans l'annuaire\n");
    printf("affiche : Affiche les options disponibles pour afficher les clients\n");
    printf("exit : Permet de quitter l'annuaire\n");
    printf("del : Supprime un client de l'annuaire\n");
    printf("modify : Permet de modifier les donnees d'un client\n");
    printf("recherche : Permet de chercher une personne dans l'annuaire\n");
} 

/**
*\fn void del(char prenom[TAILLE_GRAND],char nom[TAILLE_GRAND])
*\brief programme qui supprime un client
*\param prenom et nom sont des chaines de caracteres
*/


void supprimer_clients(char prenom[20],char nom[20]) // referend
{
    float temps;
    clock_t t1,t2;
    t1=clock();
    Client client;
    FILE* fichier_source = NULL;
    fichier_source = fopen("fichier.csv","r");
    FILE* fichier_dest = NULL;
    fichier_dest = fopen("fichier_temp.csv","w");
    char ligne[100];

    if(fichier_dest!=NULL && fichier_source!=NULL)
    {
        while(fgets(ligne,100,fichier_source)!=NULL)
        {
            client = recup_donnees(ligne);
            if(strcmp(lower(client.prenom),lower(prenom))!=0 || strcmp(lower(client.nom),lower(nom))!=0)
            {
                fprintf(fichier_dest,"%s,%s,%s,%s,%s,%s,%s\n",client.prenom,client.nom,client.ville,client.code_postal,client.num_tel,client.email,client.profession);
            }
        }
        fclose(fichier_dest);
        fclose(fichier_source);

        remove("fichier.csv");
        rename("fichier_temp.csv","fichier.csv");
        printf("Client supprimer avec succes\n");
    }
    else
    {
        printf("Impossible d'ouvrir les fichiers\n");
    }
    t2=clock();
    temps=(float)(t2-t1)/CLOCKS_PER_SEC;
    printf("\n\nTemps: %f\n",temps);
}

/**
*\fn Client recup_donnees(char ligne[TAILLE])
*\brief programme qui extrait les données d'un client
*\param ligne est une chaine de caracteres
*\return variable de type Client
*/


Client recup_donnees(char ligne[100]) // referend
{
    Client client_tmp;
    int compteur=0,i=0;
    strcpy(client_tmp.prenom,"");
    strcpy(client_tmp.nom,"");
    strcpy(client_tmp.ville,"");
    strcpy(client_tmp.code_postal,"");
    strcpy(client_tmp.num_tel,"");
    strcpy(client_tmp.email,"");
    strcpy(client_tmp.profession,"");
    char caractere;
    caractere=ligne[0];
    while(caractere!='\n')
    {
        if(caractere==',')
        {
            compteur++;
        }
        else if(compteur==0 && caractere!=',')
        {
            ajout_caractere(client_tmp.prenom,caractere);
        }
        else if(compteur==1 && caractere!=',')
        {
            ajout_caractere(client_tmp.nom,caractere);
        }
        else if(compteur==2 && caractere!=',')
        {
            ajout_caractere(client_tmp.ville,caractere);
        }
        else if(compteur==3 && caractere!=',')
        {
            ajout_caractere(client_tmp.code_postal,caractere);
        }
        else if(compteur==4 && caractere!=',')
        {
            ajout_caractere(client_tmp.num_tel,caractere);
        }
        else if(compteur==5 && caractere!=',')
        {
            ajout_caractere(client_tmp.email,caractere);
        }
        else if(compteur==6 && caractere!=',')
        {
            ajout_caractere(client_tmp.profession,caractere);
        }
        i++;
        caractere=ligne[i];
    }

    return client_tmp;
}

/**
*\fn void add_caractere(char chaine[30],char caractere)
*\brief programme qui permet d'ajouter un caractere a une chaine
*\param chaine est une chaine de caractere et caractere est un char
*/


void ajout_caractere(char chaine[30],char caractere) // referend
{
    int longueur;
    longueur = strlen(chaine);
    chaine[longueur+1]='\0';
    chaine[longueur]=caractere;
}

/**
*\fn void modify(char prenom[20],char nom[20])
*\brief programme qui modifie les données d'un client
*\param prenom et nom sont des chaines de caracteres
*/


void modifier_clients(char prenom[20],char nom[20]) // referend
{
    char confirmer[5],ligne[100],cara;
    int exit=0,i=0;
    Client new_client,client;
    FILE* fichier_source=NULL;
    FILE* fichier_dest=NULL;
    fichier_dest=fopen("fichier_temp.csv","w");
    fichier_source=fopen("fichier.csv","r");

    while(exit==0)
    {
        printf("entrez son nouveau prenom :\n");
        fgets(new_client.prenom,sizeof(new_client.prenom),stdin);
        cara=new_client.prenom[0];
        while(cara!='\n')
        {
            i++;
            cara=new_client.prenom[i];
        }
        new_client.prenom[i]='\0';
        printf("Entrez son nouveau nom :\n");
        fgets(new_client.nom,sizeof(new_client.nom),stdin);
        i=0;
        cara=new_client.nom[0];
        while(cara!='\n')
        {
            i++;
            cara=new_client.nom[i];
        }
        new_client.nom[i]='\0';
        printf("Entrez sa nouveau ville :\n");
        fgets(new_client.ville,sizeof(new_client.ville),stdin);
        i=0;
        cara=new_client.ville[0];
        while(cara!='\n')
        {
            i++;
            cara=new_client.ville[i];
        }
        new_client.ville[i]='\0';
        printf("Entrez son nouveau code postal :\n");
        fgets(new_client.code_postal,sizeof(new_client.code_postal),stdin);
        i=0;
        cara=new_client.code_postal[0];
        while(cara!='\n')
        {
            i++;
            cara=new_client.code_postal[i];
        }
        new_client.code_postal[i]='\0';
        printf("Entrez son nouveau numero de telephone :\n");
        fgets(new_client.num_tel,sizeof(new_client.num_tel),stdin);
        i=0;
        cara=new_client.num_tel[0];
        while(cara!='\n')
        {
            i++;
            cara=new_client.num_tel[i];
        }
        new_client.num_tel[i]='\0';
        printf("Entrez son nouveau email :\n");
        fgets(new_client.email,sizeof(new_client.email),stdin);
        i=0;
        cara=new_client.email[0];
        while(cara!='\n')
        {
            i++;
            cara=new_client.email[i];
        }
        new_client.email[i]='\0';
        printf("Entrez sa nouvelle profession :\n");
        fgets(new_client.profession,sizeof(new_client.profession),stdin);
        i=0;
        cara=new_client.profession[0];
        while(cara!='\n')
        {
            i++;
            cara=new_client.profession[i];
        }
        new_client.profession[i]='\0';
        printf("\nNouveau client:\nPrenom: %s\nNom: %s\nVille: %s\nCode Postal: %s\nNumero de telephone: %s\nEmail: %s\nprofession: %s\n",new_client.prenom,new_client.nom,new_client.ville,new_client.code_postal,new_client.num_tel,new_client.email,
               new_client.profession);
        printf("\nVoulez vous confirmez (O/N)\n");
        scanf("%4s",confirmer);
        if(strcmp(confirmer,"O")==0)
        {
            exit=1;
        }
    }
    if(fichier_dest!=NULL && fichier_source!=NULL)
    {
        while(fgets(ligne,100,fichier_source)!=NULL)
        {
            client = recup_donnees(ligne);
            if(strcmp(lower(prenom),lower(client.prenom))==0 && strcmp(lower(nom),lower(client.nom))==0)
            {
                fprintf(fichier_dest,"%s,%s,%s,%s,%s,%s,%s\n",new_client.prenom,new_client.nom,new_client.ville,new_client.code_postal,new_client.num_tel,new_client.email,new_client.profession);

            }
            else
            {
                fprintf(fichier_dest,"%s,%s,%s,%s,%s,%s,%s\n",client.prenom,client.nom,client.ville,client.code_postal,client.num_tel,client.email,client.profession);
            }

        }

        fclose(fichier_source);
        fclose(fichier_dest);
        remove("fichier.csv");
        rename("fichier_temp.csv","annuaire.csv");
        printf("Client modifie avec succes\n");
    }
    else
    {
        printf("Impossible d'ouvrir le fichier\n");
    }

}

/**
*\fn void menu_affiche()
*\brief programme qui demande comment afficher les clients
*/

void menu_affiche() // referend
{
    printf("\nnormal: Affiche tous les clients normalement sans filtre\n");
    printf("retour: Reviens au menu d'avant\n");
    printf("nom: Affiche tous les clients en triant par rapport au nom\n");
    printf("prenom: Affiche tous les clients en triant par rapport au prenom\n");
    printf("codepostal: Affiche tous les clients en triant par rapport au code postal\n");
    printf("profession: Affiche tous les clients en triant par rapport a leurs profession\n");
    printf("donneesManquantes: affiche toutes les personnes qui ont des donnees manquantes\n");
}

/**
*\fn void tri(char type[TAILLE_PETIT])
*\brief programme qui trie l'annuaire
*\param type est une chaine de caractere
*/

void tri(char type[20]) // referend
{
    float temps;
    clock_t t1,t2;
    t1=clock();
    int i=0,longueur=taille_annuaire("fichier.csv");
    static Client annuaire[6000];
    FILE* fichier=NULL;
    fichier=fopen("fichier.csv","r");
    FILE* fichier_trie=NULL;
    fichier_trie=fopen("fichier_temp.csv","w");
    char ligne[100];

    if(fichier!=NULL && fichier_trie!=NULL)
    {
        while(fgets(ligne,100-1,fichier)!=NULL && i<longueur)
        {
            annuaire[i]=recup_donnees(ligne);
            i++;
        }
        QuickSort(annuaire,0,longueur-1,type);
        printf("En cours de tri ...\n");
        for(i=0;i<longueur;i++)
        {
            fprintf(fichier_trie,"%s,%s,%s,%s,%s,%s,%s\n",annuaire[i].prenom,annuaire[i].nom,annuaire[i].ville,annuaire[i].code_postal,annuaire[i].num_tel,annuaire[i].email,annuaire[i].profession);
        }
        fclose(fichier);
        fclose(fichier_trie);
        remove("fichier.csv");
        rename("fichier_temp.csv","fichier.csv");
    }
    else
    {
        printf("Impossible d'ouvrir le fichier\n");
    }
    t2=clock();
    temps=(float)(t2-t1)/CLOCKS_PER_SEC;
    printf("\n\nTemps: %f\n",temps);

}

/**
*\fn char* lower(char chaineAConvertir[TAILLE])
*\brief programme qui convertit une chaine de caractere en minuscule
*\param chaineAConvertir est une chaine de caracteres
*\return chainelow est une chaine de caractere
*/

char* lower(char* chaineAConvertir) // referend
{
    char* chainelow = malloc(sizeof(char)*strlen(chaineAConvertir)+1);
    int i=0;
    for(i=0;chaineAConvertir[i]!='\0';i++)
    {

        if(chaineAConvertir[i]>='A' && chaineAConvertir[i]<='Z')
        {
            char c=chaineAConvertir[i]+32;
            chainelow[i]=c;
        }
        else if(chaineAConvertir[i]>='a' && chaineAConvertir[i]<='z')
        {
            chainelow[i]=chaineAConvertir[i];
        }
        else if(chaineAConvertir[i]==' ')
        {
            chainelow[i]=' ';
        }
        else if(chaineAConvertir[i]=='-')
        {
            chainelow[i]='-';
        }
    }
    chainelow[i]='\0';
    return chainelow;
}

/**
*\fn int taille_annuaire(char nom_fichier[30])
*\brief programme qui recupère la taille de l'annuaire
*\param nom_fichier est une chaine de caracteres
*\return taille_fichier est un entier
*/

int taille_annuaire(char nom_fichier[30]) // referend
{
    FILE* fichier=NULL;
    fichier=fopen(nom_fichier,"r");
    int taille_fichier=0;
    char ligne[100];

    if(fichier!=NULL)
    {
        while(fgets(ligne,100-1,fichier)!=NULL)
        {
            taille_fichier++;
        }
        fclose(fichier);
    }
    else
    {
        printf("Erreur");
    }
    return taille_fichier;
}

/**
*\fn void rapidSort(Client tab[6000],int debut,int fin,char type[30])
*\brief programme qui trie l'annuaire en utilisant un algorithme de quicksort
*\param tab est un tableau d'éléments de type Client, debut est un entier, fin est un entier et type est une chaine de caracteres
*/

void QuickSort(Client tab[6000],int debut,int fin,char type[30]) // referend
{
    int pivot,i,j;
    Client tmp;
    if(debut<fin)
    {
        pivot=debut;
        i=debut;
        j=fin;
        if(strcmp(type,"nom")==0)
        {
            while(i<j)
            {
                while(strcmp(lower(tab[i].nom),lower(tab[pivot].nom))<=0 && i<fin)
                {
                    i++;
                }
                while(strcmp(lower(tab[j].nom),lower(tab[pivot].nom))>0)
                {
                    j--;
                }
                if(i<j)
                {
                    tmp=tab[i];
                    tab[i]=tab[j];
                    tab[j]=tmp;
                }

            }
            tmp=tab[pivot];
            tab[pivot]=tab[j];
            tab[j]=tmp;
            QuickSort(tab,debut,j-1,type);
            QuickSort(tab,j+1,fin,type);
        }
        else if(strcmp(type,"prenom")==0)
        {
            while(i<j)
            {
                while(strcmp(lower(tab[i].prenom),lower(tab[pivot].prenom))<=0 && i<fin)
                {
                    i++;
                }
                while(strcmp(lower(tab[j].prenom),lower(tab[pivot].prenom))>0)
                {
                    j--;
                }
                if(i<j)
                {
                    tmp=tab[i];
                    tab[i]=tab[j];
                    tab[j]=tmp;
                }

            }
            tmp=tab[pivot];
            tab[pivot]=tab[j];
            tab[j]=tmp;
            QuickSort(tab,debut,j-1,type);
            QuickSort(tab,j+1,fin,type);
        }
        else if(strcmp(type,"codepostal")==0)
        {
            while(i<j)
            {
                while(strcmp(tab[i].code_postal,tab[pivot].code_postal)<=0 && i<fin)
                {
                    i++;
                }
                while(strcmp(tab[j].code_postal,tab[pivot].code_postal)>0)
                {
                    j--;
                }
                if(i<j)
                {
                    tmp=tab[i];
                    tab[i]=tab[j];
                    tab[j]=tmp;
                }

            }
            tmp=tab[pivot];
            tab[pivot]=tab[j];
            tab[j]=tmp;
            QuickSort(tab,debut,j-1,type);
            QuickSort(tab,j+1,fin,type);
        }
        else if(strcmp(type,"profession")==0)
        {
            while(i<j)
            {
                while(strcmp(lower(tab[i].profession),lower(tab[pivot].profession))<=0 && i<fin)
                {
                    i++;
                }
                while(strcmp(lower(tab[j].profession),lower(tab[pivot].profession))>0)
                {
                    j--;
                }
                if(i<j)
                {
                    tmp=tab[i];
                    tab[i]=tab[j];
                    tab[j]=tmp;
                }

            }
            tmp=tab[pivot];
            tab[pivot]=tab[j];
            tab[j]=tmp;
            QuickSort(tab,debut,j-1,type);
            QuickSort(tab,j+1,fin,type);
        }
        else
        {
            printf("Erreur lors du tri\n");
        }
    }
}

/**
*\fn void void affiche_manquant(char nom_fichier[20])
*\brief programme qui affiche tous les clients qui ont des données manquantes
*\param nom_fichier est une chaine de caractère
*/


void affiche_manquant(char nom_fichier[30]) // referend
{
    float temps;
    clock_t t1,t2;
    t1=clock();
    FILE* fichier=NULL;
    fichier=fopen(nom_fichier,"r");
    Client client;
    char ligne[100];

    if(fichier!=NULL)
    {
        while(fgets(ligne,100-1,fichier)!=NULL)
        {
            client=recup_donnees(ligne);
            if(strlen(client.nom)==0 || strlen(client.prenom)==0 || strlen(client.ville)==0 || strlen(client.code_postal)==0 || strlen(client.num_tel)==0 || strlen(client.email)==0 || strlen(client.profession)==0)
            {
                printf("Nom: %s,Prenom: %s,Ville: %s,Code Postal: %s,Numero de telephone: %s,Email: %s,profession: %s\n",client.nom,client.prenom,client.ville,client.code_postal,client.num_tel,client.email,client.profession);
            }
        }
        fclose(fichier);
    }
    else
    {
        printf("Erreur\n");
    }
    t2=clock();
    temps=(float)(t2-t1)/CLOCKS_PER_SEC;
    printf("\n\nTemps: %f\n",temps);
}

/**
*\fn void void filtre()
*\brief programme qui affiche la liste des clients répondant aux critères données
*/

void filtre() // referend
{
    char nom[20],prenom[20],codePostal[20],profession[20],test[5],ligne[100],cara;
    static Client tab[6000],tab2[6000];
    FILE* fichier=NULL;
    int i=0,compteur=0,j=0,exit=0,mainExit=0,y=0;
    fichier=fopen("annuaire.csv","r");
    while(fgets(ligne,100-1,fichier)!=NULL)
    {
        tab[i]=recup_donnees(ligne);
        i++;
    }


    printf("\nMENU RECHERCHE\n");
    while(mainExit==0)
    {

        // Filtre sur le nom

        while(exit==0)
        {
            printf("Connaissez vous le nom de la personne rechercher ? (O/N)\n");
            scanf("%4s",test);
            if(strcmp(test,"O")==0 || strcmp(test,"N")==0)
            {
                exit=1;
            }
        }
        if(strcmp(test,"O")==0)
        {
            printf("Saisissez son nom :\n");
            fgets(nom,sizeof(nom),stdin);
            fgets(nom,sizeof(nom),stdin);
            y=0;
            cara=nom[0];
            while(cara!='\n')
            {
                y++;
                cara=nom[y];
            }
            nom[y]='\0';
            while(j<i)
            {
                if(strcmp(lower(tab[j].nom),lower(nom))==0)
                {
                    tab2[compteur]=tab[j];
                    compteur++;
                }
                j++;
            }
        }
        if(compteur==0)
        {
            if(strcmp(test,"N")!=0)
            {
                printf("Aucun resultat pour cette recherche\n");
                mainExit=1;
                break;
            }
            else if(strcmp(test,"N")==0)
            {
                for(int k=0;k<i;k++)
                {
                    printf("Nom: %s,Prenom: %s,Ville: %s,Code Postal: %s,Numero de telephone: %s,Email: %s,profession: %s\n",tab[k].nom,tab[k].prenom,tab[k].ville,tab[k].code_postal,tab[k].num_tel,tab[k].email,tab[k].profession);
                    compteur++;
                }
            }

        }
        else
        {
            for(int k=0;k<compteur;k++)
            {
                tab[k]=tab2[k];
                printf("Nom: %s,Prenom: %s,Ville: %s,Code Postal: %s,Numero de telephone: %s,Email: %s,profession: %s\n",tab[k].nom,tab[k].prenom,tab[k].ville,tab[k].code_postal,tab[k].num_tel,tab[k].email,tab[k].profession);
            }
            if(compteur==1)
            {
                break;
            }
        }

        // Filtre sur le prenom

        exit=0;
        while(exit==0)
        {
            printf("Connaissez vous le prenom de la personne rechercher ? (O/N)\n");
            scanf("%4s",test);
            if(strcmp(test,"O")==0 || strcmp(test,"N")==0)
            {
                exit=1;
            }
        }
        j=0;
        i=0;
        if(strcmp(test,"O")==0)
        {
            printf("Saisissez son prenom :\n");
            fgets(prenom,sizeof(prenom),stdin);
            fgets(prenom,sizeof(prenom),stdin);
            y=0;
            cara=prenom[0];
            while(cara!='\n')
            {
                y++;
                cara=prenom[y];
            }
            prenom[y]='\0';
            while(j<compteur)
            {
                if(strcmp(lower(tab[j].prenom),lower(prenom))==0)
                {
                    tab2[i]=tab[j];
                    i++;
                }
                j++;
            }
        }
        if(i==0)
        {
            if(strcmp(test,"N")==0)
            {
                for(int k=0;k<compteur;k++)
                {
                    printf("Nom: %s,Prenom: %s,Ville: %s,Code Postal: %s,Numero de telephone: %s,Email: %s,profession: %s\n",tab[k].nom,tab[k].prenom,tab[k].ville,tab[k].code_postal,tab[k].num_tel,tab[k].email,tab[k].profession);
                }
            }
            else if(strcmp(test,"N")!=0)
            {
                printf("Aucun resultat pour cette recherche\n");
                mainExit=1;
                break;
            }

        }
        else
        {
            for(int k=0;k<i;k++)
            {
                tab[k]=tab2[k];
                printf("Nom: %s,Prenom: %s,Ville: %s,Code Postal: %s,Numero de telephone: %s,Email: %s,profession: %s\n",tab[k].nom,tab[k].prenom,tab[k].ville,tab[k].code_postal,tab[k].num_tel,tab[k].email,tab[k].profession);
            }
            if(i==1)
            {
                break;
            }
        }

        //  Filtre sur le code postal

        exit=0;
        while(exit==0)
        {
            printf("Connaissez vous le code postal de la personne rechercher ? (O/N)\n");
            scanf("%4s",test);
            if(strcmp(test,"O")==0 || strcmp(test,"N")==0)
            {
                exit=1;
            }
        }
        j=0;
        i=0;
        if(strcmp(test,"O")==0)
        {
            printf("Saisissez son code postal :\n");
            fgets(codePostal,sizeof(codePostal),stdin);
            fgets(codePostal,sizeof(codePostal),stdin);
            y=0;
            cara=codePostal[0];
            while(cara!='\n')
            {
                y++;
                cara=codePostal[y];
            }
            codePostal[y]='\0';
            while(j<compteur)
            {
                if(strcmp(tab[j].code_postal,codePostal)==0)
                {
                    tab2[i]=tab[j];
                    i++;
                }
                j++;
            }
        }
        if(i==0)
        {
            if(strcmp(test,"N")==0)
            {
                for(int k=0;k<compteur;k++)
                {
                    printf("Nom: %s,Prenom: %s,Ville: %s,Code Postal: %s,Numero de telephone: %s,Email: %s,profession: %s\n",tab[k].nom,tab[k].prenom,tab[k].ville,tab[k].code_postal,tab[k].num_tel,tab[k].email,tab[k].profession);
                }
            }
            else if(strcmp(test,"N")!=0)
            {
                printf("Aucun resultat pour cette recherche\n");
                mainExit=1;
                break;
            }

        }
        else
        {
            for(int k=0;k<i;k++)
            {
                tab[k]=tab2[k];
                printf("Nom: %s,Prenom: %s,Ville: %s,Code Postal: %s,Numero de telephone: %s,Email: %s,profession: %s\n",tab[k].nom,tab[k].prenom,tab[k].ville,tab[k].code_postal,tab[k].num_tel,tab[k].email,tab[k].profession);
            }
            if(i==1)
            {
                break;
            }
        }

        // Filtre sur la profession

        exit=0;
        while(exit==0)
        {
            printf("Connaissez vous la profession de la personne rechercher ? (O/N)\n");
            scanf("%4s",test);
            if(strcmp(test,"O")==0 || strcmp(test,"N")==0)
            {
                exit=1;
            }
        }
        j=0;
        i=0;
        if(strcmp(test,"O")==0)
        {
            printf("Saisissez sa profession :\n");
            fgets(profession,sizeof(profession),stdin);
            fgets(profession,sizeof(profession),stdin);
            y=0;
            cara=profession[0];
            while(cara!='\n')
            {
                y++;
                cara=profession[y];
            }
            profession[y]='\0';
            while(j<compteur)
            {
                if(strcmp(lower(tab[j].profession),lower(profession))==0)
                {
                    tab2[i]=tab[j];
                    i++;
                }
                j++;
            }
        }
        if(i==0 && strcmp(test,"N")==0)
        {
            if(strcmp(test,"N")==0)
            {
                for(int k=0;k<compteur;k++)
                {
                    printf("Nom: %s,Prenom: %s,Ville: %s,Code Postal: %s,Numero de telephone: %s,Email: %s,profession: %s\n",tab[k].nom,tab[k].prenom,tab[k].ville,tab[k].code_postal,tab[k].num_tel,tab[k].email,tab[k].profession);
                }
            }
            else if(strcmp(test,"N")!=0)
            {
                printf("Aucun resultat pour cette recherche\n");
                mainExit=1;
                break;
            }
        }
        else
        {
            for(int k=0;k<i;k++)
            {
                tab[k]=tab2[k];
                printf("Nom: %s,Prenom: %s,Ville: %s,Code Postal: %s,Numero de telephone: %s,Email: %s,profession: %s\n",tab[k].nom,tab[k].prenom,tab[k].ville,tab[k].code_postal,tab[k].num_tel,tab[k].email,tab[k].profession);
            }
            if(i==1)
            {
                break;
            }
        }


        mainExit=1;
    }
}















































