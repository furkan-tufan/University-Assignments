#ifndef PORTFOY_H
#define PORTFOY_H

#include "stdio.h"
#include "stdlib.h"

struct PORTFOY{
	char* id;
	char* sembol;
	double maliyet;
	int adet;
};

typedef struct PORTFOY* Portfoy;

Portfoy PortfoyOlustur(char*, char*, double, int);
void PortfoyToString(const Portfoy);
void PortfoyYoket (Portfoy);
#endif