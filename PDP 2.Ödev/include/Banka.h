#ifndef BANKA_H
#define BANKA_H

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"
#include "Hisse.h"
#include "Portfoy.h"
#include "Emir.h"

struct BANKA{
	double bilanco;
	Hisse* hisseler;
	Emir* emirler;
	Portfoy* portfoy;
};

typedef struct BANKA* Banka;
typedef enum{false, true} bool;

Banka BankaOlustur(Hisse*, Emir*, Portfoy*);
void EmirleriUygula(const Banka, int, int, int);
void BankaYoket (Banka);
#endif