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
    public partial class ArchiveCars : UserControl
    {
        int rowIndex = 0;
        List<string> vs = new List<string>();

        public ArchiveCars()
        {
            InitializeComponent();

            richTextBox1.BackColor = Color.White;
            richTextBox1.ReadOnly = true;
            textbox1_SetText();
            textbox4_SetText();

            using (SqlConnection sqlConnection = new SqlConnection(@"Data Source=.\SQLEXPRESS;Initial Catalog=CarRent;Integrated Security=True"))
            {
                SqlCommand command = new SqlCommand("Select Cod_Car, Car_Gos_ID, Marka, Car_Model, Color, Fuel, Transmission, NameType, Car_Num_Sit, Price From ArchiveCar", sqlConnection);
                sqlConnection.Open();
                SqlDataAdapter sqlDataAdapter = new SqlDataAdapter(command);
                DataTable dtRecorder = new DataTable();
                sqlDataAdapter.Fill(dtRecorder);
                dataGridView1.DataSource = dtRecorder;
                sqlConnection.Close();
            }

            dataGridView1.Columns[0].HeaderCell.Value = "Код";
            dataGridView1.Columns[1].HeaderCell.Value = "Номерной знак";
            dataGridView1.Columns[2].HeaderCell.Value = "Марка";
            dataGridView1.Columns[3].HeaderCell.Value = "Модель";
            dataGridView1.Columns[4].HeaderCell.Value = "Цвет";
            dataGridView1.Columns[5].HeaderCell.Value = "Тип топлива";
            dataGridView1.Columns[6].HeaderCell.Value = "Тип трансмиссии";
            dataGridView1.Columns[7].HeaderCell.Value = "Тип кузова";
            dataGridView1.Columns[8].HeaderCell.Value = "Количество мест";
            dataGridView1.Columns[9].HeaderCell.Value = "Цена";

            if (dataGridView1.Rows.Count > 0)
            {
                pictureBox2.Image = GetPhotoCar(Convert.ToInt32(dataGridView1.Rows[rowIndex].Cells[0].Value));

                label12.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[0].Value);
                label13.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[1].Value);
                label14.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[2].Value);
                label15.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[3].Value);
                label16.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[4].Value);
                label17.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[5].Value);
                label18.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[6].Value);
                label19.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[7].Value);
                label20.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[8].Value);
                label21.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[9].Value) + "$";
                GetAdditionCar(Convert.ToInt32(dataGridView1.Rows[rowIndex].Cells[0].Value));
                richTextBox1.ReadOnly = true;
            }
            else
            {
                pictureBox2.Image = Image.FromFile(@"Car.png");

                label12.Text = "";
                label13.Text = "";
                label14.Text = "";
                label15.Text = "";
                label16.Text = "";
                label17.Text = "";
                label18.Text = "";
                label19.Text = "";
                label20.Text = "";
                label21.Text = "";
            }

            dataGridView1.AllowUserToOrderColumns = false;
            dataGridView1.AllowUserToResizeColumns = false;
        }

        private Image GetPhotoCar(int LocalIndex)
        {
            List<byte[]> iScreen = new List<byte[]>();
            using (SqlConnection sqlConnection = new SqlConnection(@"Data Source=.\SQLEXPRESS;Initial Catalog=CarRent;Integrated Security=True"))
            {
                SqlCommand command = new SqlCommand("Select ImageData From ArchiveCar Where Cod_Car = @Cod_Car", sqlConnection);
                sqlConnection.Open();

                SqlParameter param = new SqlParameter
                {
                    ParameterName = "@Cod_Car",
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
                return Bitmap.FromFile(@"Car.png");
            }

        }

        private void dataGridView1_CellClick(object sender, DataGridViewCellEventArgs e)
        {

            if (dataGridView1.Rows.Count > 0)
            {
                pictureBox2.Image.Dispose();
                rowIndex = dataGridView1.CurrentCell.RowIndex;
                richTextBox1.Text = "";

                pictureBox2.Image = GetPhotoCar(Convert.ToInt32(dataGridView1.Rows[rowIndex].Cells[0].Value));

                label12.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[0].Value);
                label13.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[1].Value);
                label14.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[2].Value);
                label15.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[3].Value);
                label16.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[4].Value);
                label17.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[5].Value);
                label18.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[6].Value);
                label19.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[7].Value);
                label20.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[8].Value);
                label21.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[9].Value) + "$";
                GetAdditionCar(Convert.ToInt32(dataGridView1.Rows[rowIndex].Cells[0].Value));
                richTextBox1.ReadOnly = true;
            }
        }

        private void GetAdditionCar(int rowIndexLocal)
        {
            vs.Clear();
            richTextBox1.Text = "";
            vs = new List<string>();

            SqlConnection sqlConnection = new SqlConnection(@"Data Source=.\SQLEXPRESS;Initial Catalog=CarRent;Integrated Security=True");
            {
                SqlCommand command = new SqlCommand("Select Additionaly FROM ArchiveCar WHERE Cod_Car = '" + rowIndexLocal + "'", sqlConnection);
                sqlConnection.Open();
                SqlDataReader rd = command.ExecuteReader();

                while (rd.Read())
                {
                    vs.Add(rd["Additionaly"].ToString());
                }

                sqlConnection.Close();
            }

            foreach (var a in vs)
            {
                richTextBox1.Text += a;
            }

            if (richTextBox1.TextLength > 0)
            {

            }
            else
            {
                richTextBox1.Text = "Никаких дополнений";
            }
        }

        private void DataGridView1_Refresh(int rowIndexLocal)
        {
            pictureBox2.Image.Dispose();
            rowIndex = 0;

            using (SqlConnection sqlConnection = new SqlConnection(@"Data Source=.\SQLEXPRESS;Initial Catalog=CarRent;Integrated Security=True"))
            {
                SqlCommand command = new SqlCommand("Select Cod_Car, Car_Gos_ID, Marka, Car_Model, Color, Fuel, Transmission, NameType, Car_Num_Sit, Price From ArchiveCar", sqlConnection);
                sqlConnection.Open();
                SqlDataAdapter sqlDataAdapter = new SqlDataAdapter(command);
                DataTable dtRecorder = new DataTable();
                sqlDataAdapter.Fill(dtRecorder);
                dataGridView1.DataSource = dtRecorder;
                sqlConnection.Close();
            }

            richTextBox1.Text = "";

            if (dataGridView1.Rows.Count > 0)
            {
                pictureBox2.Image = GetPhotoCar(Convert.ToInt32(dataGridView1.Rows[rowIndex].Cells[0].Value));

                label12.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[0].Value);
                label13.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[1].Value);
                label14.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[2].Value);
                label15.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[3].Value);
                label16.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[4].Value);
                label17.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[5].Value);
                label18.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[6].Value);
                label19.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[7].Value);
                label20.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[8].Value);
                label21.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[9].Value) + "$";
                GetAdditionCar(Convert.ToInt32(dataGridView1.Rows[rowIndex].Cells[0].Value));
            }
            else
            {
                pictureBox2.Image = Image.FromFile(@"Car.png");

                label12.Text = "";
                label13.Text = "";
                label14.Text = "";
                label15.Text = "";
                label16.Text = "";
                label17.Text = "";
                label18.Text = "";
                label19.Text = "";
                label20.Text = "";
                label21.Text = "";
                richTextBox1.Text = "";
            }

            dataGridView1.AllowUserToOrderColumns = false;
            dataGridView1.AllowUserToResizeColumns = false;
        }


        private void pictureBox1_Click(object sender, EventArgs e)
        {
            panel2.Hide();
            panel3.Show();

        }

        private void pictureBox3_Click(object sender, EventArgs e)
        {
            panel2.Show();
            panel3.Hide();
        }

        protected void textbox1_SetText()
        {
            textBox1.Text = "Номерной знак";
            textBox1.ForeColor = Color.Gray;
        }

        private void textBox1_Enter(object sender, EventArgs e)
        {
            if (textBox1.ForeColor == Color.Black)
                return;
            textBox1.Text = "";
            textBox1.ForeColor = Color.Black;
        }

        private void textBox1_Leave(object sender, EventArgs e)
        {
            if (textBox1.Text.Trim() == "")
                textbox1_SetText();
        }

        protected void textbox4_SetText()
        {
            textBox4.Text = "Модель";
            textBox4.ForeColor = Color.Gray;
        }

        private void textBox4_Leave(object sender, EventArgs e)
        {
            if (textBox4.Text.Trim() == "")
                textbox4_SetText();
        }

        private void textBox4_Enter(object sender, EventArgs e)
        {
            if (textBox4.ForeColor == Color.Black)
                return;
            textBox4.Text = "";
            textBox4.ForeColor = Color.Black;
        }


        private void button8_Click(object sender, EventArgs e)
        {
            comboBox9.SelectedIndex = -1;
            comboBox10.SelectedIndex = -1;
            comboBox11.SelectedIndex = -1;
            comboBox12.SelectedIndex = -1;
            comboBox13.SelectedIndex = -1;

            numericUpDown6.Value = 1;
            numericUpDown5.Value = 15;

            numericUpDown3.Value = 10;
            numericUpDown4.Value = 500;
            DataGridView1_Refresh(0);
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            if (textBox1.TextLength == 0 && textBox4.TextLength == 0) DataGridView1_Refresh(0);
        }

        private void textBox4_TextChanged(object sender, EventArgs e)
        {
            if (textBox1.TextLength == 0 && textBox4.TextLength == 0) DataGridView1_Refresh(0);
        }


        private void button1_Click(object sender, EventArgs e)
        {
            pictureBox2.Image.Dispose();
            richTextBox1.Text = "";

            if (textBox1.Text == "Номерной знак") textBox1.Text = "";
            if (textBox4.Text == "Модель") textBox4.Text = "";

            if (textBox1.TextLength > 0 || textBox4.TextLength > 0 || comboBox9.SelectedIndex != -1 || comboBox10.SelectedIndex != -1 ||
                comboBox11.SelectedIndex != -1 || comboBox12.SelectedIndex != -1 || comboBox13.SelectedIndex != -1 ||
                numericUpDown6.Value != 1 || numericUpDown5.Value != 15 || numericUpDown3.Value != 10 || numericUpDown4.Value != 500)
            {

                using (SqlConnection sqlConnection = new SqlConnection(@"Data Source=.\SQLEXPRESS;Initial Catalog=CarRent;Integrated Security=True"))
                {
                    SqlCommand command = new SqlCommand("Select Cod_Car, Car_Gos_ID, Marka, Car_Model, Color, Fuel, Transmission, NameType, Car_Num_Sit, Price From ArchiveCar where Car_Gos_ID LIKE '%" + textBox1.Text + "%' and Car_model like '%" + textBox4.Text + "%' and Marka like '%" + comboBox13.Text + "%' and Color like '%" + comboBox12.Text + "%' and Fuel like '%" + comboBox11.Text + "%' and Transmission like '%" + comboBox10.Text + "%' and NameType like '%" + comboBox9.Text + "%' and Price>=" + numericUpDown3.Value + " and Price<=" + numericUpDown4.Value + " and Car_Num_Sit >=" + numericUpDown6.Value + " and Car_Num_Sit <=" + numericUpDown5.Value + "", sqlConnection);

                    sqlConnection.Open();
                    SqlDataAdapter sqlDataAdapter = new SqlDataAdapter(command);
                    DataTable dtRecorder = new DataTable();
                    sqlDataAdapter.Fill(dtRecorder);
                    sqlConnection.Close();
                    dataGridView1.DataSource = dtRecorder;

                    if (dataGridView1.Rows.Count > 0)
                    {
                        rowIndex = 0;
                        pictureBox2.Image = GetPhotoCar(Convert.ToInt32(dataGridView1.Rows[rowIndex].Cells[0].Value));

                        label12.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[0].Value);
                        label13.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[1].Value);
                        label14.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[2].Value);
                        label15.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[3].Value);
                        label16.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[4].Value);
                        label17.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[5].Value);
                        label18.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[6].Value);
                        label19.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[7].Value);
                        label20.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[8].Value);
                        label21.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[9].Value) + "$";
                        GetAdditionCar(Convert.ToInt32(dataGridView1.Rows[rowIndex].Cells[0].Value));
                        richTextBox1.ReadOnly = true;
                    }
                    else
                    {
                        pictureBox2.Image = Image.FromFile(@"Car.png");

                        label12.Text = "";
                        label13.Text = "";
                        label14.Text = "";
                        label15.Text = "";
                        label16.Text = "";
                        label17.Text = "";
                        label18.Text = "";
                        label19.Text = "";
                        label20.Text = "";
                        label21.Text = "";
                        richTextBox1.Text = "";
                    }

                    dataGridView1.AllowUserToOrderColumns = false;
                    dataGridView1.AllowUserToResizeColumns = false;
                }
            }
        }

        private void button7_Click(object sender, EventArgs e)
        {
            button1_Click(sender, e);
        }

        private void ArchiveCars_Load(object sender, EventArgs e)
        {
            using (SqlConnection sqlConnection = new SqlConnection(@"Data Source=.\SQLEXPRESS;Initial Catalog=CarRent;Integrated Security=True"))
            {
                SqlCommand command = new SqlCommand("Select Marka from Car_Marka", sqlConnection);
                sqlConnection.Open();

                DataTable table = new DataTable();
                DataTable table2 = new DataTable();
                SqlDataAdapter sqlDataAdapter = new SqlDataAdapter(command);
                sqlDataAdapter.Fill(table);
                comboBox13.DataSource = table;
                comboBox13.DisplayMember = "Marka";
                comboBox13.SelectedIndex = -1;

                command = new SqlCommand("Select Color from Car_Color", sqlConnection);
                table = new DataTable();
                sqlDataAdapter = new SqlDataAdapter(command);
                sqlDataAdapter.Fill(table);
                comboBox12.DataSource = table;
                comboBox12.DisplayMember = "Color";
                comboBox12.SelectedIndex = -1;

                command = new SqlCommand("Select Fuel from Car_Fuel", sqlConnection);
                table = new DataTable();
                sqlDataAdapter = new SqlDataAdapter(command);
                sqlDataAdapter.Fill(table);
                comboBox11.DataSource = table;
                comboBox11.DisplayMember = "Fuel";
                comboBox11.SelectedIndex = -1;

                command = new SqlCommand("Select Transmission from Car_Transmission", sqlConnection);
                table = new DataTable();
                sqlDataAdapter = new SqlDataAdapter(command);
                sqlDataAdapter.Fill(table);
                comboBox10.DataSource = table;
                comboBox10.DisplayMember = "Transmission";
                comboBox10.SelectedIndex = -1;

                command = new SqlCommand("Select NameType from Car_Type", sqlConnection);
                table = new DataTable();
                sqlDataAdapter = new SqlDataAdapter(command);
                sqlDataAdapter.Fill(table);
                comboBox9.DataSource = table;
                comboBox9.DisplayMember = "NameType";
                comboBox9.SelectedIndex = -1;


                sqlConnection.Close();
            }
        }

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }
    }
}
