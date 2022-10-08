using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Drawing.Imaging;
using System.IO;
using System.Data.SqlClient;

namespace CarRent
{
    public partial class AboutCar : UserControl
    {
        string pPicture = "Car.png";
        List<string> vs = new List<string>();
        int car = 0;
        bool photoChanged = false;
        string oldCarNumber;

        public AboutCar(int carIndex)
        {
            InitializeComponent();
            car = carIndex;
            richTextBox1.ReadOnly = true;

            pictureBox1.Image = GetPhotoCar(carIndex);
            GetAdditionCar(carIndex);

            if (Worker.user.Cod_Position == 1 || Worker.user.Cod_Position == 3) checkBox1.Visible = true;
            else checkBox1.Visible = false;

            using (SqlConnection sqlConnection = new SqlConnection(@"Data Source=.\SQLEXPRESS;Initial Catalog=CarRent;Integrated Security=True"))
            {
                SqlCommand command = new SqlCommand("Select Cod_Car, Car_Gos_ID, Marka, Car_Model, Color, Fuel, Transmission, NameType, Car_Num_Sit, Price, NameStatus From AllInfoCar Where Cod_Car = " + carIndex + "", sqlConnection);
                sqlConnection.Open();
                using (SqlDataReader reader = command.ExecuteReader())
                {
                    while (reader.Read())
                    {
                        label24.Text = reader["Cod_Car"].ToString();
                        label14.Text = reader["Car_Gos_ID"].ToString();
                        label15.Text = reader["Marka"].ToString();
                        label16.Text = reader["Car_Model"].ToString();
                        label17.Text = reader["Color"].ToString();
                        label18.Text = reader["Fuel"].ToString();
                        label19.Text = reader["Transmission"].ToString();
                        label20.Text = reader["NameType"].ToString();
                        label21.Text = reader["Car_Num_Sit"].ToString();
                        label22.Text = reader["Price"].ToString();
                        label23.Text = reader["NameStatus"].ToString();
                    }
                }
                sqlConnection.Close();
            }

            oldCarNumber = label14.Text;
        }

        private void GetAdditionCar(int rowIndexLocal)
        {
            vs.Clear();
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

            if (richTextBox1.Visible == true)
            {
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
            if (textBox3.Visible == true)
            {
                foreach (var a in vs)
                {
                    textBox3.Text += a + ", ";
                }


                if (textBox3.TextLength > 0)
                    textBox3.Text = textBox3.Text.Remove(textBox3.Text.Length - 2, 1);
            }

        }

        readonly OpenFileDialog openFileDialog = new OpenFileDialog
        {
            Filter = "Image files (*.jpg, *.jpeg) | *.jpg; *.jpeg;"
        };


        private void Button2_Click(object sender, EventArgs e)
        {
            DialogResult res = openFileDialog.ShowDialog();
            if (res == DialogResult.OK)
            {
                pPicture = VaryQualityLevel(openFileDialog.FileName);
                pictureBox1.Image = Image.FromFile(pPicture);
                photoChanged = true;
            }
            openFileDialog.Dispose();
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
                    pictureBox1.Image.Dispose();
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

        private void pictureBox12_Click(object sender, EventArgs e)
        {
            this.Dispose();
        }

        protected void readFromBD()
        {
            using (SqlConnection sqlConnection = new SqlConnection(@"Data Source=.\SQLEXPRESS;Initial Catalog=CarRent;Integrated Security=True"))
            {
                SqlCommand command = new SqlCommand("Select Marka from Car_Marka", sqlConnection);
                sqlConnection.Open();

                DataTable table = new DataTable();
                SqlDataAdapter sqlDataAdapter = new SqlDataAdapter(command);
                sqlDataAdapter.Fill(table);
                comboBox1.DataSource = table;
                comboBox1.DisplayMember = "Marka";
                comboBox1.SelectedIndex = -1;

                command = new SqlCommand("Select Color from Car_Color", sqlConnection);
                table = new DataTable();
                sqlDataAdapter = new SqlDataAdapter(command);
                sqlDataAdapter.Fill(table);
                comboBox2.DataSource = table;
                comboBox2.DisplayMember = "Color";
                comboBox2.SelectedIndex = -1;

                command = new SqlCommand("Select Fuel from Car_Fuel", sqlConnection);
                table = new DataTable();
                sqlDataAdapter = new SqlDataAdapter(command);
                sqlDataAdapter.Fill(table);
                comboBox3.DataSource = table;
                comboBox3.DisplayMember = "Fuel";
                comboBox3.SelectedIndex = -1;

                command = new SqlCommand("Select Transmission from Car_Transmission", sqlConnection);
                table = new DataTable();
                sqlDataAdapter = new SqlDataAdapter(command);
                sqlDataAdapter.Fill(table);
                comboBox4.DataSource = table;
                comboBox4.DisplayMember = "Transmission";
                comboBox4.SelectedIndex = -1;

                command = new SqlCommand("Select NameType from Car_Type", sqlConnection);
                table = new DataTable();
                sqlDataAdapter = new SqlDataAdapter(command);
                sqlDataAdapter.Fill(table);
                comboBox5.DataSource = table;
                comboBox5.DisplayMember = "NameType";
                comboBox5.SelectedIndex = -1;

                command = new SqlCommand("Select NameStatus from Reference_Status", sqlConnection);
                table = new DataTable();
                sqlDataAdapter = new SqlDataAdapter(command);
                sqlDataAdapter.Fill(table);
                comboBox6.DataSource = table;
                comboBox6.DisplayMember = "NameStatus";
                comboBox6.SelectedIndex = -1;

                sqlConnection.Close();
            }
        }


        private void checkBox1_CheckedChanged(object sender, EventArgs e)
        {
            if (checkBox1.Checked)
            {
                label14.Visible = false;
                label15.Visible = false;
                label16.Visible = false;
                label17.Visible = false;
                label18.Visible = false;
                label19.Visible = false;
                label20.Visible = false;
                label21.Visible = false;
                label22.Visible = false;
                label23.Visible = false;
                richTextBox1.Visible = false;

                readFromBD();

                textBox1.Visible = true;
                textBox1.Text = label14.Text;
                textBox2.Visible = true;
                textBox2.Text = label16.Text;
                textBox3.Visible = true;

                label11.Visible = true;

                comboBox1.Visible = true;
                comboBox1.Text = label15.Text;
                comboBox2.Visible = true;
                comboBox2.Text = label17.Text;
                comboBox3.Visible = true;
                comboBox3.Text = label18.Text;
                comboBox4.Visible = true;
                comboBox4.Text = label19.Text;
                comboBox5.Visible = true;
                comboBox5.Text = label20.Text;
                comboBox6.Visible = true;
                comboBox6.Text = label23.Text;

                numericUpDown1.Visible = true;
                numericUpDown1.Value = Convert.ToInt32(label21.Text);
                numericUpDown2.Visible = true;
                numericUpDown2.Value = Convert.ToInt32(label22.Text);

                button1.Visible = true;
                button2.Visible = true;
                button3.Visible = true;

                textBox3.Clear();
                GetAdditionCar(car);

                if (Worker.user.Cod_Position == 1)
                    button4.Visible = true;
            }
            else
            {
                label14.Visible = true;
                label15.Visible = true;
                label16.Visible = true;
                label17.Visible = true;
                label18.Visible = true;
                label19.Visible = true;
                label20.Visible = true;
                label21.Visible = true;
                label22.Visible = true;
                label23.Visible = true;
                richTextBox1.Visible = true;

                textBox1.Visible = false;
                textBox2.Visible = false;
                textBox3.Visible = false;

                label11.Visible = false;
                label12.Visible = false;

                comboBox1.Visible = false;
                comboBox2.Visible = false;
                comboBox3.Visible = false;
                comboBox4.Visible = false;
                comboBox5.Visible = false;
                comboBox6.Visible = false;

                numericUpDown1.Visible = false;
                numericUpDown2.Visible = false;

                button1.Visible = false;
                button2.Visible = false;
                button3.Visible = false;
                button4.Visible = false;

                richTextBox1.Clear();
                GetAdditionCar(car);
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            checkBox1.Checked = false;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            label12.Visible = false;
            try
            {
                if (oldCarNumber != textBox1.Text)
                    using (SqlConnection sqlConnection = new SqlConnection(@"Data Source=.\SQLEXPRESS;Initial Catalog=CarRent;Integrated Security=True"))
                    {
                        SqlCommand command = new SqlCommand("Select Count(Car_Gos_ID) from Cars Where Car_Gos_ID LIKE '" + textBox1.Text + "'", sqlConnection);
                        sqlConnection.Open();
                        int Count = Convert.ToInt32(command.ExecuteScalar());
                        sqlConnection.Close();

                        if (Count != 0) throw new Exception("Машина с указанным номерным знаком уже существует в базе");
                    }

                if (textBox1.Text.Length == 0)
                    throw new Exception("Поле номерного знака пустое");

                if (textBox1.Text.Length != 6)
                    throw new Exception("Поле номерного знака не соответствует размеру");

                int Number = 0;
                int Letter = 0;
                foreach (var a in textBox1.Text)
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
                    SqlCommand command = new SqlCommand("Select Cod_Status From Car_Status Where Cod_Car = '" + car + "'", sqlConnection);
                    sqlConnection.Open();
                    int Status = Convert.ToInt32(command.ExecuteScalar());
                    sqlConnection.Close();

                    if (comboBox6.SelectedIndex + 1 == 2 && Status == 3) throw new Exception("Чтобы изменить статус авто, создайте новый контракт");
                    if (comboBox6.SelectedIndex + 1 != Status && Status == 2) throw new Exception("Чтобы изменить статус авто, удалите текущий контракт.");
                    if (comboBox6.SelectedIndex + 1 != Status && Status == 1 && comboBox6.SelectedIndex + 1 != 3) throw new Exception("Чтобы изменить статус авто, создайте новый контракт.");
                }

                if (label12.Visible == false)
                {
                    ChangeCarInfo(car);
                    ChangeCarAddition(car);
                    Bitmap ImageCar = (Bitmap)GetPhotoCar(car);
                    if (photoChanged && !MatchPhoto((Bitmap)pictureBox1.Image, ImageCar))
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
                                Value = car,
                                SqlDbType = SqlDbType.Int
                            };
                            command.Parameters.Add(param);

                            sqlConnection.Open();
                            command.ExecuteNonQuery();
                            sqlConnection.Close();
                            br.Dispose();
                            fStream.Dispose();
                            br.Dispose();
                            pPicture = @"Car.png";
                        }

                        pictureBox1.Image = Image.FromFile(@"Car.png");
                        File.Delete(@"Car.jpg");
                    }
                }

                checkBox1.Checked = false;
                Refresh_AboutCar(car);
            }
            catch (Exception ex)
            {
                label12.Visible = true;
                label12.Text = ex.Message;
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

        private void ChangeCarInfo(int LocalRowIndex)
        {
            string connectionString = @"Data Source=.\SQLEXPRESS;Initial Catalog=CarRent;Integrated Security=True";
            string sCommand = "Update Cars Set Car_Gos_ID = '" + textBox1.Text + "', Cod_Marka = " + (1 + comboBox1.SelectedIndex) + "," +
                    "Car_Model = '" + textBox2.Text + "', Cod_Color = " + (1 + comboBox2.SelectedIndex) + "," +
                    "Cod_Fuel = " + (1 + comboBox3.SelectedIndex) + ", Cod_Transmission = " + (1 + comboBox4.SelectedIndex) + ", Cod_Type = " + (1 + comboBox5.SelectedIndex) + ", Car_Num_Sit = " + numericUpDown1.Value + ", Price =" + numericUpDown2.Value + " Where Cod_Car = '" + LocalRowIndex + "'";
            using (SqlConnection connection = new SqlConnection(connectionString))
            {
                SqlCommand command = new SqlCommand(sCommand, connection);
                connection.Open();
                command.ExecuteNonQuery();
                connection.Close();
            }

            sCommand = "Update Car_Status Set Cod_Status = " + (1 + comboBox6.SelectedIndex) + "Where Cod_Car = " + car + "";
            using (SqlConnection connection = new SqlConnection(connectionString))
            {
                SqlCommand command = new SqlCommand(sCommand, connection);
                connection.Open();
                command.ExecuteNonQuery();
                connection.Close();
            }
        }

        private void ChangeCarAddition(int LocalRowIndex)
        {
            using (SqlConnection sqlConnection = new SqlConnection(@"Data Source=.\SQLEXPRESS;Initial Catalog=CarRent;Integrated Security=True"))
            {
                sqlConnection.Open();
                SqlCommand command = new SqlCommand("Delete From Car_Additionaly Where Cod_Car =" + car + "", sqlConnection);
                command.ExecuteNonQuery();

                foreach (var a in textBox3.Text.Split(','))
                {
                    command = new SqlCommand("Insert into Car_Additionaly values ('" + car + "','" + a.Trim(' ') + "')", sqlConnection);
                    command.ExecuteNonQuery();
                }
                sqlConnection.Close();

            }
        }

        private void Refresh_AboutCar(int LocalCodClient)
        {
            pictureBox1.Image = GetPhotoCar(car);
            richTextBox1.Text = "";
            GetAdditionCar(car);


            using (SqlConnection sqlConnection = new SqlConnection(@"Data Source=.\SQLEXPRESS;Initial Catalog=CarRent;Integrated Security=True"))
            {
                SqlCommand command = new SqlCommand("Select Cod_Car, Car_Gos_ID, Marka, Car_Model, Color, Fuel, Transmission, NameType, Car_Num_Sit, Price, NameStatus From AllInfoCar Where Cod_Car = " + car + "", sqlConnection);
                sqlConnection.Open();
                using (SqlDataReader reader = command.ExecuteReader())
                {
                    while (reader.Read())
                    {
                        label24.Text = reader["Cod_Car"].ToString();
                        label14.Text = reader["Car_Gos_ID"].ToString();
                        label15.Text = reader["Marka"].ToString();
                        label16.Text = reader["Car_Model"].ToString();
                        label17.Text = reader["Color"].ToString();
                        label18.Text = reader["Fuel"].ToString();
                        label19.Text = reader["Transmission"].ToString();
                        label20.Text = reader["NameType"].ToString();
                        label21.Text = reader["Car_Num_Sit"].ToString();
                        label22.Text = reader["Price"].ToString();
                        label23.Text = reader["NameStatus"].ToString();
                    }
                }
                sqlConnection.Close();
            }
        }

        private void button4_Click(object sender, EventArgs e)
        {
            label12.Visible = false;
            try
            {
                    using (SqlConnection sqlConnection = new SqlConnection(@"Data Source=.\SQLEXPRESS;Initial Catalog=CarRent;Integrated Security=True"))
                    {
                        sqlConnection.Open();
                        SqlCommand command = new SqlCommand("Select Count(*) From Contracts Where Cod_Car = " + car + "", sqlConnection);
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
                                Value = car
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
                        }
                    }

                }

                this.Dispose();

                using (CarHasBeenDeleted carHasBeenDeleted = new CarHasBeenDeleted())
                {
                    if (carHasBeenDeleted.ShowDialog() == DialogResult.OK)
                    {
                    }
                }

            }
            catch (Exception ex)
            {
                label12.Visible = true;
                label12.Text = ex.Message;
            }

        }
    }
}
