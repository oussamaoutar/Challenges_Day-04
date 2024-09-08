#include <stdio.h>
#include <stdlib.h>

// Fonction de recherche linéaire pour trouver le maximum du tableau
int rechLineaire(int T[], int taille) {
    int max = T[0];
    int indexMax = 0;
    for(int i=0; i<taille; i++) if(T[i]>max) {
        max = T[i];
        indexMax = i;
    } 
    printf("Le maximum est: %d\nIndice: %d", max, indexMax);
} 

int main() {

    int T[] = {5, 3, 43, -1, 0};
    int taille = (sizeof(T) / sizeof(int)); // Calcul de la taille du tableau T
    rechLineaire(T, taille);

    return 0;
}