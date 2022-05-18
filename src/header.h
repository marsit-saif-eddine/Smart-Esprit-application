#include <gtk/gtk.h>
//-----------------------------------------------------------Gestion utilisateurs----------------------------------------------------
typedef struct date
{
int jour;
int mois;
int annee;
}Datee;

//----------------------------------------------------LOGIN----------------------------------------------------------------
typedef struct utilisateur
{
char nom[30];
char prenom[30];
char identifiant[30];
char sexe[30];
char cin[30];
char role[30];
char mddpSM[30];
char email[30];
char telephone[30];
Datee date;
}utilisateur;
void idetudiant(char log[] , char Pw[],char idtemp[20]);
void SMaffichage(GtkWidget* SMtreeview);
void SMajout(utilisateur E);

void SMsuppression(char id[30], utilisateur E);
void SMrecherche(GtkWidget* AStreeview);
void SMmodification(char id[30], utilisateur E);
int SMverifid(char id[30]);
int SMveriff(char x[]);
void SMrandomm(char W[9],utilisateur E);
void SMsuppressionn(char id[30],utilisateur E);
int SMcheck(char y[30]);
int SMverif (char log[] , char Pw[]);
void adminapprouver(GtkWidget* treeviewappadmin,char idadmin[30]);
void adminaffichage(GtkWidget* treeviewappadmin);
void SMrandommadminn(char ad[5]);
void suppressionadmin(char idadmin[30]);
int cherche( char y[30]);
int invcherche( char y[30]);
int checkemail(char y[30]);
void mail(char x [200]);
void mail2(char x [200], char y [100], char z[100]);
//---------------------------------------------------------------------------------------------------------------------------


