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
    public partial class Clients : UserControl
    {
        public Clients()
        {
            InitializeComponent();


            if(Worker.user.Cod_Position == 1 || Worker.user.Cod_Position == 3)
            {
                button1.Visible = false;
                button2.Dock = DockStyle.Fill;
                button1.Text = "Добавить клиента";

                GroupClients groupClients = new GroupClients
                {
                    Dock = DockStyle.Fill
                };
                this.panel4.Controls.Add(groupClients);

                pictureBox1.Visible = true;
                pictureBox2.Visible = true;

            }

            if (Worker.user.Cod_Position == 2)
            {
                button1.Dock = DockStyle.None;
                button2.Dock = DockStyle.None;
                button1.Anchor = AnchorStyles.None;
                button2.Anchor = AnchorStyles.None;
                button1.Text = "Добавить клиента";

                ClientAdd addUser = new ClientAdd
                {
                    Dock = DockStyle.Fill
                };
                this.panel4.Controls.Add(addUser);

                pictureBox1.Visible = false;
                pictureBox2.Visible = false;

            }

            if (Worker.user.Cod_Position == 4)
            {
                button2.Visible = false;
                button1.Dock = DockStyle.Fill;
                button1.Text = "Отчёты";

                ClientReports userReport = new ClientReports
                {
                    Dock = DockStyle.Fill
                };
                this.panel4.Controls.Add(userReport);

                pictureBox1.Visible = false;
                pictureBox2.Visible = false;

            }
        }

        private void Button1_Click(object sender, EventArgs e)
        {
            foreach (Control c in panel4.Controls)
            {
                if (c is ClientAdd || c is ClientReports)
                {

                }
                else
                {
                    LoadingForm loading = new LoadingForm();
                    loading.Show();
                    c.Dispose();
                    GC.Collect();
                    GC.WaitForPendingFinalizers();
                    GC.Collect();

                    if (Worker.user.Cod_Position == 2)
                    {
                        ClientAdd addUser = new ClientAdd
                        {
                            Dock = DockStyle.Fill
                        };
                        this.panel4.Controls.Add(addUser);

                        pictureBox1.Visible = false;
                        pictureBox2.Visible = false;
                    }
                    else if (Worker.user.Cod_Position == 4)
                    {
                        ClientReports userReport = new ClientReports
                        {
                            Dock = DockStyle.Fill
                        };
                        this.panel4.Controls.Add(userReport);

                    }

                    loading.Dispose();
                }
            }
        }

        private void Button2_Click(object sender, EventArgs e)
        {
            foreach (Control c in panel4.Controls)
            {
                if (c is GroupClients)
                {

                }
                else
                {
                    LoadingForm loading = new LoadingForm();
                    loading.Show();
                    c.Dispose();
                    GC.Collect();
                    GC.WaitForPendingFinalizers();
                    GC.Collect();

                    GroupClients groupClients = new GroupClients
                    {
                        Dock = DockStyle.Fill
                    };
                    this.panel4.Controls.Add(groupClients);
                    pictureBox1.Visible = true;
                    pictureBox2.Visible = true;

                    loading.Dispose();
                }
            }
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {
            foreach (Control c in panel4.Controls)
            {
                if (c is ClientsList)
                {

                }
                else
                {
                    LoadingForm loading = new LoadingForm();
                    loading.Show();


                    c.Dispose();
                    GC.Collect();
                    GC.WaitForPendingFinalizers();
                    GC.Collect();

                    ClientsList clientsList = new ClientsList
                    {
                        Dock = DockStyle.Fill
                    };
                    this.panel4.Controls.Add(clientsList);

                    loading.Dispose();
                }
            }
        }

        private void pictureBox2_Click(object sender, EventArgs e)
        {
            foreach (Control c in panel4.Controls)
            {
                if (c is GroupClients)
                {

                }
                else
                {
                    LoadingForm loading = new LoadingForm();
                    loading.Show();

                    c.Dispose();
                    GC.Collect();
                    GC.WaitForPendingFinalizers();
                    GC.Collect();

                    GroupClients groupClients = new GroupClients
                    {
                        Dock = DockStyle.Fill
                    };
                    this.panel4.Controls.Add(groupClients);

                    loading.Dispose();
                }
            }
        }
    }
}
