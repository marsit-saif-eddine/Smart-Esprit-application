#include <stdlib.h>
#include <stdio.h>
#include<string.h>
#include "header.h" 
#include "nutro.h"




enum{IDENTIFIANT,DATE,TYPE,GLUTEN,Menu,PP,DESSERT,COLUMNS2};
enum{JOUR,TEMPS,VALEUR,COLUMNSSS};


void DBaffichage(GtkWidget* treeview1)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
MENU M;char Date[100];
store=NULL;
FILE *f;
store=gtk_tree_view_get_model(treeview1);
if (store==NULL)
{
renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Identifiant", renderer, "text",IDENTIFIANT, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (treeview1), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Date", renderer, "text",DATE, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (treeview1), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("FORMULE", renderer, "text",TYPE, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (treeview1), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("REGIME", renderer, "text",GLUTEN, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (treeview1), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("ENTREE", renderer, "text",Menu, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (treeview1), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("PLAT PRINCIPAL", renderer, "text",PP, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (treeview1), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("DESSERT", renderer, "text",DESSERT, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (treeview1), column);


}






store=gtk_list_store_new(COLUMNS2,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f=fopen("menu.bin","ab");
if(f==NULL)
{return;}
else
{f=fopen("menu.bin","ab+");
while(fread(&M,sizeof(MENU),1,f))
{sprintf(Date,"%d/%d/%d",M.date.jour,M.date.mois,M.date.annee);
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,IDENTIFIANT,M.identifiant,DATE,Date,TYPE,M.type,GLUTEN,M.gluten,Menu,M.menu,PP,M.pp,DESSERT,M.dessert,-1);
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(treeview1),GTK_TREE_MODEL (store));
g_object_unref(store);}}




void DBajout (MENU M)
{
FILE*f=NULL; 
f=fopen("menu.bin","ab+");
fwrite(&M,sizeof(MENU),1,f);  
fclose(f);
}




void DBsuppression(char id[30],MENU M)
{
FILE*f;
FILE*g;
f=fopen("menu.bin","ab+");
g=fopen("tmp.bin","wb+");
if(g!=NULL){
while(fread(&M,sizeof(MENU),1,f))
{
if (strcmp(M.identifiant,id)!=0){
fwrite(&M,sizeof(MENU),1,g);

}
}
}fclose(f);
fclose(g);
remove("menu.bin");
rename("tmp.bin","menu.bin");
}


void DBmodification(char id[30],MENU M)
{

	DBsuppression(id,M);
	DBajout(M);

}


void DBrecherche(GtkWidget* treeview1)
{
GtkCellRenderer *renderer;
 GtkTreeViewColumn *column;
 GtkTreeIter iter;
 GtkListStore *store;

store=NULL;MENU M;
 FILE *f2;char Date[100]; 
 store=gtk_tree_view_get_model(treeview1);
 if (store==NULL)
{

  renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Identifiant", renderer, "text",IDENTIFIANT, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (treeview1), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Date", renderer, "text",DATE, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (treeview1), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("FORMULE", renderer, "text",TYPE, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (treeview1), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("REGIME", renderer, "text",GLUTEN, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (treeview1), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("ENTREE", renderer, "text",Menu, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (treeview1), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("PLAT PRINCIPAL", renderer, "text",PP, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (treeview1), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("DESSERT", renderer, "text",DESSERT, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (treeview1), column);
}
  
store=gtk_list_store_new(COLUMNS2,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f2=fopen("recherche.bin", "rb");
if(f2==NULL)
{
 return;
}
else 
{ f2=fopen("recherche.bin", "ab+");
    while(fread(&M,sizeof(MENU),1,f2))
     {sprintf(Date,"%d/%d/%d",M.date.jour,M.date.mois,M.date.annee);
gtk_list_store_append (store,&iter);
gtk_list_store_set(store,&iter,IDENTIFIANT,M.identifiant,DATE,Date,TYPE,M.type,GLUTEN,M.gluten,Menu,M.menu,PP,M.pp,DESSERT,M.dessert,-1);
}
fclose(f2);
gtk_tree_view_set_model (GTK_TREE_VIEW (treeview1), GTK_TREE_MODEL (store));
g_object_unref (store);
}
}


int DBverifid(char id[30])
{
   MENU M;
   int res = 1;
   FILE *f;
   f = fopen("menu.bin", "ab+");
   if (f != NULL)
   {
      while (fread(&M,sizeof(MENU),1,f))
      {
         if (strcmp(id,M.identifiant) == 0)
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
int DBveriff(char x[])
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

void DBaffichage_stat (GtkWidget *liste)
{GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store; 
  
dechet D;
char format[40];
char x[30];
char a[10];
char y[30];
char b[10];
char z[30];
char c[10];
strcpy(a,"1");
strcpy(b,"2");
strcpy(c,"3");

DBmin (x,a);
DBmin (y,b);
DBmin (z,c);


  FILE *f;
	
  store=gtk_tree_view_get_model(liste);

  if (store==NULL)
  {


    renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes("jour",renderer,"text",JOUR,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

    renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes("temps",renderer,"text",TEMPS,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

    renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes("valeur",renderer,"text",VALEUR,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);



   store=gtk_list_store_new(COLUMNSSS,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

 

  f = fopen("dechets.txt","r");

    if (f==NULL)
    
      {return;}
    
    else{
      
      while ((fscanf(f," %s\t %s\t %s \n",&D.jour,&D.temps,&D.valeur)!=EOF)){
if(((strcmp(D.temps,a)==0)&&(strcmp(D.valeur,x)==0))||((strcmp(D.temps,b)==0)&&(strcmp(D.valeur,y)==0))||((strcmp(D.temps,c)==0)&&(strcmp(D.valeur,z)==0))){
if (strcmp(D.valeur,x)==0){strcpy(format,"Petit déj");}
else if (strcmp(D.valeur,y)==0){strcpy(format,"Déjeuner");}
else if (strcmp(D.valeur,z)==0){strcpy(format,"Dinner");}
       gtk_list_store_append(store, &iter);
				gtk_list_store_set(store,&iter,JOUR,D.jour,TEMPS,format,VALEUR,D.valeur, -1);
}

      }
      fclose(f);
	


      gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
		  g_object_unref(store);



}
}
}


void DBmin (char x[30], char k[10])
{
dechet D;
FILE *f;
 f = fopen("dechets.txt","r");

    if (f==NULL)
    {
      return;
    }
    else{
      fscanf(f," %s\t %s\t %s \n",&D.jour,&D.temps,&D.valeur);
      strcpy(x,D.valeur);
      
      while ((fscanf(f," %s\t %s\t %s \n",&D.jour,&D.temps,&D.valeur)!=EOF)){
        
	if ((strcmp(D.temps,k)==0)&&(atof(D.valeur))<(atof(x)))
	{strcpy(x,D.valeur);}

}}}



void DBrandomm(char W[9],MENU M)
{
    const char alphanum[]="AZERTYUIOPQSDFGHJKLMWXCVBN0123456789";
    int i,j;
    int nb=sizeof(alphanum)-1;
    
    i=0;
    j=0;
FILE *f;
f = fopen("menu.bin", "ab+");
while (fread(&M,sizeof(M),1,f))
{
    do
    {
        for(i=0; i<8; i++)
            {
                j=rand()%nb;
                W[i]=alphanum[j];


            }
        W [8]='\0';
        





    }while (strcmp(W,M.identifiant)==0);
    
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












