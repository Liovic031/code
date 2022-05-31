#ifndef FUNKCIJE_H
#define FUNKCIJE_H
#include "struktura.h"

void izbornik(void);
int igra(void);
void kraj(void);
void upisuLjestvicu(int);
void repeat(int);
void leaderboard(void);
void zamjena(PLAYER*, PLAYER*);
void sortiranje(PLAYER*, const int);
void ispisLjestvice(PLAYER*, const int);
void povratakNaIzbornik(void);
void brojIgraca(void);
#endif
