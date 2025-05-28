namespace g191210066
{
    partial class Form1
    {
        /// <summary>
        ///Gerekli tasarımcı değişkeni.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///Kullanılan tüm kaynakları temizleyin.
        /// </summary>
        ///<param name="disposing">yönetilen kaynaklar dispose edilmeliyse doğru; aksi halde yanlış.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer üretilen kod

        /// <summary>
        /// Tasarımcı desteği için gerekli metot - bu metodun 
        ///içeriğini kod düzenleyici ile değiştirmeyin.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.label1 = new System.Windows.Forms.Label();
            this.panel1 = new System.Windows.Forms.Panel();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.panel2 = new System.Windows.Forms.Panel();
            this.panel9 = new System.Windows.Forms.Panel();
            this.puanLabel = new System.Windows.Forms.Label();
            this.saniyeSayaci = new System.Windows.Forms.Panel();
            this.saniyeLabel = new System.Windows.Forms.Label();
            this.panel10 = new System.Windows.Forms.Panel();
            this.label9 = new System.Windows.Forms.Label();
            this.panel7 = new System.Windows.Forms.Panel();
            this.label6 = new System.Windows.Forms.Label();
            this.oyunButonu = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            this.panel3 = new System.Windows.Forms.Panel();
            this.organikButonu = new System.Windows.Forms.Button();
            this.organikProgress = new System.Windows.Forms.ProgressBar();
            this.organikAtikListesi = new System.Windows.Forms.ListBox();
            this.organikBosaltimi = new System.Windows.Forms.Button();
            this.panel4 = new System.Windows.Forms.Panel();
            this.kagitButonu = new System.Windows.Forms.Button();
            this.kagitProgress = new System.Windows.Forms.ProgressBar();
            this.kagitListesi = new System.Windows.Forms.ListBox();
            this.kagitBosaltimi = new System.Windows.Forms.Button();
            this.panel5 = new System.Windows.Forms.Panel();
            this.camButonu = new System.Windows.Forms.Button();
            this.camProgress = new System.Windows.Forms.ProgressBar();
            this.camListesi = new System.Windows.Forms.ListBox();
            this.camBosaltimi = new System.Windows.Forms.Button();
            this.panel6 = new System.Windows.Forms.Panel();
            this.metalButonu = new System.Windows.Forms.Button();
            this.metalProgress = new System.Windows.Forms.ProgressBar();
            this.metalListesi = new System.Windows.Forms.ListBox();
            this.metalBosaltimi = new System.Windows.Forms.Button();
            this.timer1 = new System.Windows.Forms.Timer(this.components);
            this.panel1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.panel2.SuspendLayout();
            this.panel9.SuspendLayout();
            this.saniyeSayaci.SuspendLayout();
            this.panel10.SuspendLayout();
            this.panel7.SuspendLayout();
            this.panel3.SuspendLayout();
            this.panel4.SuspendLayout();
            this.panel5.SuspendLayout();
            this.panel6.SuspendLayout();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.BackColor = System.Drawing.Color.Wheat;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 13.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.label1.ForeColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.label1.Location = new System.Drawing.Point(349, 23);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(391, 29);
            this.label1.TabIndex = 0;
            this.label1.Text = "             ATIK KUTULARI              ";
            // 
            // panel1
            // 
            this.panel1.BackColor = System.Drawing.Color.Khaki;
            this.panel1.Controls.Add(this.pictureBox1);
            this.panel1.Location = new System.Drawing.Point(21, 23);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(300, 300);
            this.panel1.TabIndex = 1;
            // 
            // pictureBox1
            // 
            this.pictureBox1.BackColor = System.Drawing.Color.AliceBlue;
            this.pictureBox1.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.pictureBox1.Location = new System.Drawing.Point(14, 22);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(273, 254);
            this.pictureBox1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pictureBox1.TabIndex = 0;
            this.pictureBox1.TabStop = false;
            // 
            // panel2
            // 
            this.panel2.BackColor = System.Drawing.Color.Khaki;
            this.panel2.Controls.Add(this.panel9);
            this.panel2.Controls.Add(this.saniyeSayaci);
            this.panel2.Controls.Add(this.panel10);
            this.panel2.Controls.Add(this.panel7);
            this.panel2.Controls.Add(this.oyunButonu);
            this.panel2.Controls.Add(this.button2);
            this.panel2.Location = new System.Drawing.Point(23, 341);
            this.panel2.Name = "panel2";
            this.panel2.Size = new System.Drawing.Size(298, 446);
            this.panel2.TabIndex = 2;
            // 
            // panel9
            // 
            this.panel9.BackColor = System.Drawing.Color.MintCream;
            this.panel9.Controls.Add(this.puanLabel);
            this.panel9.Location = new System.Drawing.Point(12, 268);
            this.panel9.Name = "panel9";
            this.panel9.Size = new System.Drawing.Size(273, 76);
            this.panel9.TabIndex = 10;
            // 
            // puanLabel
            // 
            this.puanLabel.AutoSize = true;
            this.puanLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 22.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.puanLabel.Location = new System.Drawing.Point(98, 16);
            this.puanLabel.Name = "puanLabel";
            this.puanLabel.Size = new System.Drawing.Size(42, 44);
            this.puanLabel.TabIndex = 6;
            this.puanLabel.Text = "0";
            // 
            // saniyeSayaci
            // 
            this.saniyeSayaci.BackColor = System.Drawing.Color.MintCream;
            this.saniyeSayaci.Controls.Add(this.saniyeLabel);
            this.saniyeSayaci.Location = new System.Drawing.Point(12, 132);
            this.saniyeSayaci.Name = "saniyeSayaci";
            this.saniyeSayaci.Size = new System.Drawing.Size(272, 81);
            this.saniyeSayaci.TabIndex = 8;
            // 
            // saniyeLabel
            // 
            this.saniyeLabel.AutoSize = true;
            this.saniyeLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 22.2F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Italic))), System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.saniyeLabel.Location = new System.Drawing.Point(98, 20);
            this.saniyeLabel.Name = "saniyeLabel";
            this.saniyeLabel.Size = new System.Drawing.Size(64, 44);
            this.saniyeLabel.TabIndex = 6;
            this.saniyeLabel.Text = "60";
            // 
            // panel10
            // 
            this.panel10.BackColor = System.Drawing.Color.LightSeaGreen;
            this.panel10.Controls.Add(this.label9);
            this.panel10.Location = new System.Drawing.Point(12, 219);
            this.panel10.Name = "panel10";
            this.panel10.Size = new System.Drawing.Size(272, 43);
            this.panel10.TabIndex = 9;
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.BackColor = System.Drawing.Color.LightSeaGreen;
            this.label9.Cursor = System.Windows.Forms.Cursors.Arrow;
            this.label9.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.label9.Font = new System.Drawing.Font("Microsoft Sans Serif", 13.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.label9.Location = new System.Drawing.Point(92, 12);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(83, 29);
            this.label9.TabIndex = 5;
            this.label9.Text = "PUAN";
            // 
            // panel7
            // 
            this.panel7.BackColor = System.Drawing.Color.LightSeaGreen;
            this.panel7.Controls.Add(this.label6);
            this.panel7.Location = new System.Drawing.Point(12, 86);
            this.panel7.Name = "panel7";
            this.panel7.Size = new System.Drawing.Size(273, 43);
            this.panel7.TabIndex = 7;
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.BackColor = System.Drawing.Color.LightSeaGreen;
            this.label6.Cursor = System.Windows.Forms.Cursors.Arrow;
            this.label6.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.label6.Font = new System.Drawing.Font("Microsoft Sans Serif", 13.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.label6.Location = new System.Drawing.Point(92, 8);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(83, 29);
            this.label6.TabIndex = 5;
            this.label6.Text = "SÜRE";
            // 
            // button1
            // 
            this.oyunButonu.BackColor = System.Drawing.Color.LightSeaGreen;
            this.oyunButonu.Font = new System.Drawing.Font("Microsoft Sans Serif", 22.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.oyunButonu.ForeColor = System.Drawing.SystemColors.Control;
            this.oyunButonu.Location = new System.Drawing.Point(12, 16);
            this.oyunButonu.Name = "button1";
            this.oyunButonu.Size = new System.Drawing.Size(273, 64);
            this.oyunButonu.TabIndex = 3;
            this.oyunButonu.Text = "YENİ OYUN";
            this.oyunButonu.UseVisualStyleBackColor = false;
            this.oyunButonu.Click += new System.EventHandler(this.button1_Click);
            // 
            // button2
            // 
            this.button2.Font = new System.Drawing.Font("Microsoft Sans Serif", 22.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.button2.Location = new System.Drawing.Point(18, 372);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(273, 60);
            this.button2.TabIndex = 4;
            this.button2.Text = "ÇIKIŞ";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // panel3
            // 
            this.panel3.BackColor = System.Drawing.Color.Khaki;
            this.panel3.Controls.Add(this.organikButonu);
            this.panel3.Controls.Add(this.organikProgress);
            this.panel3.Controls.Add(this.organikAtikListesi);
            this.panel3.Controls.Add(this.organikBosaltimi);
            this.panel3.Location = new System.Drawing.Point(354, 68);
            this.panel3.Name = "panel3";
            this.panel3.Size = new System.Drawing.Size(187, 364);
            this.panel3.TabIndex = 3;
            // 
            // organikButonu
            // 
            this.organikButonu.Font = new System.Drawing.Font("Times New Roman", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.organikButonu.Location = new System.Drawing.Point(17, 8);
            this.organikButonu.Name = "organikButonu";
            this.organikButonu.Size = new System.Drawing.Size(149, 41);
            this.organikButonu.TabIndex = 6;
            this.organikButonu.Text = "ORGANİK ATIK";
            this.organikButonu.UseVisualStyleBackColor = true;
            this.organikButonu.Click += new System.EventHandler(this.organikButonu_Click);
            // 
            // organikProgress
            // 
            this.organikProgress.Location = new System.Drawing.Point(17, 273);
            this.organikProgress.Maximum = 700;
            this.organikProgress.Name = "organikProgress";
            this.organikProgress.Size = new System.Drawing.Size(149, 34);
            this.organikProgress.TabIndex = 7;
            // 
            // organikAtikListesi
            // 
            this.organikAtikListesi.FormattingEnabled = true;
            this.organikAtikListesi.ItemHeight = 16;
            this.organikAtikListesi.Location = new System.Drawing.Point(17, 55);
            this.organikAtikListesi.Name = "organikAtikListesi";
            this.organikAtikListesi.Size = new System.Drawing.Size(150, 212);
            this.organikAtikListesi.TabIndex = 6;
            // 
            // organikBosaltimi
            // 
            this.organikBosaltimi.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.organikBosaltimi.Location = new System.Drawing.Point(17, 314);
            this.organikBosaltimi.Name = "organikBosaltimi";
            this.organikBosaltimi.Size = new System.Drawing.Size(149, 47);
            this.organikBosaltimi.TabIndex = 5;
            this.organikBosaltimi.Text = "BOŞALT";
            this.organikBosaltimi.UseVisualStyleBackColor = true;
            this.organikBosaltimi.Click += new System.EventHandler(this.organikBosaltimi_Click);
            // 
            // panel4
            // 
            this.panel4.BackColor = System.Drawing.Color.Khaki;
            this.panel4.Controls.Add(this.kagitButonu);
            this.panel4.Controls.Add(this.kagitProgress);
            this.panel4.Controls.Add(this.kagitListesi);
            this.panel4.Controls.Add(this.kagitBosaltimi);
            this.panel4.Location = new System.Drawing.Point(561, 68);
            this.panel4.Name = "panel4";
            this.panel4.Size = new System.Drawing.Size(179, 364);
            this.panel4.TabIndex = 4;
            // 
            // kagitButonu
            // 
            this.kagitButonu.Font = new System.Drawing.Font("Times New Roman", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.kagitButonu.Location = new System.Drawing.Point(15, 8);
            this.kagitButonu.Name = "kagitButonu";
            this.kagitButonu.Size = new System.Drawing.Size(149, 41);
            this.kagitButonu.TabIndex = 11;
            this.kagitButonu.Text = "KAĞIT";
            this.kagitButonu.UseVisualStyleBackColor = true;
            this.kagitButonu.Click += new System.EventHandler(this.kagitButonu_Click);
            // 
            // kagitProgress
            // 
            this.kagitProgress.Location = new System.Drawing.Point(15, 273);
            this.kagitProgress.Maximum = 1200;
            this.kagitProgress.Name = "kagitProgress";
            this.kagitProgress.Size = new System.Drawing.Size(149, 34);
            this.kagitProgress.TabIndex = 10;
            // 
            // kagitListesi
            // 
            this.kagitListesi.FormattingEnabled = true;
            this.kagitListesi.ItemHeight = 16;
            this.kagitListesi.Location = new System.Drawing.Point(15, 55);
            this.kagitListesi.Name = "kagitListesi";
            this.kagitListesi.Size = new System.Drawing.Size(149, 212);
            this.kagitListesi.TabIndex = 7;
            // 
            // kagitBosaltimi
            // 
            this.kagitBosaltimi.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.kagitBosaltimi.Location = new System.Drawing.Point(15, 314);
            this.kagitBosaltimi.Name = "kagitBosaltimi";
            this.kagitBosaltimi.Size = new System.Drawing.Size(149, 47);
            this.kagitBosaltimi.TabIndex = 8;
            this.kagitBosaltimi.Text = "BOŞALT";
            this.kagitBosaltimi.UseVisualStyleBackColor = true;
            this.kagitBosaltimi.Click += new System.EventHandler(this.kagitBosaltimi_Click);
            // 
            // panel5
            // 
            this.panel5.BackColor = System.Drawing.Color.Khaki;
            this.panel5.Controls.Add(this.camButonu);
            this.panel5.Controls.Add(this.camProgress);
            this.panel5.Controls.Add(this.camListesi);
            this.panel5.Controls.Add(this.camBosaltimi);
            this.panel5.Location = new System.Drawing.Point(354, 435);
            this.panel5.Name = "panel5";
            this.panel5.Size = new System.Drawing.Size(187, 363);
            this.panel5.TabIndex = 4;
            // 
            // camButonu
            // 
            this.camButonu.Font = new System.Drawing.Font("Times New Roman", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.camButonu.Location = new System.Drawing.Point(20, 7);
            this.camButonu.Name = "camButonu";
            this.camButonu.Size = new System.Drawing.Size(149, 36);
            this.camButonu.TabIndex = 8;
            this.camButonu.Text = "CAM";
            this.camButonu.UseVisualStyleBackColor = true;
            this.camButonu.Click += new System.EventHandler(this.camButonu_Click);
            // 
            // camProgress
            // 
            this.camProgress.Location = new System.Drawing.Point(18, 273);
            this.camProgress.Maximum = 2200;
            this.camProgress.Name = "camProgress";
            this.camProgress.Size = new System.Drawing.Size(149, 34);
            this.camProgress.TabIndex = 8;
            // 
            // camListesi
            // 
            this.camListesi.FormattingEnabled = true;
            this.camListesi.ItemHeight = 16;
            this.camListesi.Location = new System.Drawing.Point(20, 49);
            this.camListesi.Name = "camListesi";
            this.camListesi.Size = new System.Drawing.Size(149, 212);
            this.camListesi.TabIndex = 8;
            // 
            // camBosaltimi
            // 
            this.camBosaltimi.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.camBosaltimi.Location = new System.Drawing.Point(20, 313);
            this.camBosaltimi.Name = "camBosaltimi";
            this.camBosaltimi.Size = new System.Drawing.Size(149, 47);
            this.camBosaltimi.TabIndex = 7;
            this.camBosaltimi.Text = "BOŞALT";
            this.camBosaltimi.UseVisualStyleBackColor = true;
            this.camBosaltimi.Click += new System.EventHandler(this.camBosaltimi_Click);
            // 
            // panel6
            // 
            this.panel6.BackColor = System.Drawing.Color.Khaki;
            this.panel6.Controls.Add(this.metalButonu);
            this.panel6.Controls.Add(this.metalProgress);
            this.panel6.Controls.Add(this.metalListesi);
            this.panel6.Controls.Add(this.metalBosaltimi);
            this.panel6.Location = new System.Drawing.Point(561, 435);
            this.panel6.Name = "panel6";
            this.panel6.Size = new System.Drawing.Size(179, 363);
            this.panel6.TabIndex = 4;
            // 
            // metalButonu
            // 
            this.metalButonu.Font = new System.Drawing.Font("Times New Roman", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.metalButonu.Location = new System.Drawing.Point(15, 7);
            this.metalButonu.Name = "metalButonu";
            this.metalButonu.Size = new System.Drawing.Size(149, 36);
            this.metalButonu.TabIndex = 9;
            this.metalButonu.Text = "METAL";
            this.metalButonu.UseVisualStyleBackColor = true;
            this.metalButonu.Click += new System.EventHandler(this.metalButonu_Click);
            // 
            // metalProgress
            // 
            this.metalProgress.Location = new System.Drawing.Point(17, 273);
            this.metalProgress.Maximum = 2300;
            this.metalProgress.Name = "metalProgress";
            this.metalProgress.Size = new System.Drawing.Size(149, 34);
            this.metalProgress.TabIndex = 9;
            // 
            // metalListesi
            // 
            this.metalListesi.FormattingEnabled = true;
            this.metalListesi.ItemHeight = 16;
            this.metalListesi.Location = new System.Drawing.Point(15, 49);
            this.metalListesi.Name = "metalListesi";
            this.metalListesi.Size = new System.Drawing.Size(149, 212);
            this.metalListesi.TabIndex = 9;
            // 
            // metalBosaltimi
            // 
            this.metalBosaltimi.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.metalBosaltimi.Location = new System.Drawing.Point(17, 313);
            this.metalBosaltimi.Name = "metalBosaltimi";
            this.metalBosaltimi.Size = new System.Drawing.Size(149, 47);
            this.metalBosaltimi.TabIndex = 6;
            this.metalBosaltimi.Text = "BOŞALT";
            this.metalBosaltimi.UseVisualStyleBackColor = true;
            this.metalBosaltimi.Click += new System.EventHandler(this.metalBosaltimi_Click);
            // 
            // timer1
            // 
            this.timer1.Interval = 1000;
            this.timer1.Tick += new System.EventHandler(this.timer1_Tick);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.DarkSeaGreen;
            this.ClientSize = new System.Drawing.Size(793, 819);
            this.Controls.Add(this.panel6);
            this.Controls.Add(this.panel5);
            this.Controls.Add(this.panel4);
            this.Controls.Add(this.panel3);
            this.Controls.Add(this.panel2);
            this.Controls.Add(this.panel1);
            this.Controls.Add(this.label1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.panel1.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.panel2.ResumeLayout(false);
            this.panel9.ResumeLayout(false);
            this.panel9.PerformLayout();
            this.saniyeSayaci.ResumeLayout(false);
            this.saniyeSayaci.PerformLayout();
            this.panel10.ResumeLayout(false);
            this.panel10.PerformLayout();
            this.panel7.ResumeLayout(false);
            this.panel7.PerformLayout();
            this.panel3.ResumeLayout(false);
            this.panel4.ResumeLayout(false);
            this.panel5.ResumeLayout(false);
            this.panel6.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.Panel panel2;
        private System.Windows.Forms.Button oyunButonu;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.Panel panel3;
        private System.Windows.Forms.Button organikBosaltimi;
        private System.Windows.Forms.Panel panel4;
        private System.Windows.Forms.Button kagitBosaltimi;
        private System.Windows.Forms.Panel panel5;
        private System.Windows.Forms.Button camBosaltimi;
        private System.Windows.Forms.Panel panel6;
        private System.Windows.Forms.Button metalBosaltimi;
        private System.Windows.Forms.ListBox organikAtikListesi;
        private System.Windows.Forms.ListBox kagitListesi;
        private System.Windows.Forms.ListBox camListesi;
        private System.Windows.Forms.ListBox metalListesi;
        private System.Windows.Forms.Timer timer1;
        private System.Windows.Forms.Panel panel9;
        private System.Windows.Forms.Label puanLabel;
        private System.Windows.Forms.Panel saniyeSayaci;
        private System.Windows.Forms.Label saniyeLabel;
        private System.Windows.Forms.Panel panel10;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.Panel panel7;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.ProgressBar organikProgress;
        private System.Windows.Forms.ProgressBar kagitProgress;
        private System.Windows.Forms.ProgressBar camProgress;
        private System.Windows.Forms.ProgressBar metalProgress;
        private System.Windows.Forms.Button organikButonu;
        private System.Windows.Forms.Button kagitButonu;
        private System.Windows.Forms.Button camButonu;
        private System.Windows.Forms.Button metalButonu;
    }
}

