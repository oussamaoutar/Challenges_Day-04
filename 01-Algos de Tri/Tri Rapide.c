#include <stdio.h>
#include <stdlib.h>

// La fonction partition divise le tableau autout d'un pivot
int partition(int T[], int bas, int haut) {
    int pivot = T[haut];
    int i = (bas-1), j;
    for(j=bas; j<haut; j++) {
        if(T[j] <= pivot) { // pour un tri décroissant : T[j] >= pivot 
            i++;
            int temp = T[i];
            T[i] = T[j];
            T[j] = temp;
        }
    }
    int temp = T[i];
    T[i] = T[j];
    T[j] = temp;
    return i+1;
}

// la fonction triRapide applique l'algo de tri rapide
void triRapide(int T[], int bas, int haut) {
    if(bas < haut) {
        int pivot = partition(T, bas, haut);
        triRapide(T, bas, pivot-1);
        triRapide(T, pivot+1, haut);
    }
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

    // Tri Rapide
    triRapide(T, 0, taille-1);
    
    // Tri après tri
    printf("\nTableau après tri: \n");
    for(i=0; i<taille; i++) {
        printf("%d ", T[i]);
    }

    return 0;
}