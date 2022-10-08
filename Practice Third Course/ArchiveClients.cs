using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
using System.Data.SqlClient;

namespace CarRent
{
    public partial class ArchiveClients : UserControl
    {
        int rowIndex = 0;
        public ArchiveClients()
        {
            InitializeComponent();

            dataGridView1.DefaultCellStyle.Font = new Font("Century Gothic", 95 / 10);

            using (SqlConnection sqlConnection = new SqlConnection(@"Data Source=.\SQLEXPRESS;Initial Catalog=CarRent;Integrated Security=True"))
            {
                SqlCommand command = new SqlCommand("Select Cod_Client, Client_Name, Client_Surname, Client_PasID, Сlient_PhoneNumber, Client_Adres, Client_Birthday From ArchiveClients", sqlConnection);
                sqlConnection.Open();
                SqlDataAdapter sqlDataAdapter = new SqlDataAdapter(command);
                DataTable dtRecorder = new DataTable();
                sqlDataAdapter.Fill(dtRecorder);
                dataGridView1.DataSource = dtRecorder;
                sqlConnection.Close();

                for (int i = 0; i < dataGridView1.Rows.Count; i++)
                {
                    if (Convert.ToString(dataGridView1.Rows[i].Cells[4].Value) != "          ")
                        dataGridView1.Rows[i].Cells[4].Value = ("+(373)" + Convert.ToString(dataGridView1.Rows[i].Cells[4].Value)).Insert(9, "-");
                }

                dataGridView1.Columns[0].HeaderCell.Value = "Код";
                dataGridView1.Columns[1].HeaderCell.Value = "Имя";
                dataGridView1.Columns[2].HeaderCell.Value = "Фамилия";
                dataGridView1.Columns[3].HeaderCell.Value = "Серия паспорта";
                dataGridView1.Columns[4].HeaderCell.Value = "Номер";
                dataGridView1.Columns[5].HeaderCell.Value = "Адрес";
                dataGridView1.Columns[6].HeaderCell.Value = "Дата рождения";


                dataGridView1.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.Fill;
                dataGridView1.AllowUserToOrderColumns = false;
                dataGridView1.AllowUserToResizeColumns = false;
            }

            if (dataGridView1.Rows.Count > 0)
            {
                pictureBox1.Image = GetPhotoClient(Convert.ToInt32(dataGridView1.Rows[rowIndex].Cells[0].Value));

                Cod.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[0].Value);
                NameLabel.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[1].Value);
                LastName.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[2].Value);
                idPas.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[3].Value);
                Phone.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[4].Value);
                Adres.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[5].Value);
                Birthday.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[6].Value);
            }
            else
            {
                pictureBox1.Image = Image.FromFile(@"UserPicture.png");

                Cod.Text = " ";
                NameLabel.Text = " ";
                LastName.Text = " ";
                idPas.Text = " ";
                Phone.Text = " ";
                Adres.Text = " ";
                Birthday.Text = " ";
            }
        }

        private void DataGridView1_Refresh(int rowIndexLocal)
        {
            pictureBox1.Image.Dispose();

            using (SqlConnection sqlConnection = new SqlConnection(@"Data Source=.\SQLEXPRESS;Initial Catalog=CarRent;Integrated Security=True"))
            {
                SqlCommand command = new SqlCommand("Select Cod_Client, Client_Name, Client_Surname, Client_PasID, Сlient_PhoneNumber, Client_Adres, Client_Birthday From ArchiveClients", sqlConnection);
                sqlConnection.Open();
                SqlDataAdapter sqlDataAdapter = new SqlDataAdapter(command);
                DataTable dtRecorder = new DataTable();
                sqlDataAdapter.Fill(dtRecorder);
                dataGridView1.DataSource = dtRecorder;
                sqlConnection.Close();

                for (int i = 0; i < dataGridView1.Rows.Count; i++)
                {
                    if (Convert.ToString(dataGridView1.Rows[i].Cells[4].Value) != "          ")
                        dataGridView1.Rows[i].Cells[4].Value = ("+(373)" + Convert.ToString(dataGridView1.Rows[i].Cells[4].Value)).Insert(9, "-");
                }

                dataGridView1.Columns[0].HeaderCell.Value = "Код";
                dataGridView1.Columns[1].HeaderCell.Value = "Имя";
                dataGridView1.Columns[2].HeaderCell.Value = "Фамилия";
                dataGridView1.Columns[3].HeaderCell.Value = "Серия паспорта";
                dataGridView1.Columns[4].HeaderCell.Value = "Номер";
                dataGridView1.Columns[5].HeaderCell.Value = "Адрес";
                dataGridView1.Columns[6].HeaderCell.Value = "Дата рождения";

            }

            if (dataGridView1.Rows.Count > 0)
            {
                pictureBox1.Image = GetPhotoClient(Convert.ToInt32(dataGridView1.Rows[rowIndexLocal].Cells[0].Value));

                Cod.Text = Convert.ToString(dataGridView1.Rows[rowIndexLocal].Cells[0].Value);
                NameLabel.Text = Convert.ToString(dataGridView1.Rows[rowIndexLocal].Cells[1].Value);
                LastName.Text = Convert.ToString(dataGridView1.Rows[rowIndexLocal].Cells[2].Value);
                idPas.Text = Convert.ToString(dataGridView1.Rows[rowIndexLocal].Cells[3].Value);
                Phone.Text = Convert.ToString(dataGridView1.Rows[rowIndexLocal].Cells[4].Value);
                Adres.Text = Convert.ToString(dataGridView1.Rows[rowIndexLocal].Cells[5].Value);
                Birthday.Text = Convert.ToString(dataGridView1.Rows[rowIndexLocal].Cells[6].Value);

                dataGridView1.CurrentCell = dataGridView1.Rows[rowIndexLocal].Cells[0];
            }
            else
            {
                pictureBox1.Image = Image.FromFile(@"UserPicture.png");

                Cod.Text = " ";
                NameLabel.Text = " ";
                LastName.Text = " ";
                idPas.Text = " ";
                Phone.Text = " ";
                Adres.Text = " ";
                Birthday.Text = " ";
            }
        }

        private Image GetPhotoClient(int LocalIndex)
        {
            List<byte[]> iScreen = new List<byte[]>();
            using (SqlConnection sqlConnection = new SqlConnection(@"Data Source=.\SQLEXPRESS;Initial Catalog=CarRent;Integrated Security=True"))
            {
                SqlCommand command = new SqlCommand("Select ImageData From ArchiveClients Where Cod_Client = @Cod_Client", sqlConnection);
                sqlConnection.Open();

                SqlParameter param = new SqlParameter
                {
                    ParameterName = "@Cod_Client",
                    Value = LocalIndex,
                };
                command.Parameters.Add(param);
                SqlDataReader sqlReader = command.ExecuteReader();

                while (sqlReader.Read())
                {
                    byte[] iTrimByte = (byte[])sqlReader["ImageData"];
                    iScreen.Add(iTrimByte);
                }
                sqlConnection.Close();
            }

            byte[] imageData = iScreen[0];

            try
            {
                MemoryStream ms = new MemoryStream(imageData);
                Image newImage = Image.FromStream(ms);
                return newImage;
            }
            catch
            {
                return Bitmap.FromFile(@"UserPicture.png");
            }
        }


        private void DataGridView1_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            pictureBox1.Image.Dispose();
            rowIndex = dataGridView1.CurrentCell.RowIndex;

            pictureBox1.Image = GetPhotoClient(Convert.ToInt32(dataGridView1.Rows[rowIndex].Cells[0].Value));

            Cod.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[0].Value);
            NameLabel.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[1].Value);
            LastName.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[2].Value);
            idPas.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[3].Value);
            Phone.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[4].Value);
            Adres.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[5].Value);
            Birthday.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[6].Value);
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            if (textBox1.Text.Length == 0) DataGridView1_Refresh(0);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            pictureBox1.Image.Dispose();

            if (textBox1.Text.Length > 0)
            {
                bool Number = false;
                bool NameSurname = false;

                foreach (var ch in textBox1.Text)
                {

                    if (Char.IsNumber(ch))
                    {
                        Number = true;
                    }
                    if (ch >= 'а' && ch <= 'я' || ch >= 'А' && ch < 'Я') NameSurname = true;
                }

                string firstpart = textBox1.Text.Split(' ')[0];
                string secondpart = "";
                int position = textBox1.Text.IndexOf(' ');

                if (position != -1)
                    secondpart = textBox1.Text.Substring(position);


                using (SqlConnection sqlConnection = new SqlConnection(@"Data Source=.\SQLEXPRESS;Initial Catalog=CarRent;Integrated Security=True"))
                {
                    SqlCommand command = new SqlCommand("Select Cod_Client, Client_Name, Client_Surname, Client_PasID, Сlient_PhoneNumber, Client_Adres, Client_Birthday From ArchiveClients Where Cod_Client = 0", sqlConnection);


                    if (NameSurname)
                    {
                        if (position != -1)
                            command = new SqlCommand("Select Cod_Client, Client_Name, Client_Surname, Client_PasID, Сlient_PhoneNumber, Client_Adres, Client_Birthday From ArchiveClients  Where Client_Name like '%" + firstpart + "%' or Client_Name like '%" + secondpart + "%' or Client_Surname like '%" + secondpart + "%' or Client_Surname like '%" + firstpart + "%' or Client_Adres like '%" + secondpart + "%' or Client_Adres like '%" + firstpart + "%'", sqlConnection);
                        else
                            command = new SqlCommand("Select Cod_Client, Client_Name, Client_Surname, Client_PasID, Сlient_PhoneNumber, Client_Adres, Client_Birthday From ArchiveClients Where Client_Name like '%" + firstpart + "%' or Client_Surname like '%" + firstpart + "%' or Client_Adres like '%" + firstpart + "%'", sqlConnection);
                    }

                    if (Number)
                    {
                        command = new SqlCommand("Select Cod_Client, Client_Name, Client_Surname, Client_PasID, Сlient_PhoneNumber, Client_Adres, Client_Birthday From ArchiveClients Where Client_PasID like '%" + firstpart + "%' or Сlient_PhoneNumber like '%" + firstpart + "%' or Client_Adres like '%" + firstpart + "%' or Client_Birthday like '%" + firstpart + "%' or Cod_Client like '%" + firstpart + "%'", sqlConnection);
                    }

                    sqlConnection.Open();
                    SqlDataAdapter sqlDataAdapter = new SqlDataAdapter(command);
                    DataTable dtRecorder = new DataTable();
                    sqlDataAdapter.Fill(dtRecorder);
                    dataGridView1.DataSource = dtRecorder;
                    sqlConnection.Close();

                    for (int i = 0; i < dataGridView1.Rows.Count; i++)
                    {
                        if (Convert.ToString(dataGridView1.Rows[i].Cells[4].Value) != "          ")
                            dataGridView1.Rows[i].Cells[4].Value = ("+(373)" + Convert.ToString(dataGridView1.Rows[i].Cells[4].Value)).Insert(9, "-");
                    }

                }

                if (dataGridView1.Rows.Count > 0)
                {
                    rowIndex = 0;
                    pictureBox1.Image = GetPhotoClient(Convert.ToInt32(dataGridView1.Rows[rowIndex].Cells[0].Value));

                    Cod.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[0].Value);
                    NameLabel.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[1].Value);
                    LastName.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[2].Value);
                    idPas.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[3].Value);
                    Phone.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[4].Value);
                    Adres.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[5].Value);
                    Birthday.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[6].Value);
                }
                else
                {
                    pictureBox1.Image = Image.FromFile(@"UserPicture.png");

                    Cod.Text = " ";
                    NameLabel.Text = " ";
                    LastName.Text = " ";
                    idPas.Text = " ";
                    Phone.Text = " ";
                    Adres.Text = " ";
                    Birthday.Text = " ";
                }
            }
        }
    }
}
