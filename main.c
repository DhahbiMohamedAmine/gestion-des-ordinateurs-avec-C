#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ordinateur
{
    char marque[15];
    int memoire;
    int quantite;
    float prix;
};

struct cellule
{
    struct ordinateur info;
    struct cellule *suiv;
};

typedef struct cellule* pile;
typedef struct cellule* liste;

void saisirOrdinateur(struct ordinateur *o);
void ajouterOrdinateur(liste *L);
void afficherOrdinateurs(liste L);
int main()
{
    liste L = NULL;
    pile P = NULL;
    int choix;

    do {
        printf("Menu:\n");
        printf("1. Ajouter un ordinateur\n");
        printf("2. Afficher les ordinateurs\n");
        printf("3. Vendre un ordinateur\n");
        printf("4. Empiler les ordinateurs en rupture de stock\n");
        printf("5. Approvisionner un ordinateur\n");
        printf("6. Quitter\n");
        printf("Choix: ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                ajouterOrdinateur(&L);
                break;
            case 2:
                afficherOrdinateurs(L);
                break;
            case 3:
                vendreOrdinateur(&L);
                break;
            case 4:
                empilerRuptureStock(&P, &L);
                break;
            case 5:
                approvisionnerOrdinateur(&L);
                break;
            case 6:
                printf("Au revoir!\n");
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
        }
    } while (choix != 6);

    return 0;
}

void saisirOrdinateur(struct ordinateur *o)
{
    printf("Donner la marque de l'ordinateur: ");
    scanf("%s", o->marque);
    printf("Donner la mémoire de l'ordinateur: ");
    scanf("%d", &(o->memoire));
    printf("Donner la quantité de l'ordinateur: ");
    scanf("%d", &(o->quantite));
    printf("Donner le prix de l'ordinateur: ");
    scanf("%f", &(o->prix));
}
void ajouterOrdinateur(liste *L)
{
    struct cellule *k = (struct cellule*) malloc(sizeof(struct cellule));
    saisirOrdinateur(&(k->info));
    k->suiv = *L;
    *L = k;
    printf("Ordinateur ajouté avec succès.\n");
}

void afficherOrdinateurs(liste L)
{
    if (L == NULL) {
        printf("Liste vide.\n");
    } else {
        printf("Liste des ordinateurs:\n");
        while (L != NULL) {
            printf("Marque: %s, Mémoire: %d Go, Prix: %.2f\n", L->info.marque, L->info.memoire, L->info.prix);
            L = L->suiv;
        }
    }
}
