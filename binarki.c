#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 50

struct ksiazka {
    char autor[25], tytul[30];
    int rokWydania, liczbaStron;
    double cena;
    char wypozyczona;
    int ileWypozyczen;
};

void stworzPierwszyPlik(char*);

void zapisz(char*, char*, char*);

int main() {
    char *d1, *d2, *zadAutor;
    d1 = malloc(sizeof(char*)*N);
    d2 = malloc(sizeof(char*)*N);
    zadAutor = malloc(sizeof(char*)*N);
    strcpy(d1, "pierwszy.bin");
    strcpy(d2, "drugi.bin");
    printf("podaj autora: ");
    gets(zadAutor);
    stworzPierwszyPlik(d1);
    zapisz(d1, d2, zadAutor);
    free(d1);
    free(d2);
    return 0;
}

void zapisz(char *dir1, char *dir2, char *zadAutor) {
    FILE *f1, *f2;
    struct ksiazka szukanaK;
    if((f1 = fopen(dir1, "rb")) == NULL) {
        printf("Nie mozna otworzyc pliku PIERWSZEGO do ODCZYTU");
        exit(1);
    }
    if((f2 = fopen(dir2, "wb")) == NULL) {
        printf("Nie mozna otworzyc pliku DRUGIEGO do ZAPISU");
        exit(1);
    }
    while(1) {
        fread(&szukanaK, sizeof(struct ksiazka), 1, f1);
        if(feof(f1))
            break;
        if(strcmp(szukanaK.autor, zadAutor) == 0)
            fwrite(&szukanaK, sizeof(struct ksiazka), 1, f2);
    }
    fclose(f1);
    fclose(f2);
}

void stworzPierwszyPlik(char *dir1) { //TWORZY PIERWSZA STRUKTURE I ZAPISUJE DO PLIKU
    FILE *f1;
    struct ksiazka K1 = {"Bielawski", "Upierdole Was wszystkich", 2009, 505, 10.99, 't', 10};
    if((f1 = fopen(dir1, "wb")) == NULL) {
        printf("Nie mozna otworzyc pliku PIERWSZEGO do ZAPISU");
        exit(1);
    }
    fwrite(&K1, sizeof(struct ksiazka), 1, f1);
    fclose(f1);
}
