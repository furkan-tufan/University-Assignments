/****************************************************************************
**
**				ÖĞRENCİ ADI....................: FURKAN İSMET TUFAN
**				ÖĞRENCİ NUMARASI...............: g191210066
**				DERS GRUBU.....................: 2. ÖĞRETİM A GRUBU
****************************************************************************/

#include <iostream>
#include <time.h>
#include <iomanip>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Turkish");

	int boyut;
	cout << "Matris Boyutu: ";
	cin >> boyut;

	//Boyut değerinin 5 ile 25 arasında olmasını sağlayacak döngüyü yazıyoruz.
	for (;;)
	{
		//Boyut değeri doğruysa döngüden çıkaran koşulu yazıyoruz.
		if (boyut >= 5 && boyut <= 25)
			break;

		//Boyut değeri doğru değilse tekrar girilmesini isteyecek ifadeleri yazıyoruz.
		else
		{
			cout << "Boyut değeri 5 ile 25 aralığında olmalıdır.(5 ve 25 dahil)" << endl;
			cout << "Matris boyutunu yeniden giriniz: ";
			cin >> boyut;
		}
	}

	//Matrisin boyutu en fazla 25 olacağı için dizi boyutlarına 25 yazıyoruz.
	//25'ten küçük boyutlar girildiğinde bazı kısımların boş kalmasının sakıncası yok.
	int matris[25][25];

	srand(time(0));

	//Matris elemanlarına 1-9 aralığında rastgele değerler atayacağımız iç içe döngüyü yazıyoruz.
	for (int satir = 0; satir < boyut; satir++)
	{
		for (int sutun = 0; sutun < boyut; sutun++)
			matris[satir][sutun] = rand() % 9 + 1;
	}

	//Daha sonra kullanmak üzere fazladan bir dizi oluşturup rastgele değerler atıyoruz.
	int geciciDizi[25][25];
	for (int satir = 0; satir < boyut; satir++)
	{
		for (int sutun = 0; sutun < boyut; sutun++)
			geciciDizi[satir][sutun] = rand() % 9 + 1;
	}

	//Daha sonrasında "goto" kullanarak matrisi ve kullanıcı menüsünü gösteren kısma geri dönebilmek için etiket oluşturuyoruz.
a:

	// Sütun numaralarını gösteren ilk satır için ifade ve döngüler yazıyoruz.
	cout << setw(12);
	for (int sutunNumarasi = 1; sutunNumarasi <= boyut; sutunNumarasi++)
		cout << sutunNumarasi << setw(5);
	cout << endl;

	// Sütun numarasının altındaki çizgileri gösteren ifade ve döngüler yazıyoruz.
	cout << setw(12);
	for (int altCizgi = 1; altCizgi <= boyut; altCizgi++)
		cout << "_____";
	cout << endl << endl << setw(5);

	//Matris üyelerinin değerlerini gösteren satırları yazdırmak için döngü yazıyoruz.
	for (int satir = 0; satir < boyut; satir++)
	{
		cout << satir + 1 << " |" << setw(5);
		for (int sutun = 0; sutun < boyut; sutun++)
		{
			cout << matris[satir][sutun] << setw(5);
		}
		cout << endl << endl;
	}

	//Kullanıcı menüsünü ekranda gösterecek ifadeleri yazıyoruz.
	cout << endl;
	cout << "1)Sütun ve satırları yer değiştir" << endl;
	cout << "2)Tek sayıları başa al (Satır)" << endl;
	cout << "3)Ters Çevir (Sütun)" << endl;
	cout << "4)Toplamları yazdır" << endl;
	int secim;
	cout << "1 ile 4 arasında bir rakam yazarak yukardaki işlemlerden istediğinizi seçiniz: ";
	cin >> secim;

	// Kullanıcı 1. işlemi seçtiğinde yapılacakları yazıyoruz.
	if (secim == 1)
	{
		int degisecekSatir, degisecekSutun;
		cout << "Sırasıyla değiştirmek istediğiniz satır ve sütun değerlerini giriniz.";
		cin >> degisecekSatir >> degisecekSutun;

		//Seçilen değerlerin matris boyutundan büyük olması halinde uyarı verip matris ve kullanıcı menüsüne geri döndürecek kodu yazıyoruz.
		if (degisecekSatir > boyut || degisecekSutun > boyut)
		{
			cout << "Değiştireceğiniz satır veya sütun değeri matris boyutundan büyük olmamalıdır." << endl;
			goto a;
		}

		//Dizinin boyutuna değişken adı girilmediği için, değişecek satır ve sütun değerlerini dizide kullanılacak şekilde bulan iç içe döngüyü yazıyoruz.
		for (int satir = 0; satir < boyut; satir++)
		{
			for (int sutun = 0; sutun < boyut; sutun++)

				//Dizi elemanları 0'dan başladığı için kullanıcının girdiği değerlerden 1 eksiğini bulmasını istiyoruz.
				if (satir == degisecekSatir - 1 && sutun == degisecekSutun - 1)
				{
					//Kesişecek matris üyelerini değişkenlere kopyalıyoruz.
					int gecici1 = matris[satir][satir];
					int gecici2 = matris[sutun][sutun];

					//Seçilen satır ve sütunu yer değiştiren döngüyü yazıyoruz.
					for (int sayi = 0; sayi < boyut; sayi++)
					{
						geciciDizi[satir][sayi] = matris[satir][sayi];
						matris[satir][sayi] = matris[sayi][sutun];
						matris[sayi][sutun] = geciciDizi[satir][sayi];
					}
					matris[satir][sutun] = gecici1 + gecici2;
				}
		}
		// Satır ve sütunları yer değiştirdikten sonra yazdırması için a etiketine geri dönüyoruz.
		goto a;
	}

	// Kullanıcı 2. işlemi seçtiğinde yapılacakları yazıyoruz.
	if (secim == 2)
	{
		int satirDegeri;
		cout << "Satır numarası giriniz: ";
		cin >> satirDegeri;

		// Seçilen değerin matris boyutundan büyük olması halinde uyarı verip matris ve kullanıcı menüsüne geri döndürecek kodu yazıyoruz.
		if (satirDegeri > boyut)
		{
			cout << "Seçtiğiniz satır değeri matris boyutundan büyük olmamalıdır." << endl;
			goto a;
		}

		// Dizi boyutuna değişken adı girilemeyeceği için seçilen satırı bulması için döngü kullanıyoruz.
		for (int satir = 0; satir < boyut; satir++)
		{
			// Dizi elemanları 0'dan başladığı için kullanıcının girdiği değerden 1 eksiğini bulmasını istiyoruz.
			if (satir == satirDegeri - 1)
			{
				int tekSayaci = 0;

				//Tek sayıları satır başına alacak döngüyü yazıyoruz.
				for (int sayi = 0; sayi < boyut; sayi++)
				{
					if (matris[satir][sayi] % 2 == 1)
					{
						geciciDizi[satir][sayi] = matris[satir][sayi];
						matris[satir][sayi] = matris[satir][tekSayaci];
						matris[satir][tekSayaci] = geciciDizi[satir][sayi];
						tekSayaci++;
					}
				}
				// Tek sayılar başa alındıktan sonra yazdırması için a etiketine geri dönüyoruz.
				goto a;
			}
		}
	}

	//Kullanıcı 3. işlemi seçtiğinde yapılacakları yazıyoruz.
	if (secim == 3)
	{
		int sutunDegeri;
		cout << "Sütun numarası giriniz: ";
		cin >> sutunDegeri;

		//Seçilen değerin matris boyutundan büyük olması halinde uyarı verip matris ve kullanıcı menüsüne geri döndürecek kodu yazıyoruz.
		if (sutunDegeri > boyut)
		{
			cout << "Seçilen değer, matris boyutundan büyük olmamalıdır." << endl;
			goto a;
		}

		// Dizi boyutuna değişken adı girilemeyeceği için seçilen satırı bulması için döngü kullanıyoruz.
		for (int sutun = 0; sutun < boyut; sutun++)
		{
			// Dizi elemanları 0'dan başladığı için kullanıcının girdiği değerden 1 eksiğini bulmasını istiyoruz.
			if (sutun == sutunDegeri - 1)
			{
				//Dizi elemanları en son "boyut-1"de değer bulacağı için yeni bir değişken atıyoruz.
				int yeniBoyut = boyut - 1;

				//Sütundaki değerleri baştan aşağı ters çeviren döngüyü yazıyoruz.
				for (int n = 0; n < (boyut / 2); n++)
				{
					geciciDizi[yeniBoyut - n][sutun] = matris[yeniBoyut - n][sutun];
					matris[yeniBoyut - n][sutun] = matris[n][sutun];
					matris[n][sutun] = geciciDizi[yeniBoyut - n][sutun];
				}
				// Sütun ters çevrildikten sonra yazdırması için a etiketine geri dönüyoruz.
				goto a;
			}
		}
	}

	//Kullanıcı 4. işlemi seçtiğinde yapılacakları yazıyoruz.
	if (secim == 4)
	{
		int toplam = 0;

		// Tüm matris elemanlarını toplayan döngüyü giriyoruz.
		for (int satir = 0; satir < boyut; satir++)
			for (int sutun = 0; sutun < boyut; sutun++)
				toplam += matris[satir][sutun];

		matris[0][0] = toplam;

		// Her satırın ilk sütunundaki değeri bulan iç içe döngüyü giriyoruz.
		// 0.satırın ilk sütunu zaten bilindiği için 1.satırdan başlatıyoruz.
		for (int satir = 1; satir < boyut; satir++)
		{
			int cikarilacakSayi = 0;
			for (int sutun = 1; sutun < boyut; sutun++)
			{
				cikarilacakSayi += matris[satir - 1][sutun];
			}
			matris[satir][0] = matris[satir - 1][0] - cikarilacakSayi - matris[satir][0];
		}

		// İlk sütun dışındaki değerleri ilk sütunda bulduğumuz değerlerden faydalanarak bulan iç içe döngüyü yazıyoruz.
		for (int satir = 0; satir < boyut; satir++)
		{
			for (int sutun = 1; sutun < boyut; sutun++)
				matris[satir][sutun] = matris[satir][sutun - 1] - matris[satir][sutun];
		}
		// İstenen işlemler yapıldıktan sonra yazdırması için a etiketine geri dönüyoruz.
		goto a;
	}
}