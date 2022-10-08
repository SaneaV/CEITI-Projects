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
    public partial class ClientAdd : UserControl
    {
        string pPicture = @"UserPicture.png";

        public ClientAdd()
        {
            InitializeComponent();
            label20.Visible = false;
            NameTextBox.Select();
        }

        private void TextBox1_TextChanged(object sender, EventArgs e)
        {
            NameTextBox.Text = System.Text.RegularExpressions.Regex.Replace(NameTextBox.Text, @"[^а-яА-яЁё]", "");
            NameTextBox.SelectionStart = NameTextBox.Text.Length;
        }

        private void SurnameTextBox_TextChanged(object sender, EventArgs e)
        {
            SurnameTextBox.Text = System.Text.RegularExpressions.Regex.Replace(SurnameTextBox.Text, @"[^а-яА-яЁё]", "");
            SurnameTextBox.SelectionStart = SurnameTextBox.Text.Length;
        }

        private void Button1_Click(object sender, EventArgs e)
        {
            label20.Visible = false;

            try
            {
                if (NameTextBox.Text.Length <= 1)
                    throw new Exception("Поле имени пустое");

                if (SurnameTextBox.Text.Length <= 1)
                    throw new Exception("Поле фамилии пустое");

                if (TelBox.Text.Length != 16)
                    throw new Exception("Поле телефона пустое");

                if (AdresBox.Text.Length <= 5)
                    throw new Exception("Поле адреса пустое");

                if (DateBox.Text.Length != 10)
                    throw new Exception("Поле даты рождения пустое");


                if (Convert.ToDateTime(DateBox.Text) >= DateTime.Now.Date)
                    throw new Exception("Ошибка в дате");

                var today = DateTime.Today;
                var age = today.Year - Convert.ToDateTime(DateBox.Text).Year;
                if (Convert.ToDateTime(DateBox.Text).Date > today.AddYears(-age)) age--;

                if (age < 18) throw new Exception("Клиенту меньше 18 лет");
                if (age > 120) throw new Exception("Возможна ошибка в дате. Если всё верно, обратитесь к администратору");


                if (IDBox.Text.Length == 0)
                    throw new Exception("Поле серии паспорта пустое");

                if (IDBox.Text.Length != 13)
                    throw new Exception("Поле серии паспорта не полное");

                using (SqlConnection sqlConnection = new SqlConnection(@"Data Source=.\SQLEXPRESS;Initial Catalog=CarRent;Integrated Security=True"))
                {
                    SqlCommand command = new SqlCommand("Select Count(*) from Clients Where Client_PasID LIKE '" + IDBox.Text + "'", sqlConnection);
                    sqlConnection.Open();
                    int Count = Convert.ToInt32(command.ExecuteScalar());
                    sqlConnection.Close();

                    if (Count != 0) throw new Exception("Человек с такой серией паспорта уже существует в базе");
                }

                if (ImageFormat.Png.Equals(pictureBox1.Image.RawFormat))
                    throw new Exception("Добавьте фотографию");


                NameTextBox.Text = NameTextBox.Text.ToLower();
                SurnameTextBox.Text = SurnameTextBox.Text.ToLower();

                NameTextBox.Text = char.ToUpper(NameTextBox.Text[0]) + NameTextBox.Text.Substring(1);
                SurnameTextBox.Text = char.ToUpper(SurnameTextBox.Text[0]) + SurnameTextBox.Text.Substring(1);


                using (SqlConnection sqlConnection = new SqlConnection(@"Data Source=.\SQLEXPRESS;Initial Catalog=CarRent;Integrated Security=True"))
                {
                    byte[] imageData = null;
                    FileInfo fInfo = new FileInfo(pPicture);
                    long numBytes = fInfo.Length;
                    FileStream fStream = new FileStream(pPicture, FileMode.Open, FileAccess.Read);
                    BinaryReader br = new BinaryReader(fStream);
                    imageData = br.ReadBytes((int)numBytes);
                    sqlConnection.Open();

                    SqlCommand command = new SqlCommand("InsertClientData", sqlConnection)
                    {
                        CommandType = System.Data.CommandType.StoredProcedure
                    };

                    SqlParameter NameClient = new SqlParameter
                    {
                        ParameterName = "@Client_Name",
                        Value = NameTextBox.Text
                    };
                    command.Parameters.Add(NameClient);

                    SqlParameter SurnameClient = new SqlParameter
                    {
                        ParameterName = "@Client_Surname",
                        Value = SurnameTextBox.Text
                    };
                    command.Parameters.Add(SurnameClient);

                    SqlParameter IDClient = new SqlParameter
                    {
                        ParameterName = "@Client_PasID",
                        Value = IDBox.Text
                    };
                    command.Parameters.Add(IDClient);

                    TelBox.TextMaskFormat = MaskFormat.ExcludePromptAndLiterals;
                    SqlParameter PhoneClient = new SqlParameter
                    {
                        ParameterName = "@Сlient_PhoneNumber",
                        
                        Value = TelBox.Text,
                    
                    };
                    command.Parameters.Add(PhoneClient);

                    SqlParameter AdresClient = new SqlParameter
                    {
                        ParameterName = "@Client_Adres",
                        Value = AdresBox.Text
                    };
                    command.Parameters.Add(AdresClient);

                    SqlParameter BirthdayClient = new SqlParameter
                    {
                        ParameterName = "@Client_Birthday",
                        Value = DateBox.Text
                    };
                    command.Parameters.Add(BirthdayClient);

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
                    pPicture = @"UserPicture.png";
                }

                NameTextBox.Clear();
                SurnameTextBox.Clear();
                IDBox.Clear();
                TelBox.Clear();
                AdresBox.Clear();
                DateBox.Clear();
                pictureBox1.Image.Dispose();
                pictureBox1.Image = Image.FromFile(@"UserPicture.png");
                File.Delete(@"ClientPicture.jpg");
                TelBox.TextMaskFormat = MaskFormat.IncludePromptAndLiterals;

                using (ClientHasBeenAdded clientHasBeenAdded = new ClientHasBeenAdded())
                {
                    if (clientHasBeenAdded.ShowDialog() == DialogResult.OK)
                    {

                    }
                }

            }
            catch (Exception ex)
            {
                label20.Visible = true;
                label20.Text = ex.Message;
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

                if (File.Exists(@"ClientPicture.jpg"))
                {
                    pPicture = @"UserPicture.png";
                    pictureBox1.Image.Dispose();
                    File.Delete(@"ClientPicture.jpg");
                    pPicture = @"ClientPicture.jpg";
                }


                bmp1.Save(@"ClientPicture.jpg", jpgEncoder, myEncoderParameters);
                bmp1.Dispose();

                return @"ClientPicture.jpg";
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

        private void TelBox_MaskInputRejected(object sender, MaskInputRejectedEventArgs e)
        {
            TelBox.SelectionStart = 7;
        }
    }
}
