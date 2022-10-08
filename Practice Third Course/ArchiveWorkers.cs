using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data.SqlClient;
using System.IO;

namespace CarRent
{
    public partial class ArchiveWorkers : UserControl
    {
        int rowIndex = 0;

        public ArchiveWorkers()
        {
            InitializeComponent();
            dataGridView1.DefaultCellStyle.Font = new Font("Century Gothic", 95 / 10);

            using (SqlConnection sqlConnection = new SqlConnection(@"Data Source=.\SQLEXPRESS;Initial Catalog=CarRent;Integrated Security=True"))
            {
                SqlCommand command = new SqlCommand("Select Cod_Worker, Worker_Login, Worker_Password, Worker_Mail, Worker_Name, Worker_Surname, Worker_PasID, Worker_PhoneNumber, Worker_Adres, Worker_Birthday, Name_Position From ArchiveWorkers", sqlConnection);
                sqlConnection.Open();
                SqlDataAdapter sqlDataAdapter = new SqlDataAdapter(command);
                DataTable dtRecorder = new DataTable();
                sqlDataAdapter.Fill(dtRecorder);
                dataGridView1.DataSource = dtRecorder;
                sqlConnection.Close();

                if (dtRecorder.Rows.Count>0)
                {
                    for (int i = 0; i < dataGridView1.Rows.Count; i++)
                    {
                        if (Convert.ToString(dataGridView1.Rows[i].Cells[4].Value) != "          ")
                            dataGridView1.Rows[i].Cells[7].Value = ("+(373)" + Convert.ToString(dataGridView1.Rows[i].Cells[7].Value)).Insert(9, "-");
                    }


                    pictureBox1.Image = GetPhoto(Convert.ToInt32(dataGridView1.Rows[rowIndex].Cells[0].Value));

                    Cod.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[0].Value);
                    NameLabel.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[4].Value);
                    LastName.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[5].Value);
                    idPas.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[6].Value);
                    Phone.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[7].Value);
                    Adres.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[8].Value);
                    Birthday.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[9].Value);
                    Log.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[1].Value);
                    Mail.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[3].Value);
                    Status.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[10].Value);
                }
                

                dataGridView1.Columns[0].HeaderCell.Value = "Код";
                dataGridView1.Columns[1].HeaderCell.Value = "Логин";
                dataGridView1.Columns[2].Visible = false;
                dataGridView1.Columns[3].HeaderCell.Value = "Почта";
                dataGridView1.Columns[4].HeaderCell.Value = "Имя";
                dataGridView1.Columns[5].HeaderCell.Value = "Фамилия";
                dataGridView1.Columns[6].HeaderCell.Value = "Серия паспорта";
                dataGridView1.Columns[7].HeaderCell.Value = "Номер";
                dataGridView1.Columns[8].HeaderCell.Value = "Адрес";
                dataGridView1.Columns[9].HeaderCell.Value = "Дата рождения";
                dataGridView1.Columns[10].HeaderCell.Value = "Должность";




                dataGridView1.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.Fill;
                dataGridView1.AllowUserToOrderColumns = false;
                dataGridView1.AllowUserToResizeColumns = false;

            }

        }


        public Image GetPhoto(int Cod_WorkerSelect)
        {
            List<byte[]> iScreen = new List<byte[]>();
            using (SqlConnection sqlConnection = new SqlConnection(@"Data Source=.\SQLEXPRESS;Initial Catalog=CarRent;Integrated Security=True"))
            {
                SqlCommand command = new SqlCommand("Select ImageData From ArchiveWorkers Where Cod_Worker = @Cod_Worker", sqlConnection);
                sqlConnection.Open();

                SqlParameter param = new SqlParameter
                {
                    ParameterName = "@Cod_Worker",
                    Value = Cod_WorkerSelect,
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


        private void DataGridView1_Refresh(int rowIndexLocal)
        {
            pictureBox1.Image.Dispose();
            using (SqlConnection sqlConnection = new SqlConnection(@"Data Source=.\SQLEXPRESS;Initial Catalog=CarRent;Integrated Security=True"))
            {
                SqlCommand command = new SqlCommand("Select Cod_Worker, Worker_Login, Worker_Password, Worker_Mail, Worker_Name, Worker_Surname, Worker_PasID, Worker_PhoneNumber, Worker_Adres, Worker_Birthday, Name_Position From ArchiveWorkers", sqlConnection);
                sqlConnection.Open();
                SqlDataAdapter sqlDataAdapter = new SqlDataAdapter(command);
                DataTable dtRecorder = new DataTable();
                sqlDataAdapter.Fill(dtRecorder);
                dataGridView1.DataSource = dtRecorder;
                sqlConnection.Close();

                if (dtRecorder.Rows.Count > 0)
                {
                    for (int i = 0; i < dataGridView1.Rows.Count; i++)
                    {
                        if (Convert.ToString(dataGridView1.Rows[i].Cells[4].Value) != "          ")
                            dataGridView1.Rows[i].Cells[7].Value = ("+(373)" + Convert.ToString(dataGridView1.Rows[i].Cells[7].Value)).Insert(9, "-");
                    }


                    pictureBox1.Image = GetPhoto(Convert.ToInt32(dataGridView1.Rows[rowIndexLocal].Cells[0].Value));

                    Cod.Text = Convert.ToString(dataGridView1.Rows[rowIndexLocal].Cells[0].Value);
                    NameLabel.Text = Convert.ToString(dataGridView1.Rows[rowIndexLocal].Cells[4].Value);
                    LastName.Text = Convert.ToString(dataGridView1.Rows[rowIndexLocal].Cells[5].Value);
                    idPas.Text = Convert.ToString(dataGridView1.Rows[rowIndexLocal].Cells[6].Value);
                    Phone.Text = Convert.ToString(dataGridView1.Rows[rowIndexLocal].Cells[7].Value);
                    Adres.Text = Convert.ToString(dataGridView1.Rows[rowIndexLocal].Cells[8].Value);
                    Birthday.Text = Convert.ToString(dataGridView1.Rows[rowIndexLocal].Cells[9].Value);
                    Log.Text = Convert.ToString(dataGridView1.Rows[rowIndexLocal].Cells[1].Value);
                    Mail.Text = Convert.ToString(dataGridView1.Rows[rowIndexLocal].Cells[3].Value);
                    Status.Text = Convert.ToString(dataGridView1.Rows[rowIndexLocal].Cells[10].Value);
                }

                else
                {

                    pictureBox1.Image = Image.FromFile(@"UserPicture.png");

                    Cod.Text = "";
                    NameLabel.Text = "";
                    LastName.Text = "";
                    idPas.Text = "";
                    Phone.Text = "";
                    Adres.Text = "";
                    Birthday.Text = "";
                    Log.Text = "";
                    Mail.Text = "";
                    Status.Text = "";
                }
            }
        }


        private void DataGridView1_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            pictureBox1.Image.Dispose();
            rowIndex = dataGridView1.CurrentCell.RowIndex;

            pictureBox1.Image = GetPhoto(Convert.ToInt32(dataGridView1.Rows[rowIndex].Cells[0].Value));

            Cod.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[0].Value);
            NameLabel.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[4].Value);
            LastName.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[5].Value);
            idPas.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[6].Value);
            Phone.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[7].Value);
            Adres.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[8].Value);
            Birthday.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[9].Value);
            Log.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[1].Value);
            Mail.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[3].Value);
            Status.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[10].Value);
        }


        private void Button1_Click(object sender, EventArgs e)
        {
            pictureBox1.Image.Dispose();

            if (textBox1.Text.Length > 0)
            {
                bool Number = false;
                bool UserNameMail = false;
                bool NameSurname = false;

                foreach (var ch in textBox1.Text)
                {

                    if (Char.IsNumber(ch))
                    {
                        Number = true;
                    }
                    if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch < 'Z') UserNameMail = true;
                    if (ch >= 'а' && ch <= 'я' || ch >= 'А' && ch < 'Я') NameSurname = true;
                }

                string firstpart = textBox1.Text.Split(' ')[0];
                string secondpart = "";
                int position = textBox1.Text.IndexOf(' ');

                if (position != -1)
                    secondpart = textBox1.Text.Substring(position);


                using (SqlConnection sqlConnection = new SqlConnection(@"Data Source=.\SQLEXPRESS;Initial Catalog=CarRent;Integrated Security=True"))
                {
                    SqlCommand command = new SqlCommand("Select Cod_Worker, Worker_Login, Worker_Password, Worker_Mail, Worker_Name, Worker_Surname, Worker_PasID, Worker_PhoneNumber, Worker_Adres, Worker_Birthday, Name_Position From ArchiveWorkers", sqlConnection);


                    if (NameSurname)
                    {
                        if (position != -1)
                            command = new SqlCommand("Select Cod_Worker, Worker_Login, Worker_Password, Worker_Mail, Worker_Name, Worker_Surname, Worker_PasID, Worker_PhoneNumber, Worker_Adres, Worker_Birthday, Name_Position From ArchiveWorkers Where Worker_Name like '%" + firstpart + "%' or Worker_Name like '%" + secondpart + "%' or Worker_Surname like '%" + secondpart + "%' or Worker_Surname like '%" + firstpart + "%' or Worker_Adres like '%" + secondpart + "%' or Worker_Adres like '%" + firstpart + "%'", sqlConnection);
                        else
                            command = new SqlCommand("Select Cod_Worker, Worker_Login, Worker_Password, Worker_Mail, Worker_Name, Worker_Surname, Worker_PasID, Worker_PhoneNumber, Worker_Adres, Worker_Birthday, Name_Position From ArchiveWorkers Where Worker_Name like '%" + firstpart + "%' or Worker_Surname like '%" + firstpart + "%' or Worker_Adres like '%" + firstpart + "%' or Name_Position like '%" + firstpart + "%'", sqlConnection);
                    }

                    if (Number)
                    {
                        command = new SqlCommand("Select Cod_Worker, Worker_Login, Worker_Password, Worker_Mail, Worker_Name, Worker_Surname, Worker_PasID, Worker_PhoneNumber, Worker_Adres, Worker_Birthday, Name_Position From ArchiveWorkers Where Worker_PasID like '%" + firstpart + "%' or Worker_PhoneNumber like '%" + firstpart + "%' or Worker_Adres like '%" + firstpart + "%' or Worker_Birthday like '%" + firstpart + "%' or Cod_Worker like '%" + firstpart + "%'", sqlConnection);
                    }

                    if (UserNameMail)
                    {
                        command = new SqlCommand("Select Cod_Worker, Worker_Login, Worker_Password, Worker_Mail, Worker_Name, Worker_Surname, Worker_PasID, Worker_PhoneNumber, Worker_Adres, Worker_Birthday, Name_Position From ArchiveWorkers Where Worker_Login like '%" + firstpart + "%' or Worker_Mail like '%" + firstpart + "%'", sqlConnection);
                    }

                    sqlConnection.Open();
                    SqlDataAdapter sqlDataAdapter = new SqlDataAdapter(command);
                    DataTable dtRecorder = new DataTable();
                    sqlDataAdapter.Fill(dtRecorder);
                    dataGridView1.DataSource = dtRecorder;
                    sqlConnection.Close();
                }

                if (dataGridView1.Rows.Count > 0)
                {
                    rowIndex = 0;
                    for (int i = 0; i < dataGridView1.Rows.Count; i++)
                    {
                        if (Convert.ToString(dataGridView1.Rows[i].Cells[4].Value) != "          ")
                            dataGridView1.Rows[i].Cells[7].Value = ("+(373)" + Convert.ToString(dataGridView1.Rows[i].Cells[7].Value)).Insert(9, "-");
                    }
                    pictureBox1.Image = GetPhoto(Convert.ToInt32(dataGridView1.Rows[rowIndex].Cells[0].Value));

                    Cod.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[0].Value);
                    NameLabel.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[4].Value);
                    LastName.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[5].Value);
                    idPas.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[6].Value);
                    Phone.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[7].Value);
                    Adres.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[8].Value);
                    Birthday.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[9].Value);
                    Log.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[1].Value);
                    Mail.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[3].Value);
                    Status.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[10].Value);
                }
                else
                {
                    pictureBox1.Image = Image.FromFile(@"UserPicture.png");
                    Cod.Text = "";
                    NameLabel.Text = "";
                    LastName.Text = "";
                    idPas.Text = "";
                    Phone.Text = "";
                    Adres.Text = "";
                    Birthday.Text = "";
                    Log.Text = "";
                    Mail.Text = "";
                    Status.Text = "";
                }
            }
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            if (textBox1.Text.Length == 0) DataGridView1_Refresh(0);
        }
    }
    
}
