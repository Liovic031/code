/******************************************************************************
3. Napisati program u C jeziku u kojem se treba kreirati novi složeni tip podatka struct cijeli_broj pod
nazivom CIJELI_BROJ. Struktura CIJELI_BROJ treba sadržavati dva cijela člana tipa long za
uneseni_broj i int za broj_znamenaka. U član uneseni_broj potrebno je upisati generirani P-S broj
iz intervala [-2147483648, 2147483647], a u član broj_znamenaka potrebno je upisati koliko
generirani broj ima znamenaka. Za generiranje P-S vrijednosti potrebno je koristiti funkciju koja ne
prima argumente, a vraća P-S generiranu vrijednost, a za izračunavanje broja znamenaka potrebno
je također koristiti funkciju koja prima P-S generirani broj (član uneseni_broj) te izračunava i vraća
broj znamenaka. U glavnom dijelu programa potrebno je kreirati polje struktura CIJELI_BROJ od 40
elemenata, te pomoću ranije spomenutih funkcija popuniti članove pojedine strukture iz polja
struktura. Pronaći i ispisati sve članove strukture koja ima najveći, kao i strukturu koja ima najmanji
broj znamenaka generiranog broja.
*******************************************************************************/
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
long int pseudoSlucajni();

int znamenke(long int a);

typedef struct cijeli_broj{
    long int uneseni_broj;
    int broj_znamenaka;
}CIJELI_BROJ;


int main()
{
    srand((unsigned)time(NULL));
    CIJELI_BROJ brojevi[40];
    for (int i = 0; i < 40; i++){
        brojevi[i].uneseni_broj = pseudoSlucajni();
        brojevi[i].broj_znamenaka = znamenke(brojevi[i].uneseni_broj);
    }
    
int max = 0;
int min = brojevi[0].broj_znamenaka;

    for(int i = 0; i < 40; i++){
        if(brojevi[i].broj_znamenaka > max){
            max = i;
        }
        if(brojevi[i].broj_znamenaka < min){
            min = i;
        }
    }
    
    printf("Najvise znamenaka: %d. cijeli broj:\n", max + 1);
    printf("uneseni_broj: %ld ", brojevi[max].uneseni_broj);
    printf("broj_znamenaka: %d\n", brojevi[max].broj_znamenaka);
    printf("\n");
    printf("Najmanje znamenaka: %d. cijeli broj:\n", min + 1);
    printf("uneseni_broj: %ld ", brojevi[min].uneseni_broj);
    printf("broj_znamenaka: %d\n", brojevi[min].broj_znamenaka);
    
    return 0;
}

long int pseudoSlucajni(){
    long int x;
    for(int i = 0; i < 40; i++){
        x = -2147483648 + (float)rand()/RAND_MAX * 4294967295;
        return x;
    }
}

int znamenke(long int a){
    int brojac = 0;
    while(a != 0){
        a = a / 10;
        brojac++;
    }
    return brojac;
}
