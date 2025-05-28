#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "windows.h"
#include "Hisse.h"
#include "Portfoy.h"
#include "Emir.h"
#include "Banka.h"


int main(){
	SetConsoleOutputCP(65001);
	bool bulduMu; // Banka.h içerisinde typedef ile bool tanımlandı
	size_t uzunluk = 0;
    ssize_t oku;
	char c='"', c2='}';
	int index, ilkSutun, sonSutun;
	int hisseSayisi=0, portfoyElemanSayisi=0, emirSayisi=0, elemanNumarasi=0;
	char* satir= NULL;
	char* bul;
	char* bas;
	char* son;
	char* substr;
	char* geciciId;
	char* geciciAd;
	char* geciciSembol;
	char* geciciIslem;
	int geciciAdet;
	double geciciFiyat, geciciMaliyet;
	
	FILE* hisseDosyasi;
	hisseDosyasi = fopen("./doc/hisseler.json", "r");
	
	//satır satır okuma işlemini yapıyoruz.
	while ((oku = getline(&satir, &uzunluk, hisseDosyasi)) != -1) {
		bul = strstr( satir, "_id" );
		if (bul != NULL)
			hisseSayisi++; //satırda "_id" bulunduğu sürece hisse sayısını bir artırıyoruz
	}
	//heap bellek bölgesinde, bulduğumuz hisse sayısı boyutunda Hisse dizisi oluşturuyoruz.
	Hisse* hisseler = (Hisse*)malloc(hisseSayisi * sizeof(Hisse)); 
	fseek(hisseDosyasi, 0, SEEK_SET); //dosyanın başına dönüyoruz.

	//satır satır okuma işlemini yapıyoruz.
    while ((oku = getline(&satir, &uzunluk, hisseDosyasi)) != -1) {
		bulduMu=false;
		
		bul = strstr( satir, "_id" ); //satırda "_id" olma durumunu kontrol ediyoruz.
		if (bul != NULL){ //NULL değilse satırda "_id" bulunmuştur
			bulduMu=true;
			index = bul - satir; // "_id" nin başlangıç indexini buluyoruz.
			ilkSutun=index+7; // dosyadaki satırlarda "_id"nin başlangıç indexinden 7 karakter sonra id değeri yazılıyor
			sonSutun=ilkSutun;
			for(int i = ilkSutun; c!=satir[i]; i++){
				sonSutun++;//tırnak işareti görene kadar son sütunu artırıyoruz(c değişkeni, tırnak işaretine eşit)
			}
			bas = &satir[ilkSutun];
			son = &satir[sonSutun];
			//ilkSutun ile sonSutun arasındaki karakterleri alıyoruz ve geciciId 'ye atıyoruz.
			substr = (char *)calloc(1, son - bas + 1);
			memcpy(substr, bas, son - bas);
			geciciId=substr;
		}
		
		bul = strstr( satir, "Sembol" ); //satırda "Sembol" olma durumunu kontrol ediyoruz.
		if (bul != NULL){ //NULL değilse satırda "Sembol" vardır.
			index = bul - satir;  // "Sembol" ün başlangıç indexini buluyoruz.
			ilkSutun=index+10; //dosyadaki satırlarda "Sembol"ün başlangıç indexinden 10 karakter sonra sembol değeri yazılıyor.
			sonSutun=ilkSutun; 
			for(int i = ilkSutun; c!=satir[i]; i++){
				sonSutun++;//tırnak işareti görene kadar son sütunu artırıyoruz(c değişkeni, tırnak işaretine eşit)
			}
			bas = &satir[ilkSutun];
			son = &satir[sonSutun];
			//ilkSutun ile sonSutun arasındaki karakterleri alıyoruz ve geciciSembol 'e atıyoruz.
			substr = (char *)calloc(1, son - bas + 1);
			memcpy(substr, bas, son - bas);
			geciciSembol=substr;
		}
		
		bul = strstr( satir, "Ad" ); //satırda "Ad" olma durumunu kontrol ediyoruz.
		if (bul != NULL){ //NULL değilse satırda "Ad" vardır.
			index = bul - satir; // "Ad" ın başlangıç indexini buluyoruz.
			ilkSutun=index+6; //dosyadaki satırlarda "Ad"ın başlangıç indexinden 6 karakter sonra ad değeri yazılıyor.
			sonSutun=ilkSutun;
			for(int i = ilkSutun; c!=satir[i]; i++){
				sonSutun++;//tırnak işareti görene kadar son sütunu artırıyoruz. (c değişkeni, tırnak işaretine eşit)
			}
			bas = &satir[ilkSutun];
			son = &satir[sonSutun];
			//ilkSutun ile sonSutun arasındaki karakterleri alıyoruz ve geciciAd 'a atıyoruz.
			substr = (char *)calloc(1, son - bas + 1);
			memcpy(substr, bas, son - bas);
			geciciAd=substr;
		}
		
		bul = strstr( satir, "Fiyat" ); //satırda "Fiyat" olma durumunu kontrol ediyoruz.
		if (bul != NULL){ //NULL değilse satırda "Fiyat" vardır.
			index = bul - satir; // "Fiyat" ın başlangıç indexini buluyoruz.
			ilkSutun=index+8; //dosyadaki satırlarda "Fiyat"ın başlangıç indexinden 8 karakter sonra fiyat değeri yazılıyor.
			sonSutun=ilkSutun;
			for(int i = ilkSutun; c2!=satir[i]; i++){
				sonSutun++; // '{' sembolünü görene kadar son sütunu artırıyoruz. (c2 değişkeni, '{' sembolüne eşit)
			}
			bas = &satir[ilkSutun];
			son = &satir[sonSutun];
			//ilkSutun ile sonSutun arasındaki karakterleri alıyoruz ve geciciFiyat 'a atıyoruz.
			substr = (char *)calloc(1, son - bas + 1);
			memcpy(substr, bas, son - bas);
			geciciFiyat=atof(substr);
		}
		//satırdaki değerler bulunduysa hisseler dizimizin bir indexine hisse oluşturuyoruz.
		if(bulduMu==true){ 
			hisseler[elemanNumarasi]=HisseOlustur(geciciId, geciciSembol, geciciAd, geciciFiyat);
			elemanNumarasi++;
		}
	}
    fclose(hisseDosyasi); //işimiz bittiği için dosyayı kapıyoruz.
	
	uzunluk = 0;
	elemanNumarasi=0;
	
	
	/*
	YUKARIDA HİSSELER DOSYASI İÇİN YAPILANLARIN ÇOK BENZERİNİ AŞAĞIDA PORTFOY VE EMİRLER DOSYASI İÇİN DE YAPIYORUZ.
	*/
	
	
	FILE* portfoyDosyasi;
	portfoyDosyasi = fopen("./doc/portfoy.json", "r");
	
	//satır satır okuma işlemini yapıyoruz.
	while ((oku = getline(&satir, &uzunluk, portfoyDosyasi)) != -1) {
		bul = strstr( satir, "_id" );
		if (bul != NULL)
			portfoyElemanSayisi++;
	}
	Portfoy* portfoy = (Portfoy*)malloc(portfoyElemanSayisi * sizeof(Portfoy));
	fseek(portfoyDosyasi, 0, SEEK_SET);
	
	//satır satır okuma işlemini yapıyoruz.
    while ((oku = getline(&satir, &uzunluk, portfoyDosyasi)) != -1) {
		bulduMu=false;
		
		bul = strstr( satir, "_id" );
		if (bul != NULL){
			bulduMu=true;
			index = bul - satir;
			ilkSutun=index+7;
			sonSutun=ilkSutun;
			for(int i = ilkSutun; c!=satir[i]; i++){
				sonSutun++;
			}
			bas = &satir[ilkSutun];
			son = &satir[sonSutun];
			substr = (char *)calloc(1, son - bas + 1);
			memcpy(substr, bas, son - bas);
			geciciId=substr;
		}
		
		bul = strstr( satir, "Sembol" ); 
		if (bul != NULL){
			index = bul - satir;
			ilkSutun=index+10;
			sonSutun=ilkSutun;
			for(int i = ilkSutun; c!=satir[i]; i++){
				sonSutun++;
			}
			bas = &satir[ilkSutun];
			son = &satir[sonSutun];
			substr = (char *)calloc(1, son - bas + 1);
			memcpy(substr, bas, son - bas);
			geciciSembol=substr;
		}
		
		bul = strstr( satir, "Adet" ); 
		if (bul != NULL){
			index = bul - satir;
			ilkSutun=index+7;
			sonSutun=ilkSutun;
			for(int i = ilkSutun; c!=satir[i]; i++){
				sonSutun++;
			}
			bas = &satir[ilkSutun];
			son = &satir[sonSutun];
			substr = (char *)calloc(1, son - bas + 1);
			memcpy(substr, bas, son - bas);
			geciciAdet=atoi(substr);
		}
		
		bul = strstr( satir, "Maliyet" ); 
		if (bul != NULL){
			index = bul - satir;
			ilkSutun=index+10;
			sonSutun=ilkSutun;
			for(int i = ilkSutun; c2!=satir[i]; i++){
				sonSutun++;
			}
			bas = &satir[ilkSutun];
			son = &satir[sonSutun];
			substr = (char *)calloc(1, son - bas + 1);
			memcpy(substr, bas, son - bas);
			geciciMaliyet=atof(substr);
		}
		
		if(bulduMu==true){
			portfoy[elemanNumarasi]=PortfoyOlustur(geciciId, geciciSembol, geciciMaliyet, geciciAdet);
			elemanNumarasi++;
		}
	}
    fclose(portfoyDosyasi);
	
	uzunluk = 0;
	elemanNumarasi=0;
	
	FILE* emirDosyasi;
	emirDosyasi = fopen("./doc/emirler.json", "r");
	//satır satır okuma işlemini yapıyoruz.
	while ((oku = getline(&satir, &uzunluk, emirDosyasi)) != -1) {
		bul = strstr( satir, "_id" );
		if (bul != NULL)
			emirSayisi++;
	}
	Emir* emirler = (Emir*)malloc(emirSayisi * sizeof(Emir));
	fseek(emirDosyasi, 0, SEEK_SET);
	
	//satır satır okuma işlemini yapıyoruz.
    while ((oku = getline(&satir, &uzunluk, emirDosyasi)) != -1) {
		bulduMu=false;
		
		bul = strstr( satir, "_id" );
		if (bul != NULL){
			bulduMu=true;
			index = bul - satir;
			ilkSutun=index+7;
			sonSutun=ilkSutun;
			for(int i = ilkSutun; c!=satir[i]; i++){
				sonSutun++;
			}
			bas = &satir[ilkSutun];
			son = &satir[sonSutun];
			substr = (char *)calloc(1, son - bas + 1);
			memcpy(substr, bas, son - bas);
			geciciId=substr;
		}
		
		bul = strstr( satir, "Sembol" ); 
		if (bul != NULL){
			index = bul - satir;
			ilkSutun=index+10;
			sonSutun=ilkSutun;
			for(int i = ilkSutun; c!=satir[i]; i++){
				sonSutun++;
			}
			bas = &satir[ilkSutun];
			son = &satir[sonSutun];
			substr = (char *)calloc(1, son - bas + 1);
			memcpy(substr, bas, son - bas);
			geciciSembol=substr;
		}
		
		bul = strstr( satir, "Islem" ); 
		if (bul != NULL){
			index = bul - satir;
			ilkSutun=index+9;
			sonSutun=ilkSutun;
			for(int i = ilkSutun; c!=satir[i]; i++){
				sonSutun++;
			}
			bas = &satir[ilkSutun];
			son = &satir[sonSutun];
			substr = (char *)calloc(1, son - bas + 1);
			memcpy(substr, bas, son - bas);
			geciciIslem=substr;
		}
		
		bul = strstr( satir, "Adet" ); 
		if (bul != NULL){
			index = bul - satir;
			ilkSutun=index+7;
			sonSutun=ilkSutun;
			for(int i = ilkSutun; c2!=satir[i]; i++){
				sonSutun++;
			}
			bas = &satir[ilkSutun];
			son = &satir[sonSutun];
			substr = (char *)calloc(1, son - bas + 1);
			memcpy(substr, bas, son - bas);
			geciciAdet=atoi(substr);
		}
		
		if(bulduMu==true){
			emirler[elemanNumarasi]=EmirOlustur(geciciId, geciciSembol, geciciIslem, geciciAdet);
			elemanNumarasi++;
		}
	}
    fclose(emirDosyasi);
	
	Banka banka=BankaOlustur(hisseler, emirler, portfoy);
	EmirleriUygula(banka, emirSayisi, hisseSayisi, portfoyElemanSayisi);
	
	// malloc ile oluşturulan dizilerimizin ELEMANLARINI bankamızın EmirleriUygula() metodunda free komutuyla iade ettik.
	// şimdi de heap bellek bölgesinde oluşturulan diğer pointerları işletim sistemine iade ediyoruz.
	BankaYoket(banka);
	free(hisseler);
	free(portfoy);
	free(emirler);
	
	return 0;
}