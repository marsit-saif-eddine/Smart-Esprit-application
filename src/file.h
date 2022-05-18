#include <gtk/gtk.h>


typedef struct
{
int heure;
int minute;
}timee;

typedef struct

{
char type[30];
char identifiant[30];
char marque[30];
char valeur[30];
char etage[30];
Datee date;
timee temps;
}CAPTEURS;


void ajout(CAPTEURS c);
void recherche(GtkWidget* treeview11);
void suppression(char id[30], CAPTEURS c);
void affichage(GtkWidget* treeview11);
void modification(char id[30],CAPTEURS c);
void affichagestat(GtkWidget* treeview12);
void affichagestat1(GtkWidget* treeview12);
void affichagestat2(GtkWidget* treeview12);
int nombret(CAPTEURS c);
int nombrep(CAPTEURS c);
int Mrq_Deff(CAPTEURS c);
void randomm(char id[9],CAPTEURS c);
int veriff(char x[]);
int floatt(char y[30]);
