using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Practic
{
    public partial class FAQ : Form
    {
        public FAQ()
        {
            InitializeComponent();
            radioButton2.Checked = true;
            label1.Text = "Справка программы \"Обрабатываемые земли\"";
            radioButton1.Checked = false;
        }

        int Btn = 0;

        //=============================Button1_Click==========================================
        //=============================о программе============================================
        private void Button1_Click(object sender, EventArgs e)
        {
            SlidePanel.Height = button1.Height;
            SlidePanel.Top = button1.Top;

            if (radioButton2.Checked)
                userControl1.BringToFront();
            else if (radioButton1.Checked)
                 userControl2.BringToFront();
            else if (radioButton3.Checked)
                userControl91.BringToFront();

            Btn = 1;
        }

        //=============================Button2_Click==========================================
        //=============================о программе============================================
        private void Button2_Click(object sender, EventArgs e)
        {
            SlidePanel.Height = button2.Height;
            SlidePanel.Top = button2.Top;

            if (radioButton2.Checked)
                userControl31.BringToFront();
            else if (radioButton1.Checked)
                userControl41.BringToFront();
            else if (radioButton3.Checked)
                userControl101.BringToFront();

            Btn = 2;
        }

        //=============================Button3_Click==========================================
        //=============================о программе============================================
        private void Button3_Click(object sender, EventArgs e)
        {
            SlidePanel.Height = button3.Height;
            SlidePanel.Top = button3.Top;

            if (radioButton2.Checked)
                userControl51.BringToFront();
            else if (radioButton1.Checked)
                userControl61.BringToFront();
            else if (radioButton3.Checked)
                userControl111.BringToFront();

            Btn = 3;
        }

        //=============================Button5_Click==========================================
        //=============================об авторе============================================
        private void Button5_Click(object sender, EventArgs e)
        {
            SlidePanel.Height = button5.Height;
            SlidePanel.Top = button5.Top;

            if (radioButton2.Checked)
                userControl71.BringToFront();
            else if (radioButton1.Checked)
                userControl81.BringToFront();
            else if (radioButton3.Checked)
                userControl121.BringToFront();

            Btn = 4;
        }

        //=============================Button4_Click==========================================
        //=============================Закрытие справки=======================================
        private void Button4_Click(object sender, EventArgs e)
        {
            this.Hide();
        }

        //=============================PictureBox3_Click======================================
        //=============================Румынский язык===========================================
        private void PictureBox2_Click(object sender, EventArgs e)
        {
            radioButton1.Checked = true;
            radioButton2.Checked = false;
            radioButton3.Checked = false;
        }

        //=============================PictureBox3_Click======================================
        //=============================Русский язык===========================================
        private void PictureBox3_Click(object sender, EventArgs e)
        {
            radioButton1.Checked = false;
            radioButton2.Checked = true;
            radioButton3.Checked = false;
        }

        //=============================PictureBox4_Click======================================
        //=============================Английский язык===========================================
        private void PictureBox4_Click(object sender, EventArgs e)
        {
            radioButton1.Checked = false;
            radioButton2.Checked = false;
            radioButton3.Checked = true;
        }


        public void RadioButton1_CheckedChanged(object sender, EventArgs e)
        {
            if (Btn == 1)
                Button1_Click(sender, e);
            else if (Btn == 2)
                Button2_Click(sender, e);
            else if (Btn == 3)
                Button3_Click(sender, e);
            else if (Btn == 4)
                Button5_Click(sender, e);

            label1.Text = "Ajutor \"Terenuri cultivate\"";

            button1.Text = "Despre program";
            button2.Text = "Termeni de sarcini";
            button3.Text = "Principala";
            button5.Text = "Despre autor";
        }

        private void RadioButton2_CheckedChanged(object sender, EventArgs e)
        {
            if (Btn == 1)
                Button1_Click(sender, e);
            else if (Btn == 2)
                Button2_Click(sender, e);
            else if (Btn == 3)
                Button3_Click(sender, e);
            else if (Btn == 4)
                Button5_Click(sender, e);

            label1.Text = "Справка программы \"Обрабатываемые земли\"";

            button1.Text = "О программе";
            button2.Text = "Условия задач";
            button3.Text = "Главная";
            button5.Text = "Об авторе";
        }

        private void RadioButton3_CheckedChanged(object sender, EventArgs e)
        {
            if (Btn == 1)
                Button1_Click(sender, e);
            else if (Btn == 2)
                Button2_Click(sender, e);
            else if (Btn == 3)
                Button3_Click(sender, e);
            else if (Btn == 4)
                Button5_Click(sender, e);

            label1.Text = "FAQ \"Cultivated land.\"";

            button1.Text = "About the program";
            button2.Text = "Task conditions";
            button3.Text = "The main";
            button5.Text = "About the author";
        }
    }
}
