#include <gtk/gtk.h>




typedef struct stock
{


char nom[30];
char prenom[30];
char identifiant[30];
char sexe[30];
char cin[30];
char chambre[30];
char etage[30];
Datee date;
}stock;

void AMaffichage(GtkWidget* treeview);
void AMajout(stock s);

void AMsuppression(char id[30], stock s);
void AMrecherche(GtkWidget* AStreeview);
void AMmodification(char id[30], stock s);
int AMverifid(char id[30]);
int AMveriff(char x[]);
void AMrandomm(char W[9]);
void AMaffichage_etud(char niveau[30],GtkWidget* treeview1);
int AMcheck(char y[30]);
int nombreniv(char niveau[30]);
typedef struct etudiant
{
char nomm[20];    
char prenomm[20];  
char cinn[20];
char sexee[20];
char niv[30];
}etudiant;

