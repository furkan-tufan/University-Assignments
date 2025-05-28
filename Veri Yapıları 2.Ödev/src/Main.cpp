/**
* @file         Main.cpp
* @description  main fonksiyonu içeriyor. Veri.txt'den verileri okuyup ağaç düğümlerine eklemeyi sağlıyor.
* @course       2/B Şubesi
* @assignment   Ödev 2
* @date         22.12.2020
* @author       Furkan İsmet Tufan / furkan.tufan@ogr.sakarya.edu.tr
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <windows.h>
#include <IcAgac.hpp>
#include <DisAgac.hpp>
using namespace std;

int main(){
	SetConsoleOutputCP(65001);
	
	DisAgac* sirketler=new DisAgac();
	string sirket, isim, tempYil;
	int yil;
	
	ifstream dosya("Veri.txt", ios::in);
	while(!dosya.eof()){
		getline(dosya, sirket, '#');
		getline(dosya, isim, '#');
		getline(dosya, tempYil, '\n');
		yil = stoi(tempYil);
		
		if(sirketler->Search(sirket)==0){
			sirketler->Insert(sirket, 0);
			sirketler->BulVeGetir(sirket)->calisanlar->Insert(isim, yil);
			sirketler->calisanSayisiArttir( sirketler->BulVeGetir(sirket) );
		}
		else if(sirketler->Search(sirket)==1){
			sirketler->BulVeGetir(sirket)->calisanlar->Insert(isim, yil);
			sirketler->calisanSayisiArttir( sirketler->BulVeGetir(sirket) );
		}
	}
	dosya.close();
	
	sirketler->PostOrder();

	delete sirketler;
}