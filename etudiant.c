#include <stdio.h>
#include <string.h>
#include "etudiant.h"


#include <time.h>
#include <errno.h>
#include <stdlib.h>
#include <stdbool.h>
#include "callbacks.h"
#include <gtk/gtk.h>
int ajouter_etudiant( char nom_fich[], Etudiant E)
{FILE *fp;
    fp = fopen(nom_fich,"a");//a mode ecriture a la fin du fichier
    if (fp!=NULL)
        {fprintf(fp,"%s %s %s %s %s %s %s %s %s %s %s %s \n",E.Nom,E.Prenom,E.ID,E.naissance,E.CIN,E.sexe,E.niveau,E.hobbies,E.telephone,E.etat,E.mail,E.adresse);
   fclose(fp);
return (1);}
        return 0;
}

int supprimer_etudiant(char CIN[],char nom_fichier[])
{FILE *f1=NULL, *f2=NULL;
Etudiant E;
int x=-1;
    f1 = fopen(nom_fichier, "r");
    f2 = fopen("etudiant2.txt", "w");
    if (f1==NULL)
   return(x);
    else
        while (fscanf(f1,"%s %s %s %s %s %s %s %s %s %s %s %s \n",E.Nom,E.Prenom,E.ID,E.naissance,E.CIN,E.sexe,E.niveau,E.hobbies,E.telephone,E.etat,E.mail,E.adresse)!=EOF)
            if (strcmp(CIN,E.CIN)!=0) 
                fprintf(f2,"%s %s %s %s %s %s %s %s %s %s %s %s \n",E.Nom,E.Prenom,E.ID,E.naissance,E.CIN,E.sexe,E.niveau,E.hobbies,E.telephone,E.etat,E.mail,E.adresse);
     		else
		 x=1;
    fclose(f1);
    fclose(f2);
    remove(nom_fichier);
    rename("etudiant2.txt",nom_fichier);
return(x);
}

void modifier_etudiant( char nom_fichier[], Etudiant E)
{FILE *f1, *f2;
Etudiant E1;
f1 = fopen(nom_fichier, "r"); //ouvrir fichier en mode lecture
f2 = fopen("etudiant2.txt", "w");
if (f1==NULL)
  printf("\nEchec lors de l'ouverture du fichier %s ",nom_fichier);
else
{
	while (fscanf(f1,"%s %s %s %s %s %s %s %s %s %s %s %s \n",E1.Nom,E1.Prenom,E1.ID,E1.naissance,E1.CIN,E1.sexe,E1.niveau,E1.hobbies,E1.telephone,E1.etat,E1.mail,E1.adresse)!=EOF)
		if (strcmp(E1.ID,E.ID)==0)
			fprintf(f2,"%s %s %s %s %s %s %s %s %s %s %s %s \n",E.Nom,E.Prenom,E.ID,E.naissance,E.CIN,E.sexe,E.niveau,E.hobbies,E.telephone,E.etat,E.mail,E.adresse);
		else
			fprintf(f2,"%s %s %s %s %s %s %s %s %s %s %s %s \n",E1.Nom,E1.Prenom,E1.ID,E1.naissance,E1.CIN,E1.sexe,E1.niveau,E1.hobbies,E1.telephone,E1.etat,E1.mail,E1.adresse);	
       fclose(f1);
      fclose(f2);
      remove(nom_fichier);
      rename("etudiant2.txt", nom_fichier) ;
}
}
enum{
NOM,
PRENOM,
MAIL,
CIN,
ID,
NIVEAU,
SEXE,
ADRESSE,
ETAT,
HOBB,
TELEPHONE,
NAISS,
COLUMNS};

void afficher_etudiant(GtkWidget *liste)
{Etudiant E;
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
FILE *f;

store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("NOM",renderer,"text",NOM,NULL);//nom du colonne"reference"
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	gtk_tree_view_column_set_expand(column,TRUE);////
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("PRENOM",renderer,"text",PRENOM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	gtk_tree_view_column_set_expand(column,TRUE);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("MAIL",renderer,"text",MAIL,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	gtk_tree_view_column_set_resizable(column,TRUE);//////////////////
	gtk_tree_view_column_set_expand(column,TRUE);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("CIN",renderer,"text",CIN,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	gtk_tree_view_column_set_expand(column,TRUE);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("ID",renderer,"text",ID,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	gtk_tree_view_column_set_expand(column,TRUE);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("TELEPHONE",renderer,"text",TELEPHONE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	gtk_tree_view_column_set_expand(column,TRUE);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("ADRESSE",renderer,"text",ADRESSE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	gtk_tree_view_column_set_expand(column,TRUE);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("SEXE",renderer,"text",SEXE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	gtk_tree_view_column_set_expand(column,TRUE);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("ETAT",renderer,"text",ETAT,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	gtk_tree_view_column_set_expand(column,TRUE);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("NIVEAU",renderer,"text",NIVEAU,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	gtk_tree_view_column_set_expand(column,TRUE);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("HOBB",renderer,"text",HOBB,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	gtk_tree_view_column_set_expand(column,TRUE);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Naissance",renderer,"text",NAISS,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	gtk_tree_view_column_set_expand(column,TRUE);

	


store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f=fopen("etudiant.txt","r");
if(f!=NULL)

{ f = fopen("etudiant.txt","a+");
		while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s \n",E.Nom,E.Prenom,E.ID,E.naissance,E.CIN,E.sexe,E.niveau,E.hobbies,E.telephone,E.etat,E.mail,E.adresse)!=EOF)
	{ 
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,NOM,E.Nom,PRENOM,E.Prenom,MAIL,E.mail,CIN,E.CIN,ID,E.ID,TELEPHONE,E.telephone,ADRESSE,E.adresse,SEXE,E.sexe,ETAT,E.etat,NIVEAU,E.niveau,HOBB,E.hobbies,NAISS,E.naissance,-1);
	}
	fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref(store);
}
}
gtk_tree_view_set_enable_search(GTK_TREE_VIEW(liste),TRUE);
}
/////////////////////////////////////////////
Etudiant chercher_etudiant(char nom_fichier[],char ID[])
{FILE *f=NULL;

Etudiant E1;
f=fopen(nom_fichier,"r");
if(f!=NULL)
{   while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s \n",E1.Nom,E1.Prenom,E1.ID,E1.naissance,E1.CIN,E1.sexe,E1.niveau,E1.hobbies,E1.telephone,E1.etat,E1.mail,E1.adresse)!=EOF);
      if(strcmp(ID,E1.ID)==0)
         {fclose(f);
          return(E1);}
}
  return(E1);

int dash( char nom_fich[])
{ 
 FILE *f,*f2;
Etudiant E1;
int x1=0,x2=0,x3=0,x4=0,x5=0;
f=fopen(nom_fich,"r");
f2=fopen("nb_etudiant.txt","w");

	while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s \n",E1.Nom,E1.Prenom,E1.ID,E1.naissance,E1.CIN,E1.sexe,E1.niveau,E1.hobbies,E1.telephone,E1.etat,E1.mail,E1.adresse)!=EOF)
	{if(strcmp(E1.niveau,"1er")==0)
            x1++;
   	else 
	    if(strcmp(E1.niveau,"2eme")==0)
		x2++;
	else 
	    if(strcmp(E1.niveau,"3eme")==0)
		x3++;
	else 
	    if(strcmp(E1.niveau,"4eme")==0)
		x4++;
	else 
	    if(strcmp(E1.niveau,"5eme")==0)
		x5++;
	}
fprintf(f2,"%d %d %d %d %d \n",x1,x2,x3,x4,x5);
fclose(f);
fclose(f2);}}







