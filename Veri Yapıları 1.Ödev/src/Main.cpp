/**
* @file 		   Main.cpp
* @description     "Sayilar.txt" dosyasından sayıları okuyor, listelere yazdırıyor. orta değeri en buyuk & en kucuk listeler arasında carprazlama islemini yapıp ekrana yazdırıyor.
* @course          2.Öğretim B Grubu
* @assignment      1.Ödev
* @date            20.11.2020
* @author          Furkan İsmet Tufan - furkan.tufan@ogr.sakarya.edu.tr
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include "List.hpp"
using namespace std;

int main()
{
	ifstream dosya("Sayilar.txt", ios::in);
	string str;
	int satirSayisi = 0;
	while (getline(dosya, str)) { //bu döngü sayesinde txt dosyasında kaç satır olduğunu öğrendik.
		satirSayisi++;
	}
	//dosyanın satır sayısına göre listeleri tutan dizimizi ve stringstream dizimizi oluşturuyoruz.
	stringstream* parcala = new stringstream[satirSayisi];
	List** listeDizisi = new List* [satirSayisi];
	
	//dosyanın başına dönmek için aşağıdaki iki komutu kullanıyoruz.
	dosya.clear();
	dosya.seekg(0);
	
	for (int i = 0; i < satirSayisi; i++) {
		listeDizisi[i] = new List();
		getline(dosya, str);
		parcala[i] << str;
		
		int sayiMiktari=1;
		for (int j= 1 ; j < str.length(); j++){ //bu döngü, boşluk sayısı kadar sayiMiktari'ni artırıyor.
			if (str.substr(j, 1) == " ") {  
				sayiMiktari += 1;	
			}
		}
		int* temp = new int[sayiMiktari];
		for (int sayac=0; sayac<sayiMiktari; sayac++){
			parcala[i] >> temp[sayac];
		}
		listeDizisi[i]->Ekle(temp,sayiMiktari);
		delete[] temp;
	}
	dosya.close();
	delete[] parcala;
	
	int kListeIndisi= 0; //küçük liste indisi 
	int bListeIndisi= 0; //büyük liste indisi 
	//bu döngüyle listelerin orta düğümlerindeki değerleri kıyaslayarak en büyük ve en küçük liste indislerini buluyoruz
	for (int i = 0; i < satirSayisi; i++) {
		if( listeDizisi[i]->getListeOrta()->data > listeDizisi[bListeIndisi]->getListeOrta()->data )
			bListeIndisi=i;
		if( listeDizisi[i]->getListeOrta()->data < listeDizisi[kListeIndisi]->getListeOrta()->data )
			kListeIndisi=i;
	}
	
	int bListeDoneceklerinSayisi= listeDizisi[bListeIndisi]->Buyukluk()-1;
	int kListeDoneceklerinSayisi= listeDizisi[kListeIndisi]->Buyukluk()-1;
	int* bListeDonenler = listeDizisi[bListeIndisi]->OrtaHaricDondurVeTemizle();
	int* kListeDonenler = listeDizisi[kListeIndisi]->OrtaHaricDondurVeTemizle();
	listeDizisi[bListeIndisi]->Caprazla(kListeDonenler,kListeDoneceklerinSayisi);
	listeDizisi[kListeIndisi]->Caprazla(bListeDonenler,bListeDoneceklerinSayisi);

	cout<< "En Buyuk Liste Orta Dugum Adresi: " << listeDizisi[bListeIndisi]->getListeOrta() <<endl;
	cout<< "En Buyuk Liste Degerler:" <<endl << *listeDizisi[bListeIndisi] <<endl<<endl;
	cout<< "En Kucuk Liste Orta Dugum Adresi: " << listeDizisi[kListeIndisi]->getListeOrta() <<endl;
	cout<< "En Kucuk Liste Degerler:" <<endl << *listeDizisi[kListeIndisi] <<endl<<endl;
	
	delete bListeDonenler;
	delete kListeDonenler;
	delete[] listeDizisi;
}