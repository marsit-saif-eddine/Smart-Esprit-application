#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "header.h"
#include "rec.h"
#include "file.h"
#include "filestock.h"
#include "nutro.h"
#include "utilisateurs.h"

char idadmin[30],id[30],idrech[30],mailadmin[50],idtemp[20];
GtkWidget *SMWindowutil;
GtkWidget *SMWindowAjout;
GtkWidget *SMWindowLogin;
GtkWidget *SMwindowmodif;
GtkWidget *SMwindowinscrii;
GtkWidget *SMAccueil;
GtkWidget *window4;
int mad=1;
int aad=0;
int lad=0;
int kad=0;


void
on_SMcheckbutton_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton)){
lad=1;}
}


void
on_SMcheckbutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton)){
kad=1;}
}

void
on_SMradiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))){
mad=1;}
}


void
on_SMradiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))){
mad=2;}
}
void
on_SMbuttonAjout_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowskipo;

windowskipo=create_SMWindowAjout();
gtk_widget_show (windowskipo);


}


void
on_SMbuttonAjouter_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
char Role[30];char x[30];char Sexe[30];char lid[20];char W[9];
char test[30];char testt[30];char testtt[30];char testttt[20];char testtttt[30];char testttttt[30] ;char tel[30];char emo[30];
FILE *f=NULL;
utilisateur E;

GtkWidget *SMentryNom;
GtkWidget *SMentryprenom;
GtkWidget *SMentrycin;
GtkWidget *SMcomboboxentryrole;
GtkWidget *SMradiobutton1;
GtkWidget *SMradiobutton2;
GtkWidget *SMspinbuttonday;
GtkWidget *SMspinbuttonmonth;
GtkWidget *SMspinbuttonyear;
GtkWidget *sortiea;
GtkWidget *alert1;
GtkWidget *SMbien_ajout;
GtkWidget *windowskipppp;
GtkWidget *SMmddp;
GtkWidget *SMalert3;
GtkWidget *entryemail;
GtkWidget *entrytelephone;

entryemail=lookup_widget(button, "entryemail");
entrytelephone=lookup_widget(button, "entrytelephone");
SMalert3=lookup_widget(button,"SMalert3");
SMspinbuttonday=lookup_widget(button, "SMspinbuttonday");
SMspinbuttonmonth=lookup_widget(button, "SMspinbuttonmonth");
SMspinbuttonyear=lookup_widget(button, "SMspinbuttonyear");
SMradiobutton1=lookup_widget(button, "SMradiobutton1");
SMradiobutton2=lookup_widget(button, "SMradiobutton2");
SMcomboboxentryrole=lookup_widget(button, "SMcomboboxentryrole");
SMentrycin=lookup_widget(button, "SMentrycin");
SMentryNom=lookup_widget(button, "SMentryNom");
SMentryprenom=lookup_widget(button, "SMentryprenom");
sortiea=lookup_widget(button, "SMlabelmsgsucc");
alert1=lookup_widget(button, "SMlabelajoutalertid");
SMmddp=lookup_widget(button, "SMmddp");



  SMrandomm(W,E);

strcpy(x,W);


	
strcpy(E.identifiant,x);

strcpy(E.telephone,gtk_entry_get_text(GTK_ENTRY(entrytelephone)));
strcpy(tel,gtk_entry_get_text(GTK_ENTRY(entrytelephone)));

strcpy(E.email,gtk_entry_get_text(GTK_ENTRY(entryemail)));
strcpy(emo,gtk_entry_get_text(GTK_ENTRY(entryemail)));

strcpy(E.mddpSM,gtk_entry_get_text(GTK_ENTRY(SMmddp)));
strcpy(test,gtk_entry_get_text(GTK_ENTRY(SMmddp)));


strcpy(E.nom,gtk_entry_get_text(GTK_ENTRY(SMentryNom)));
strcpy(testt,gtk_entry_get_text(GTK_ENTRY(SMentryNom)));

strcpy(E.prenom,gtk_entry_get_text(GTK_ENTRY(SMentryprenom)));
strcpy(testtt,gtk_entry_get_text(GTK_ENTRY(SMentryprenom)));

strcpy(E.cin,gtk_entry_get_text(GTK_ENTRY(SMentrycin)));
strcpy(testttt,gtk_entry_get_text(GTK_ENTRY(SMentrycin)));

E.date.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(SMspinbuttonday));
E.date.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(SMspinbuttonmonth));
E.date.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(SMspinbuttonyear));


if(mad==1)strcpy(Sexe,"Homme");
else if (mad==2) strcpy(Sexe,"Femme");
strcpy(E.sexe,Sexe);

strcpy(Role,gtk_combo_box_get_active_text(GTK_COMBO_BOX(SMcomboboxentryrole)));
strcpy(E.role,Role);
strcpy(testtttt,Role);

if ((SMveriff(test)==0)||(SMveriff(testt)==0)||(SMveriff(testtt)==0)||(SMveriff(testttt)==0)||(SMveriff(testtttt)==0)||(SMveriff(tel)==0)||(SMveriff(emo)==0)){gtk_label_set_text(GTK_LABEL(SMalert3),"champs obligatoires!");}
else if (SMcheck(testttt)==0 || strlen(testttt)!=8){gtk_label_set_text(GTK_LABEL(SMalert3),"il faut entrer une vrai CIN!");}
else if (checkemail(emo) == 0){gtk_label_set_text(GTK_LABEL(SMalert3),"il faut entrer un vrai email!");}
else if (SMcheck(tel)==0 || strlen(tel)!=8){gtk_label_set_text(GTK_LABEL(SMalert3),"il faut entrer un vrai numero tel!");}
else if (lad==0){gtk_label_set_text(GTK_LABEL(SMalert3),"il faut cocher le SMcheckbuton!");}
else if((SMveriff(test)==1)||(SMveriff(testt)==1)||(SMveriff(testtt)==1)||(SMveriff(testttt)==1)||(SMveriff(testtttt)==1)||(SMveriff(tel)==1)||(SMveriff(emo)==1)&& (lad==1)){
f=fopen("admin.txt","a+");
if(f!=NULL)
{
SMajout(E);
mail(emo);
fprintf(f,"%s *** %s *** %s *** %s *** %s *** %s *** %s *** %s *** %s\n",testt,test,testt,testtt,testttt,testtttt,x,tel,emo);
fclose(f);
lad=0;
}
else printf("\n not found");




windowskipppp = lookup_widget(button,"SMWindowAjout");
gtk_widget_destroy(windowskipppp);
SMbien_ajout=create_SMbienajout();
gtk_widget_show (SMbien_ajout);


}mad=1;}


void
on_SMbuttonutil_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_buttongen_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_SMbuttonSign_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
FILE *f=NULL;
GtkWidget *login,*pw, *windowespaceadmin,*windowskippp,*windowpp,*AMWindowutil,*page_principale,*windowahmedpp;
char user[20];
char pass[20];
int trouve;

login = lookup_widget (button, "SMentrylogg");
pw = lookup_widget (button, "SMentrymdpp");

strcpy(user, gtk_entry_get_text(GTK_ENTRY(login)));
strcpy(pass, gtk_entry_get_text(GTK_ENTRY(pw)));

trouve=SMverif(user,pass);
if(trouve==1)
{
windowskippp = lookup_widget(button,"SMWindowLogin");
gtk_widget_destroy(windowskippp);
windowespaceadmin=create_SMAccueil();
gtk_widget_show (windowespaceadmin);

}
else if(trouve==3)
{
windowskippp = lookup_widget(button,"SMWindowLogin");
gtk_widget_destroy(windowskippp);
windowpp=create_windowpp();
gtk_widget_show (windowpp);

}
else if(trouve==2)
{

windowskippp = lookup_widget(button,"SMWindowLogin");
gtk_widget_destroy(windowskippp);
page_principale=create_page_principale();
gtk_widget_show (page_principale);
idetudiant(user,pass,idtemp);
}
else if(trouve==5)
{
windowskippp = lookup_widget(button,"SMWindowLogin");
gtk_widget_destroy(windowskippp);
AMWindowutil=create_AMWindowutil();
gtk_widget_show (AMWindowutil);

}
else if(trouve==4)
{

windowskippp = lookup_widget(button,"SMWindowLogin");
gtk_widget_destroy(windowskippp);
windowpp=create_DBwindowpp();
gtk_widget_show (windowpp);
}
else if(trouve==6)
{

windowskippp = lookup_widget(button,"SMWindowLogin");
gtk_widget_destroy(windowskippp);
windowpp=create_windowahmedpp();
gtk_widget_show (windowpp);
}

else if(trouve==7)
{

windowskippp = lookup_widget(button,"SMWindowLogin");
gtk_widget_destroy(windowskippp);
windowpp=create_window4();
gtk_widget_show (windowpp);
}

else if(trouve==0)
{

windowskippp = lookup_widget(button,"SMWindowLogin");
gtk_widget_destroy(windowskippp);
windowahmedpp=create_windowahmedpp();
gtk_widget_show (windowahmedpp);
}


}


void
on_SMbuttoninscrire_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget  *windowin,*windowskipp;
windowskipp = lookup_widget(button,"SMWindowLogin");
gtk_widget_destroy(windowskipp);
windowin=create_SMwindowinscrii();
gtk_widget_show (windowin);
}


void
on_SMButtonmodier_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
char Rolee[30];char x[30];char Sexee[30];
utilisateur E;
GtkWidget *SMmodifid;
GtkWidget *SMmodifNom;
GtkWidget *SMmodifprenom;
GtkWidget *SMmodifcin;
GtkWidget *SMcomboboxmodifrole;
GtkWidget *comboboxmodifsex;
GtkWidget *SMspinbuttondaymodif;
GtkWidget *SMspinbuttonmonthmodif;
GtkWidget *SMspinbuttonyearmodif;
GtkWidget *sortieamodif;
GtkWidget *alert1modif;
GtkWidget *SMentry1;
GtkWidget *entryemailmodif;
GtkWidget *entrytelephonemodif;
char test[30];char testt[30];char testtt[30];char testttt[20];char testtttt[30];char testttttt[30];char tel[30];char emo[30];
FILE *f=NULL;
entryemailmodif=lookup_widget(button, "entryemailmodif");
entrytelephonemodif=lookup_widget(button, "entrytelephonemodif");
SMspinbuttondaymodif=lookup_widget(button, "SMspinbuttonjour");
SMspinbuttonmonthmodif=lookup_widget(button, "SMspinbuttonmois");
SMspinbuttonyearmodif=lookup_widget(button, "SMspinbuttonannee");
comboboxmodifsex=lookup_widget(button, "SMcomboboxentryse");
SMcomboboxmodifrole=lookup_widget(button, "SMcomboboxentryrol");
SMmodifcin=lookup_widget(button, "SMentryci");
SMmodifNom=lookup_widget(button, "SMentrynomm");
SMmodifprenom=lookup_widget(button, "SMentryprenomm");
sortieamodif=lookup_widget(button, "SMlabelmsgsucc");
alert1modif=lookup_widget(button, "SMlabelajoutalertid");
SMentry1=lookup_widget(button, "SMentry1");
strcpy(E.mddpSM,gtk_entry_get_text(GTK_ENTRY(SMentry1)));
strcpy(test,gtk_entry_get_text(GTK_ENTRY(SMentry1)));
strcpy(E.identifiant,id);
strcpy(E.nom,gtk_entry_get_text(GTK_ENTRY(SMmodifNom)));
strcpy(testt,gtk_entry_get_text(GTK_ENTRY(SMmodifNom)));

strcpy(E.prenom,gtk_entry_get_text(GTK_ENTRY(SMmodifprenom)));
strcpy(testtt,gtk_entry_get_text(GTK_ENTRY(SMmodifprenom)));

strcpy(E.cin,gtk_entry_get_text(GTK_ENTRY(SMmodifcin)));
strcpy(testttt,gtk_entry_get_text(GTK_ENTRY(SMmodifcin)));

strcpy(E.telephone,gtk_entry_get_text(GTK_ENTRY(entrytelephonemodif)));
strcpy(tel,gtk_entry_get_text(GTK_ENTRY(entrytelephonemodif)));

strcpy(E.email,gtk_entry_get_text(GTK_ENTRY(entryemailmodif)));
strcpy(emo,gtk_entry_get_text(GTK_ENTRY(entryemailmodif)));

E.date.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(SMspinbuttondaymodif));
E.date.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(SMspinbuttonmonthmodif));
E.date.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(SMspinbuttonyearmodif));

strcpy(Sexee,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxmodifsex)));
strcpy(E.sexe,Sexee);

strcpy(Rolee,gtk_combo_box_get_active_text(GTK_COMBO_BOX(SMcomboboxmodifrole)));
strcpy(E.role,Rolee);
strcpy(testtttt,Rolee);
if ((SMveriff(test)==0)||(SMveriff(testt)==0)||(SMveriff(testtt)==0)||(SMveriff(testttt)==0)||(SMveriff(testtttt)==0)||(SMveriff(Sexee)==0)||(SMveriff(tel)==0)||(SMveriff(emo)==0)){gtk_label_set_text(GTK_LABEL(sortieamodif),"champs obligatoires!");}
else if (SMcheck(testttt)==0 || strlen(testttt)!=8){gtk_label_set_text(GTK_LABEL(sortieamodif),"il faut entrer une vrai CIN!");}
else if (checkemail(emo) == 0){gtk_label_set_text(GTK_LABEL(sortieamodif),"il faut entrer un vrai email!");}
else if (SMcheck(tel)==0 || strlen(tel)!=8){gtk_label_set_text(GTK_LABEL(sortieamodif),"il faut entrer un vrai numero tel!");}
else if (kad==0){gtk_label_set_text(GTK_LABEL(sortieamodif),"il faut cocher le SMcheckbuton!");}
else if((SMveriff(test)==1)||(SMveriff(testt)==1)||(SMveriff(testtt)==1)||(SMveriff(testttt)==1)||(SMveriff(testtttt)==1)||(SMveriff(Sexee)==1)||(SMveriff(tel)==1)||(SMveriff(emo)==1)&& (kad==1)){
f=fopen("admin.txt","a+");
if(f!=NULL)
{
SMsuppressionn(id,E);
SMmodification(id,E);



}
f=fopen("admin.txt","a+");
if(f!=NULL)
{
fprintf(f,"%s *** %s *** %s *** %s *** %s *** %s *** %s *** %s *** %s\n",testt,test,testt,testtt,testttt,testtttt,id,tel,emo);
fclose(f);
kad=0;
}
else printf("\n not found");

gtk_label_set_text(GTK_LABEL(sortieamodif),"Modification effectuée avec succès!");

}}



void
on_buttonEM_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_buttonAD_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_buttonsupp_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{


}


/*void
on_SMInscributton_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{

FILE *f=NULL;
GtkWidget *login,*pw,*pww ,*nom,*prenom,*cin, *windowAuth,*windowskip;
GtkWidget *alert2;
char login1[20];
char passw[20];
char passw2[20];
char nom1[20];
char prenom1[20];
char cin1[20];
char role[]="Admin";char W[]="0000";
alert2=lookup_widget(button, "SMlabelalertrechh");
login = lookup_widget (button, "SMentryloginn");
pw = lookup_widget (button, "SMentrymddp");
pww = lookup_widget (button, "SMentryre");
nom = lookup_widget (button, "SMentrynomm");
prenom = lookup_widget (button, "SMentryprenomm");
cin = lookup_widget (button, "SMentrycinn");

strcpy(login1, gtk_entry_get_text(GTK_ENTRY(login)));
strcpy(passw, gtk_entry_get_text(GTK_ENTRY(pw)));
strcpy(passw2, gtk_entry_get_text(GTK_ENTRY(pww)));
strcpy(nom1, gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(prenom1, gtk_entry_get_text(GTK_ENTRY(prenom)));
strcpy(cin1, gtk_entry_get_text(GTK_ENTRY(cin)));

if ((SMveriff(login1)==0)||(SMveriff(prenom1)==0)||(SMveriff(passw)==0)||(SMveriff(cin1)==0)||(SMveriff(nom1)==0)||(SMveriff(passw2)==0)){gtk_label_set_text(GTK_LABEL(alert2),"champs obligatoires!");}
else if (SMcheck(cin1)==0 || strlen(cin1)!=8){gtk_label_set_text(GTK_LABEL(alert2),"il faut entrer une vrai CIN!");}
else if (strcmp(passw2,passw)!=0){gtk_label_set_text(GTK_LABEL(alert2),"il faut retapez le mot de passe correctement!");}
else if((SMveriff(login1)==1)||(SMveriff(prenom1)==1)||(SMveriff(passw)==1)||(SMveriff(cin1)==1)||(SMveriff(nom1)==1)){
f=fopen("admin.txt","a+");
if(f!=NULL)
{
fprintf(f,"%s *** %s *** %s *** %s *** %s *** %s *** %s\n",login1,passw,nom1,prenom1,cin1,role,W);
fclose(f);

}
else printf("\n not found");
windowskip = lookup_widget(button,"SMwindowinscrii");
gtk_widget_destroy(windowskip);
windowAuth=create_SMWindowLogin();
gtk_widget_show (windowAuth);
}



}*/
void
on_SMInscributton_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{

FILE *f=NULL;
GtkWidget *login,*pw,*pww ,*nom,*prenom,*cin, *windowAuth,*windowskip;
GtkWidget *alert2;
GtkWidget *entryemailinscri;
GtkWidget *entrytelephoneinscri;
char login1[20];
char passw[20];
char passw2[20];
char nom1[20];
char prenom1[20];
char cin1[20];
char role[]="Admin";
char approbation[]="non-approuvee";char W[5];char ad[5];char tel[30];char emo[30];
alert2=lookup_widget(button, "SMlabelalertrechh");
login = lookup_widget (button, "SMentryloginn");
pw = lookup_widget (button, "SMentrymddp");
pww = lookup_widget (button, "SMentryre");
nom = lookup_widget (button, "SMentrynomm");
prenom = lookup_widget (button, "SMentryprenomm");
cin = lookup_widget (button, "SMentrycinn");
entryemailinscri=lookup_widget(button, "entryemailinscri");
entrytelephoneinscri=lookup_widget(button, "entrytelephoneinscri");
strcpy(login1, gtk_entry_get_text(GTK_ENTRY(login)));
strcpy(passw, gtk_entry_get_text(GTK_ENTRY(pw)));
strcpy(passw2, gtk_entry_get_text(GTK_ENTRY(pww)));
strcpy(nom1, gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(prenom1, gtk_entry_get_text(GTK_ENTRY(prenom)));
strcpy(cin1, gtk_entry_get_text(GTK_ENTRY(cin)));

strcpy(tel,gtk_entry_get_text(GTK_ENTRY(entrytelephoneinscri)));
strcpy(emo,gtk_entry_get_text(GTK_ENTRY(entryemailinscri)));
SMrandommadminn(ad);

strcpy(W,ad);
if ((SMveriff(login1)==0)||(SMveriff(prenom1)==0)||(SMveriff(passw)==0)||(SMveriff(cin1)==0)||(SMveriff(nom1)==0)||(SMveriff(passw2)==0)||(SMveriff(tel)==0)||(SMveriff(emo)==0)){gtk_label_set_text(GTK_LABEL(alert2),"champs obligatoires!");}
else if (SMcheck(cin1)==0 || strlen(cin1)!=8){gtk_label_set_text(GTK_LABEL(alert2),"il faut entrer une vrai CIN!");}

else if (strcmp(passw2,passw)!=0){gtk_label_set_text(GTK_LABEL(alert2),"il faut retapez le mot de passe correctement!");}
else if (checkemail(emo)==0){gtk_label_set_text(GTK_LABEL(alert2),"il faut entrer un vrai email!");}
else if (SMcheck(tel)==0 || strlen(tel)!=8){gtk_label_set_text(GTK_LABEL(alert2),"il faut entrer un vrai numero tel!");}
else if((SMveriff(login1)==1)||(SMveriff(prenom1)==1)||(SMveriff(passw)==1)||(SMveriff(cin1)==1)||(SMveriff(nom1)==1)||(SMveriff(tel)==1)||(SMveriff(emo)==1)){
f=fopen("approuv.txt","a+");
if(f!=NULL)
{
fprintf(f,"%s *** %s *** %s *** %s *** %s *** %s *** %s *** %s *** %s *** %s\n",login1,passw,nom1,prenom1,cin1,role,W,approbation,tel,emo);
fclose(f);

}
else printf("\n not found");
windowskip = lookup_widget(button,"SMwindowinscrii");
gtk_widget_destroy(windowskip);
windowAuth=create_SMWindowLogin();
gtk_widget_show (windowAuth);
}



}


void
on_SMTreeviewEtud_row_activated        (GtkTreeView     *SMTreeviewEtud,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
	gchar* identifiant;
	GtkTreeModel *Model = gtk_tree_view_get_model(SMTreeviewEtud);

		if (gtk_tree_model_get_iter(Model, &iter, path)){
				gtk_tree_model_get(GTK_LIST_STORE(Model),&iter,1,&identifiant, -1);
				strcpy(id,identifiant);}

}


void
on_SMbuttonactualiser_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *SMtreeview;
SMWindowutil=lookup_widget(button,"SMWindowutil");
SMtreeview=lookup_widget(SMWindowutil,"SMTreeviewEtud");
SMaffichage(SMtreeview);

}


void
on_SMbuttonSupprimer_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
utilisateur E;
	    GtkWidget *SMtreeview;
            SMWindowutil=lookup_widget(button,"SMWindowutil");
	    SMtreeview=lookup_widget(SMWindowutil,"SMTreeviewEtud");
	    SMsuppression(id,E);
            SMsuppressionn(id,E);
            SMaffichage(SMtreeview);

}


void
on_SMbuttonModif_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *SMentrymodi;
GtkWidget *Windwskippoo;
		SMentrymodi=lookup_widget(button,"SMentrymodi");
                
                Windwskippoo=create_SMwindowmodifierr();
                gtk_widget_show (Windwskippoo);	
		gtk_entry_set_text(GTK_ENTRY(SMentrymodi),id);






}


void
on_SMbuttonchercher_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
utilisateur E;
GtkWidget *windowskipoi;
GtkWidget *SMentrychercher;
GtkWidget *SMTreeviewEtud;
GtkWidget *alert2;
FILE*f;
FILE*f2;
alert2=lookup_widget(button, "SMlabelalertrech");
windowskipoi=lookup_widget(button,"SMWindowutil");
SMentrychercher=lookup_widget(button,"SMentrychercher");
strcpy(idrech,gtk_entry_get_text(GTK_ENTRY(SMentrychercher)));
if (SMveriff(idrech)==0){gtk_label_set_text(GTK_LABEL(alert2),"Champs obligatoire!");}
else if (SMveriff(idrech)==1){
f=fopen("utilisateurs.bin","rb");

 if(f!=NULL)
 {
  while(fread(&E,sizeof(utilisateur),1,f))
     {
       f2=fopen("recherche.bin","ab+");
       if  (f2!=NULL)
   {  
     
     if (((strcmp(E.cin,idrech)==0))||((strcmp(E.nom,idrech)==0)) ||((strcmp(E.prenom,idrech)==0)) )
     { 
     fwrite(&E,sizeof(utilisateur),1,f2);
     }
   
     SMTreeviewEtud=lookup_widget(windowskipoi,"SMTreeviewEtud");
     SMrecherche(SMTreeviewEtud);
    
        fclose(f2);
    }

 }
 fclose(f);
}
remove("recherche.bin");}

}


void
on_SMbuttonpanne_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
/*
GtkWidget *pannetreeview;
SMWindowutil=lookup_widget(button,"SMwindowpanne");
pannetreeview=lookup_widget(SMWindowutil,"pannetreeview");
SMaffichagepanne(pannetreeview);*/
}




void
on_SMbien_ajout_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowskippppp;

windowskippppp = lookup_widget(button,"SMbienajout");
gtk_widget_destroy(windowskippppp);


}


void
on_SMbien_supp_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{

}




void
on_SMbutton9_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowespaceadmin,*windowskippp;
windowskippp = lookup_widget(button,"SMAccueil");
gtk_widget_destroy(windowskippp);
windowespaceadmin=create_SMWindowutil();
gtk_widget_show (windowespaceadmin);
}


void
on_SMbutton10_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowespaceadmin,*windowskippp;
windowskippp = lookup_widget(button,"SMWindowutil");
gtk_widget_destroy(windowskippp);
windowespaceadmin=create_SMAccueil();
gtk_widget_show (windowespaceadmin);
}



//----------------------------------------------------capteur--------------------------------------------------


char id[30],idrech[30];
GtkWidget *windowpp;
GtkWidget *windowstat;
GtkWidget *windowajout;
GtkWidget *windowmodif;
int n=1,mca=1,o;

void
on_button_cnx_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_buttonmenucp_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
	 // windowpp = lookup_widget(button,"windowpp");//
         // gtk_widget_destroy(windowpp);//
         // windowlogin = create_windowlogin()//
         // gtk_widget_show(windowlogin);//

}


void
on_buttonrecherchrer_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
CAPTEURS c;
GtkWidget *entryid;
GtkWidget *treeview11;
FILE*f;
FILE*f2;


windowpp=lookup_widget(button,"windowpp");
entryid=lookup_widget(button,"entryid");
strcpy(idrech,gtk_entry_get_text(GTK_ENTRY(entryid)));
f=fopen("capteurs.bin","rb");

 if(f!=NULL)
 {
  while(fread(&c,sizeof(CAPTEURS),1,f))
     {
       f2=fopen("recherche.bin","ab+");
       if  (f2!=NULL)
   {  
     
     if (((strcmp(c.identifiant,idrech)==0))||((strcmp(c.type,idrech)==0))||((strcmp(c.marque,idrech)==0)))
     { 
     fwrite(&c,sizeof(CAPTEURS),1,f2);
     }
   
     treeview11=lookup_widget(windowpp,"treeview11");
     recherche(treeview11);
    
        fclose(f2);
    }

 }
 fclose(f);
}
remove("recherche.bin");
}


void
on_treeview11_row_activated            (GtkTreeView     *treeview11,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
	gchar* identifiant;
	GtkTreeModel *Model = gtk_tree_view_get_model(treeview11);

		if (gtk_tree_model_get_iter(Model, &iter, path)){
				gtk_tree_model_get(GTK_LIST_STORE(Model),&iter,1,&identifiant, -1);
				strcpy(id,identifiant);}
}


void
on_buttonsupprimer_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
CAPTEURS c;
	    GtkWidget *treeview11;
	    windowpp=lookup_widget(button,"windowpp");
	    treeview11=lookup_widget(windowpp,"treeview11");
	    suppression(id,c);
            affichage(treeview11);
}


void
on_buttonmodifier_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowmodif,*windowpp;
windowpp = lookup_widget(button,"windowpp");
gtk_widget_destroy(windowpp);

windowmodif=create_windowmodif();
gtk_widget_show (windowmodif);
}


void
on_buttonactualiser_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview11;
windowpp=lookup_widget(button,"windowpp");
treeview11=lookup_widget(windowpp,"treeview11");
affichage(treeview11);
}


void
on_buttonboard_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowstat,*windowpp;
windowpp = lookup_widget(button,"windowpp");
gtk_widget_destroy(windowpp);
windowstat=create_windowstat();
gtk_widget_show (windowstat);
}


void
on_buttonajouter_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowajout,*windowpp;
windowpp = lookup_widget(button,"windowpp");
gtk_widget_destroy(windowpp);
windowajout=create_windowajout();
gtk_widget_show (windowajout);
}


void
on_buttonajout_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
char Type[30];char Marque[30];char W[9];char Etage[30];char x[30];char y[30];char z[30];
CAPTEURS c;
//GtkWidget *entryajoutidentifiant;
GtkWidget *comboboxajoutetage;
GtkWidget *entryajoutvaleur;
GtkWidget *spinbuttonajoutjour;
GtkWidget *spinbuttonajoutmois;
GtkWidget *spinbuttonajoutannee;
GtkWidget *spinbuttonajouttt;
GtkWidget *spinbuttonajouthh;
GtkWidget *comboboxajouttype;
GtkWidget *radiobutton1;
GtkWidget *radiobutton2;
GtkWidget *radiobutton3;
GtkWidget *sortiea;




randomm(W,c);
spinbuttonajouthh=lookup_widget(button, "spinbuttonajouthh");
spinbuttonajouttt=lookup_widget(button, "spinbuttonajouttt");
spinbuttonajoutjour=lookup_widget(button, "spinbuttonajoutjour");
spinbuttonajoutmois=lookup_widget(button, "spinbuttonajoutmois");
spinbuttonajoutannee=lookup_widget(button, "spinbuttonajoutannee");
comboboxajouttype=lookup_widget(button, "comboboxajouttype");
//entryajoutidentifiant=lookup_widget(button,"entryajoutidentifiant");
comboboxajoutetage=lookup_widget(button,"comboboxajoutetage");
radiobutton1=lookup_widget(button, "radiobutton1");
radiobutton2=lookup_widget(button, "radiobutton2");
radiobutton3=lookup_widget(button, "radiobutton3");
entryajoutvaleur=lookup_widget(button,"entryajoutvaleur");
sortiea=lookup_widget(button, "labelajoutreus");

strcpy(x,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxajouttype)));
strcpy(z,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxajoutetage)));
strcpy(y,gtk_entry_get_text(GTK_ENTRY(entryajoutvaleur)));
if ((strcmp(x,"cpt temperature")==0)||(strcmp(x,"cpt poids")==0)||(strcmp(x,"cpt pression")==0)){
if (veriff(x)==0){gtk_label_set_text(GTK_LABEL(sortiea),"ajoutez le type de capteur svp !");}
else if (veriff(x)==1){
	if(veriff(y)==0){gtk_label_set_text(GTK_LABEL(sortiea)," ajoutez la valeur svp!");}
        else if (veriff(y)==1){
	if (floatt(y)==0){gtk_label_set_text(GTK_LABEL(sortiea)," ajoutez une valeur valide !");}
	else if (floatt(y)==1){
	if(veriff(z)==0){gtk_label_set_text(GTK_LABEL(sortiea),"ajoutez l'étage svp !");}
        else if (o==0){gtk_label_set_text(GTK_LABEL(sortiea),"il faut cocher le checkbuton!");}
        else if ((o==1)&&(veriff(z)==1)){
       





//strcpy(c.identifiant,gtk_entry_get_text(GTK_ENTRY(entryajoutidentifiant)));
strcpy(c.identifiant,W);
strcpy(c.valeur,gtk_entry_get_text(GTK_ENTRY(entryajoutvaleur)));
c.temps.heure=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbuttonajouthh));
c.temps.minute=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbuttonajouttt));
c.date.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbuttonajoutjour));
c.date.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbuttonajoutmois));
c.date.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbuttonajoutannee));
if (mca==1)
{strcpy(Marque,"marque1");}
else if (mca==2)
{strcpy(Marque,"marque2");}
else if (mca==3)
{strcpy(Marque,"marque3");}

strcpy(Type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxajouttype)));
strcpy(Etage,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxajoutetage)));
strcpy(c.type,Type);
strcpy(c.marque,Marque);
strcpy(c.etage,Etage);
ajout(c);
gtk_label_set_text(GTK_LABEL(sortiea),"Ajout effectué avec succès!");
}}}}}
else if ((strcmp(x,"cpt mouvement")==0)||(strcmp(x,"cpt fumée")==0)){
if (veriff(x)==0){gtk_label_set_text(GTK_LABEL(sortiea),"ajoutez le type de capteur svp !");}
else if (veriff(x)==1){
	if(veriff(y)==0){gtk_label_set_text(GTK_LABEL(sortiea)," ajoutez la valeur svp!");}
        else if (veriff(y)==1){
	if ((floatt(y)==0)&&((strcmp(y,"1")!=0)||(strcmp(y,"0")!=0))){gtk_label_set_text(GTK_LABEL(sortiea)," ajoutez une valeur valide !");}
	else if ((floatt(y)==1)&&((strcmp(y,"1")==0)||(strcmp(y,"0")==0))){
	if(veriff(z)==0){gtk_label_set_text(GTK_LABEL(sortiea),"ajoutez l'étage svp !");}
        else if (o==0){gtk_label_set_text(GTK_LABEL(sortiea),"il faut cocher le checkbuton!");}
        else if ((o==1)&&(veriff(z)==1)){





//strcpy(c.identifiant,gtk_entry_get_text(GTK_ENTRY(entryajoutidentifiant)));
strcpy(c.identifiant,W);
strcpy(c.valeur,gtk_entry_get_text(GTK_ENTRY(entryajoutvaleur)));
c.temps.heure=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbuttonajouthh));
c.temps.minute=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbuttonajouttt));
c.date.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbuttonajoutjour));
c.date.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbuttonajoutmois));
c.date.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbuttonajoutannee));
if (mca==1)
{strcpy(Marque,"marque1");}
else if (mca==2)
{strcpy(Marque,"marque2");}
else if (mca==3)
{strcpy(Marque,"marque3");}

strcpy(Type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxajouttype)));
strcpy(Etage,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxajoutetage)));
strcpy(c.type,Type);
strcpy(c.marque,Marque);
strcpy(c.etage,Etage);
ajout(c);
gtk_label_set_text(GTK_LABEL(sortiea),"Ajout effectué avec succès!");
}}}}}o=0;}


void
on_buttonmodif_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
CAPTEURS c;char Type[30];char Marque[30];char W[30];char Etage[30];char x[30];char y[30];char z[30];
GtkWidget *comboboxmodiftype;
//GtkWidget *entrymodifidentifiant;
GtkWidget *comboboxmodifetage;
GtkWidget *spinbuttonmodifjour;
GtkWidget *spinbuttonmodifmois;
GtkWidget *spinbuttonmodifannee;
GtkWidget *spinbuttonmodifhh;
GtkWidget *spinbuttonmodiftt;
GtkWidget *entrymodifvaleur;
GtkWidget *radiobutton4;
GtkWidget *radiobutton5;
GtkWidget *radiobutton6;
GtkWidget *sortiem;    

spinbuttonmodifhh=lookup_widget(button, "spinbuttonmodifhh");
spinbuttonmodiftt=lookup_widget(button, "spinbuttonmodiftt");	
spinbuttonmodifjour=lookup_widget(button, "spinbuttonmodifjour");
spinbuttonmodifmois=lookup_widget(button, "spinbuttonmodifmois");
spinbuttonmodifannee=lookup_widget(button, "spinbuttonmodifannee");
comboboxmodiftype=lookup_widget(button, "comboboxmodiftype");
//entrymodifidentifiant=lookup_widget(button,"entrymodifidentifiant");
comboboxmodifetage=lookup_widget(button,"comboboxmodifetage");
entrymodifvaleur=lookup_widget(button,"entrymodifvaleur");
radiobutton4=lookup_widget(button, "radiobutton4");
radiobutton5=lookup_widget(button, "radiobutton5");
radiobutton6=lookup_widget(button, "radiobutton6");
sortiem=lookup_widget(button, "labelmodifreus");


strcpy(x,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxmodiftype)));
strcpy(z,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxmodifetage)));
strcpy(y,gtk_entry_get_text(GTK_ENTRY(entrymodifvaleur)));
if ((strcmp(x,"cpt temperature")==0)||(strcmp(x,"cpt poids")==0)||(strcmp(x,"cpt pression")==0)){
if (veriff(x)==0){gtk_label_set_text(GTK_LABEL(sortiem),"ajoutez le type de capteur svp !");}
else if (veriff(x)==1){
	if(veriff(y)==0){gtk_label_set_text(GTK_LABEL(sortiem)," ajoutez la valeur svp!");}
        else if (veriff(y)==1){
	if (floatt(y)==0){gtk_label_set_text(GTK_LABEL(sortiem)," ajoutez une valeur valide !");}
	else if (floatt(y)==1){
	if(veriff(z)==0){gtk_label_set_text(GTK_LABEL(sortiem),"ajoutez l'étage svp !");}
        else if (o==0){gtk_label_set_text(GTK_LABEL(sortiem),"il faut cocher le checkbuton!");}
        else if ((o==2)&&(veriff(z)==1)){



strcpy(c.identifiant,id);
//strcpy(c.identifiant,gtk_entry_get_text(GTK_ENTRY(entrymodifidentifiant)));
strcpy(c.valeur,gtk_entry_get_text(GTK_ENTRY(entrymodifvaleur)));
c.temps.heure=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbuttonmodifhh));
c.temps.minute=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbuttonmodiftt));
c.date.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbuttonmodifjour));
c.date.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbuttonmodifmois));
c.date.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbuttonmodifannee));
strcpy(Type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxmodiftype)));
strcpy(Etage,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxmodifetage)));
if (n==1)
{strcpy(Marque,"marque1");}
else if (n==2)
{strcpy(Marque,"marque2");}
else if (n==3)
{strcpy(Marque,"marque3");}
strcpy(c.type,Type);
strcpy(c.marque,Marque);
strcpy(c.etage,Etage);
modification(id,c);
gtk_label_set_text(GTK_LABEL(sortiem),"Modification effectuée avec succès!");
}}}}}
else if ((strcmp(x,"cpt mouvement")==0)||(strcmp(x,"cpt fumée")==0)){
if (veriff(x)==0){gtk_label_set_text(GTK_LABEL(sortiem),"ajoutez le type de capteur svp !");}
else if (veriff(x)==1){
	if(veriff(y)==0){gtk_label_set_text(GTK_LABEL(sortiem)," ajoutez la valeur svp!");}
        else if (veriff(y)==1){
	if ((floatt(y)==0)&&((strcmp(y,"1")!=0)||(strcmp(y,"0")!=0))){gtk_label_set_text(GTK_LABEL(sortiem)," ajoutez une valeur valide !");}
	else if ((floatt(y)==1)&&((strcmp(y,"1")==0)||(strcmp(y,"0")==0))){
	if(veriff(z)==0){gtk_label_set_text(GTK_LABEL(sortiem),"ajoutez l'étage svp !");}
        else if (o==0){gtk_label_set_text(GTK_LABEL(sortiem),"il faut cocher le checkbuton!");}
        else if ((o==2)&&(veriff(z)==1)){
strcpy(c.identifiant,id);
//strcpy(c.identifiant,gtk_entry_get_text(GTK_ENTRY(entrymodifidentifiant)));
strcpy(c.valeur,gtk_entry_get_text(GTK_ENTRY(entrymodifvaleur)));
c.temps.heure=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbuttonmodifhh));
c.temps.minute=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbuttonmodiftt));
c.date.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbuttonmodifjour));
c.date.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbuttonmodifmois));
c.date.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbuttonmodifannee));
strcpy(Type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxmodiftype)));
strcpy(Etage,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxmodifetage)));
if (n==1)
{strcpy(Marque,"marque1");}
else if (n==2)
{strcpy(Marque,"marque2");}
else if (n==3)
{strcpy(Marque,"marque3");}
strcpy(c.type,Type);
strcpy(c.marque,Marque);
strcpy(c.etage,Etage);
modification(id,c);
gtk_label_set_text(GTK_LABEL(sortiem),"Modification effectuée avec succès!");
}}}}}}



void
on_buttonaffichboard_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
int t,p,mr;
char chp[30],cht[30],chmr[30],chnm[30];
CAPTEURS c;
GtkWidget *labelt;
GtkWidget *labelp;
GtkWidget *labelmr;
GtkWidget *treeview12;
GtkWidget *windowstat;

t=nombret(c);
p=nombrep(c);
mr=Mrq_Deff(c);

labelt=lookup_widget(button,"labelt");
labelp=lookup_widget(button,"labelp");
labelmr=lookup_widget(button,"labelmr");

strcpy(chmr,"marque");

sprintf(cht,"%d",t);
sprintf(chp,"%d",p);
sprintf(chnm,"%d",mr);
strcat(chmr,chnm);

gtk_label_set_text(labelt,cht);
gtk_label_set_text(labelp,chp);
gtk_label_set_text(labelmr,chmr);
windowstat=lookup_widget(button,"windowstat");
treeview12=lookup_widget(windowstat,"treeview12");
affichagestat(treeview12);
}


void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton)){
mca=1;}
}


void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton)){
mca=2;}
}


void
on_radiobutton3_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton)){
mca=3;}
}


void
on_buttonpp1_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget  *windowajout,*windowpp;
windowajout = lookup_widget(button,"windowajout");
gtk_widget_destroy(windowajout);
windowpp=create_windowpp();
gtk_widget_show (windowpp);
}


void
on_checkbuttonva_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton)){
o=1;}
}


void
on_radiobutton5_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton)){
n=2;}
}


void
on_radiobutton6_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton)){
n=3;}
}


void
on_radiobutton4_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton)){
n=1;}
}


void
on_buttonpp2_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget  *windowmodif,*windowpp;
windowmodif = lookup_widget(button,"windowmodif");
gtk_widget_destroy(windowmodif);
windowpp=create_windowpp();
gtk_widget_show (windowpp);
}


void
on_checkbuttonvm_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton)){
o=2;}
}


void
on_buttonpp3_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget  *windowstat,*windowpp;
windowstat = lookup_widget(button,"windowstat");
gtk_widget_destroy(windowstat);
windowpp=create_windowpp();
gtk_widget_show (windowpp);
}


void
on_AZbuttonfire_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
CAPTEURS c;
GtkWidget *AZtreeviewfire;
GtkWidget *AZwindowfire;
AZwindowfire=lookup_widget(button,"AZwindowfire");
AZtreeviewfire=lookup_widget(AZwindowfire,"AZtreeviewfire");
affichagestat1(AZtreeviewfire);
}


void
on_AZbuttonmvt_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_AZbuttonpres_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
CAPTEURS c;
GtkWidget *AZtreeviewpres;
GtkWidget *window3;
window3=lookup_widget(button,"window3");
AZtreeviewpres=lookup_widget(window3,"AZtreeviewpres");
affichagestat2(AZtreeviewpres);
}

//---------------------------------------agent foyer-----------------------------------------------------------

char id[30],idrech[30];
GtkWidget *AMWindowutil;
GtkWidget *AMWindowAjout;
GtkWidget *windowmodif;
GtkWidget *Accueil;
GtkWidget *AMwindowetudd;
GtkWidget *windowealarm;
int l=0,j=1;


void
on_AMcheckbutton_toggled                 (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton)){
l=1;}
}


void
on_AMradiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))){
j=1;}
}


void
on_AMradiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))){
j=2;}
}


void
on_AMTreeviewstock_row_activated         (GtkTreeView     *AMTreeviewstock,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
	gchar* identifiant;
	GtkTreeModel *Model = gtk_tree_view_get_model(AMTreeviewstock);

		if (gtk_tree_model_get_iter(Model, &iter, path)){
				gtk_tree_model_get(GTK_LIST_STORE(Model),&iter,1,&identifiant, -1);
				strcpy(id,identifiant);}

}


void
on_AMbuttonactualiser_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview;
AMWindowutil=lookup_widget(button,"AMWindowutil");
treeview=lookup_widget(AMWindowutil,"AMTreeviewstock");
AMaffichage(treeview);

}


void
on_AMbuttonModif_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *entrymodi;
GtkWidget *Windwskippoo;
		entrymodi=lookup_widget(button,"entrymodi");
                
                Windwskippoo=create_AMwindowmodifierr();
                gtk_widget_show (Windwskippoo);	
		gtk_entry_set_text(GTK_ENTRY(entrymodi),id);
}


void
on_AMbuttonAjout_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowskipo;

windowskipo=create_AMWindowAjout();
gtk_widget_show (windowskipo);

}


void
on_AMbuttonchercher_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{

stock s;
GtkWidget *windowskipoi;
GtkWidget *AMentrychercher;
GtkWidget *AMTreeviewstock;
GtkWidget *alert2;
FILE*f=NULL;
FILE*f2=NULL;
char Identifiant[30];
char Nom[30];
char Prenom[30];
char Sexe[30];
char Cin[30];
char Chambre[30];
char Etage[30];
char Date[100];
alert2=lookup_widget(button, "AMlabelalertrech");
windowskipoi=lookup_widget(button,"AMWindowutil");
AMentrychercher=lookup_widget(button,"AMentrychercher");
strcpy(idrech,gtk_entry_get_text(GTK_ENTRY(AMentrychercher)));
if (AMveriff(idrech)==0){gtk_label_set_text(GTK_LABEL(alert2),"Champs obligatoire!");}
else if (AMveriff(idrech)==1){
f=fopen("etudiant.txt","r");

 if(f!=NULL)
 {
  while ((fscanf(f,"%s *** %s *** %s *** %s *** %s *** %s *** %s *** %s\n",&Chambre,&Identifiant,&Nom,&Prenom,&Date,&Cin,&Sexe,&Etage)!=EOF))
     {
       f2=fopen("recherche.txt","a+");
       if  (f2!=NULL)
   {  
     
     if (((strcmp(Cin,idrech)==0))||((strcmp(Nom,idrech)==0)) ||((strcmp(Prenom,idrech)==0)) )
     { 
     
fprintf(f2,"%s *** %s *** %s *** %s *** %s *** %s *** %s *** %s\n",Chambre,Identifiant,Nom,Prenom,Date,Cin,Sexe,Etage);
     }
   
     AMTreeviewstock=lookup_widget(windowskipoi,"AMTreeviewstock");
     AMrecherche(AMTreeviewstock);
    
        fclose(f2);
    }

 }
 fclose(f);
}
remove("recherche.txt");}


}


void
on_AMbuttonSupprimer_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
stock s;
	    GtkWidget *treeview;
            AMWindowutil=lookup_widget(button,"AMWindowutil");
	    treeview=lookup_widget(AMWindowutil,"AMTreeviewstock");
	    AMsuppression(id,s);
            AMaffichage(treeview);

}


void
on_AMbuttonAjouter_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
char Chambre[30];
char Etage[30];char Date[30];char Nomm[30];char Prenomm[30];char Cinn[30];char W[9];
char x[30];char Sexe[30];char lid[20];

stock s;

GtkWidget *AMentryNom;
GtkWidget *AMentryprenom;
GtkWidget *AMentrycin;
GtkWidget *AMcomboboxentryrole;
GtkWidget *comboboxentrysex;
GtkWidget *comboboxentrysex1;
GtkWidget *AMspinbuttonday;
GtkWidget *AMspinbuttonmonth;
GtkWidget *AMspinbuttonyear;
GtkWidget *sortiea;
GtkWidget *alert1;
GtkWidget *bien_ajout;
GtkWidget *windowskipppp;
GtkWidget *AMcomboboxentry1;


AMspinbuttonday=lookup_widget(button, "AMspinbuttonday");
AMspinbuttonmonth=lookup_widget(button, "AMspinbuttonmonth");
AMspinbuttonyear=lookup_widget(button, "AMspinbuttonyear");
comboboxentrysex=lookup_widget(button, "AMradiobutton1");
comboboxentrysex1=lookup_widget(button, "AMradiobutton2");
AMcomboboxentryrole=lookup_widget(button, "AMcomboboxentryrole");
AMentrycin=lookup_widget(button, "AMentrycin");
AMentryNom=lookup_widget(button, "AMentryNom");
AMentryprenom=lookup_widget(button, "AMentryprenom");
sortiea=lookup_widget(button, "AMlabelmsgsucc");
alert1=lookup_widget(button, "AMlabelajoutalertid");
AMcomboboxentry1=lookup_widget(button, "AMcomboboxentry1");
strcpy(Nomm,gtk_entry_get_text(GTK_ENTRY(AMentryNom)));
strcpy(Prenomm,gtk_entry_get_text(GTK_ENTRY(AMentryprenom)));
strcpy(Cinn,gtk_entry_get_text(GTK_ENTRY(AMentrycin)));
strcpy(Etage,gtk_combo_box_get_active_text(GTK_COMBO_BOX(AMcomboboxentryrole)));
strcpy(Chambre,gtk_combo_box_get_active_text(GTK_COMBO_BOX(AMcomboboxentry1)));

AMrandomm(W);

strcpy(x,W);

if ((AMveriff(x)==0)||(AMveriff(Etage)==0)||(AMveriff(Chambre)==0)||(AMveriff(Cinn)==0)||(AMveriff(Nomm)==0)||(AMveriff(Prenomm)==0)){gtk_label_set_text(GTK_LABEL(alert1),"IL FAUT REMPLIR TOUS LES CASES!");}
else if (AMcheck(Cinn)==0 || strlen(Cinn)!=8){gtk_label_set_text(GTK_LABEL(alert1),"IL FAUT ENTRER UN VRAI CIN!");}
else if (AMveriff(x)==1){
	if(AMverifid(x)==0){gtk_label_set_text(GTK_LABEL(alert1),"THIS ID IS NOT AVAILABLE !");}

	else if((AMverifid(x)==1)&&(l==1)){

	
strcpy(s.identifiant,x);
strcpy(s.nom,gtk_entry_get_text(GTK_ENTRY(AMentryNom)));
strcpy(s.prenom,gtk_entry_get_text(GTK_ENTRY(AMentryprenom)));
strcpy(s.cin,gtk_entry_get_text(GTK_ENTRY(AMentrycin)));
s.date.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(AMspinbuttonday));
s.date.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(AMspinbuttonmonth));
s.date.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(AMspinbuttonyear));

if(j==1)strcpy(Sexe,"Homme");
else if (j==2) strcpy(Sexe,"Femme");
strcpy(s.sexe,Sexe);

strcpy(Etage,gtk_combo_box_get_active_text(GTK_COMBO_BOX(AMcomboboxentryrole)));
strcpy(s.etage,Etage);
strcpy(Chambre,gtk_combo_box_get_active_text(GTK_COMBO_BOX(AMcomboboxentry1)));
strcpy(s.chambre,Chambre);

AMajout(s);
gtk_label_set_text(GTK_LABEL(sortiea),"AJOUT EFFECTUÉ AVEC SUCCÉS!");}}

j=1;}




void
on_AMButtonmodier_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{

char Chambre[30];
char Etage[30];

char Nomm[30];char Prenomm[30];char Cinn[30];
char x[30];char Sexee[30];
stock s;
GtkWidget *modifid;
GtkWidget *modifNom;
GtkWidget *modifprenom;
GtkWidget *modifcin;
GtkWidget *comboboxmodifrole;
GtkWidget *comboboxmodifsex;
GtkWidget *spinbuttondaymodif;
GtkWidget *spinbuttonmonthmodif;
GtkWidget *spinbuttonyearmodif;
GtkWidget *sortieamodif;
GtkWidget *alert1modif;
GtkWidget *AMcomboboxentry2;


spinbuttondaymodif=lookup_widget(button, "AMspinbuttonjour");
spinbuttonmonthmodif=lookup_widget(button, "AMspinbuttonmois");
spinbuttonyearmodif=lookup_widget(button, "AMspinbuttonannee");
comboboxmodifsex=lookup_widget(button, "AMcomboboxentryse");
comboboxmodifrole=lookup_widget(button, "AMcomboboxentryrol");
modifcin=lookup_widget(button, "AMentryci");
modifNom=lookup_widget(button, "AMentrynomm");
modifprenom=lookup_widget(button, "AMentryprenomm");
sortieamodif=lookup_widget(button, "AMlabelmsgsucc");
alert1modif=lookup_widget(button, "AMlabelajoutalertid");
AMcomboboxentry2=lookup_widget(button, "AMcomboboxentry2");


strcpy(s.identifiant,id);
strcpy(s.nom,gtk_entry_get_text(GTK_ENTRY(modifNom)));
strcpy(s.prenom,gtk_entry_get_text(GTK_ENTRY(modifprenom)));
strcpy(s.cin,gtk_entry_get_text(GTK_ENTRY(modifcin)));


s.date.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbuttondaymodif));
s.date.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbuttonmonthmodif));
s.date.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbuttonyearmodif));

strcpy(Sexee,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxmodifsex)));
strcpy(s.sexe,Sexee);

strcpy(Etage,gtk_combo_box_get_active_text(GTK_COMBO_BOX(AMcomboboxentry2)));
strcpy(s.etage,Etage);
strcpy(Chambre,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxmodifrole)));
strcpy(s.chambre,Chambre);
strcpy(Nomm,gtk_entry_get_text(GTK_ENTRY(modifNom)));
strcpy(Prenomm,gtk_entry_get_text(GTK_ENTRY(modifprenom)));
strcpy(Cinn,gtk_entry_get_text(GTK_ENTRY(modifcin)));
strcpy(Etage,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxmodifrole)));
strcpy(Chambre,gtk_combo_box_get_active_text(GTK_COMBO_BOX(AMcomboboxentry2)));

if ((AMveriff(Etage)==0)||(AMveriff(Chambre)==0)||(AMveriff(Cinn)==0) ||(AMveriff(Sexee)==0)||(AMveriff(Nomm)==0)||(AMveriff(Prenomm)==0))
{gtk_label_set_text(GTK_LABEL(sortieamodif),"IL FAUT REMPLIR TOUS LES CASES!");}
else if (AMcheck(Cinn)==0 || strlen(Cinn)!=8){gtk_label_set_text(GTK_LABEL(sortieamodif),"IL FAUT ENTRER UN VRAI CIN!");}
else if ((AMveriff(Etage)==1)||(AMveriff(Chambre)==1)||(AMveriff(Cinn)==1)||(AMveriff(Nomm)==1)||(AMveriff(Prenomm)==1)){
AMmodification(id,s);gtk_label_set_text(GTK_LABEL(sortieamodif),"MODIFICATION EFFECTUÉE AVEC SUCCÉS!");}


}




void
on_AMbutton9_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *AMtreeview1;
GtkWidget *labelniv;

etudiant e;
char nomm[20];    
char prenomm[20];  
char cinn[20];
char sexee[20];
char niveau[30];
int niv;
char chniv[30];
GtkWidget *windowskipoii;
GtkWidget *AMentrychercherr;
GtkWidget *Treevieww;
GtkWidget *AMcomboboxentry3;
FILE*f;
FILE*f2;
AMwindowetudd=lookup_widget(button,"AMwindowetudd");
AMtreeview1=lookup_widget(AMwindowetudd,"AMtreeview1");
AMcomboboxentry3=lookup_widget(button, "AMcomboboxentry3");
strcpy(niveau,gtk_combo_box_get_active_text(GTK_COMBO_BOX(AMcomboboxentry3)));
niv=nombreniv(niveau);

     Treevieww=lookup_widget(AMwindowetudd,"AMtreeview1");
     AMaffichage_etud(niveau,AMtreeview1);
labelniv=lookup_widget(button,"labelniv");
sprintf(chniv,"%d",niv);
gtk_label_set_text(labelniv,chniv);




}


void
on_AMbutton10_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

windowealarm=create_AMwindowetudd();
gtk_widget_show (windowealarm);
}

//-------------------------------------------------------nutro----------------------------------------------------------------------

GtkWidget *DBwindowpp;
char id[30],idrech[30];
int s=0;
int g=0;
int k=1;
int o=1;

void
on_DBtreeview1_row_activated             (GtkTreeView     *DBtreeview1,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
	gchar* identifiant;
	GtkTreeModel *Model = gtk_tree_view_get_model(DBtreeview1);

		if (gtk_tree_model_get_iter(Model, &iter, path)){
				gtk_tree_model_get(GTK_LIST_STORE(Model),&iter,0,&identifiant, -1);
				strcpy(id,identifiant);}
}


void
on_DBbuttonmodifier_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
		GtkWidget *DBwindowmodif,*DBwindowpp;
DBwindowpp = lookup_widget(button,"DBwindowpp");
gtk_widget_destroy(DBwindowpp);

DBwindowmodif=create_DBwindowmodif();
gtk_widget_show (DBwindowmodif);
}


void
on_DBbuttonajouter_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
		GtkWidget *DBwindowajout,*DBwindowpp;
DBwindowpp = lookup_widget(button,"DBwindowpp");
gtk_widget_destroy(DBwindowpp);
DBwindowajout=create_DBwindowajout();
gtk_widget_show (DBwindowajout);
}


void
on_DBbuttonsupprimer_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
MENU M;
GtkWidget *DBwindowpp;
	    GtkWidget *DBtreeview1;
	    DBwindowpp=lookup_widget(button,"DBwindowpp");
	    DBtreeview1=lookup_widget(DBwindowpp,"DBtreeview1");
	    DBsuppression(id,M);
            DBaffichage(DBtreeview1);
}


void
on_DBbuttonactualiser_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *DBtreeview1;
GtkWidget *DBwindowpp;
DBwindowpp=lookup_widget(button,"DBwindowpp");
DBtreeview1=lookup_widget(DBwindowpp,"DBtreeview1");
DBaffichage(DBtreeview1);
}


void
on_DBbuttonstatistique_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
		GtkWidget *DBwindowstat,*DBwindowpp;
DBwindowpp = lookup_widget(button,"DBwindowpp");
gtk_widget_destroy(DBwindowpp);
DBwindowstat=create_DBwindowstat();
gtk_widget_show (DBwindowstat);
}


void
on_DBbuttonajout_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
char Menu[30];char Type[30];char x[30];char W[9]; char y[30];char z[30];
MENU M;
//GtkWidget *entryajoutid;
GtkWidget *DBcomboboxajoutmenu;
GtkWidget *DBentryajoutmenu;
GtkWidget *DBentryajoutdessert;
GtkWidget *DBentryajoutpp;
GtkWidget *DBspinbuttonajoutjj;
GtkWidget *DBspinbuttonajoutmm;
GtkWidget *DBspinbuttonajoutaa;
GtkWidget *DBradiobuttonna;
GtkWidget *DBradiobuttonsa;
GtkWidget *sortiea;
DBrandomm(W,M);



DBspinbuttonajoutjj=lookup_widget(button, "DBspinbuttonajoutjj");
DBspinbuttonajoutmm=lookup_widget(button, "DBspinbuttonajoutmm");
DBspinbuttonajoutaa=lookup_widget(button, "DBspinbuttonajoutaa");
//entryajoutid=lookup_widget(button,"entryajoutid");
DBradiobuttonsa=lookup_widget(button, "DBradiobuttonsa");
DBradiobuttonna=lookup_widget(button, "DBradiobuttonna");
DBcomboboxajoutmenu=lookup_widget(button,"DBcomboboxajoutmenu");
DBentryajoutmenu=lookup_widget(button,"DBentryajoutmenu");
DBentryajoutdessert=lookup_widget(button,"DBentryajoutdessert");
DBentryajoutpp=lookup_widget(button,"DBentryajoutpp");
sortiea=lookup_widget(button, "DBlabel20");

strcpy(z,gtk_entry_get_text(GTK_ENTRY(DBentryajoutdessert)));
strcpy(y,gtk_entry_get_text(GTK_ENTRY(DBentryajoutpp)));
strcpy(x,gtk_entry_get_text(GTK_ENTRY(DBentryajoutmenu)));
if (DBveriff(x)==0){gtk_label_set_text(GTK_LABEL(sortiea),"ajoutez un menu svp");}
else if(DBveriff(x)==1){
if (DBveriff(y)==0){gtk_label_set_text(GTK_LABEL(sortiea),"ajoutez un plat principale svp");}
else if (DBveriff(y)==1){
if (DBveriff(z)==0){gtk_label_set_text(GTK_LABEL(sortiea),"ajoutez un dessert svp");}
if (s==0){gtk_label_set_text(GTK_LABEL(sortiea),"il faut cocher le checkbutton!");}
else if ((DBveriff(z)==1)&&(s==1)){
	


//strcpy(M.identifiant,gtk_entry_get_text(GTK_ENTRY(entryajoutid)));
strcpy(M.identifiant,W);
strcpy(M.menu,gtk_entry_get_text(GTK_ENTRY(DBentryajoutmenu)));
strcpy(M.dessert,gtk_entry_get_text(GTK_ENTRY(DBentryajoutdessert)));
strcpy(M.pp,gtk_entry_get_text(GTK_ENTRY(DBentryajoutpp)));
M.date.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(DBspinbuttonajoutjj));
M.date.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(DBspinbuttonajoutmm));
M.date.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(DBspinbuttonajoutaa));
if (k==1)
{strcpy(Type,"sans gluten");}
else if (k==2)
{strcpy(Type,"normal");}
strcpy(Menu,gtk_combo_box_get_active_text(GTK_COMBO_BOX(DBcomboboxajoutmenu)));
strcpy(M.type,Menu);
strcpy(M.gluten,Type);
DBajout(M);
gtk_label_set_text(GTK_LABEL(sortiea),"Ajout effectué avec succès!");
}}}
s=0;}



void
on_DBbuttonmodif_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
char Menu[30];char Type[30]; char y[30];char z[30];char x[30];
MENU M;
GtkWidget *DBcomboboxmodifmenu;
GtkWidget *DBentrymodifmenu;
GtkWidget *DBspinbuttonmodifjj;
GtkWidget *DBspinbuttonmodifmm;
GtkWidget *DBspinbuttonmodifaa;
GtkWidget *DBradiobuttonnm;
GtkWidget *DBradiobuttonsm;
GtkWidget *DBentrymodifdessert;
GtkWidget *DBentrymodifpp;
GtkWidget *sortiem;



DBspinbuttonmodifjj=lookup_widget(button, "DBspinbuttonmodifjj");
DBspinbuttonmodifmm=lookup_widget(button, "DBspinbuttonmodifmm");
DBspinbuttonmodifaa=lookup_widget(button, "DBspinbuttonmodifaa");
DBcomboboxmodifmenu=lookup_widget(button,"DBcomboboxmodifmenu");
DBentrymodifmenu=lookup_widget(button,"DBentrymodifmenu");
DBradiobuttonsm=lookup_widget(button, "DBradiobuttonsm");
DBradiobuttonnm=lookup_widget(button, "DBradiobuttonnm");
DBentrymodifdessert=lookup_widget(button,"DBentrymodifdessert");
DBentrymodifpp=lookup_widget(button,"DBentrymodifpp");
sortiem=lookup_widget(button, "DBlabel21");

strcpy(z,gtk_entry_get_text(GTK_ENTRY(DBentrymodifdessert)));
strcpy(y,gtk_entry_get_text(GTK_ENTRY(DBentrymodifpp)));
strcpy(x,gtk_entry_get_text(GTK_ENTRY(DBentrymodifmenu)));
if (DBveriff(x)==0){gtk_label_set_text(GTK_LABEL(sortiem),"ajoutez un menu svp");}
else if(DBveriff(x)==1){
if (DBveriff(y)==0){gtk_label_set_text(GTK_LABEL(sortiem),"ajoutez un plat principale svp");}
else if (DBveriff(y)==1){
if (DBveriff(z)==0){gtk_label_set_text(GTK_LABEL(sortiem),"ajoutez un dessert svp");}
if (g==0){gtk_label_set_text(GTK_LABEL(sortiem),"il faut cocher le checkbutton!");}
else if ((DBveriff(z)==1)&&(g==1)){


strcpy(M.identifiant,id);
if (o==2)
{strcpy(Type,"sans gluten");}
else if (o==1)
{strcpy(Type,"normal");}
strcpy(M.menu,gtk_entry_get_text(GTK_ENTRY(DBentrymodifmenu)));
strcpy(M.dessert,gtk_entry_get_text(GTK_ENTRY(DBentrymodifdessert)));
strcpy(M.pp,gtk_entry_get_text(GTK_ENTRY(DBentrymodifpp)));
M.date.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(DBspinbuttonmodifjj));
M.date.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(DBspinbuttonmodifmm));
M.date.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(DBspinbuttonmodifaa));
strcpy(Menu,gtk_combo_box_get_active_text(GTK_COMBO_BOX(DBcomboboxmodifmenu)));
strcpy(M.type,Menu);
strcpy(M.gluten,Type);
DBmodification(id,M);
gtk_label_set_text(GTK_LABEL(sortiem),"Modification effectué avec succès!");
}}}g=0;}


void
on_DBbuttonafficher_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
dechet D;
GtkWidget *DBtreeview2;
GtkWidget *DBwindowstat;
DBwindowstat=lookup_widget(button,"DBwindowstat");
DBtreeview2=lookup_widget(DBwindowstat,"DBtreeview2");
DBaffichage_stat(DBtreeview2);
}


void
on_DBcheckbuttona_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton)){
s=1;}
}


void
on_DBcheckbuttonm_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton)){
g=1;}
}


void
on_DBbuttonpp3_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget  *DBwindowstat,*DBwindowpp;
DBwindowstat = lookup_widget(button,"DBwindowstat");
gtk_widget_destroy(DBwindowstat);
DBwindowpp=create_DBwindowpp();
gtk_widget_show (DBwindowpp);
}


void
on_DBbuttonpp1_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget  *DBwindowajout,*DBwindowpp;
DBwindowajout = lookup_widget(button,"DBwindowajout");
gtk_widget_destroy(DBwindowajout);
DBwindowpp=create_DBwindowpp();
gtk_widget_show (DBwindowpp);
}


void
on_DBbuttonpp2_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget  *DBwindowmodif,*DBwindowpp;
DBwindowmodif = lookup_widget(button,"DBwindowmodif");
gtk_widget_destroy(DBwindowmodif);
DBwindowpp=create_DBwindowpp();
gtk_widget_show (DBwindowpp);
}


void
on_DBbuttonrecherche_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
MENU M;
GtkWidget *DBentryid;
GtkWidget *DBtreeview1;
FILE*f;
FILE*f2;


DBwindowpp=lookup_widget(button,"DBwindowpp");
DBentryid=lookup_widget(button,"DBentryid");
strcpy(idrech,gtk_entry_get_text(GTK_ENTRY(DBentryid)));
f=fopen("menu.bin","rb");

 if(f!=NULL)
 {
  while(fread(&M,sizeof(MENU),1,f))
     {
       f2=fopen("recherche.bin","ab+");
       if  (f2!=NULL)
   {  
     
     if ((strcmp(M.type,idrech)==0)||(strcmp(M.identifiant,idrech)==0))
     { 
     fwrite(&M,sizeof(MENU),1,f2);
     }
   
     DBtreeview1=lookup_widget(DBwindowpp,"DBtreeview1");
     DBrecherche(DBtreeview1);
    
        fclose(f2);
    }

 }
 fclose(f);
}
remove("recherche.bin");
}




void
on_DBradiobuttonsa_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton)){
k=1;}
}


void
on_DBradiobuttonna_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton)){
k=2;}
}


void
on_DBradiobuttonnm_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton)){
o=1;}
}


void
on_DBradiobuttonsm_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton)){
o=2;}
}


//----------------------------------------------------------------reclamation-----------------------------------------------------------------------
char id[30],idrech[30];
GtkWidget *page_principale;
int m=0;
int a=0;
void
on_KRcheckbuttonvm_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton)){
m=1;}
}


void
on_KRcheckbuttonva_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton)){
a=1;}
}


void
on_KRbuttonactualiser_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *KRtreeview1;
page_principale=lookup_widget(button,"page_principale");
KRtreeview1=lookup_widget(page_principale,"KRtreeview1");
KRaffichage(KRtreeview1,idtemp);
}


void
on_KRbuttonsupprimer_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
RECLAMATION r;
	    GtkWidget *KRtreeview1;
	    page_principale=lookup_widget(button,"page_principale");
	    KRtreeview1=lookup_widget(page_principale,"KRtreeview1");
	
	    KRsuppression(id,r);
            KRaffichage(KRtreeview1,idtemp);


}


void
on_KRbuttonajouter_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
		GtkWidget *windowskipo,*page_principale;
page_principale= lookup_widget(button,"page_principale");
gtk_widget_destroy(page_principale);
windowskipo=create_ajout_de_la_reclamation();
gtk_widget_show (windowskipo);
}


void
on_KRbuttonmodifier_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
		GtkWidget *windowskipoo,*page_principale;
page_principale= lookup_widget(button,"page_principale");
gtk_widget_destroy(page_principale);
windowskipoo=create_modification_de_la_reclamation();
gtk_widget_show (windowskipoo);
}


void
on_KRbuttonboard_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
		GtkWidget *windowskipooo,*page_principale;
page_principale= lookup_widget(button,"page_principale");
gtk_widget_destroy(page_principale);
windowskipooo=create_statistique();
gtk_widget_show (windowskipooo);
}


void
on_KRbuttonajout_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
RECLAMATION r;char Type[30];char W[9];
char x[30];
char d[30];
char o[30];
char ll[30];
int lll;
GtkWidget *KRcomboboxajout;
GtkWidget *entryid;
GtkWidget *KRentryprob;

GtkWidget *KRspinbuttonjj;
GtkWidget *KRspinbuttonmm;
GtkWidget *KRspinbuttonaa;

GtkWidget *KRspinbuttonjour;
GtkWidget *KRspinbuttonmois;
GtkWidget *KRspinbuttonanne;

GtkWidget *KRentry1;
GtkWidget *KRentry2;
GtkWidget *KRlabel49;

 

KRspinbuttonjour=lookup_widget(button, "KRspinbuttonjour");
KRspinbuttonmois=lookup_widget(button, "KRspinbuttonmois");
KRspinbuttonanne=lookup_widget(button, "KRspinbuttonanne");
KRspinbuttonjj=lookup_widget(button, "KRspinbuttonjj");
KRspinbuttonmm=lookup_widget(button, "KRspinbuttonmm");
KRspinbuttonaa=lookup_widget(button, "KRspinbuttonaa");

KRcomboboxajout=lookup_widget(button, "KRcomboboxajout");

KRentryprob=lookup_widget(button,"KRentryprob");
KRentry1=lookup_widget(button,"KRentry1");
KRentry2=lookup_widget(button,"KRentry2");
KRlabel49=lookup_widget(button, "KRlabel49");

strcpy(ll,gtk_entry_get_text(GTK_ENTRY(KRentry2)));
lll=strlen(ll);
strcpy(d,gtk_entry_get_text(GTK_ENTRY(KRentryprob)));

strcpy(Type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(KRcomboboxajout)));
strcpy(o,Type);


KRrandomm(W,r);

strcpy(x,W);

	
        if (KRveriff(o)==0){gtk_label_set_text(GTK_LABEL(KRlabel49),"il faut mentionner le service a reclamer!");}
        else if (lll!=8){gtk_label_set_text(GTK_LABEL(KRlabel49),"il faut entrer une vrai carte d identite !");}
        else if (KRveriff(d)==0){gtk_label_set_text(GTK_LABEL(KRlabel49),"il faut mentionner le probleme!");}
        else if (a==0){gtk_label_set_text(GTK_LABEL(KRlabel49),"il faut valider le check button!");}
	else {
strcpy(r.identifiant,x);
strcpy(r.problem,gtk_entry_get_text(GTK_ENTRY(KRentryprob)));
strcpy(r.nom,gtk_entry_get_text(GTK_ENTRY(KRentry1)));
strcpy(r.cin,gtk_entry_get_text(GTK_ENTRY(KRentry2)));

r.dater.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(KRspinbuttonjour));
r.dater.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(KRspinbuttonmois));
r.dater.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(KRspinbuttonanne));
r.datea.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(KRspinbuttonjj));
r.datea.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(KRspinbuttonmm));
r.datea.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(KRspinbuttonaa));
strcpy(Type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(KRcomboboxajout)));
strcpy(r.type,Type);
strcpy(r.idtempp,idtemp);
KRajout(r);
gtk_label_set_text(GTK_LABEL(KRlabel49),"Ajout effectué avec succès!");}
a=0;}


void
on_KRbuttonmodif_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
RECLAMATION r;char Type[30];
char x[30];
char d[30];
char o[30];
char ll[30];
int lll;
GtkWidget *KRcomboboxmodif;
GtkWidget *entrymodifid;
GtkWidget *KRentrymodifprob;
GtkWidget *spinbuttonmodifjj;
GtkWidget *KRspinbuttonmodifmm;
GtkWidget *KRspinbuttonmodifaa;

GtkWidget *KRspinbuttonmodifjour;
GtkWidget *KRspinbuttonmodifmois;
GtkWidget *KRspinbuttonmodifanne;
GtkWidget *KRentry3;
GtkWidget *KRentry4;
GtkWidget *KRLabel53;


    
	
KRspinbuttonmodifjour=lookup_widget(button, "KRspinbuttonmodifjour");
KRspinbuttonmodifmois=lookup_widget(button, "KRspinbuttonmodifmois");
KRspinbuttonmodifanne=lookup_widget(button, "KRspinbuttonmodifanne");
spinbuttonmodifjj=lookup_widget(button, "spinbuttonmodifjj");
KRspinbuttonmodifmm=lookup_widget(button, "KRspinbuttonmodifmm");
KRspinbuttonmodifaa=lookup_widget(button, "KRspinbuttonmodifaa");
KRcomboboxmodif=lookup_widget(button, "KRcomboboxmodif");
KRLabel53=lookup_widget(button, "KRLabel53");
KRentrymodifprob=lookup_widget(button,"KRentrymodifprob");
KRentry3=lookup_widget(button,"KRentry3");
KRentry4=lookup_widget(button,"KRentry4");


strcpy(ll,gtk_entry_get_text(GTK_ENTRY(KRentry4)));
lll=strlen(ll);
strcpy(d,gtk_entry_get_text(GTK_ENTRY(KRentrymodifprob)));

strcpy(Type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(KRcomboboxmodif)));
strcpy(o,Type);


  if (KRveriff(o)==0){gtk_label_set_text(GTK_LABEL(KRLabel53),"il faut mentionner le service a reclamer!");}
        else if (lll!=8){gtk_label_set_text(GTK_LABEL(KRLabel53),"il faut entrer une vrai carte d identite !");}
        else if (KRveriff(d)==0){gtk_label_set_text(GTK_LABEL(KRLabel53),"il faut mentionner le probleme!");}
        else if (m==0){gtk_label_set_text(GTK_LABEL(KRLabel53),"il faut valider le check button!");}
        else{

strcpy(r.identifiant,id);
strcpy(r.problem,gtk_entry_get_text(GTK_ENTRY(KRentrymodifprob)));
strcpy(r.nom,gtk_entry_get_text(GTK_ENTRY(KRentry3)));
strcpy(r.cin,gtk_entry_get_text(GTK_ENTRY(KRentry4)));
r.dater.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(KRspinbuttonmodifjour));
r.dater.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(KRspinbuttonmodifmois));
r.dater.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(KRspinbuttonmodifanne));
r.datea.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbuttonmodifjj));
r.datea.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(KRspinbuttonmodifmm));
r.datea.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(KRspinbuttonmodifaa));
strcpy(Type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(KRcomboboxmodif)));
strcpy(r.type,Type);
strcpy(r.idtempp,idtemp);

KRmodification(id,r);
gtk_label_set_text(GTK_LABEL(KRLabel53),"modification effectué avec succès!");}
m=0;

}


void
on_KRbuttonafficher_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
char chr[30];char chh[30];
int k,h;
RECLAMATION r;
GtkWidget *KRlabelrest;
GtkWidget *KRlabelheb;
GtkWidget *KRlabelstat;
k=KRnombrer(r);
h=KRnombreh(r);
KRlabelrest=lookup_widget(button,"KRlabelrest");
KRlabelheb=lookup_widget(button,"KRlabelheb");
KRlabelstat=lookup_widget(button,"KRlabelstat");
sprintf(chr,"%d",k);
sprintf(chh,"%d",h);
gtk_label_set_text(KRlabelrest,chr);
gtk_label_set_text(KRlabelheb,chh);
if (k>h)
{gtk_label_set_text(KRlabelstat,"service Restauration");}
else 
{gtk_label_set_text(KRlabelstat,"service Hébergement");}

}


void
on_KRbuttonrecherche_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{


RECLAMATION r;
GtkWidget *KRentryrech;
GtkWidget *KRtreeview1;
FILE*f;
FILE*f2;


page_principale=lookup_widget(button,"page_principale");
KRentryrech=lookup_widget(button,"KRentryrech");
strcpy(idrech,gtk_entry_get_text(GTK_ENTRY(KRentryrech)));
f=fopen("reclamation.bin","rb");

 if(f!=NULL)
 {
  while(fread(&r,sizeof(RECLAMATION),1,f))
     {
       f2=fopen("recherche.bin","ab+");
       if  (f2!=NULL)
   {  
     
     if ((strcmp(r.nom,idrech)==0)||(strcmp(r.identifiant,idrech)==0)||(strcmp(r.type,idrech)==0))
     { 
     fwrite(&r,sizeof(RECLAMATION),1,f2);
     }
   
     KRtreeview1=lookup_widget(page_principale,"KRtreeview1");
     KRrecherche(KRtreeview1);
    
        fclose(f2);
    }

 }
 fclose(f);
}
remove("recherche.bin");
}





void
on_KRtreeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
	gchar* identifiant;
	GtkTreeModel *Model = gtk_tree_view_get_model(treeview);

		if (gtk_tree_model_get_iter(Model, &iter, path)){
				gtk_tree_model_get(GTK_LIST_STORE(Model),&iter,1,&identifiant, -1);
				strcpy(id,identifiant);}
}

//-------------------------------------stock-------------------------------------------------------


char id[30],idrech[30];
int ll=0,j1=0,mm=1,nn=1;
GtkWidget *windowahmedpp;




void
on_Mbuttonrecherchrer_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
STOCK c;
GtkWidget *Mentryid;
GtkWidget *Mtreeview11;
FILE*f;
FILE*f2;


windowahmedpp=lookup_widget(button,"windowahmedpp");
Mentryid=lookup_widget(button,"Mentryid");
strcpy(idrech,gtk_entry_get_text(GTK_ENTRY(Mentryid)));
f=fopen("stock.bin","rb");

 if(f!=NULL)
 {
  while(fread(&c,sizeof(STOCK),1,f))
     {
       f2=fopen("recherche.bin","ab+");
       if  (f2!=NULL)
   {  
     
     if (((strcmp(c.identifiant,idrech)==0))||((strcmp(c.type,idrech)==0))||((strcmp(c.marque,idrech)==0)))
     { 
     fwrite(&c,sizeof(STOCK),1,f2);
     }
   
     Mtreeview11=lookup_widget(windowahmedpp,"Mtreeview11");
     Mrecherche(Mtreeview11);
    
        fclose(f2);
    }

 }
 fclose(f);
}
remove("recherche.bin");
}


void
on_Mtreeview11_row_activated            (GtkTreeView     *Mtreeview11,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
	gchar* identifiant;
	GtkTreeModel *Model = gtk_tree_view_get_model(Mtreeview11);

		if (gtk_tree_model_get_iter(Model, &iter, path)){
				gtk_tree_model_get(GTK_LIST_STORE(Model),&iter,1,&identifiant, -1);
				strcpy(id,identifiant);}
}


void
on_Mbuttonsupprimer_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
STOCK c;
	    GtkWidget *Mtreeview11;
	    windowahmedpp=lookup_widget(button,"windowahmedpp");
	    Mtreeview11=lookup_widget(windowahmedpp,"Mtreeview11");
	    Msuppression(id,c);
            Maffichage(Mtreeview11);
}


void
on_Mbuttonmodifier_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
				GtkWidget *windowahmedmodif,*windowahmedpp;
windowahmedpp = lookup_widget(button,"windowahmedpp");
gtk_widget_destroy(windowahmedpp);

windowahmedmodif=create_windowahmedmodif();
gtk_widget_show (windowahmedmodif);
}


void
on_Mbuttonactualiser_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Mtreeview11;
windowahmedpp=lookup_widget(button,"windowahmedpp");
Mtreeview11=lookup_widget(windowahmedpp,"Mtreeview11");
Maffichage(Mtreeview11);
}


void
on_Mbuttonboard_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
		GtkWidget *windowahmedstat,*windowahmedpp;
windowahmedpp = lookup_widget(button,"windowahmedpp");
gtk_widget_destroy(windowahmedpp);
windowahmedstat=create_windowahmedstat();
gtk_widget_show (windowahmedstat);
}


void
on_Mbuttonajouter_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
			GtkWidget *windowahmedajout,*windowahmedpp;
windowahmedpp = lookup_widget(button,"windowahmedpp");
gtk_widget_destroy(windowahmedpp);
windowahmedajout=create_windowahmedajout();
gtk_widget_show (windowahmedajout);
}


void
on_Mbuttonajout_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
char Type[30];char Marque[30];char x[30];char W[9];char y[30];
STOCK c;
//GtkWidget *entryajoutidentifiant;
GtkWidget *Mcomboboxajouttype;
GtkWidget *Mentryajoutquantite;
GtkWidget *Mspinbuttonajoutjour;
GtkWidget *Mspinbuttonajoutmois;
GtkWidget *Mspinbuttonajoutannee;
GtkWidget *sortiea;
GtkWidget *Mradiobutton1;
GtkWidget *Mradiobutton2;
GtkWidget *Mradiobutton3;

Mspinbuttonajoutjour=lookup_widget(button, "Mspinbuttonajoutjour");
Mspinbuttonajoutmois=lookup_widget(button, "Mspinbuttonajoutmois");
Mspinbuttonajoutannee=lookup_widget(button, "Mspinbuttonajoutannee");
Mcomboboxajouttype=lookup_widget(button, "Mcomboboxajouttype");
Mradiobutton1=lookup_widget(button, "Mradiobutton1");
Mradiobutton2=lookup_widget(button, "Mradiobutton2");
Mradiobutton3=lookup_widget(button, "Mradiobutton3");
//entryajoutidentifiant=lookup_widget(button,"entryajoutidentifiant");
Mentryajoutquantite=lookup_widget(button,"Mentryajoutquantite");
sortiea=lookup_widget(button, "Mlabelajoutreus");
Mrandomm(W,c);

strcpy(x,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Mcomboboxajouttype)));
strcpy(y,gtk_entry_get_text(GTK_ENTRY(Mentryajoutquantite)));
if (Mveriff(x)==0){gtk_label_set_text(GTK_LABEL(sortiea),"ajoutez le type svp!");}
else if (Mveriff(x)==1){
	if(Mveriff(y)==0){gtk_label_set_text(GTK_LABEL(sortiea),"ajoutez la quantite svp !");}
        else if (Mveriff(y)==1){
	if (Mfloatt(y)==0){gtk_label_set_text(GTK_LABEL(sortiea),"ajoutez une valeure valide svp !");}
	else if(Mfloatt(y)==1){
	if((Mfloatt(y)==1)&&(ll==0)){gtk_label_set_text(GTK_LABEL(sortiea),"validez le check button svp !");}


else if(ll==1){


strcpy(c.identifiant,W);
strcpy(c.quantite,gtk_entry_get_text(GTK_ENTRY(Mentryajoutquantite)));
c.date.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Mspinbuttonajoutjour));
c.date.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Mspinbuttonajoutmois));
c.date.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Mspinbuttonajoutannee));
if (mm==1)
{strcpy(Marque,"marque2");}
else if (mm==2)
{strcpy(Marque,"marque1");}
else if (mm==3)
{strcpy(Marque,"marque3");}

strcpy(Type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Mcomboboxajouttype)));
//strcpy(Marque,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Mcomboboxajouttype)));
strcpy(c.type,Type);
strcpy(c.marque,Marque);
Majout(c);
gtk_label_set_text(GTK_LABEL(sortiea),"ajout effectué avec succés");
}}}}ll=0;}


void
on_Mbuttonmodif_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
STOCK c;char Type[30];char Marque[30];char x[30];char y[30];
GtkWidget *Mcomboboxmodiftype;
//GtkWidget *entrymodifidentifiant;
//GtkWidget *comboboxmodifmarque;
GtkWidget *Mspinbuttonmodifjour;
GtkWidget *Mspinbuttonmodifmois;
GtkWidget *Mspinbuttonmodifannee;
GtkWidget *Mentrymodifquantite;
GtkWidget *Mradiobutton4;
GtkWidget *Mradiobutton5;
GtkWidget *Mradiobutton6;
GtkWidget *sortiem;    
	
Mspinbuttonmodifjour=lookup_widget(button, "Mspinbuttonmodifjour");
Mspinbuttonmodifmois=lookup_widget(button, "Mspinbuttonmodifmois");
Mspinbuttonmodifannee=lookup_widget(button, "Mspinbuttonmodifannee");
Mcomboboxmodiftype=lookup_widget(button, "Mcomboboxmodiftype");
Mradiobutton4=lookup_widget(button, "Mradiobutton4");
Mradiobutton5=lookup_widget(button, "Mradiobutton5");
Mradiobutton6=lookup_widget(button, "Mradiobutton6");
//entrymodifidentifiant=lookup_widget(button,"entrymodifidentifiant");
//comboboxmodifmarque=lookup_widget(button,"comboboxmodifmarque");
Mentrymodifquantite=lookup_widget(button,"Mentrymodifquantite");
sortiem=lookup_widget(button, "Mlabelmodifreus");

strcpy(x,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Mcomboboxmodiftype)));
strcpy(y,gtk_entry_get_text(GTK_ENTRY(Mentrymodifquantite)));
if (Mveriff(x)==0){gtk_label_set_text(GTK_LABEL(sortiem),"ajoutez le type svp!");}
else if (Mveriff(x)==1){
	if(Mveriff(y)==0){gtk_label_set_text(GTK_LABEL(sortiem),"ajoutez la quantite svp !");}
        else if (Mveriff(y)==1){
	if (Mfloatt(y)==0){gtk_label_set_text(GTK_LABEL(sortiem),"ajoutez une valeur valide svp !");}
	else if(Mfloatt(y)==1){
	if((Mfloatt(y)==1)&&(j1==0)){gtk_label_set_text(GTK_LABEL(sortiem),"validez le check button svp !");}
if (j1==1){
strcpy(c.identifiant,id);
strcpy(c.quantite,gtk_entry_get_text(GTK_ENTRY(Mentrymodifquantite)));
c.date.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Mspinbuttonmodifjour));
c.date.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Mspinbuttonmodifmois));
c.date.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Mspinbuttonmodifannee));
if (nn==1)
{strcpy(Marque,"marque3");}
else if (nn==2)
{strcpy(Marque,"marque2");}
else if (nn==3)
{strcpy(Marque,"marque1");}

strcpy(Type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Mcomboboxmodiftype)));
//strcpy(Marque,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxmodifmarque)));
strcpy(c.type,Type);
strcpy(c.marque,Marque);

Mmodification(id,c);
gtk_label_set_text(GTK_LABEL(sortiem),"Modification effectué avec succés");
}}}}j1=0;}


void
on_Mbuttonaffichboard_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{

STOCK c;
GtkWidget *windowahmedstat;

GtkWidget *Mtreeview12;

windowahmedstat = lookup_widget(button,"windowahmedstat");
Mtreeview12=lookup_widget(windowahmedstat,"Mtreeview12");
Maffichagestat(Mtreeview12);
}


void
on_Mcheckbutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton)){
ll=1;}

}


void
on_Mcheckbutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton)){
j1=1;}

}


void
on_Mradiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton)){
mm=1;}
}


void
on_Mradiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton)){
mm=2;}
}


void
on_Mbuttonpp1_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget  *windowahmedajout,*windowahmedpp;
windowahmedajout = lookup_widget(button,"Windowahmedajout");
gtk_widget_destroy(windowahmedajout);
windowahmedpp=create_windowahmedpp();
gtk_widget_show (windowahmedpp);
}


void
on_Mradiobutton3_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton)){
mm=3;}
}


void
on_Mradiobutton6_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton)){
nn=3;}
}


void
on_Mradiobutton5_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton)){
nn=2;}
}


void
on_Mradiobutton4_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton)){
nn=1;}
}


void
on_Mbuttonpp2_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget  *windowahmedmodif,*windowahmedpp;
windowahmedmodif = lookup_widget(button,"Windowahmedmodif");
gtk_widget_destroy(windowahmedmodif);
windowahmedpp=create_windowahmedpp();
gtk_widget_show (windowahmedpp);
}


void
on_Mbuttonpp3_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget  *windowahmedstat,*windowahmedpp;
windowahmedstat = lookup_widget(button,"Windowahmedstat");
gtk_widget_destroy(windowahmedstat);
windowahmedpp=create_windowahmedpp();
gtk_widget_show (windowahmedpp);
}


//-------------------------------------------------------------------------------------------------------------------------------









void
on_SMbuttonreccc_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget  *ajout_de_la_reclamation,*SMAcceuil;
SMAcceuil = lookup_widget(button,"SMAccueil");
gtk_widget_destroy(SMAcceuil);
ajout_de_la_reclamation=create_ajout_de_la_reclamation();
gtk_widget_show (ajout_de_la_reclamation);
}


/*void
on_SMbuttonMENU_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget  *AZwindowfire,*SMAcceuil;
SMAcceuil = lookup_widget(button,"SMAccueil");
gtk_widget_destroy(SMAcceuil);
AZwindowfire=create_AZwindowfire();
gtk_widget_show (AZwindowfire);
}*/


void
on_SMbuttoncap_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget  *windowpp,*SMAcceuil;
SMAcceuil = lookup_widget(button,"SMAccueil");
gtk_widget_destroy(SMAcceuil);
windowpp=create_windowpp();
gtk_widget_show (windowpp);
}


/*void
on_SMbuttonfoyer_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget  *window3,*SMAcceuil;
SMAcceuil = lookup_widget(button,"SMAccueil");
gtk_widget_destroy(SMAcceuil);
window3=create_window3();
gtk_widget_show (window3);
}*/


void
on_SMbuttonlogoutt_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget  *SMWindowLogin,*SMWindowutil;
SMWindowutil = lookup_widget(button,"SMWindowutil");
gtk_widget_destroy(SMWindowutil);
SMWindowLogin=create_SMWindowLogin();
gtk_widget_show (SMWindowLogin);
}


void
on_AZbuttonlogout_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget  *SMWindowLogin,*windowpp;
windowpp = lookup_widget(button,"windowpp");
gtk_widget_destroy(windowpp);
SMWindowLogin=create_SMWindowLogin();
gtk_widget_show (SMWindowLogin);
}


void
on_AMbuttonlogouttt_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget  *SMWindowLogin,*AMWindowutil;
AMWindowutil= lookup_widget(button,"AMWindowutil");
gtk_widget_destroy(AMWindowutil);
SMWindowLogin=create_SMWindowLogin();
gtk_widget_show (SMWindowLogin);
}


void
on_KHbuttonlogoutttt_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget  *SMWindowLogin,*page_principale;
page_principale= lookup_widget(button,"page_principale");
gtk_widget_destroy(page_principale);
SMWindowLogin=create_SMWindowLogin();
gtk_widget_show (SMWindowLogin);
}


void
on_DBbuttonlogout_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget  *SMWindowLogin,*windowpp;
windowpp = lookup_widget(button,"DBwindowpp");
gtk_widget_destroy(windowpp);
SMWindowLogin=create_SMWindowLogin();
gtk_widget_show (SMWindowLogin);
}

void
on_treeviewappadmin_row_activated      (GtkTreeView     *treeviewappadmin,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
	gchar* identifiant;
	
	GtkTreeModel *Model = gtk_tree_view_get_model(treeviewappadmin);

		if (gtk_tree_model_get_iter(Model, &iter, path)){
				gtk_tree_model_get(GTK_LIST_STORE(Model),&iter,1,&identifiant, -1);
				strcpy(idadmin,identifiant);}
                                
}
void
on_buttonapprouveradmin_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *treeviewappadmin;
adminapprouver(treeviewappadmin,idadmin);



}


void
on_buttonactualiseradmin_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *treeviewappadmin;
window4=lookup_widget(button,"window4");
treeviewappadmin=lookup_widget(window4,"treeviewappadmin");
adminaffichage(treeviewappadmin);
}


void
on_buttonsupprimeradmin_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{

	    GtkWidget *treeviewappadmin;
            window4=lookup_widget(button,"window4");
	    treeviewappadmin=lookup_widget(window4,"treeviewappadmin");
	    suppressionadmin(idadmin);
            adminaffichage(treeviewappadmin);


}





void
on_button1_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget  *window3,*SMAcceuil;
window3 = lookup_widget(button,"window3");
gtk_widget_destroy(window3);
SMAcceuil=create_windowpp();
gtk_widget_show (SMAcceuil);
}


void
on_button2_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget  *AZwindowfire,*SMAcceuil;
AZwindowfire = lookup_widget(button,"AZwindowfire");
gtk_widget_destroy(AZwindowfire);
SMAcceuil=create_windowpp();
gtk_widget_show (SMAcceuil);
}




void
on_button3_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget  *ajout_de_la_reclamation,*SMAcceuil;
SMAcceuil = lookup_widget(button,"SMAccueil");
gtk_widget_destroy(SMAcceuil);
ajout_de_la_reclamation=create_window7();
gtk_widget_show (ajout_de_la_reclamation);
}


void
on_buttonrmdp_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowskippp,*window5 ;
utilisateur E;
char x[50];char y[50];
char ch1[20];
char ch2[20];
char ch3[20];
char ch5[20];
char ch9[20];
char ch4[20];
char ch6[20];
char ch7[20];
char ch8[20];
GtkWidget *comboboxentryrollle;
GtkWidget *entryeml;
entryeml=lookup_widget(button,"entryeml");
comboboxentryrollle=lookup_widget(button,"comboboxentryrollle");
strcpy(x,gtk_entry_get_text(GTK_ENTRY(entryeml)));
strcpy(y,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxentryrollle)));
FILE*f;
f=fopen("admin.txt","r+");
if(f!=NULL){
while(fscanf(f,"%s *** %s *** %s *** %s *** %s *** %s *** %s *** %s *** %s\n",ch1,ch2,ch3,ch4,ch6,ch5,ch9,ch7,ch8)!=EOF)
{

if ((strcmp(ch8,x)==0)&&(strcmp(ch5,y)==0))
{mail2(x,ch1,ch2);}
}}
fclose(f);
windowskippp = lookup_widget(button,"window5");
gtk_widget_destroy(windowskippp);
window5=create_SMWindowLogin();
gtk_widget_show (window5);
}

void
on_button4_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowskippp,*window5 ;
windowskippp = lookup_widget(button,"SMWindowLogin");
gtk_widget_destroy(windowskippp);
window5=create_window5();
gtk_widget_show (window5);
}


void
on_button5_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget  *window3,*SMAcceuil;
SMAcceuil = lookup_widget(button,"windowpp");
gtk_widget_destroy(SMAcceuil);
window3=create_window3();
gtk_widget_show (window3);
}


void
on_button6_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget  *AZwindowfire,*SMAcceuil;
SMAcceuil = lookup_widget(button,"windowpp");
gtk_widget_destroy(SMAcceuil);
AZwindowfire=create_AZwindowfire();
gtk_widget_show (AZwindowfire);
}


void
on_br_clicked                          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget  *page_principale,*SMAccueil;
page_principale = lookup_widget(button,"page_principale");
gtk_widget_destroy(page_principale);
SMAccueil=create_SMAccueil();
gtk_widget_show (SMAccueil);
}


void
on_br1_clicked                         (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget  *statistique,*page_principale;
statistique = lookup_widget(button,"statistique");
gtk_widget_destroy(statistique);
page_principale=create_window7();
gtk_widget_show (page_principale);
}

void
on_br2_clicked                         (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget  *SMWindowAjout,*SMWindowutil;
SMWindowAjout= lookup_widget(button,"SMWindowAjout");
gtk_widget_destroy(SMWindowAjout);
SMWindowutil=create_SMWindowutil();
gtk_widget_show (SMWindowutil);
}

void
on_br3_clicked                         (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget  *SMwindowmodifierr,*SMWindowutil;
SMwindowmodifierr = lookup_widget(button,"SMwindowmodifierr");
gtk_widget_destroy(SMwindowmodifierr);
SMWindowutil=create_SMWindowutil();
gtk_widget_show (SMWindowutil);
}




void
on_br4_clicked                         (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget  *modification_de_la_reclamation,*page_principale;
modification_de_la_reclamation = lookup_widget(button,"modification_de_la_reclamation");
gtk_widget_destroy(modification_de_la_reclamation);
page_principale=create_page_principale();
gtk_widget_show (page_principale);
}


void
on_button7_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget  *window5,*SMWindowLogin;
window5 = lookup_widget(button,"window5");
gtk_widget_destroy(window5);
SMWindowLogin=create_SMWindowLogin();
gtk_widget_show (SMWindowLogin);
}


void
on_br5_clicked                         (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget  *AMWindowAjout,*AMWindowutil;
AMWindowAjout = lookup_widget(button,"AMWindowAjout");
gtk_widget_destroy(AMWindowAjout);
AMWindowutil=create_AMWindowutil();
gtk_widget_show (AMWindowutil);
}


void
on_br6_clicked                         (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget  *AMwindowmodifierr,*AMWindowutil;
AMwindowmodifierr= lookup_widget(button,"AMwindowmodifierr");
gtk_widget_destroy(AMwindowmodifierr);
AMWindowutil=create_AMWindowutil();
gtk_widget_show (AMWindowutil);
}


void
on_br7_clicked                         (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget  *AMwindowetudd,*AMWindowutil;
AMwindowetudd = lookup_widget(button,"AMwindowetudd");
gtk_widget_destroy(AMwindowetudd);
AMWindowutil=create_AMWindowutil();
gtk_widget_show (AMWindowutil);
}


void
on_lg_clicked                          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget  *SMWindowLogin,*windowahmedpp;
windowahmedpp = lookup_widget(button,"windowahmedpp");
gtk_widget_destroy(windowahmedpp);
SMWindowLogin=create_SMWindowLogin();
gtk_widget_show (SMWindowLogin);
}


void
on_buttonajoutreclammation_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget  *SMWindowLogin,*windowahmedpp;
SMWindowLogin=create_ajout_de_la_reclamation();
gtk_widget_show (SMWindowLogin);
}


void
on_KRtreeview1111_row_activated        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
	gchar* identifiant;
	GtkTreeModel *Model = gtk_tree_view_get_model(treeview);

		if (gtk_tree_model_get_iter(Model, &iter, path)){
				gtk_tree_model_get(GTK_LIST_STORE(Model),&iter,1,&identifiant, -1);
				strcpy(id,identifiant);}
}


void
on_button5KRbuttonsupprimer_clicked    (GtkButton       *button,
                                        gpointer         user_data)
{
RECLAMATION r;
	    GtkWidget *KRtreeview1111;
	    page_principale=lookup_widget(button,"window7");
	    KRtreeview1111=lookup_widget(page_principale,"KRtreeview1111");
	
	    KRsuppression(id,r);
            KRaffichagee(KRtreeview1111);
}


void
on_KRbuttonactualiser111_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *KRtreeview1111;
page_principale=lookup_widget(button,"window7");
KRtreeview1111=lookup_widget(page_principale,"KRtreeview1111");
KRaffichagee(KRtreeview1111);
}


void
on_KRbuttonboard111_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowskipooo,*page_principale;
page_principale= lookup_widget(button,"window7");
gtk_widget_destroy(page_principale);
windowskipooo=create_statistique();
gtk_widget_show (windowskipooo);
}


void
on_KHbuttonlogoutttt111_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget  *SMWindowLogin,*page_principale;
page_principale= lookup_widget(button,"window7");
gtk_widget_destroy(page_principale);
SMWindowLogin=create_SMWindowLogin();
gtk_widget_show (SMWindowLogin);
}


void
on_br111_clicked                       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget  *page_principale,*SMAccueil;
page_principale = lookup_widget(button,"window7");
gtk_widget_destroy(page_principale);
SMAccueil=create_SMAccueil();
gtk_widget_show (SMAccueil);
}


void
on_KRbuttonrecherche111_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
RECLAMATION r;
GtkWidget *KRentryrech111;
GtkWidget *KRtreeview1111;
FILE*f;
FILE*f2;


page_principale=lookup_widget(button,"window7");
KRentryrech111=lookup_widget(button,"KRentryrech111");
strcpy(idrech,gtk_entry_get_text(GTK_ENTRY(KRentryrech111)));
f=fopen("reclamation.bin","rb");

 if(f!=NULL)
 {
  while(fread(&r,sizeof(RECLAMATION),1,f))
     {
       f2=fopen("recherche.bin","ab+");
       if  (f2!=NULL)
   {  
     
     if ((strcmp(r.nom,idrech)==0)||(strcmp(r.identifiant,idrech)==0)||(strcmp(r.type,idrech)==0))
     { 
     fwrite(&r,sizeof(RECLAMATION),1,f2);
     }
   
     KRtreeview1111=lookup_widget(page_principale,"KRtreeview1111");
     KRrecherche(KRtreeview1111);
    
        fclose(f2);
    }

 }
 fclose(f);
}
remove("recherche.bin");
}


void
on_buttonll_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget  *SMWindowLogin,*page_principale;
page_principale= lookup_widget(button,"window4");
gtk_widget_destroy(page_principale);
SMWindowLogin=create_SMWindowLogin();
gtk_widget_show (SMWindowLogin);
}

