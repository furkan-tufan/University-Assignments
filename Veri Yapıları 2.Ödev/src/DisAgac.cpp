/**
* @file         DisAgac.cpp
* @description  Şirketlerden(dış düğümlerden) oluşan dış ağaç sınıfı.
* @course       2/B Şubesi
* @assignment   Ödev 2
* @date         22.12.2020
* @author       Furkan İsmet Tufan / furkan.tufan@ogr.sakarya.edu.tr
*/

#include <DisAgac.hpp>
using namespace std;

DisAgac::DisAgac(){
	kokDugum=NULL;
}

DisDugum* DisAgac::Insert(string firmaIsmi, int calisanSayisi, DisDugum* dugum){
	if(kokDugum==NULL){
		kokDugum=NewNode(firmaIsmi, calisanSayisi);
		return kokDugum;
	}
	else if(dugum==NULL){
		return NewNode(firmaIsmi, calisanSayisi);
	}
	else if(calisanSayisi <= dugum->calisanSayisi){
		dugum->solCocuk=Insert(firmaIsmi, calisanSayisi, dugum->solCocuk);
		if(height(dugum->solCocuk) - height(dugum->sagCocuk) == 2)
        {
            if(calisanSayisi < dugum->solCocuk->calisanSayisi)
                dugum = llDonustur(dugum);
            else
                dugum = lrDonustur(dugum);
        }
	}
	else{
		dugum->sagCocuk=Insert(firmaIsmi, calisanSayisi, dugum->sagCocuk);
		if(height(dugum->sagCocuk) - height(dugum->solCocuk) == 2)
        {
            if(calisanSayisi > dugum->sagCocuk->calisanSayisi)
                dugum = rrDonustur(dugum);
            else
                dugum = rlDonustur(dugum);
        }
	}
	dugum->derinlik = max(height(dugum->solCocuk), height(dugum->sagCocuk))+1;
	return dugum;
}

void DisAgac::Insert(string firmaIsmi, int calisanSayisi){
	Insert(firmaIsmi, calisanSayisi, kokDugum);
}

DisDugum* DisAgac::NewNode(string firmaIsmi, int calisanSayisi){
	DisDugum* yeniDugum = new DisDugum(firmaIsmi, calisanSayisi);
	return yeniDugum;
}

bool DisAgac::Search(string firma,DisDugum* dugum){
	if (dugum == NULL) return false;

    if (firma.compare(dugum->firmaIsmi)==0) return true;

    if (Search(firma, dugum->solCocuk)) return true;

    if (Search(firma, dugum->sagCocuk)) return true;

    return false;
}

bool DisAgac::Search(string firma){
	return Search(firma, kokDugum);
}

DisDugum* DisAgac::BulVeGetir(string firma,DisDugum* dugum){
	
	if (dugum == NULL) return NULL;

    if (firma.compare(dugum->firmaIsmi)==0) return dugum;

    if (BulVeGetir(firma, dugum->solCocuk)!=NULL) return BulVeGetir(firma, dugum->solCocuk);

    if (BulVeGetir(firma, dugum->sagCocuk)!=NULL) return BulVeGetir(firma, dugum->sagCocuk);

    return NULL;
}

DisDugum* DisAgac::BulVeGetir(string firma){
	return BulVeGetir(firma, kokDugum);
}

DisDugum* DisAgac::llDonustur(DisDugum* &ebeveyn)
{
	if (ebeveyn->solCocuk != NULL) {
		DisDugum* dugum = ebeveyn->solCocuk;
		ebeveyn->solCocuk = dugum->sagCocuk;
		dugum->sagCocuk = ebeveyn;
		ebeveyn->derinlik = max(height(ebeveyn->solCocuk), height(ebeveyn->sagCocuk))+1;
		dugum->derinlik = max(height(dugum->solCocuk), ebeveyn->derinlik)+1;
		if(ebeveyn==kokDugum){
			kokDugum=dugum;
		}
		return dugum;
	}
	return ebeveyn;
}

DisDugum* DisAgac::rrDonustur(DisDugum* &ebeveyn)
{
	if (ebeveyn->sagCocuk != NULL) {
		DisDugum* dugum = ebeveyn->sagCocuk;
		ebeveyn->sagCocuk = dugum->solCocuk;
		dugum->solCocuk = ebeveyn;
		ebeveyn->derinlik = max(height(ebeveyn->solCocuk), height(ebeveyn->sagCocuk))+1;
		dugum->derinlik = max(height(ebeveyn->sagCocuk), ebeveyn->derinlik)+1 ;
		if(ebeveyn==kokDugum){
			kokDugum=dugum;
		}
		return dugum;
    }
	return ebeveyn;
}

DisDugum* DisAgac::rlDonustur(DisDugum* &ebeveyn)
{
    ebeveyn->sagCocuk = llDonustur(ebeveyn->sagCocuk);
    return rrDonustur(ebeveyn);
}

DisDugum* DisAgac::lrDonustur(DisDugum* &ebeveyn)
{
    ebeveyn->solCocuk = rrDonustur(ebeveyn->solCocuk);
    return llDonustur(ebeveyn);
}

int DisAgac::height(DisDugum* ebeveyn)
{
	if(ebeveyn == NULL)
		return -1;
	else
		return ebeveyn->derinlik;
}

void DisAgac::PostOrder(DisDugum* dugum){
	if(dugum!=NULL){
		PostOrder(dugum->solCocuk);
		PostOrder(dugum->sagCocuk);
		cout<<dugum->firmaIsmi<<endl;
		dugum->calisanlar->PostOrder();
		cout<<endl;
	}
}

void DisAgac::PostOrder(){
	PostOrder(kokDugum);
}

void DisAgac::calisanSayisiArttir(DisDugum* dugum){
	dugum->calisanSayisi++;
}

bool DisAgac::DugumSil(DisDugum* &alt_Dugum)
{			
	DisDugum* silinecekDugum = alt_Dugum;
	
	if(alt_Dugum->sagCocuk == NULL) alt_Dugum = alt_Dugum->solCocuk;
	else if(alt_Dugum->solCocuk == NULL) alt_Dugum = alt_Dugum->sagCocuk;
	else{
		silinecekDugum = alt_Dugum->solCocuk;
		DisDugum* ebeveynDugum = alt_Dugum;
		while(silinecekDugum->sagCocuk != NULL){
			ebeveynDugum=silinecekDugum;
			silinecekDugum=silinecekDugum->sagCocuk;
		}
		alt_Dugum->calisanSayisi = silinecekDugum->calisanSayisi;
		alt_Dugum->firmaIsmi = silinecekDugum->firmaIsmi;

		if(ebeveynDugum == alt_Dugum) alt_Dugum->solCocuk = silinecekDugum->solCocuk;
		else ebeveynDugum->sagCocuk = silinecekDugum->solCocuk;
	}
	delete silinecekDugum;
	return true;
}

bool DisAgac::Bosmu() const{
	return kokDugum == NULL;
}

void DisAgac::Temizle(){
	while(!Bosmu()) DugumSil(kokDugum);
}

DisAgac::~DisAgac(){
	Temizle();
}