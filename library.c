#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


#define MAX_LIVRES 100    // Maximum number of books
#define MAX_TITRE 50      // Maximum length of a book title
#define MAX_AUTEUR 50 
typedef struct {
    char titre[MAX_TITRE];
    char auteur[MAX_AUTEUR];
    int quantite;
    float prix;

}Livre;
int count = 0;
void afficherLivre(Livre stock[], int count) {
   for (int i = 0; i < count; i++) {
        printf(" les titres :  %s",stock[i].titre);
         printf(" les auteurs :  %s",stock[i].auteur);
          printf(" les prix :  %f",stock[i].prix);
           printf(" la quantites :  %d",stock[i].quantite);
}
}
int rechercherLivre(Livre stock[], int count, char titre_rechercher[]) {
    for (int i = 0; i < count; i++) {
        if (strcmp(stock[i].titre, titre_rechercher) == 0) {
            return i;  // Return the index of the book if found
        }
    }
    return -1;  // Return -1 if the book is not found
}
void afficherQuantiteTotale(Livre stock[], int count) {
    int total = 0;
    for (int i = 0; i < count; i++) {
        total += stock[i].quantite;
    }
    printf("Quantité totale de livres en stock: %d\n", total);
}
void supprimerLivre(Livre stock[], int *count, int index) {
    for (int i = index; i < (*count) - 1; i++) {
        stock[i] = stock[i + 1];  // Shift the array to the left
    }
    (*count)--;  // Decrease the count of books
    printf("Livre supprimé avec succès.\n");
}
int main(){
    Livre stock[MAX_LIVRES];
    
    int choice;
    
    char titre_rechercher[MAX_TITRE];
do{
printf("1;Ajouter un livre au stock. \n");
printf("2;Afficher tous les livres disponibles.\n");
printf("3;Rechercher un livre par son titre.\n");
printf("4;Mettre à jour la quantité d'un livre.\n");
printf("5;Supprimer un livre du stock.\n");
printf("6;Afficher le nombre total de livres en stock.\n");
printf("0;quitter\n");
printf("your choice : ");
scanf(" %d", &choice);
getchar();

switch(choice){
    case 1:
        if(count<MAX_LIVRES){
        
    printf("entrer le Titre du livre.\n");   
    fgets(stock[count].titre,MAX_TITRE, stdin);
    stock[count].titre[strcspn(stock[count].titre, "\n")] = '\0'; 
    printf("entrer l'Auteur du livre\n");
    fgets(stock[count].auteur,MAX_AUTEUR,stdin);
   stock[count].auteur[strcspn(stock[count].auteur, "\n")] = '\0';
    printf("entrer le prix de livre\n");
    scanf("%f",&stock[count].prix);
    printf("entrer la quantite en stock\n");
    scanf("%d",&stock[count].quantite);
    count++;
    } else {
        printf("le stock est pleine.\n");
    }
    break;
    case 2 :
    if(count<= 0){
        printf("le sotck est empty");
    }else{
    afficherLivre(stock, count);
    }
    break;
    case 3:  
                printf("Entrer le titre du livre pour mettre à jour la quantité: ");
                fgets(titre_rechercher, MAX_TITRE, stdin);
                gitchar(); // Remove newline

                index = rechercherLivre(stock, count, titre_rechercher);
                if (index != -1) {
                    printf("Entrer la nouvelle quantité: ");
                    scanf("%d", &stock[index].quantite);
                    printf("Quantité mise à jour avec succès.\n");
                } else {
                    printf("Livre non trouvé.\n");
                }
                break;
                case 4:  // Delete a book from stock
                printf("Entrer le titre du livre à supprimer: ");
                fgets(titre_rechercher, MAX_TITRE, stdin);
                titre_rechercher[strcspn(titre_rechercher, "\n")] = '\0';  // Remove newline

                index = rechercherLivre(stock, count, titre_rechercher);
                if (index != -1) {
                    supprimerLivre(stock, &count, index);
                } else {
                    printf("Livre non trouvé.\n");
                }
                break;
                case 4:  // Delete a book from stock
                printf("Entrer le titre du livre à supprimer: ");
                fgets(titre_rechercher, MAX_TITRE, stdin);
                titre_rechercher[strcspn(titre_rechercher, "\n")] = '\0';  // Remove newline

                index = rechercherLivre(stock, count, titre_rechercher);
                if (index != -1) {
                    supprimerLivre(stock, &count, index);
                } else {
                    printf("Livre non trouvé.\n");
                }
                break;
  case 5:  // Display the total number of books in stock
                afficherQuantiteTotale(stock, count);
                break;

            case 0:  // Exit the program
                printf("Quitter le programme.\n");
                break;

            default:
                printf("Choix invalide. Essayez encore.\n");
                break;

    }

    
}
while (choice >= 0 && choice <= 6);
return 0;

}
