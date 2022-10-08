using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CarRent
{
    public partial class NewLogPasMail : Form
    {
        int VisiblePass = 0;

        public NewLogPasMail()
        {
            InitializeComponent();
            label4.Visible = false;
        }

        private void OK_Click(object sender, EventArgs e)
        {
            label4.Visible = false;
                try
                {
                    if (Login_Box.TextLength == 0) throw new Exception("Поле логина пустое!");
                    if (Pass_Box.TextLength == 0) throw new Exception("Поле пароля пустое!");
                    if (Mail_Box.TextLength == 0) throw new Exception("Поле почты пустое!");

                    int dogs = 0;
                    int points = 0;
                    foreach (char c in Mail_Box.Text)
                    {
                        if (c.Equals('@')) dogs++;
                        if (c.Equals('.')) points++;
                    }
                    if (dogs >= 2 || dogs == 0 || points == 0 || points >= 2) throw new Exception("Поле почты содержит ошибки");


                    if (Mail_Box.Text[0].Equals('@') || Mail_Box.Text[0].Equals('.') ||
                        Mail_Box.Text[Mail_Box.Text.Length - 1].Equals('@') || Mail_Box.Text[Mail_Box.Text.Length - 1].Equals('.'))
                        throw new Exception("Поле почты содержит ошибки");

                    Mail_Box.Text = Mail_Box.Text.ToLower();
                    Login_Box.Text = Login_Box.Text.ToLower();

                string connectionString = @"Data Source=.\SQLEXPRESS;Initial Catalog=CarRent;Integrated Security=True";

                using (SqlConnection connection = new SqlConnection(connectionString))
                {

                    SqlCommand command = new SqlCommand("Select Count(*) From Worker_LoginTable Where Worker_Login = '" + Login_Box.Text + "'", connection);

                    connection.Open();
                    int i = (int)command.ExecuteScalar();

                    if (i > 0)
                    {
                        connection.Close();
                        throw new Exception("Данный логин занят!");
                    }

                    command = new SqlCommand("Select Count(*) From Worker_LoginTable Where Worker_Mail = '" + Mail_Box.Text + "'", connection);
                    i = (int)command.ExecuteScalar();

                    if (i > 0)
                    {
                        connection.Close();
                        throw new Exception("Данная почта занята!");
                    }

                    var result = command.ExecuteScalar();
                    connection.Close();
                }

                if(label4.Visible == false)
                Worker.user.UpdateLogMailPas(Login_Box.Text, Pass_Box.Text, Mail_Box.Text);

                }
                catch (Exception ex)
                {
                    label4.Visible = true;
                    label4.Text = ex.Message;
                }

            if (!label4.Visible) this.DialogResult = DialogResult.OK;
        }



        //====================Правила текста в Логине====================
        private void Login_Box_TextChanged(object sender, EventArgs e)
        {
            Login_Box.Text = System.Text.RegularExpressions.Regex.Replace(Login_Box.Text, @"[^a-zA-Z0-9_.]", "");
            if (Login_Box.SelectionStart == 0)
                Login_Box.SelectionStart = Login_Box.Text.Length;
        }

        //====================Правила текста в Пароле====================
        private void Pass_Box_TextChanged(object sender, EventArgs e)
        {
            Pass_Box.Text = System.Text.RegularExpressions.Regex.Replace(Pass_Box.Text, @"[^a-zA-Z0-9!@#$%^&*()_+=-]", "");
            if (Pass_Box.SelectionStart == 0)
                Pass_Box.SelectionStart = Pass_Box.Text.Length;
        }

        //====================Правила текста в Почте====================
        private void Mail_Box_TextChanged(object sender, EventArgs e)
        {
            Mail_Box.Text = System.Text.RegularExpressions.Regex.Replace(Mail_Box.Text, @"[^a-zA-Z0-9_.@]", "");
            if (Mail_Box.SelectionStart == 0)
                Mail_Box.SelectionStart = Mail_Box.Text.Length;
        }


        //====================Видмость пароля====================
        private void Button4_Click(object sender, EventArgs e)
        {
            if (VisiblePass == 1)
            {
                Pass_Box.UseSystemPasswordChar = true;
                VisiblePass = 0;
            }
            else
            {
                Pass_Box.UseSystemPasswordChar = false;
                VisiblePass = 1;
            }

        }
    }
}
