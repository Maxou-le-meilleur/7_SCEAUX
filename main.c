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
    int penalite;
    int victoire;
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
int tour(void);
int penalite(void);
int vainqueur(void);

//Variable globales
int n;
int nb2cartes;
int p=0;
int d=0;
int t=0;
int q=0;
int c=0;
int V=0;


//Programme principal

int main()
{
    int i;
    int a;
    srand(time(NULL));
    printf("\n\n\n                                   Bonjour! Bienvenue au jeu des...\n\n\n");
    printf("                                               7 SEAUX\n\n\n");
    printf("                          Serez-vous le plus grand mage que l'histoire ait connu?\n\n\n\n");
    nombre_joueur();
    defdeck(n);
    if (n=!3)
    {
        for (a=0; a<n; a++)
        {
            for (i=0; i<15; i++)
            {
                tour();
            }
            penalite();
        }
    }
    else
    {
        for (a=0; a<6; a++)
        {
            for (i=0; i<15; i++)
            {
                tour();
            }
            penalite();
        }
    }
    vainqueur();
    return 0;

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

int defdeck(n)
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

int distrib(n)
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
        joueur[(i/15)].jeu[i/n]=tab[alea];
        tab[alea]=tab[nb2cartes - i];
    }
    return 0;
}
void affichagecartes(int f)
{
    printf ("Joueur %d votre jeu \n ",f);
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
int prediction(i)
{
    char non[] = "non";
    char reponse[3];
    printf ("Joueur %d voulez vous prendre le mage noir?",i);
    scanf(reponse);
    if (strcmp(reponse,non) == 0)
    {
        printf("\n Joueur %d quel est votre prediction pour la couleur rouge?",i);
        scanf("%d",joueur[i].sceauR);
        printf("\n Joueur %d quel est votre prediction pour la couleur bleu?",i);
        scanf("%d",joueur[i].sceauB);
        printf("\n Joueur %d quel est votre prediction pour la couleur vert?",i);
        scanf("%d",joueur[i].sceauV);
        printf("\n Joueur %d quel est votre prediction pour la couleur jaune?",i);
        scanf("%d",joueur[i].sceauJ);
        printf("\n Joueur %d quel est votre prediction pour la couleur violet?",i);
        scanf("%d",joueur[i].sceauVi);
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
      printf("\nvous avez posé la carte %c", joueur[0].jeu[r]);
      joueur[0].jeu[r]= p;
//joueur 2
      affichagecartes(2);
      printf("\njoueur 2 quel est le numero de la carte que vous voulez poser ?");
      scanf("%d",&r);
      printf("\nvous avez posé la carte %c", joueur[1].jeu[r]);
      joueur[1].jeu[r]= d;
//joueur 3
      affichagecartes(3);
      printf("\njoueur 3 quel est le numero de la carte que vous voulez poser ?");
      scanf("%d",&r);
      printf("\nvous avez posé la carte %c", joueur[2].jeu[r]);
      joueur[2].jeu[r]= t;
if (n>=4)
      affichagecartes(4);
      printf("\njoueur 4 quel est le numero de la carte que vous voulez poser ?");
      scanf("%d",&r);
      printf("\nvous avez posé la carte %c", joueur[3].jeu[r]);
      joueur[3].jeu[r]= q;
if (n>4)
      affichagecartes(5);
      printf("\njoueur 5 quel est le numero de la carte que vous voulez poser ?");
      scanf("%d",&r);
      printf("\nvous avez posé la carte %c", joueur[4].jeu[r]);
      joueur[4].jeu[r]= c;
    return p;
    return q;
    return t;
    return c;
    return d;
}

void ComparaisonCartes()
{
    if (n<4)
        if (p>d && p>t)
        {
            printf("le joueur 1 remporte le tour");
            V=1;
        }
        if (d>p && d>t)
        {
            printf("le joueur 2 remporte le tour");
            V=2;
        }
        if (t>p && t>d)
        {
            printf("le joueur 3 remporte le tour");
            V=3;
        }
    if (n==4)
        if (p>d && p>t && p>q)
        {
            printf("le joueur 1 remporte le tour");
            V=1;
        }
        if (d>p && d>t && d>q)
        {
            printf("le joueur 2 remporte le tour");
            V=2;
        }
        if (t>p && t>d && t>q)
        {
            printf("le joueur 3 remporte le tour");
            V=3;
        }
        if (q>p && q>d && q>t)
        {
            printf("le joueur 4 remporte le tour");
            V=4;
        }
    if (n>4)
        if (p>d && p>t && p>q && p>c)
        {
            printf("le joueur 1 remporte le tour");
            V=1;
        }
        if (d>p && d>t && d>q && d>c)
        {
            printf("le joueur 2 remporte le tour");
            V=2;
        }
        if (t>p && t>d && t>q && t>c)
        {
            printf("le joueur 3 remporte le tour");
            V=3;
        }
        if (q>p && q>d && q>t && q>c)
        {
            printf("le joueur 4 remporte le tour");
            V=4;
        }
        if (c>p && c>d && c>t && c>q)
        {
            printf("le joueur 5 remporte le tour");
            V=5;
        }
    return V;
}

void gainSceaux()
{
    int r;
    int f;
    printf("\ntapez 1 si la couleur ayant remporté le plis est le rouge\ntapez 2 si la couleur ayant remporté le plis est le bleue\ntapez 3 si la couleur ayant remporté le plis est le vert\ntapez 4 si la couleur ayant remporté le plis est le jaune\ntapez 5 si la couleur ayant remporté le plis est le violet ",r);
    scanf ("%d",&r);
    switch (r)
    {
        case 1 :
            if (V==1)
            {
                joueur [0].sceauR = joueur [0].sceauR-1;
            }
            else
            {
                if (V==2)
                    joueur [1].sceauR = joueur [1].sceauR-1;
                else
                {
                    if (V==3)
                        joueur [2].sceauR = joueur [2].sceauR-1;
                    else
                    {
                        if (V==4)
                            joueur [3].sceauR = joueur [3].sceauR-1;
                        else
                        {
                            if (V==5)
                                joueur [4].sceauR = joueur [4].sceauR-1;
                        }
                    }
                }
            }
        break;
        case 2 :
            if (V==1)
                joueur[0].sceauB = joueur[0].sceauB-1;
            if (V==2)
                joueur [1].sceauB = joueur[1].sceauB-1;
            if (V==3)
                joueur [2].sceauB = joueur[2].sceauB-1;
            if (V==4)
                joueur [3].sceauB = joueur[3].sceauB-1;
            if (V==5)
                joueur [4].sceauB = joueur[4].sceauB-1;
        break;
        case 3 :
            if (V==1)
                joueur[0].sceauV = joueur[0].sceauV-1;
            if (V==2)
                joueur [1].sceauV = joueur[1].sceauV-1;
            if (V==3)
                joueur [2].sceauV = joueur[2].sceauV-1;
            if (V==4)
                joueur [3].sceauV = joueur[3].sceauV-1;
            if (V==5)
                joueur [4].sceauV = joueur[4].sceauV-1;
        break;
        case 4 :
            if (V==1)
                joueur[0].sceauJ = joueur[0].sceauJ-1;
            if (V==2)
                joueur [1].sceauJ = joueur[1].sceauJ-1;
            if (V==3)
                joueur [2].sceauJ = joueur[2].sceauJ-1;
            if (V==4)
                joueur [3].sceauJ = joueur[3].sceauJ-1;
            if (V==5)
                joueur [4].sceauJ = joueur[4].sceauJ-1;
        break;
        default :
            if (V==1)
                joueur[0].sceauVi = joueur[0].sceauVi-1;
            if (V==2)
                joueur [1].sceauVi = joueur[1].sceauVi-1;
            if (V==3)
                joueur [2].sceauVi = joueur[2].sceauVi-1;
            if (V==4)
                joueur [3].sceauVi = joueur[3].sceauVi-1;
            if (V==5)
                joueur [4].sceauVi = joueur[4].sceauVi-1;
        break;
    }
}

int tour()
{
    int i;
    distrib(n);
    for (i=0; i>=n; i++)
    {
        affichagecartes(i);
        prediction(i);
    }
        Jeu();
        ComparaisonCartes();
        gainSceaux();
        V=0;
    return V;
}

int penalite()
{
    if (n==3)
    {
        joueur[0].penalite = 2*(joueur[0].sceauR + joueur[0].sceauB + joueur[0].sceauV + joueur[0].sceauJ + joueur[0].sceauVi);
        joueur[1].penalite = 2*(joueur[1].sceauR + joueur[1].sceauB + joueur[1].sceauV + joueur[1].sceauJ + joueur[1].sceauVi);
        joueur[2].penalite = 2*(joueur[2].sceauR + joueur[2].sceauB + joueur[2].sceauV + joueur[2].sceauJ + joueur[2].sceauVi);
        if (joueur[0].penalite < joueur[1].penalite && joueur[0].penalite < joueur[2].penalite)
        {
            printf("Le joueur 1 a gagne cette manche!");
            joueur[0].victoire = joueur[0].victoire+1;
        }
        if (joueur[1].penalite < joueur[0].penalite && joueur[1].penalite < joueur[2].penalite)
        {
            printf("Le joueur 2 a gagne cette manche!");
            joueur[1].victoire = joueur[1].victoire+1;
        }
        if (joueur[2].penalite < joueur[0].penalite && joueur[2].penalite < joueur[1].penalite)
        {
            printf("Le joueur 3 a gagne cette manche!");
            joueur[2].victoire = joueur[2].victoire+1;
        }
    }
    if (n==4)
    {
        joueur[0].penalite = 2*(joueur[0].sceauR + joueur[0].sceauB + joueur[0].sceauV + joueur[0].sceauJ + joueur[0].sceauVi);
        joueur[1].penalite = 2*(joueur[1].sceauR + joueur[1].sceauB + joueur[1].sceauV + joueur[1].sceauJ + joueur[1].sceauVi);
        joueur[2].penalite = 2*(joueur[2].sceauR + joueur[2].sceauB + joueur[2].sceauV + joueur[2].sceauJ + joueur[2].sceauVi);
        joueur[3].penalite = 2*(joueur[3].sceauR + joueur[3].sceauB + joueur[3].sceauV + joueur[3].sceauJ + joueur[3].sceauVi);
        if (joueur[0].penalite < joueur[1].penalite && joueur[0].penalite < joueur[2].penalite && joueur[0].penalite < joueur[3].penalite)
        {
            printf("Le joueur 1 a gagne cette manche!");
            joueur[0].victoire = joueur[0].victoire+1;
        }
        if (joueur[1].penalite < joueur[0].penalite && joueur[1].penalite < joueur[2].penalite && joueur[1].penalite < joueur[3].penalite)
        {
            printf("Le joueur 2 a gagne cette manche!");
            joueur[1].victoire = joueur[1].victoire+1;
        }
        if (joueur[2].penalite < joueur[0].penalite && joueur[2].penalite < joueur[1].penalite && joueur[2].penalite < joueur[3].penalite)
        {
            printf("Le joueur 3 a gagne cette manche!");
            joueur[2].victoire = joueur[2].victoire+1;
        }
        if (joueur[3].penalite < joueur[0].penalite && joueur[3].penalite < joueur[1].penalite && joueur[3].penalite < joueur[2].penalite)
        {
            printf("Le joueur 4 a gagne cette manche!");
            joueur[3].victoire = joueur[3].victoire+1;
        }
    }
    if (n==5)
    {
        joueur[0].penalite = 2*(joueur[0].sceauR + joueur[0].sceauB + joueur[0].sceauV + joueur[0].sceauJ + joueur[0].sceauVi);
        joueur[1].penalite = 2*(joueur[1].sceauR + joueur[1].sceauB + joueur[1].sceauV + joueur[1].sceauJ + joueur[1].sceauVi);
        joueur[2].penalite = 2*(joueur[2].sceauR + joueur[2].sceauB + joueur[2].sceauV + joueur[2].sceauJ + joueur[2].sceauVi);
        joueur[3].penalite = 2*(joueur[3].sceauR + joueur[3].sceauB + joueur[3].sceauV + joueur[3].sceauJ + joueur[3].sceauVi);
        joueur[4].penalite = 2*(joueur[4].sceauR + joueur[4].sceauB + joueur[4].sceauV + joueur[4].sceauJ + joueur[4].sceauVi);
        if (joueur[0].penalite < joueur[1].penalite && joueur[0].penalite < joueur[2].penalite && joueur[0].penalite < joueur[3].penalite && joueur[0].penalite < joueur[4].penalite)
        {
            printf("Le joueur 1 a gagne cette manche!");
            joueur[0].victoire = joueur[0].victoire+1;
        }
        if (joueur[1].penalite < joueur[0].penalite && joueur[1].penalite < joueur[2].penalite && joueur[1].penalite < joueur[3].penalite && joueur[1].penalite < joueur[4].penalite)
        {
            printf("Le joueur 2 a gagne cette manche!");
            joueur[1].victoire = joueur[1].victoire+1;
        }
        if (joueur[2].penalite < joueur[0].penalite && joueur[2].penalite < joueur[1].penalite && joueur[2].penalite < joueur[3].penalite && joueur[2].penalite < joueur[4].penalite)
        {
            printf("Le joueur 3 a gagne cette manche!");
            joueur[2].victoire = joueur[2].victoire+1;
        }
        if (joueur[3].penalite < joueur[0].penalite && joueur[3].penalite < joueur[1].penalite && joueur[3].penalite < joueur[2].penalite && joueur[3].penalite < joueur[4].penalite)
        {
            printf("Le joueur 4 a gagne cette manche!");
            joueur[3].victoire = joueur[3].victoire+1;
        }
        if (joueur[4].penalite < joueur[0].penalite && joueur[4].penalite < joueur[1].penalite && joueur[4].penalite < joueur[2].penalite && joueur[4].penalite < joueur[3].penalite)
        {
            printf("Le joueur 5 a gagne cette manche!");
            joueur[4].victoire = joueur[4].victoire+1;
        }
    }
}
int vainqueur()
{
    if (n==3)
    {
        if (joueur[0].victoire < joueur[1].victoire && joueur[0].victoire < joueur[2].victoire)
        {
            printf("Le joueur 1 a gagne la partie!");
        }
        if (joueur[1].victoire < joueur[0].victoire && joueur[1].victoire < joueur[2].victoire)
        {
            printf("Le joueur 2 a gagne la partie!");
        }
        if (joueur[2].victoire < joueur[0].victoire && joueur[2].victoire < joueur[1].victoire)
        {
            printf("Le joueur 3 a gagne la partie!");
        }
    }
    if (n==4)
    {
        if (joueur[0].victoire < joueur[1].victoire && joueur[0].victoire < joueur[2].victoire && joueur[0].victoire < joueur[3].victoire)
        {
            printf("Le joueur 1 a gagne la partie!");
        }
        if (joueur[1].victoire < joueur[0].victoire && joueur[1].victoire < joueur[2].victoire && joueur[1].victoire < joueur[3].victoire)
        {
            printf("Le joueur 2 a gagne la partie!");
        }
        if (joueur[2].victoire < joueur[0].victoire && joueur[2].victoire < joueur[1].victoire && joueur[2].victoire < joueur[3].victoire)
        {
            printf("Le joueur 3 a gagne la partie!");
        }
        if (joueur[3].victoire < joueur[0].victoire && joueur[3].victoire < joueur[1].victoire && joueur[3].victoire < joueur[2].victoire)
        {
            printf("Le joueur 4 a gagne la partie!");
        }
    }
    if (n==5)
    {
        if (joueur[0].victoire < joueur[1].victoire && joueur[0].victoire < joueur[2].victoire && joueur[0].victoire < joueur[3].victoire && joueur[0].victoire < joueur[4].victoire)
        {
            printf("Le joueur 1 a gagne la partie!");
        }
        if (joueur[1].victoire < joueur[0].victoire && joueur[1].victoire < joueur[2].victoire && joueur[1].victoire < joueur[3].victoire && joueur[1].victoire < joueur[4].victoire)
        {
            printf("Le joueur 2 a gagne la partie!");
        }
        if (joueur[2].victoire < joueur[0].victoire && joueur[2].victoire < joueur[1].victoire && joueur[2].victoire < joueur[3].victoire && joueur[2].victoire < joueur[4].victoire)
        {
            printf("Le joueur 3 a gagne la partie!");
        }
        if (joueur[3].victoire < joueur[0].victoire && joueur[3].victoire < joueur[1].victoire && joueur[3].victoire < joueur[2].victoire && joueur[3].victoire < joueur[4].victoire)
        {
            printf("Le joueur 4 a gagne la partie!");
        }
        if (joueur[4].victoire < joueur[0].victoire && joueur[4].victoire < joueur[1].victoire && joueur[4].victoire < joueur[2].victoire && joueur[4].victoire < joueur[3].victoire)
        {
            printf("Le joueur 5 a gagne la partie!");
        }
    }
}



