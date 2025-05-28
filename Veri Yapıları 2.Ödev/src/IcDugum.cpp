/**
* @file         IcDugum.cpp
* @description  Çalışan bilgilerinin saklanacağı iç düğüm sınıfı.
* @course       2/B Şubesi
* @assignment   Ödev 2
* @date         22.12.2020
* @author       Furkan İsmet Tufan / furkan.tufan@ogr.sakarya.edu.tr
*/

#include <IcDugum.hpp>
using namespace std;

IcDugum::IcDugum(string isim, int basladigiYil){
	this->basladigiYil=basladigiYil;
	this->isim=isim;
	derinlik=0;
	solCocuk=NULL;
	sagCocuk=NULL;
}
IcDugum::IcDugum(){
	basladigiYil=int();
	isim=" ? ";
	derinlik=0;
	solCocuk=NULL;	
	sagCocuk=NULL;
}