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
    int sceauR;
    int sceauB;
    int sceauV;
    int sceauJ;
    int sceauVi;
};

typedef struct joueur S_joueur;
S_joueur joueur[4];




//Déclaration des prototypes
int nombre_joueur(void);
int distrib(int n);
int defdeck(int n);
int prediction(int a);
void ChoixDesSceaux(void);
void affichagecartes(int f);
void tour1(void);

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
    affichagecartes(2);
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

    printf("Le joueur ayant allume le jeu sera Ogarorin!\n");
    Sleep (1000);
    printf("Le joueur a la gauche de Ogarorin sera Atras!\n");
    Sleep (1000);
    printf("Le joueur a la gauche de Astras sera Ekyorn!\n");
    Sleep (1000);

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
void affichagecartes(f)
{
    int i;
    printf ("Joueur 1 votre jeu \n ");
    for (int e=0; e < 15; e++)
    {
        if (joueur[f].jeu[e]<(nb2cartes/5))
        {
            printf("\n %d bleu", joueur[f].jeu[e]+1);
        }
        if (joueur[f].jeu[e]<(2*nb2cartes/5) && joueur[f].jeu[e]>=(nb2cartes/5));
        {
            printf("\n %d jaune", joueur[f].jeu[e]+1);
        }
        if (joueur[f].jeu[e]<(3*nb2cartes/5) && joueur[f].jeu[e]>=(2*nb2cartes/5));
        {
            printf("\n %d rouge", joueur[f].jeu[e]+1);
        }
        if (joueur[f].jeu[e]<(4*nb2cartes/5) && joueur[f].jeu[e]>=(3*nb2cartes/5));
        {
            printf("\n %d violet", joueur[f].jeu[e]+1);
        }
        if (joueur[f].jeu[e]<(5*nb2cartes/5) && joueur[f].jeu[e]>=(4*nb2cartes/5));
        {
            printf("\n %d vert", joueur[f].jeu[e]+1);
        }
    }
}
int prediction(a)
{
    char non[] = "non";
    char reponse[3];
    printf ("Joueur %d voulez vous prendre le mage noir?",a);
    gets(reponse);
    if (strcmp(reponse,non) == 0)
    {
        printf("\n Joueur %d quel est votre prediction pour la couleur rouge?",a);
        scanf("%d",joueur[a].sceauR);
        printf("\n Joueur %d quel est votre prediction pour la couleur bleu?",a);
        scanf("%d",joueur[a].sceauB);
        printf("\n Joueur %d quel est votre prediction pour la couleur vert?",a);
        scanf("%d",joueur[a].sceauV);
        printf("\n Joueur %d quel est votre prediction pour la couleur jaune?",a);
        scanf("%d",joueur[a].sceauJ);
        printf("\n Joueur %d quel est votre prediction pour la couleur violet?",a);
        scanf("%d",joueur[a].sceauVi);
    }
    else;
    {
        printf("Vous avez pris le mage noir!");
    }

}

void tour1()
{
    int i;
    for (i=1; i<=5; i++)
    prediction(i);


}

