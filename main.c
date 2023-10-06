#include <stdio.h>
#include <stdlib.h>
#define Amax 30
#define Tmax 50


typedef struct str{
     int entier;
     struct str *suivant;
    struct str *precedant;
}LDC;

LDC*AllouerNoeud(){
       LDC *q=(LDC*)malloc(sizeof(LDC));
       if(!q) exit(-1);
       q->suivant=NULL;
       q->precedant=NULL;

       return q;
}

LDC* insert_debut(LDC*L,int ne){
      LDC*q=AllouerNoeud();
      q->entier=ne;
      if(!L) L=q;
      else{
         q->suivant=L;
         L->precedant=q;
         L=q;
     }
     return L;
}

void afficher_a_v(LDC *L){
      LDC*der;
      if(!L) printf("Liste vide\n");
      else{
           for(der=L;der->suivant;der=der->suivant);
           for(;der;der=der->precedant){
           printf("%d->",L->entier);
     }
     printf("\n");
    }
}


LDC* supprimer_liste(LDC *L,int id){
        LDC *courant = L,*elem_sup;
        while(courant){
                if(courant->entier!=id)
                     courant=courant->suivant;
                else{elem_sup=courant;
                    if(courant==L){
                        courant->suivant->precedant = NULL;
                        L=courant->suivant;
                        courant=courant->suivant;
                        free(elem_sup);}
                    else{
                         courant->precedant->suivant=courant->suivant;
                        if(courant->suivant){
                             courant->suivant->precedant=courant->precedant;}
                        courant=courant->suivant;
                        free(elem_sup);

                }
            }
        }


        return L;

}

void afficher_liste(LDC *lsd)
{
    LDC *tmp;
    tmp=lsd;
    while(tmp)
    {
        printf("%d->",tmp->entier);
        tmp=tmp->suivant;
    }
}

int main()
{
 LDC*L=NULL;
 int id;

 int choice;
 do{
    printf("1:Inserer une livre\n");
    printf("2:Afficher la liste des livres\n");
    printf("3:Rechercher les livres d'un auteur\n");
    printf("4:Supprimer un livre en fonction de son id\n");
    printf("5:quitter le programme\n");
    printf("Entrez votre choix: ");
     scanf("%d",&choice);
     switch(choice){
 case 1:
     do{
     printf("Entrez le num: ");scanf("%d",&liv.num);
    } while(liv.num<0);
      printf("Entrez le nom d auteur: ");scanf("%s",liv.auteur);
      printf("Entrez le titre: ");scanf("%s",liv.titre);
      printf("Entrez l editeur: ");scanf("%s",liv.editeur);
      printf("Entrez l annee: ");scanf("%d",&liv.annee);
      L=insertH(L,liv);break;

 case 2:
    afficherAr(L);break;
 case 3:
     printf("Entrez le nom d auteur: ");scanf("%s",Auteur);
     afficherLivresParAuteur(L,Auteur);break;
 case 4:
     printf("Entrez l id: ");scanf("%d",&id);
     L=supprimerLivre(L,id);break;
 case 5: break;
 default:printf("choix invalide");
     }

 }while(choice);
 return 0;
}
