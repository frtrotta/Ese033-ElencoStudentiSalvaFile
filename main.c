#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definisci le costanti
#define N 3
#define MAX_STRLEN 30
#define FNAME "elenco.dat"

// Definisci il tipo di dato struct s_studente
struct s_studente {
    char nome[MAX_STRLEN+1];
    char cognome[MAX_STRLEN+1];
    int eta;
    char classe[MAX_STRLEN+1];
};

// Definisci studente come struct s_studente
typedef struct s_studente studente;

int main(int argc, char** argv) {
    // Dichiara le variabili locali
    studente elenco[N];
    int i;
    FILE *outf;
    int written;
    
    // Codice per l'inserimento, da parte dell'utente, dei dati in un array
    printf("Inserisci i dati per %d studenti\n", N);
    for(i=0; i<N; i++) {
        printf("\nInserisci il nome (%d max): ", MAX_STRLEN);
        scanf("%s", elenco[i].nome);
        printf("Inserisci il cognome (%d max): ", MAX_STRLEN);
        scanf("%s", elenco[i].cognome);
        printf("Inserisci l'eta': ");
        scanf("%d", &(elenco[i].eta));
        printf("Inserisci la classe (%d max): ", MAX_STRLEN);
        scanf("%s", elenco[i].classe);
    }
    
    // Codice per la scrittura dell'elenco su file
    outf = fopen(FNAME, "wb");
    
    if(outf == NULL) {
        fprintf(stderr, "Impossibile aprire il file %s\n", FNAME);
        exit(1);
    }
    else {
        printf("\nFile %s aperto\n", FNAME);
    }
    
    written = fwrite(elenco, sizeof(studente), N, outf);
    if(written != N) {
        fprintf(stderr, "Errore di scrittura nel file\n");
        exit(2);
    }
    else {
        printf("Dati scritti su %s\n", FNAME);
    }
    fclose(outf);
    
    return (EXIT_SUCCESS);
}
