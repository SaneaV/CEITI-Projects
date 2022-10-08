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
    public partial class ListContracts : UserControl
    {
        int rowIndex = 0;
        public ListContracts()
        {
            InitializeComponent();

            if (Worker.user.Cod_Position == 1)
                button2.Visible = true;
            else button2.Visible = false;

            using (SqlConnection sqlConnection = new SqlConnection(@"Data Source=.\SQLEXPRESS;Initial Catalog=CarRent;Integrated Security=True"))
            {
                SqlCommand command = new SqlCommand("Select * From ContractData", sqlConnection);
                sqlConnection.Open();
                SqlDataAdapter sqlDataAdapter = new SqlDataAdapter(command);
                DataTable dtRecorder = new DataTable();
                sqlDataAdapter.Fill(dtRecorder);
                dataGridView1.DataSource = dtRecorder;
                sqlConnection.Close();


                command = new SqlCommand("Select Concat(Marka,' ', Car_Model, ' ', Cod_Car) as Car from AllInfoCar", sqlConnection);
                sqlConnection.Open();

                DataTable table = new DataTable();
                sqlDataAdapter = new SqlDataAdapter(command);
                sqlDataAdapter.Fill(table);
                comboBox1.DataSource = table;
                comboBox1.DisplayMember = "Car";
                comboBox1.SelectedIndex = -1;

                command = new SqlCommand("Select Concat(Client_Name,' ', Client_Surname,' ', Cod_Client) as Client from Clients", sqlConnection);

                table = new DataTable();
                sqlDataAdapter = new SqlDataAdapter(command);
                sqlDataAdapter.Fill(table);
                comboBox2.DataSource = table;
                comboBox2.DisplayMember = "Client";
                comboBox2.SelectedIndex = -1;
                sqlConnection.Close();

                command = new SqlCommand("Select Concat(Worker_Name,' ', Worker_Surname,' ', Cod_Worker) as Worker from Workers Where Cod_Position = 2", sqlConnection);

                table = new DataTable();
                sqlDataAdapter = new SqlDataAdapter(command);
                sqlDataAdapter.Fill(table);
                comboBox3.DataSource = table;
                comboBox3.DisplayMember = "Worker";
                comboBox3.SelectedIndex = -1;
                sqlConnection.Close();


            }

            dataGridView1.Columns[0].HeaderCell.Value = "Код";
            dataGridView1.Columns[1].HeaderCell.Value = "Клиент";
            dataGridView1.Columns[2].HeaderCell.Value = "Авто";
            dataGridView1.Columns[3].HeaderCell.Value = "Работник";
            dataGridView1.Columns[4].HeaderCell.Value = "Дата создания";
            dataGridView1.Columns[5].HeaderCell.Value = "Дата начала";
            dataGridView1.Columns[6].HeaderCell.Value = "Дата конца";
            dataGridView1.Columns[7].HeaderCell.Value = "Сумма($)";

            if (dataGridView1.Rows.Count > 0)
            {
                string CodCar = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[2].Value);
                string CodClient = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[1].Value);

                pictureBox1.Image = GetPhotoCar(Convert.ToInt32(CodCar.Split(' ').Last()));
                pictureBox2.Image = GetPhotoClient(Convert.ToInt32(CodClient.Split(' ').Last()));

                label9.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[0].Value);
                label10.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[1].Value);
                label11.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[2].Value);
                label12.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[3].Value);
                label13.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[4].Value);
                label14.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[5].Value);
                label15.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[6].Value);
                label16.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[7].Value)+"$";
            }
            else
            {
                pictureBox1.Image = Image.FromFile(@"Car.png");
                pictureBox2.Image = Image.FromFile(@"UserPicture.png");

                label9.Text = " ";
                label10.Text = " ";
                label11.Text = " ";
                label12.Text = " ";
                label13.Text = " ";
                label14.Text = " ";
                label15.Text = " ";
                label16.Text = " ";
            }
        }

        private void DataGridView1_Refresh(int rowIndexLocal)
        {
            pictureBox1.Image.Dispose();
            pictureBox2.Image.Dispose();
            rowIndex = 0;

            using (SqlConnection sqlConnection = new SqlConnection(@"Data Source=.\SQLEXPRESS;Initial Catalog=CarRent;Integrated Security=True"))
            {
                SqlCommand command = new SqlCommand("Select * From ContractData", sqlConnection);
                sqlConnection.Open();
                SqlDataAdapter sqlDataAdapter = new SqlDataAdapter(command);
                DataTable dtRecorder = new DataTable();
                sqlDataAdapter.Fill(dtRecorder);
                dataGridView1.DataSource = dtRecorder;
                sqlConnection.Close();

            }

            dataGridView1.Columns[0].HeaderCell.Value = "Код";
            dataGridView1.Columns[1].HeaderCell.Value = "Клиент";
            dataGridView1.Columns[2].HeaderCell.Value = "Авто";
            dataGridView1.Columns[3].HeaderCell.Value = "Работник";
            dataGridView1.Columns[4].HeaderCell.Value = "Дата создания";
            dataGridView1.Columns[5].HeaderCell.Value = "Дата начала";
            dataGridView1.Columns[6].HeaderCell.Value = "Дата конца";
            dataGridView1.Columns[7].HeaderCell.Value = "Сумма($)";

            if (dataGridView1.Rows.Count > 0)
            {
                string CodCar = Convert.ToString(dataGridView1.Rows[rowIndexLocal].Cells[2].Value);
                string CodClient = Convert.ToString(dataGridView1.Rows[rowIndexLocal].Cells[1].Value);

                pictureBox1.Image = GetPhotoCar(Convert.ToInt32(CodCar.Split(' ').Last()));
                pictureBox2.Image = GetPhotoClient(Convert.ToInt32(CodClient.Split(' ').Last()));

                label9.Text = Convert.ToString(dataGridView1.Rows[rowIndexLocal].Cells[0].Value);
                label10.Text = Convert.ToString(dataGridView1.Rows[rowIndexLocal].Cells[1].Value);
                label11.Text = Convert.ToString(dataGridView1.Rows[rowIndexLocal].Cells[2].Value);
                label12.Text = Convert.ToString(dataGridView1.Rows[rowIndexLocal].Cells[3].Value);
                label13.Text = Convert.ToString(dataGridView1.Rows[rowIndexLocal].Cells[4].Value);
                label14.Text = Convert.ToString(dataGridView1.Rows[rowIndexLocal].Cells[5].Value);
                label15.Text = Convert.ToString(dataGridView1.Rows[rowIndexLocal].Cells[6].Value);
                label16.Text = Convert.ToString(dataGridView1.Rows[rowIndexLocal].Cells[7].Value) + "$";
            }
            else
            {
                pictureBox1.Image = Image.FromFile(@"Car.png");
                pictureBox2.Image = Image.FromFile(@"UserPicture.png");

                label9.Text = " ";
                label10.Text = " ";
                label11.Text = " ";
                label12.Text = " ";
                label13.Text = " ";
                label14.Text = " ";
                label15.Text = " ";
                label16.Text = " ";
            }

        }

        private void DataGridView1_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            pictureBox1.Image.Dispose();
            pictureBox2.Image.Dispose();
            rowIndex = dataGridView1.CurrentCell.RowIndex;

            string CodCar = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[2].Value);
            string CodClient = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[1].Value);

            pictureBox1.Image = GetPhotoCar(Convert.ToInt32(CodCar.Split(' ').Last()));
            pictureBox2.Image = GetPhotoClient(Convert.ToInt32(CodClient.Split(' ').Last()));

            label9.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[0].Value);
            label10.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[1].Value);
            label11.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[2].Value);
            label12.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[3].Value);
            label13.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[4].Value);
            label14.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[5].Value);
            label15.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[6].Value);
            label16.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[7].Value) + "$";
        }

        private Image GetPhotoCar(int Cod_Car)
        {
            List<byte[]> iScreen = new List<byte[]>();
            using (SqlConnection sqlConnection = new SqlConnection(@"Data Source=.\SQLEXPRESS;Initial Catalog=CarRent;Integrated Security=True"))
            {
                SqlCommand command = new SqlCommand("Select ImageData From Cars Where Cod_Car = @Cod_Car", sqlConnection);
                sqlConnection.Open();

                SqlParameter param = new SqlParameter
                {
                    ParameterName = "@Cod_Car",
                    Value = Cod_Car,
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
                return Bitmap.FromFile(@"Car.png");
            }

        }

        private Image GetPhotoClient(int LocalIndex)
        {
            List<byte[]> iScreen = new List<byte[]>();
            using (SqlConnection sqlConnection = new SqlConnection(@"Data Source=.\SQLEXPRESS;Initial Catalog=CarRent;Integrated Security=True"))
            {
                SqlCommand command = new SqlCommand("Select ImageData From Clients Where Cod_Client = @Cod_Client", sqlConnection);
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


        private void Button3_Click(object sender, EventArgs e)
        {
            if(dataGridView1.Rows.Count!=0)
            using (AreYouSure areYouSure = new AreYouSure())
            {
                if (areYouSure.ShowDialog() == DialogResult.OK)
                {
                    using (SqlConnection sqlConnection = new SqlConnection(@"Data Source=.\SQLEXPRESS;Initial Catalog=CarRent;Integrated Security=True"))
                    {
                        sqlConnection.Open();

                        SqlCommand command = new SqlCommand("DeleteContract", sqlConnection)
                        {
                            CommandType = CommandType.StoredProcedure
                        };

                        SqlParameter nameParam = new SqlParameter
                        {
                            ParameterName = "@Cod_Contract",
                            Value = dataGridView1.Rows[rowIndex].Cells[0].Value
                        };

                        command.Parameters.Add(nameParam);
                        command.ExecuteScalar();

                        sqlConnection.Close();
                        DataGridView1_Refresh(0);
                    }
                }

            }
        }

        private void button3_Click_1(object sender, EventArgs e)
        {
            DataGridView1_Refresh(0);
            comboBox1.SelectedIndex = -1;
            comboBox2.SelectedIndex = -1;
            comboBox3.SelectedIndex = -1;
            checkBox1.Checked = false;
            checkBox2.Checked = false;
            checkBox3.Checked = false;
        }


        private void button1_Click(object sender, EventArgs e)
        {
            if (comboBox1.SelectedIndex != -1 ||
                comboBox2.SelectedIndex != -1 ||
                comboBox3.SelectedIndex != -1 ||
                checkBox1.Checked || checkBox2.Checked || checkBox3.Checked)
            {
                string car = comboBox1.Text;
                string client = comboBox2.Text;
                string worker = comboBox3.Text;

                using (SqlConnection sqlConnection = new SqlConnection(@"Data Source=.\SQLEXPRESS;Initial Catalog=CarRent;Integrated Security=True"))
                {
                    sqlConnection.Open();

                    SqlCommand command = new SqlCommand("Select * From ContractData", sqlConnection);

                    if (!checkBox1.Checked && !checkBox2.Checked && !checkBox3.Checked)
                    {
                        command = new SqlCommand("Select * From ContractData Where ClientInfo like '%" + client + "%' and Car like '%" + car + "%' and Worker like '%" + worker + "%'", sqlConnection);
                    }
                    if (checkBox1.Checked && checkBox2.Checked && checkBox3.Checked)
                    {
                         command = new SqlCommand("Select * From ContractData Where ClientInfo like '%"+client+ "%' and Car like '%" + car+ "%' and Worker like '%" + worker+"%'", sqlConnection);
                    }
                    if (checkBox1.Checked && checkBox2.Checked && checkBox3.Checked == false)
                    {
                         command = new SqlCommand("Select * From ContractData Where ClientInfo like '%" + client + "%' and Car like '%" + car + "%' and Worker like '%" + worker + "%' and Convert(datetime,LastDayOrder,104) <Convert(datetime, '" + DateTime.Now.ToString("dd.MM.yyyy") + "',104) or Convert(datetime,LastDayOrder,104)>=Convert(datetime, '" + DateTime.Now.ToString("dd.MM.yyyy") + "',104) and Convert(datetime,FirstDayOrder,104)<=Convert(datetime, '" + DateTime.Now.ToString("dd.MM.yyyy") + "',104)", sqlConnection);
                    }
                    if (checkBox1.Checked && checkBox2.Checked==false && checkBox3.Checked)
                    {
                         command = new SqlCommand("Select * From ContractData Where ClientInfo like '%" + client + "%' and Car like '%" + car + "%' and Worker like '%" + worker + "%' and Convert(datetime,LastDayOrder,104) <Convert(datetime, '" + DateTime.Now.ToString("dd.MM.yyyy") + "',104) or Convert(datetime,FirstDayOrder,104) > Convert(datetime, '" + DateTime.Now.ToString("dd.MM.yyyy") + "',104)", sqlConnection);
                    }
                    if (checkBox1.Checked==false && checkBox2.Checked && checkBox3.Checked)
                    {
                         command = new SqlCommand("Select * From ContractData Where ClientInfo like '%" + client + "%' and Car like '%" + car + "%' and Worker like '%" + worker + "%' and Convert(datetime,LastDayOrder,104) >=Convert(datetime, '" + DateTime.Now.ToString("dd.MM.yyyy") + "',104)", sqlConnection);
                    }
                    if (checkBox1.Checked && checkBox2.Checked==false && checkBox3.Checked==false)
                    {
                         command = new SqlCommand("Select * From ContractData Where ClientInfo like '%" + client + "%' and Car like '%" + car + "%' and Worker like '%" + worker + "%' and Convert(datetime,LastDayOrder,104) <Convert(datetime, '" + DateTime.Now.ToString("dd.MM.yyyy") + "',104)", sqlConnection);
                    }
                    if (checkBox1.Checked==false && checkBox2.Checked==false && checkBox3.Checked)
                    {
                         command = new SqlCommand("Select * From ContractData Where ClientInfo like '%" + client + "%' and Car like '%" + car + "%' and Worker like '%" + worker + "%' and Convert(datetime,FirstDayOrder,104) >Convert(datetime, '" + DateTime.Now.ToString("dd.MM.yyyy") + "',104)", sqlConnection);
                    }
                    if (checkBox1.Checked == false && checkBox2.Checked && checkBox3.Checked == false)
                    {
                        command = new SqlCommand("Select * From ContractData Where ClientInfo like '%" + client + "%' and Car like '%" + car + "%' and Worker like '%" + worker + "%' and Convert(datetime,LastDayOrder,104)>=Convert(datetime, '" + DateTime.Now.ToString("dd.MM.yyyy") + "',104) and Convert(datetime,FirstDayOrder,104)<=Convert(datetime, '" + DateTime.Now.ToString("dd.MM.yyyy") + "',104)", sqlConnection);
                    }

                    SqlDataAdapter sqlDataAdapter = new SqlDataAdapter(command);
                    DataTable dtRecorder = new DataTable();
                    sqlDataAdapter.Fill(dtRecorder);
                    dataGridView1.DataSource = dtRecorder;
                    sqlConnection.Close();

                    if (dataGridView1.Rows.Count > 0)
                    {
                        string CodCar = Convert.ToString(dataGridView1.Rows[0].Cells[2].Value);
                        string CodClient = Convert.ToString(dataGridView1.Rows[0].Cells[1].Value);

                        pictureBox1.Image = GetPhotoCar(Convert.ToInt32(CodCar.Split(' ').Last()));
                        pictureBox2.Image = GetPhotoClient(Convert.ToInt32(CodClient.Split(' ').Last()));

                        label9.Text = Convert.ToString(dataGridView1.Rows[0].Cells[0].Value);
                        label10.Text = Convert.ToString(dataGridView1.Rows[0].Cells[1].Value);
                        label11.Text = Convert.ToString(dataGridView1.Rows[0].Cells[2].Value);
                        label12.Text = Convert.ToString(dataGridView1.Rows[0].Cells[3].Value);
                        label13.Text = Convert.ToString(dataGridView1.Rows[0].Cells[4].Value);
                        label14.Text = Convert.ToString(dataGridView1.Rows[0].Cells[5].Value);
                        label15.Text = Convert.ToString(dataGridView1.Rows[0].Cells[6].Value);
                        label16.Text = Convert.ToString(dataGridView1.Rows[0].Cells[7].Value) + "$";
                    }
                    else
                    {
                        pictureBox1.Image = Image.FromFile(@"Car.png");
                        pictureBox2.Image = Image.FromFile(@"UserPicture.png");

                        label9.Text = " ";
                        label10.Text = " ";
                        label11.Text = " ";
                        label12.Text = " ";
                        label13.Text = " ";
                        label14.Text = " ";
                        label15.Text = " ";
                        label16.Text = " ";
                    }

                }
            }
        }

        

        private void checkBox2_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void checkBox3_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void checkBox4_CheckedChanged(object sender, EventArgs e)
        {

        }
    }
}
