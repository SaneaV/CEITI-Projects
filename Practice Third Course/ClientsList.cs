﻿using System;
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
    public partial class ClientsList : UserControl
    {
        int rowIndex = 0;
        string pPicture = @"UserPicture.png";
        bool photoChanged = false;

        public ClientsList()
        {
            InitializeComponent();
            button6.Visible = false;
            button3.Visible = false;
            button2.Visible = false;
            button4.Visible = false;

            label4.Visible = false;

            NameBox.Visible = false;
            SurnameBox.Visible = false;
            DateBox.Visible = false;
            TelBox.Visible = false;
            IDBox.Visible = false;
            AdresBox.Visible = false;

            if (Worker.user.Cod_Position == 2 || Worker.user.Cod_Position == 1) checkBox1.Visible = true;
            else checkBox1.Visible = false;


            dataGridView1.DefaultCellStyle.Font = new Font("Century Gothic", 95 / 10);

            using (SqlConnection sqlConnection = new SqlConnection(@"Data Source=.\SQLEXPRESS;Initial Catalog=CarRent;Integrated Security=True"))
            {
                SqlCommand command = new SqlCommand("Select Cod_Client, Client_Name, Client_Surname, Client_PasID, Сlient_PhoneNumber, Client_Adres, Client_Birthday From Clients", sqlConnection);
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

                dataGridView1.Columns[0].HeaderCell.Value = "Код";
                dataGridView1.Columns[1].HeaderCell.Value = "Имя";
                dataGridView1.Columns[2].HeaderCell.Value = "Фамилия";
                dataGridView1.Columns[3].HeaderCell.Value = "Серия паспорта";
                dataGridView1.Columns[4].HeaderCell.Value = "Номер";
                dataGridView1.Columns[5].HeaderCell.Value = "Адрес";
                dataGridView1.Columns[6].HeaderCell.Value = "Дата рождения";


                dataGridView1.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.Fill;
                dataGridView1.AllowUserToOrderColumns = false;
                dataGridView1.AllowUserToResizeColumns = false;
            }

            if (dataGridView1.Rows.Count > 0)
            {
                pictureBox1.Image = GetPhotoClient(Convert.ToInt32(dataGridView1.Rows[rowIndex].Cells[0].Value));

                Cod.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[0].Value);
                NameLabel.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[1].Value);
                LastName.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[2].Value);
                idPas.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[3].Value);
                Phone.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[4].Value);
                Adres.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[5].Value);
                Birthday.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[6].Value);
            }
            else
            {
                pictureBox1.Image = Image.FromFile(@"UserPicture.png");

                Cod.Text = " ";
                NameLabel.Text = " ";
                LastName.Text = " ";
                idPas.Text = " ";
                Phone.Text = " ";
                Adres.Text = " ";
                Birthday.Text = " ";
            }
        }

        private void DataGridView1_Refresh(int rowIndexLocal)
        {
            pictureBox1.Image.Dispose();
            rowIndex = 0;

            using (SqlConnection sqlConnection = new SqlConnection(@"Data Source=.\SQLEXPRESS;Initial Catalog=CarRent;Integrated Security=True"))
            {
                SqlCommand command = new SqlCommand("Select Cod_Client, Client_Name, Client_Surname, Client_PasID, Сlient_PhoneNumber, Client_Adres, Client_Birthday From Clients", sqlConnection);
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

                dataGridView1.Columns[0].HeaderCell.Value = "Код";
                dataGridView1.Columns[1].HeaderCell.Value = "Имя";
                dataGridView1.Columns[2].HeaderCell.Value = "Фамилия";
                dataGridView1.Columns[3].HeaderCell.Value = "Серия паспорта";
                dataGridView1.Columns[4].HeaderCell.Value = "Номер";
                dataGridView1.Columns[5].HeaderCell.Value = "Адрес";
                dataGridView1.Columns[6].HeaderCell.Value = "Дата рождения";

            }

            if (dataGridView1.Rows.Count > 0)
            {
                pictureBox1.Image = GetPhotoClient(Convert.ToInt32(dataGridView1.Rows[rowIndexLocal].Cells[0].Value));

                Cod.Text = Convert.ToString(dataGridView1.Rows[rowIndexLocal].Cells[0].Value);
                NameLabel.Text = Convert.ToString(dataGridView1.Rows[rowIndexLocal].Cells[1].Value);
                LastName.Text = Convert.ToString(dataGridView1.Rows[rowIndexLocal].Cells[2].Value);
                idPas.Text = Convert.ToString(dataGridView1.Rows[rowIndexLocal].Cells[3].Value);
                Phone.Text = Convert.ToString(dataGridView1.Rows[rowIndexLocal].Cells[4].Value);
                Adres.Text = Convert.ToString(dataGridView1.Rows[rowIndexLocal].Cells[5].Value);
                Birthday.Text = Convert.ToString(dataGridView1.Rows[rowIndexLocal].Cells[6].Value);

                dataGridView1.CurrentCell = dataGridView1.Rows[rowIndexLocal].Cells[0];
            }
            else
            {
                pictureBox1.Image = Image.FromFile(@"UserPicture.png");

                Cod.Text = " ";
                NameLabel.Text = " ";
                LastName.Text = " ";
                idPas.Text = " ";
                Phone.Text = " ";
                Adres.Text = " ";
                Birthday.Text = " ";
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

        private void DataGridView1_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            pictureBox1.Image.Dispose();
            rowIndex = dataGridView1.CurrentCell.RowIndex;

            pictureBox1.Image = GetPhotoClient(Convert.ToInt32(dataGridView1.Rows[rowIndex].Cells[0].Value));

            Cod.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[0].Value);
            NameLabel.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[1].Value);
            LastName.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[2].Value);
            idPas.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[3].Value);
            Phone.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[4].Value);
            Adres.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[5].Value);
            Birthday.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[6].Value);

            checkBox1.Checked = false;
        }

        private void CheckBox1_CheckedChanged(object sender, EventArgs e)
        {
            if (checkBox1.Checked == true && dataGridView1.Rows.Count>0)
            {
                NameLabel.Visible = false;
                LastName.Visible = false;
                Birthday.Visible = false;
                Phone.Visible = false;
                idPas.Visible = false;
                Adres.Visible = false;

                NameBox.Visible = true;
                NameBox.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[1].Value);
                SurnameBox.Visible = true;
                SurnameBox.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[2].Value);
                DateBox.Visible = true;
                DateBox.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[6].Value);
                TelBox.Visible = true;
                TelBox.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[4].Value);
                IDBox.Visible = true;
                IDBox.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[3].Value);
                AdresBox.Visible = true;
                AdresBox.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[5].Value);

                button2.Visible = true;
                button6.Visible = true;
                button4.Visible = true;
                if (Worker.user.Cod_Worker == "1")
                    button3.Visible = true;
            }
            else
            {
                NameBox.Visible = false;
                SurnameBox.Visible = false;
                DateBox.Visible = false;
                TelBox.Visible = false;
                IDBox.Visible = false;
                AdresBox.Visible = false;
                button4.Visible = false;

                label4.Visible = false;

                NameLabel.Visible = true;
                LastName.Visible = true;
                Birthday.Visible = true;
                Phone.Visible = true;
                idPas.Visible = true;
                Adres.Visible = true;

                NameBox.Text = "";
                SurnameBox.Text = "";
                DateBox.Text = "";
                TelBox.Text = "";
                IDBox.Text = "";
                AdresBox.Text = "";

                button2.Visible = false;
                button6.Visible = false;
                if (Worker.user.Cod_Worker == "1")
                    button3.Visible = false;

            }
        }

        private void Button2_Click(object sender, EventArgs e)
        {
            checkBox1.Checked = false;
        }


        private void Button6_Click(object sender, EventArgs e)
        {
            label4.Visible = false;
            try
            {
                if (NameBox.Text.Length <= 1)
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

                NameBox.Text = NameBox.Text.ToLower();
                SurnameBox.Text = SurnameBox.Text.ToLower();

                NameBox.Text = char.ToUpper(NameBox.Text[0]) + NameBox.Text.Substring(1);
                SurnameBox.Text = char.ToUpper(SurnameBox.Text[0]) + SurnameBox.Text.Substring(1);

                if (!label4.Visible)
                {
                    ChangeClientInfo(Convert.ToInt32(dataGridView1.Rows[rowIndex].Cells[0].Value));

                    Bitmap imageClient = (Bitmap)GetPhotoClient(Convert.ToInt32(dataGridView1.Rows[rowIndex].Cells[0].Value));
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
                                Value = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[0].Value),
                            SqlDbType = SqlDbType.Int
                            };
                            command.Parameters.Add(param);

                            sqlConnection.Open();
                            command.ExecuteNonQuery();
                            sqlConnection.Close();
                            fStream.Dispose();
                            br.Dispose();
                            pPicture = @"UserPicture.png";
                        }

                        pictureBox1.Image = Image.FromFile(@"UserPicture.png");
                        File.Delete(@"ClientPicture.jpg");
                    }
                }


                checkBox1.Checked = false;

                DataGridView1_Refresh(rowIndex);
            }
            catch(Exception ex)
            {
                label4.Visible = true;
                label4.Text = ex.Message;
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


        private void ChangeClientInfo(int LocalRowIndex)
        {
            TelBox.TextMaskFormat = MaskFormat.ExcludePromptAndLiterals;

            string connectionString = @"Data Source=.\SQLEXPRESS;Initial Catalog=CarRent;Integrated Security=True";
            string sCommand = "Update Clients Set Client_Name = '" + NameBox.Text + "', Client_Surname = '" + SurnameBox.Text + "'," +
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

        private void Button3_Click(object sender, EventArgs e)
        {
            label4.Visible = false;
            try
            {
                using (SqlConnection sqlConnection = new SqlConnection(@"Data Source=.\SQLEXPRESS;Initial Catalog=CarRent;Integrated Security=True"))
                {
                    sqlConnection.Open();
                    SqlCommand command = new SqlCommand("Select Count(*) From Contracts Where Cod_Client = " + dataGridView1.Rows[rowIndex].Cells[0].Value + "", sqlConnection);
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
                label4.Visible = true;
                label4.Text = ex.Message;
            }
            
        }

        private void TextBox1_TextChanged(object sender, EventArgs e)
        {
            if (textBox1.Text.Length == 0) DataGridView1_Refresh(0);
        }

        private void NameBox_TextChanged(object sender, EventArgs e)
        {
            NameBox.Text = System.Text.RegularExpressions.Regex.Replace(NameBox.Text, @"[^а-яА-яЁё]", "");
            NameBox.SelectionStart = NameBox.Text.Length;
        }

        private void SurnameBox_TextChanged(object sender, EventArgs e)
        {
            SurnameBox.Text = System.Text.RegularExpressions.Regex.Replace(SurnameBox.Text, @"[^а-яА-яЁё]", "");
            SurnameBox.SelectionStart = SurnameBox.Text.Length;
        }

        private void AdresBox_TextChanged(object sender, EventArgs e)
        {
            AdresBox.Text = System.Text.RegularExpressions.Regex.Replace(AdresBox.Text, @"[^а-яА-Я0-9.,ёЁ ]", "");
            AdresBox.SelectionStart = AdresBox.Text.Length;
        }

        readonly OpenFileDialog openFileDialog = new OpenFileDialog
        {
            Filter = "Image files (*.jpg, *.jpeg, ) | *.jpg; *.jpeg; "
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

        private void Button4_Click(object sender, EventArgs e)
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

        private void button1_Click(object sender, EventArgs e)
        {
            pictureBox1.Image.Dispose();

            if (textBox1.Text.Length > 0)
            {
                bool Number = false;
                bool NameSurname = false;

                foreach (var ch in textBox1.Text)
                {

                    if (Char.IsNumber(ch))
                    {
                        Number = true;
                    }
                    if (ch >= 'а' && ch <= 'я' || ch >= 'А' && ch < 'Я') NameSurname = true;
                }

                string firstpart = textBox1.Text.Split(' ')[0];
                string secondpart = "";
                int position = textBox1.Text.IndexOf(' ');

                if (position != -1)
                    secondpart = textBox1.Text.Substring(position);


                using (SqlConnection sqlConnection = new SqlConnection(@"Data Source=.\SQLEXPRESS;Initial Catalog=CarRent;Integrated Security=True"))
                {
                    SqlCommand command = new SqlCommand("Select Cod_Client, Client_Name, Client_Surname, Client_PasID, Сlient_PhoneNumber, Client_Adres, Client_Birthday From Clients", sqlConnection);


                    if (NameSurname)
                    {
                        if (position != -1)
                            command = new SqlCommand("Select Cod_Client, Client_Name, Client_Surname, Client_PasID, Сlient_PhoneNumber, Client_Adres, Client_Birthday From Clients Where Client_Name like '%" + firstpart + "%' or Client_Name like '%" + secondpart + "%' or Client_Surname like '%" + secondpart + "%' or Client_Surname like '%" + firstpart + "%' or Client_Adres like '%" + secondpart + "%' or Client_Adres like '%" + firstpart + "%'", sqlConnection);
                        else
                            command = new SqlCommand("Select Cod_Client, Client_Name, Client_Surname, Client_PasID, Сlient_PhoneNumber, Client_Adres, Client_Birthday From Clients Where Client_Name like '%" + firstpart + "%' or Client_Surname like '%" + firstpart + "%' or Client_Adres like '%" + firstpart + "%'", sqlConnection);
                    }

                    if (Number)
                    {
                        command = new SqlCommand("Select Cod_Client, Client_Name, Client_Surname, Client_PasID, Сlient_PhoneNumber, Client_Adres, Client_Birthday From Clients Where Client_PasID like '%" + firstpart + "%' or Сlient_PhoneNumber like '%" + firstpart + "%' or Client_Adres like '%" + firstpart + "%' or Client_Birthday like '%" + firstpart + "%' or Cod_Client like '%" + firstpart + "%'", sqlConnection);
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
                    pictureBox1.Image = GetPhotoClient(Convert.ToInt32(dataGridView1.Rows[rowIndex].Cells[0].Value));

                    Cod.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[0].Value);
                    NameLabel.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[1].Value);
                    LastName.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[2].Value);
                    idPas.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[3].Value);
                    Phone.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[4].Value);
                    Adres.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[5].Value);
                    Birthday.Text = Convert.ToString(dataGridView1.Rows[rowIndex].Cells[6].Value);
                }
                else
                {
                    pictureBox1.Image = Image.FromFile(@"UserPicture.png");

                    Cod.Text = " ";
                    NameLabel.Text = " ";
                    LastName.Text = " ";
                    idPas.Text = " ";
                    Phone.Text = " ";
                    Adres.Text = " ";
                    Birthday.Text = " ";
                }
            }
        }

        private void TelBox_MaskInputRejected(object sender, MaskInputRejectedEventArgs e)
        {
            TelBox.SelectionStart = 7;
        }
    }
}
