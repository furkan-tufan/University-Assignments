/****************************************************************************
**
**				ÖĞRENCİ ADI..................: FURKAN İSMET TUFAN
**				ÖĞRENCİ NUMARASI.............: G191210066
**				DERS GRUBU...................: 2.ÖĞRETİM A GRUBU
****************************************************************************/

#include <iostream>
#include <Windows.h>
#include <iomanip>
using namespace std;

// Oluşturacağımız sahne için bir yapı tasarlıyoruz ve içine sahnenin boyut değişkenlerini ve karakter değişkenini koyuyoruz.
struct sahne
{
	int genislik;
	int yukseklik;
	char karakter;
};

// "L şekli" için bir yapı tasarlıyoruz ve içine şeklin boyut değişkenini, koordinat değişkenlerini ve karakter değişkenini koyuyoruz.
struct LSekli
{
	int x;
	int y;
	int boyut;
	char karakter;
};

// Okunabilirliği artırmak için "main" dışındaki fonksiyonları main'in altına yazıp buraya prototiplerini yazıyoruz.
void koordinatAta(int x, int y);
void  imlecGizleyici();
sahne sahneOlustur();
void sahneCiz(sahne s);
LSekli lSekliOlustur();
void lSekliCiz(LSekli l);
LSekli lSekliAsagiGotur(LSekli l);

// Ara ara kullanmak üzere global bir dizi oluşturuyoruz.
char goruntu[50][30];

int main()
{
	setlocale(LC_ALL, "Turkish");
	srand(time(0));

	sahne sahneDegerleri = sahneOlustur(); // Çizilecek sahnenin değerlerini belirliyoruz.
	for (;;) //Sonsuz çizim döngüsü.
	{
		LSekli sekilDegerleri = lSekliOlustur(); // Her seferinde l şekli değerlerinin değişmesini sağlamak için sonsuz döngünün içine yazıyoruz.
		system("cls");
		sahneCiz(sahneDegerleri); // Sahneyi yazdırıyoruz.
		lSekliCiz(sekilDegerleri); // L Şeklini yazdırıyoruz.

		// Sahnenin son satırlarına kadar L şeklinin aşağı yönde hareket etmesini sağlayacak döngü.
		for (int x = 0; x + 5 + sekilDegerleri.boyut * 2 <= sahneDegerleri.yukseklik; x++)
		{

			sekilDegerleri = lSekliAsagiGotur(sekilDegerleri);
			system("cls"); //Şeklin önceki hareketinin izinin silinmesini sağlıyoruz.
			sahneCiz(sahneDegerleri);
			lSekliCiz(sekilDegerleri);
			imlecGizleyici();
			Sleep(100);
		}
	}
}

void sahneCiz(sahne s)
{
	// Global değişkenin ilk satırını karakterlerle dolduruyoruz.
	for (int x = 0; x < s.genislik; x++)
		goruntu[x][0] = s.karakter;

	// Global değişkenin ilk sütununu karakterlerle dolduruyoruz.
	for (int y = 0; y < s.yukseklik; y++)
		goruntu[0][y] = s.karakter;

	//Global değişkenin çizilecek sahnenin genişliğine dahil olan son sütununu karakterlerle dolduruyoruz.
	for (int y = 0; y < s.yukseklik; y++)
		goruntu[s.genislik - 1][y] = s.karakter;

	//Global değişkenin çizilecek sahnenin yüksekliğine dahil olan son satırını karakterlerle dolduruyoruz.
	for (int x = 0; x < s.genislik; x++)
		goruntu[x][s.yukseklik - 1] = s.karakter;

	// Karakterleri içine yerleştirdiğimiz global değişkeni yazdırıyoruz ve sahneyi yazdırmış oluyoruz.
	for (int y = 0; y < s.yukseklik; y++)
	{
		for (int x = 0; x < s.genislik; x++)
			cout << goruntu[x][y];
		cout << endl;
	}
}

sahne sahneOlustur()
{
	sahne S; // "return" ile döndürmek için sahne yapısında bir değişken oluşturuyoruz.

	int genislikDegerleri[3] = { 30,40,50 }; // Genişlik değeri olabilecek sayıları içeren dizi.
	int secilecekDeger = rand() % 3; // Dizinin hangi indexinin seçileceğini rand fonksiyonu ile buluyoruz.

	// Index numarasına değişken adı girilemediği için seçilen random değeri bulan döngü & koşul yazıyoruz.
	for (int i = 0; i < 3; i++)
	{
		if (i == secilecekDeger)
		{
			S.genislik = genislikDegerleri[i]; // Genişlik değerine, dizinin seçilen indexinin değerini atıyoruz.
			break;
		}
	}

	int yukseklikDegerleri[11]; // Yükseklik değeri olabilecek sayıları saklayacak diziyi oluşturuyoruz.

	// Olabilecek yükseklik değerlerini (20'den 30'a kadar) diziye yerleştirecek döngüyü yazıyoruz.
	for (int i = 0; i < 11; i++)
		yukseklikDegerleri[i] = i + 20;

	secilecekDeger = rand() % 11; // Dizinin hangi indexinin seçileceğini rand fonksiyonu ile buluyoruz.

	// Index numarasına değişken adı girilemediği için seçilen random değeri bulan döngü & koşul yazıyoruz.
	for (int i = 0; i < 11; i++)
	{
		if (i == secilecekDeger)
		{
			S.yukseklik = yukseklikDegerleri[i]; // Yükseklik değerine, dizinin seçilen indexinin değerini atıyoruz.
			break;
		}
	}

	char karakterDegerleri[5] = { '*', '#' , '$' , '+' , '@' }; // Seçilebilecek karakterleri bir diziye yerleştiriyoruz.
	secilecekDeger = rand() % 5; // Dizinin hangi indexinin seçileceğini rand fonksiyonu ile buluyoruz.

	// Index numarasına değişken adı girilemediği için seçilen random değeri bulan döngü & koşul yazıyoruz.
	for (int i = 0; i < 5; i++)
	{
		if (i == secilecekDeger)
		{
			S.karakter = karakterDegerleri[i]; // Karakter değerine, dizinin seçilen indexinin değerini atıyoruz.
			break;
		}
	}

	return S;
}

LSekli lSekliOlustur()
{
	LSekli L; // "return" ile döndürmek için LSekli yapısında bir değişken oluşturuyoruz.

	int xDegerleri[21]; // x koordinatının alabileceği değerleri saklayacağımız diziyi oluşturuyoruz.

	// Diziye x'in alabileceği değerleri yerleştiriyoruz.
	for (int i = 0; i < 21; i++)
		xDegerleri[i] = i + 5;

	int secilecekDeger = rand() % 21; // Dizinin hangi indexinin seçileceğini rand fonksiyonu ile buluyoruz.

	// Index numarasına değişken adı girilemediği için seçilen random değeri bulan döngü & koşul yazıyoruz.
	for (int i = 0; i < 21; i++)
		if (i == secilecekDeger)
		{
			L.x = xDegerleri[i]; // Koordinat değerine, dizinin seçilen indexinin değerini atıyoruz.
			break;
		}

	L.x = L.x - 1; // Index numaraları 0'dan başladığı için kullanım kolaylığı adına L.x 'den bir çıkarıyoruz.

	L.y = 3;
	L.y = L.y - 1; // Index numaraları 0'dan başladığı için kullanım kolaylığı adına L.y 'den bir çıkarıyoruz.

	char karakterDegerleri[5] = { '*', '#' , '$' , '+' , '@' };  // Seçilebilecek karakterleri bir diziye yerleştiriyoruz.
	secilecekDeger = rand() % 5; // Dizinin hangi indexinin seçileceğini rand fonksiyonu ile buluyoruz.

	// Index numarasına değişken adı girilemediği için seçilen random değeri bulan döngü & koşul yazıyoruz.
	for (int i = 0; i < 5; i++)
	{
		if (i == secilecekDeger)
		{
			L.karakter = karakterDegerleri[i]; // Karakter değerine, dizinin seçilen indexinin değerini atıyoruz.
			break;
		}
	}

	int boyutDegerleri[6] = { 2,3,4,5,6,7 }; // Seçilebilecek boyut değerlerini bir diziye yerleştiriyoruz.
	secilecekDeger = rand() % 6; // Dizinin hangi indexinin seçileceğini rand fonksiyonu ile buluyoruz.

	// Index numarasına değişken adı girilemediği için seçilen random değeri bulan döngü & koşul yazıyoruz.
	for (int i = 0; i < 6; i++)
		if (i == secilecekDeger)
		{
			L.boyut = boyutDegerleri[i]; // Boyut değerine, dizinin seçilen indexinin değerini atıyoruz.
			break;
		}
	return L;
}

void lSekliCiz(LSekli l)
{
	int gercekX = l.x; //İlk x değerini gercekX değişkenine kaydediyoruz.
	int gercekY = l.y; //İlk y değerini gercekY değişkenine kaydediyoruz.

	// L şeklinin ilk satırını yazdırıyoruz.
	for (; l.x < gercekX + l.boyut; l.x++)
	{
		koordinatAta(l.x, l.y);
		cout << l.karakter;
	}
	l.x = gercekX; //Değişen l.x değerini ilk l.x değerine eşitliyoruz.

	// L şeklinin ikinci satırından orta satırının öncesine kadarını yazdırıyoruz.
	for (; l.y <= gercekY + l.boyut - 1; l.y++)
	{
		koordinatAta(l.x, l.y + 1);
		cout << l.karakter;
		koordinatAta(l.x + l.boyut - 1, l.y + 1);
		cout << l.karakter;
	}
	l.y = gercekY; //Değişen l.y değerini ilk l.y değerine eşitliyoruz.

	koordinatAta(l.x, l.y + l.boyut);
	cout << l.karakter; // L şeklinin orta satırınının ilk karakterini yazdırıyoruz.

	// L şeklinin orta satırınının sonundaki karakterleri yazdırıyoruz.
	for (; l.x < gercekX + l.boyut + 1; l.x++)
	{
		koordinatAta(l.x + l.boyut - 1, l.y + l.boyut);
		cout << l.karakter;
	}
	l.x = gercekX; //Değişen l.x değerini ilk l.x değerine eşitliyoruz.

	// L şeklinin orta satırının altından alt satırın öncesine kadarını yazdırıyoruz.
	for (; l.y < gercekY + l.boyut - 1; l.y++)
	{
		koordinatAta(l.x, l.y + l.boyut + 1);
		cout << l.karakter;
		koordinatAta(l.x + l.boyut * 2 - 1, l.y + l.boyut + 1);
		cout << l.karakter;
	}
	l.y = gercekY; //Değişen l.y değerini ilk l.y değerine eşitliyoruz.

	// L şeklinin en alt satırını yazdırıyoruz.
	for (; l.x < gercekX + l.boyut * 2; l.x++)
	{
		koordinatAta(l.x, l.y + l.boyut * 2);
		cout << l.karakter;
	}
	l.x = gercekX; //Değişen l.x değerini ilk l.x değerine eşitliyoruz.
}

LSekli lSekliAsagiGotur(LSekli l)
{

	l.y += 1; // Şeklin bir alt satıra inmesi için şeklin y koordinatını 1 artırıyoruz.
	return l;
}

void koordinatAta(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void imlecGizleyici()
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO    cursorInfo;
	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = false;
	SetConsoleCursorInfo(out, &cursorInfo);
}