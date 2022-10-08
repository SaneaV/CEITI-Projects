using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.IO;
using System.Threading;
using System.Windows.Forms;

namespace CarRent
{
    public partial class MainForm : Form
    {
        int ResizeForm = 0;

        public MainForm()
        {
            InitializeComponent();
            SlidePanel.Height = button1.Height;
            SlidePanel.Top = button1.Top;
            Contracts.Visible = false;
            Cars.Visible = false;
            Clients.Visible = false;
            panel4.Visible = false;
            menuStrip1.Visible = false;

            MainPage mainPage = new MainPage
            {
                Dock = DockStyle.Fill
            };
            this.panel5.Controls.Add(mainPage);
        }



        const int WS_MINIMIZEBOX = 0x20000;
        const int CS_DBLCLKS = 0x8;

        protected override CreateParams CreateParams
        {
            get
            {
                CreateParams cp = base.CreateParams;
                cp.Style |= WS_MINIMIZEBOX;
                cp.ClassStyle |= CS_DBLCLKS;
                return cp;
            }
        }


        private void Button1_Click(object sender, EventArgs e)
        {

            foreach (Control c in panel5.Controls)
                if (c is MainPage) { }
                else
                {
                    LoadingForm loading = new LoadingForm();
                    loading.Show();
                    c.Dispose();

                    GC.Collect();
                    GC.WaitForPendingFinalizers();
                    GC.Collect();

                    MainPage mainPage = new MainPage
                    {
                        Dock = DockStyle.Fill
                    };
                    this.panel5.Controls.Add(mainPage);

                    SlidePanel.Visible = true;
                    SlidePanel.Height = button1.Height;
                    SlidePanel.Top = button1.Top;
                    loading.Dispose();
                }
        }


        private void Button3_Click(object sender, EventArgs e)
        {
            if (Worker.user.Cod_Position == 0)
            {
                foreach (Control c in panel5.Controls)
                    if (c is AccessIsDenied) { }
                    else
                    {
                        c.Dispose();

                        GC.Collect();
                        GC.WaitForPendingFinalizers();
                        GC.Collect();

                        AccessIsDenied accessIsDenied = new AccessIsDenied
                        {
                            Dock = DockStyle.Fill
                        };
                        this.panel5.Controls.Add(accessIsDenied);
                    }

                SlidePanel.Visible = true;
                SlidePanel.Height = Contracts.Height;
                SlidePanel.Top = Contracts.Top;
            }
            else
            {
                LoadingForm loading = new LoadingForm();
                loading.Show();
                foreach (Control c in panel5.Controls)
                    if (c is Contracts) { }
                    else
                    {
                        c.Dispose();

                        GC.Collect();
                        GC.WaitForPendingFinalizers();
                        GC.Collect();

                        Contracts contracts = new Contracts()
                        {
                            Dock = DockStyle.Fill
                        };
                        this.panel5.Controls.Add(contracts);


                        SlidePanel.Visible = true;
                        SlidePanel.Height = Contracts.Height;
                        SlidePanel.Top = Contracts.Top;
                    }
                loading.Dispose();

            }
        }

        private void Button2_Click(object sender, EventArgs e)
        {
            if (Worker.user.Cod_Position == 0)
            {
                foreach (Control c in panel5.Controls)
                        if (c is AccessIsDenied) { }
                        else
                        {
                            c.Dispose();

                            GC.Collect();
                            GC.WaitForPendingFinalizers();
                            GC.Collect();

                            AccessIsDenied accessIsDenied = new AccessIsDenied
                            {
                                Dock = DockStyle.Fill
                            };
                            this.panel5.Controls.Add(accessIsDenied);
                        }
                SlidePanel.Visible = true;
                SlidePanel.Height = Cars.Height;
                SlidePanel.Top = Cars.Top;               
            }
            else
            {
                LoadingForm loading = new LoadingForm();
                loading.Show();
                foreach (Control c in panel5.Controls)
                    if (c is Car) { }
                    else
                    {
                        c.Dispose();

                        GC.Collect();
                        GC.WaitForPendingFinalizers();
                        GC.Collect();

                        Car cars = new Car()
                        {
                            Dock = DockStyle.Fill
                        };
                        this.panel5.Controls.Add(cars);


                        SlidePanel.Visible = true;
                        SlidePanel.Height = Cars.Height;
                        SlidePanel.Top = Cars.Top;
                    }
                loading.Dispose();
            }

        }

        private void Button4_Click(object sender, EventArgs e)
        {

            if (Worker.user.Cod_Position == 0)
            {
                foreach (Control c in panel5.Controls)
                    if (c is AccessIsDenied) { }
                    else
                    {
                        c.Dispose();
                        GC.Collect();
                        GC.WaitForPendingFinalizers();
                        GC.Collect();

                        AccessIsDenied accessIsDenied = new AccessIsDenied
                        {
                            Dock = DockStyle.Fill
                        };
                        this.panel5.Controls.Add(accessIsDenied);
                    }

                SlidePanel.Visible = true;
                SlidePanel.Height = Clients.Height;
                SlidePanel.Top = Clients.Top;
            }
            else
            {
                LoadingForm loading = new LoadingForm();
                loading.Show();
                foreach (Control c in panel5.Controls)
                    if (c is Clients) { }
                    else
                    {
                        c.Dispose();
                        GC.Collect();
                        GC.WaitForPendingFinalizers();
                        GC.Collect();

                        Clients clients = new Clients
                        {
                            Dock = DockStyle.Fill
                        };
                        this.panel5.Controls.Add(clients);



                        SlidePanel.Visible = true;
                        SlidePanel.Height = Clients.Height;
                        SlidePanel.Top = Clients.Top;
                    }
                loading.Dispose();
            }

        }


        private void Label2_Click(object sender, EventArgs e)
        {
            using (RegLog LoginRegister = new RegLog(1))
            {
                if (LoginRegister.ShowDialog() == DialogResult.OK)
                {
                    if (Worker.user.Cod_Position == 1)
                        menuStrip1.Visible = true;

                    Contracts.Visible = true;
                    Cars.Visible = true;
                    Clients.Visible = true;

                    panel3.Visible = false;
                    panel4.Visible = true;

                    if (Worker.user.Name_Worker != "")
                    {
                        label4.Text = Worker.user.Name_Worker + " " + Worker.user.Surname_Worker;
                        pictureBox4.Image = Worker.user.GetPhoto();
                    }
                    else
                    {
                        label4.Text = "Новый" + " " + "Сотрудник";
                        pictureBox4.Image = Worker.user.GetPhoto(Convert.ToInt32(Worker.user.Cod_Worker));
                    }


                    if (Worker.user.Login_Worker == "user" + Worker.user.Cod_Worker)
                    {
                        using (NewLogPasMail newLogPasMail = new NewLogPasMail())

                            if (newLogPasMail.ShowDialog() == DialogResult.OK)
                            {
                                Worker.user.GetLogPasMail();
                            }
                    }

                }
            }
            GC.Collect();
            GC.WaitForPendingFinalizers();
            GC.Collect();



        }

        private void Label3_Click(object sender, EventArgs e)
        {
            using (RegLog LoginRegister = new RegLog(2))
            {
                if (LoginRegister.ShowDialog() == DialogResult.OK)
                {
                    if (Worker.user.Cod_Position == 1)
                        menuStrip1.Visible = true;

                    Contracts.Visible = true;
                    Cars.Visible = true;
                    Clients.Visible = true;

                    panel3.Visible = false;
                    panel4.Visible = true;

                    if (Worker.user.Name_Worker != "")
                    {
                        label4.Text = Worker.user.Name_Worker + " " + Worker.user.Surname_Worker;
                        pictureBox4.Image = Worker.user.GetPhoto();
                    }
                    else
                    {
                        label4.Text = "Новый" + " " + "Сотрудник";
                        pictureBox4.Image = Worker.user.GetPhoto(Convert.ToInt32(Worker.user.Cod_Worker));
                    }


                    if (Worker.user.Login_Worker == "user" + Worker.user.Cod_Worker)
                        using (NewLogPasMail newLogPasMail = new NewLogPasMail())
                        {
                            if (newLogPasMail.ShowDialog() == DialogResult.OK)
                            {
                                Worker.user.GetLogPasMail();
                            }
                        }
                }
            }

            GC.Collect();
            GC.WaitForPendingFinalizers();
            GC.Collect();
        }

        private void PictureBox2_Click(object sender, EventArgs e)
        {
            if (ResizeForm == 1)
            {
                this.WindowState = FormWindowState.Normal;
                ResizeForm = 0;
            }
            else
            {
                this.WindowState = FormWindowState.Maximized;
                ResizeForm = 1;
            }


        }

        private void Profil_Button_Click(object sender, EventArgs e)
        {
            SlidePanel.Visible = false;


            foreach (Control c in panel5.Controls)
                if (c is UserProfil) { }
                else
                {
                    LoadingForm loading = new LoadingForm();
                    loading.Show();
                    c.Dispose();
                    GC.Collect();
                    GC.WaitForPendingFinalizers();
                    GC.Collect();

                    UserProfil userProfil = new UserProfil
                    {
                        Dock = DockStyle.Fill
                    };
                    this.panel5.Controls.Add(userProfil);
                    loading.Dispose();
                }
        }

        public void PictureBox5_Click(object sender, EventArgs e)
        {

            using (AreYouSure areYouSure = new AreYouSure())
            {
                if (areYouSure.ShowDialog() == DialogResult.OK)
                {
                    Worker.user.ClearData();
                    Contracts.Visible = false;
                    Cars.Visible = false;
                    Clients.Visible = false;

                    pictureBox4.Image.Dispose();
                    pictureBox4.Image = Image.FromFile(@"UserPicture.png");
                    label4.Text = "";

                    SlidePanel.Visible = true;
                    SlidePanel.Height = button1.Height;
                    SlidePanel.Top = button1.Top;

                    menuStrip1.Visible = false;

                    panel3.Visible = true;
                    panel4.Visible = false;

                    foreach (Control c in panel5.Controls)
                        c.Dispose();

                    MainPage mainPage = new MainPage
                    {
                        Dock = DockStyle.Fill
                    };
                    this.panel5.Controls.Add(mainPage);

                }
            }

            GC.Collect();
            GC.WaitForPendingFinalizers();
            GC.Collect();
        }

        private void РаботникиToolStripMenuItem_Click(object sender, EventArgs e)
        {

            foreach (Control c in panel5.Controls)
                if (c is AdminUsersPanel) { }
                else
                {
                    LoadingForm loading = new LoadingForm();
                    loading.Show();
                    SlidePanel.Visible = false;
                    c.Dispose();
                    GC.Collect();
                    GC.WaitForPendingFinalizers();
                    GC.Collect();

                    AdminUsersPanel admin = new AdminUsersPanel
                    {
                        Dock = DockStyle.Fill
                    };
                    this.panel5.Controls.Add(admin);
                    loading.Dispose();
                }
        }

        private void Close_Click(object sender, EventArgs e)
        {
            GC.Collect();
            GC.WaitForPendingFinalizers();
            GC.Collect();
            this.Dispose();
        }


        private void архивРаботниковToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            foreach (Control c in panel5.Controls)
                if (c is ArchiveWorkers) { }
                else
                {
                    LoadingForm loading = new LoadingForm();
                    loading.Show();
                    SlidePanel.Visible = false;
                    c.Dispose();
                    GC.Collect();
                    GC.WaitForPendingFinalizers();
                    GC.Collect();

                    ArchiveWorkers archiveWorkers = new ArchiveWorkers
                    {
                        Dock = DockStyle.Fill
                    };
                    this.panel5.Controls.Add(archiveWorkers);
                    loading.Dispose();
                }
        }

        private void архивКлиентовToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            foreach (Control c in panel5.Controls)
                if (c is ArchiveClients) { }
                else
                {
                    LoadingForm loading = new LoadingForm();
                    loading.Show();
                    SlidePanel.Visible = false;
                    c.Dispose();
                    GC.Collect();
                    GC.WaitForPendingFinalizers();
                    GC.Collect();

                    ArchiveClients archiveClients = new ArchiveClients
                    {
                        Dock = DockStyle.Fill
                    };
                    this.panel5.Controls.Add(archiveClients);
                    loading.Dispose();
                }
        }

        private void архивАвтомобилейToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            foreach (Control c in panel5.Controls)
                if (c is ArchiveCars) { }
                else
                {
                    LoadingForm loading = new LoadingForm();
                    loading.Show();
                    SlidePanel.Visible = false;
                    c.Dispose();
                    GC.Collect();
                    GC.WaitForPendingFinalizers();
                    GC.Collect();

                    ArchiveCars archiveCars = new ArchiveCars
                    {
                        Dock = DockStyle.Fill
                    };
                    this.panel5.Controls.Add(archiveCars);
                    loading.Dispose();
                }
        }

        private void архивКонтрактовToolStripMenuItem_Click(object sender, EventArgs e)
        {
            foreach (Control c in panel5.Controls)
                if (c is ArchiveContracts) { }
                else
                {
                    LoadingForm loading = new LoadingForm();
                    loading.Show();
                    SlidePanel.Visible = false;
                    c.Dispose();
                    GC.Collect();
                    GC.WaitForPendingFinalizers();
                    GC.Collect();

                    ArchiveContracts archiveContracts = new ArchiveContracts
                    {
                        Dock = DockStyle.Fill
                    };
                    this.panel5.Controls.Add(archiveContracts);
                    loading.Dispose();
                }
        }

        private void чисткаToolStripMenuItem_Click(object sender, EventArgs e)
        {
            foreach (Control c in panel5.Controls)
                if (c is Clear) { }
                else
                {
                    LoadingForm loading = new LoadingForm();
                    loading.Show();
                    SlidePanel.Visible = false;
                    c.Dispose();
                    GC.Collect();
                    GC.WaitForPendingFinalizers();
                    GC.Collect();

                    Clear clear = new Clear
                    {
                        Dock = DockStyle.Fill
                    };
                    this.panel5.Controls.Add(clear);
                    loading.Dispose();
                }
        }

        private void новыеОписанияToolStripMenuItem_Click(object sender, EventArgs e)
        {
            foreach (Control c in panel5.Controls)
                if (c is NewArguments) { }
                else
                {
                    LoadingForm loading = new LoadingForm();
                    loading.Show();
                    SlidePanel.Visible = false;
                    c.Dispose();
                    GC.Collect();
                    GC.WaitForPendingFinalizers();
                    GC.Collect();

                    NewArguments newArguments = new NewArguments
                    {
                        Dock = DockStyle.Fill
                    };
                    this.panel5.Controls.Add(newArguments);
                    loading.Dispose();
                }
        }

        private void резервноеКопированиеToolStripMenuItem_Click(object sender, EventArgs e)
        {
            foreach (Control c in panel5.Controls)
                if (c is BackupDatabase) { }
                else
                {
                    LoadingForm loading = new LoadingForm();
                    loading.Show();
                    SlidePanel.Visible = false;
                    c.Dispose();
                    GC.Collect();
                    GC.WaitForPendingFinalizers();
                    GC.Collect();

                    BackupDatabase backupDatabase = new BackupDatabase
                    {
                        Dock = DockStyle.Fill
                    };
                    this.panel5.Controls.Add(backupDatabase);
                    loading.Dispose();
                }
        }

        private void button5_Click(object sender, EventArgs e)
        {
            foreach (Control c in panel5.Controls)
                if (c is Help) { }
                else
                {
                    LoadingForm loading = new LoadingForm();
                    loading.Show();
                    SlidePanel.Visible = false;
                    c.Dispose();
                    GC.Collect();
                    GC.WaitForPendingFinalizers();
                    GC.Collect();

                    Help help = new Help
                    {
                        Dock = DockStyle.Fill
                    };
                    this.panel5.Controls.Add(help);
                    loading.Dispose();
                }
        }
    }
}

