#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIVRES 100    // Maximum number of books
#define MAX_TITRE 50      // Maximum length of a book title
#define MAX_AUTEUR 50     // Maximum length of an author's name

typedef struct {
    char titre[MAX_TITRE];
    char auteur[MAX_AUTEUR];
    int quantite;
    float prix;
} Livre;

int count = 0;  // To track the number of books

// Function to display all books in stock
void afficherLivre(Livre stock[], int count) {
    for (int i = 0; i < count; i++) {  // Loop over the stock
        printf("Livre %d:\n", i + 1);
        printf("Titre: %s\n", stock[i].titre);
        printf("Auteur: %s\n", stock[i].auteur);
        printf("Prix: %.2f\n", stock[i].prix);
        printf("Quantité: %d\n\n", stock[i].quantite);
    }
}

int main() {
    Livre stock[MAX_LIVRES];  // Array of books

    int choice;
    char titre_rechercher[MAX_TITRE];

    do {
        // Display menu
        printf("\nMenu:\n");
        printf("1: Ajouter un livre au stock.\n");
        printf("2: Afficher tous les livres disponibles.\n");
        printf("3: Rechercher un livre par son titre.\n");
        printf("4: Mettre à jour la quantité d'un livre.\n");
        printf("5: Supprimer un livre du stock.\n");
        printf("6: Afficher le nombre total de livres en stock.\n");
        printf("0: Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choice);
        getchar();  // To consume newline after scanf

        switch (choice) {
            case 1:  // Add a book to the stock
                if (count < MAX_LIVRES) {
                    printf("Entrer le Titre du livre:\n");
                    fgets(stock[count].titre, MAX_TITRE, stdin);
                    stock[count].titre[strcspn(stock[count].titre, "\n")] = '\0';  // Remove newline

                    printf("Entrer l'Auteur du livre:\n");
                    fgets(stock[count].auteur, MAX_AUTEUR, stdin);
                    stock[count].auteur[strcspn(stock[count].auteur, "\n")] = '\0';  // Remove newline

                    printf("Entrer le prix du livre: ");
                    scanf("%f", &stock[count].prix);
                    printf("Entrer la quantité en stock: ");
                    scanf("%d", &stock[count].quantite);
                    getchar();  // To consume newline after scanf

                    count++;  // Increment the book count
                } else {
                    printf("Le stock est plein.\n");
                }
                break;

            case 2:  // Display all available books
                if (count == 0) {
                    printf("Le stock est vide.\n");
                } else {
                    afficherLivre(stock, count);
                }
                break;

            case 0:  // Exit the program
                printf("Quitter le programme.\n");
                break;

            default:
                printf("Choix invalide. Essayez encore.\n");
                break;
        }

    } while (choice >= 0 && choice <= 6);  // Loop until choice is between 0 and 6

    return 0;
}
