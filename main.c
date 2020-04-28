/********************************************
* NOM : LES 7 SEAUX                         *
* Date : 18/05/2020                         *
* AUTEURS : LAUNE Maxence, LEBAIL Romaric   *
********************************************/

//Bibliothèques
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>


// Déclaration des types structurés
struct joueur
{
    char prenom[20];
    int jeu[14];
};
typedef struct joueur S_joueur;
S_joueur joueur[4];

//Déclaration des prototypes
int nombre_joueur(void);
int distrib(int n);
int defdeck(int n);

//Variable globales
int n;
int nb2cartes;

//Programme principal

int main()
{
    srand(time(NULL));
    printf("\n\n\n                                   Bonjour! Bienvenue au jeu des...\n\n\n");
    printf("                                               7 SEAUX\n\n\n");
    printf("                          Serez-vous le plus grand mage que l'histoire ait connu?\n\n\n\n");
    nombre_joueur();
}

//Prototypes
int nombre_joueur()
{
    int n;
    printf("                          Pour commencer veuillez indiquer le nombre de joueur : ");
    scanf("%d",&n);
    printf("\nLe joueur ayant allume le jeu doit entrer son prenom : ");
    scanf("%s",&joueur[0].prenom[20]);
    Sleep (500);
    printf("\nLe joueur a la gauche du joueur 2 doit entrer son prenom : ");
    scanf("%s",&joueur[1].prenom[20]);
    Sleep (500);
    printf("\nLe joueur a la gauche du joueur 3 doit entrer son prenom : ");
    scanf("%s",&joueur[2].prenom[20]);
    Sleep (500);
    if (n==4)
    {
        printf("\nLe joueur a la gauche du joueur 4 doit entrer son prenom : ");
        scanf("%s",&joueur[3].prenom[20]);
        Sleep(500);
    }
    if (n==5)
    {
        printf("\nLe joueur a la gauche du joueur 5 doit entrer son prenom : ");
        scanf("%s",&joueur[4].prenom[20]);
    }
    return n;
}

int defdeck(int n)
{
    if (n==3)
    {
        nb2cartes = 45;
    }
    if (n==4)
    {
        nb2cartes = 60;
    }
    if (n==5)
    {
        nb2cartes = 75;
    }
    return nb2cartes;
}

int distrib(int n)
{
    int i;
    int tab[nb2cartes - 1];
    for (i=0;i<= nb2cartes - 1; i++)
    {
        tab[i] = i;
    }
    for (i=0;i<= nb2cartes - 1; i++)
    {
        int alea = rand()% (nb2cartes - 1);
        joueur[i/15].jeu[i/n]=tab[alea];
        tab[alea]=tab[nb2cartes - 1];
    }
    return 0;
}


