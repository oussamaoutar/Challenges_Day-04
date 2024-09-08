#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Fonction de recherche linéaire pour trouver une sous-chaîne dans une chaîne de caractères
int rechLineaire(char ch[], char sCh[]) {
    int tailleCh = strlen(ch);
    int tailleSCh = strlen(sCh);
    for(int i=0; i<=tailleCh-tailleSCh; i++) {
        int j;
        for(j=0; j<tailleSCh; j++) if(ch[i+j] != sCh[j]) break;
        if(j==tailleSCh) return i; // i est l'indice de la première occurrence
    }
    return -1;
} 

int main() {

    char ch[] = "Oussama Outar";
    // char sCh[] = "Outar";
    char sCh[] = "test";
    if(rechLineaire(ch, sCh)==-1) printf("La sous-chaîne n'est pas trouvée!!");
    else printf("%d", rechLineaire(ch, sCh));

    return 0;

}