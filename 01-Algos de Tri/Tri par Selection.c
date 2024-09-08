#include <stdio.h>
#include <stdlib.h>

int main() {

    int T[] = {5, 3, 43, -1, 0};
    int i, j, indice;
    int taille = (sizeof(T) / sizeof(int)); // Calcul de la taille du tableau T

    // Tri avant tri
    printf("Tableau avant tri: \n");
    for(i=0; i<taille; i++) {
        printf("%d ", T[i]);
    }

    // Tri par Sélection
    for(i=0; i<(taille-1); i++){
        indice = i;
        for(j=i+1; j<taille; j++) {
            if (T[indice] > T[j]) indice = j;
        }
        if (indice != i) {
            int temp = T[i];
            T[i] = T[indice];
            T[indice] = temp;
        }
    }

    // Tri après tri
    printf("\nTableau après tri: \n");
    for(i=0; i<taille; i++) {
        printf("%d ", T[i]);
    }

    return 0;
}