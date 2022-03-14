
/*Deklarirati strukturu stan koja ima èlanove: površina, cijena, adresa, energetski razred, klima
ureðaj [1/0]. Omoguæiti korisniku unos podataka za željeni broj stanova (max. 20) u polje struktura.
Ponavljati unos dokle god je željeni broj manji od 2, a veæi od 20. Ispisati podatke o svim unesenim
stanovima kod kojih je cijena po kvadratu manja od 900 eura i sve stanove kojima je cijena veæa od
1100 eura po kvadratu, a nemaju klima ureðaj.
Ako nema takvih stanova ispisati tekst: „Niti jedan stan ne odgovara kriterijima.“, a ako ima takvih
stanova ispisati ih u formatu „adresa, cijena“ za svaki takav stan u novi red.*/


#include <stdio.h>

struct stan{
    float povrsina;
    float cijena;
    char adresa[40];
    char enegraz[3];
    int klima;
};


int main()
{
    int n;
    
    printf("Å½eljeni broj stanova (2-20): ");
    do{
        scanf("%d", &n);
    }while(n < 2 || n > 20);
    
    struct stan stanovi[20];
    
    for(int i = 0; i < n; i++){
        printf("Unesite povrsinu %d. stana.\n", i + 1);
        scanf("%f", &stanovi[i].povrsina);
        printf("Unesite cijenu %d. stana.\n", i + 1);
        scanf("%f", &stanovi[i].cijena);
        printf("Unesi energetsku razinu(A+ - G) %d. stana.\n", i + 1);
        scanf("%s", stanovi[i].enegraz);
        printf("Ima li %d. stan klimu(1/0): ", i + 1);
        scanf("%d", &stanovi[i].klima);
        printf("Unesite adresu %d. stana.\n", i + 1);
        scanf("%s", stanovi[i].adresa);
    }
    int k = 0;
    for(int i = 0; i < n; i++){
        if(stanovi[i].klima == 0 && stanovi[i].cijena / stanovi[i].povrsina < 900 || stanovi[i].cijena / stanovi[i].povrsina > 1100 ){
            k++;
            printf("%d. stan:\n", i + 1);
            printf("Adresa: %s ", stanovi[i].adresa);
            printf("Cijena: %f\n", stanovi[i].cijena);
        }
    }
    
    if(k == 0){
        printf("Niti jedan stan ne odgovara kriterijima.");
    }
    
    return 0;
    
}