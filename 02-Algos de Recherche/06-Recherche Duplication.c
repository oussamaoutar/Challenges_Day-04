#include <stdio.h>
#include <stdlib.h>

// Fonction de recherche linéaire pour vérifier s'il existe des doublons dans le tableau
int rechLineaire(int T[], int taille) {
    for(int i=0; i<taille-1; i++) 
        for(int j=i+1; j<taille; j++)
            if(T[i]==T[j]) return 1;
    return -1;
} 

int main() {

    int T[] = {5, 3, 43, -1, 0};
    int taille = (sizeof(T) / sizeof(int)); // Calcul de la taille du tableau T
    if(rechLineaire(T, taille)==1) printf("Il y a des doublons");
    else printf("Il n'y a pas des doublons");

    return 0;
}