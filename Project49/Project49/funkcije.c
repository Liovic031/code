#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funkcije.h"
#include "struktura.h"

int izbornik(void) {

	printf("\t\t************************************\n\n");
	printf("\t\tOdaberite jednu od ponudenih opcija: \n\n");
	printf("\t\t************************************\n\n");

	printf("\t\tOpcija 1: Nova igra\n");
	printf("\t\tOpcija 2: Leaderboard\n");
	printf("\t\tOpcija 3: Izlaz iz igre\n");


	printf("\t\t************************************\n\n");

	int uvijet = 0;
    int brojBodova = 0;
        scanf("%d", &uvijet);

        switch (uvijet) {
        case 1:
            igra();
            break;
        case 2:
            leaderboard();
            break;
        case 3:
            kraj();
            break;
        default:
            uvijet = 1;  
        }
       
        return uvijet;
}


void igra(void) {
    char rijec[50];
    char pomocniString[50];
    int duljina, k, pogodak;
    int zivot = 5;
    char slovo;
    int brPogodjenih = 0;
    int poeni = 0;
    int temp = zivot;


    printf("Unesite zeljenu rijec:\n");
    scanf("%s", rijec);
    duljina = strlen(rijec);

    for (int i = 0; i < duljina; i++) {
        pomocniString[i] = '_';
        k = i;
    }

    pomocniString[k + 1] = '\0';
   
    system("cls");

 
    printf("\n\t______ ");
    printf("\n\t|    | ");
    printf("\n\t|    O ");
    printf("\n\t|      ");
    printf("\n\t|      ");
    printf("\n\t|      ");

    while (temp != 0) {
        
        pogodak = 0;
        
        printf("\nPogodi slovo!\n");
        getchar();
        scanf("%c", &slovo);
       
        for (int i = 0; i < duljina; i++) {
            if (rijec[i] == slovo) {
                pomocniString[i] = rijec[i];
                brPogodjenih++;
                pogodak = 1;
            }
        }
        if (pogodak == 1) {
            prikazVjesala(zivot);
            printf("\nTocno pogodjeno! \n %s\n", pomocniString);
            poeni = poeni + 35;
        }
        else if (pogodak == 0) {
            zivot--;
            temp = zivot;
            prikazVjesala(zivot);
            printf("\nNetocno, pokusajte ponovno! \n %s\n", pomocniString);
        }

        if (brPogodjenih == duljina) {
            printf("Cestitke na pobjedi!\n");
            temp = 0;
            upisuLeaderboard(poeni);
        }

    }
    if (zivot == 0) {
        system("cls");
        printf("\n\t______ ");
        printf("\n\t|    | ");
        printf("\n\t|   %cO/", '\\');
        printf("\n\t|    | ");
        printf("\n\t|   / %c", '\\');
        printf("\n\t|     ");
        printf("\n Nazalost ste izgubili, rijec je bila: %s\n", rijec);
        upisuLeaderboard(poeni);
    }
    
}

void prikazVjesala(int zivot)                          
{

    if (zivot == 1) {
        system("cls");
        printf("\n\t______ ");
        printf("\n\t|    | ");
        printf("\n\t|   %cO/", '\\');
        printf("\n\t|    | ");
        printf("\n\t|     %c", '\\');
        printf("\n\t|      ");
    }
    if (zivot == 2) {
        system("cls");
        printf("\n\t______ ");
        printf("\n\t|    | ");
        printf("\n\t|   %cO/", '\\');
        printf("\n\t|    | ");
        printf("\n\t|      ");
        printf("\n\t|      ");
    }
    if (zivot == 3) {
        system("cls");
        printf("\n\t______ ");
        printf("\n\t|    | ");
        printf("\n\t|   %cO/", '\\');
        printf("\n\t|      ");
        printf("\n\t|      ");
        printf("\n\t|      ");
    }
    if (zivot == 4) {
        system("cls");
        printf("\n\t______ ");
        printf("\n\t|    | ");
        printf("\n\t|   %cO ", '\\');
        printf("\n\t|      ");
        printf("\n\t|      ");
        printf("\n\t|      ");
    }
    if (zivot == 5) {
        system("cls");
        printf("\n\t______ ");
        printf("\n\t|    | ");
        printf("\n\t|    O ");
        printf("\n\t|      ");
        printf("\n\t|      ");
        printf("\n\t|      ");
    }
    
}

void kraj(void) {
	char y = 121;
	char n = 110;
	char o;
	printf("Zelite li izaci iz igre? y(da) ili n(ne)\n");
	scanf("%c", &o);
	if (o == y) {
		exit(EXIT_SUCCESS);
	}
	if (o == n) {
		system("cls");
		izbornik();

	}
    else {
        system("cls");
        printf("Unesite 'y' ili 'n'\n");
		kraj();
    }
		
}



void upisuLeaderboard(int b) {
     FILE* Test = NULL;
     Test = fopen("Ljestvica.bin", "rb");                    
     if (Test == NULL)
     {
           fflush(Test);
           Test = fopen("Ljestvica.bin", "wb");               
           int Broj = 0;
           fwrite(&Broj, sizeof(int), 1, Test);
     }
     fclose(Test);
     PLAYER* igrac = NULL;
     igrac = (PLAYER*)calloc(1, sizeof(PLAYER));
     FILE* fp = NULL;
     fp = fopen("Ljestvica.bin", "rb+");
     if (fp == NULL)
     {
            perror("Otvaranje");
     }
     else
     {
            int x = 0;
            fread(&x, sizeof(int), 1, fp);
            x++;
            fseek(fp, 0, SEEK_SET);
            fwrite(&x, sizeof(int), 1, fp);
            fseek(fp, 0, SEEK_END);
            printf("Osvojeni bodovi: %d\n", b);
            printf("Unesite vase ime: ");
            scanf(" %[^\n]%*c", igrac->ime);
            igrac->bodovi = b;
            fwrite(igrac, sizeof(PLAYER), 1, fp);
            system("cls");
     }
     fclose(fp);
     return;
}

void povratakNaIzbornik(void){

    while ((getchar()) != '\n');
    char i = 105;
    char x;
    printf("\nUnesite i za povratak na izbornik  ");
    scanf("%c", &x);
    if (x == i)
    {
        system("cls");
        izbornik();
    }
    else
    {
        system("cls");
        printf("\nPogresan unos, pokusajte ponovno\n\n");
        povratakNaIzbornik();
    }
}


void leaderboard(void){
    system("cls");
	FILE* fp = NULL;
	fp = fopen("Ljestvica.bin", "rb+");
	if (fp == NULL)
	{
		perror("Error");
		printf("Nema upisanih igraca");                 //ako pokusamo otvoriti ljestvicu dok nema upisanih igraca dobit cemo poruku da trenutacno nema igraca i vratit ce nas u izbornik
		povratakNaIzbornik();
	}
	else
	{
		int y = 0;
		fread(&y, sizeof(int), 1, fp);
		PLAYER* igrac = NULL;
		igrac = (PLAYER*)calloc(y, sizeof(PLAYER));
		fread(igrac, sizeof(PLAYER), y, fp);
		
		
        system("cls");
        sortiranje(igrac, y);
        ispisLjestvice(igrac, y);
        povratakNaIzbornik();
	}
}



void sortiranje(PLAYER* igrac, const int y) {
    int min = 0;
    for (int i = 0; i < y - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < y; j++)
        {
            if ((igrac + j)->bodovi > (igrac + min)->bodovi)
            {
                min = j;
            }
        }
        zamjena((igrac + i), (igrac + min));
    }
}


void zamjena(PLAYER* v, PLAYER* m){
   
    PLAYER pomocni = *m;
    *m = *v;
    *v = pomocni;
}

void ispisLjestvice(PLAYER* igrac, const int y){
    int i;

    for (i = 0; i < y; i++){
    printf("\n%d. Ime: %s   Bodovi: %d\n", (i + 1), (igrac + i)->ime, (igrac + i)->bodovi);
    }

}
