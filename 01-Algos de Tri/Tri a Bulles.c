#include <stdio.h>
#include <stdlib.h>

int main() {
    int T[] = {5, 3, 43, -1, 0};
    int i, j, temp;
    int taille = (sizeof(T)/sizeof(int));
    printf("Tableau avant tri: \n");
    for(i=0; i<taille; i++) {
        printf("%d ", T[i]);
    }
    for(i=0; i<taille-1; i++) {
        for(j=0; j<taille-i-1; j++) {
            if(T[j] > T[j+1]) {
                temp = T[j];
                T[j] = T[j+1];
                T[j+1] = temp;
            }
        }
    }
    printf("\nTableau après tri: \n");
    for(i=0; i<taille; i++) {
        printf("%d ", T[i]);
    }
    return 0;
}