#ifndef HISSE_H
#define HISSE_H

#include "stdio.h"
#include "stdlib.h"

struct HISSE{
	char* id;
	char* sembol;
	char* ad;
	double fiyat;
};

typedef struct HISSE* Hisse;

Hisse HisseOlustur(char*, char*, char*, double);
void HisseToString(const Hisse);
void HisseYoket (Hisse);
#endif