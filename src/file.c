#include <stdlib.h>
#include <stdio.h>
#include<string.h>
#include "header.h" 
#include "file.h"

enum{TYPE2,IDENTIFIANT2,MARQUE,DATE2,TIME2,VALEUR2,ETAGE2,COLUMNS2};
enum{TYPEC,ETAGEC,IDENTIFIANTC,MARQUEC,VALEURC,COLUMNSC};

void affichage(GtkWidget* treeview11)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
CAPTEURS c;char Date[100];char Temps[30];
store=NULL;
FILE *f;
store=gtk_tree_view_get_model(treeview11);
if (store==NULL)
{
renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Type", renderer, "text",TYPE2, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (treeview11), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Etage", renderer, "text",ETAGE2, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (treeview11), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("temps", renderer, "text",TIME2, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (treeview11), column);


renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Identifiant", renderer, "text",IDENTIFIANT2, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (treeview11), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Marque", renderer, "text",MARQUE, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (treeview11), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Date", renderer, "text",DATE2, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (treeview11), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Valeur", renderer, "text",VALEUR2, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (treeview11), column);}

store=gtk_list_store_new(COLUMNS2,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f=fopen("capteurs.bin","ab");
if(f==NULL)
{return;}
else
{f=fopen("capteurs.bin","ab+");
while(fread(&c,sizeof(CAPTEURS),1,f))
{sprintf(Date,"%d/%d/%d",c.date.jour,c.date.mois,c.date.annee);
sprintf(Temps,"%d:%d",c.temps.heure,c.temps.minute);
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,TYPE2,c.type,ETAGE2,c.etage,IDENTIFIANT2,c.identifiant,MARQUE,c.marque,DATE2,Date,TIME2,Temps,VALEUR2,c.valeur,-1);
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(treeview11),GTK_TREE_MODEL (store));
g_object_unref(store);}}



void ajout (CAPTEURS c){
FILE*f=NULL; 
f=fopen("capteurs.bin","ab+");
fwrite(&c,sizeof(CAPTEURS),1,f);  
fclose(f);
 
}


void suppression(char id[30],CAPTEURS c){
FILE*f;
FILE*g;
f=fopen("capteurs.bin","ab+");
g=fopen("tmp.bin","wb+");
if(g!=NULL){
while(fread(&c,sizeof(CAPTEURS),1,f))
{
if (strcmp(c.identifiant,id)!=0){
fwrite(&c,sizeof(CAPTEURS),1,g);

}
}
}fclose(f);
fclose(g);
remove("capteurs.bin");
rename("tmp.bin","capteurs.bin");
}



void modification(char id[30],CAPTEURS c)
{

	suppression(id,c);
	ajout(c);

}

void recherche(GtkWidget* treeview11)
{
GtkCellRenderer *renderer;
 GtkTreeViewColumn *column;
 GtkTreeIter iter;
 GtkListStore *store;

store=NULL;CAPTEURS c;
 FILE *f2;char Date[100];char Temps[30]; 
 store=gtk_tree_view_get_model(treeview11);
 if (store==NULL)
{

   renderer=gtk_cell_renderer_text_new();
   column= gtk_tree_view_column_new_with_attributes("Type",renderer, "text",TYPE2,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(treeview11), column);

   renderer = gtk_cell_renderer_text_new ();
   column = gtk_tree_view_column_new_with_attributes("Etage", renderer, "text",ETAGE2, NULL);
   gtk_tree_view_append_column (GTK_TREE_VIEW (treeview11), column);

   renderer=gtk_cell_renderer_text_new();
   column= gtk_tree_view_column_new_with_attributes("Identifiant",renderer, "text",IDENTIFIANT2,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(treeview11), column);

   renderer = gtk_cell_renderer_text_new ();
   column = gtk_tree_view_column_new_with_attributes("temps", renderer, "text",TIME2, NULL);
   gtk_tree_view_append_column (GTK_TREE_VIEW (treeview11), column);

   renderer=gtk_cell_renderer_text_new();
   column= gtk_tree_view_column_new_with_attributes("Marque",renderer, "text",MARQUE,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(treeview11), column);
   
   renderer=gtk_cell_renderer_text_new();
   column= gtk_tree_view_column_new_with_attributes("Date",renderer, "text",DATE2,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(treeview11), column);
   
   renderer=gtk_cell_renderer_text_new();
   column= gtk_tree_view_column_new_with_attributes("Valeur",renderer, "text",VALEUR2,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(treeview11), column);}
  
store=gtk_list_store_new(COLUMNS2,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f2=fopen("recherche.bin", "rb");
if(f2==NULL)
{
 return;
}
else 
{ f2=fopen("recherche.bin", "ab+");
    while(fread(&c,sizeof(CAPTEURS),1,f2))
     {sprintf(Date,"%d/%d/%d",c.date.jour,c.date.mois,c.date.annee);
sprintf(Temps,"%d:%d",c.temps.heure,c.temps.minute);
gtk_list_store_append (store,&iter);
gtk_list_store_set(store,&iter,TYPE2,c.type,ETAGE2,c.etage,IDENTIFIANT2,c.identifiant,MARQUE,c.marque,DATE2,Date,TIME2,Temps,VALEUR2,c.valeur,-1);
}
fclose(f2);
gtk_tree_view_set_model (GTK_TREE_VIEW (treeview11), GTK_TREE_MODEL (store));
g_object_unref (store);
}
}
int nombret(CAPTEURS c)
{
int t=0;
float max1=45, min1=0;

FILE *f;
f = fopen("capteurs.bin", "rb");
while (fread(&c,sizeof(c),1,f)){
if((strcmp(c.type,"cpt temperature")==0)&&((atoi(c.valeur)<min1) || (atoi(c.valeur)>max1)))
t=t+1;


}fclose(f);

return t;
} 
int Mrq_Deff(CAPTEURS c){

int n=0,m=0,p=0,z=0,res=0,x=0;
float max1=45,max2=300,min1=0,min2=10;
FILE *f;
f = fopen("capteurs.bin", "rb");
if(f!=NULL){
while (fread(&c,sizeof(c),1,f)){

	if(strcmp("marque1",c.marque)==0)
	{
	   if( ((strcmp(c.type,"cpt temperature")==0)&&((atoi(c.valeur)<min1) || (atoi(c.valeur)>max1)))||((strcmp(c.type,"cpt pression")==0)&&((atoi(c.valeur)<min2) || (atoi(c.valeur)>max2))) ){n++;}
	}
        else if(strcmp("marque2",c.marque)==0)
	{
	   if( ((strcmp(c.type,"cpt temperature")==0)&&((atoi(c.valeur)<min1) || (atoi(c.valeur)>max1)))||((strcmp(c.type,"cpt pression")==0)&&((atoi(c.valeur)<min2) || (atoi(c.valeur)>max2))) ){m++;}
	}
        else if(strcmp("marque3",c.marque)==0)
	{
	   if( ((strcmp(c.type,"cpt temperature")==0)&&((atoi(c.valeur)<min1) || (atoi(c.valeur)>max1)))||((strcmp(c.type,"cpt pression")==0)&&((atoi(c.valeur)<min2) || (atoi(c.valeur)>max2))) ){p++;}
	}
        else if(strcmp("marque4",c.marque)==0)
	{
	   if( ((strcmp(c.type,"cpt temperature")==0)&&((atoi(c.valeur)<min1) || (atoi(c.valeur)>max1)))||((strcmp(c.type,"cpt pression")==0)&&((atoi(c.valeur)<min2) || (atoi(c.valeur)>max2))) ){z++;}
	}
	
}
}
fclose(f);
if(n>=m && p>=z && n>=p){res=n;}
else if(n>=m && p>=z && n<=p){res=p;}
else if(n<=m && p<=z && m>=z){res=m;}
else {res=z;}

if (res==n){x=1;}
else if (res==m){x=2;}
else if (res==p){x=3;}
else {x=4;}
return x;}
//....................................................................................
int nombrep(CAPTEURS c)
{
int p=0;
float max2=300 ,  min2=10;

FILE *f;
f = fopen("capteurs.bin", "rb");
while (fread(&c,sizeof(c),1,f)){

if((strcmp(c.type,"cpt pression")==0)&&((atoi(c.valeur)<min2 )|| (atoi(c.valeur)>max2)))
p=p+1;
}
fclose(f);

return p;
}


void affichagestat(GtkWidget* treeview12)
{
float max1=45, min1=0,max2=300 ,  min2=10;
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
CAPTEURS c;char Date[100];
store=NULL;
FILE *f;
store=gtk_tree_view_get_model(treeview12);
if (store==NULL)
{
renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Type", renderer, "text",TYPEC, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (treeview12), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Etage", renderer, "text",ETAGEC, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (treeview12), column);


renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Identifiant", renderer, "text",IDENTIFIANTC, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (treeview12), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Marque", renderer, "text",MARQUEC, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (treeview12), column);

renderer=gtk_cell_renderer_text_new();
column= gtk_tree_view_column_new_with_attributes("Valeur",renderer, "text",VALEURC,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(treeview12), column);}

store=gtk_list_store_new(COLUMNSC,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f=fopen("capteurs.bin","rb");
if(f==NULL)
{return;}
else
{f=fopen("capteurs.bin","ab+");
while(fread(&c,sizeof(CAPTEURS),1,f))
{
if( ((strcmp(c.type,"cpt temperature")==0)&&((atoi(c.valeur)<min1) || (atoi(c.valeur)>max1)))||((strcmp(c.type,"cpt pression")==0)&&((atoi(c.valeur)<min2) || (atoi(c.valeur)>max2))) )
{
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,TYPEC,c.type,ETAGEC,c.etage,IDENTIFIANTC,c.identifiant,MARQUEC,c.marque,VALEURC,c.valeur,-1);
}}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(treeview12),GTK_TREE_MODEL (store));
g_object_unref(store);}}


void randomm(char id[9],CAPTEURS c)
{
    const char alphanum[]="AZERTYUIOPQSDFGHJKLMWXCVBN0123456789";
    int i,j;
    int nb=sizeof(alphanum)-1;
    
    i=0;
    j=0;
FILE *f;
f = fopen("capteurs.bin", "ab+");
while (fread(&c,sizeof(c),1,f))
{
    do
    {
        for(i=0; i<8; i++)
            {
                j=rand()%nb;
                id[i]=alphanum[j];


            }
        id [8]='\0';
        





    }while (strcmp(id,c.identifiant)==0);
    
}
if(strcmp(id,"")==0) {
        for(i=0; i<8; i++)
            {
                j=rand()%nb;
                id[i]=alphanum[j];


            }
        id [8]='\0';
        





    } 



fclose(f);

}


int veriff(char x[])
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


int floatt(char y[30])

{
   int indice,i;
   int correct;
       i=0;
       correct = 1;
       indice = 0;
       while(y[indice] != '\0')
       {
          if (y[indice]=='.') {indice++; i++;}
          if (y[indice] < '0' ||y[indice] > '9' || i>1)
               correct = 0;

          indice++;
       }
  
    return correct;
}

enum{TYPE3,ETAGE3,IDENTIFIANT3,TEMPS3,VALEUR3,COLUMNS3};
void affichagestat1(GtkWidget* treeview12)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
CAPTEURS c;char Date[100];char Temps[100];
store=NULL;
FILE *f;
store=gtk_tree_view_get_model(treeview12);
if (store==NULL)
{
renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Type", renderer, "text",TYPE3, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (treeview12), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Etage", renderer, "text",ETAGE3, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (treeview12), column);


renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Identifiant", renderer, "text",IDENTIFIANT3, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (treeview12), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("temps", renderer, "text",TEMPS3, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (treeview12), column);

renderer=gtk_cell_renderer_text_new();
column= gtk_tree_view_column_new_with_attributes("Valeur",renderer, "text",VALEUR3,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(treeview12), column);}

store=gtk_list_store_new(COLUMNS3,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f=fopen("capteurs.bin","rb");
if(f==NULL)
{return;}
else
{f=fopen("capteurs.bin","ab+");
while(fread(&c,sizeof(CAPTEURS),1,f))
{
if(((strcmp(c.type,"cpt fumée")==0)||(strcmp(c.type,"cpt mouvement")==0))&&((c.temps.heure <6) || (c.temps.heure >0))&&(strcmp(c.valeur,"1")==0))
{

system("./sendEmail");
system("sendEmail -f smartesprit.esprit@gmail.com -t protection.civil.tn@gmail.com -m 'alert de securite' -s 127.0.0.1");
sprintf(Temps,"%d:%d",c.temps.heure,c.temps.minute);
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,TYPE3,c.type,ETAGE3,c.etage,IDENTIFIANT3,c.identifiant,TEMPS3,Temps,VALEUR3,c.valeur,-1);
}}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(treeview12),GTK_TREE_MODEL (store));
g_object_unref(store);}}

void affichagestat2(GtkWidget* treeview12)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
CAPTEURS c;char Date[100];char Temps[100];
store=NULL;
FILE *f;
store=gtk_tree_view_get_model(treeview12);
if (store==NULL)
{
renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Type", renderer, "text",TYPE3, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (treeview12), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Etage", renderer, "text",ETAGE3, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (treeview12), column);


renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Identifiant", renderer, "text",IDENTIFIANT3, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (treeview12), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("temps", renderer, "text",TEMPS3, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (treeview12), column);

renderer=gtk_cell_renderer_text_new();
column= gtk_tree_view_column_new_with_attributes("Valeur",renderer, "text",VALEUR3,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(treeview12), column);}

store=gtk_list_store_new(COLUMNS3,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f=fopen("capteurs.bin","rb");
if(f==NULL)
{return;}
else
{f=fopen("capteurs.bin","ab+");
while(fread(&c,sizeof(CAPTEURS),1,f))
{
if((strcmp(c.type,"cpt pression")==0)&&((atoi(c.valeur)<30) || (atoi(c.valeur)>10)))
{
sprintf(Temps,"%d:%d",c.temps.heure,c.temps.minute);
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,TYPE3,c.type,ETAGE3,c.etage,IDENTIFIANT3,c.identifiant,TEMPS3,Temps,VALEUR3,c.valeur,-1);
}}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(treeview12),GTK_TREE_MODEL (store));
g_object_unref(store);}}

