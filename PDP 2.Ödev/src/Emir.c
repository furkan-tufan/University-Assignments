#include "Emir.h"
Emir EmirOlustur(char* id, char* sembol, char* islem, int adet){
	Emir this;
	this= (Emir)malloc(sizeof(struct EMIR));
	this->id=id;
	this->sembol=sembol;
	this->islem=islem;
	this->adet=adet;
	return this;
}

void EmirToString(const Emir this){
	printf("%s   %s   %s   %d\n", this->id, this->sembol, this->islem,this->adet);
}

void EmirYoket (Emir this){
	if(this!=NULL)
		free(this);
}