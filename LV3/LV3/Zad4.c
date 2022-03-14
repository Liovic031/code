
/*Deklarirati strukturu stan koja ima �lanove: povr�ina, cijena, adresa, energetski razred, klima
ure�aj [1/0]. Omogu�iti korisniku unos podataka za �eljeni broj stanova (max. 20) u polje struktura.
Ponavljati unos dokle god je �eljeni broj manji od 2, a ve�i od 20. Ispisati podatke o svim unesenim
stanovima kod kojih je cijena po kvadratu manja od 900 eura i sve stanove kojima je cijena ve�a od
1100 eura po kvadratu, a nemaju klima ure�aj.
Ako nema takvih stanova ispisati tekst: �Niti jedan stan ne odgovara kriterijima.�, a ako ima takvih
stanova ispisati ih u formatu �adresa, cijena� za svaki takav stan u novi red.*/


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
    
    printf("Željeni broj stanova (2-20): ");
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