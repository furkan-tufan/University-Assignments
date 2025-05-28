#include "Portfoy.h"

Portfoy PortfoyOlustur(char* id, char* sembol, double maliyet, int adet){
	Portfoy this;
	this= (Portfoy)malloc(sizeof(struct PORTFOY));
	this->id=id;
	this->sembol=sembol;
	this->maliyet=maliyet;
	this->adet=adet;
	return this;
}

void PortfoyToString(const Portfoy this){
	if(this->adet!=0){
		printf("Hisse: %s\nAdet: %d\nMaliyet: %.2f TL\n", this->sembol, this->adet, this->maliyet);
	}
}

void PortfoyYoket (Portfoy this){
	if(this!=NULL)
		free(this);
	
}