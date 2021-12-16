#ifndef ETUDIANT_H_
#define ETUDIANT_H_
#include <gtk/gtk.h>
typedef struct etudiant
{
char Nom[30];
char Prenom[30];
char ID[10];
char naissance[11];
char CIN[9];
char sexe[10];
char niveau[20];
char hobbies[30];
char telephone[8];
char etat[20];
char mail[20];
char adresse[30];
}Etudiant;

int ajouter_etudiant( char nom_fich[], Etudiant E);
void modifier_etudiant( char nom_fichier[], Etudiant E);
int supprimer_etudiant(char CIN[],char nom_fichier[]);
void afficher_etudiant(GtkWidget *liste);
Etudiant chercher_etudiant(char nom_fichier[],char ID[]);
int dash( char nom_fich[]);
 #endif

