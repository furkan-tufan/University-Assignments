#ifndef EMIR_H
#define EMIR_H

#include "stdio.h"
#include "stdlib.h"

struct EMIR{
	char* id;
	char* sembol;
	char* islem;
	int adet;


};

typedef struct EMIR* Emir;

Emir EmirOlustur(char*, char*, char*, int);
void EmirToString(const Emir);
void EmirYoket (Emir);
#endif