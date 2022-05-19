#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funkcije.h"
#include "struktura.h"

int izbornik(const char* const ime) {

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
		break;
	case 2:
		break;
	case 3:
		break;
	default:
		uvijet = 0;
	}
	return uvijet;
}

