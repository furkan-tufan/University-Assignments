/****************************************************************************
**
**				ÖĞRENCİ ADI..................: FURKAN İSMET TUFAN
**				ÖĞRENCİ NUMARASI.............: g191210066
**				DERS GRUBU...................: 2.ÖĞRETİM A GRUBU
****************************************************************************/

#include <iostream>
#include <Windows.h>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Turkish");

	int satirSayisi;
	cout << "Satır sayısını giriniz." << endl;
	cin >> satirSayisi;

	//Satır sayısı yanlış ise tekrar girmemizi sağlayan koşul işlemi.
	if (satirSayisi < 5 || satirSayisi>15)
	{
		//Yeniden girilmesi istenecek satır sayısını tekrar kontrol etmesi için döngü kullanıyoruz.
		for (;;)
		{
			cout << "Girdiğiniz satır sayısı hatalı. Yeniden giriniz." << endl;
			cin >> satirSayisi;

			//Döngü parantezine koşulu yazmak yerine döngüden çıkılması istenen durumu koşul işlemine yazıp break ile döngüden çıkartıyoruz.
			if (satirSayisi >= 5 && satirSayisi <= 15)
				break;
		}
	}

	int sutunSayisi;
	cout << "Sütun sayısını giriniz." << endl;
	cin >> sutunSayisi;

	//Sütun sayısı yanlış ise tekrar girmemizi sağlayan koşul işlemi.
	if (sutunSayisi < 5 || sutunSayisi>40)
	{
		//Yeniden girilmesi istenecek sütun sayısını tekrar kontrol etmesi için döngü kullanıyoruz.
		while (true)
		{
			cout << "Girdiğiniz sütun sayısı hatalı. Yeniden giriniz." << endl;
			cin >> sutunSayisi;

			//Döngü parantezine koşulu yazmak yerine döngüden çıkılması istenen durumu koşul işlemine yazıp break ile döngüden çıkartıyoruz.
			if (sutunSayisi >= 5 && sutunSayisi <= 40)
				break;
		}
	}

	//Sütun sayısı satır sayısının iki katı olmadığında tekrar girmemizi isteyen koşul işlemi.
	if (satirSayisi * 2 != sutunSayisi)
	{
		//Yeniden girilmesi istenecek satır ve sütun sayılarını tekrar kontrol etmesi için döngü kullanıyoruz.
		while (true)
		{
			cout << "Sütun sayısı, satır sayısının iki katı olmalıdır." << endl;
			cout << "Satır sayısı:";
			cin >> satirSayisi;
			cout << endl;
			cout << "Sütun sayısı:";
			cin >> sutunSayisi;

			while (sutunSayisi < 5 || sutunSayisi>15) //Girilen sütun değerini tekrar kontrol ediyoruz.
			{
				cout << "Girdiğiniz sütun sayısı hatalı. Yeniden giriniz." << endl;
				cin >> sutunSayisi;
			}
			while (satirSayisi < 5 || satirSayisi>40) //Girilen satır değerini tekrar kontrol ediyoruz.
			{
				cout << "Girdiğiniz satır sayısı hatalı. Yeniden giriniz." << endl;
				cin >> satirSayisi;
			}

			//Bağlı olunan while parantezine sadece "True" yazıp, döngüden çıkılması istenen durumu koşul işlemine yazıp break ile döngüden çıkartıyoruz.
			if (satirSayisi * 2 == sutunSayisi)
				break;
		}
	}

	//:::::::::::::::::::::::ŞEKLİN İLK PARÇASI:::::::::::::::::::::::::::::::::::::::::::

	//Şeklimizin ilk parçasının en üst satırındaki boşluksuz yıldızları yazdırıyoruz.
	for (int ustSatir = 1; ustSatir <= sutunSayisi; ustSatir++)
		cout << "*";

	cout << endl;

	/* Boşluk ve yıldızlarla şeklin ilk parçasını oluşturacak olacak döngüyü yazıyoruz.
	Baş ve sondaki boşluksuz yıldız dizisini bu koşuldan önce ve sonra yazdırdığımız için döngünün koşul kısmında "satirSayisi-2" kullanıyoruz.
	Yukarıdaki cümlede yazılandan dolayı aşağılarda kullanılacak satir=1'den kasıtımız içinde boşluk da bulunan ilk satırdır. */
	for (int satir = 1; satir <= satirSayisi - 2; satir++)
	{
		cout << "*"; 

		//Her satırın başındaki yıldızdan sonraki boşlukları yazmak için döngünün içinde başka bir döngü kullanıyoruz.
		for (int bosluk1 = 1; bosluk1 <= satirSayisi - 2 - satir; bosluk1++)
			cout << " ";

		cout << "*";

		//İkinci yıldızdan sonraki boşlukları yazmak için  başka bir döngü kullanıyoruz.
		for (int bosluk2 = 1; bosluk2 <= satir * 2; bosluk2++)
			cout << " ";

		cout << "*";

		//Üçüncü yıldızdan sonraki boşlukları yazmak için  başka bir döngü kullanıyoruz.
		for (int bosluk3 = 1; bosluk3 <= satirSayisi - 2 - satir; bosluk3++)
			cout << " ";

		cout << "*";
		Sleep(100);
		cout << endl;
	}

	//Şeklimizin ilk parçasının en alt satırındaki boşluksuz yıldızları yazdırıyoruz.
	for (int altSatir = 1; altSatir <= sutunSayisi; altSatir++)
		cout << "*";


	cout << endl << endl;

	//:::::::::::::::::::::::ŞEKLİN İKİNCİ PARÇASI:::::::::::::::::::::::::::::::::::::::::::

	//Şeklimizin ikinci parçasının en üst satırındaki boşluksuz yıldızları yazdırıyoruz.
	for (int ustSatir = 1; ustSatir <= sutunSayisi; ustSatir++)
		cout << "*";
	cout << endl;

	/* Boşluk ve yıldızlarla şeklin ikinci parçasını oluşturacak olacak döngüyü yazıyoruz.
	Baş ve sondaki boşluksuz yıldız dizisini bu koşuldan önce ve sonra yazdırdığımız için döngünün koşul kısmında "satirSayisi-2" kullanıyoruz.
	Yukarıdaki cümlede yazılandan dolayı aşağılarda kullanılacak satir=1'den kasıtımız içinde boşluk da bulunan ilk satırdır. */

	for (int satir = 1; satir <= satirSayisi - 2; satir++)
	{
		cout << "*";

		//Her satırın başındaki yıldızdan sonraki boşlukları yazmak için döngünün içinde başka bir döngü kullanıyoruz.
		for (int bosluk1 = 1; bosluk1 <= satir - 1; bosluk1++)
			cout << " ";

		cout << "*";

		//İkinci yıldızdan sonraki boşlukları yazmak için  başka bir döngü kullanıyoruz.
		for (int bosluk2 = 1; bosluk2 <= (sutunSayisi - 2) - 2 * satir; bosluk2++)
			cout << " ";

		cout << "*";

		//Üçüncü yıldızdan sonraki boşlukları yazmak için  başka bir döngü kullanıyoruz.
		for (int bosluk3 = 1; bosluk3 <= satir - 1; bosluk3++)
			cout << " ";

		cout << "*";
		Sleep(100);
		cout << endl;
	}

	//Şeklimizin ikinci parçasının en alt satırındaki boşluksuz yıldızları yazdırıyoruz.
	for (int altSatir = 1; altSatir <= sutunSayisi; altSatir++)
		cout << "*";
}