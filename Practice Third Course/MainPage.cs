using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data.SqlClient;
using System.Windows.Threading;
using System.IO;

namespace CarRent
{
    public partial class MainPage : UserControl
    {
        Image[] imageList = new Image[new DirectoryInfo(@"mainPagePictures\").GetFiles().Length];
        int index;


        public MainPage()
        {
            InitializeComponent();

            using (SqlConnection sqlConnection = new SqlConnection(@"Data Source=.\SQLEXPRESS;Initial Catalog=CarRent;Integrated Security=True;Connect Timeout = '150'"))
            {
                SqlCommand command = new SqlCommand("Select TOP(1) Cod_Worker, Count(*) as 'NumberOf' From Contracts Where MONTH(Convert(datetime,DateOfOrder,104)) like MONTH(Convert(datetime,GETDATE(),104)) Group by Cod_Worker order by NumberOf desc", sqlConnection);

                sqlConnection.Open();
                if (command.ExecuteScalar() != null)
                {
                    pictureBox1.Image.Dispose();
                    pictureBox1.Image = Worker.user.GetPhoto(Convert.ToInt32(command.ExecuteScalar()));
                }
                else
                {
                    pictureBox1.Image = Image.FromFile(@"UserPicture.png");
                }
                sqlConnection.Close();
            }

            this.LoadImage();
            this.timer1.Interval = 5000;
            this.index = 0;
            this.pictureBox3.Image = this.imageList[this.index];
            this.timer1.Start();
        }

        private void MainPage_Load(object sender, EventArgs e)
        {

        }

        private void LoadImage()
        {
            string _path = @"mainPagePictures\";
            for (int i = 0; i < this.imageList.Length; i++)
            {
                this.imageList[i] = new Bitmap(_path + i.ToString() + ".jpg");
            }
        }

        private void timer_Tick(object sender, EventArgs e)
        {
            if ((++this.index) >= this.imageList.Length)
            {
                this.index = 0;
            }
            this.pictureBox3.Image = this.imageList[this.index];

        }
    }
}
