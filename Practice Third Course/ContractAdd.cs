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
    public partial class ContractAdd : UserControl
    {
        int price = 0;
        List<DateTime> FirstDate;
        List<DateTime> LastDate;

        public ContractAdd()
        {
            InitializeComponent();
            dateTimePicker1.MinDate = DateTime.Now.Date;
            dateTimePicker2.MinDate = DateTime.Now.Date;
            comboBox1.Select();

            using (SqlConnection sqlConnection = new SqlConnection(@"Data Source=.\SQLEXPRESS;Initial Catalog=CarRent;Integrated Security=True"))
            {
                SqlCommand command = new SqlCommand("Select Concat(Marka,' ', Car_Model, ' ', Car_Gos_ID,' ',Cod_Car) as Car from AllInfoCar Where NameStatus = 'Свободна' or NameStatus = 'Занята'", sqlConnection);
                sqlConnection.Open();

                DataTable table = new DataTable();
                SqlDataAdapter sqlDataAdapter = new SqlDataAdapter(command);
                sqlDataAdapter.Fill(table);
                comboBox1.DataSource = table;
                comboBox1.DisplayMember = "Car";
                comboBox1.SelectedIndex = -1;

                command = new SqlCommand("Select Concat(Client_Name,' ', Client_Surname,' ', Cod_Client) as Client from Clients Where Cod_Client not in (Select Cod_Client From Contracts Where Convert(DATE,LastDayOrder,104)>=Convert(date,GETDATE(),104)) or (Clients.Cod_Client not in (Select Cod_Client From Contracts))", sqlConnection);

                table = new DataTable();
                sqlDataAdapter = new SqlDataAdapter(command);
                sqlDataAdapter.Fill(table);
                comboBox2.DataSource = table;
                comboBox2.DisplayMember = "Client";
                comboBox2.SelectedIndex = -1;
                sqlConnection.Close();

                command = new SqlCommand("Execute InsertStatusCar", sqlConnection);
                sqlConnection.Open();
                command.ExecuteScalar();
                sqlConnection.Close();
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            label4.Visible = false;

            try
            {
                if (comboBox1.SelectedIndex == -1)
                    throw new Exception("Вы не выбрали автомобиль");

                if (comboBox2.SelectedIndex == -1)
                    throw new Exception("Вы не выбрали клиента");

                for(int i=0;i<LastDate.Count;i++)
                {
                    if(dateTimePicker1.Value.Date >= FirstDate[i] && dateTimePicker1.Value.Date <= LastDate[i])
                        throw new Exception("Первый день аренды входит в дату другой аренды");

                    if (dateTimePicker2.Value.Date >= FirstDate[i] && dateTimePicker2.Value.Date <= LastDate[i])
                        throw new Exception("Последний день аренды входит в дату другой аренды");

                    if (dateTimePicker1.Value.Date <= FirstDate[i] && dateTimePicker2.Value.Date >= LastDate[i])
                        throw new Exception("В дату аренды включена другая дата аренды");

                }

                using (SqlConnection sqlConnection = new SqlConnection(@"Data Source=.\SQLEXPRESS;Initial Catalog=CarRent;Integrated Security=True"))
                {
                    sqlConnection.Open();

                    SqlCommand command = new SqlCommand("InsertContract", sqlConnection)
                    {
                        CommandType = System.Data.CommandType.StoredProcedure
                    };

                    SqlParameter Cod_Client = new SqlParameter
                    {
                        ParameterName = "@Cod_Client",
                        Value = comboBox2.Text.Split(' ').Last()
                    };
                    command.Parameters.Add(Cod_Client);

                    SqlParameter Cod_Car = new SqlParameter
                    {
                        ParameterName = "@Cod_Car",
                        Value = comboBox1.Text.Split(' ').Last()
                    };
                    command.Parameters.Add(Cod_Car);

                    SqlParameter Cod_Worker = new SqlParameter
                    {
                        ParameterName = "@Cod_Worker",
                        Value = Worker.user.Cod_Worker
                    };
                    command.Parameters.Add(Cod_Worker);

                    SqlParameter DateOfOrder = new SqlParameter
                    {
                        ParameterName = "@DateOfOrder",
                        Value = DateTime.Now.Date.ToString("dd.MM.yyyy")
                    };
                    command.Parameters.Add(DateOfOrder);

                    SqlParameter FirstDayOrder = new SqlParameter
                    {
                        ParameterName = "@FirstDayOrder",
                        Value = dateTimePicker1.Value.ToString("dd.MM.yyyy")
                    };
                    command.Parameters.Add(FirstDayOrder);

                    SqlParameter LastDayOrder = new SqlParameter
                    {
                        ParameterName = "@LastDayOrder",
                        Value = dateTimePicker2.Value.ToString("dd.MM.yyyy")
                    };
                    command.Parameters.Add(LastDayOrder);

                    SqlParameter TotalPrice = new SqlParameter
                    {
                        ParameterName = "@TotalPrice",
                        Value = GetPrice() * ((dateTimePicker2.Value.Date - dateTimePicker1.Value.Date).TotalDays + 1)
                    };
                    command.Parameters.Add(TotalPrice);

                    command.ExecuteScalar();
                    sqlConnection.Close();
                }

                comboBox1.SelectedIndex = -1;
                comboBox2.SelectedIndex = -1;
                richTextBox1.Text = "";
                dateTimePicker1.Value = DateTime.Now.Date;
                dateTimePicker2.Value = DateTime.Now.Date;
                pictureBox1.Image = Image.FromFile(@"Car.png");
                pictureBox2.Image = Image.FromFile(@"UserPicture.png");
                UpdateData();

                using (ContractHasBeenAddedcs contractHasBeenAddedcs = new ContractHasBeenAddedcs())
                {
                    if (contractHasBeenAddedcs.ShowDialog() == DialogResult.OK)
                    {

                    }
                }
            }
            catch (Exception ex)
            {
                label4.Visible = true;
                label4.Text = ex.Message;
            }
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

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            richTextBox1.Text = "";
            if (comboBox1.SelectedIndex != -1)
                pictureBox1.Image = GetPhotoCar(Convert.ToInt32(comboBox1.Text.Split(' ').Last()));

            if (comboBox1.SelectedIndex == -1)
            {
                pictureBox1.Image = Image.FromFile(@"Car.png");
            }

            label6.Text = Convert.ToString(GetPrice() * ((dateTimePicker2.Value.Date - dateTimePicker1.Value.Date).TotalDays + 1)) + "$";

            if (comboBox1.Text.Length != 0)
                Lease_Dates(Convert.ToInt32(comboBox1.Text.Split(' ').Last()));
        }


        private void Lease_Dates(int Cod_Car)
        {
            FirstDate = new List<DateTime>();
            LastDate = new List<DateTime>();
            using (SqlConnection sqlConnection = new SqlConnection(@"Data Source=.\SQLEXPRESS;Initial Catalog=CarRent;Integrated Security=True"))
            {
                SqlCommand command = new SqlCommand("Select FirstDayOrder, LastDayOrder From Contracts Where Cod_Car ='" + Cod_Car + "' and Convert(datetime,LastDayOrder,104) >=Convert(datetime, '" + DateTime.Now.ToString("dd.MM.yyyy") + "',104)", sqlConnection);
                sqlConnection.Open();
                SqlDataAdapter sqlDataAdapter = new SqlDataAdapter(command);
                DataTable dtRecorder = new DataTable();
                sqlDataAdapter.Fill(dtRecorder);
                sqlConnection.Close();

                if (dtRecorder.Rows.Count > 0)
                {
                    for (int i = 0; i < dtRecorder.Rows.Count; i++)
                    {
                        FirstDate.Add(Convert.ToDateTime(dtRecorder.Rows[i][0]));
                        LastDate.Add(Convert.ToDateTime(dtRecorder.Rows[i][1]));
                    }

                    FirstDate.Sort((x, y) => DateTime.Compare(x, y));
                    LastDate.Sort((x, y) => DateTime.Compare(x, y));


                    if(FirstDate[0]!=DateTime.Now.Date && FirstDate[0]>DateTime.Now.Date)
                    {
                        richTextBox1.Text = DateTime.Now.ToString("dd.MM.yyyy") + " - " + FirstDate[0].AddDays(-1).ToString("dd.MM.yyyy") + "\n";
                    }

                    for (int i = 0; i < LastDate.Count; i++)
                    {
                        if (i + 1 < LastDate.Count && FirstDate[i + 1].Date == LastDate[i].Date)
                            continue;
                        else if (i + 1 < LastDate.Count && FirstDate[i + 1].Date > LastDate[i].Date.AddDays(1))
                        {
                            richTextBox1.Text += LastDate[i].Date.AddDays(1).ToString("dd.MM.yyyy") + " - " + LastDate[i].Date.AddDays((FirstDate[i + 1].Date - LastDate[i].Date.AddDays(1)).Days).ToString("dd.MM.yyyy") + "\n";
                        }
                    }
                    richTextBox1.Text += LastDate.Last().Date.AddDays(1).ToString("dd.MM.yyyy") + " - ...";
                    
                }
                else
                richTextBox1.Text = DateTime.Now.Date.ToString("dd.MM.yyyy") + " - ...";
            }
        }




        private void comboBox2_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (comboBox2.SelectedIndex != -1)
                pictureBox2.Image = GetPhotoClient(Convert.ToInt32(comboBox2.Text.Split(' ').Last()));

            if (comboBox2.SelectedIndex == -1)
            {
                pictureBox2.Image = Image.FromFile(@"UserPicture.png");
            }

        }

        

        private void dateTimePicker1_ValueChanged(object sender, EventArgs e)
        {
            if(dateTimePicker2.Value.Date< dateTimePicker1.Value.Date)
            {
                DateTime dateTime = dateTimePicker1.Value.Date;
                dateTimePicker1.Value = dateTimePicker2.Value.Date;
                dateTimePicker2.Value = dateTime;
            }

            label6.Text = Convert.ToString(GetPrice() * ((dateTimePicker2.Value.Date - dateTimePicker1.Value.Date).TotalDays +1)) + "$";
        
        }

        private void dateTimePicker2_ValueChanged(object sender, EventArgs e)
        {
            if (dateTimePicker2.Value.Date < dateTimePicker1.Value.Date)
            {
                DateTime dateTime = dateTimePicker2.Value.Date;
                dateTimePicker2.Value = dateTimePicker1.Value.Date;
                dateTimePicker1.Value = dateTime;
            }

            label6.Text = Convert.ToString(GetPrice() * ((dateTimePicker2.Value.Date - dateTimePicker1.Value.Date).TotalDays + 1)) + "$";
        }

        private int GetPrice()
        {
            using (SqlConnection sqlConnection = new SqlConnection(@"Data Source=.\SQLEXPRESS;Initial Catalog=CarRent;Integrated Security=True"))
            {
                SqlCommand command = new SqlCommand("Select Price From Cars Where Cod_Car ='" + comboBox1.Text.Split(' ').Last() + "'", sqlConnection);
                sqlConnection.Open();
                price = Convert.ToInt32(command.ExecuteScalar());
                sqlConnection.Close();

            }

            return price;
        }

        protected void UpdateData()
        {
            using (SqlConnection sqlConnection = new SqlConnection(@"Data Source=.\SQLEXPRESS;Initial Catalog=CarRent;Integrated Security=True"))
            {
                SqlCommand command = new SqlCommand("Select Concat(Marka,' ', Car_Model, ' ', Car_Gos_ID,' ',Cod_Car) as Car from AllInfoCar Where NameStatus = 'Свободна' or NameStatus = 'Занята'", sqlConnection);
                sqlConnection.Open();

                DataTable table = new DataTable();
                SqlDataAdapter sqlDataAdapter = new SqlDataAdapter(command);
                sqlDataAdapter.Fill(table);
                comboBox1.DataSource = table;
                comboBox1.DisplayMember = "Car";
                comboBox1.SelectedIndex = -1;

                command = new SqlCommand("Select Concat(Client_Name,' ', Client_Surname,' ', Cod_Client) as Client from Clients Where Cod_Client not in (Select Cod_Client From Contracts Where Convert(DATE,LastDayOrder,104)>=Convert(date,GETDATE(),104)) or (Clients.Cod_Client not in (Select Cod_Client From Contracts))", sqlConnection);

                table = new DataTable();
                sqlDataAdapter = new SqlDataAdapter(command);
                sqlDataAdapter.Fill(table);
                comboBox2.DataSource = table;
                comboBox2.DisplayMember = "Client";
                comboBox2.SelectedIndex = -1;
                sqlConnection.Close();

                command = new SqlCommand("Execute InsertStatusCar", sqlConnection);
                sqlConnection.Open();
                command.ExecuteScalar();
                sqlConnection.Close();
            }
        }
    }
}
