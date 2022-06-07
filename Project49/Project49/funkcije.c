#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funkcije.h"
#include "struktura.h"

void izbornik(void) {

	printf("\t\t************************************\n\n");
	printf("\t\tOdaberite jednu od ponudenih opcija: \n\n");
	printf("\t\t************************************\n\n");

	printf("\t\tOpcija 1: Nova igra\n");
	printf("\t\tOpcija 2: Leaderboard\n");
	printf("\t\tOpcija 3: Izlaz iz igre\n");


	printf("\t\t************************************\n\n");

	int uvijet = 0;

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
		uvijet = 0;
	}
	return uvijet;
}


int igra(void) {
    char rijec[50];
    char pomocniString[50];
    int duljina, k, pogodak;
    int zivot = 5;
    char slovo;
    int brPogodjenih = 0;
    int bodovi = 0;
    int temp = zivot;


    printf("Unesite zeljenu rijec:\n");
    scanf("%s", rijec);
    duljina = strlen(rijec);

    for (int i = 0; i < duljina; i++) {
        pomocniString[i] = '_';
        //printf("%c\n", pomoc[i]);
        k = i;
    }

    pomocniString[k + 1] = '\0';
   
    system("cls");

    //printf("%s\n", pomocniString);
    
 
    printf("\n\t|_____ ");
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
        // getchar();
        for (int i = 0; i < duljina; i++) {
            if (rijec[i] == slovo) {
                pomocniString[i] = rijec[i];
                //printf("Nakon promjene %s\n", pomocniString);
                brPogodjenih++;
                pogodak = 1;
            }
        }
        if (pogodak == 1) {
            prikazVjesala(zivot);
            printf("\nTocno pogodjeno! \n %s\n", pomocniString);
            bodovi = bodovi + 35;
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
            //upisuLeaderboard(bodovi);
        }

    }
    if (zivot == 0) {
        system("cls");
        printf("\n\t|_____ ");
        printf("\n\t|    | ");
        printf("\n\t|   %cO/", '\\');
        printf("\n\t|    | ");
        printf("\n\t|   / %c", '\\');
        printf("\n\t|     ");
        printf("\n Nazalost ste izgubili, rijec je bila: %s\n", rijec);
        //upisuLeaderboard(bodovi);
    }
    printf("Bodovi: %d", bodovi);
    return bodovi;
}

void prikazVjesala(int zivot)                          
{

    if (zivot == 1) {
        system("cls");
        printf("\n\t|_____ ");
        printf("\n\t|    | ");
        printf("\n\t|   %cO/", '\\');
        printf("\n\t|    | ");
        printf("\n\t|     %c", '\\');
        printf("\n\t|      ");
    }
    if (zivot == 2) {
        system("cls");
        printf("\n\t|_____ ");
        printf("\n\t|    | ");
        printf("\n\t|   %cO/", '\\');
        printf("\n\t|    | ");
        printf("\n\t|      ");
        printf("\n\t|      ");
    }
    if (zivot == 3) {
        system("cls");
        printf("\n\t|_____ ");
        printf("\n\t|    | ");
        printf("\n\t|   %cO/", '\\');
        printf("\n\t|      ");
        printf("\n\t|      ");
        printf("\n\t|      ");
    }
    if (zivot == 4) {
        system("cls");
        printf("\n\t|_____ ");
        printf("\n\t|    | ");
        printf("\n\t|   %cO ", '\\');
        printf("\n\t|      ");
        printf("\n\t|      ");
        printf("\n\t|      ");
    }
    if (zivot == 5) {
        system("cls");
        printf("\n\t|_____ ");
        printf("\n\t|    | ");
        printf("\n\t|    O ");
        printf("\n\t|      ");
        printf("\n\t|      ");
        printf("\n\t|      ");
    }
    
    return;
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



//void upisuLeaderboard(int) {}




//void leaderboard(void);






/*void zamjena(PLAYER*, PLAYER*) {
   
    PLAYER temp = *manji;
    *manji = *veci;
    *veci = temp;
}

//void sortiranje(PLAYER*, const int){
    int min = 0;
    for (int i = 0; i < k - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < k; j++)
        {
            if ((igrac + j)->bodovi > (igrac + min)->bodovi)
            {
                min = j;
            }
        }
        Zamjena((igrac + i), (igrac + min));
    }
}


//void ispisLjestvice(PLAYER*, const int){
    int i;

    for (i = 0; i < k; i++){
    printf("\n%d. Ime: %s   Bodovi: %d\n", (i + 1), (igrac + i)->ime, (igrac + i)->bodovi);
    }

}

//void povratakNaIzbornik(void);
//void brojIgraca(void);

*/
