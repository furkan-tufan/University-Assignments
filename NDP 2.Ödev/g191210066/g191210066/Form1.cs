/****************************************************************************
**			    SAKARYA ÜNİVERSİTESİ
**				BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**				BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				NESNEYE DAYALI PROGRAMLAMA DERSİ
**				2019-2020 BAHAR DÖNEMİ
**	
**				ÖDEV NUMARASI..........: ÖDEV 2
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
        private void button1_Click(object sender, EventArgs e)
        {
            string tempString; //ara ara geçici olarak kullanacağımız değişken
            int x, y; // textbox'lara yazılan sayıları kaydedeceğimiz değişkenler
            int xCarpanlarToplami = 0, yCarpanlarToplami = 0; // x ve y sayılarının çarpanlarını ekleyeceğimiz değişkenler
            x = Convert.ToInt32(textBox1.Text);
            y = Convert.ToInt32(textBox2.Text);

            // girilen tam sayıların pozitif olmaması durumunda uyarı mesajı çıkaran koşulu yazıyoruz.
            if (x < 1 || y < 1 )
            {
                MessageBox.Show("Lütfen pozitif tam sayılar girerek yeniden deneyiniz.");
            }
            else
            {
                // "ARKADAŞMI" butonuna her tıklandığında listBox ve textBox'ların içini temizlemesi için bu iki kodu giriyoruz.
                this.Controls.Clear();
                this.InitializeComponent();

                // kullanıcının girdiği sayıları tekrardan textBox'lara yazdırıyoruz.
                textBox1.Text = Convert.ToString(x);
                textBox2.Text = Convert.ToString(y);

                //sayıların çarpanlarını yazdıracağımız listBoxları oluşturup forma ekliyoruz.
                var list1 = new ListBox();
                list1.Location = new Point(340, 110);
                list1.Size = new Size(140, 300);
                Controls.Add(list1);
                var list2 = new ListBox();
                list2.Location = new Point(490, 110);
                list2.Size = new Size(140, 300);
                Controls.Add(list2);

                // girilen x sayısının kendisinden küçük çarpanlarını bulup bir değişkende topluyoruz ve listBox1'e ekliyoruz.
                for (int i = 1; i < x; i++)
                {
                    // çarpanlarını bulmak için x'ten küçük pozitif tam sayıların x'e tam bölünme durumuna bakıyoruz.
                    if (x % i == 0)
                    {
                        tempString = Convert.ToString(i);
                        list1.Items.Add(tempString);
                        xCarpanlarToplami += i;
                    }
                }
                // girilen y sayısının kendisinden küçük çarpanlarını bulup bir değişkende topluyoruz ve listBox2'ye ekliyoruz.
                for (int i = 1; i < y; i++)
                {
                    // çarpanlarını bulmak için y'den küçük pozitif tam sayıların y'ye tam bölünme durumuna bakıyoruz.
                    if (y % i == 0)
                    {
                        tempString = Convert.ToString(i);
                        list2.Items.Add(tempString);
                        yCarpanlarToplami += i;
                    }
                }

                // iki yeni textBox üretip, x ve y'nin çarpanlarının toplamlarını bu textBox'lara yazıyoruz
                var text1 = new TextBox();
                tempString = Convert.ToString(xCarpanlarToplami);
                text1.Text = tempString;
                text1.Font = new Font("Arial", 14, FontStyle.Bold);
                text1.Left = 340;
                text1.Top = 420;
                text1.Size = new Size(140, 40);
                Controls.Add(text1);

                var text2 = new TextBox();
                tempString = Convert.ToString(yCarpanlarToplami);
                text2.Text = tempString;
                text2.Font = new Font("Arial", 14, FontStyle.Bold);
                text2.Left = 490;
                text2.Top = 420;
                text2.Size = new Size(140, 40);
                Controls.Add(text2);

                // Butona basıldığında istediğimiz konumlara yazılar yazdırması için üç yeni etiket oluşturuyoruz.
                var label1 = new Label();
                label1.Text = "X";
                label1.Font = new Font("Arial", 14, FontStyle.Bold);
                label1.Left = 400;
                label1.Top = 80;
                Controls.Add(label1);

                var label2 = new Label();
                label2.Text = "Y";
                label2.Font = new Font("Arial", 14, FontStyle.Bold);
                label2.Left = 550;
                label2.Top = 80;
                Controls.Add(label2);

                var label3 = new Label();
                label3.Text = "Toplamlar: ";
                label3.Font = new Font("Arial", 14, FontStyle.Bold);
                label3.Left = 220;
                label3.Top = 420;
                label3.Size = new Size(120, 40);
                Controls.Add(label3);

                // arkadaş sayı olup olmadığını kontrol edip, sonucunu ekrana mesaj kutusunda yazdıran koşulu yazıyoruz.
                if (y == xCarpanlarToplami && x == yCarpanlarToplami)
                    MessageBox.Show("Arkadaş Sayılar");
                else
                    MessageBox.Show("Arkadaş Sayı Değiller");
            }
        }
        private void button2_Click(object sender, EventArgs e)
        {
            //"SON" yazılı butona tıklandığında formu kapatması için bu iki kodu yazıyoruz.
            this.Close();
            Application.Exit();
        }
    }
}
