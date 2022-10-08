namespace CarRent
{
    partial class ArchiveWorkers
    {
        /// <summary> 
        /// Обязательная переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary> 
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором компонентов

        /// <summary> 
        /// Требуемый метод для поддержки конструктора — не изменяйте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.dataGridView1 = new System.Windows.Forms.DataGridView();
            this.button1 = new System.Windows.Forms.Button();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.Status = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.Cod = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.Log = new System.Windows.Forms.Label();
            this.Mail = new System.Windows.Forms.Label();
            this.idPas = new System.Windows.Forms.Label();
            this.Adres = new System.Windows.Forms.Label();
            this.Birthday = new System.Windows.Forms.Label();
            this.Phone = new System.Windows.Forms.Label();
            this.LastName = new System.Windows.Forms.Label();
            this.NameLabel = new System.Windows.Forms.Label();
            this.Login = new System.Windows.Forms.Label();
            this.Email = new System.Windows.Forms.Label();
            this.ID = new System.Windows.Forms.Label();
            this.Adresa = new System.Windows.Forms.Label();
            this.label11 = new System.Windows.Forms.Label();
            this.Telephone = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.panel1 = new System.Windows.Forms.Panel();
            this.carRentDataSetBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.carRentDataSet = new CarRent.CarRentDataSet();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.panel1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.carRentDataSetBindingSource)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.carRentDataSet)).BeginInit();
            this.SuspendLayout();
            // 
            // dataGridView1
            // 
            this.dataGridView1.AllowUserToAddRows = false;
            this.dataGridView1.AllowUserToDeleteRows = false;
            this.dataGridView1.AutoSizeColumnsMode = System.Windows.Forms.DataGridViewAutoSizeColumnsMode.Fill;
            this.dataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.dataGridView1.GridColor = System.Drawing.SystemColors.ActiveBorder;
            this.dataGridView1.Location = new System.Drawing.Point(0, 241);
            this.dataGridView1.Name = "dataGridView1";
            this.dataGridView1.ReadOnly = true;
            this.dataGridView1.RowHeadersWidth = 45;
            this.dataGridView1.Size = new System.Drawing.Size(755, 281);
            this.dataGridView1.TabIndex = 4;
            this.dataGridView1.CellClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.DataGridView1_CellClick);
            // 
            // button1
            // 
            this.button1.BackgroundImage = global::CarRent.Properties.Resources.search;
            this.button1.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.button1.Image = global::CarRent.Properties.Resources.search;
            this.button1.ImageAlign = System.Drawing.ContentAlignment.TopLeft;
            this.button1.Location = new System.Drawing.Point(308, 4);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(19, 20);
            this.button1.TabIndex = 44;
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.Button1_Click);
            // 
            // textBox1
            // 
            this.textBox1.Font = new System.Drawing.Font("Century Gothic", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.textBox1.Location = new System.Drawing.Point(3, 4);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(302, 21);
            this.textBox1.TabIndex = 2;
            this.textBox1.TextChanged += new System.EventHandler(this.textBox1_TextChanged);
            // 
            // Status
            // 
            this.Status.AutoSize = true;
            this.Status.Font = new System.Drawing.Font("Century Gothic", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.Status.Location = new System.Drawing.Point(551, 89);
            this.Status.Name = "Status";
            this.Status.Size = new System.Drawing.Size(0, 17);
            this.Status.TabIndex = 22;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Century Gothic", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label4.Location = new System.Drawing.Point(468, 89);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(83, 17);
            this.label4.TabIndex = 21;
            this.label4.Text = "Должность:";
            // 
            // Cod
            // 
            this.Cod.AutoSize = true;
            this.Cod.Font = new System.Drawing.Font("Century Gothic", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.Cod.Location = new System.Drawing.Point(505, 39);
            this.Cod.Name = "Cod";
            this.Cod.Size = new System.Drawing.Size(0, 17);
            this.Cod.TabIndex = 18;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Century Gothic", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label3.Location = new System.Drawing.Point(468, 39);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(37, 17);
            this.label3.TabIndex = 17;
            this.label3.Text = "Код:";
            // 
            // Log
            // 
            this.Log.AutoSize = true;
            this.Log.Font = new System.Drawing.Font("Century Gothic", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.Log.Location = new System.Drawing.Point(519, 65);
            this.Log.Name = "Log";
            this.Log.Size = new System.Drawing.Size(0, 17);
            this.Log.TabIndex = 16;
            // 
            // Mail
            // 
            this.Mail.AutoSize = true;
            this.Mail.Font = new System.Drawing.Font("Century Gothic", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.Mail.Location = new System.Drawing.Point(293, 168);
            this.Mail.Name = "Mail";
            this.Mail.Size = new System.Drawing.Size(0, 17);
            this.Mail.TabIndex = 15;
            // 
            // idPas
            // 
            this.idPas.AutoSize = true;
            this.idPas.Font = new System.Drawing.Font("Century Gothic", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.idPas.Location = new System.Drawing.Point(276, 141);
            this.idPas.Name = "idPas";
            this.idPas.Size = new System.Drawing.Size(0, 17);
            this.idPas.TabIndex = 14;
            // 
            // Adres
            // 
            this.Adres.AutoSize = true;
            this.Adres.Font = new System.Drawing.Font("Century Gothic", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.Adres.Location = new System.Drawing.Point(207, 193);
            this.Adres.Name = "Adres";
            this.Adres.Size = new System.Drawing.Size(0, 17);
            this.Adres.TabIndex = 13;
            // 
            // Birthday
            // 
            this.Birthday.AutoSize = true;
            this.Birthday.Font = new System.Drawing.Font("Century Gothic", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.Birthday.Location = new System.Drawing.Point(266, 89);
            this.Birthday.Name = "Birthday";
            this.Birthday.Size = new System.Drawing.Size(0, 17);
            this.Birthday.TabIndex = 12;
            // 
            // Phone
            // 
            this.Phone.AutoSize = true;
            this.Phone.Font = new System.Drawing.Font("Century Gothic", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.Phone.Location = new System.Drawing.Point(228, 116);
            this.Phone.Name = "Phone";
            this.Phone.Size = new System.Drawing.Size(0, 17);
            this.Phone.TabIndex = 11;
            // 
            // LastName
            // 
            this.LastName.AutoSize = true;
            this.LastName.Font = new System.Drawing.Font("Century Gothic", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.LastName.Location = new System.Drawing.Point(228, 65);
            this.LastName.Name = "LastName";
            this.LastName.Size = new System.Drawing.Size(0, 17);
            this.LastName.TabIndex = 10;
            // 
            // NameLabel
            // 
            this.NameLabel.AutoSize = true;
            this.NameLabel.Font = new System.Drawing.Font("Century Gothic", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.NameLabel.Location = new System.Drawing.Point(203, 39);
            this.NameLabel.Name = "NameLabel";
            this.NameLabel.Size = new System.Drawing.Size(0, 17);
            this.NameLabel.TabIndex = 9;
            // 
            // Login
            // 
            this.Login.AutoSize = true;
            this.Login.Font = new System.Drawing.Font("Century Gothic", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.Login.Location = new System.Drawing.Point(468, 65);
            this.Login.Name = "Login";
            this.Login.Size = new System.Drawing.Size(51, 17);
            this.Login.TabIndex = 8;
            this.Login.Text = "Логин:";
            // 
            // Email
            // 
            this.Email.AutoSize = true;
            this.Email.Font = new System.Drawing.Font("Century Gothic", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.Email.Location = new System.Drawing.Point(153, 168);
            this.Email.Name = "Email";
            this.Email.Size = new System.Drawing.Size(140, 17);
            this.Email.TabIndex = 7;
            this.Email.Text = "Электронная почта:";
            // 
            // ID
            // 
            this.ID.AutoSize = true;
            this.ID.Font = new System.Drawing.Font("Century Gothic", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.ID.Location = new System.Drawing.Point(153, 141);
            this.ID.Name = "ID";
            this.ID.Size = new System.Drawing.Size(123, 17);
            this.ID.TabIndex = 6;
            this.ID.Text = "Серия паспорта:";
            // 
            // Adresa
            // 
            this.Adresa.AutoSize = true;
            this.Adresa.Font = new System.Drawing.Font("Century Gothic", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.Adresa.Location = new System.Drawing.Point(153, 193);
            this.Adresa.Name = "Adresa";
            this.Adresa.Size = new System.Drawing.Size(54, 17);
            this.Adresa.TabIndex = 5;
            this.Adresa.Text = "Адрес:";
            // 
            // label11
            // 
            this.label11.AutoSize = true;
            this.label11.Font = new System.Drawing.Font("Century Gothic", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label11.Location = new System.Drawing.Point(153, 89);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(113, 17);
            this.label11.TabIndex = 4;
            this.label11.Text = "Дата Рождения:";
            // 
            // Telephone
            // 
            this.Telephone.AutoSize = true;
            this.Telephone.Font = new System.Drawing.Font("Century Gothic", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.Telephone.Location = new System.Drawing.Point(153, 116);
            this.Telephone.Name = "Telephone";
            this.Telephone.Size = new System.Drawing.Size(75, 17);
            this.Telephone.TabIndex = 3;
            this.Telephone.Text = "Телефон: ";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Century Gothic", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label2.Location = new System.Drawing.Point(153, 65);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(76, 17);
            this.label2.TabIndex = 2;
            this.label2.Text = "Фамилия: ";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Century Gothic", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label1.Location = new System.Drawing.Point(153, 39);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(43, 17);
            this.label1.TabIndex = 1;
            this.label1.Text = "Имя: ";
            // 
            // pictureBox1
            // 
            this.pictureBox1.Image = global::CarRent.Properties.Resources.UserPicture;
            this.pictureBox1.Location = new System.Drawing.Point(19, 52);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(106, 123);
            this.pictureBox1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.pictureBox1.TabIndex = 0;
            this.pictureBox1.TabStop = false;
            // 
            // panel1
            // 
            this.panel1.Controls.Add(this.button1);
            this.panel1.Controls.Add(this.textBox1);
            this.panel1.Controls.Add(this.Status);
            this.panel1.Controls.Add(this.label4);
            this.panel1.Controls.Add(this.Cod);
            this.panel1.Controls.Add(this.label3);
            this.panel1.Controls.Add(this.Log);
            this.panel1.Controls.Add(this.Mail);
            this.panel1.Controls.Add(this.idPas);
            this.panel1.Controls.Add(this.Adres);
            this.panel1.Controls.Add(this.Birthday);
            this.panel1.Controls.Add(this.Phone);
            this.panel1.Controls.Add(this.LastName);
            this.panel1.Controls.Add(this.NameLabel);
            this.panel1.Controls.Add(this.Login);
            this.panel1.Controls.Add(this.Email);
            this.panel1.Controls.Add(this.ID);
            this.panel1.Controls.Add(this.Adresa);
            this.panel1.Controls.Add(this.label11);
            this.panel1.Controls.Add(this.Telephone);
            this.panel1.Controls.Add(this.label2);
            this.panel1.Controls.Add(this.label1);
            this.panel1.Controls.Add(this.pictureBox1);
            this.panel1.Dock = System.Windows.Forms.DockStyle.Top;
            this.panel1.Location = new System.Drawing.Point(0, 0);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(755, 241);
            this.panel1.TabIndex = 3;
            // 
            // carRentDataSetBindingSource
            // 
            this.carRentDataSetBindingSource.DataSource = this.carRentDataSet;
            this.carRentDataSetBindingSource.Position = 0;
            // 
            // carRentDataSet
            // 
            this.carRentDataSet.DataSetName = "CarRentDataSet";
            this.carRentDataSet.SchemaSerializationMode = System.Data.SchemaSerializationMode.IncludeSchema;
            // 
            // ArchiveWorkers
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.dataGridView1);
            this.Controls.Add(this.panel1);
            this.Name = "ArchiveWorkers";
            this.Size = new System.Drawing.Size(755, 522);
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.carRentDataSetBindingSource)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.carRentDataSet)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.DataGridView dataGridView1;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.Label Status;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label Cod;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label Log;
        private System.Windows.Forms.Label Mail;
        private System.Windows.Forms.Label idPas;
        private System.Windows.Forms.Label Adres;
        private System.Windows.Forms.Label Birthday;
        private System.Windows.Forms.Label Phone;
        private System.Windows.Forms.Label LastName;
        private System.Windows.Forms.Label NameLabel;
        private System.Windows.Forms.Label Login;
        private System.Windows.Forms.Label Email;
        private System.Windows.Forms.Label ID;
        private System.Windows.Forms.Label Adresa;
        private System.Windows.Forms.Label label11;
        private System.Windows.Forms.Label Telephone;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.BindingSource carRentDataSetBindingSource;
        private CarRentDataSet carRentDataSet;
    }
}
