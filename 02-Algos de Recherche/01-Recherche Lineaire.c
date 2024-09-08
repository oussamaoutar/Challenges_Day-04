#include <stdio.h>
#include <stdlib.h>

// la fonction de recherche linéaire
int rechLineaire(int T[], int taille, int el) {
    for(int i=0; i<taille; i++) if(T[i]==el) return i;
    return -1;
} 

int main() {

    int T[] = {5, 3, 43, -1, 0};
    // int element = 7;
    int element = 5;
    int taille = (sizeof(T) / sizeof(int)); // Calcul de la taille du tableau T
    if(rechLineaire(T, taille, element) == -1) printf("Element non trouvé!");
    else printf("Element trouvé.");

    return 0;
}