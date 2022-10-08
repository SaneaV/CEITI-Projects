using System;
using System.Drawing;
using System.Drawing.Imaging;
using System.IO;
using System.Windows.Forms;


namespace CarRent
{
    public partial class UserProfil : UserControl
    {
        string pPicture = @"UserPicture.png";

        public UserProfil()
        {
            InitializeComponent();
            label19.Text = Worker.user.Name_Worker;
            label18.Text = Worker.user.Surname_Worker;
            if (Worker.user.Worker_PhoneNumber != "          ")
                label17.Text = ("+(373)" + Worker.user.Worker_PhoneNumber).Insert(9, "-");
            else label17.Text = "";
            label16.Text = Worker.user.Worker_Adres;
            label15.Text = Worker.user.Worker_Birthday;
            label14.Text = Worker.user.Login_Worker;
            label12.Text = Worker.user.Mail_Worker;
            label11.Text = Worker.user.Worker_PasID;
            pictureBox1.Image = Worker.user.GetPhoto();

            button6.Visible = false;
            button4.Visible = false;
            button3.Visible = false;
            button2.Visible = false;

            if (ImageFormat.Png.Equals(pictureBox1.Image.RawFormat))
                button1.Visible = true;
            else button1.Visible = false;

            NameTextBox.Visible = false;
            SurnameBox.Visible = false;
            TelBox.Visible = false;
            AdresBox.Visible = false;
            DateBox.Visible = false;
            IDBox.Visible = false;

            label20.Visible = false;

            if (Worker.user.Cod_Position != 1 && Worker.user.Cod_Position != 0)
                ChangeInfo.Dispose();


        }

        private void UserProfil_Refresh()
        {
            label19.Text = Worker.user.Name_Worker;
            label18.Text = Worker.user.Surname_Worker;
            label17.Text = Worker.user.Worker_PhoneNumber;
            if (Worker.user.Worker_PhoneNumber != "          ")
                label17.Text = ("+(373)" + Worker.user.Worker_PhoneNumber).Insert(9, "-");
            else label17.Text = "";
            label16.Text = Worker.user.Worker_Adres;
            label15.Text = Worker.user.Worker_Birthday;
            label14.Text = Worker.user.Login_Worker;
            label12.Text = Worker.user.Mail_Worker;
            label11.Text = Worker.user.Worker_PasID;
            pictureBox1.Image = Worker.user.GetPhoto();

            button6.Visible = false;
            button4.Visible = false;
            button3.Visible = false;
            button2.Visible = false;

            if (ImageFormat.Png.Equals(pictureBox1.Image.RawFormat))
            button1.Visible = true;
            else button1.Visible = false;

            NameTextBox.Visible = false;
            SurnameBox.Visible = false;
            TelBox.Visible = false;
            AdresBox.Visible = false;
            DateBox.Visible = false;
            IDBox.Visible = false;

            label20.Visible = false;

            if (Worker.user.Cod_Position != 0)
                ChangeInfo.Dispose();
        }


        readonly OpenFileDialog openFileDialog = new OpenFileDialog
        {
            Filter = "Image files (*.jpg, *.jpeg) | *.jpg; *.jpeg;"
        };


        private void Button1_Click(object sender, EventArgs e)
        {
            DialogResult res = openFileDialog.ShowDialog();
            if (res == DialogResult.OK)
            {
                pPicture = VaryQualityLevel(openFileDialog.FileName);
                pictureBox1.Image = Image.FromFile(pPicture);
            }
            openFileDialog.Dispose();

            button6.Visible = true;
            button2.Visible = true;
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
                bmp1.Save(@"UserPicture.jpg", jpgEncoder, myEncoderParameters);
                bmp1.Dispose();

                return @"UserPicture.jpg";
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


        private void Button6_Click(object sender, EventArgs e)
        {
            Worker.user.SetPhoto(pPicture);
            pPicture = @"UserPicture.png";
            pictureBox1.Image.Dispose();
            UserProfil_Refresh();

            File.Delete(@"UserPicture.jpg");
            button6.Visible = false;
            button2.Visible = false;

            using (FotoUpdated fotoUpdated = new FotoUpdated())
            {
                if (fotoUpdated.ShowDialog() == DialogResult.OK)
                { 
                }
            }
        }

        private void Button2_Click(object sender, EventArgs e)
        {
            label19.Visible = false;
            label18.Visible = false;
            label17.Visible = false;
            label16.Visible = false;
            label15.Visible = false;
            button3.Visible = true;

            button4.Visible = true;
            ChangeInfo.Enabled = false;
            button1.Enabled = false;

            NameTextBox.Visible = true;
            SurnameBox.Visible = true;
            TelBox.Visible = true;
            AdresBox.Visible = true;
            DateBox.Visible = true;
            IDBox.Visible = true;

        }

        private void Button4_Click(object sender, EventArgs e)
        {
            label20.Visible = false;

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

                if (age < 18) throw new Exception("Вам меньше 18 лет");
                if (age > 120) throw new Exception("Возможна ошибка в дате. Если всё верно, обратитесь к администратору");

                if (IDBox.Text.Length == 0)
                    throw new Exception("Поле серии паспорта пустое");

                if (IDBox.Text.Length != 13)
                    throw new Exception("Поле серии паспорта не полное");

                NameTextBox.Text.ToLower();
                SurnameBox.Text.ToLower();

                NameTextBox.Text = char.ToUpper(NameTextBox.Text[0]) + NameTextBox.Text.Substring(1);
                SurnameBox.Text = char.ToUpper(SurnameBox.Text[0]) + SurnameBox.Text.Substring(1);

                Worker.user.Name_Worker = NameTextBox.Text;
                Worker.user.Surname_Worker = SurnameBox.Text;
                Worker.user.Worker_PasID = IDBox.Text;
                TelBox.TextMaskFormat = MaskFormat.ExcludePromptAndLiterals;
                {
                    Worker.user.Worker_PhoneNumber = TelBox.Text;
                }
                Worker.user.Worker_Adres = AdresBox.Text;
                Worker.user.Worker_Birthday = DateBox.Text;

                Worker.user.UpdateData();

                label19.Visible = true;
                label18.Visible = true;
                label17.Visible = true;
                label16.Visible = true;
                label15.Visible = true;
                label14.Visible = true;
                button3.Visible = false;

                button4.Visible = false;
                ChangeInfo.Enabled = true;
                button1.Enabled = true;

                NameTextBox.Visible = false;
                SurnameBox.Visible = false;
                TelBox.Visible = false;
                AdresBox.Visible = false;
                DateBox.Visible = false;
                IDBox.Visible = false;

                UserProfil_Refresh();

                using (itsOkay itsOkay = new itsOkay()) 
                {
                    if(itsOkay.ShowDialog() == DialogResult.OK)
                    { }
                }
            }
            catch (Exception ex)
            {
                label20.Visible = true;
                label20.Text = ex.Message;
            } 
        }


        private void Button3_Click(object sender, EventArgs e)
        {
            label19.Visible = true;
            label18.Visible = true;
            label17.Visible = true;
            label16.Visible = true;
            label15.Visible = true;
            label14.Visible = true;
            button3.Visible = false;
            label20.Visible = false;

            button4.Visible = false;
            ChangeInfo.Enabled = true;
            button1.Enabled = true;

            NameTextBox.Visible = false;
            SurnameBox.Visible = false;
            TelBox.Visible = false;
            AdresBox.Visible = false;
            DateBox.Visible = false;
            IDBox.Visible = false;

        }

        private void Button2_Click_1(object sender, EventArgs e)
        {
            button6.Visible = false;
            button2.Visible = false;
            pictureBox1.Image = Worker.user.GetPhoto();
        }

        private void NameTextBox_TextChanged(object sender, EventArgs e)
        {
            NameTextBox.Text = System.Text.RegularExpressions.Regex.Replace(NameTextBox.Text, @"[^а-яА-ЯЁё-]", "");
            NameTextBox.SelectionStart = NameTextBox.Text.Length;
        }

        private void SurnameBox_TextChanged_1(object sender, EventArgs e)
        {
            SurnameBox.Text = System.Text.RegularExpressions.Regex.Replace(SurnameBox.Text, @"[^а-яА-ЯёЁ-]", "");
            SurnameBox.SelectionStart = SurnameBox.Text.Length;
        }

        private void AdresBox_TextChanged(object sender, EventArgs e)
        {
            AdresBox.Text = System.Text.RegularExpressions.Regex.Replace(AdresBox.Text, @"[^а-яА-Я0-9.,ёЁ ]", "");
            AdresBox.SelectionStart = AdresBox.Text.Length;
        }
    }
}
