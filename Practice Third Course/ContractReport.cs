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
    public partial class ContractReport : UserControl
    {
        public ContractReport()
        {
            InitializeComponent();
        }

        private void ContractReport_Load(object sender, EventArgs e)
        {
            // TODO: данная строка кода позволяет загрузить данные в таблицу "CarRentDataSet.ContractData". При необходимости она может быть перемещена или удалена.
            this.ContractDataTableAdapter.Fill(this.CarRentDataSet.ContractData);

            this.reportViewer1.RefreshReport();
        }
    }
}
