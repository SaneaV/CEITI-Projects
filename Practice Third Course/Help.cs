using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CarRent
{
    public partial class Help : UserControl
    {
        public Help()
        {
            InitializeComponent();
            pictureBox2.Visible = false;
        }

        private void label1_Click(object sender, EventArgs e)
        {
            pictureBox1.Image = Image.FromFile(@"Help\1.jpg");
            pictureBox1.BringToFront();
            pictureBox2.Visible = true;
            pictureBox2.BringToFront();
        }

        private void pictureBox2_Click(object sender, EventArgs e)
        {
            pictureBox2.Visible = false;
            panel1.BringToFront();
            
        }

        private void label2_Click(object sender, EventArgs e)
        {
            pictureBox1.Image = Image.FromFile(@"Help\2.jpg");
            pictureBox1.BringToFront();
            pictureBox2.Visible = true;
            pictureBox2.BringToFront();
        }

        private void label3_Click(object sender, EventArgs e)
        {
            pictureBox1.Image = Image.FromFile(@"Help\3.jpg");
            pictureBox1.BringToFront();
            pictureBox2.Visible = true;
            pictureBox2.BringToFront();
        }

        private void label4_Click(object sender, EventArgs e)
        {
            pictureBox1.Image = Image.FromFile(@"Help\4.jpg");
            pictureBox1.BringToFront();
            pictureBox2.Visible = true;
            pictureBox2.BringToFront();
        }

        private void label5_Click(object sender, EventArgs e)
        {
            pictureBox1.Image = Image.FromFile(@"Help\5.jpg");
            pictureBox1.BringToFront();
            pictureBox2.Visible = true;
            pictureBox2.BringToFront();
        }

        private void label6_Click(object sender, EventArgs e)
        {
            pictureBox1.Image = Image.FromFile(@"Help\6.jpg");
            pictureBox1.BringToFront();
            pictureBox2.Visible = true;
            pictureBox2.BringToFront();
        }

        private void label7_Click(object sender, EventArgs e)
        {
            pictureBox1.Image = Image.FromFile(@"Help\7.jpg");
            pictureBox1.BringToFront();
            pictureBox2.Visible = true;
            pictureBox2.BringToFront();
        }

        private void label8_Click(object sender, EventArgs e)
        {
            pictureBox1.Image = Image.FromFile(@"Help\8.jpg");
            pictureBox1.BringToFront();
            pictureBox2.Visible = true;
            pictureBox2.BringToFront();
        }

        private void label9_Click(object sender, EventArgs e)
        {
            pictureBox1.Image = Image.FromFile(@"Help\9.jpg");
            pictureBox1.BringToFront();
            pictureBox2.Visible = true;
            pictureBox2.BringToFront();
        }

        private void label10_Click(object sender, EventArgs e)
        {
            pictureBox1.Image = Image.FromFile(@"Help\10.jpg");
            pictureBox1.BringToFront();
            pictureBox2.Visible = true;
            pictureBox2.BringToFront();
        }
    }
}
