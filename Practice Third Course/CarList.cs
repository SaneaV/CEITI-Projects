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
using System.Drawing.Imaging;

namespace CarRent
{
    public partial class CarList : UserControl
    {
        int rowIndex = 0;
        string pPicture = @"Car.png";
        bool photoChanged = false;
        List<string> vs = new List<string>();
        string OldNumber;
        List<string> ListAddition = new List<string>();

        public CarList()
        {
            InitializeComponent();
            comboBox1.Visible = false;
            textBox2.Visible = false;
            textBox3.Visible = false;
            comboBox2.Visible = false;
            comboBox3.Visible = false;
            comboBox4.Visible = false;
            comboBox5.Visible = false;
            numericUpDown1.Visible = false;
            numericUpDown2.Visible = false;
            comboBox6.Visible = false;
            label23.Visible = false;

            button2.Visible = false;
            button6.Visible = false;
            button4.Visible = false;
            button3.Visible = false;

            if (Worker.user.Cod_Position == 1 || Worker.user.Cod_Position == 3) checkBox1.Visible = true;
            else checkBox1.Visible = false;

            richTextBox1.BackColor = Color.White;
            richTextBox2.BackColor = Color.White;
            richTextBox1.ReadOnly = true;
            textbox1_SetText();
            textbox4_SetText();

            using (SqlConnection sqlConnection = new SqlConnection(@"Data Source=.\SQLEXPRESS;Initial Catalog=CarRent;Integrated Security=True"))
            {
                SqlCommand command = new SqlCommand("Select Cod_Car, Car_Gos_ID, Marka, Car_Model, Color, Fuel, Transmission, NameType, Car_Num_Sit, Price, NameStatus From AllInfoCar", sqlConnection);
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
            dataGridView1.Columns[10].HeaderCell.Value = "Статус";

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
                label22.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[10].Value);
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
                label22.Text = "";
            }

            dataGridView1.AllowUserToOrderColumns = false;
            dataGridView1.AllowUserToResizeColumns = false;
        }

        private Image GetPhotoCar(int LocalIndex)
        {
            List<byte[]> iScreen = new List<byte[]>();
            using (SqlConnection sqlConnection = new SqlConnection(@"Data Source=.\SQLEXPRESS;Initial Catalog=CarRent;Integrated Security=True"))
            {
                SqlCommand command = new SqlCommand("Select ImageData From Cars Where Cod_Car = @Cod_Car", sqlConnection);
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
                label22.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[10].Value);
                GetAdditionCar(Convert.ToInt32(dataGridView1.Rows[rowIndex].Cells[0].Value));
                richTextBox1.ReadOnly = true;

                checkBox1.Checked = false;
            }
        }

        private void checkBox1_CheckedChanged(object sender, EventArgs e)
        {
            if (checkBox1.Checked == true && dataGridView1.Rows.Count > 0)
            {
                OldNumber = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[3].Value);
                label12.Visible = false;
                label13.Visible = false;
                label14.Visible = false;
                label15.Visible = false;
                label16.Visible = false;
                label17.Visible = false;
                label18.Visible = false;
                label19.Visible = false;
                label20.Visible = false;
                label21.Visible = false;
                label22.Visible = false;

                comboBox1.Visible = true;
                comboBox1.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[2].Value);
                textBox2.Visible = true;
                textBox2.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[3].Value);
                textBox3.Visible = true;
                textBox3.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[1].Value);
                comboBox2.Visible = true;
                comboBox2.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[4].Value);
                comboBox3.Visible = true;
                comboBox3.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[5].Value);
                comboBox4.Visible = true;
                comboBox4.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[6].Value);
                comboBox5.Visible = true;
                comboBox5.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[7].Value);
                numericUpDown1.Visible = true;
                numericUpDown1.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[8].Value);
                numericUpDown2.Visible = true;
                numericUpDown2.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[9].Value);
                comboBox6.Visible = true;
                comboBox6.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[10].Value);
                richTextBox1.ReadOnly = false;

                button2.Visible = true;
                button6.Visible = true;
                button4.Visible = true;
                if (Worker.user.Cod_Worker == "1")
                    button3.Visible = true;
            }
            else
            {
                label23.Visible = false;

                label12.Visible = true;
                label13.Visible = true;
                label14.Visible = true;
                label15.Visible = true;
                label16.Visible = true;
                label17.Visible = true;
                label18.Visible = true;
                label19.Visible = true;
                label20.Visible = true;
                label21.Visible = true;
                label22.Visible = true;

                comboBox1.Visible = false;
                comboBox1.Text = "";
                textBox2.Visible = false;
                textBox2.Text = "";
                textBox3.Visible = false;
                textBox3.Text = "";
                comboBox2.Visible = false;
                comboBox2.Text = "";
                comboBox3.Visible = false;
                comboBox3.Text = "";
                comboBox4.Visible = false;
                comboBox4.Text = "";
                comboBox5.Visible = false;
                comboBox5.Text = "";
                numericUpDown1.Visible = false;
                comboBox5.Text = "";
                numericUpDown2.Visible = false;
                comboBox5.Text = "";
                comboBox6.Visible = false;
                comboBox6.Text = "";

                button2.Visible = false;
                button6.Visible = false;
                button4.Visible = false;
                if (Worker.user.Cod_Worker == "1")
                    button3.Visible = false;

                comboBox1.SelectedIndex = -1;
                comboBox2.SelectedIndex = -1;
                comboBox3.SelectedIndex = -1;
                comboBox4.SelectedIndex = -1;
                comboBox5.SelectedIndex = -1;
                comboBox6.SelectedIndex = -1;
                comboBox7.SelectedIndex = -1;
                comboBox8.SelectedIndex = -1;
                comboBox9.SelectedIndex = -1;
                comboBox10.SelectedIndex = -1;
                comboBox11.SelectedIndex = -1;
                comboBox12.SelectedIndex = -1;
                comboBox13.SelectedIndex = -1;

            }
        }

        private void GetAdditionCar(int rowIndexLocal)
        {
            vs.Clear();
            richTextBox1.Text = "";
            vs = new List<string>();

            SqlConnection sqlConnection = new SqlConnection(@"Data Source=.\SQLEXPRESS;Initial Catalog=CarRent;Integrated Security=True");
            {
                SqlCommand command = new SqlCommand("Select Additionaly FROM Car_Additionaly WHERE Cod_Car = '" + rowIndexLocal + "'", sqlConnection);
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
                richTextBox1.Text += a + ",\n";
            }

            if (richTextBox1.TextLength > 0)
                richTextBox1.Text = richTextBox1.Text.Remove(richTextBox1.Text.Length - 2, 1);
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
                SqlCommand command = new SqlCommand("Select Cod_Car, Car_Gos_ID, Marka, Car_Model, Color, Fuel, Transmission, NameType, Car_Num_Sit, Price, NameStatus From AllInfoCar", sqlConnection);
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
                label22.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[10].Value);
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
                label22.Text = "";
                richTextBox1.Text = "";
            }

            dataGridView1.AllowUserToOrderColumns = false;
            dataGridView1.AllowUserToResizeColumns = false;
        }

        private string VaryQualityLevel(string image)
        {
            using (Bitmap bmp1 = new Bitmap(image))
            {
                ImageCodecInfo jpgEncoder = GetEncoder(ImageFormat.Jpeg);
                System.Drawing.Imaging.Encoder myEncoder = System.Drawing.Imaging.Encoder.Quality;
                EncoderParameters myEncoderParameters = new EncoderParameters(1);

                EncoderParameter myEncoderParametr = new EncoderParameter(myEncoder, 20L);
                myEncoderParameters.Param[0] = myEncoderParametr;

                if (File.Exists(@"Car.jpg"))
                {
                    pPicture = @"Car.png";
                    pictureBox2.Image.Dispose();
                    File.Delete(@"Car.jpg");
                    pPicture = @"Car.jpg";
                }

                bmp1.Save(@"Car.jpg", jpgEncoder, myEncoderParameters);
                bmp1.Dispose();

                return @"Car.jpg";
            }
        }

        private ImageCodecInfo GetEncoder(ImageFormat format)
        {
            ImageCodecInfo[] codecs = ImageCodecInfo.GetImageEncoders();
            foreach (ImageCodecInfo codec in codecs)
            {
                if (codec.FormatID == format.Guid)
                {
                    return codec;
                }
            }
            return null;
        }

        private void Button4_Click(object sender, EventArgs e)
        {
            DialogResult res = openFileDialog.ShowDialog();
            if (res == DialogResult.OK)
            {
                pPicture = VaryQualityLevel(openFileDialog.FileName);
                pictureBox2.Image = Image.FromFile(pPicture);
            }
            openFileDialog.Dispose();
            photoChanged = true;
        }

        readonly OpenFileDialog openFileDialog = new OpenFileDialog
        {
            Filter = "Image files (*.jpg, *.jpeg, ) | *.jpg; *.jpeg; "
        };

        private void button2_Click(object sender, EventArgs e)
        {
            checkBox1.Checked = false;
        }

        private void button6_Click(object sender, EventArgs e)
        {
            label23.Visible = false;

            try
            {
                if(OldNumber != textBox2.Text)
                using (SqlConnection sqlConnection = new SqlConnection(@"Data Source=.\SQLEXPRESS;Initial Catalog=CarRent;Integrated Security=True"))
                {
                    SqlCommand command = new SqlCommand("Select Count(Car_Gos_ID) from Cars Where Car_Gos_ID LIKE '" + textBox1.Text + "'", sqlConnection);
                    sqlConnection.Open();
                    int Count = Convert.ToInt32(command.ExecuteScalar());
                    sqlConnection.Close();

                    if (Count != 0) throw new Exception("Машина с указанным номерным знаком уже существует в базе");
                }


                if (textBox3.Text.Length == 0)
                    throw new Exception("Поле номерного знака пустое");

                if (textBox3.Text.Length != 6)
                    throw new Exception("Поле номерного знака не соответствует размеру");

                int Number = 0;
                int Letter = 0;
                foreach (var a in textBox3.Text)
                {
                    if (Char.IsDigit(a)) Number++;
                    if (Char.IsLetter(a)) Letter++;
                }
                if (Number != 3)
                    throw new Exception("В поле номерного знака допущена ошибка цифр");

                if (Letter != 3)
                    throw new Exception("В поле номерного знака допущена ошибка букв");

                if (comboBox1.SelectedItem == null)
                    throw new Exception("Выберите марку автомобиля");

                if (textBox2.Text.Length == 0)
                    throw new Exception("Поле модели автомобиля пустое");

                if (comboBox2.SelectedItem == null)
                    throw new Exception("Выберите цвет автомобиля");

                if (comboBox3.SelectedItem == null)
                    throw new Exception("Выберите тип топлива автомобиля");

                if (comboBox4.SelectedItem == null)
                    throw new Exception("Выберите тип трансмиссии автомобиля");

                if (comboBox5.SelectedItem == null)
                    throw new Exception("Выберите тип кузова автомобиля");

                using (SqlConnection sqlConnection = new SqlConnection(@"Data Source=.\SQLEXPRESS;Initial Catalog=CarRent;Integrated Security=True"))
                {
                    SqlCommand command = new SqlCommand("Select Cod_Status From Car_Status Where Cod_Car = '" + dataGridView1.Rows[rowIndex].Cells[0].Value + "'", sqlConnection);
                    sqlConnection.Open();
                    int Status = Convert.ToInt32(command.ExecuteScalar());
                    sqlConnection.Close();

                    if (comboBox6.SelectedIndex + 1 == 2 && Status == 3) throw new Exception("Чтобы изменить статус авто, создайте новый контракт");
                    if (comboBox6.SelectedIndex + 1 != Status && Status == 2) throw new Exception("Чтобы изменить статус авто, удалите текущий контракт.");
                    if (comboBox6.SelectedIndex + 1 != Status && Status == 1 && comboBox6.SelectedIndex + 1 != 3) throw new Exception("Чтобы изменить статус авто, просто создайте новый контракт.");
                }

                ChangeCarInfo(Convert.ToInt32(dataGridView1.Rows[rowIndex].Cells[0].Value));

                Bitmap imageCar = (Bitmap)GetPhotoCar(Convert.ToInt32(dataGridView1.Rows[rowIndex].Cells[0].Value));
                if (photoChanged && !MatchPhoto((Bitmap)pictureBox2.Image, imageCar))
                {
                    ChangeCarPhoto(Convert.ToInt32(dataGridView1.Rows[rowIndex].Cells[0].Value));
                    File.Delete(@"Car.jpg");
                }

                ChangeCarAddition(Convert.ToInt32(dataGridView1.Rows[rowIndex].Cells[0].Value));

                DataGridView1_Refresh(Convert.ToInt32(dataGridView1.Rows[rowIndex].Cells[0].Value));
                checkBox1.Checked = false;

            }
            catch (Exception ex)
            {
                label23.Visible = true;
                label23.Text = ex.Message;
            }
        }

        private void ChangeCarInfo(int LocalRowIndex)
        {
            string connectionString = @"Data Source=.\SQLEXPRESS;Initial Catalog=CarRent;Integrated Security=True";
            string sCommand = "Update Cars Set Car_Gos_ID = '" + textBox3.Text + "', Cod_Marka = '" + (1+comboBox1.SelectedIndex) + "', Car_Model = '" + textBox2.Text + "'" +
                ", Cod_Color = '" + (1+comboBox2.SelectedIndex) + "', Cod_Fuel = '" + (1+comboBox3.SelectedIndex) + "', Cod_Transmission = '" + (1+comboBox4.SelectedIndex) + "'," +
                "Cod_Type = '" + (1+comboBox5.SelectedIndex) + "', Car_Num_Sit = '" + numericUpDown1.Value + "', Price = '" + numericUpDown2.Value + "' Where Cod_Car = '" + LocalRowIndex + "'";
            using (SqlConnection connection = new SqlConnection(connectionString))
            {
                SqlCommand command = new SqlCommand(sCommand, connection);
                connection.Open();
                command.ExecuteNonQuery();
                connection.Close();
            }

            sCommand = "Update Car_Status Set Cod_Status = '"+ (1+comboBox6.SelectedIndex) + "' Where Cod_Car = '" + LocalRowIndex + "'";
            using (SqlConnection connection = new SqlConnection(connectionString))
            {
                SqlCommand command = new SqlCommand(sCommand, connection);
                connection.Open();
                command.ExecuteNonQuery();
                connection.Close();
            }
        }

        private void ChangeCarPhoto(int LocalRowIndex)
        {
            photoChanged = false;
            byte[] imageData = null;
            FileInfo fInfo = new FileInfo(pPicture);
            long numBytes = fInfo.Length;
            FileStream fStream = new FileStream(pPicture, FileMode.Open, FileAccess.Read);
            BinaryReader br = new BinaryReader(fStream);
            imageData = br.ReadBytes((int)numBytes);

            using (SqlConnection sqlConnection = new SqlConnection(@"Data Source=.\SQLEXPRESS;Initial Catalog=CarRent;Integrated Security=True"))
            {
                SqlCommand command = new SqlCommand("Update Cars " +
                                                "Set ImageData = @ImageData " +
                                                "where Cod_Car = @Cod_Car", sqlConnection);

                SqlParameter param = new SqlParameter
                {
                    ParameterName = "@ImageData",
                    Value = (object)imageData,
                    SqlDbType = SqlDbType.Image
                };
                command.Parameters.Add(param);

                param = new SqlParameter
                {
                    ParameterName = "@Cod_Car",
                    Value = LocalRowIndex,
                    SqlDbType = SqlDbType.Int
                };
                command.Parameters.Add(param);

                sqlConnection.Open();
                command.ExecuteNonQuery();
                sqlConnection.Close();
                fStream.Dispose();
                br.Dispose();
                pPicture = @"Car.png";
            }
        }

        private void ChangeCarAddition(int LocalRowIndex)
        {
            string connectionString = @"Data Source=.\SQLEXPRESS;Initial Catalog=CarRent;Integrated Security=True";
            string sCommand = "Delete From Car_Additionaly Where Cod_Car = '" + LocalRowIndex + "'";
            using (SqlConnection connection = new SqlConnection(connectionString))
            {
                SqlCommand command = new SqlCommand(sCommand, connection);
                connection.Open();
                command.ExecuteNonQuery();
                connection.Close();
            }

            using (SqlConnection sqlConnection = new SqlConnection(@"Data Source=.\SQLEXPRESS;Initial Catalog=CarRent;Integrated Security=True"))
            {
                SqlCommand command = new SqlCommand("Select Cod_Car From Cars Where Car_Gos_ID = '" + textBox1.Text + "'", sqlConnection);
                sqlConnection.Open();
                foreach (var a in richTextBox1.Text.Split(',','\n'))
                {
                    if (a != "" && a != "," && a != ".")
                    {
                        command = new SqlCommand("Insert into Car_Additionaly values ('" + LocalRowIndex + "','" + a.Trim(' ', '\n') + "')", sqlConnection);
                        command.ExecuteNonQuery();
                    }
                }
                sqlConnection.Close();
            }
        }

        private bool MatchPhoto(Bitmap Original, Bitmap User)
        {
            var pixelTrue = 0.0;
            var pixelFalse = 0.0;

            if (Original.Size == User.Size)
            {
                for (int i = 0; i < Original.Width; i++)
                {
                    for (int j = 0; j < Original.Height; j++)
                    {
                        var pixel1 = Original.GetPixel(i, j);
                        var pixel2 = User.GetPixel(i, j);

                        if (pixel1 != pixel2) pixelFalse++;
                        else
                            pixelTrue++;
                    }
                }

                Original.Dispose();
                User.Dispose();
            }
            else
            {
                Original.Dispose();
                User.Dispose();

                return false;
            }
            var percentResult = (pixelTrue / (pixelTrue + pixelFalse)) * 100;
            return percentResult >= 97;
        }

        private void textBox3_TextChanged(object sender, EventArgs e)
        {
            textBox3.Text = System.Text.RegularExpressions.Regex.Replace(textBox3.Text, @"[^a-zA-Z0-9 ]", "");
            textBox3.Text = textBox3.Text.ToUpper();
            textBox3.SelectionStart = textBox3.Text.Length;
        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {
            textBox2.Text = System.Text.RegularExpressions.Regex.Replace(textBox2.Text, @"[^a-zA-Z0-9 ]", "");
            textBox2.SelectionStart = textBox2.Text.Length;
        }

        private void richTextBox1_TextChanged(object sender, EventArgs e)
        {
            richTextBox1.Text = System.Text.RegularExpressions.Regex.Replace(richTextBox1.Text, @"[^a-zA-Z0-9,'\n'а-яА-Я ]", "");
            richTextBox1.SelectionStart = richTextBox1.Text.Length;
        }

        private void button3_Click(object sender, EventArgs e)
        {
            label23.Visible = false;
            try
            {
                using (SqlConnection sqlConnection = new SqlConnection(@"Data Source=.\SQLEXPRESS;Initial Catalog=CarRent;Integrated Security=True"))
                {
                    sqlConnection.Open();
                    SqlCommand command = new SqlCommand("Select Count(*) From Contracts Where Cod_Car = " + dataGridView1.Rows[rowIndex].Cells[0].Value+"", sqlConnection);
                    int Count = (int)command.ExecuteScalar();
                    if (Count > 0)
                        throw new Exception("Сперва удалите все контракты связанные с этим авто");

                    sqlConnection.Close();
                }


                    using (AreYouSure areYouSure = new AreYouSure())
                {
                    if (areYouSure.ShowDialog() == DialogResult.OK)
                    {
                        using (SqlConnection sqlConnection = new SqlConnection(@"Data Source=.\SQLEXPRESS;Initial Catalog=CarRent;Integrated Security=True"))
                        {
                            sqlConnection.Open();

                            SqlCommand command = new SqlCommand("DeleteCar", sqlConnection)
                            {
                                CommandType = CommandType.StoredProcedure
                            };

                            SqlParameter Cod_Client = new SqlParameter
                            {
                                ParameterName = "@Cod_Car",
                                Value = dataGridView1.Rows[rowIndex].Cells[0].Value
                            };
                            command.Parameters.Add(Cod_Client);

                            string ValueAdd = "";
                            foreach (var a in vs)
                            {
                                ValueAdd += a + ", ";
                            }

                            if (ValueAdd.Length > 0)
                                ValueAdd = ValueAdd.Remove(ValueAdd.Length - 1, 1);

                            SqlParameter Additionaly = new SqlParameter
                            {
                                ParameterName = "@Additionaly",
                                Value = ValueAdd
                            };
                            command.Parameters.Add(Additionaly);

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
                label23.Visible = true;
                label23.Text = ex.Message;
            }
            
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

        private void CarList_Load(object sender, EventArgs e)
        {
            using (SqlConnection sqlConnection = new SqlConnection(@"Data Source=.\SQLEXPRESS;Initial Catalog=CarRent;Integrated Security=True"))
            {
                SqlCommand command = new SqlCommand("Select Marka from Car_Marka", sqlConnection);
                sqlConnection.Open();

                DataTable table = new DataTable();
                DataTable table2 = new DataTable();
                SqlDataAdapter sqlDataAdapter = new SqlDataAdapter(command);
                sqlDataAdapter.Fill(table);
                comboBox1.DataSource = table;
                comboBox1.DisplayMember = "Marka";
                comboBox1.SelectedIndex = -1;
                comboBox13.DataSource = table;
                comboBox13.DisplayMember = "Marka";
                comboBox13.SelectedIndex = -1;

                command = new SqlCommand("Select Color from Car_Color", sqlConnection);
                table = new DataTable();
                sqlDataAdapter = new SqlDataAdapter(command);
                sqlDataAdapter.Fill(table);
                comboBox2.DataSource = table;
                comboBox2.DisplayMember = "Color";
                comboBox2.SelectedIndex = -1;
                comboBox12.DataSource = table;
                comboBox12.DisplayMember = "Color";
                comboBox12.SelectedIndex = -1;

                command = new SqlCommand("Select Fuel from Car_Fuel", sqlConnection);
                table = new DataTable();
                sqlDataAdapter = new SqlDataAdapter(command);
                sqlDataAdapter.Fill(table);
                comboBox3.DataSource = table;
                comboBox3.DisplayMember = "Fuel";
                comboBox3.SelectedIndex = -1;
                comboBox11.DataSource = table;
                comboBox11.DisplayMember = "Fuel";
                comboBox11.SelectedIndex = -1;

                command = new SqlCommand("Select Transmission from Car_Transmission", sqlConnection);
                table = new DataTable();
                sqlDataAdapter = new SqlDataAdapter(command);
                sqlDataAdapter.Fill(table);
                comboBox4.DataSource = table;
                comboBox4.DisplayMember = "Transmission";
                comboBox4.SelectedIndex = -1;
                comboBox10.DataSource = table;
                comboBox10.DisplayMember = "Transmission";
                comboBox10.SelectedIndex = -1;

                command = new SqlCommand("Select NameType from Car_Type", sqlConnection);
                table = new DataTable();
                sqlDataAdapter = new SqlDataAdapter(command);
                sqlDataAdapter.Fill(table);
                comboBox5.DataSource = table;
                comboBox5.DisplayMember = "NameType";
                comboBox5.SelectedIndex = -1;
                comboBox9.DataSource = table;
                comboBox9.DisplayMember = "NameType";
                comboBox9.SelectedIndex = -1;

                command = new SqlCommand("Select NameStatus from Reference_Status", sqlConnection);
                table = new DataTable();
                sqlDataAdapter = new SqlDataAdapter(command);
                sqlDataAdapter.Fill(table);
                comboBox6.DataSource = table;
                comboBox6.DisplayMember = "NameStatus";
                comboBox6.SelectedIndex = -1;
                comboBox8.DataSource = table;
                comboBox8.DisplayMember = "NameStatus";
                comboBox8.SelectedIndex = -1;

                command = new SqlCommand("Select distinct (Additionaly) from Car_Additionaly", sqlConnection);
                table = new DataTable();
                sqlDataAdapter = new SqlDataAdapter(command);
                sqlDataAdapter.Fill(table);
                comboBox7.DataSource = table;
                comboBox7.DisplayMember = "Additionaly";
                comboBox7.SelectedIndex = -1;


                sqlConnection.Close();

            }
        }

        private void button5_Click(object sender, EventArgs e)
        {
            if(richTextBox2.Find(comboBox7.Text)==-1)
            {
                if (richTextBox2.TextLength != 0)
                    richTextBox2.Text += ", " + comboBox7.Text;
                else
                        richTextBox2.Text += comboBox7.Text;
            }

            comboBox7.SelectedIndex = -1;
        }

        private void button8_Click(object sender, EventArgs e)
        {
            comboBox7.SelectedIndex = -1;
            comboBox8.SelectedIndex = -1;
            comboBox9.SelectedIndex = -1;
            comboBox10.SelectedIndex = -1;
            comboBox11.SelectedIndex = -1;
            comboBox12.SelectedIndex = -1;
            comboBox13.SelectedIndex = -1;

            numericUpDown6.Value = 1;
            numericUpDown5.Value = 15;

            numericUpDown3.Value = 10;
            numericUpDown4.Value = 500;

            richTextBox2.Text = "";
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
            comboBox7.SelectedIndex = -1;

            if (textBox1.Text == "Номерной знак") textBox1.Text = "";
            if (textBox4.Text == "Модель") textBox4.Text = "";

            if (textBox1.TextLength > 0 || textBox4.TextLength > 0 || comboBox8.SelectedIndex != -1 || comboBox9.SelectedIndex != -1 || comboBox10.SelectedIndex != -1 ||
                comboBox11.SelectedIndex != -1 || comboBox12.SelectedIndex != -1 || comboBox13.SelectedIndex != -1 ||
                richTextBox2.TextLength> 0 || numericUpDown6.Value != 1 || numericUpDown5.Value != 15 || numericUpDown3.Value != 10 || numericUpDown4.Value != 500)
            {

                using (SqlConnection sqlConnection = new SqlConnection(@"Data Source=.\SQLEXPRESS;Initial Catalog=CarRent;Integrated Security=True"))
                {
                    SqlCommand command = new SqlCommand("Select Cod_Car, Car_Gos_ID, Marka, Car_Model, Color, Fuel, Transmission, NameType, Car_Num_Sit, Price, NameStatus From AllInfoCar where Car_Gos_ID LIKE '%" + textBox1.Text + "%' and Car_model like '%" + textBox4.Text + "%' and Marka like '%"+comboBox13.Text+"%' and Color like '%"+comboBox12.Text+ "%' and Fuel like '%" + comboBox11.Text+ "%' and Transmission like '%" + comboBox10.Text + "%' and NameType like '%" + comboBox9.Text + "%' and Price>="+ numericUpDown3.Value +" and Price<="+ numericUpDown4.Value + " and Car_Num_Sit >="+ numericUpDown6.Value+ " and Car_Num_Sit <="+ numericUpDown5.Value + " and NameStatus like '%"+ comboBox8.Text+"%'", sqlConnection);

                    sqlConnection.Open();
                    SqlDataAdapter sqlDataAdapter = new SqlDataAdapter(command);
                    DataTable dtRecorder = new DataTable();
                    sqlDataAdapter.Fill(dtRecorder);
                    sqlConnection.Close();

                    if(richTextBox2.TextLength > 0 && dtRecorder.Rows.Count>0)
                    {
                        for (int i = 0; i < dtRecorder.Rows.Count; i++)
                        {
                            GetAdditionCarSearch(Convert.ToInt32(dtRecorder.Rows[i][0]));

                            foreach (var UserAdditon in richTextBox2.Text.Split(',', '\n'))
                            {

                                if (UserAdditon != "" && UserAdditon != "," && UserAdditon != ".")
                                {
                                    if (UserAdditon[0] == ' ')
                                    {
                                        if (!ListAddition.Contains(UserAdditon.Substring(1)))
                                        {
                                            dtRecorder.Rows[i].Delete();
                                            continue;
                                        }
                                    }
                                    else
                                    {
                                        if (!ListAddition.Contains(UserAdditon))
                                        {
                                            dtRecorder.Rows[i].Delete();
                                            continue;
                                        }
                                    }
                                }
                                
                            }
                        }
                    }

                    dataGridView1.DataSource = dtRecorder;

                }

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
                    label22.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[10].Value);
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
                    label22.Text = "";
                    richTextBox1.Text ="";
                }

                dataGridView1.AllowUserToOrderColumns = false;
                dataGridView1.AllowUserToResizeColumns = false;
            }
        }


        private void GetAdditionCarSearch(int rowIndexLocal)
        {
            ListAddition.Clear();
            ListAddition = new List<string>();

            SqlConnection sqlConnection = new SqlConnection(@"Data Source=.\SQLEXPRESS;Initial Catalog=CarRent;Integrated Security=True");
            {
                SqlCommand command = new SqlCommand("Select Additionaly FROM Car_Additionaly WHERE Cod_Car = '" + rowIndexLocal + "'", sqlConnection);
                sqlConnection.Open();
                SqlDataReader rd = command.ExecuteReader();

                while (rd.Read())
                {
                    ListAddition.Add(rd["Additionaly"].ToString());
                }

                sqlConnection.Close();
            }
        }

        private void button7_Click(object sender, EventArgs e)
        {
            button1_Click(sender, e);
        }
    }
}
