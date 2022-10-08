using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Practic
{
    static class Program
    {
        /// <summary>
        /// Главная точка входа для приложения.
        /// </summary>
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);

            Loading first = new Loading();
            DateTime end = DateTime.Now + TimeSpan.FromSeconds(5);
            first.Show();

            while(end>DateTime.Now)
            {
                Application.DoEvents();
            }

            first.Close();
            first.Dispose();
            Application.Run(new MainForm());
        }
    }
}
