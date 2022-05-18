#include <gtk/gtk.h>


typedef struct

{
char type[30];
char identifiant[30];
char marque[30];
char quantite[30];
Datee date;
}STOCK;

void Majout(STOCK c);
void Mrecherche(GtkWidget* treeview11);
void Msuppression(char id[30], STOCK c);
void Maffichage(GtkWidget* treeview11);
void Mmodification(char id[30],STOCK c);
void Maffichagestat(GtkWidget* Mtreeview12);
int Mverifid(char id[30]);
int Mveriff(char x[]);
void Mrandomm(char W[9],STOCK c);
int Mfloatt(char y[30]);




