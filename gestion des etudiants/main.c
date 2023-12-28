#include <stdio.h>
#include <stdlib.h>


struct Etudiant {
    char nom[50];
    int id;
    float notes[5]; // Suppose 5 matières
    float moyenne;
};


void ajouterEtudiant(struct Etudiant *etudiants, int *nbEtudiants) {
    printf("Entrez le nom de l'etudiant: ");
    scanf("%s", etudiants[*nbEtudiants].nom);
    etudiants[*nbEtudiants].id = *nbEtudiants + 1;

    printf("Etudiant ajoute avec succes!\n");
    (*nbEtudiants)++;
}


void enregistrerNotes(struct Etudiant *etudiants, int nbEtudiants) {
    int id, i;

    printf("Entrez l'ID de l'etudiant: ");
    scanf("%d", &id);


    for (i = 0; i < nbEtudiants; i++) {
        if (etudiants[i].id == id) {
            printf("Entrez les notes pour l'etudiant %s:\n", etudiants[i].nom);
            for (int j = 0; j < 5; j++) {
                printf("Note pour la matiere %d: ", j + 1);
                scanf("%f", &etudiants[i].notes[j]);
            }
            printf("Notes enregistrees avec succes!\n");
            return;
        }
    }

    printf("Etudiant non trouve!\n");
}


void calculerMoyenne(struct Etudiant *etudiants, int nbEtudiants) {
    int i, j;

    for (i = 0; i < nbEtudiants; i++) {
        float somme = 0;
        for (j = 0; j < 5; j++) {
            somme += etudiants[i].notes[j];
        }
        etudiants[i].moyenne = somme / 5;
    }

    printf("Moyennes calculees avec succes!\n");
}


void afficherResultats(struct Etudiant *etudiants, int nbEtudiants) {
    int i, j;

    for (i = 0; i < nbEtudiants; i++) {
        printf("Etudiant %s (ID: %d)\n", etudiants[i].nom, etudiants[i].id);
        printf("Notes: ");
        for (j = 0; j < 5; j++) {
            printf("%.2f ", etudiants[i].notes[j]);
        }
        printf("\nMoyenne: %.2f\n\n", etudiants[i].moyenne);
    }
}

int main() {
    struct Etudiant etudiants[100];
    int choix, nbEtudiants = 0;

    do {
        printf("Menu:\n");
        printf("1. Ajouter un etudiant\n");
        printf("2. Enregistrer des notes\n");
        printf("3. Calculer les moyennes\n");
        printf("4. Afficher les resultats\n");
        printf("5. Quitter\n");
        printf("Choix: ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                ajouterEtudiant(etudiants, &nbEtudiants);
                break;
            case 2:
                enregistrerNotes(etudiants, nbEtudiants);
                break;
            case 3:
                calculerMoyenne(etudiants, nbEtudiants);
                break;
            case 4:
                afficherResultats(etudiants, nbEtudiants);
                break;
            case 5:
                printf("Au revoir!\n");
                break;
            default:
                printf("Choix invalide. Veuillez entrer un nombre entre 1 et 5.\n");
        }
    } while (choix != 5);

    return 0;
}
