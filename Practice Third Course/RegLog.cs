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
    public partial class RegLog : Form
    {
        int VisiblePass = 0;

        public RegLog(int Value)
        {
            InitializeComponent();
            if (Value == 1) Login_Click(this, EventArgs.Empty);
            if (Value == 2) Register_Click(this, EventArgs.Empty);
            this.Value = Value;

            Login_Box.Select();
            
        }

        int Value;


        private void Login_Click(object sender, EventArgs e)
        {
            Value = 1;
            this.Height = 163;
            OK.Top = 134;
            Cancel.Top = 134;
            label4.Top = 107;
            label4.Visible = false;

            Mail_Box.Visible = false;
            MailLabel.Visible = false;
        }

        private void Register_Click(object sender, EventArgs e)
        {
            this.Value = 2;
            this.Height = 213;
            OK.Top = 174;
            Cancel.Top = 174;
            label4.Top = 136;
            label4.Visible = false;

            Mail_Box.Visible = true;
            MailLabel.Visible = true;
        }

        private void OK_Click(object sender, EventArgs e)
        {
            label4.Visible = false;

            if (Value == 1)
            {
                try
                {
                    if (Login_Box.TextLength == 0) throw new Exception("Поле логина пустое!");
                    if (Pass_Box.TextLength == 0) throw new Exception("Поле пароля пустое!");
                    Login_Box.Text = Login_Box.Text.ToLower();

                    string connectionString = @"Data Source=.\SQLEXPRESS;Initial Catalog=CarRent;Integrated Security=True;Connect Timeout = '150'";
                    string userLogin;
                    string passwordDB;
                    bool find = false;

                    using (SqlConnection connection = new SqlConnection(connectionString))
                    {
                        SqlCommand command = new SqlCommand();
                        command = new SqlCommand("SELECT Cod_Worker, Worker_Login, Worker_Password, Worker_Mail FROM Worker_LoginTable", connection);
                        connection.Open();
                        SqlDataReader rd = command.ExecuteReader();

                        while (!find && rd.Read())
                        {
                            userLogin = rd["Worker_Login"].ToString();
                            passwordDB = rd["Worker_Password"].ToString();

                            if (Login_Box.Text == userLogin && Pass_Box.Text == passwordDB)
                            {
                                Worker.user.Cod_Worker = rd["Cod_Worker"].ToString();
                                Worker.user.Login_Worker = rd["Worker_Login"].ToString();
                                Worker.user.Password_Worker = rd["Worker_Password"].ToString();
                                Worker.user.Mail_Worker = rd["Worker_Mail"].ToString();
                                connection.Close();

                                command = new SqlCommand("SELECT Worker_Name, Worker_Surname, Worker_PasID," +
                                        "Worker_PhoneNumber, Worker_Adres, Worker_Birthday," +
                                        "Cod_Position from Workers Where Cod_Worker = '" + Worker.user.Cod_Worker + "'", connection);
                                connection.Open();
                                rd = command.ExecuteReader();

                                while (!find && rd.Read())
                                {
                                                Worker.user.Name_Worker = rd["Worker_Name"].ToString();
                                                Worker.user.Surname_Worker = rd["Worker_Surname"].ToString();
                                                Worker.user.Worker_PasID = rd["Worker_PasID"].ToString();
                                                Worker.user.Worker_PhoneNumber = rd["Worker_PhoneNumber"].ToString();
                                                Worker.user.Worker_Adres = rd["Worker_Adres"].ToString();
                                                Worker.user.Worker_Birthday = rd["Worker_Birthday"].ToString();
                                                Worker.user.Cod_Position = Convert.ToInt32(rd["Cod_Position"].ToString());
                                                connection.Close();
                                                find = true;
                                }
                            }

                            if (Login_Box.Text == userLogin && Pass_Box.Text != passwordDB)
                            {
                                connection.Close();
                                throw new Exception("Пароль введён неверно.");
                            }
                        }
                    }
                    if (!find) throw new Exception("Такого пользователя не существует.");
                }
                catch (Exception ex)
                {
                    label4.Visible = true;
                    label4.Text = ex.Message;
                }
            }
            
            else if (Value == 2)
            {
                try
                {
                    if (Login_Box.TextLength == 0) throw new Exception("Поле логина пустое!");
                    if (Pass_Box.TextLength <= 4) throw new Exception("Пароль слишком простой!");
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

                        command = new SqlCommand("Select Count(*) From Worker_LoginTable Where Worker_Mail = '" + Mail_Box.Text +"'", connection);
                        i = (int)command.ExecuteScalar();

                        if (i > 0)
                        {
                            connection.Close();
                            throw new Exception("Данная почта занята!");
                        }

                        command = new SqlCommand("InsertLogData", connection)
                        {
                            CommandType = CommandType.StoredProcedure
                        };
                        command.Parameters.AddWithValue("@Worker_Login", Login_Box.Text);
                        command.Parameters.AddWithValue("@Worker_Password", Pass_Box.Text);
                        command.Parameters.AddWithValue("@Worker_Mail", Mail_Box.Text);

                        var result = command.ExecuteScalar();
                        connection.Close();

                        Value = 1;
                        OK_Click(this, EventArgs.Empty);
                    }
                
                }
                catch (Exception ex)
                {
                    label4.Visible = true;
                    label4.Text = ex.Message;
                }
            }
            if (!label4.Visible) this.DialogResult = DialogResult.OK;
        }

        //====================Правила текста в Логине====================
        private void Login_Box_TextChanged(object sender, EventArgs e)
        {
            Login_Box.Text = System.Text.RegularExpressions.Regex.Replace(Login_Box.Text, @"[^a-zA-Z0-9_.]", "");
            if(Login_Box.SelectionStart == 0)
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
