using System;
using System.Data.SqlClient;
using System.Drawing;
using System.IO;
using System.Windows.Forms;

namespace CarRent
{
    public partial class BackupDatabase : UserControl
    {
        string path = Application.StartupPath;
        int item = 0;
        public BackupDatabase()
        {
            InitializeComponent();
            updateListBox();
            if (listBox1.Items.Count == 0)
            {
                item = 0;
                label2.Text = "";
            }
            else
            {
                item = listBox1.Items.Count;
                label2.Text = listBox1.Items[item - 1].ToString().Substring(7, 10);
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            LoadingForm loading = new LoadingForm();
            loading.Show();
            string connectionString = @"Data Source=.\SQLEXPRESS;Initial Catalog=CarRent;Integrated Security=True";
            using (SqlConnection connection = new SqlConnection(connectionString))
            {
                try
                {
                    SqlCommand command = new SqlCommand("BACKUP DATABASE CarRent TO DISK = '" + path + @"\Backup\backup(" + DateTime.Now.Date.ToString("dd.MM.yyyy") + ").bak" + "'", connection);

                    connection.Open();
                    command.ExecuteScalar();
                    connection.Close();

                    label1.ForeColor = Color.Green;
                    label1.Visible = true;
                    label1.Text = "Резервная копия успешно создана";
                }
                catch (Exception)
                {
                    label1.ForeColor = Color.Red;
                    label1.Visible = true;
                    label1.Text = "Возникла ошибка при создании резервной копии";
                }
            }

            updateListBox();
                item = listBox1.Items.Count;
                label2.Text = listBox1.Items[item - 1].ToString().Substring(7, 10);
            loading.Dispose();
            
        }


        private void updateListBox()
        {
            listBox1.Items.Clear();
            DirectoryInfo d = new DirectoryInfo(path + @"\Backup");
            FileInfo[] Files = d.GetFiles("*.bak");
            foreach (var file in Files)
            {
                listBox1.Items.Add(file.Name);
            }
        }

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            item = listBox1.SelectedIndex + 1;
            label2.Text = listBox1.Items[item - 1].ToString().Substring(7, 10);
        }

        private void button2_Click(object sender, EventArgs e)
        {

            if (listBox1.Items.Count != 0)
            {
                LoadingForm loading = new LoadingForm();
                loading.Show();
                string connectionString = @"Data Source=.\SQLEXPRESS;Initial Catalog=CarRent;Integrated Security=True";
                using (SqlConnection connection = new SqlConnection(connectionString))
                {
                    try
                    {
                        SqlCommand command = new SqlCommand("Use Master", connection);
                        SqlCommand command1 = new SqlCommand("Alter Database CarRent Set Single_User with Rollback Immediate", connection);
                        SqlCommand command2 = new SqlCommand("RESTORE DATABASE CarRent FROM DISK = '" + path + @"\Backup\backup(" + listBox1.Items[item - 1].ToString().Substring(7, 10) + ").bak" + "' WITH replace ", connection);
                        SqlCommand command3 = new SqlCommand("Use CarRent", connection);
                        SqlCommand command4 = new SqlCommand("Alter Database CarRent set Multi_User", connection);

                        connection.Open();
                        command.ExecuteNonQuery();
                        command1.ExecuteNonQuery();
                        command2.ExecuteNonQuery();
                        command3.ExecuteNonQuery();
                        command4.ExecuteNonQuery();
                        connection.Close();

                        label1.ForeColor = Color.Green;
                        label1.Visible = true;
                        label1.Text = "Резервная копия успешно восстановленна";
                    }
                    catch (Exception)
                    {
                        label1.ForeColor = Color.Red;
                        label1.Visible = true;
                        label1.Text = "Возникла ошибка при восстановлении резервной копии";
                    }
                }

                loading.Dispose();

            }
        }
    }
}
