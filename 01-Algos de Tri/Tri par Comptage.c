#include <stdio.h>
#include <stdlib.h>

// la fonction triComptage applique l'algo de tri par comptage
void triComptage(int T[], int taille) {
    int N[taille];
    int max = T[0];
    int min = T[0];
    for(int i=1; i<taille; i++) {
        if(T[i] > max) max = T[i];
        if(T[i] < min) min = T[i];
    }
    int range = max - min +1;
    int compte[range];
    for(int i=0; i<range; i++) compte[i] = 0;
    for(int i=0; i<taille; i++) compte[T[i]-min]++;
    for(int i=1; i<range; i++) compte[i]+=compte[i-1];
    for(int i=taille-1; i>=0; i--) {
        compte[T[i]-min]--;
        N[compte[T[i]-min]] = T[i];
    }
    for(int i=0; i<taille; i++) T[i] = N[i]; // pour tri décroissant : T[i] = N[taille-1-i]
}

int main() {

    int T[] = {5, 3, 43, -1, 0};
    int i, j, indice;
    int taille = (sizeof(T) / sizeof(int)); // Calcul de la taille du tableau T

    // Tri avant tri
    printf("Tableau avant tri: \n");
    for(i=0; i<taille; i++) {
        printf("%d ", T[i]);
    }

    // Tri par Comptage
    triComptage(T, taille);
    
    // Tri après tri
    printf("\nTableau après tri: \n");
    for(i=0; i<taille; i++) {
        printf("%d ", T[i]);
    }

    return 0;
}