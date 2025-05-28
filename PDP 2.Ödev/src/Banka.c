#include "Banka.h"

Banka BankaOlustur(Hisse* hisseler, Emir* emirler, Portfoy* portfoy){
	Banka this;
	this= (Banka)malloc(sizeof(struct BANKA));
	this->bilanco=0;
	this->hisseler=hisseler;
	this->emirler=emirler;
	this->portfoy=portfoy;
	return this;
}

void EmirleriUygula(const Banka this, int emirSayisi, int hisseSayisi, int portfoyElemanSayisi){
	int portfoydekiSirasi, ilkAdet, guncelAdet;
	double guncelFiyat, maliyet, yeniMaliyet, temp;
	bool portfoydeVarMi=false;
	bool hisseVarMi=false;

	printf("Satislar Kar/Zarar:\n");
	
	// emirleri tek tek uyguladığımız döngü
	for(int i=0; i<emirSayisi; i++){
		portfoydeVarMi=false;
		hisseVarMi=false;
		
		for(int j=0; j<hisseSayisi; j++){ //emrin sembolüyle hisselerdeki sembolleri karşılaştırdığımız döngü
			if(strcmp(this->emirler[i]->sembol, this->hisseler[j]->sembol) == 0){
				guncelFiyat = this->hisseler[j]->fiyat;
				hisseVarMi=true;
			}
		}
		for(int j=0; j<portfoyElemanSayisi; j++){ //emrin sembolüyle portföydeki sembolleri karşılaştırdığımız döngü
			if(strcmp(this->emirler[i]->sembol, this->portfoy[j]->sembol) == 0){
				portfoydekiSirasi=j;
				ilkAdet = this->portfoy[j]->adet;
				maliyet = this->portfoy[j]->maliyet;
				portfoydeVarMi=true;
			}
		}
		if(strcmp(this->emirler[i]->islem, "ALIS") == 0){ //işlemimizin alış işlemi olma durumunu kontrol ediyoruz.
			if(portfoydeVarMi==true){ //portfoyde varsa maliyet ve adete güncelleme yapıyoruz
				temp=(guncelFiyat * this->emirler[i]->adet)+(maliyet * ilkAdet);
				guncelAdet = ilkAdet + this->emirler[i]->adet;
				yeniMaliyet=temp/guncelAdet;
				this->portfoy[portfoydekiSirasi]->maliyet=yeniMaliyet;
				this->portfoy[portfoydekiSirasi]->adet=guncelAdet;
			}
			else if(hisseVarMi==true){ //portfoyde yoksa portfoye eleman olarak ekliyoruz
				temp = guncelFiyat * this->emirler[i]->adet;
				guncelAdet = this->emirler[i]->adet;
				yeniMaliyet=temp/guncelAdet;
				portfoyElemanSayisi++;
				this->portfoy = (Portfoy*) realloc(this->portfoy, (portfoyElemanSayisi) * sizeof(Portfoy));
				this->portfoy[portfoyElemanSayisi-1]=PortfoyOlustur(this->emirler[i]->id, this->emirler[i]->sembol, yeniMaliyet, guncelAdet);
			}
				
		}
		else if(strcmp(this->emirler[i]->islem, "SATIS") == 0){ //işlemimizin satış işlemi olma durumunu kontrol ediyoruz.
			if(portfoydeVarMi==true && ilkAdet >= this->emirler[i]->adet){
				temp=(guncelFiyat * this->emirler[i]->adet)-(maliyet * this->emirler[i]->adet);
				if(temp>0)
					printf("%s : %.2f TL Kar\n",this->emirler[i]->sembol, temp);
				else if(temp<0)
					printf("%s : %.2f TL Zarar\n",this->emirler[i]->sembol, fabs(temp));
				else
					printf("%s : 0 TL\n",this->emirler[i]->sembol);
				
				this->bilanco+=temp;
				guncelAdet = ilkAdet - this->emirler[i]->adet;
				this->portfoy[portfoydekiSirasi]->adet=guncelAdet;
			}
			//portfoydeki adetten fazla sayıda satış emri varsa işlem yapılamıyor.
			else if(portfoydeVarMi==true && ilkAdet < this->emirler[i]->adet){ 
				printf("Portfoydekinden	fazla satilamayacagindan %s satilamamistir.\n", this->emirler[i]->sembol);

			}
		}
	}
	printf("Toplam Kar/Zarar: %+.2f TL\n\n", this->bilanco);
	
	//portfoyümüzün elemanlarını yazdırıyoruz.
	printf("Guncel Portfoy:\n");
	for(int i=0; i<portfoyElemanSayisi; i++){
		PortfoyToString(this->portfoy[i]); 
		if(i!=portfoyElemanSayisi-1 && this->portfoy[i]->adet!=0){ //0 adet değilse veya son eleman değilse, araya tire ekleyip alt satıra geçiyor.
			printf("--------------------------\n");
		}
	}
	
	//malloc ile oluşturulan dizi elemanlarını işletim sistemine iade ediyoruz
	for(int i=0; i<hisseSayisi; i++){
		HisseYoket(this->hisseler[i]);
		this->hisseler[i]=NULL;
	}
	for(int i=0; i<portfoyElemanSayisi; i++){
		PortfoyYoket(this->portfoy[i]);
		this->portfoy[i]=NULL;
	}
	
	for(int i=0; i<emirSayisi; i++){
		EmirYoket(this->emirler[i]);
		this->emirler[i]=NULL;
	}
}

void BankaYoket (Banka this){
	if(this!=NULL)
		free(this);
}