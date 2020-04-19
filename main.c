/********************************************
* NOM : LES 7 SEAUX                         *
* Date : 18/05/2020                         *
* AUTEURS : LAUNE Maxence, LEBAIL Romaric   *
********************************************/

//Bibliothèques
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

// Déclaration des types structurés
struct carte
{
    int valeur;
    char couleur[6];
};

//Déclaration des prototypes
int nombre_joueur(void);
int distrib(n);
int test;
//Variable globales
int n;
char j1[20];
char j2[20];
char j3[20];
char j4[20];
char j5[20];

//Programme principal

int main()
{
    printf("\n\n\n                                   Bonjour! Bienvenue au jeu des...\n\n\n");
    printf("                                               7 SEAUX\n\n\n");
    printf("                          Serez-vous le plus grand mage que l'histoire ait connu?\n\n\n\n");
    nombre_joueur();
}

//Prototypes
int nombre_joueur()
{
    int n;
    printf("                          Pour commencer veuillez indiquer le nombre de joueur : \n");
    scanf("%d",&n);
    printf("Le joueur ayant allume le jeu sera Ogarorin!\n");
    Sleep (1000);
    printf("Le joueur a la gauche de Ogarorin gauche sera Atras!\n");
    Sleep (1000);
    printf("Le joueur a la gauche de Astras sera Ekyorn!\n");
    Sleep (1000);
    if (n==4)
    {
        printf("Le joueur a la gauche de Ekyorn sera Vrilune!\n");
        Sleep(1000);
    }
    if (n==5)
    {
        printf("Le joueur a la gauche de Vrilune sera Ezthar!\n");
    }
    return n;
}

int distrib(n)
{
    int cartes[75];
    int i;

        cartes[i].valeur = 1;
        cartes[i].couleur = rouge;
        i=i+1;
        cartes[i].valeur = 2;
        cartes[i].couleur = rouge;
        i=i+1;
        cartes[i].valeur = 3;
        cartes[i].couleur = rouge;
        i=i+1;
        cartes[i].valeur = 4;
        cartes[i].couleur = rouge;
        i=i+1;
        cartes[i].valeur = 5;
        cartes[i].couleur = rouge;
        i=i+1;
        cartes[i].valeur = 6;
        cartes[i].couleur = rouge;
        i=i+1;
        cartes[i].valeur = 7;
        cartes[i].couleur = rouge;
        i=i+1;
        cartes[i].valeur = 8;
        cartes[i].couleur = rouge;
        i=i+1;
        cartes[i].valeur = 9;
        cartes[i].couleur = rouge;
        i=i+1;
        cartes[i].valeur = 1;
        cartes[i].couleur = bleu;
        i=i+1;
        cartes[i].valeur = 2;
        cartes[i].couleur = bleu;
        i=i+1;
        cartes[i].valeur = 3;
        cartes[i].couleur = bleu;
        i=i+1;
        cartes[i].valeur = 4;
        cartes[i].couleur = bleu;
        i=i+1;
        cartes[i].valeur = 5;
        cartes[i].couleur = bleu;
        i=i+1;
        cartes[i].valeur = 6;
        cartes[i].couleur = bleu;
        i=i+1;
        cartes[i].valeur = 7;
        cartes[i].couleur = bleu;
        i=i+1;
        cartes[i].valeur = 8;
        cartes[i].couleur = bleu;
        i=i+1;
        cartes[i].valeur = 9;
        cartes[i].couleur = bleu;
        i=i+1;
        cartes[i].valeur = 1;
        cartes[i].couleur = vert;
        i=i+1;
        cartes[i].valeur = 2;
        cartes[i].couleur = vert;
        i=i+1;
        cartes[i].valeur = 3;
        cartes[i].couleur = vert;
        i=i+1;
        cartes[i].valeur = 4;
        cartes[i].couleur = vert;
        i=i+1;
        cartes[i].valeur = 5;
        cartes[i].couleur = vert;
        i=i+1;
        cartes[i].valeur = 6;
        cartes[i].couleur = vert;
        i=i+1;
        cartes[i].valeur = 7;
        cartes[i].couleur = vert;
        i=i+1;
        cartes[i].valeur = 8;
        cartes[i].couleur = vert;
        i=i+1;
        cartes[i].valeur = 9;
        cartes[i].couleur = vert;
        i=i+1;
        cartes[i].valeur = 1;
        cartes[i].couleur = jaune;
        i=i+1;
        cartes[i].valeur = 2;
        cartes[i].couleur = jaune;
        i=i+1;
        cartes[i].valeur = 3;
        cartes[i].couleur = jaune;
        i=i+1;
        cartes[i].valeur = 4;
        cartes[i].couleur = jaune;
        i=i+1;
        cartes[i].valeur = 5;
        cartes[i].couleur = jaune;
        i=i+1;
        cartes[i].valeur = 6;
        cartes[i].couleur = jaune;
        i=i+1;
        cartes[i].valeur = 7;
        cartes[i].couleur = jaune;
        i=i+1;
        cartes[i].valeur = 8;
        cartes[i].couleur = jaune;
        i=i+1;
        cartes[i].valeur = 9;
        cartes[i].couleur = jaune;
        i=i+1;
        cartes[i].valeur = 1;
        cartes[i].couleur = violet;
        i=i+1;
        cartes[i].valeur = 2;
        cartes[i].couleur = violet;
        i=i+1;
        cartes[i].valeur = 3;
        cartes[i].couleur = violet;
        i=i+1;
        cartes[i].valeur = 4;
        cartes[i].couleur = violet;
        i=i+1;
        cartes[i].valeur = 5;
        cartes[i].couleur = violet;
        i=i+1;
        cartes[i].valeur = 6;
        cartes[i].couleur = violet;
        i=i+1;
        cartes[i].valeur = 7;
        cartes[i].couleur = violet;
        i=i+1;
        cartes[i].valeur = 8;
        cartes[i].couleur = violet;
        i=i+1;
        cartes[i].valeur = 9;
        cartes[i].couleur = violet;
        i=i+1;
        cartes[i].valeur = 10;
        cartes[i].couleur = rouge;
        i=i+1;
        cartes[i].valeur = 11;
        cartes[i].couleur = rouge;
        i=i+1;
        cartes[i].valeur = 12;
        cartes[i].couleur = rouge;
        i=i+1;
        cartes[i].valeur = 10;
        cartes[i].couleur = bleu;
        i=i+1;
        cartes[i].valeur = 11;
        cartes[i].couleur = bleu;
        i=i+1;
        cartes[i].valeur = 12;
        cartes[i].couleur = bleu;
        i=i+1;
        cartes[i].valeur = 10;
        cartes[i].couleur = vert;
        i=i+1;
        cartes[i].valeur = 11;
        cartes[i].couleur = vert;
        i=i+1;
        cartes[i].valeur = 12;
        cartes[i].couleur = vert;
        i=i+1;
        cartes[i].valeur = 10;
        cartes[i].couleur = jaune;
        i=i+1;
        cartes[i].valeur = 11;
        cartes[i].couleur = jaune;
        i=i+1;
        cartes[i].valeur = 12;
        cartes[i].couleur = jaune;
        i=i+1;
        cartes[i].valeur = 10;
        cartes[i].couleur = violet;
        i=i+1;
        cartes[i].valeur = 11;
        cartes[i].couleur = violet;
        i=i+1;
        cartes[i].valeur = 12;
        cartes[i].couleur = violet;
        i=i+1;
        cartes[i].valeur = 13;
        cartes[i].couleur = rouge;
        i=i+1;
        cartes[i].valeur = 14;
        cartes[i].couleur = rouge;
        i=i+1;
        cartes[i].valeur = 15;
        cartes[i].couleur = rouge;
        i=i+1;
        cartes[i].valeur = 13;
        cartes[i].couleur = bleu;
        i=i+1;
        cartes[i].valeur = 14;
        cartes[i].couleur = bleu;
        i=i+1;
        cartes[i].valeur = 15;
        cartes[i].couleur = bleu;
        i=i+1;
        cartes[i].valeur = 13;
        cartes[i].couleur = vert;
        i=i+1;
        cartes[i].valeur = 14;
        cartes[i].couleur = vert;
        i=i+1;
        cartes[i].valeur = 15;
        cartes[i].couleur = vert;
        i=i+1;
        cartes[i].valeur = 13;
        cartes[i].couleur = jaune;
        i=i+1;
        cartes[i].valeur = 14;
        cartes[i].couleur = jaune;
        i=i+1;
        cartes[i].valeur = 15;
        cartes[i].couleur = jaune;
        i=i+1;
        cartes[i].valeur = 13;
        cartes[i].couleur = violet;
        i=i+1;
        cartes[i].valeur = 14;
        cartes[i].couleur = violet;
        i=i+1;
        cartes[i].valeur = 15;
        cartes[i].couleur = violet;
        i=i+1;
    return 0;
}


