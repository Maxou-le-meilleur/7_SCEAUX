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
int p=0;
int d=0;
int t=0;
int q=0;
int c=0;


//Programme principal

int main()
{
    int i;
    srand(time(NULL));
    printf("\n\n\n                                   Bonjour! Bienvenue au jeu des...\n\n\n");
    printf("                                               7 SEAUX\n\n\n");
    printf("                          Serez-vous le plus grand mage que l'histoire ait connu?\n\n\n\n");
    nombre_joueur();
    distrib(n);
    for(i=0; i<=n; i++)
    affichagecartes(i);

}

//Prototypes
int nombre_joueur()
{
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
    for (i=0; i<= nb2cartes - 1; i++)
    {
        tab[i] = i;
    }
    for (i=0; i<= nb2cartes - 1; i++)
    {
        int alea = rand()% (nb2cartes - i);
        joueur[(i/15)+1].jeu[i/n]=tab[alea];
        tab[alea]=tab[nb2cartes - i];
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
            if (joueur[f].jeu[e]+1>(nb2cartes/5) && joueur[f].jeu[e]+1<=(2*nb2cartes/5))
            {
                joueur[f].jeu[e]=joueur[f].jeu[e]-(nb2cartes/5);
            }
            if (joueur[f].jeu[e]+1>(2*nb2cartes/5) && joueur[f].jeu[e]+1<=(3*nb2cartes/5))
            {
                joueur[f].jeu[e]=joueur[f].jeu[e]-(2*nb2cartes/5);
            }
            if (joueur[f].jeu[e]+1>(3*nb2cartes/5) && joueur[f].jeu[e]+1<=(4*nb2cartes/5))
            {
                joueur[f].jeu[e]=joueur[f].jeu[e]-(3*nb2cartes/5);
            }
            if (joueur[f].jeu[e]+1>(4*nb2cartes/5) && joueur[f].jeu[e]+1<=(nb2cartes))
            {
                joueur[f].jeu[e]=joueur[f].jeu[e]-(4*nb2cartes/5);
            }
            printf("\n %d bleu", joueur[f].jeu[e]+1);
        }
        if (joueur[f].jeu[e]<(2*nb2cartes/5) && joueur[f].jeu[e]>=(nb2cartes/5));
        {
            if (joueur[f].jeu[e]+1>(nb2cartes/5) && joueur[f].jeu[e]+1<=(2*nb2cartes/5))
            {
                joueur[f].jeu[e]=joueur[f].jeu[e]-(nb2cartes/5);
            }
            if (joueur[f].jeu[e]+1>(2*nb2cartes/5) && joueur[f].jeu[e]+1<=(3*nb2cartes/5))
            {
                joueur[f].jeu[e]=joueur[f].jeu[e]-(2*nb2cartes/5);
            }
            if (joueur[f].jeu[e]+1>(3*nb2cartes/5) && joueur[f].jeu[e]+1<=(4*nb2cartes/5))
            {
                joueur[f].jeu[e]=joueur[f].jeu[e]-(3*nb2cartes/5);
            }
            if (joueur[f].jeu[e]+1>(4*nb2cartes/5) && joueur[f].jeu[e]+1<=(nb2cartes))
            {
                joueur[f].jeu[e]=joueur[f].jeu[e]-(4*nb2cartes/5);
            }
            printf("\n %d jaune", joueur[f].jeu[e]+1);
        }
        if (joueur[f].jeu[e]<(3*nb2cartes/5) && joueur[f].jeu[e]>=(2*nb2cartes/5));
        {
            if (joueur[f].jeu[e]+1>(nb2cartes/5) && joueur[f].jeu[e]+1<=(2*nb2cartes/5))
            {
                joueur[f].jeu[e]=joueur[f].jeu[e]-(nb2cartes/5);
            }
            if (joueur[f].jeu[e]+1>(2*nb2cartes/5) && joueur[f].jeu[e]+1<=(3*nb2cartes/5))
            {
                joueur[f].jeu[e]=joueur[f].jeu[e]-(2*nb2cartes/5);
            }
            if (joueur[f].jeu[e]+1>(3*nb2cartes/5) && joueur[f].jeu[e]+1<=(4*nb2cartes/5))
            {
                joueur[f].jeu[e]=joueur[f].jeu[e]-(3*nb2cartes/5);
            }
            if (joueur[f].jeu[e]+1>(4*nb2cartes/5) && joueur[f].jeu[e]+1<=(nb2cartes))
            {
                joueur[f].jeu[e]=joueur[f].jeu[e]-(4*nb2cartes/5);
            }
            printf("\n %d rouge", joueur[f].jeu[e]+1);
        }
        if (joueur[f].jeu[e]<(4*nb2cartes/5) && joueur[f].jeu[e]>=(3*nb2cartes/5));
        {
            if (joueur[f].jeu[e]+1>(nb2cartes/5) && joueur[f].jeu[e]+1<=(2*nb2cartes/5))
            {
                joueur[f].jeu[e]=joueur[f].jeu[e]-(nb2cartes/5);
            }
            if (joueur[f].jeu[e]+1>(2*nb2cartes/5) && joueur[f].jeu[e]+1<=(3*nb2cartes/5))
            {
                joueur[f].jeu[e]=joueur[f].jeu[e]-(2*nb2cartes/5);
            }
            if (joueur[f].jeu[e]+1>(3*nb2cartes/5) && joueur[f].jeu[e]+1<=(4*nb2cartes/5))
            {
                joueur[f].jeu[e]=joueur[f].jeu[e]-(3*nb2cartes/5);
            }
            if (joueur[f].jeu[e]+1>(4*nb2cartes/5) && joueur[f].jeu[e]+1<=(nb2cartes))
            {
                joueur[f].jeu[e]=joueur[f].jeu[e]-(4*nb2cartes/5);
            }
            printf("\n %d violet", joueur[f].jeu[e]+1);
        }
        if (joueur[f].jeu[e]<(5*nb2cartes/5) && joueur[f].jeu[e]>=(4*nb2cartes/5));
        {
            if (joueur[f].jeu[e]+1>(nb2cartes/5) && joueur[f].jeu[e]+1<=(2*nb2cartes/5))
            {
                joueur[f].jeu[e]=joueur[f].jeu[e]-(nb2cartes/5);
            }
            if (joueur[f].jeu[e]+1>(2*nb2cartes/5) && joueur[f].jeu[e]+1<=(3*nb2cartes/5))
            {
                joueur[f].jeu[e]=joueur[f].jeu[e]-(2*nb2cartes/5);
            }
            if (joueur[f].jeu[e]+1>(3*nb2cartes/5) && joueur[f].jeu[e]+1<=(4*nb2cartes/5))
            {
                joueur[f].jeu[e]=joueur[f].jeu[e]-(3*nb2cartes/5);
            }
            if (joueur[f].jeu[e]+1>(4*nb2cartes/5) && joueur[f].jeu[e]+1<=(nb2cartes))
            {
                joueur[f].jeu[e]=joueur[f].jeu[e]-(4*nb2cartes/5);
            }
            printf("\n %d vert", joueur[f].jeu[e]+1);
        }
    }
}
int prediction(a)
{
    char non[] = "non";
    char reponse[3];
    printf ("Joueur %d voulez vous prendre le mage noir?",a);
    scanf(reponse);
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

void Jeu()
{
    int j;
    int r;
 //joueur 1
      affichagecartes(1);
      printf("\njoueur 1 quel est le numero de la carte que vous voulez poser ?");
      scanf("%d",&r);
      printf("\nvous avez posé la carte %c", joueur[1].jeu[r]);
      joueur[1].jeu[r]= p;
//joueur 2
      affichagecartes(2);
      printf("\njoueur 2 quel est le numero de la carte que vous voulez poser ?");
      scanf("%d",&r);
      printf("\nvous avez posé la carte %c", joueur[2].jeu[r]);
      joueur[2].jeu[r]= d;
//joueur 3
      affichagecartes(3);
      printf("\njoueur 3 quel est le numero de la carte que vous voulez poser ?");
      scanf("%d",&r);
      printf("\nvous avez posé la carte %c", joueur[3].jeu[r]);
      joueur[3].jeu[r]= t;
if (n>=4)
      affichagecartes(4);
      printf("\njoueur 4 quel est le numero de la carte que vous voulez poser ?");
      scanf("%d",&r);
      printf("\nvous avez posé la carte %c", joueur[4].jeu[r]);
      joueur[4].jeu[r]= q;
if (n>4)
      affichagecartes(5);
      printf("\njoueur 5 quel est le numero de la carte que vous voulez poser ?");
      scanf("%d",&r);
      printf("\nvous avez posé la carte %c", joueur[5].jeu[r]);
      joueur[5].jeu[r]= c;
    return p;
    return q;
    return t;
    return c;
    return d;
}

void Comparaisoncartes ()
{
    if (n<4)
        if (p>d && p>t)
            printf("le joueur 1 remporte le tour");
        if (d>p && d>t)
            printf("le joueur 2 remporte le tour");
        if (t>p && t>d)
            printf("le joueur 3 remporte le tour");
    if (n=4)
        if (p>d && p>t && p>q)
                printf("le joueur 1 remporte le tour");
        if (d>p && d>t && d>q)
                printf("le joueur 2 remporte le tour");
        if (t>p && t>d && t>q)
                printf("le joueur 3 remporte le tour");
        if (q>p && q>d && q>t)
                printf("le joueur 4 remporte le tour");
    if (n>4)
        if (p>d && p>t && p>q && p>c)
                printf("le joueur 1 remporte le tour");
        if (d>p && d>t && d>q && d>c)
                printf("le joueur 2 remporte le tour");
        if (t>p && t>d && t>q && t>c)
                printf("le joueur 3 remporte le tour");
        if (q>p && q>d && q>t && q>c)
                printf("le joueur 4 remporte le tour");
        if (c>p && c>d && c>t && c>q)
                printf("le joueur 5 remporte le tour");

}


void tour1 ()
{
    int i;
    for (i=1; i<=n; i++)
    {
        prediction(i);
    }
    Jeu();
    Comparaisoncartes();



}

