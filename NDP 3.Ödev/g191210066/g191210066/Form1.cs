/****************************************************************************
**			    SAKARYA ÜNİVERSİTESİ
**				BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**				BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				NESNEYE DAYALI PROGRAMLAMA DERSİ
**				2019-2020 BAHAR DÖNEMİ
**	
**				ÖDEV NUMARASI..........: ÖDEV 3
**				ÖĞRENCİ ADI............: FURKAN İSMET TUFAN
**				ÖĞRENCİ NUMARASI.......: g191210066
**              DERSİN ALINDIĞI GRUP...: A GRUBU
****************************************************************************/

using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace g191210066
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        
        // kurucu fonksiyon aracılığıyla sınıf özelliklerine değer vermek için ve rastgele şekilde stok adetlerini belirlemek için her sınıftan birer nesne oluşturuyoruz.
        Buzdolabi buzdolabi = new Buzdolabi("Vestel NF520", "Vestel", "NF520", "NoFrost", 3500, 0, 520, "A++");
        LedTv ledTv = new LedTv("Samsung 49N5300", "Samsung", "49N5300", "Smart TV", 4000, 0, 49, "1920x1080");
        CepTel cepTel = new CepTel("Huawei P30", "Huawei", "P30", "Android", 2500, 0, 128, 6, 3650);
        Laptop laptop = new Laptop("Asus FX503VD-DM077", "Asus", "FX503VD-DM077", "Freedos, i5 7300HQ, GTX1050", 6000, 0, 15.6, "1920x1080", 256, 8, "4 Hücreli");
        int ilkStokBuz, ilkStokTv, ilkStokLaptop, ilkStokCep;
        private void Form1_Load(object sender, EventArgs e)
        {
            // form ilk kez çalıştırıldığında, ürünlerin stok adetlerinin label'lara yazdırılmasını sağlıyoruz
            label28.Text = Convert.ToString(ledTv.StokAdedi);
            label29.Text = Convert.ToString(buzdolabi.StokAdedi);
            label30.Text = Convert.ToString(laptop.StokAdedi);
            label31.Text = Convert.ToString(cepTel.StokAdedi);

            //başlangıçtaki stok adetlerini kaydediyoruz.
            ilkStokBuz = buzdolabi.StokAdedi;
            ilkStokTv =  ledTv.StokAdedi;
            ilkStokLaptop = laptop.StokAdedi;
            ilkStokCep = cepTel.StokAdedi;
        }
        private void button1_Click(object sender, EventArgs e)
        {
            // "sepete ekle" butonuna her tıklandığında stok adetlerinin ilk baştaki haline göre hesaplanmasını sağlıyoruz.
            ledTv.StokAdedi = ilkStokTv;
            buzdolabi.StokAdedi = ilkStokBuz;
            laptop.StokAdedi = ilkStokLaptop;
            cepTel.StokAdedi = ilkStokCep;

            // formun sağ tarafındaki listBox'ları her seferinde temizliyoruz.
            listBox1.Items.Clear();
            listBox2.Items.Clear();
            listBox3.Items.Clear();

            ledTv.SecilenAdet = Convert.ToInt32(numericUpDown1.Value);
            buzdolabi.SecilenAdet = Convert.ToInt32(numericUpDown2.Value);
            laptop.SecilenAdet = Convert.ToInt32(numericUpDown3.Value);
            cepTel.SecilenAdet = Convert.ToInt32(numericUpDown4.Value);

            Sepet sepet = new Sepet();
            
            // sadece ürünün seçilme durumunda, listBox'a yazdırmak için koşul yazıyoruz.
            if (ledTv.SecilenAdet != 0)
            {
                listBox1.Items.Add(Convert.ToString(ledTv.SecilenAdet)); //üründen kaç adet seçildiğini yazdırıyoruz.
                listBox2.Items.Add("Led Tv"); //ürünün ismini yazdırıyoruz.
                listBox3.Items.Add(Convert.ToString(sepet.SepeteUrunEkle(ledTv))); //kdv dahil fiyatını yazdırıyoruz.
            }

            if (buzdolabi.SecilenAdet != 0)
            {
                listBox1.Items.Add(Convert.ToString(buzdolabi.SecilenAdet));
                listBox2.Items.Add("Buzdolabı");
                listBox3.Items.Add(Convert.ToString(sepet.SepeteUrunEkle(buzdolabi)));
            }

            if (laptop.SecilenAdet != 0)
            {
                listBox1.Items.Add(Convert.ToString(laptop.SecilenAdet));
                listBox2.Items.Add("Laptop");
                listBox3.Items.Add(Convert.ToString(sepet.SepeteUrunEkle(laptop)));

            }
            if (cepTel.SecilenAdet != 0)
            {
                listBox1.Items.Add(Convert.ToString(cepTel.SecilenAdet));
                listBox2.Items.Add("Cep Telefonu");
                listBox3.Items.Add(Convert.ToString(sepet.SepeteUrunEkle(cepTel)));

            }

            //toplam kdv'li fiyatı yazdırmak için sepet sınıfına ait bir fonksiyonu kullanıyoruz.
            //bu fonksiyona parametre olarak, ürünlerin kdvli fiyatlarını hesaplayan fonksiyonları veriyoruz.
            label27.Text = Convert.ToString(sepet.ToplamKdvliFiyatBul(sepet.SepeteUrunEkle(ledTv), sepet.SepeteUrunEkle(buzdolabi), sepet.SepeteUrunEkle(laptop), sepet.SepeteUrunEkle(cepTel))) + "₺";  

            //seçilen ürünlerin stok adetlerini güncelliyoruz.
            ledTv.StokAdedi -= ledTv.SecilenAdet;
            buzdolabi.StokAdedi -= buzdolabi.SecilenAdet;
            laptop.StokAdedi -= laptop.SecilenAdet;
            cepTel.StokAdedi -= cepTel.SecilenAdet;

            //güncellenmiş stok adetlerini label'lara yeniden yazdırıyoruz.
            label28.Text = Convert.ToString(ledTv.StokAdedi);
            label29.Text = Convert.ToString(buzdolabi.StokAdedi);
            label30.Text = Convert.ToString(laptop.StokAdedi);
            label31.Text = Convert.ToString(cepTel.StokAdedi);
        }
        private void button2_Click(object sender, EventArgs e)
        {
            // sepete temizle butonuna tıklandığında tüm listBox ve textBox'ları temizlemesi için aşağıdaki komutları kullanıyoruz.
            this.Controls.Clear();
            this.InitializeComponent();

            //stok adetlerini baştaki haline çeviriyoruz ve label'ları güncelliyoruz.
            ledTv.StokAdedi = ilkStokTv;
            buzdolabi.StokAdedi = ilkStokBuz;
            laptop.StokAdedi = ilkStokLaptop;
            cepTel.StokAdedi = ilkStokCep;
            label28.Text = Convert.ToString(ledTv.StokAdedi);
            label29.Text = Convert.ToString(buzdolabi.StokAdedi);
            label30.Text = Convert.ToString(laptop.StokAdedi);
            label31.Text = Convert.ToString(cepTel.StokAdedi);

        }
    }
    class Urun
    {
        public string Ad { get; set; }
        public string Marka { get; set; }
        public string Model { get; set; }
        public string Ozellik { get; set; }
        public int StokAdedi { get; set; }
        public int HamFiyat { get; set; }
        public int SecilenAdet { get; set; }
        public int faizOrani { get; set; }

        public int KdvUygula(int faizOrani)
        {
            return (HamFiyat * SecilenAdet) + ((HamFiyat * SecilenAdet) / 100) * faizOrani;
        }


        public int[] sayilar = new int[4];
        // rastgele sayı üretmek istediğimde hep aynı random sayılar oluşturuluyordu. bu sorunu düzeltmek için aşağıdaki fonksiyonu oluşturup kullandım.
        // bu fonksiyon, birbirinden farklı 4 adet random sayı oluşturup bir diziye kaydediyor.
        public void randomSayiDizisiOlustur()
        {
            Random random = new Random();
            int index = 0;
            while ( index < 4)
            {
                int sayi = random.Next(0, 100);

                // bu if bloğu, eğer sayı dizisinde yeni oluşturulan random sayıdan varsa random sayıyı kaydetmeden koşul bloğunun başına dönmeyi sağlıyor.
                if (sayilar.Contains(sayi)) 
                    continue;

                sayilar[index] = sayi;
                index++;
            }
        }
    }
    class Buzdolabi : Urun
    {
        public int IcHacim { get; set; }
        public string EnerjiSinifi { get; set; }
        public Buzdolabi(string ad, string marka, string model, string ozellik, int hamFiyat, int secilenAdet, int icHacim, string enerjiSinifi)
        {
            randomSayiDizisiOlustur(); //birbirinden farklı random sayılar oluşturup bir diziye kaydeden fonksiyonumuzu çağırıyoruz.
            StokAdedi = sayilar[0]; // ve içinden bir tanesini stok adedi olarak kaydediyoruz.
            Ad = ad;
            Marka = marka;
            Model = model;
            Ozellik = ozellik;
            HamFiyat = hamFiyat;
            SecilenAdet = secilenAdet;
            IcHacim = icHacim;
            EnerjiSinifi = enerjiSinifi;
            faizOrani = 5;
        }

    }
    class LedTv : Urun
    {
        public double EkranBoyutu { get; set; }
        public string EkranCozunurlugu { get; set; }
        public LedTv(string ad, string marka, string model, string ozellik, int hamFiyat, int secilenAdet, double ekranBoyutu, string ekranCozunurlugu)
        {
            randomSayiDizisiOlustur();
            StokAdedi = sayilar[1];
            Ad = ad;
            Marka = marka;
            Model = model;
            Ozellik = ozellik;
            HamFiyat = hamFiyat;
            SecilenAdet = secilenAdet;
            EkranBoyutu = ekranBoyutu;
            EkranCozunurlugu = ekranCozunurlugu;
            faizOrani = 18;
        }


    }
    class CepTel : Urun
    {
        public int DahiliHafiza { get; set; }
        public int RamKapasitesi { get; set; }
        public int PilGucu { get; set; }
        public CepTel(string ad, string marka, string model, string ozellik, int hamFiyat, int secilenAdet, int dahiliHafiza, int ramKapasitesi, int pilGucu)
        {
            randomSayiDizisiOlustur();
            StokAdedi = sayilar[2]; 
            Ad = ad;
            Marka = marka;
            Model = model;
            Ozellik = ozellik;
            HamFiyat = hamFiyat;
            SecilenAdet = secilenAdet;
            DahiliHafiza = dahiliHafiza;
            RamKapasitesi = ramKapasitesi;
            PilGucu = pilGucu;
            faizOrani = 20;
        }

    }
    class Laptop : Urun
    {
        public double EkranBoyutu { get; set; }
        public string EkranCozunurlugu { get; set; }
        public int DahiliHafiza { get; set; }
        public int RamKapasitesi { get; set; }
        public string PilGucu { get; set; }
        public Laptop(string ad, string marka, string model, string ozellik, int hamFiyat, int secilenAdet, double ekranBoyutu, string ekranCozunurlugu, int dahiliHafiza, int ramKapasitesi, string pilGucu)
        {
            randomSayiDizisiOlustur();
            StokAdedi = sayilar[3];
            Ad = ad;
            Marka = marka;
            Model = model;
            Ozellik = ozellik;
            HamFiyat = hamFiyat;
            SecilenAdet = secilenAdet;
            EkranBoyutu = ekranBoyutu;
            EkranCozunurlugu = ekranCozunurlugu;
            DahiliHafiza = dahiliHafiza;
            RamKapasitesi = ramKapasitesi;
            PilGucu = pilGucu;
            faizOrani = 15;
        }

    }

    class Sepet
    {
        public int ToplamKdvliFiyatBul(int ledKdvli, int buzdolabiKdvli, int laptopKdvli, int  cepKdvli)
        {
            return ledKdvli + buzdolabiKdvli + laptopKdvli + cepKdvli;

        }
        public int SepeteUrunEkle(Urun u)
        {
            return u.KdvUygula(u.faizOrani);
        }

    }
}
