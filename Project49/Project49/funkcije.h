#ifndef FUNKCIJE_H
#define FUNKCIJE_H
#include "struktura.h"

int izbornik(void);
void igra(void);
void prikazVjesala(int choice);
void kraj(void);
void upisuLeaderboard(int poeni);
void leaderboard(void);
void zamjena(PLAYER* v, PLAYER* m);
void sortiranje(PLAYER* igrac, const int y);
void ispisLjestvice(PLAYER* igrac, const int y);
void povratakNaIzbornik(void);
#endif
