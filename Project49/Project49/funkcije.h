#ifndef FUNKCIJE_H
#define FUNKCIJE_H
#include "struktura.h"

int izbornik(void);
void igra(void);
void prikazVjesala(int choice);
void kraj(void);
void upisuLeaderboard(int poeni);
void leaderboard(void);
void zamjena(PLAYER* veci, PLAYER* manji);
void sortiranje(PLAYER* igrac, const int k);
void ispisLjestvice(PLAYER* igrac, const int k);
void povratakNaIzbornik(void);
#endif
