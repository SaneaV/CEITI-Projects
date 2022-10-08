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
using System.Data.SqlClient;
using System.IO;

namespace CarRent
{
    public partial class AboutClientcs : UserControl
    {
        string pPicture = @"UserPicture.png";
        bool photoChanged = false;
        int LocCod;

        public AboutClientcs(int LocalCodClient)
        {
            InitializeComponent();

            LocCod =  LocalCodClient;

            NameTextBox.Visible = false;
            SurnameBox.Visible = false;
            TelBox.Visible = false;
            AdresBox.Visible = false;
            DateBox.Visible = false;
            IDBox.Visible = false;
            label7.Visible = false;


            button2.Visible = false;
            button6.Visible = false;
            button1.Visible = false;


            if (Worker.user.Cod_Position == 2 || Worker.user.Cod_Position == 1) checkBox1.Visible = true;
            else checkBox1.Visible = false;

            using (SqlConnection sqlConnection = new SqlConnection(@"Data Source=.\SQLEXPRESS;Initial Catalog=CarRent;Integrated Security=True"))
            {
                SqlCommand command = new SqlCommand("Select Cod_Client, Client_Name, Client_Surname, Client_PasID, Сlient_PhoneNumber, Client_Adres, Client_Birthday From Clients Where Cod_Client = '" + LocalCodClient + "'", sqlConnection);

                sqlConnection.Open();
                using (SqlDataReader reader = command.ExecuteReader())
                {
                    while (reader.Read())
                    {
                        CodLabel.Text = reader["Cod_Client"].ToString();
                        NameLabel.Text = reader["Client_Name"].ToString();
                        LastNameLabel.Text = reader["Client_Surname"].ToString();
                        IdLabel.Text = reader["Client_PasID"].ToString();
                        PhoneLabel.Text = ("+(373)" + reader["Сlient_PhoneNumber"].ToString()).Insert(9, "-");
                        AdresLabel.Text = reader["Client_Adres"].ToString();
                        DataLabel.Text = reader["Client_Birthday"].ToString();
                    }
                }
                sqlConnection.Close();
            }

            pictureBox1.Image = GetPhotoClient(LocalCodClient);
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

        readonly OpenFileDialog openFileDialog = new OpenFileDialog
        {
            Filter = "Image files (*.jpg, *.jpeg) | *.jpg; *.jpeg; "
        };

        private string VaryQualityLevel(string image)
        {
            using (Bitmap bmp1 = new Bitmap(image))
            {
                ImageCodecInfo jpgEncoder = GetEncoder(ImageFormat.Jpeg);
                System.Drawing.Imaging.Encoder myEncoder = System.Drawing.Imaging.Encoder.Quality;
                EncoderParameters myEncoderParameters = new EncoderParameters(1);

                EncoderParameter myEncoderParametr = new EncoderParameter(myEncoder, 20L);
                myEncoderParameters.Param[0] = myEncoderParametr;
                
                if(File.Exists(@"ClientPicture.jpg"))
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

        private void button1_Click(object sender, EventArgs e)
        {
            DialogResult res = openFileDialog.ShowDialog();
            if (res == DialogResult.OK)
            {
                pPicture = VaryQualityLevel(openFileDialog.FileName);
                pictureBox1.Image = Image.FromFile(pPicture);
            }
            openFileDialog.Dispose();
            photoChanged = true;
        }

        private void checkBox1_CheckedChanged(object sender, EventArgs e)
        {
            if (checkBox1.Checked == true)
            {
                NameLabel.Visible = false;
                LastNameLabel.Visible = false;
                DataLabel.Visible = false;
                PhoneLabel.Visible = false;
                IdLabel.Visible = false;
                AdresLabel.Visible = false;

                NameTextBox.Visible = true;
                NameTextBox.Text = NameLabel.Text;
                SurnameBox.Visible = true;
                SurnameBox.Text = LastNameLabel.Text;
                TelBox.Visible = true;
                TelBox.Text = PhoneLabel.Text;
                AdresBox.Visible = true;
                AdresBox.Text = AdresLabel.Text;
                DateBox.Visible = true;
                DateBox.Text = DataLabel.Text;
                IDBox.Visible = true;
                IDBox.Text = IdLabel.Text;

                button2.Visible = true;
                button6.Visible = true;
                button1.Visible = true;

                if (Worker.user.Cod_Position == 1)
                    button3.Visible = true;
            }
            else
            {
                NameLabel.Visible = true;
                LastNameLabel.Visible = true;
                DataLabel.Visible = true;
                PhoneLabel.Visible = true;
                IdLabel.Visible = true;
                AdresLabel.Visible = true;

                NameTextBox.Visible = false;
                SurnameBox.Visible = false;
                TelBox.Visible = false;
                AdresBox.Visible = false;
                DateBox.Visible = false;
                IDBox.Visible = false;

                button2.Visible = false;
                button6.Visible = false;
                button1.Visible = false;
                    button3.Visible = false;
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            checkBox1.Checked = false;
        }

        private void Button6_Click(object sender, EventArgs e)
        {
            label7.Visible = false;
            try
            {
                if (NameTextBox.Text.Length <= 1)
                    throw new Exception("Поле имени пустое");

                if (SurnameBox.Text.Length <= 1)
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

                NameTextBox.Text = NameTextBox.Text.ToLower();
                SurnameBox.Text = SurnameBox.Text.ToLower();

                NameTextBox.Text = char.ToUpper(NameTextBox.Text[0]) + NameTextBox.Text.Substring(1);
                SurnameBox.Text = char.ToUpper(SurnameBox.Text[0]) + SurnameBox.Text.Substring(1);

                if (!label7.Visible)
                {
                    ChangeClientInfo(LocCod);

                    Bitmap imageClient = (Bitmap)GetPhotoClient(LocCod);
                    if (photoChanged && !MatchPhoto((Bitmap)pictureBox1.Image, imageClient))
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
                            SqlCommand command = new SqlCommand("Update Clients " +
                                                            "Set ImageData = @ImageData " +
                                                            "where Cod_Client = @Cod_Client", sqlConnection);

                            SqlParameter param = new SqlParameter
                            {
                                ParameterName = "@ImageData",
                                Value = (object)imageData,
                                SqlDbType = SqlDbType.Image
                            };
                            command.Parameters.Add(param);

                            param = new SqlParameter
                            {
                                ParameterName = "@Cod_Client",
                                Value = LocCod,
                                SqlDbType = SqlDbType.Int
                            };
                            command.Parameters.Add(param);

                            sqlConnection.Open();
                            command.ExecuteNonQuery();
                            sqlConnection.Close();
                            br.Dispose();
                            fStream.Dispose();
                            br.Dispose();
                            pPicture = @"UserPicture.png";
                        }

                        pictureBox1.Image = Image.FromFile(@"UserPicture.png");
                        File.Delete(@"ClientPicture.jpg");
                    }
                }


                checkBox1.Checked = false;
                Refresh_AboutClient(LocCod);
            }
            catch (Exception ex)
            {
                label7.Visible = true;
                label7.Text = ex.Message;
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


        private void Refresh_AboutClient(int LocalCodClient)
        {
            using (SqlConnection sqlConnection = new SqlConnection(@"Data Source=.\SQLEXPRESS;Initial Catalog=CarRent;Integrated Security=True"))
            {
                SqlCommand command = new SqlCommand("Select Cod_Client, Client_Name, Client_Surname, Client_PasID, Сlient_PhoneNumber, Client_Adres, Client_Birthday From Clients Where Cod_Client = '" + LocalCodClient + "'", sqlConnection);

                sqlConnection.Open();
                using (SqlDataReader reader = command.ExecuteReader())
                {
                    while (reader.Read())
                    {
                        CodLabel.Text = reader["Cod_Client"].ToString();
                        NameLabel.Text = reader["Client_Name"].ToString();
                        LastNameLabel.Text = reader["Client_Surname"].ToString();
                        IdLabel.Text = reader["Client_PasID"].ToString();
                        PhoneLabel.Text = ("+(373)" + reader["Сlient_PhoneNumber"].ToString()).Insert(9, "-");
                        AdresLabel.Text = reader["Client_Adres"].ToString();
                        DataLabel.Text = reader["Client_Birthday"].ToString();
                    }
                }
                sqlConnection.Close();
            }

            pictureBox1.Image = GetPhotoClient(LocalCodClient);
        }


        private void ChangeClientInfo(int LocalRowIndex)
        {
            TelBox.TextMaskFormat = MaskFormat.ExcludePromptAndLiterals;

            string connectionString = @"Data Source=.\SQLEXPRESS;Initial Catalog=CarRent;Integrated Security=True";
            string sCommand = "Update Clients Set Client_Name = '" + NameTextBox.Text + "', Client_Surname = '" + SurnameBox.Text + "'," +
                    "Client_PasID = '" + IDBox.Text + "', Сlient_PhoneNumber = '" + TelBox.Text + "'," +
                    "Client_Adres = '" + AdresBox.Text + "', Client_Birthday = '" + DateBox.Text + "' Where Cod_Client = '" + LocalRowIndex + "'";
            using (SqlConnection connection = new SqlConnection(connectionString))
            {
                SqlCommand command = new SqlCommand(sCommand, connection);
                connection.Open();
                command.ExecuteNonQuery();
                connection.Close();
            }

            TelBox.TextMaskFormat = MaskFormat.IncludePromptAndLiterals;
        }

        private void pictureBox12_Click(object sender, EventArgs e)
        {
            this.Dispose();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            label7.Visible = false;
            try
            {
                using (SqlConnection sqlConnection = new SqlConnection(@"Data Source=.\SQLEXPRESS;Initial Catalog=CarRent;Integrated Security=True"))
                {
                    sqlConnection.Open();
                    SqlCommand command = new SqlCommand("Select Count(*) From Contracts Where Cod_Client = " + LocCod + "", sqlConnection);
                    int Count = (int)command.ExecuteScalar();
                    if (Count > 0)
                        throw new Exception("Сперва удалите все контракты клиента");

                    sqlConnection.Close();
                }

                using (AreYouSure areYouSure = new AreYouSure())
                {
                    if (areYouSure.ShowDialog() == DialogResult.OK)
                    {
                        using (SqlConnection sqlConnection = new SqlConnection(@"Data Source=.\SQLEXPRESS;Initial Catalog=CarRent;Integrated Security=True"))
                        {
                            sqlConnection.Open();

                            SqlCommand command = new SqlCommand("DeleteClient", sqlConnection)
                            {
                                CommandType = CommandType.StoredProcedure
                            };

                            SqlParameter nameParam = new SqlParameter
                            {
                                ParameterName = "@Cod_Client",
                                Value = LocCod
                            };

                            command.Parameters.Add(nameParam);
                            command.ExecuteScalar();

                            sqlConnection.Close();
                        }
                    }

                }

                this.Dispose();

                using (ClientHasBeenDeleted clientHasBeenDeleted = new ClientHasBeenDeleted())
                {
                    if (clientHasBeenDeleted.ShowDialog() == DialogResult.OK)
                    {
                    }
                }


            }
            catch (Exception ex)
            {
                label7.Visible = true;
                label7.Text = ex.Message;
            }
        }
    }
}
