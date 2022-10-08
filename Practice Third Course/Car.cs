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
    public partial class Car : UserControl
    {
        public Car()
        {
            InitializeComponent();

            if (Worker.user.Cod_Position == 1 || Worker.user.Cod_Position == 2)
            {
                button1.Visible = false;
                button1.Text = "Добавить машину";
                button2.Dock = DockStyle.Fill;

                GroupCar groupCar = new GroupCar
                {
                    Dock = DockStyle.Fill
                };
                this.panel2.Controls.Add(groupCar);

                pictureBox1.Visible = true;
                pictureBox2.Visible = true;

            }

            if (Worker.user.Cod_Position == 4)
            {
                
                button2.Visible = false;
                button1.Dock = DockStyle.Fill;
                button1.Text = "Отчёты";

                CarReport carReport = new CarReport
                {
                    Dock = DockStyle.Fill
                };
                this.panel2.Controls.Add(carReport);

                pictureBox1.Visible = false;
                pictureBox2.Visible = false;

            }

            if (Worker.user.Cod_Position == 3)
            {
                button1.Dock = DockStyle.None;
                button2.Dock = DockStyle.None;
                button1.Anchor = AnchorStyles.None;
                button2.Anchor = AnchorStyles.None;
                button1.Text = "Добавить машину";

                CarAdd carAdd = new CarAdd
                {
                    Dock = DockStyle.Fill
                };
                this.panel2.Controls.Add(carAdd);

                pictureBox1.Visible = false;
                pictureBox2.Visible = false;
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            foreach (Control c in panel2.Controls)
                if (c is CarAdd || c is CarReport) { }
                else
                {
                    LoadingForm loading = new LoadingForm();
                    loading.Show();

                    c.Dispose();
                    GC.Collect();
                    GC.WaitForPendingFinalizers();
                    GC.Collect();

                    if (Worker.user.Cod_Position == 3)
                    {
                        CarAdd carAdd = new CarAdd
                        {
                            Dock = DockStyle.Fill
                        };
                        this.panel2.Controls.Add(carAdd);
                        pictureBox1.Visible = false;
                        pictureBox2.Visible = false;
                    }
                    else if (Worker.user.Cod_Position == 4)
                    {
                        CarReport carReport = new CarReport
                        {
                            Dock = DockStyle.Fill
                        };
                        this.panel2.Controls.Add(carReport);
                    }
                    loading.Dispose();
                }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            foreach (Control c in panel2.Controls)
                if (c is GroupCar) { }
                else
                {
                    LoadingForm loading = new LoadingForm();
                    loading.Show();
                    c.Dispose();
                    GC.Collect();
                    GC.WaitForPendingFinalizers();
                    GC.Collect();

                    GroupCar groupCar = new GroupCar
                    {
                        Dock = DockStyle.Fill
                    };
                    this.panel2.Controls.Add(groupCar);

                    pictureBox1.Visible = true;
                    pictureBox2.Visible = true;
                    loading.Dispose();
                }
        }

        private void pictureBox2_Click(object sender, EventArgs e)
        {
            foreach (Control c in panel2.Controls)
                if (c is GroupCar) { }
                else
                {
                    LoadingForm loading = new LoadingForm();
                    loading.Show();
                    c.Dispose();
                    GC.Collect();
                    GC.WaitForPendingFinalizers();
                    GC.Collect();

                    GroupCar groupCar = new GroupCar
                    {
                        Dock = DockStyle.Fill
                    };
                    this.panel2.Controls.Add(groupCar);

                    pictureBox1.Visible = true;
                    pictureBox2.Visible = true;
                    loading.Dispose();
                }
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {
            foreach (Control c in panel2.Controls)
                if (c is CarList) { }
                else
                {
                    LoadingForm loading = new LoadingForm();
                    loading.Show();
                    c.Dispose();
                    GC.Collect();
                    GC.WaitForPendingFinalizers();
                    GC.Collect();

                    CarList carList = new CarList
                    {
                        Dock = DockStyle.Fill
                    };
                    this.panel2.Controls.Add(carList);

                    pictureBox1.Visible = true;
                    pictureBox2.Visible = true;
                    loading.Dispose();
                }
        }
    }
}
