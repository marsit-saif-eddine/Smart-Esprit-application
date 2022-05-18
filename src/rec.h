//--------------------------------------------------RECLAMATION+SERVICEPLUSRECLAMAEE-------------------------------------------------------

#include <gtk/gtk.h>

typedef struct

{
char type[30];
char identifiant[30];
char nom[30];
char cin[30];
char problem[30];
Datee datea;
Datee dater;
char idtempp[20];
}RECLAMATION;

void KRajout(RECLAMATION r);
void KRrecherche(GtkWidget* KRtreeview1);
void KRsuppression(char id[30], RECLAMATION r);
void KRaffichage(GtkWidget* KRtreeview1,char idtemp[20]);
void KRmodification(char id[30],RECLAMATION r);
int KRnombrer(RECLAMATION r);
int KRnombreh(RECLAMATION r);
int KRverifid(char id[30]);
int KRveriff(char x[]);
void KRrandomm(char W[9],RECLAMATION r);
void KRaffichagee(GtkWidget* KRtreeview1111);

//------------------------------------------------------------------------------------------------------------------------------------------
