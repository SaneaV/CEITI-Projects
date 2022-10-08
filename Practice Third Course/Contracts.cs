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
    public partial class Contracts : UserControl
    {
        public Contracts()
        {
            InitializeComponent();


            if (Worker.user.Cod_Position == 1 || Worker.user.Cod_Position == 3)
            {
                button1.Visible = false;
                button2.Dock = DockStyle.Fill;
                button1.Text = "Создать контракт";

                ListContracts listContracts = new ListContracts
                {
                    Dock = DockStyle.Fill
                };
                this.panel2.Controls.Add(listContracts);
            }

            if (Worker.user.Cod_Position == 2)
            {
                button1.Visible = true;
                button1.Dock = DockStyle.None;
                button2.Dock = DockStyle.None;
                button1.Anchor = AnchorStyles.None;
                button2.Anchor = AnchorStyles.None;
                button1.Text = "Создать контракт";

                ContractAdd contractAdd = new ContractAdd
                {
                    Dock = DockStyle.Fill
                };
                this.panel2.Controls.Add(contractAdd);
            }


            if (Worker.user.Cod_Position == 4)
            {

                button2.Visible = false;
                button1.Dock = DockStyle.Fill;
                button1.Text = "Отчёты";

                ContractReport contract = new ContractReport
                {
                    Dock = DockStyle.Fill
                };
                this.panel2.Controls.Add(contract);
            }

        }

        private void button1_Click(object sender, EventArgs e)
        {
            foreach (Control c in panel2.Controls)
                if (c is ContractAdd || c is ContractReport) { }
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
                        ContractAdd contractAdd = new ContractAdd
                        {
                            Dock = DockStyle.Fill
                        };
                        this.panel2.Controls.Add(contractAdd);
                    }
                    else if (Worker.user.Cod_Position == 4)
                    {
                        ContractReport contract = new ContractReport
                        {
                            Dock = DockStyle.Fill
                        };
                        this.panel2.Controls.Add(contract);
                    }

                    loading.Dispose();
                }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            foreach (Control c in panel2.Controls)
                if (c is ListContracts) { }
                else
                {
                    LoadingForm loading = new LoadingForm();
                    loading.Show();
                    c.Dispose();
                    GC.Collect();
                    GC.WaitForPendingFinalizers();
                    GC.Collect();

                    ListContracts listContracts = new ListContracts
                    {
                        Dock = DockStyle.Fill
                    };
                    this.panel2.Controls.Add(listContracts);

                    loading.Dispose();
                }
        }
    }
}
