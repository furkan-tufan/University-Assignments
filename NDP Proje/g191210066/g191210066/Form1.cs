/****************************************************************************
**			    SAKARYA ÜNİVERSİTESİ
**				BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**				BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				NESNEYE DAYALI PROGRAMLAMA DERSİ
**				2019-2020 BAHAR DÖNEMİ
**	
**				ÖDEV NUMARASI..........: PROJE
**				ÖĞRENCİ ADI............: FURKAN İSMET TUFAN
**				ÖĞRENCİ NUMARASI.......: g191210066
**              DERSİN ALINDIĞI GRUP...: 2A GRUBU
****************************************************************************/

using g191210066;
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
        Atik atik = new Atik();
        OrganikKutusu organikKutusu = new OrganikKutusu();
        KagitKutusu kagitKutusu = new KagitKutusu();
        CamKutusu camKutusu = new CamKutusu();
        MetalKutusu metalKutusu = new MetalKutusu();
        public Form1()
        {
            InitializeComponent();
        }
        private void Form1_Load(object sender, EventArgs e)
        {
            // "yeni oyun" butonuna tıklanana kadar boşaltma ve ekleme butonlarını disable durumda bırakıyoruz.
            organikButonu.Enabled = false;
            kagitButonu.Enabled = false;
            camButonu.Enabled = false;
            metalButonu.Enabled = false;
            organikBosaltimi.Enabled = false;
            kagitBosaltimi.Enabled = false;
            camBosaltimi.Enabled = false;
            metalBosaltimi.Enabled = false;
        }

        int sure = 60;
        private void timer1_Tick(object sender, EventArgs e)
        {
            // timer çalışıyorken süre değişkeni 0'a gelmediği sürece süre değerini bir azaltıyoruz ve label'a yazdırıyoruz.
            if (sure > 0)
            {
                sure -= 1;
                saniyeLabel.Text = Convert.ToString(sure);
            }
            // süre sıfıra gelince, yeni oyun butonuna tekrar tıklanıncaya kadar oyunu bitiriyoruz ve timer'ı durduruyoruz.
            else 
            {
                oyunButonu.Enabled = true;
                organikButonu.Enabled = false;
                kagitButonu.Enabled = false;
                camButonu.Enabled = false;
                metalButonu.Enabled = false;
                organikBosaltimi.Enabled = false;
                kagitBosaltimi.Enabled = false;
                camBosaltimi.Enabled = false;
                metalBosaltimi.Enabled = false;
                sure = 60;
                saniyeLabel.Text = Convert.ToString(sure);
                timer1.Stop();
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            timer1.Start(); //butona tıklandığı anda timer çalıştırılıyor.
            oyunButonu.Enabled = false; // timer durana kadar "yeni oyun" butonuna bir daha tıklanamıyor.

            //ekleme ve boşaltma butonları aktif hale getiriliyor.
            organikButonu.Enabled = true;
            kagitButonu.Enabled = true;
            camButonu.Enabled = true;
            metalButonu.Enabled = true;
            organikBosaltimi.Enabled = true;
            kagitBosaltimi.Enabled = true;
            camBosaltimi.Enabled = true;
            metalBosaltimi.Enabled = true;

            organikKutusu.DoluHacim = 0;
            kagitKutusu.DoluHacim = 0;
            camKutusu.DoluHacim = 0;
            metalKutusu.DoluHacim = 0;

            organikProgress.Value = 0;
            kagitProgress.Value = 0;
            camProgress.Value = 0;
            metalProgress.Value = 0;

            organikAtikListesi.Items.Clear();
            kagitListesi.Items.Clear();
            camListesi.Items.Clear();
            metalListesi.Items.Clear();

            atik.toplamPuan = 0;
            puanLabel.Text = "0";

            Random rastgele = new Random();
            int index;
            index = rastgele.Next(1, 9);

            // 1'den 8'e kadar rastgele bir sayı üretiliyor ve gelen sayıya göre pictureBox'a debug dosyasından alınan resim koyuluyor.
            // atık sınıfında, resmi getirilen atığın hangisi olduğunu kaydettiğimiz 8 adet boolean değişken var ve getirilen atığa göre uygun değişken "true" yapılıyor.
            switch (index)
            {
                case 1:
                    Bardak bardak = new Bardak();
                    pictureBox1.Image = bardak.Image;
                    atik.bardakMi = true;
                    break;
                case 2:
                    Dergi dergi = new Dergi();
                    pictureBox1.Image = dergi.Image;
                    atik.dergiMi = true;
                    break;
                case 3:
                    Gazete gazete = new Gazete();
                    pictureBox1.Image = gazete.Image;
                    atik.gazeteMi = true;
                    break;
                case 4:
                    Domates domates = new Domates();
                    pictureBox1.Image = domates.Image;
                    atik.domatesMi = true;
                    break;
                case 5:
                    Salatalik salatalik = new Salatalik();
                    pictureBox1.Image = salatalik.Image;
                    atik.salatalikMi = true;
                    break;
                case 6:
                    KolaKutusu kolaKutusu = new KolaKutusu();
                    pictureBox1.Image = kolaKutusu.Image;
                    atik.kolaKutusuMu = true;
                    break;
                case 7:
                    SalcaKutusu salcaKutusu = new SalcaKutusu();
                    pictureBox1.Image = salcaKutusu.Image;
                    atik.salcaKutusuMu = true;
                    break;
                case 8:
                    CamSise camSise = new CamSise();
                    pictureBox1.Image = camSise.Image;
                    atik.camSiseMi = true;
                    break;
            }
        }
        private void button2_Click(object sender, EventArgs e)
        {
            //"ÇIKIŞ" yazılı butona tıklandığında formu kapatması için bu iki kodu yazıyoruz.
            this.Close();
            Application.Exit();
        }

        private void organikButonu_Click(object sender, EventArgs e)
        {
            atik.eklendiMi = false;

            // organik atık kutusuna atılmaya uygun atıklardan birinin resminin olup olmadığını kontrol ediyoruz.
            if (atik.domatesMi == true)
            {
                // metod yardımıyla, resmi olan atığın atılacağı kutuda kendisi için yeterli yer var mı diye kontrol ediyoruz.
                if (organikKutusu.Ekle(atik) == true)
                {
                    //eğer yeterli alan varsa atığı listBox'a ekliyoruz, progressBar'ı ilerletiyoruz, puanı ve kutunun dolu hacmini artırıyoruz. 
                    organikAtikListesi.Items.Add("Domates(" + Convert.ToString(150) + ")");
                    atik.toplamPuan += 150;
                    puanLabel.Text = Convert.ToString(atik.toplamPuan);
                    organikKutusu.DoluHacim += 150;
                    organikProgress.Value += 150;
                    atik.domatesMi = false; //atıkla işimiz bittiği için kendisine ait boolean değişkeni tekrar false yapıyoruz
                    atik.eklendiMi = true; 
                }
                else
                {
                    atik.eklendiMi = false;
                }
            }
            // organik atık kutusuna atılmaya uygun atıklardan birinin resminin olup olmadığını kontrol ediyoruz.
            if (atik.salatalikMi == true)
            {
                // metod yardımıyla, resmi olan atığın atılacağı kutuda kendisi için yeterli yer var mı diye kontrol ediyoruz.
                if (organikKutusu.Ekle(atik) == true)
                {
                    //eğer yeterli alan varsa atığı listBox'a ekliyoruz, progressBar'ı ilerletiyoruz, puanı ve kutunun dolu hacmini artırıyoruz. 
                    organikAtikListesi.Items.Add("Salatalık(" + Convert.ToString(120) + ")");
                    atik.toplamPuan += 120;
                    puanLabel.Text = Convert.ToString(atik.toplamPuan); 
                    organikKutusu.DoluHacim += 120;
                    organikProgress.Value += 120;
                    atik.salatalikMi = false; //atıkla işimiz bittiği için kendisine ait boolean değişkeni tekrar false yapıyoruz
                    atik.eklendiMi = true;
                }
                else
                {
                    atik.eklendiMi = false;
                }
            }

            // atık, uygun kutuya eklendiyse yeni resim getiriyoruz.
            if (atik.eklendiMi==true)
            {
                Random rastgele = new Random();
                int index;
                index = rastgele.Next(1, 9);
                switch (index)
                {
                    case 1:
                        Bardak bardak = new Bardak();
                        pictureBox1.Image = bardak.Image;
                        atik.bardakMi = true;
                        break;
                    case 2:
                        Dergi dergi = new Dergi();
                        pictureBox1.Image = dergi.Image;
                        atik.dergiMi = true;
                        break;
                    case 3:
                        Gazete gazete = new Gazete();
                        pictureBox1.Image = gazete.Image;
                        atik.gazeteMi = true;
                        break;
                    case 4:
                        Domates domates = new Domates();
                        pictureBox1.Image = domates.Image;
                        atik.domatesMi = true;
                        break;
                    case 5:
                        Salatalik salatalik = new Salatalik();
                        pictureBox1.Image = salatalik.Image;
                        atik.salatalikMi = true;
                        break;
                    case 6:
                        KolaKutusu kolaKutusu = new KolaKutusu();
                        pictureBox1.Image = kolaKutusu.Image;
                        atik.kolaKutusuMu = true;
                        break;
                    case 7:
                        SalcaKutusu salcaKutusu = new SalcaKutusu();
                        pictureBox1.Image = salcaKutusu.Image;
                        atik.salcaKutusuMu = true;
                        break;
                    case 8:
                        CamSise camSise = new CamSise();
                        pictureBox1.Image = camSise.Image;
                        atik.camSiseMi = true;
                        break;
                }
            }
        }

        private void kagitButonu_Click(object sender, EventArgs e)
        {
            atik.eklendiMi = false;

            // kağıt kutusuna atılmaya uygun atıklardan birinin resminin olup olmadığını kontrol ediyoruz.
            if (atik.dergiMi == true)
            {
                // metod yardımıyla, resmi olan atığın atılacağı kutuda kendisi için yeterli yer var mı diye kontrol ediyoruz.
                if (kagitKutusu.Ekle(atik) == true)
                {
                    //eğer yeterli alan varsa atığı listBox'a ekliyoruz, progressBar'ı ilerletiyoruz, puanı ve kutunun dolu hacmini artırıyoruz.
                    kagitListesi.Items.Add("Dergi(" + Convert.ToString(200) + ")");
                    atik.toplamPuan += 200;
                    puanLabel.Text = Convert.ToString(atik.toplamPuan);
                    kagitKutusu.DoluHacim += 200;
                    kagitProgress.Value += 200;
                    atik.dergiMi = false; //atıkla işimiz bittiği için kendisine ait boolean değişkeni tekrar false yapıyoruz
                    atik.eklendiMi = true;

                }
                else
                {
                    atik.eklendiMi = false;
                }
            }
            // kağıt kutusuna atılmaya uygun atıklardan birinin resminin olup olmadığını kontrol ediyoruz.
            if (atik.gazeteMi == true)
            {
                // metod yardımıyla, resmi olan atığın atılacağı kutuda kendisi için yeterli yer var mı diye kontrol ediyoruz.
                if (kagitKutusu.Ekle(atik) == true)
                {
                    //eğer yeterli alan varsa atığı listBox'a ekliyoruz, progressBar'ı ilerletiyoruz, puanı ve kutunun dolu hacmini artırıyoruz.
                    kagitListesi.Items.Add("Gazete(" + Convert.ToString(250) + ")");
                    atik.toplamPuan += 250;
                    puanLabel.Text = Convert.ToString(atik.toplamPuan);
                    kagitKutusu.DoluHacim += 250;
                    kagitProgress.Value += 250;
                    atik.gazeteMi = false;  //atıkla işimiz bittiği için kendisine ait boolean değişkeni tekrar false yapıyoruz
                    atik.eklendiMi = true;
                }
                else
                {
                    atik.eklendiMi = false;
                }
            }

            // atık, uygun kutuya eklendiyse yeni resim getiriyoruz.
            if (atik.eklendiMi == true)
            {
                Random rastgele = new Random();
                int index;
                index = rastgele.Next(1, 9);
                switch (index)
                {
                    case 1:
                        Bardak bardak = new Bardak();
                        pictureBox1.Image = bardak.Image;
                        atik.bardakMi = true;
                        break;
                    case 2:
                        Dergi dergi = new Dergi();
                        pictureBox1.Image = dergi.Image;
                        atik.dergiMi = true;
                        break;
                    case 3:
                        Gazete gazete = new Gazete();
                        pictureBox1.Image = gazete.Image;
                        atik.gazeteMi = true;
                        break;
                    case 4:
                        Domates domates = new Domates();
                        pictureBox1.Image = domates.Image;
                        atik.domatesMi = true;
                        break;
                    case 5:
                        Salatalik salatalik = new Salatalik();
                        pictureBox1.Image = salatalik.Image;
                        atik.salatalikMi = true;
                        break;
                    case 6:
                        KolaKutusu kolaKutusu = new KolaKutusu();
                        pictureBox1.Image = kolaKutusu.Image;
                        atik.kolaKutusuMu = true;
                        break;
                    case 7:
                        SalcaKutusu salcaKutusu = new SalcaKutusu();
                        pictureBox1.Image = salcaKutusu.Image;
                        atik.salcaKutusuMu = true;
                        break;
                    case 8:
                        CamSise camSise = new CamSise();
                        pictureBox1.Image = camSise.Image;
                        atik.camSiseMi = true;
                        break;
                }
            }

        }

        private void camButonu_Click(object sender, EventArgs e)
        {
            atik.eklendiMi = false;

            // cam atık kutusuna atılmaya uygun atıklardan birinin resminin olup olmadığını kontrol ediyoruz.
            if (atik.camSiseMi == true)
            {
                // metod yardımıyla, resmi olan atığın atılacağı kutuda kendisi için yeterli yer var mı diye kontrol ediyoruz.
                if (camKutusu.Ekle(atik) == true)
                {
                    //eğer yeterli alan varsa atığı listBox'a ekliyoruz, progressBar'ı ilerletiyoruz, puanı ve kutunun dolu hacmini artırıyoruz.
                    camListesi.Items.Add("Cam Şişe(" + Convert.ToString(600) + ")");
                    atik.toplamPuan += 600;
                    puanLabel.Text = Convert.ToString(atik.toplamPuan);
                    camKutusu.DoluHacim += 600;
                    camProgress.Value += 600;
                    atik.camSiseMi = false; //atıkla işimiz bittiği için kendisine ait boolean değişkeni tekrar false yapıyoruz
                    atik.eklendiMi = true;
                }
                else
                {
                    atik.eklendiMi = false;
                }
            }
            // cam atık kutusuna atılmaya uygun atıklardan birinin resminin olup olmadığını kontrol ediyoruz.
            if (atik.bardakMi == true)
            {
                // metod yardımıyla, resmi olan atığın atılacağı kutuda kendisi için yeterli yer var mı diye kontrol ediyoruz.
                if (camKutusu.Ekle(atik) == true)
                {
                    //eğer yeterli alan varsa atığı listBox'a ekliyoruz, progressBar'ı ilerletiyoruz, puanı ve kutunun dolu hacmini artırıyoruz.
                    camListesi.Items.Add("Bardak(" + Convert.ToString(250) + ")");
                    atik.toplamPuan += 250;
                    puanLabel.Text = Convert.ToString(atik.toplamPuan);
                    camKutusu.DoluHacim += 250;
                    camProgress.Value += 250;
                    atik.bardakMi = false; //atıkla işimiz bittiği için kendisine ait boolean değişkeni tekrar false yapıyoruz
                    atik.eklendiMi = true;
                }
                else
                {
                    atik.eklendiMi = false;
                }
            }

            // atık, uygun kutuya eklendiyse yeni resim getiriyoruz.
            if (atik.eklendiMi == true)
            {
                Random rastgele = new Random();
                int index;
                index = rastgele.Next(1, 9);
                switch (index)
                {
                    case 1:
                        Bardak bardak = new Bardak();
                        pictureBox1.Image = bardak.Image;
                        atik.bardakMi = true;
                        break;
                    case 2:
                        Dergi dergi = new Dergi();
                        pictureBox1.Image = dergi.Image;
                        atik.dergiMi = true;
                        break;
                    case 3:
                        Gazete gazete = new Gazete();
                        pictureBox1.Image = gazete.Image;
                        atik.gazeteMi = true;
                        break;
                    case 4:
                        Domates domates = new Domates();
                        pictureBox1.Image = domates.Image;
                        atik.domatesMi = true;
                        break;
                    case 5:
                        Salatalik salatalik = new Salatalik();
                        pictureBox1.Image = salatalik.Image;
                        atik.salatalikMi = true;
                        break;
                    case 6:
                        KolaKutusu kolaKutusu = new KolaKutusu();
                        pictureBox1.Image = kolaKutusu.Image;
                        atik.kolaKutusuMu = true;
                        break;
                    case 7:
                        SalcaKutusu salcaKutusu = new SalcaKutusu();
                        pictureBox1.Image = salcaKutusu.Image;
                        atik.salcaKutusuMu = true;
                        break;
                    case 8:
                        CamSise camSise = new CamSise();
                        pictureBox1.Image = camSise.Image;
                        atik.camSiseMi = true;
                        break;
                }
            }
        }

        private void metalButonu_Click(object sender, EventArgs e)
        {
            atik.eklendiMi = false;

            // metal atık kutusuna atılmaya uygun atıklardan birinin resminin olup olmadığını kontrol ediyoruz.
            if (atik.salcaKutusuMu == true)
            {
                // metod yardımıyla, resmi olan atığın atılacağı kutuda kendisi için yeterli yer var mı diye kontrol ediyoruz.
                if (metalKutusu.Ekle(atik) == true)
                {
                    //eğer yeterli alan varsa atığı listBox'a ekliyoruz, progressBar'ı ilerletiyoruz, puanı ve kutunun dolu hacmini artırıyoruz.
                    metalListesi.Items.Add("Salça Kutusu(" + Convert.ToString(550) + ")");
                    atik.toplamPuan += 550;
                    puanLabel.Text = Convert.ToString(atik.toplamPuan);
                    metalKutusu.DoluHacim += 550;
                    metalProgress.Value += 550;
                    atik.salcaKutusuMu = false; //atıkla işimiz bittiği için kendisine ait boolean değişkeni tekrar false yapıyoruz
                    atik.eklendiMi = true;
                }
                else
                {
                    atik.eklendiMi = false;
                }
            }
            // metal atık kutusuna atılmaya uygun atıklardan birinin resminin olup olmadığını kontrol ediyoruz.
            if (atik.kolaKutusuMu == true)
            {
                // metod yardımıyla, resmi olan atığın atılacağı kutuda kendisi için yeterli yer var mı diye kontrol ediyoruz.
                if (metalKutusu.Ekle(atik) == true)
                {
                    //eğer yeterli alan varsa atığı listBox'a ekliyoruz, progressBar'ı ilerletiyoruz, puanı ve kutunun dolu hacmini artırıyoruz.
                    metalListesi.Items.Add("Kola Kutusu(" + Convert.ToString(350) + ")");
                    atik.toplamPuan += 350;
                    puanLabel.Text = Convert.ToString(atik.toplamPuan);
                    metalKutusu.DoluHacim += 350;
                    metalProgress.Value += 350;
                    atik.kolaKutusuMu = false; //atıkla işimiz bittiği için kendisine ait boolean değişkeni tekrar false yapıyoruz
                    atik.eklendiMi = true;
                }
                else
                {
                    atik.eklendiMi = false;
                }
            }

            // atık, uygun kutuya eklendiyse yeni resim getiriyoruz.
            if (atik.eklendiMi == true)
            {
                Random rastgele = new Random();
                int index;
                index = rastgele.Next(1, 9);
                switch (index)
                {
                    case 1:
                        Bardak bardak = new Bardak();
                        pictureBox1.Image = bardak.Image;
                        atik.bardakMi = true;
                        break;
                    case 2:
                        Dergi dergi = new Dergi();
                        pictureBox1.Image = dergi.Image;
                        atik.dergiMi = true;
                        break;
                    case 3:
                        Gazete gazete = new Gazete();
                        pictureBox1.Image = gazete.Image;
                        atik.gazeteMi = true;
                        break;
                    case 4:
                        Domates domates = new Domates();
                        pictureBox1.Image = domates.Image;
                        atik.domatesMi = true;
                        break;
                    case 5:
                        Salatalik salatalik = new Salatalik();
                        pictureBox1.Image = salatalik.Image;
                        atik.salatalikMi = true;
                        break;
                    case 6:
                        KolaKutusu kolaKutusu = new KolaKutusu();
                        pictureBox1.Image = kolaKutusu.Image;
                        atik.kolaKutusuMu = true;
                        break;
                    case 7:
                        SalcaKutusu salcaKutusu = new SalcaKutusu();
                        pictureBox1.Image = salcaKutusu.Image;
                        atik.salcaKutusuMu = true;
                        break;
                    case 8:
                        CamSise camSise = new CamSise();
                        pictureBox1.Image = camSise.Image;
                        atik.camSiseMi = true;
                        break;
                }
            }
        }

        private void organikBosaltimi_Click(object sender, EventArgs e)
        {
            // oluşturduğumuz bir metod ile atık kutusunun hacminin %75 dolu olup olmadığını kontrol ediyoruz. metodumuz true dönerse kutuyu boşaltıyoruz, süre ve puan ekliyoruz.
            if (organikKutusu.Bosalt()==true)
            {
                sure += 3;
                atik.toplamPuan += organikKutusu.BosaltmaPuani;
                puanLabel.Text = Convert.ToString(atik.toplamPuan);
                organikAtikListesi.Items.Clear();
                organikKutusu.DoluHacim = 0;
                organikProgress.Value = 0;
            }
        }

        private void kagitBosaltimi_Click(object sender, EventArgs e)
        {
            // oluşturduğumuz bir metod ile atık kutusunun hacminin %75 dolu olup olmadığını kontrol ediyoruz. metodumuz true dönerse kutuyu boşaltıyoruz, süre ve puan ekliyoruz.
            if (kagitKutusu.Bosalt()==true)
            {
                sure += 3;
                atik.toplamPuan += kagitKutusu.BosaltmaPuani;
                puanLabel.Text = Convert.ToString(atik.toplamPuan);
                kagitListesi.Items.Clear();
                kagitKutusu.DoluHacim = 0;
                kagitProgress.Value = 0;
            }
        }

        private void camBosaltimi_Click(object sender, EventArgs e)
        {
            // oluşturduğumuz bir metod ile atık kutusunun hacminin %75 dolu olup olmadığını kontrol ediyoruz. metodumuz true dönerse kutuyu boşaltıyoruz, süre ve puan ekliyoruz.
            if (camKutusu.Bosalt()==true)
            {
                sure += 3;
                atik.toplamPuan += camKutusu.BosaltmaPuani;
                puanLabel.Text = Convert.ToString(atik.toplamPuan);
                camListesi.Items.Clear();
                camKutusu.DoluHacim = 0;
                camProgress.Value = 0;
            }
        }

        private void metalBosaltimi_Click(object sender, EventArgs e)
        {
            // oluşturduğumuz bir metod ile atık kutusunun hacminin %75 dolu olup olmadığını kontrol ediyoruz. metodumuz true dönerse kutuyu boşaltıyoruz, süre ve puan ekliyoruz.

            if (metalKutusu.Bosalt()==true)
            {
                sure += 3;
                atik.toplamPuan += metalKutusu.BosaltmaPuani;
                puanLabel.Text = Convert.ToString(atik.toplamPuan);
                metalListesi.Items.Clear();
                metalKutusu.DoluHacim = 0;
                metalProgress.Value = 0;
            }
        }
    }

    public interface IAtik
    {
        int Hacim { get; }
        System.Drawing.Image Image { get; }
    }
    public interface IAtikKutusu : IDolabilen
    {
        int BosaltmaPuani { get; }

        bool Ekle(Atik atik);
         
        bool Bosalt();
    }
    public interface IDolabilen
    {
        int Kapasite { get; set; }
        int DoluHacim { get; set; }
        int DolulukOrani { get; }
    }

    public class Atik
    {
        // bu class 'da, her atık için bir özellik oluşturup gelen atığın türünü boolean özellikler yardımıyla kaydediyoruz.
        public Atik()
        {
            kolaKutusuMu = false;
            gazeteMi = false;
            salcaKutusuMu = false;
            dergiMi = false;
            bardakMi = false;
            domatesMi = false;
            salatalikMi = false;
            camSiseMi = false;
            eklendiMi = false;
            toplamPuan = 0;
        }
        public bool kolaKutusuMu { get; set; }
        public bool gazeteMi { get; set; }
        public bool salcaKutusuMu { get; set; }
        public bool dergiMi { get; set; }
        public bool bardakMi { get; set; }
        public bool domatesMi { get; set; }
        public bool salatalikMi { get; set; }
        public bool camSiseMi { get; set; }
        public bool eklendiMi { get; set; }
        public int toplamPuan { get; set; }
    }

    // her atık kutusu için ayrı sınıf oluşturuyoruz ve "get,set" metodlarıyla boşaltma puanlarını, kapasitelerini özelleştiriyoruz.
    class OrganikKutusu : IAtikKutusu
    {
        public int BosaltmaPuani
        {
            get
            {
                return 0;
            }
        }
        public int Kapasite
        {
            get
            {
                return 700;
            }
            set { }
        }
        public int DoluHacim { get; set; }
        public int DolulukOrani
        {
            get
            {
                return (DoluHacim * 100) / Kapasite;
            }
        }

        //bu metodla atık kutusunun boşaltmaya uygun olup olmadığı kontrol ediliyor.
        public bool Bosalt()
        {
            if (DolulukOrani > 75)
            {
                return true;
            }
            else
                return false;
        }

        // bu metodla atığın organik atık kutusuna eklenmek için uygun olup olmadığı kontrol ediliyor
        public bool Ekle(Atik atik)
        {
            if (atik.salatalikMi && (DoluHacim + 120) <= Kapasite)
            {
                return true;
            }
            else if (atik.domatesMi && (DoluHacim + 150) <= Kapasite)
            {
                return true;
            }
            else
                return false;
        }
    }
    class KagitKutusu : IAtikKutusu
    {
        public int BosaltmaPuani
        {
            get
            {
                return 1000;
            }
        }
        public int Kapasite
        {
            get
            {
                return 1200;
            }
            set { }
        }
        public int DoluHacim { get; set; }
        public int DolulukOrani
        {
            get
            {
                return (DoluHacim * 100) / Kapasite;
            }
        }

        //bu metodla atık kutusunun boşaltmaya uygun olup olmadığı kontrol ediliyor.
        public bool Bosalt()
        {
            if (DolulukOrani > 75)
            {
                return true;
            }
            else
                return false;
        }

        // bu metodla atığın kağıt kutusuna eklenmek için uygun olup olmadığı kontrol ediliyor
        public bool Ekle(Atik atik)
        {
            if (atik.dergiMi && (DoluHacim + 200) <= Kapasite)
            {
                return true;
            }
            else if (atik.gazeteMi && (DoluHacim + 250) <= Kapasite)
            {
                return true;
            }
            else
                return false;
        }
    }
    class CamKutusu : IAtikKutusu
    {
        public int BosaltmaPuani
        {
            get
            {
                return 600;
            }
        }
        public int Kapasite
        {
            get
            {
                return 2200;
            }
            set { }
        }
        public int DoluHacim { get; set; }

        public int DolulukOrani
        {
            get
            {
                return (DoluHacim * 100) / Kapasite;
            }
        }

        //bu metodla atık kutusunun boşaltmaya uygun olup olmadığı kontrol ediliyor.
        public bool Bosalt()
        {
            if (DolulukOrani > 75)
            {
                return true;
            }
            else
                return false;
        }

        // bu metodla atığın cam kutusuna eklenmek için uygun olup olmadığı kontrol ediliyor
        public bool Ekle(Atik atik)
        {
            if (atik.camSiseMi && (DoluHacim + 600) <= Kapasite)
            {
                return true;
            }
            else if (atik.bardakMi && (DoluHacim + 250) <= Kapasite)
            {
                return true;
            }

            else
                return false;

        }
    }
    class MetalKutusu : IAtikKutusu
    {
        public int BosaltmaPuani
        {
            get
            {
                return 800;
            }
        }

        public int Kapasite
        {
            get
            {
                return 2300;
            }
            set { }
        }
    
        public int DoluHacim { get; set; }

        public int DolulukOrani
        {
            get
            {
                return (DoluHacim * 100) / Kapasite;
            }
        }

        //bu metodla atık kutusunun boşaltmaya uygun olup olmadığı kontrol ediliyor.
        public bool Bosalt()
        {
            if (DolulukOrani > 75)
            {
                return true;
            }
            else
                return false;
        }

        // bu metodla atığın metal kutusuna eklenmek için uygun olup olmadığı kontrol ediliyor
        public bool Ekle(Atik atik)
        {
            if (atik.kolaKutusuMu && (DoluHacim + 350) <= Kapasite)
            {
                return true;
            }
            else if (atik.salcaKutusuMu && (DoluHacim + 550) <= Kapasite)
            {
                return true;
            }
            else
                return false;
        }
    }

    //her atık için ayrı class oluşturuyoruz ve hacim ile resimlerini getter metoduyla özelleştiriyoruz.
    class CamSise : IAtik
    {
        public int Hacim
        {
            get
            {
                return 600;
            }
        }
        public Image Image
        {
            get
            {
                return Image.FromFile("sise.jpg");
            }
        }
    }
    class Domates : IAtik
    {
        public int Hacim
        {
            get
            {
                return 150;
            }
        }
        public Image Image
        {
            get
            {
                return Image.FromFile("domates.jpg");
            }
        }
    }
    class Dergi : IAtik
    {
        public int Hacim
        {
            get
            {
                return 200;
            }
        }
        public Image Image
        {
            get
            {
                return Image.FromFile("dergi.png");
            }
        }
    }
    class Gazete : IAtik
    {
        public int Hacim
        {
            get
            {
                return 250;
            }
        }
        public Image Image
        {
            get
            {
                return Image.FromFile("gazete.jpg");
            }
        }
    }
    class Bardak : IAtik
    {
        public int Hacim
        {
            get
            {
                return 250;
            }
        }
        public Image Image
        {
            get
            {
                return Image.FromFile("bardak.jpg");
            }
        }
    }
    class Salatalik : IAtik
    {
        public int Hacim
        {
            get
            {
                return 120;
            }
        }
        public Image Image
        {
            get
            {
                return Image.FromFile("salatalik.jpg");
            }
        }
    }
    class KolaKutusu : IAtik
    {
        public int Hacim
        {
            get
            {
                return 350;
            }
        }
        public Image Image
        {
            get
            {
                return Image.FromFile("kola.jpg");
            }
        }
    }
    class SalcaKutusu : IAtik
    {
        public int Hacim
        {
            get
            {
                return 550;
            }
        }
        public Image Image
        {
            get
            {
                return Image.FromFile("konserve.jpg");
            }
        }
    }
}