#include <stdio.h>
#include <stdlib.h>

// Fonction de tri à bulles
void triABulles(int T[], int taille) {
    for(int i=0; i<taille-1; i++) {
        for(int j=0; j<taille-i-1; j++) {
            if(T[j] > T[j+1]) {
                int temp = T[j];
                T[j] = T[j+1];
                T[j+1] = temp;
            }
        }
    }
}

// Fonction de recherche binaire
int rechBinaire(int T[], int el, int inf, int sup) {
    while(inf<=sup) {
        int milieu = (inf+sup) / 2;
        if(T[milieu] == el) return milieu;
        else if(T[milieu] < el) inf = milieu +1;
        else sup = milieu - 1;
    }
    return -1;
} 

int main() {

    int T[] = {5, 3, 43, -1, 0};
    int element = 7;
    // int element = 5;
    int taille = (sizeof(T) / sizeof(T[0])); // Calcul de la taille du tableau T
    
    // Trier le tableau T
    triABulles(T, taille);

    if(rechBinaire(T, element, 0, taille-1) == -1) printf("Element non trouvé!");
    else printf("Element trouvé.");

    return 0;
}