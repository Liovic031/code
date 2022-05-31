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


int igra(void){}


void kraj(void) {
	char y = 121;
	char n = 110;
	char o;
	printf("Zelite li izaci iz igre? y(da) ili n(ne)\n");
	scanf("%c", &o);
	if (o == n){
		exit(EXIT_SUCCESS);
	}
	if(o == y){
		system("cls");
		izbornik();

	}
	else {
		printf("Unesite 'y' ili 'n'\n");
		kraj();
	}
}

