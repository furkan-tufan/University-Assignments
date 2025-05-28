/**
* @file         DisDugum.cpp
* @description  Şirket bilgilerinin saklanacağı dış düğüm sınıfı. İçerisinde şirketin çalışanlarının saklanacağı iç ağacı gösteren pointer değişkeni tanımlanmış.
* @course       2/B Şubesi
* @assignment   Ödev 2
* @date         24.12.2020
* @author       Furkan İsmet Tufan / furkan.tufan@ogr.sakarya.edu.tr
*/

#include <DisDugum.hpp>
using namespace std;

DisDugum::DisDugum(std::string firmaIsmi, int calisanSayisi){
	this->calisanSayisi=calisanSayisi;
	this->firmaIsmi=firmaIsmi;
	derinlik=0;
	solCocuk=NULL;
	sagCocuk=NULL;
	calisanlar=new IcAgac();
}
DisDugum::DisDugum(){
	calisanSayisi=int();
	firmaIsmi=" ? ";
	derinlik=0;
	solCocuk=NULL;
	sagCocuk=NULL;
	calisanlar=new IcAgac();
}
DisDugum::~DisDugum(){
	delete calisanlar;
}