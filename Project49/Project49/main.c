#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "funkcije.h"
#include "struktura.h"


int main(void) {
	
	int uvijet = 1;
	while (uvijet) {
		system("cls");
		uvijet = izbornik();
	}
	return 0;
}
