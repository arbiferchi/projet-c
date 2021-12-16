#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "etudiant.h"
int x=0,n;
int t[4]={0,0,0,0};
Etudiant e;
/*______________page d'acceuil_____________________________________________*/
void
on_Supprimer1_clicked                  (GtkWidget       *button,
                                        gpointer         user_data)
{ GtkWidget *windowsup,*windowacc;
  
windowacc=lookup_widget(button,"Acceuil");
gtk_widget_destroy(windowacc);

windowsup=create_Suppresion();
gtk_widget_show(windowsup);

}
////////////////////////////
void
on_Quitter_clicked                     (GtkWidget       *button,
                                        gpointer         user_data)
{GtkWidget *windowaff;

windowaff=lookup_widget(button,"Acceuil");
gtk_widget_destroy(windowaff);}
//////////////////////////////
void
on_Chercher_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{GtkWidget *windowrech,*windowacc;

windowacc=lookup_widget(button,"Acceuil");
gtk_widget_destroy(windowacc);

windowrech=create_chercher();
gtk_widget_show(windowrech);

}
/////////////////////////////
void
on_Afficher_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *windowacc, *windowaff,*treeview1;

windowacc=lookup_widget(button,"Acceuil");
gtk_widget_destroy(windowacc);

windowaff=lookup_widget(button,"Afficher");
windowaff=create_Afficher();
gtk_widget_show(windowaff);

treeview1 = lookup_widget (windowaff, "treeview1");
afficher_etudiant(treeview1);
}

//////////////////////////////
void
on__modifier_clicked                   (GtkWidget       *button,gpointer         user_data)
{GtkWidget *windowrech,*windowacc;

windowacc=lookup_widget(button,"Acceuil");
gtk_widget_destroy(windowacc);

windowrech=create_chercher();
gtk_widget_show(windowrech);}                               

//////////////////////////////
void
on_Ajouter_clicked                     (GtkWidget       *button,
                                        gpointer         user_data)
{GtkWidget *windowajout,*windowacc;

windowacc=lookup_widget(button,"Acceuil");
gtk_widget_destroy(windowacc);

windowajout=create_Ajouter();
gtk_widget_show(windowajout);}
///////////////////////////////
void
on_Dashboard_clicked                   (GtkWidget       *button,
                                        gpointer         user_data)
{GtkWidget *windowdash,*windowacc;

windowacc=lookup_widget(button,"Acceuil");
gtk_widget_destroy(windowacc);

windowdash=create_Dashboard();
gtk_widget_show(windowdash);}
////////////////////////////////

/*________________________les boutons home___________________________________*/

void
on_Homeajout_clicked                   (GtkWidget       *button,
                                        gpointer         user_data)
 
{GtkWidget *windowacc, *windowajout;

windowajout=lookup_widget(button,"Ajouter");
gtk_widget_destroy(windowajout);

windowacc=create_Acceuil();
gtk_widget_show(windowacc);}
///////////////////////////////
void
on_Homesupp_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{GtkWidget *windowacc, *windowsup;

windowsup=lookup_widget(button,"Suppresion");
gtk_widget_destroy(windowsup);

windowacc=create_Acceuil();
gtk_widget_show(windowacc);}
//////////////////////////////
void
on_Homechercher_clicked                (GtkWidget       *button,
                                        gpointer         user_data)
{GtkWidget *windowacc, *windowrech;

windowrech=lookup_widget(button,"chercher");
gtk_widget_destroy(windowrech);

windowacc=create_Acceuil();
gtk_widget_show(windowacc);}

/////////////////////////////
void
on_homeafficher_clicked                (GtkWidget       *button,
                                        gpointer         user_data)
{GtkWidget *windowacc, *windowaff;

windowaff=lookup_widget(button,"Afficher");
gtk_widget_destroy(windowaff);

windowacc=create_Acceuil();
gtk_widget_show(windowacc);}
////////////////////////////
void
on_Homedash_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{GtkWidget *windowacc, *windowdash;

windowdash=lookup_widget(button,"Dashboard");
gtk_widget_destroy(windowdash);

windowacc=create_Acceuil();
gtk_widget_show(windowacc);}
///////////////////////////
void
on_Homemodifi_clicked                  (GtkWidget      *button,
                                        gpointer         user_data)
{GtkWidget *windowacc, *windowmodif;

windowmodif=lookup_widget(button,"Modification");
gtk_widget_destroy(windowmodif);

windowacc=create_Acceuil();
gtk_widget_show(windowacc);}
/////////////////////////////////
/*_______________________les boutons radio________________________*/
void
on_Homme_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
 if(gtk_toggle_button_get_active (GTK_RADIO_BUTTON(togglebutton)))
 {x=1;}
}
void
on_Femme_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
 if(gtk_toggle_button_get_active (GTK_RADIO_BUTTON(togglebutton)))
 {x=2;}
}
/*____________________case a cocher____________________________________*/
void
on_Natation_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{ if (gtk_toggle_button_get_active (togglebutton))
 t[0]=1;
}
void
on_lec_toggled                         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{if (gtk_toggle_button_get_active(togglebutton))
 t[1]=1;
}
void
on_prog_toggled                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{if (gtk_toggle_button_get_active(togglebutton))
 t[2]=1;
}
void
on_autre_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{if (gtk_toggle_button_get_active(togglebutton))
 t[3]=1;
}
/*_________________fenetre ajout___________________________________________________________*/
void
on_Ajouter2_clicked                    (GtkWidget       *button, gpointer         user_data)
{
 GtkWidget *j,*m,*a;
char ch1[30];
int x1,x2,x3,r;
 GtkWidget* input,*output;
Etudiant e;
 input = lookup_widget(button,"entry_nom");
 strcpy(e.Nom,gtk_entry_get_text(GTK_ENTRY(input)));
 input = lookup_widget(button,"entry38");
 strcpy(e.adresse,gtk_entry_get_text(GTK_ENTRY(input)));
 input = lookup_widget(button,"entry_prenom");
 strcpy(e.Prenom,gtk_entry_get_text(GTK_ENTRY(input)));
 input = lookup_widget(button,"entry_cin");
 strcpy(e.CIN,gtk_entry_get_text(GTK_ENTRY(input)));
 input = lookup_widget(button,"entry_id");
 strcpy(e.ID,gtk_entry_get_text(GTK_ENTRY(input)));
 input = lookup_widget(button,"entry27");
 strcpy(e.mail,gtk_entry_get_text(GTK_ENTRY(input)));
 input = lookup_widget(button,"entry28");
 strcpy(e.telephone,gtk_entry_get_text(GTK_ENTRY(input)));
input = lookup_widget(button,"entry37");
 strcpy(e.etat,gtk_entry_get_text(GTK_ENTRY(input)));
 ////////les boutons radios
 if(x==1) strcpy(e.sexe,"Homme");
else  strcpy(e.sexe,"Femme");
//////spinboutons
j=lookup_widget(button,"spinbutton1");
m=lookup_widget(button,"spinbutton2"); 
a=lookup_widget(button,"spinbutton3");
//////recuperer les valeurs des spin button 
x1=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(j));
x2=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(m));
x3=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(a));
sprintf(e.naissance,"%d/%d/%d",x1,x2,x3);
////////combobox
input=lookup_widget(button, "combobox2") ; 
strcpy(e.niveau,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input)));
///////case a coucher
strcpy(e.hobbies,"");
if(t[0]==1)
strcat(e.hobbies,"Nattation");
if(t[1]==1)
strcat(e.hobbies,"Lecture");
if(t[2]==1)
strcat(e.hobbies,"programmation");
if(t[3]==1)
strcat(e.hobbies,"autre");
/////////////////////////
r=ajouter_etudiant("etudiant.txt",e);
output=lookup_widget(button,"label95");
if(r==1)
{ strcpy (ch1,"ajout avec succée");
gtk_label_set_text(GTK_LABEL(output),ch1);
}
else{strcpy (ch1,"ajout failed");
sprintf(ch1,"%d",r);
gtk_label_set_text(GTK_LABEL(output),ch1);
}
}
/*___________________les boutons annuler__________________________________________________*/
void
on_Annuler1_clicked                    (GtkWidget      *button,
                                        gpointer         user_data)
{GtkWidget *windowajout;

windowajout=lookup_widget(button,"Ajouter");
gtk_widget_destroy(windowajout);
windowajout=create_Ajouter();
gtk_widget_show(windowajout);
}

void
on_Annuler2_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{GtkWidget *windowsup;

windowsup=lookup_widget(button,"Suppression");
gtk_widget_destroy(windowsup);
windowsup=create_Suppresion();
gtk_widget_show(windowsup);

}

/*_____________________________________________________________________________________*/
void
on_chercher2_clicked                   (GtkWidget       *button,
                                        gpointer         user_data)
{GtkWidget* input;
  GtkWidget* output ;
char ID[10],ch[10];
Etudiant e;

input = lookup_widget(button, "entry11") ;
strcpy(ID,gtk_entry_get_text(GTK_ENTRY(input))); 

e=chercher_etudiant("etudiant.txt",ID);

 
if(strcmp(e.ID,ID)==0)
{//mawjoud
output=lookup_widget(button,"entry12");
gtk_entry_set_text(GTK_ENTRY(output),e.Nom);

output=lookup_widget(button,"entry13");
gtk_entry_set_text(GTK_ENTRY(output),e.Prenom);

output=lookup_widget(button,"entry15");
gtk_entry_set_text(GTK_ENTRY(output),e.CIN);

output=lookup_widget(button,"entry16");
gtk_entry_set_text(GTK_ENTRY(output),e.niveau);

output=lookup_widget(button,"entry17");
gtk_entry_set_text(GTK_ENTRY(output),e.mail);

output=lookup_widget(button,"entry18");
gtk_entry_set_text(GTK_ENTRY(output),e.etat);

output=lookup_widget(button,"entry30");
gtk_entry_set_text(GTK_ENTRY(output),e.adresse);

output=lookup_widget(button,"entry29");
gtk_entry_set_text(GTK_ENTRY(output),e.telephone);

output=lookup_widget(button,"entry36");
gtk_entry_set_text(GTK_ENTRY(output),e.naissance);
}
else{
///mch mawjoud
output=lookup_widget(button,"label135");
gtk_label_set_text(GTK_LABEL(output),"etudiant n'existe pas");
}


}


/*_____________suppression______________________________________________*/
void
on_button1_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget* input;
  GtkWidget* output ;
char CIN[9],msg[30];
int r;
 output = lookup_widget(objet, "label125") ;
 input = lookup_widget(objet, "entry_cinsup") ;
 
 strcpy(CIN,gtk_entry_get_text(GTK_ENTRY(input))); 
 r=supprimer_etudiant(CIN,"etudiant.txt");
 if(r==-1)
    strcpy(msg,"Suppression non effectuée\n");
  else
    strcpy(msg,"suppression effectuée avec succès \n");
 gtk_label_set_text(GTK_LABEL(output),msg);
}


void
on_oksup_clicked                       (GtkButton       *button,
                                        gpointer         user_data)
{

}



/*____________modif____________________________*/

void
on_button2_clicked                     (GtkWidget      *button,
                                        gpointer         user_data)
{ GtkWidget* input;
  GtkWidget* output ;
char ID[10];
Etudiant e;

input = lookup_widget(button, "entry11") ;
strcpy(ID,gtk_entry_get_text(GTK_ENTRY(input))); 
e=chercher_etudiant("etudiant.txt",ID);

 
if(strcmp(e.ID,ID)==0)
{//mawjoud
input=lookup_widget(button, "entry11") ;
strcpy(e.ID,gtk_entry_get_text(GTK_ENTRY(input)));
input = lookup_widget(button, "entry12") ;
strcpy(e.Nom,gtk_entry_get_text(GTK_ENTRY(input)));
input = lookup_widget(button, "entry13") ;
strcpy(e.Prenom,gtk_entry_get_text(GTK_ENTRY(input)));
input = lookup_widget(button, "entry15") ;
strcpy(e.CIN,gtk_entry_get_text(GTK_ENTRY(input)));
input = lookup_widget(button, "entry16") ;
strcpy(e.niveau,gtk_entry_get_text(GTK_ENTRY(input)));
input = lookup_widget(button, "entry17") ;
strcpy(e.mail,gtk_entry_get_text(GTK_ENTRY(input)));
input = lookup_widget(button, "entry18") ;
strcpy(e.etat,gtk_entry_get_text(GTK_ENTRY(input)));
input = lookup_widget(button, "entry30") ;
strcpy(e.adresse,gtk_entry_get_text(GTK_ENTRY(input)));

input=lookup_widget(button,"entry29");
strcpy(e.telephone,gtk_entry_get_text(GTK_ENTRY(input)));

input = lookup_widget(button, "entry36") ;
strcpy(e.naissance,gtk_entry_get_text(GTK_ENTRY(input)));
modifier_etudiant("etudiant.txt",e);
}
}
/*______________________________________________________________________*/


void
on_button3_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{{char cin[10],mdp[10];
GtkWidget * input,*windowacc,*output;

input = lookup_widget(button, "cinfoyer") ;
strcpy(cin,gtk_entry_get_text(GTK_ENTRY(input)));

input = lookup_widget(button, "passfoyer") ;
strcpy(mdp,gtk_entry_get_text(GTK_ENTRY(input)));
if((strcmp(cin,"")==0)&&(strcmp(mdp,"")==0))//////////////////////////////////////////
{
windowacc=lookup_widget(button,"Acceuil");
windowacc=create_Acceuil();
gtk_widget_show(windowacc);
}
else
     {	output=lookup_widget(windowacc,"affichemsg");
	gtk_label_set_text(GTK_LABEL(output),"verifier votre donnees!!");
     }
}

}

