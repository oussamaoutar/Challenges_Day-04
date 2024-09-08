#include <stdio.h>
#include <stdlib.h>

int main() {

    int T[] = {5, 3, 43, -1, 0};
    int i, j, temp;
    int taille = (sizeof(T) / sizeof(int)); // Calcul de la taille du tableau T

    // Tri avant tri
    printf("Tableau avant tri: \n");
    for(i=0; i<taille; i++) {
        printf("%d ", T[i]);
    }

    // Tri par Insertion
    for(i=1 ; i<=taille-1; i++) {
        j = i;    
        while (j>0 && T[j-1]>T[j]) {
            temp = T[j];
            T[j] = T[j-1];
            T[j-1] = temp;
            j--;
        }
    }

    // Tri après tri
    printf("\nTableau après tri: \n");
    for(i=0; i<taille; i++) {
        printf("%d ", T[i]);
    }

    return 0;
}