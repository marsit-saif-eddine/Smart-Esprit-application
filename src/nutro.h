#include <gtk/gtk.h>




typedef struct 
{
char type[30];
char menu[30];
char identifiant[30];
char gluten[30];
char pp[30];
char dessert[30];
Datee date;
}MENU;

typedef struct
{
char jour[20];    
char temps[20];  
char valeur[20];
}dechet;


void DBaffichage(GtkWidget* treeview1);
void DBajout(MENU M);
void DBsuppression(char id[30], MENU M);
void DBrecherche(GtkWidget* treeview1);
void DBmodification(char id[30], MENU M);
void DBaffichage_stat(GtkWidget* treeview2);
int DBverifid(char id[30]);
int DBveriff(char x[]);
void DBmin (char x[30],char k[10]);
void DBrandomm(char W[9],MENU M);

