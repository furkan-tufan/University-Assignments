/****************************************************************************
**
**				ÖĞRENCİ ADI..................: FURKAN İSMET TUFAN
**				ÖĞRENCİ NUMARASI.............: G191210066
**				DERS GRUBU...................: 2.ÖĞRETİM A GRUBU
****************************************************************************/

#include<iostream>
#include<string>
#include<fstream>
#include<time.h>
#include<Windows.h>
#include<iomanip>
#include<stdlib.h>
#include<sstream> 
using namespace std;

void koordinatAta(int x, int y);
int sinifSayisi = 0; // her yerden ulaşabilmek için global bir sınıf sayısı değişkeni oluşturuyoruz.

class Ogrenci
{
private:
	string ad;
	string soyAd;
	int numara;

public:

	//private olarak tanımlanan ad değişkenine ulaşabilmeyi sağlar.
	string getAd()
	{
		return ad;
	}

	//private olarak tanımlanan ad değişkenini değiştirmeyi sağlar. DosyaYonetim sınıfının isimGetir fonksiyonunu parametre alarak kullanılacak.
	void setAd(string ismiAyarla)
	{
		ad = ismiAyarla;
	}

	//private olarak tanımlanan soyAd değişkenine ulaşabilmeyi sağlar.
	string getSoyAd()
	{
		return soyAd;
	}

	//private olarak tanımlanan soyAd değişkenini değiştirmeyi sağlar. DosyaYonetim sınıfının soyIsimGetir fonksiyonunu parametre alarak kullanılacak.
	void setSoyAd(string soyIsmiAyarla)
	{
		soyAd = soyIsmiAyarla;
	}

	//private olarak tanımlanan numara değişkenine ulaşabilmeyi sağlar.
	int getNumara()
	{
		return numara;
	}

	//private olarak tanımlanan numara değişkenine random değer atamayı sağlar.
	void setNumara()
	{
		numara = rand() % 900 + 100; //100 ile 999 arasında değerler atar.
	}

};

class Sinif
{
public:
	string sinifIsmi;

	// oluşturulan sınıfın ismini uygun şekilde oluşturur.
	string sinifIsmiOlustur()
	{
		//global değişken olan ("int" tipindeki) sınıf sayısının  string değişkenine aktarılmasını sağlayan fonksiyon.
		string sayi = to_string(sinifSayisi);
		srand(time(0));
		//65 ile 90 arasındaki sayıların ascii tablosunda a-z arasına denk gelmesi sebebiyle 65-90 arasında random sayı seçiyoruz.
		int randomNumber = rand() % 26 + 65;
		// seçtiğimiz random sayıyı ascii tablosundaki (char) karşılığına çevirip "harf" değişkenine atıyoruz.
		char harf = (char)randomNumber;
		//bulduğumuz sınıf sayısını ve random harfi birleştirip sınıf ismine yazıyoruz ve return ile döndürüyoruz.
		sinifIsmi = sayi + harf;
		return sinifIsmi;
	}

	int ogrenciSayisi = 0; //Kullanıcı menüsünden öğrenci ekle seçildiğinde oluşturulan sınıf nesnesinin ogrenciSayisi değişkeni 1 artırılacak.

	string ogrenciler[100];

	// Her çağrıldığında parametre olarak aldığı öğrenci nesnesini öğrenciler dizisine aktaran  metodu yazıyoruz.
	void ogrenciEkle(Ogrenci o1)
	{
		ogrenciler[ogrenciSayisi - 1] = o1.getAd() + o1.getSoyAd();
	}
};

class Okul
{
public:

	char solUstKose = 201;
	char duz = 205;
	char sagUstKose = 187;
	char solAltKose = 200;
	char sagAltKose = 188;
	char dikey = 186;

	//Kutu şeklinin üst kısmının yazdırılmasını sağlayan metod.
	void ustYazdir(int elemanSayisi)
	{

		cout << solUstKose;
		for (int i = 0; i < elemanSayisi; i++)
		{
			cout << duz;
		}
		cout << sagUstKose;
	}

	//Kutu şeklinin alt kısmının yazdırılmasını sağlayan metod.
	void altYazdir(int elemanSayisi)
	{
		cout << solAltKose;
		for (int i = 0; i < elemanSayisi; i++)
		{
			cout << duz;
		}
		cout << sagAltKose;
	}

	//İçine sınıf isminin yazılacağı kutuyu çağrıldığı zaman yazdıran metod.
	void sinifCercevesi(int sinifSirasi) //Sınıf sırası değişkenini parametre alır. Bu değişken, kaçıncı sınıfın kutusunu çizdiğimizi belirtir.
	{
		//Kaçıncı sınıfın kutusunu çiziyorsak yatay doğrultuyu ona göre belirtiyoruz.
		koordinatAta(0 + (sinifSirasi - 1) * 16, 0);
		cout << dikey << setw(15) << dikey << endl;
		koordinatAta(0 + (sinifSirasi - 1) * 16, 1);
		altYazdir(14);
	}

	//İçine öğrenci bilgilerinin yazılacağı kutuyu çağrıldığı zaman yazdıran metod.
	//kacOgrenciVar değişkeni sınıfın kaçıncı öğrencisinin kutusunu çizdiğimizi, sinifSirasi için kaçıncı sınıfın öğrencisinin kutusunu çizdiğimizi belli eder.
	void ogrenciCercevesi(int kacOgrenciVar, int sinifSirasi)
	{
		koordinatAta(1 + (sinifSirasi - 1) * 16, 2 + ((kacOgrenciVar - 1) * 5));
		ustYazdir(12);
		cout << endl;
		koordinatAta(1 + (sinifSirasi - 1) * 16, 3 + ((kacOgrenciVar - 1) * 5));
		cout << dikey << endl;
		koordinatAta(1 + (sinifSirasi - 1) * 16, 4 + ((kacOgrenciVar - 1) * 5));
		cout << dikey << endl;
		koordinatAta(1 + (sinifSirasi - 1) * 16, 5 + ((kacOgrenciVar - 1) * 5));
		cout << dikey << endl;
		for (int i = 1; i < 4; i++) //Kutunun orta kısmının sağ tarafındaki dikey çizgileri çizdiriyoruz.
		{
			koordinatAta(14 + (sinifSirasi - 1) * 16, i + 2 + ((kacOgrenciVar - 1) * 5));
			cout << dikey;
		}
		koordinatAta(1 + (sinifSirasi - 1) * 16, 6 + ((kacOgrenciVar - 1) * 5));
		altYazdir(12);
	}
};

class DosyaYonetim
{
public:
	//Çağrıldığı zaman rastgele isim döndüren sınıf metodu. Ogrenci sınıfının nesnelerinin ismini belirlemek için  kullanırız.
	string isimSec()
	{
		srand(time(0));
		string isimListesi[5000];
		int sayac = 0;

		//İsimler.txt dosyasındaki isimleri diziye aktarıyoruz. Daha sonra bu dizinin içinden bir eleman seçilecek.
		ifstream isimDosyasi;
		isimDosyasi.open("isimler.txt", ios::in);
		if (isimDosyasi.is_open()) //Dosya açılırsa işlemi yapıyor. açılmassa "else" ile uyarı veriyor.
		{
			while (!isimDosyasi.eof()) //Dosyanın sonuna gelene kadar okumaya devam ediyor.
			{
				isimDosyasi >> isimListesi[sayac];
				sayac++;
			}
			isimDosyasi.close();
		}
		else
			cout << "Dosya acilamadi";

		//isimListesi dizisinin kaçıncı elemanını seçeceğimizi belirlemek için random sayı buluyoruz.
		int randomSayi;
		randomSayi = rand() % 5000;
		//Dizinin seçilen random sayı indexindeki elemanını alıp isim olarak döndürüyoruz.
		string secilenIsim = isimListesi[randomSayi];
		return secilenIsim;
	}

	//Çağrıldığı zaman rastgele soyisim döndüren sınıf metodu. Ogrenci sınıfının nesnelerinin soyismini belirlemek için  kullanırız.
	string soyIsimSec()
	{
		srand(time(0));
		string soyIsimListesi[300];
		int sayac2 = 0;
		//Soyisimler.txt dosyasındaki soyisimleri diziye aktarıyoruz. Daha sonra bu dizinin içinden bir eleman seçilecek.
		ifstream soyIsimDosyasi("soyisimler.txt", ios::in);
		if (soyIsimDosyasi.is_open()) //Dosya açılırsa işlemi yapıyor. açılmassa "else" ile uyarı veriyor.
		{
			while (soyIsimDosyasi.good()) //Dosyanın sonuna gelene kadar okumaya devam ediyor.
			{
				soyIsimDosyasi >> soyIsimListesi[sayac2];
				sayac2++;
			}
			soyIsimDosyasi.close();
		}
		else
			cout << "AÇILAMADI";

		//soyIsimListesi dizisinin kaçıncı elemanını seçeceğimizi belirlemek için random sayı buluyoruz.
		int randomSayi2;
		randomSayi2 = rand() % 278;
		//Dizinin seçilen random sayı indexindeki elemanını alıp soyisim olarak döndürüyoruz.
		string secilenSoyIsim = soyIsimListesi[randomSayi2];
		return secilenSoyIsim;
	}

	//Verilen öğrenci nesnesini "kayitlar.txt" dosyasına kaydeden  metod.
	void ogrenciKaydet(Ogrenci o)
	{
		ofstream ogrenciKayidi("kayitlar.txt", ios::app);
		if (ogrenciKayidi.is_open())
		{
			ogrenciKayidi << o.getAd() << " " << o.getSoyAd() << " " << o.getNumara() << endl;
			ogrenciKayidi.close();
		}
		else
			cout << "Dosya açılamadı";
	}

	//Verilen sınıf nesnesini "kayitlar.txt" dosyasına kaydeden metod.
	void sinifKaydet(Sinif s)
	{

		ofstream sinifKayidi("kayitlar.txt", ios::app);
		if (sinifKayidi.is_open())
		{
			sinifKayidi << s.sinifIsmi << "\n";
			sinifKayidi.close();
		}
		else
			cout << "Dosya açılamadı";
	}
};

class Program
{
public:
	Okul okul;
	void calistir()
	{
		fstream x("kayitlar.txt", ios::trunc); //calistir() metodu ilk çalıştığında kayıtlar.txt dosyasının içini temizliyoruz.
		x.close(); //  ve dosyayı geri kapıyoruz.

		//Seçim sorusunun tekrarlanacağı koordinatı "KoordinatAta(x, secimSorusuKonumu)" fonksiyonuyla belirleyeceğiz. Dikey koordinatını her seçimden sonra 2 artırıyoruz
		int secimSorusuKonumu = 25;

		int ogrenciSayisi;

		// Birçok işlemde kullanmak üzere değişkenler oluşturuyoruz. Kullanma şekli ileride anlatılacaktır.
		int a1 = 0, b2 = 0, c3 = 0, d4 = 0, e5 = 0, f6 = 0, g7 = 0, h8 = 0, j9 = 0, k10 = 0;

		//Sınıf ve öğrencileri yazdırmak için 20 satırlık boşluk bıraktıktan sonra kullancıcı menüsünü ortaya çıkarıyoruz.
		for (int i = 0; i < 20; i++)
			cout << endl;

		cout << "1. Ogrenci Ekle" << endl;
		cout << "2. Sinif Ekle" << endl;
		cout << "3. Ogrenci Degistir" << endl;
		cout << "4. Ogrenci Sil" << endl;
		cout << "5. Sinif Sil" << endl;
		cout << "6. Cikis" << endl;

		//Seçimi sürekli sorması için sonsuz döngüye alıyoruz.
		for (;;)
		{
			cout << "Seciminizi sayi olarak giriniz: ";
			int secim;
			cin >> secim;
			if (secim == 1)
			{
				secimSorusuKonumu += 2;
				string sinifSecimi;
				cout << "Hangi sinifa eklemek istiyorsunuz?: ";
				cin >> sinifSecimi;
				Ogrenci ogr;
				Sinif sin;
				DosyaYonetim dos;
				//Öğrencinin ismini rastgele seçiyoruz.
				ogr.setAd(dos.isimSec());
				//Öğrencinin soy ismini rastgele seçiyoruz.
				ogr.setSoyAd(dos.soyIsimSec());
				//Öğrencinin numarasını rastgele seçiyoruz.(zaten "setNumara()" fonksiyonu kendi içinde random değer atıyor. Parametreye gerek yok.)
				ogr.setNumara();
				//Öğrencimizi "kayitlar.txt" dosyasına kaydediyoruz.
				dos.ogrenciKaydet(ogr);

				sin.ogrenciSayisi += 1;
				sin.ogrenciEkle(ogr); //öğrenciyi sınıf nesnesinin içindeki öğrenciler dizisine aktarıyoruz.

				int sinifSirasi; //Seçilen sınıf isminin sayı kısmını kaydetmek için bir değişken oluşturuyoruz.
				sinifSirasi = stoi(sinifSecimi); //stoi fonksiyonuyla string tipindeki sınıfSecimi'nden sayı kısmını alıp sinifSirasi'na koyuyoruz.
				//a1 değişkeni ilk sınıfı temsil ediyor, b2 değişkeni 2.sınıfı temsil ediyor, c3 değişkeni 3.sınıfı temsil ediyor mantığıyla 10 değişken oluşturduk.
				//En fazla 10 sınıf olacağını düşünüyoruz ve hangi sınıf seçildiyse o sınıfın temsilci değişkenini bir artırıp işlem için öğrenci sayısını seçilen sınıfın temsilcisine eşitliyoruz.
				switch (sinifSirasi)
				{
				case 1:
					a1 += 1;
					ogrenciSayisi = a1;
					break;
				case 2:
					b2 += 1;
					ogrenciSayisi = b2;
					break;
				case 3:
					c3 += 1;
					ogrenciSayisi = c3;
					break;
				case 4:
					d4 += 1;
					ogrenciSayisi = d4;
					break;
				case 5:
					e5 += 1;
					ogrenciSayisi = e5;
					break;
				case 6:
					f6 += 1;
					ogrenciSayisi = f6;
					break;
				case 7:
					g7 += 1;
					ogrenciSayisi = g7;
					break;
				case 8:
					h8 += 1;
					ogrenciSayisi = h8;
					break;
				case 9:
					j9 += 1;
					ogrenciSayisi = j9;
					break;
				case 10:
					k10 += 1;
					ogrenciSayisi = k10;
					break;
				}

				// Öğrencinin kaçıncı sınıf numarasında olduğunu ve sınıfın kaçıncı öğrencisi olduğunu parametre olarak atayıp öğrencinin kutu çercevesini yazıyoruz.
				okul.ogrenciCercevesi(ogrenciSayisi, sinifSirasi);

				//Aşağıdaki satırlarda öğrencinin isim,soyisim ve numarasını öğrenci için oluşturulan kutuya yazdırıyoruz.
				koordinatAta(2 + (sinifSirasi - 1) * 16, 3 + 5 * (ogrenciSayisi - 1));
				cout << setw(12) << ogr.getAd();
				koordinatAta(2 + (sinifSirasi - 1) * 16, 4 + 5 * (ogrenciSayisi - 1));
				cout << setw(12) << ogr.getSoyAd();
				koordinatAta(2 + (sinifSirasi - 1) * 16, 5 + 5 * (ogrenciSayisi - 1));
				cout << setw(12) << ogr.getNumara();

				//Seçim sorusunu tekrar çıkarması için koordinat belirliyoruz.
				koordinatAta(0, secimSorusuKonumu);
			}
			if (secim == 2)
			{
				secimSorusuKonumu += 2;
				sinifSayisi += 1;
				//Kaçıncı sınıf olduğunu parametreye koyarak sınıf isminin yazılacağı kutuyu çizdiriyoruz.
				okul.sinifCercevesi(sinifSayisi);
				Sinif yeniSinif;
				//Yeni oluşturduğumuz sınıfın ismini belirliyoruz.
				yeniSinif.sinifIsmi = yeniSinif.sinifIsmiOlustur();
				DosyaYonetim dos2;
				//Sınıfı "kayitlar.txt" dosyasına kaydediyoruz.
				dos2.sinifKaydet(yeniSinif);
				//Oluşturulan kutunun içine sınıfın ismini yazıyoruz.
				koordinatAta(7 + (sinifSayisi - 1) * 16, 0);
				cout << yeniSinif.sinifIsmi;
				//Seçim sorusunu tekrar çıkarması için koordinat belirliyoruz.
				koordinatAta(0, secimSorusuKonumu);
			}
			if (secim == 3)
			{

			}
			if (secim == 4)
			{

			}
			if (secim == 5)
			{
				secimSorusuKonumu += 2;
				sinifSayisi = sinifSayisi - 1;
				string silinecekSinif;
				cout << "Silmek istediğiniz sinifin adi: ";
				cin >> silinecekSinif; //silinecek sınıfın ismindeki sayıyı kaydetmek için değişken oluşturduk
				int sinifNumarasi = stoi(silinecekSinif); //stoi fonksiyonuyla silinecekSinif değişkenin sayı kısmını string'den int'e aktardık ve sinifNumarasi'na eşitledik.
				int siniftakiOgrenciSayisi;
				// Yukarıda (a1, b2, c3....) değişkenlerinin her birinin bir sınıfı temsil ettiğini belirmtiştik. 
				// Bir sınıfa her öğrenci eklendiğinde o sınıfı temsil eden değişkeni 1 artırmıştık.
				// sinifNumarasi değişkeniyle kaçıncı sınıfı sileceğimizi tespit ettik ve o sınıfı temsil eden değişkenin değerini siniftakiOgrenciSayisi'na eşitliyoruz.
				switch (sinifNumarasi)
				{
				case 1:
					siniftakiOgrenciSayisi = a1;
					break;
				case 2:
					siniftakiOgrenciSayisi = b2;
					break;
				case 3:
					siniftakiOgrenciSayisi = c3;
					break;
				case 4:
					siniftakiOgrenciSayisi = d4;
					break;
				case 5:
					siniftakiOgrenciSayisi = e5;
					break;
				case 6:
					siniftakiOgrenciSayisi = f6;
					break;
				case 7:
					siniftakiOgrenciSayisi = g7;
					break;
				case 8:
					siniftakiOgrenciSayisi = h8;
					break;
				case 9:
					siniftakiOgrenciSayisi = j9;
					break;
				case 10:
					siniftakiOgrenciSayisi = k10;
					break;
				}

				//Tespit edilen sınıfı komple siliyoruz.
				koordinatAta(0 + (sinifNumarasi - 1) * 16, 0);
				for (int i = 0; i < 16; i++)
				{
					for (int j = 0; j < 2 + (siniftakiOgrenciSayisi * 5); j++)
					{
						koordinatAta(i + (sinifNumarasi - 1) * 16, j);
						cout << " ";
					}
				}

				koordinatAta(0, secimSorusuKonumu);
			}
			if (secim == 6)
			{
				exit(EXIT_FAILURE);
			}
		}
	}
};

int main()
{
	Program prog;
	prog.calistir();
}

void koordinatAta(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}