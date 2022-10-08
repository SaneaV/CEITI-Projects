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
    public partial class ArchiveContracts : UserControl
    {
        int rowIndex = 0;
        public ArchiveContracts()
        {
            InitializeComponent();

            using (SqlConnection sqlConnection = new SqlConnection(@"Data Source=.\SQLEXPRESS;Initial Catalog=CarRent;Integrated Security=True"))
            {
                SqlCommand command = new SqlCommand("Select * From ArchiveContracts", sqlConnection);
                sqlConnection.Open();
                SqlDataAdapter sqlDataAdapter = new SqlDataAdapter(command);
                DataTable dtRecorder = new DataTable();
                sqlDataAdapter.Fill(dtRecorder);
                dataGridView1.DataSource = dtRecorder;
                sqlConnection.Close();


                command = new SqlCommand("Select distinct Car from ArchiveContracts", sqlConnection);
                sqlConnection.Open();

                DataTable table = new DataTable();
                sqlDataAdapter = new SqlDataAdapter(command);
                sqlDataAdapter.Fill(table);
                comboBox1.DataSource = table;
                comboBox1.DisplayMember = "Car";
                comboBox1.SelectedIndex = -1;

                command = new SqlCommand("Select distinct Client from ArchiveContracts", sqlConnection);

                table = new DataTable();
                sqlDataAdapter = new SqlDataAdapter(command);
                sqlDataAdapter.Fill(table);
                comboBox2.DataSource = table;
                comboBox2.DisplayMember = "Client";
                comboBox2.SelectedIndex = -1;
                sqlConnection.Close();

                command = new SqlCommand("Select distinct Worker from ArchiveContracts", sqlConnection);

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


                label9.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[0].Value);
                label10.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[1].Value);
                label11.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[2].Value);
                label12.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[3].Value);
                label13.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[4].Value);
                label14.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[5].Value);
                label15.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[6].Value);
                label16.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[7].Value) + "$";
            }
            else
            {

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
            rowIndex = 0;

            using (SqlConnection sqlConnection = new SqlConnection(@"Data Source=.\SQLEXPRESS;Initial Catalog=CarRent;Integrated Security=True"))
            {
                SqlCommand command = new SqlCommand("Select * From ArchiveContracts", sqlConnection);
                sqlConnection.Open();
                SqlDataAdapter sqlDataAdapter = new SqlDataAdapter(command);
                DataTable dtRecorder = new DataTable();
                sqlDataAdapter.Fill(dtRecorder);
                dataGridView1.DataSource = dtRecorder;
                sqlConnection.Close();

            }

            if (dataGridView1.Rows.Count > 0)
            {
                string CodCar = Convert.ToString(dataGridView1.Rows[rowIndexLocal].Cells[2].Value);
                string CodClient = Convert.ToString(dataGridView1.Rows[rowIndexLocal].Cells[1].Value);

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
            rowIndex = dataGridView1.CurrentCell.RowIndex;

            string CodCar = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[2].Value);
            string CodClient = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[1].Value);

            label9.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[0].Value);
            label10.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[1].Value);
            label11.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[2].Value);
            label12.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[3].Value);
            label13.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[4].Value);
            label14.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[5].Value);
            label15.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[6].Value);
            label16.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[7].Value) + "$";
        }

        private void button3_Click(object sender, EventArgs e)
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

                    SqlCommand command = new SqlCommand("Select * From ArchiveContracts", sqlConnection);

                    if (!checkBox1.Checked && !checkBox2.Checked && !checkBox3.Checked)
                    {
                        command = new SqlCommand("Select * From ArchiveContracts Where Client like '%" + client + "%' and Car like '%" + car + "%' and Worker like '%" + worker + "%'", sqlConnection);
                    }
                    if (checkBox1.Checked && checkBox2.Checked && checkBox3.Checked)
                    {
                        command = new SqlCommand("Select * From ArchiveContracts Where Client like '%" + client + "%' and Car like '%" + car + "%' and Worker like '%" + worker + "%'", sqlConnection);
                    }
                    if (checkBox1.Checked && checkBox2.Checked && checkBox3.Checked == false)
                    {
                        command = new SqlCommand("Select * From ArchiveContracts Where Client like '%" + client + "%' and Car like '%" + car + "%' and Worker like '%" + worker + "%' and Convert(datetime,LastDayOrder,104) <Convert(datetime, '" + DateTime.Now.ToString("dd.MM.yyyy") + "',104) or Convert(datetime,LastDayOrder,104)>=Convert(datetime, '" + DateTime.Now.ToString("dd.MM.yyyy") + "',104) and Convert(datetime,FirstDayOrder,104)<=Convert(datetime, '" + DateTime.Now.ToString("dd.MM.yyyy") + "',104)", sqlConnection);
                    }
                    if (checkBox1.Checked && checkBox2.Checked == false && checkBox3.Checked)
                    {
                        command = new SqlCommand("Select * From ArchiveContracts Where Client like '%" + client + "%' and Car like '%" + car + "%' and Worker like '%" + worker + "%' and Convert(datetime,LastDayOrder,104) <Convert(datetime, '" + DateTime.Now.ToString("dd.MM.yyyy") + "',104) or Convert(datetime,FirstDayOrder,104) > Convert(datetime, '" + DateTime.Now.ToString("dd.MM.yyyy") + "',104)", sqlConnection);
                    }
                    if (checkBox1.Checked == false && checkBox2.Checked && checkBox3.Checked)
                    {
                        command = new SqlCommand("Select * From ArchiveContracts Where Client like '%" + client + "%' and Car like '%" + car + "%' and Worker like '%" + worker + "%' and Convert(datetime,LastDayOrder,104) >=Convert(datetime, '" + DateTime.Now.ToString("dd.MM.yyyy") + "',104)", sqlConnection);
                    }
                    if (checkBox1.Checked && checkBox2.Checked == false && checkBox3.Checked == false)
                    {
                        command = new SqlCommand("Select * From ArchiveContracts Where Client like '%" + client + "%' and Car like '%" + car + "%' and Worker like '%" + worker + "%' and Convert(datetime,LastDayOrder,104) <Convert(datetime, '" + DateTime.Now.ToString("dd.MM.yyyy") + "',104)", sqlConnection);
                    }
                    if (checkBox1.Checked == false && checkBox2.Checked == false && checkBox3.Checked)
                    {
                        command = new SqlCommand("Select * From ArchiveContracts Where Client like '%" + client + "%' and Car like '%" + car + "%' and Worker like '%" + worker + "%' and Convert(datetime,FirstDayOrder,104) >Convert(datetime, '" + DateTime.Now.ToString("dd.MM.yyyy") + "',104)", sqlConnection);
                    }
                    if (checkBox1.Checked == false && checkBox2.Checked && checkBox3.Checked == false)
                    {
                        command = new SqlCommand("Select * From ArchiveContracts Where Client like '%" + client + "%' and Car like '%" + car + "%' and Worker like '%" + worker + "%' and Convert(datetime,LastDayOrder,104)>=Convert(datetime, '" + DateTime.Now.ToString("dd.MM.yyyy") + "',104) and Convert(datetime,FirstDayOrder,104)<=Convert(datetime, '" + DateTime.Now.ToString("dd.MM.yyyy") + "',104)", sqlConnection);
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
    }
}
