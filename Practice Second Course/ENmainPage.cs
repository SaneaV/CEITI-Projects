using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Diagnostics;

namespace Practic
{
    public partial class ENmainPage : UserControl
    {
        public ENmainPage()
        {
            InitializeComponent();
        }

        private void Label2_Click(object sender, EventArgs e)
        {
            Process.Start(@"E:\Всё для колледжа\Задачи по программированию\Задачи (основные)\Проекты\Практика 2 курс (2019)\Practic\bin\Debug\ВичевАлександрПрактика.docx");
        }
    }
}
