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
    int temp = T[i+1];
    T[i+1] = T[haut];
    T[haut] = temp;
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

// afficher les éléments du tableau passé en paramètres
void affichage(int T[], int taille) {
    for(int i=0; i<taille; i++) {
        printf("%d ", T[i]);
    }
}

int rechBinaire(int T[], int x, int inf, int sup) {
    while(inf<=sup) {
        int milieu = (inf + sup)/2;
        if(T[milieu] == x) return milieu;
        else if(T[milieu] < x) inf = milieu+1;
        else sup = milieu-1;
    }
    return -1;
}

// on recherche si tous les éléments du sous tabelau "sT" sont dans le tableau T
int rechSousTab(int T[], int taille, int sT[], int tailleST) {
    for(int i=0; i<tailleST; i++) {
        if(rechBinaire(T, sT[i], 0, taille-1)==-1) return 0;
    }
    return 1;
}

int main() {
    int T[] = {5, 3, 43, -1, 0};
    int taille = (sizeof(T) / sizeof(int)); // Calcul de la taille du tableau T
    int sT[] = {5, -1};
    // int sT[] = {999, -1}; 
    int tailleST = (sizeof(sT) / sizeof(sT[0])); // Calcul de la taille du tableau sT

    // Tableau avant tri
    printf("Tableau avant tri: \n");
    affichage(T, taille);

    // Tri Rapide
    triRapide(T, 0, taille-1);
    
    // Tableau après tri
    printf("\nTableau après tri: \n");
    affichage(T, taille);

    if(rechSousTab(T, taille, sT, tailleST)) printf("\nsT est présent dans T");
    else printf("\nST n'est pas présent dans T");

    return 0;
}