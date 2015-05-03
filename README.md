# Ese033-ElencoStudentiSalvaFile

Realizza un programma C che richieda all'utente di inserire i dati di N studenti, 
con N definito dal programmatore pari a 3, e li salvi nel file `elenco.dat`.

I dati di uno studente, da richiedere in questo esatto ordine, sono:

1. nome: stringa di lunghezza massima MAX_STRLEN, definita dal programmatore pari a 30
2. cognome: stringa di lunghezza massima MAX_STRLEN
3. età: intero non negativo
4. classe: stringa di lunghezza massima MAX_STRLEN

Il programma usa array di record, in modo da scrivere tutti gli elementi in un'unica
chiamata a `fwrite`.