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
    public partial class CarAdd : UserControl
    {
        string pPicture = @"Car.png";

        public CarAdd()
        {
            InitializeComponent();
            label12.Visible = false;
            textBox1.Select();
        }

        private void Button1_Click(object sender, EventArgs e)
        {
            label12.Visible = false;

            try
            {
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

                if (ImageFormat.Png.Equals(pictureBox1.Image.RawFormat))
                    throw new Exception("Добавьте фотографию");


                using (SqlConnection sqlConnection = new SqlConnection(@"Data Source=.\SQLEXPRESS;Initial Catalog=CarRent;Integrated Security=True"))
                {
                    sqlConnection.Open();
                    byte[] imageData = null;
                    FileInfo fInfo = new FileInfo(pPicture);
                    long numBytes = fInfo.Length;
                    FileStream fStream = new FileStream(pPicture, FileMode.Open, FileAccess.Read);
                    BinaryReader br = new BinaryReader(fStream);
                    imageData = br.ReadBytes((int)numBytes);

                    SqlCommand command = new SqlCommand("AddCar", sqlConnection)
                    {
                        CommandType = System.Data.CommandType.StoredProcedure
                    };

                    SqlParameter Car_Gos_ID = new SqlParameter
                    {
                        ParameterName = "@Car_Gos_ID",
                        Value = textBox1.Text
                    };
                    command.Parameters.Add(Car_Gos_ID);

                    SqlParameter Marka = new SqlParameter
                    {
                        ParameterName = "@Cod_Marka",
                        Value = (1 + comboBox1.SelectedIndex)
                    };
                    command.Parameters.Add(Marka);

                    SqlParameter Color = new SqlParameter
                    {
                        ParameterName = "@Cod_Color",
                        Value = (1 + comboBox2.SelectedIndex)
                    };
                    command.Parameters.Add(Color);

                    SqlParameter Model = new SqlParameter
                    {
                        ParameterName = "@Car_Model",
                        Value = textBox2.Text
                    };
                    command.Parameters.Add(Model);

                    SqlParameter Fuel = new SqlParameter
                    {
                        ParameterName = "@Cod_Fuel",
                        Value = (1 + comboBox3.SelectedIndex)
                    };
                    command.Parameters.Add(Fuel);

                    SqlParameter Transmission = new SqlParameter
                    {
                        ParameterName = "@Cod_Transmission",
                        Value = (1 + comboBox4.SelectedIndex)
                    };
                    command.Parameters.Add(Transmission);

                    SqlParameter Type = new SqlParameter
                    {
                        ParameterName = "@Cod_Type",
                        Value = (1 + comboBox5.SelectedIndex)
                    };
                    command.Parameters.Add(Type);

                    SqlParameter Car_Num_Sit = new SqlParameter
                    {
                        ParameterName = "@Car_Num_Sit",
                        Value = numericUpDown1.Value
                    };
                    command.Parameters.Add(Car_Num_Sit);

                    SqlParameter Price = new SqlParameter
                    {
                        ParameterName = "@Price",
                        Value = numericUpDown2.Value
                    };
                    command.Parameters.Add(Price);

                    SqlParameter image = new SqlParameter
                    {
                        ParameterName = "@ImageData",
                        Value = (object)imageData,
                        SqlDbType = SqlDbType.Image
                    };
                    command.Parameters.Add(image);

                    command.ExecuteScalar();
                    sqlConnection.Close();

                    fStream.Dispose();
                    br.Dispose();
                    pPicture = @"Car.png";
                }

                using (SqlConnection sqlConnection = new SqlConnection(@"Data Source=.\SQLEXPRESS;Initial Catalog=CarRent;Integrated Security=True"))
                {
                    SqlCommand command = new SqlCommand("Select Cod_Car From Cars Where Car_Gos_ID = '" + textBox1.Text + "'", sqlConnection);
                    sqlConnection.Open();
                    SqlDataReader rd = command.ExecuteReader();
                    string CodCar = "0";

                    while (rd.Read())
                    {
                        CodCar = (rd["Cod_Car"].ToString());
                    }
                    sqlConnection.Close();


                    sqlConnection.Open();
                    foreach (var a in textBox3.Text.Split(','))
                    {
                        command = new SqlCommand("Insert into Car_Additionaly values ('" + CodCar + "','" + a.Trim(' ') + "')", sqlConnection);
                        command.ExecuteNonQuery();
                    }
                    sqlConnection.Close();
                }


                textBox1.Text = null;
                textBox2.Text = null;
                textBox3.Text = null;

                comboBox1.SelectedItem = null;
                comboBox2.SelectedItem = null;
                comboBox3.SelectedItem = null;
                comboBox4.SelectedItem = null;
                comboBox5.SelectedItem = null;

                pictureBox1.Image.Dispose();

                numericUpDown1.Value = 1;
                numericUpDown2.Value = 10;

                pictureBox1.Image = Image.FromFile(@"Car.png");
                File.Delete(@"Car.jpg");

                using (CarHasBeenAdded carHasBeenAdded = new CarHasBeenAdded())
                {
                    if(carHasBeenAdded.ShowDialog() == DialogResult.OK)
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

        private void TextBox1_TextChanged(object sender, EventArgs e)
        {
            textBox1.Text = System.Text.RegularExpressions.Regex.Replace(textBox1.Text, @"[^a-zA-Z0-9 ]", "");
            textBox1.Text = textBox1.Text.ToUpper();
            textBox1.SelectionStart = textBox1.Text.Length;
        }


        private void TextBox3_TextChanged(object sender, EventArgs e)
        {
            textBox3.Text = System.Text.RegularExpressions.Regex.Replace(textBox3.Text, @"[^a-zA-Z0-9,а-яА-Я ]", "");
            textBox3.SelectionStart = textBox3.Text.Length;
        }

        private void TextBox2_TextChanged(object sender, EventArgs e)
        {
            textBox2.Text = System.Text.RegularExpressions.Regex.Replace(textBox2.Text, @"[^a-zA-Z0-9 ]", "");
            textBox2.SelectionStart = textBox2.Text.Length;
        }

        private void CarAdd_Load(object sender, EventArgs e)
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

                sqlConnection.Close();

            }
        }
    }
}
