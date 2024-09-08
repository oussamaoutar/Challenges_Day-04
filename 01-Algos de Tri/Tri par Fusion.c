#include <stdio.h>
#include <stdlib.h>

void fusion(int T[], int g, int m, int d) {
    int i, j, k;
    int n1 = m-g+1;
    int n2 = d-m;
    int Tg[n1], Td[n2];
    for(i=0; i<n1; i++) Tg[i] = T[g+i];
    for(j=0; j<n2; j++) Td[j] = T[m+1+j];
    i=0; j=0; k=g;
    while(i<n1 && j<n2) {
        if(Tg[i] <= Td[j]) { // pour tri décroissant : Tg[i] >= Td[j]
            T[k] = Tg[i];
            i++;
        }
        else {
            T[k] = Td[j];
            j++;
        }
        k++;
    }
    while(i<n1) {
        T[k] = Tg[i];
        i++;
        k++;
    }
    while(j<n2) {
        T[k] = Td[j];
        j++;
        k++;
    }
}

// la fonction triRapide applique l'algo de tri rapide
void triFusion(int T[], int g, int d) {
    if(g < d) {
        int m = (g+d) / 2;
        triFusion(T, g, m);
        triFusion(T, m+1, d);
        fusion(T, g, m, d);
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

    // Tri Fusion
    triFusion(T, 0, taille-1);
    
    // Tri après tri
    printf("\nTableau après tri: \n");
    for(i=0; i<taille; i++) {
        printf("%d ", T[i]);
    }

    return 0;
}