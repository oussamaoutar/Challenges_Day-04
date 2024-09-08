#include <stdio.h>
#include <stdlib.h>

// Fonction de recherche linéaire pour trouver le minimum du tableau
int rechLineaire(int T[], int taille) {
    int min = T[0];
    for(int i=0; i<taille; i++) if(T[i]<min) min = T[i];
    return min;
} 

int main() {

    int T[] = {5, 3, 43, -1, 0};
    int taille = (sizeof(T) / sizeof(int)); // Calcul de la taille du tableau T
    printf("Le minimum est: %d", rechLineaire(T, taille));

    return 0;
}