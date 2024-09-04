#include <stdio.h>
#include <string.h>

// Déclaration des constantes
#define MAX_livres 100
#define titre_lenght 50
#define auteur_lenght 50

// Déclaration des variables
int j,i,quantite[MAX_livres], total_liv = 0;
float prix[MAX_livres];
char titre[MAX_livres][titre_lenght], auteur[MAX_livres][auteur_lenght];

// Fonction pour ajouter un livre
void AjouterLivre() {
    if (total_liv < MAX_livres) {
        printf("Donner le titre du livre\n");
        scanf("%s", titre[total_liv]);
        printf("Donner l'auteur du livre\n");
        scanf("%s", auteur[total_liv]);
        printf("Donner le prix du livre\n");
        scanf("%f", &prix[total_liv]);
        printf("Donner la quantité de livres\n");
        scanf("%d", &quantite[total_liv]);
        total_liv++; // Incrémenter le nombre total de livres
        printf("le titre est ajouter avec succes\n");
    } else {
        printf("Vous ne pouvez pas ajouter plus de livres\n");
    }
}
void AfficherLivre(){

        for (i=0;i<total_liv;i++){
            printf("les informations du livre trouvé est: titre:%s,auteur:%s,prix:%f,quantite:%d \n",titre[i],auteur[i],prix[i],quantite[i]);
        }

}
int  RechercherLivre(){
char rechercherlivre[titre_lenght];
printf("entrer  le livre rechercher\n");
scanf("%s",rechercherlivre);
int tr=0;

for(i=0;i<total_liv;i++){
    if(strcmp(titre[i],rechercherlivre) == 0){
    printf("livre trouver,titre :%s,auteur:%s,prix:%f,quantite:%d",titre[i],auteur[i],prix[i],quantite[i]);
    return 1;

    }
   else return 0;
    break;
    }



}
void ModifierQuantite(){
    int x=RechercherLivre();
    for(int i=0;i<total_liv;i++){
        if(x){
       printf("Entrer la nouvelle quantite");
       scanf("%d",&quantite[i]);
       printf("la quantite est mise a jour avec succes.\n");
   }
    }

}
int SupprimerLivre(){
    int c =RechercherLivre();
    for(j=i;j<total_liv;j++){
        strcpy(titre[j],titre[j+1]);
        strcpy(auteur[j],auteur[j+1]);
        prix[j]=prix[j+1];
        quantite[j]=quantite[j+1];
        printf("le livre est supprimer avec succes:\n");
    }
        total_liv--;

    return 1;

}
void AfficherNBT(){
    int totalQuan =0;
    for(i=0;i<total_liv;i++){
        totalQuan+=quantite[i];
    }
    printf("le nombre total des livres est :%d\n",totalQuan);
}


int main() {
    int d;
    do {
        printf("La gestion de stock\n");
        printf("1: Ajouter un livre\n");
        printf("2: Afficher un livre\n");
        printf("3: Modifier la quantite\n");
        printf("4: Rechercher un livre\n");
        printf("5: Supprimer un livre\n");
        printf("6: Afficher le nombre total des livres\n");

        printf("Quelle est votre demande ? ");
        scanf("%d", &d);

        switch (d) {
            case 1:
                AjouterLivre();
                break;
            case 2:
                 AfficherLivre();
                break;
            case 3:
                 ModifierQuantite();
                break;
            case 4:
                 RechercherLivre();
                break;
            case 5:
                 SupprimerLivre();
                break;
            case 6:
               AfficherNBT();
                break;
            default:
                printf("Demande introuvable\n");
                break;
        }
    } while (d != 6);

    return 0;
}
