#include "header.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <ctype.h>

void idetudiant(char log[] , char Pw[],char idtemp[20]){
FILE *f=NULL;
char ch1[20];
char ch2[20];
char ch3[100];
char ch5[20];
char ch6[20];
f=fopen("admin.txt","r");
if(f!=NULL){
while(fscanf(f,"%s *** %s *** %s *** %s *** %s *** %s *** %s *** %s *** %s\n",ch1,ch2,ch3,ch3,ch3,ch5,ch6,ch3,ch3)!=EOF)
{
if ((strcmp(ch1,log)==0)&&(strcmp(ch2,Pw)==0)&&(strcmp(ch5,"Etudiant")==0))
strcpy(idtemp,ch6);}
fclose(f);}
}
int SMverif(char log[] , char Pw[]){
int trouve=-1;
FILE *f=NULL;
char ch1[20];
char ch2[20];
char ch3[20];
char ch5[20];
char ch6[20];
f=fopen("admin.txt","r");
if(f!=NULL){
while(fscanf(f,"%s *** %s *** %s *** %s *** %s *** %s *** %s *** %s *** %s\n",ch1,ch2,ch3,ch3,ch3,ch5,ch6,ch3,ch3)!=EOF)
{
if ((strcmp(ch1,log)==0)&&(strcmp(ch2,Pw)==0)&&(strcmp(ch5,"Admin")==0))
trouve=1;

else if ((strcmp(ch1,log)==0)&&(strcmp(ch2,Pw)==0)&&(strcmp(ch5,"Etudiant")==0))
trouve=2;

else if ((strcmp(ch1,log)==0)&&(strcmp(ch2,Pw)==0)&&(strcmp(ch5,"Technicien")==0))
trouve=3;

else if ((strcmp(ch1,log)==0)&&(strcmp(ch2,Pw)==0)&&(strcmp(ch5,"Nutritionniste")==0))
trouve=4;

else if ((strcmp(ch1,log)==0)&&(strcmp(ch2,Pw)==0)&&(strcmp(ch5,"Agent_du_foyer")==0))
trouve=5;

else if ((strcmp(ch1,log)==0)&&(strcmp(ch2,Pw)==0)&&(strcmp(ch5,"Agent_du_restaurent")==0))
trouve=6;

else if ((strcmp(ch1,log)==0)&&(strcmp(ch2,Pw)==0)&&(strcmp(ch5,"super")==0))
trouve=7;
}
fclose(f);
}
return trouve;
}

enum{ROLE,IDENTIFIANT,NOM,PRENOM,DATE,CIN,SEXE,MDP,TEL,EMAIL,COLUMNS};

void SMaffichage(GtkWidget* SMTreeviewEtud)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
utilisateur E;
char Nom[100];
char Prenom[100];
char Sexe[100];
char Cin[100];
char Role[100];
char Date[100];
char mddpSM[30]; 
char tel[30];
char emo[30];
store=NULL;
FILE *f;
store=gtk_tree_view_get_model(SMTreeviewEtud);
if (store==NULL)
{
renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Role", renderer, "text",ROLE, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (SMTreeviewEtud), column);}

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Identifiant", renderer, "text",IDENTIFIANT, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (SMTreeviewEtud), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Nom", renderer, "text",NOM, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (SMTreeviewEtud), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Prenom", renderer, "text",PRENOM, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (SMTreeviewEtud), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Date", renderer, "text",DATE, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (SMTreeviewEtud), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Cin", renderer, "text",CIN, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (SMTreeviewEtud), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Sexe", renderer, "text",SEXE, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (SMTreeviewEtud), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("mot de passe", renderer, "text",MDP, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (SMTreeviewEtud), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("telephone", renderer, "text",TEL, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (SMTreeviewEtud), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("email", renderer, "text",EMAIL, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (SMTreeviewEtud), column);







store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f=fopen("utilisateurs.bin","rb");
if(f==NULL)
{return;}
else
{f=fopen("utilisateurs.bin","ab+");
while(fread(&E,sizeof(utilisateur),1,f))
{sprintf(Date,"%d/%d/%d",E.date.jour,E.date.mois,E.date.annee);
sprintf(Nom,"%d",E.nom);
sprintf(Prenom,"%d",E.prenom);
sprintf(Cin,"%d",E.cin);
sprintf(Sexe,"%d",E.sexe);
sprintf(Role,"%d",E.role);
sprintf(mddpSM,"%d",E.mddpSM);
sprintf(tel,"%d",E.telephone);
sprintf(emo,"%d",E.email);
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,ROLE,E.role,IDENTIFIANT,E.identifiant,NOM,E.nom,PRENOM,E.prenom,DATE,Date,CIN,E.cin,SEXE,E.sexe,MDP,E.mddpSM,TEL,E.telephone,EMAIL,E.email,-1);
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(SMTreeviewEtud),GTK_TREE_MODEL (store));
g_object_unref(store);}}

void SMajout (utilisateur E){
FILE*f=NULL; 
f=fopen("utilisateurs.bin","ab+");
fwrite(&E,sizeof(utilisateur),1,f);  
fclose(f);
 
}
int SMverifid(char id[30])
{
   utilisateur E;
   int res = 1;
   FILE *f;
   f = fopen("utlisateurs.bin", "ab+");
   if (f != NULL)
   {
      while (fread(&E,sizeof(utilisateur),1,f))
      {
         if (strcmp(id,E.identifiant) == 0)
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
int SMveriff(char x[])
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

void SMsuppression(char id[30],utilisateur E){
FILE*f;
FILE*g;
f=fopen("utilisateurs.bin","ab+");
g=fopen("SMneww.bin","wb+");

if(g!=NULL){
while(fread(&E,sizeof(utilisateur),1,f))
{
if (strcmp(E.identifiant,id)!=0){
fwrite(&E,sizeof(utilisateur),1,g);

}
}
}fclose(f);
fclose(g);
remove("utilisateurs.bin");
rename("SMneww.bin","utilisateurs.bin");
}


void SMsuppressionn(char id[30],utilisateur E){

FILE *l=NULL;
FILE *k=NULL;
char ch1[20];
char ch2[20];
char ch3[20];
char ch5[20];
char ch9[20];
char ch4[20];
char ch6[20];
char ch7[20];
char ch8[100];
l=fopen("admin.txt","a+");
k=fopen("SMneww.txt","a+");


if(k!=NULL){
while(fscanf(l,"%s *** %s *** %s *** %s *** %s *** %s *** %s *** %s *** %s\n",ch1,ch2,ch3,ch4,ch6,ch5,ch9,ch7,ch8)!=EOF)
{

if (strcmp(ch9,id)!=0){
fprintf(k,"%s *** %s *** %s *** %s *** %s *** %s *** %s *** %s *** %s\n",ch1,ch2,ch3,ch4,ch6,ch5,ch9,ch7,ch8);

}
}
}fclose(l);
fclose(k);
remove("admin.txt");
rename("SMneww.txt","admin.txt");
}

void SMmodification(char id[30],utilisateur E)
{

	SMsuppression(id,E);
        
	SMajout(E);
        
        

}

void SMrecherche(GtkWidget* SMTreeviewEtud)
{
GtkCellRenderer *renderer;
 GtkTreeViewColumn *column;
 GtkTreeIter iter;
 GtkListStore *store;


 FILE *f2;
utilisateur E;
char Nom[100];
char Prenom[100];
char Sexe[100];
char Cin[100];
char Role[100];
char Date[100]; char mddpSM[30];char tel[30];
char emo[30];
store=NULL; 
store=gtk_tree_view_get_model(SMTreeviewEtud);
if (store==NULL)
{
renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Role", renderer, "text",ROLE, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (SMTreeviewEtud), column);}

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Identifiant", renderer, "text",IDENTIFIANT, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (SMTreeviewEtud), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Nom", renderer, "text",NOM, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (SMTreeviewEtud), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Prenom", renderer, "text",PRENOM, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (SMTreeviewEtud), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Date", renderer, "text",DATE, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (SMTreeviewEtud), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Cin", renderer, "text",CIN, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (SMTreeviewEtud), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Sexe", renderer, "text",SEXE, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (SMTreeviewEtud), column);
   
renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("mot de passe", renderer, "text",MDP, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (SMTreeviewEtud), column);
renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("telephone", renderer, "text",TEL, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (SMTreeviewEtud), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("email", renderer, "text",EMAIL, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (SMTreeviewEtud), column);

store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f2=fopen("recherche.bin", "rb");
if(f2==NULL)
{
 return;
}
else 
{ f2=fopen("recherche.bin", "ab+");
    while(fread(&E,sizeof(utilisateur),1,f2))
{sprintf(Date,"%d/%d/%d",E.date.jour,E.date.mois,E.date.annee);
sprintf(Nom,"%d",E.nom);
sprintf(Prenom,"%d",E.prenom);
sprintf(Cin,"%d",E.cin);
sprintf(Sexe,"%d",E.sexe);
sprintf(Role,"%d",E.role);
sprintf(mddpSM,"%d",E.mddpSM);
sprintf(tel,"%d",E.telephone);
sprintf(emo,"%d",E.email);
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,ROLE,E.role,IDENTIFIANT,E.identifiant,NOM,E.nom,PRENOM,E.prenom,DATE,Date,CIN,E.cin,SEXE,E.sexe,MDP,E.mddpSM,TEL,E.telephone,EMAIL,E.email,-1);
}
fclose(f2);
gtk_tree_view_set_model (GTK_TREE_VIEW (SMTreeviewEtud), GTK_TREE_MODEL (store));
g_object_unref (store);
}}


void SMrandomm(char W[9],utilisateur E)
{
    const char alphanum[]="AZERTYUIOPQSDFGHJKLMWXCVBN0123456789";
    int i,j;
    int nb=sizeof(alphanum)-1;
    
    i=0;
    j=0;
FILE *f;
f = fopen("utilisateurs.bin", "ab+");
while (fread(&E,sizeof(E),1,f))
{
    do
    {
        for(i=0; i<8; i++)
            {
                j=rand()%nb;
                W[i]=alphanum[j];


            }
        W [8]='\0';
        





    }while (strcmp(W,E.identifiant)==0);
    
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
int SMcheck(char y[30]){

   
   int indice;
   int correct;
   
       
       correct = 1;
       indice = 0;
       while(y[indice] != '\0')
       {
          
          if (y[indice] < '0' ||y[indice] > '9' )
               correct = 0;

          indice++;
       }
       
    
    return correct;
}



enum{ROLEE,IDENTIFIANTT,NOMM,PRENOMM,CINN,LOGINN,MDPP,APPROUV,TELL,EMAILL,COLUMNSSS};
void adminaffichage(GtkWidget* treeviewappadmin)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

char role[100];
char W[100];
char k[100];
char nom1[100];
char prenom1[100];
char cin1[100];
char login1[100];
char passw[30];char tel[30];
char emo[30]; 
 
store=NULL;
FILE *f=NULL;
FILE *g=NULL;
store=gtk_tree_view_get_model(treeviewappadmin);
if (store==NULL)
{
renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Role", renderer, "text",ROLEE, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (treeviewappadmin), column);}

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Identifiant", renderer, "text",IDENTIFIANTT, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (treeviewappadmin), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Nom", renderer, "text",NOMM, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (treeviewappadmin), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Prenom", renderer, "text",PRENOMM, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (treeviewappadmin), column);


renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Login", renderer, "text",LOGINN, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (treeviewappadmin), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Cin", renderer, "text",CINN, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (treeviewappadmin), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("mot de passe", renderer, "text",MDPP, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (treeviewappadmin), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Approbation", renderer, "text",APPROUV, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (treeviewappadmin), column);


renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("telephone", renderer, "text",TELL, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (treeviewappadmin), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("email", renderer, "text",EMAILL, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (treeviewappadmin), column);




store=gtk_list_store_new(COLUMNSSS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);



  f = fopen("approuv.txt","r");

    if (f==NULL)
    {
      return;
    }
    else{
      
      while ((fscanf(f,"%s *** %s *** %s *** %s *** %s *** %s *** %s *** %s *** %s *** %s\n",&login1,&passw,&nom1,&prenom1,&cin1,&role,&W,&k,&tel,&emo)!=EOF)){

gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,ROLEE,role,IDENTIFIANTT,W,NOMM,nom1,PRENOMM,prenom1,CINN,cin1,LOGINN,login1,MDPP,passw,APPROUV,k,TEL,tel,EMAIL,emo,-1);
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(treeviewappadmin),GTK_TREE_MODEL (store));
g_object_unref(store);}}

void adminapprouver(GtkWidget* treeviewappadmin,char idadmin[30])
{


char role[100];
char W[100];
char k[100];
char nom1[100];
char prenom1[100];
char cin1[100];
char login1[100];
char passw[30];
char approbation[]="approuvee"; 
char ii[]="0000";char tel[30];
char emo[30];

FILE *f=NULL;
FILE *f2=NULL;



  f = fopen("approuv.txt","a+");

    if (f==NULL)
    {
      return;
    }
    else{
      
      while ((fscanf(f,"%s *** %s *** %s *** %s *** %s *** %s *** %s *** %s *** %s *** %s\n",&login1,&passw,&nom1,&prenom1,&cin1,&role,&W,&k,&tel,&emo)!=EOF)){

f2=fopen("admin.txt","a+");
       if  (f2!=NULL)
   {  


if ( ((strcmp(W,idadmin)==0)) && (strcmp(k,"non-approuvee")==0)  )
     {
  suppressionadmin(idadmin);
  fprintf(f2,"%s *** %s *** %s *** %s *** %s *** %s *** %s *** %s *** %s\n",login1,passw,nom1,prenom1,cin1,role,ii,tel,emo);
  mail(emo);
     }
fclose(f2);}

}
fclose(f);
}

if ((strcmp(k,"non-approuvee")==0)  ){
f=fopen("approuv.txt","a+");
if(f!=NULL)
{
fprintf(f,"%s *** %s *** %s *** %s *** %s *** %s *** %s *** %s *** %s *** %s\n",login1,passw,nom1,prenom1,cin1,role,W,approbation,tel,emo);
fclose(f);

}
else printf("\n not found");}



}

void SMrandommadminn(char ad[5])
{
    const char alphanum[]="0123456789";
    int i,j;
    int nb=sizeof(alphanum)-1;
    char role[100];
char W[100];
char k[100];
char nom1[100];
char prenom1[100];
char cin1[100];
char login1[100];
char passw[30]; char tel[30];
char emo[30];
    i=0;
    j=0;
FILE *f=NULL;
f = fopen("approuv.txt", "r+");
 while ((fscanf(f,"%s *** %s *** %s *** %s *** %s *** %s *** %s *** %s *** %s *** %s\n",&login1,&passw,&nom1,&prenom1,&cin1,&role,&W,&k,&tel,&emo)!=EOF))
{
    do
    {
        for(i=0; i<4; i++)
            {
                j=rand()%nb;
                ad[i]=alphanum[j];


            }
        ad [4]='\0';
        





    }while (strcmp(W,ad)==0);
    
}
if(strcmp(ad,"")==0) {
        for(i=0; i<4; i++)
            {
                j=rand()%nb;
                ad[i]=alphanum[j];


            }
        ad [4]='\0';
        





    } 

fclose(f);

}
void suppressionadmin(char idadmin[30]){
   char role[100];
char W[100];
char k[100];
char nom1[100];
char prenom1[100];
char cin1[100];
char login1[100];
char passw[30]; char tel[30];
char emo[30];
FILE*f=NULL;
FILE*g=NULL;
f=fopen("approuv.txt","r+");
g=fopen("neww.txt","w+");
if(g!=NULL){
 while ((fscanf(f,"%s *** %s *** %s *** %s *** %s *** %s *** %s *** %s *** %s *** %s\n",&login1,&passw,&nom1,&prenom1,&cin1,&role,&W,&k,&tel,&emo)!=EOF))
{
if (strcmp(W,idadmin)!=0){
fprintf(g,"%s *** %s *** %s *** %s *** %s *** %s *** %s *** %s *** %s *** %s\n",login1,passw,nom1,prenom1,cin1,role,W,k,tel,emo);


}
}
}fclose(f);
fclose(g);
remove("approuv.txt");
rename("neww.txt","approuv.txt");
}
int cherche( char y[30]){
    int k,indice;
    k=0;
    indice=0;
    while((y[indice] != '\0'))
       {
           if(y[indice]== '@') {k=indice; return k;}
           indice++;
       }
    return k;

}
int invcherche( char y[30]){
    int k,indice;
    k=0;
    indice=strlen(y);
    while(indice>=0)
       {
           if(y[indice]== '@') {k=indice; return k;}
           indice--;
       }
    return k;

}
int checkemail(char y[30]){
    int indice,l,adr,adrr,i=0,calc=0;
    int correct;
    int d=0;
    l=strlen(y);
    correct = 1;
    indice = 0;
    adr=cherche(y);
    adrr=invcherche(y);
    if((adr==0)||(adr!=adrr)){correct=0; return correct;}
    if ((y[l-3]=='.' )|| y[l-4]=='.' ) correct=1;
    else {correct=0; return correct;}

    while((y[indice] != '\0'))
    {
        char c = y[indice];

        int result = isalnum(c);
        int resultat = isalpha(c);
        if ((y[indice]=='@')||(y[indice]=='.')||(y[indice]=='_')||(y[indice]=='-')||(result >0)) correct = 1;
        else {correct=0; return correct;}
        if(y[indice]=='@')calc=1;
        if(calc==1){if(y[indice]=='.') i++;}
        if(i>1){correct=0; return correct;}
        if (indice>adr){
        d++;
        if((resultat >0)||(y[indice]=='.') ) {correct=1;}
        else{correct=0; return correct;}
}

        indice++;

    }

    if(d<6){correct=0; return correct;}
    return correct;
}
void mail(char x [200]){
char all [5000];
char sender [100];
char reciver[100];
char message [100];
strcpy(sender,"sendEmail -f smartesprit.esprit@gmail.com -t ");
strcpy(reciver,x);
strcpy(message,"Bienvenue merci pour votre confiance votre compte a ete active");
sprintf(all,"%s%s -m %s -s 127.0.0.1",sender,reciver,message);
   

system("./sendEmail");
system(all);
}


void mail2(char x [200], char y [100], char z[100]){
char all [5000];
char sender [100];
char reciver[100];
char message [400];
strcpy(sender,"sendEmail -f smartesprit.esprit@gmail.com -t ");
strcpy(reciver,x);
sprintf(message,"'conformément a votre demande  \n login :%s \n mot de passe : %s '",y,z);
sprintf(all,"%s%s -m %s -s 127.0.0.1",sender,reciver,message);
   

system("./sendEmail");
system(all);
}





