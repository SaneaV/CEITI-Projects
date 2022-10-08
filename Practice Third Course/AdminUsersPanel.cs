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

namespace CarRent
{
    public partial class AdminUsersPanel : UserControl
    {
        int rowIndex = 0;
        int statusUser = 0;

        public AdminUsersPanel()
        {
            InitializeComponent();
            dataGridView1.DefaultCellStyle.Font = new Font("Century Gothic", 95 / 10);
            comboBox1.Visible = false;
            checkBox2.Visible = false;
            checkBox3.Visible = false;
            button2.Visible = false;
            button6.Visible = false;
            button3.Visible = false;


            using (SqlConnection sqlConnection = new SqlConnection(@"Data Source=.\SQLEXPRESS;Initial Catalog=CarRent;Integrated Security=True"))
            {
                SqlCommand command = new SqlCommand("Select * From WorkerData", sqlConnection);
                sqlConnection.Open();
                SqlDataAdapter sqlDataAdapter = new SqlDataAdapter(command);
                DataTable dtRecorder = new DataTable();
                sqlDataAdapter.Fill(dtRecorder);
                dataGridView1.DataSource = dtRecorder;
                sqlConnection.Close();

                for (int i = 0; i < dataGridView1.Rows.Count; i++)
                {
                    if(Convert.ToString(dataGridView1.Rows[i].Cells[4].Value) != "          ")
                    dataGridView1.Rows[i].Cells[4].Value = ("+(373)" + Convert.ToString(dataGridView1.Rows[i].Cells[4].Value)).Insert(9, "-");
                }

                dataGridView1.Columns[0].HeaderCell.Value = "Код";
                dataGridView1.Columns[1].HeaderCell.Value = "Имя";
                dataGridView1.Columns[2].HeaderCell.Value = "Фамилия";
                dataGridView1.Columns[3].HeaderCell.Value = "Серия паспорта";
                dataGridView1.Columns[4].HeaderCell.Value = "Номер";
                dataGridView1.Columns[5].HeaderCell.Value = "Адрес";
                dataGridView1.Columns[6].HeaderCell.Value = "Дата рождения";
                dataGridView1.Columns[7].HeaderCell.Value = "Логин";
                dataGridView1.Columns[8].HeaderCell.Value = "Пароль";
                dataGridView1.Columns[8].Visible = false;
                dataGridView1.Columns[10].HeaderCell.Value = "Должность";
                dataGridView1.Columns[9].HeaderCell.Value = "Почта";


                dataGridView1.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.Fill;
                dataGridView1.AllowUserToOrderColumns = false;
                dataGridView1.AllowUserToResizeColumns = false;

            }

            pictureBox1.Image = Worker.user.GetPhoto(Convert.ToInt32(dataGridView1.Rows[rowIndex].Cells[0].Value));

            Cod.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[0].Value);
            NameLabel.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[1].Value);
            LastName.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[2].Value);
            idPas.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[3].Value);
            Phone.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[4].Value);
            Adres.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[5].Value);
            Birthday.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[6].Value);
            Log.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[7].Value);
            Mail.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[9].Value);
            Status.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[10].Value);

        }


        private void DataGridView1_Refresh(int rowIndexLocal)
        {
            pictureBox1.Image.Dispose();
            rowIndex = 0;
            using (SqlConnection sqlConnection = new SqlConnection(@"Data Source=.\SQLEXPRESS;Initial Catalog=CarRent;Integrated Security=True"))
            {
                SqlCommand command = new SqlCommand("Select * From WorkerData", sqlConnection);
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

            pictureBox1.Image = Worker.user.GetPhoto(Convert.ToInt32(dataGridView1.Rows[rowIndexLocal].Cells[0].Value));

            Cod.Text = Convert.ToString(dataGridView1.Rows[rowIndexLocal].Cells[0].Value);
            NameLabel.Text = Convert.ToString(dataGridView1.Rows[rowIndexLocal].Cells[1].Value);
            LastName.Text = Convert.ToString(dataGridView1.Rows[rowIndexLocal].Cells[2].Value);
            idPas.Text = Convert.ToString(dataGridView1.Rows[rowIndexLocal].Cells[3].Value);
            Phone.Text = Convert.ToString(dataGridView1.Rows[rowIndexLocal].Cells[4].Value);
            Adres.Text = Convert.ToString(dataGridView1.Rows[rowIndexLocal].Cells[5].Value);
            Birthday.Text = Convert.ToString(dataGridView1.Rows[rowIndexLocal].Cells[6].Value);
            Log.Text = Convert.ToString(dataGridView1.Rows[rowIndexLocal].Cells[7].Value);
            Mail.Text = Convert.ToString(dataGridView1.Rows[rowIndexLocal].Cells[9].Value);
            Status.Text = Convert.ToString(dataGridView1.Rows[rowIndexLocal].Cells[10].Value);

            dataGridView1.CurrentCell = dataGridView1.Rows[rowIndexLocal].Cells[0];
        }


        private void DataGridView1_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            pictureBox1.Image.Dispose();
            rowIndex = dataGridView1.CurrentCell.RowIndex;

            pictureBox1.Image = Worker.user.GetPhoto(Convert.ToInt32(dataGridView1.Rows[rowIndex].Cells[0].Value));
            Cod.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[0].Value);
            NameLabel.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[1].Value);
            LastName.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[2].Value);
            idPas.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[3].Value);
            Phone.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[4].Value);
            Adres.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[5].Value);
            Birthday.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[6].Value);
            Log.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[7].Value);
            Mail.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[9].Value);
            Status.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[10].Value);

            checkBox1.Checked = false;
            label5.Visible = false;
        }

        private void CheckBox1_CheckedChanged(object sender, EventArgs e)
        {
            if (checkBox1.Checked == true)
            {

                if (Convert.ToString(dataGridView1.Rows[rowIndex].Cells[0].Value) != Worker.user.Cod_Worker)
                {
                    comboBox1.Visible = true;
                    comboBox1.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[10].Value);
                    statusUser = comboBox1.SelectedIndex;
                }
                else
                {
                    statusUser = 1;
                    comboBox1.SelectedIndex = 0;
                }

                checkBox2.Visible = true;
                checkBox3.Visible = true;
                button2.Visible = true;
                button6.Visible = true;
                if(Convert.ToString(dataGridView1.Rows[rowIndex].Cells[0].Value)!=Worker.user.Cod_Worker)
                    button3.Visible = true;

                label5.Visible = false;
            }
            else
            {
                label5.Visible = false;
                comboBox1.Visible = false;
                checkBox2.Visible = false;
                checkBox2.Checked = false;
                checkBox3.Visible = false;
                checkBox3.Checked = false;
                button2.Visible = false;
                button6.Visible = false;
                button3.Visible = false;

            }
        }

        private void Button2_Click(object sender, EventArgs e)
        {
            checkBox1.Checked = false;
        }

        private void Button6_Click(object sender, EventArgs e)
        {
            if(statusUser!=comboBox1.SelectedIndex || checkBox2.Checked || checkBox3.Checked)
            using (AreYouSure areYouSure = new AreYouSure())
            {
                    if (areYouSure.ShowDialog() == DialogResult.OK)
                    {
                        rowIndex = dataGridView1.CurrentCell.RowIndex;

                        if(statusUser!=1)
                        Worker.user.UpdateStatus(Convert.ToInt32(dataGridView1.Rows[rowIndex].Cells[0].Value), comboBox1.SelectedIndex);

                        if (checkBox2.Checked == true)
                        {
                            Worker.user.ResetPhoto(Convert.ToInt32(dataGridView1.Rows[rowIndex].Cells[0].Value));
                        }

                        if (checkBox3.Checked == true)
                        {
                            Worker.user.ResetLogPas(Convert.ToInt32(dataGridView1.Rows[rowIndex].Cells[0].Value));
                        }

                        DataGridView1_Refresh(rowIndex);
                        checkBox1.Checked = false;
                    }
            }
            else checkBox1.Checked = false;
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
                    SqlCommand command = new SqlCommand("Select * From WorkerData", sqlConnection);


                    if (NameSurname)
                    {
                        if (position != -1)
                            command = new SqlCommand("Select * From WorkerData Where Worker_Name like '%" + firstpart + "%' or Worker_Name like '%" + secondpart + "%' or Worker_Surname like '%" + secondpart + "%' or Worker_Surname like '%" + firstpart + "%' or Worker_Adres like '%" + secondpart + "%' or Worker_Adres like '%" + firstpart + "%' or Name_Position like '%" + firstpart + "%'", sqlConnection);
                        else
                            command = new SqlCommand("Select * From WorkerData Where Worker_Name like '%" + firstpart + "%' or Worker_Surname like '%" + firstpart + "%' or Worker_Adres like '%" + firstpart + "%' or Name_Position like '%" + firstpart + "%'", sqlConnection);
                    }

                    if (Number)
                    {
                        command = new SqlCommand("Select * From WorkerData Where Worker_PasID like '%" + firstpart + "%' or Worker_PhoneNumber like '%" + firstpart + "%' or Worker_Adres like '%" + firstpart + "%' or Worker_Birthday like '%" + firstpart + "%' or Cod_Worker like '%" + firstpart + "%'", sqlConnection);
                    }

                    if (UserNameMail)
                    {
                        command = new SqlCommand("Select * From WorkerData Where Worker_Login like '%" + firstpart + "%' or Worker_Mail like '%" + firstpart + "%'", sqlConnection);
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
                    pictureBox1.Image = Worker.user.GetPhoto(Convert.ToInt32(dataGridView1.Rows[rowIndex].Cells[0].Value));
                    Cod.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[0].Value);
                    NameLabel.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[1].Value);
                    LastName.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[2].Value);
                    idPas.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[3].Value);
                    Phone.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[4].Value);
                    Adres.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[5].Value);
                    Birthday.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[6].Value);
                    Log.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[7].Value);
                    Mail.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[9].Value);
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

        private void TextBox1_TextChanged(object sender, EventArgs e)
        {
            if (textBox1.Text.Length == 0) DataGridView1_Refresh(0);
        }

        private void Button3_Click(object sender, EventArgs e)
        {
            label5.Visible = false;
            try
            {
                using (SqlConnection sqlConnection = new SqlConnection(@"Data Source=.\SQLEXPRESS;Initial Catalog=CarRent;Integrated Security=True"))
                {
                    sqlConnection.Open();
                    SqlCommand command = new SqlCommand("Select Count(*) From Contracts Where Cod_Worker = " + dataGridView1.Rows[rowIndex].Cells[0].Value + "", sqlConnection);
                    int Count = (int)command.ExecuteScalar();
                    if (Count > 0)
                        throw new Exception("Сперва удалите все контракты этого работника");

                    sqlConnection.Close();
                }

                using (AreYouSure areYouSure = new AreYouSure())
                {
                    if (areYouSure.ShowDialog() == DialogResult.OK)
                    {
                        using (SqlConnection sqlConnection = new SqlConnection(@"Data Source=.\SQLEXPRESS;Initial Catalog=CarRent;Integrated Security=True"))
                        {
                            sqlConnection.Open();

                            SqlCommand command = new SqlCommand("DeleteWorker", sqlConnection)
                            {
                                CommandType = CommandType.StoredProcedure
                            };

                            SqlParameter nameParam = new SqlParameter
                            {
                                ParameterName = "@Cod_WorkerLocal",
                                Value = dataGridView1.Rows[rowIndex].Cells[0].Value
                            };

                            command.Parameters.Add(nameParam);
                            command.ExecuteScalar();

                            sqlConnection.Close();
                            DataGridView1_Refresh(0);
                        }
                    }

                }

                checkBox1.Checked = false;

            }
            catch(Exception ex)
            {
                label5.Visible = true;
                label5.Text = ex.Message;
            }
            
        }

        private void AdminUsersPanel_Load(object sender, EventArgs e)
        {
            using (SqlConnection sqlConnection = new SqlConnection(@"Data Source=.\SQLEXPRESS;Initial Catalog=CarRent;Integrated Security=True"))
            {
                SqlCommand command = new SqlCommand("Select Name_Position from Positions", sqlConnection);
                sqlConnection.Open();

                DataTable table = new DataTable();
                SqlDataAdapter sqlDataAdapter = new SqlDataAdapter(command);
                sqlDataAdapter.Fill(table);
                comboBox1.DataSource = table;
                comboBox1.DisplayMember = "Name_Position";
                comboBox1.SelectedIndex = -1;
            }
            }
    }
    
}
