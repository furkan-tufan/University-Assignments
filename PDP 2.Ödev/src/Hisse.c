#include "Hisse.h"

Hisse HisseOlustur(char* id, char* sembol, char* ad, double fiyat){
	Hisse this;
	this= (Hisse)malloc(sizeof(struct HISSE));
	this->id=id;
	this->sembol=sembol;
	this->ad=ad;
	this->fiyat=fiyat;
	return this;
}

void HisseToString(const Hisse this){
	printf("%s   %s   %s   %G\n", this->id, this->sembol, this->ad,this->fiyat);
}

void HisseYoket (Hisse this){
	if(this!=NULL)
		free(this);
}