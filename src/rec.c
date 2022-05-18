#include <stdlib.h>
#include <stdio.h>
#include<string.h>
#include "header.h" 

#include "rec.h"
enum{TYPER,IDENTIFIANTR,NOMR,CINR,PROBLEMR,DATER,DATER2,COLUMNS2};

void KRaffichage(GtkWidget* KRtreeview1,char idtemp[20])
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
RECLAMATION r;char Date[100];char Dater[100];
store=NULL;
FILE *f;
store=gtk_tree_view_get_model(KRtreeview1);
if (store==NULL)
{
renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Type", renderer, "text",TYPER, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (KRtreeview1), column);


renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Identifiant", renderer, "text",IDENTIFIANTR, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (KRtreeview1), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Nom et Prenom", renderer, "text",NOMR, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (KRtreeview1), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Cin", renderer, "text",CINR, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (KRtreeview1), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("problem", renderer, "text",PROBLEMR, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (KRtreeview1), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Date d'ajout", renderer, "text",DATER, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (KRtreeview1), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Date de reclamation", renderer, "text",DATER2, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (KRtreeview1), column);}

store=gtk_list_store_new(COLUMNS2,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f=fopen("reclamation.bin","ab");
if(f==NULL)
{return;}
else
{f=fopen("reclamation.bin","ab+");
while(fread(&r,sizeof(RECLAMATION),1,f))
{
if(strcmp(r.idtempp,idtemp)==0){
sprintf(Date,"%d/%d/%d",r.datea.jour,r.datea.mois,r.datea.annee);
sprintf(Dater,"%d/%d/%d",r.dater.jour,r.dater.mois,r.dater.annee);

gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,TYPER,r.type,IDENTIFIANTR,r.identifiant,NOMR,r.nom,CINR,r.cin,PROBLEMR,r.problem,DATER,Date,DATER2,Dater,-1);
}}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(KRtreeview1),GTK_TREE_MODEL (store));
g_object_unref(store);}}



void KRajout (RECLAMATION r){
FILE*f=NULL; 
f=fopen("reclamation.bin","ab+");
fwrite(&r,sizeof(RECLAMATION),1,f);  
fclose(f);

}


void KRsuppression(char id[30],RECLAMATION r){
FILE*f;
FILE*g;
f=fopen("reclamation.bin","ab+");
g=fopen("tmp.bin","wb+");
if(g!=NULL){
while(fread(&r,sizeof(RECLAMATION),1,f))
{
if (strcmp(r.identifiant,id)!=0){
fwrite(&r,sizeof(RECLAMATION),1,g);

}
}
}fclose(f);
fclose(g);
remove("reclamation.bin");
rename("tmp.bin","reclamation.bin");
}



void KRmodification(char id[30],RECLAMATION r)
{

	KRsuppression(id,r);
	KRajout(r);

}

void KRrecherche(GtkWidget* KRtreeview1)
{
GtkCellRenderer *renderer;
 GtkTreeViewColumn *column;
 GtkTreeIter iter;
 GtkListStore *store;

store=NULL;RECLAMATION r;
 FILE *f2;char Date[100];char Dater[100];
 store=gtk_tree_view_get_model(KRtreeview1);
 if (store==NULL)
{

   renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Type", renderer, "text",TYPER, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (KRtreeview1), column);


renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Identifiant", renderer, "text",IDENTIFIANTR, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (KRtreeview1), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Nom et Prenom", renderer, "text",NOMR, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (KRtreeview1), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Cin", renderer, "text",CINR, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (KRtreeview1), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("problem", renderer, "text",PROBLEMR, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (KRtreeview1), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Date d'ajout", renderer, "text",DATER, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (KRtreeview1), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Date de reclamation", renderer, "text",DATER2, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (KRtreeview1), column);}

store=gtk_list_store_new(COLUMNS2,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f2=fopen("recherche.bin", "rb");
if(f2==NULL)
{
 return;
}
else 
{ f2=fopen("recherche.bin", "ab+");
    while(fread(&r,sizeof(RECLAMATION),1,f2))
     {sprintf(Date,"%d/%d/%d",r.datea.jour,r.datea.mois,r.datea.annee);
sprintf(Dater,"%d/%d/%d",r.dater.jour,r.dater.mois,r.dater.annee);

gtk_list_store_append (store,&iter);
gtk_list_store_set(store,&iter,TYPER,r.type,IDENTIFIANTR,r.identifiant,NOMR,r.nom,CINR,r.cin,PROBLEMR,r.problem,DATER,Date,DATER2,Dater,-1);
}
fclose(f2);
gtk_tree_view_set_model (GTK_TREE_VIEW (KRtreeview1), GTK_TREE_MODEL (store));
g_object_unref (store);
}
}
int KRnombrer(RECLAMATION r)
{
int k=0;


FILE *f;
f = fopen("reclamation.bin", "rb");
while (fread(&r,sizeof(r),1,f)){
if(strcmp(r.type,"Restauration")==0)
k=k+1;


}fclose(f);

return k;}
int KRnombreh(RECLAMATION r)
{
int h=0;


FILE *f;
f = fopen("reclamation.bin", "rb");
while (fread(&r,sizeof(r),1,f)){
if(strcmp(r.type,"Hébergement")==0)
h=h+1;


}fclose(f);

return h;
}

int KRverifid(char id[30])
{
   RECLAMATION r;
   int res = 1;
   FILE *f;
   f = fopen("reclamation.bin", "ab+");
   if (f != NULL)
   {
      while (fread(&r,sizeof(RECLAMATION),1,f))
      {
         if (strcmp(id,r.identifiant) == 0)
         {
            res = 0;
         }
         else
         {
            res = 1;
         }
      }
   }
   fclose(f);
   return res;
}
int KRveriff(char x[])
{
   int i=0;
   if (strcmp(x, "")==0)
   {
      i=0;
   }
   else
   {
      i=1;
   }
   return i;
}
void KRrandomm(char W[9],RECLAMATION r)
{
    const char alphanum[]="AZERTYUIOPQSDFGHJKLMWXCVBN0123456789";
    int i,j;
    int nb=sizeof(alphanum)-1;
    
    i=0;
    j=0;
FILE *f;
f = fopen("reclamation.bin", "ab+");
while (fread(&r,sizeof(r),1,f))
{
    do
    {
        for(i=0; i<8; i++)
            {
                j=rand()%nb;
                W[i]=alphanum[j];


            }
        W [8]='\0';
        





    }while (strcmp(W,r.identifiant)==0);
    
}
if(strcmp(W,"")==0) {
        for(i=0; i<8; i++)
            {
                j=rand()%nb;
                W[i]=alphanum[j];


            }
        W [8]='\0';
        





    } 

fclose(f);

}


void KRaffichagee(GtkWidget* KRtreeview1111)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
RECLAMATION r;char Date[100];char Dater[100];
store=NULL;
FILE *f;
store=gtk_tree_view_get_model(KRtreeview1111);
if (store==NULL)
{
renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Type", renderer, "text",TYPER, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (KRtreeview1111), column);


renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Identifiant", renderer, "text",IDENTIFIANTR, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (KRtreeview1111), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Nom et Prenom", renderer, "text",NOMR, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (KRtreeview1111), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Cin", renderer, "text",CINR, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (KRtreeview1111), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("problem", renderer, "text",PROBLEMR, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (KRtreeview1111), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Date d'ajout", renderer, "text",DATER, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (KRtreeview1111), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Date de reclamation", renderer, "text",DATER2, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (KRtreeview1111), column);}

store=gtk_list_store_new(COLUMNS2,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f=fopen("reclamation.bin","ab");
if(f==NULL)
{return;}
else
{f=fopen("reclamation.bin","ab+");
while(fread(&r,sizeof(RECLAMATION),1,f))
{
sprintf(Date,"%d/%d/%d",r.datea.jour,r.datea.mois,r.datea.annee);
sprintf(Dater,"%d/%d/%d",r.dater.jour,r.dater.mois,r.dater.annee);

gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,TYPER,r.type,IDENTIFIANTR,r.identifiant,NOMR,r.nom,CINR,r.cin,PROBLEMR,r.problem,DATER,Date,DATER2,Dater,-1);
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(KRtreeview1111),GTK_TREE_MODEL (store));
g_object_unref(store);}}


