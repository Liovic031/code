#include<stdio.h>

struct datum {
    unsigned short dan;
    unsigned short mjesec;
    unsigned short godina;
};
struct itTvrtka {
    char ime[20];
    char prezime[20];
    unsigned long long oib;
    float placa;
    struct datum datumRodjenja;
};

int main(void){
    int n;
    
    printf("Unesi broj programera [1, 16>: ");
    do{
        scanf("%d", &n);
    }while(n < 1 || n >= 16);
    
    struct itTvrtka programeri[15];
    
    for(int i = 0; i < n; i++){
        printf("Unesite ime %d programera. \n", i + 1);
        scanf("%19s", programeri[i].ime);
        printf("Unesite prezime %d. programera\n", i + 1);
        scanf("%19s", programeri[i].prezime);
        printf("Unesite oib %d. programera\n", i + 1);
        scanf("%llu", &programeri[i].oib);
        printf("Unesite placu %d. programera\n", i + 1);
        scanf("%f", &programeri[i].placa);
        printf("Unesite dan rodjendan %d. programera\n", i + 1);
        scanf("%hu", &programeri[i].datumRodjenja.dan);
        printf("Unesite mjesec rodjendan %d. programera\n", i + 1);
        scanf("%hu", &programeri[i].datumRodjenja.mjesec);
        printf("Unesite godinu rodjendan %d. programera\n", i + 1);
        scanf("%hu", &programeri[i].datumRodjenja.godina);
    }
    float max = programeri[0].placa;
    int k = 0;
    for(int i = 0; i < n; i++){
        if(programeri[i].placa > max){
            max = programeri[i].placa;
            k = i;
        }
    }
    printf("\n");
    printf("Ime programera: %s\nPrezime programera: %s\noib programera: %llu\nPlaca programera: %.2f\nDatum rodenja programera: %2hu.%2hu.%4hu.\n"
    , programeri[k].ime, programeri[k].prezime, programeri[k].oib, programeri[k].placa, programeri[k].datumRodjenja.dan, programeri[k].datumRodjenja.mjesec, 
    programeri[k].datumRodjenja.godina);

    return 0;
}
