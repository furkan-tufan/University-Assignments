/****************************************************************************
**			    SAKARYA ÜNİVERSİTESİ
**				BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**				BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				NESNEYE DAYALI PROGRAMLAMA DERSİ
**				2019-2020 BAHAR DÖNEMİ
**	
**				ÖDEV NUMARASI..........: ÖDEV 1
**				ÖĞRENCİ ADI............: FURKAN İSMET TUFAN
**				ÖĞRENCİ NUMARASI.......: g191210066
**              DERSİN ALINDIĞI GRUP...: A GRUBU
****************************************************************************/

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace g191210066
{
    class g191210066
    {

        static void Main(string[] args)
        {
            Random random = new Random();

            //öğrencilerin not değerlerini yerleştirmek için diziler oluşturuyoruz.
            double[] odev1 = new double[100];
            double[] odev2 = new double[100];
            double[] vize = new double[100];
            double[] final = new double[100];

            // aralarından rastgele kombinasyonlarla isim oluşturması için dizilere 30'ar adet ad ve soyad giriyoruz.
            string[] isimler = new string[30] { "AYCAN", "CEMİL", "BERNA", "FURKAN", "HÜSEYİN", "ERKAN", "HAKAN", "BAYRAM", "RUMEYSA", "KÜBİLAY", "VEYSİ", "ZUHAL",
                "YÜCEL", "ESMERALDA", "NİLÜFER", "BURHAN", "VOLKAN", "SELCEN", "MUSTAFA", "HATİCE", "BURCU", "AHMET", "BÜLENT", "MÜCADİYE", "SONGÜL", "IŞIK", "MEHMET",
                "AYHAN", "SERDAR", "ERKAN" };
            string[] soyIsimler = new string[30] { "ÇOPUR", "EYİSOY", "ÜSTÜNDAĞ", "KILAVUZ", "YÜCEL", "ÖKTEM", "YAŞAN", "USLU", "BOZOĞLU", "GÜLTEKİN", "KOCASARAÇ",
                "DURAN", "ALĞAN", "ERDAL", "KAYKA", "BACAKSIZ", "ÜNALAN", "ZEYBEK", "KILIÇ", "TEMİZ", "KARAKAŞ", "OĞUZ", "AYIK", "ETLEÇ", "PEHLİVAN", "COŞAR", "KAHYA",
                "ÇETİN", "ATALAY", "YALÇIN" };

            FileStream belgeyeKaydet = new FileStream("degerler.txt", FileMode.OpenOrCreate, FileAccess.Write);
            StreamWriter kaydet = new StreamWriter(belgeyeKaydet);

            // oluşturulacak dosyadaki ilk satırda bulunması gereken ödev-sınav puanlarını yerleştiriyoruz.   
            kaydet.Write("                                    ");
            kaydet.Write(String.Format("{0,-12}", "Ödev1:10"));
            kaydet.Write(String.Format("{0,-12}", "Ödev2:10"));
            kaydet.Write(String.Format("{0,-12}", "Vize:30"));
            kaydet.WriteLine(String.Format("{0,-12}", "Final:50"));

            int geciciSayi;

            /* Bu döngüde:
             *  geciciSayi dizisine rastgele değer atayıp isim ve soyIsim dizisinin o indisteki elemanlarını kullanarak rastgele öğrenci adları oluşturup dosyaya yazıyoruz
             *  rastgele numara, ödev1, ödev2, vize ve final sayıları oluşturup değerler dosyasına uygun şekilde yazıyoruz. */
            for (int i = 0; i < 100; i++)
            {
                geciciSayi = random.Next(1, 30);
                kaydet.Write(String.Format("{0,-12}", isimler[geciciSayi])); //rastgele isim seçip dosyaya yazdırdık.

                geciciSayi = random.Next(1, 30);
                kaydet.Write(String.Format("{0, -12}", soyIsimler[geciciSayi])); //rastgele soy isim seçip dosyaya yazdırdık.

                geciciSayi = random.Next(1000, 10000);
                kaydet.Write(String.Format("{0, -12}", geciciSayi)); //rastgele numara oluşturup dosyaya yazdırdık.

                geciciSayi = random.Next(1, 101);
                odev1[i] = geciciSayi;
                kaydet.Write(String.Format("{0, -12}", geciciSayi));

                geciciSayi = random.Next(1, 101);
                odev2[i] = geciciSayi;
                kaydet.Write(String.Format("{0, -12}", geciciSayi));

                geciciSayi = random.Next(1, 101);
                vize[i] = geciciSayi;
                kaydet.Write(String.Format("{0, -12}", geciciSayi));

                geciciSayi = random.Next(1, 101);
                final[i] = geciciSayi;
                kaydet.WriteLine(String.Format("{0, -12}", geciciSayi));
            }
            kaydet.Close();
            belgeyeKaydet.Close();

            int sayi;
            Console.WriteLine("Ortalama hesaplamak istiyorsanız e'ye basınız: ");
            sayi = Console.Read();

            //kullanıcı e veya E 'ye basarsa hesaplamaları yapıp sonuclar.txt 'yi oluşturacak koşulu yazıyoruz.
            if (sayi == 69 || sayi == 101) //ascii tablosunda 69 e'yi temsil ediyor ; 101 E'yi temsil ediyor.
            {
                double AA = 0, BA = 0, BB = 0, CB = 0, CC = 0, DC = 0, DD = 0, FD = 0, FF = 0, genelNot;
                int gecenSayisi = 0, kalanSayisi;

                // bu döngüde; ödev ve sınavların ortalamaya etkisine göre öğrencilerin genel notunu hesaplayıp harf notunu veriyoruz
                for (int i = 0; i < 100; i++)
                {
                    odev1[i] = odev1[i] / 10;
                    odev2[i] = odev2[i] / 10;
                    vize[i] = (vize[i] / 10) * 3;
                    final[i] = (final[i] / 10) * 5;
                    genelNot = odev1[i] + odev2[i] + vize[i] + final[i];

                    // oluşturduğumuz harf notu değişkenlerini her uygun notta bir artırarak harf notlarını saklıyoruz.
                    if (genelNot < 40)
                    {
                        FF += 1;
                    }
                    else if (genelNot < 50 && genelNot >= 40)
                    {
                        FD += 1;
                    }
                    else if (genelNot < 58 && genelNot >= 50)
                    {
                        DD += 1;
                    }
                    else if (genelNot < 65 && genelNot >= 58)
                    {
                        DC += 1;
                    }
                    else if (genelNot < 75 && genelNot >= 65)
                    {
                        CC += 1;
                    }
                    else if (genelNot < 80 && genelNot >= 75)
                    {
                        CB += 1;
                    }
                    else if (genelNot < 85 && genelNot >= 80)
                    {
                        BB += 1;
                    }
                    else if (genelNot < 90 && genelNot >= 85)
                    {
                        BA += 1;
                    }
                    else if (genelNot >= 90)
                    {
                        AA += 1;
                    }


                    if (genelNot >= 50) //kaç kişininin dersten geçtiğini de gecenSayisi değişkenine kaydediyoruz.
                    {
                        gecenSayisi += 1;
                    }
                }
                kalanSayisi = 100 - gecenSayisi;

                FileStream sonucuKaydet = new FileStream("sonuclar.txt", FileMode.OpenOrCreate, FileAccess.Write);
                StreamWriter save = new StreamWriter(sonucuKaydet);

                save.WriteLine("AA       {0}", AA);
                save.WriteLine("BA       {0}", BA);
                save.WriteLine("BB       {0}", BB);
                save.WriteLine("CB       {0}", CB);
                save.WriteLine("CC       {0}", CC);
                save.WriteLine("DC       {0}", DC);
                save.WriteLine("DD       {0}", DD);
                save.WriteLine("FD       {0}", FD);
                save.WriteLine("FF       {0}", FF);
                save.WriteLine("Geçen öğrenci sayısı     {0}", gecenSayisi);
                save.WriteLine("Kalan öğrenci sayısı     {0}", kalanSayisi);
                save.Close();
                sonucuKaydet.Close();

                Console.WriteLine("Hesaplamalar yapılmıştır.");
            }

            else
                Console.WriteLine("Uygulamadan çıkılıyor.");
            Environment.Exit(0);
        }
    }
}
