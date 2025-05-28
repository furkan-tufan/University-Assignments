/**
* @file         IcAgac.cpp
* @description  Dış ağaçtaki şirketlerin çalışanlarını tutan iç ağaç sınıfı.
* @course       2/B Şubesi
* @assignment   Ödev 2
* @date         24.12.2020
* @author       Furkan İsmet Tufan / furkan.tufan@ogr.sakarya.edu.tr
*/

#include <IcAgac.hpp>
using namespace std;

IcAgac::IcAgac(){
	kokDugum=NULL;
}

IcDugum* IcAgac::Insert(string isim, int basladigiYil,IcDugum* dugum){
	if(kokDugum==NULL){
		kokDugum=NewNode(basladigiYil, isim);
		return kokDugum;
	}
	else if(dugum==NULL){
		return NewNode(basladigiYil, isim);
	}
	else if(basladigiYil >= dugum->basladigiYil){
		dugum->solCocuk=Insert(isim,basladigiYil,dugum->solCocuk);
		if(height(dugum->solCocuk) - height(dugum->sagCocuk) == 2)
        {
            if(basladigiYil < dugum->solCocuk->basladigiYil)
                dugum = llDonustur(dugum);
            else
                dugum = lrDonustur(dugum);
        }
	}
	else{
		dugum->sagCocuk=Insert(isim, basladigiYil, dugum->sagCocuk);
		if(height(dugum->sagCocuk) - height(dugum->solCocuk) == 2)
        {
            if(basladigiYil > dugum->sagCocuk->basladigiYil)
                dugum = rrDonustur(dugum);
            else
                dugum = rlDonustur(dugum);
        }
	}
	dugum->derinlik = max(height(dugum->solCocuk), height(dugum->sagCocuk))+1;
	return dugum;
}

void IcAgac::Insert(string isim, int basladigiYil){
	Insert(isim, basladigiYil, kokDugum);
}


IcDugum* IcAgac::NewNode(int basladigiYil, string isim){
	IcDugum* yeniDugum = new IcDugum(isim, basladigiYil);
	return yeniDugum;
}

IcDugum* IcAgac::llDonustur(IcDugum* &ebeveyn)
{
	if (ebeveyn->solCocuk != NULL) {
		IcDugum* dugum = ebeveyn->solCocuk;
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

IcDugum* IcAgac::rrDonustur(IcDugum* &ebeveyn)
{
	if (ebeveyn->sagCocuk != NULL) {
		IcDugum* dugum = ebeveyn->sagCocuk;
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

IcDugum* IcAgac::rlDonustur(IcDugum* &ebeveyn)
{
    ebeveyn->sagCocuk = llDonustur(ebeveyn->sagCocuk);
    return rrDonustur(ebeveyn);
}

IcDugum* IcAgac::lrDonustur(IcDugum* &ebeveyn)
{
    ebeveyn->solCocuk = rrDonustur(ebeveyn->solCocuk);
    return llDonustur(ebeveyn);
}

int IcAgac::height(IcDugum* ebeveyn)
{
	if(ebeveyn == NULL)
		return -1;
	else
		return ebeveyn->derinlik;
}

void IcAgac::PostOrder(IcDugum* dugum){
	if(dugum!=NULL){
		PostOrder(dugum->solCocuk);
		PostOrder(dugum->sagCocuk);
		cout<<dugum->isim<<" - "<< dugum->basladigiYil<<" | ";
	}
}

void IcAgac::PostOrder(){
	PostOrder(kokDugum);
	cout<<endl;
}

bool IcAgac::DugumSil(IcDugum* &alt_Dugum)
{			
	IcDugum* silinecekDugum = alt_Dugum;
	
	if(alt_Dugum->sagCocuk == NULL) alt_Dugum = alt_Dugum->solCocuk;
	else if(alt_Dugum->solCocuk == NULL) alt_Dugum = alt_Dugum->sagCocuk;
	else{
		silinecekDugum = alt_Dugum->solCocuk;
		IcDugum* ebeveynDugum = alt_Dugum;
		while(silinecekDugum->sagCocuk != NULL){
			ebeveynDugum=silinecekDugum;
			silinecekDugum=silinecekDugum->sagCocuk;
		}
		alt_Dugum->basladigiYil = silinecekDugum->basladigiYil;
		alt_Dugum->isim = silinecekDugum->isim;

		if(ebeveynDugum == alt_Dugum) alt_Dugum->solCocuk = silinecekDugum->solCocuk;
		else ebeveynDugum->sagCocuk = silinecekDugum->solCocuk;
	}
	delete silinecekDugum;
	return true;
}

bool IcAgac::Bosmu() const{
	return kokDugum == NULL;
}

void IcAgac::Temizle(){
	while(!Bosmu()) DugumSil(kokDugum);
}

IcAgac::~IcAgac(){
	Temizle();
}