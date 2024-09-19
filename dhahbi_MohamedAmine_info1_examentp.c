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

int main()
{
    struct ordinateur o;
    saisirOrdinateur(&o);
    printf("salem");
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
