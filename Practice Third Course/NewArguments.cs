using System;
using System.Data.SqlClient;
using System.Drawing;
using System.Windows.Forms;

namespace CarRent
{
    public partial class NewArguments : UserControl
    {
        public NewArguments()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            label6.Visible = false;
            if (textBox1.TextLength > 0)
            {
                textBox1.Text = textBox1.Text.ToLower();
                textBox1.Text = char.ToUpper(textBox1.Text[0]) + textBox1.Text.Substring(1);
                string connectionString = @"Data Source=.\SQLEXPRESS;Initial Catalog=CarRent;Integrated Security=True";
                using (SqlConnection connection = new SqlConnection(connectionString))
                {
                    try
                    {
                        SqlCommand command = new SqlCommand("Select Count(*) from Car_Color where Color = '" + textBox1.Text + "'", connection);

                        connection.Open();
                        int i = (int)command.ExecuteScalar();
                        connection.Close();
                        if (i == 1) throw new Exception("Такой цвет уже существует");


                        command = new SqlCommand("INSERT INTO Car_Color (Color) VALUES ('" + textBox1.Text + "')", connection);
                        connection.Open();
                        command.ExecuteNonQuery();
                        connection.Close();

                        label6.ForeColor = Color.Green;
                        label6.Visible = true;
                        label6.Text = "Новый цвет добавлен";
                    }
                    catch (Exception ex)
                    {
                        label6.ForeColor = Color.Red;
                        label6.Visible = true;
                        label6.Text = ex.Message;
                    }
                }
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            label6.Visible = false;
            if (textBox2.TextLength > 0)
            {
                textBox2.Text = textBox2.Text.ToLower();
                textBox2.Text = char.ToUpper(textBox2.Text[0]) + textBox2.Text.Substring(1);
                string connectionString = @"Data Source=.\SQLEXPRESS;Initial Catalog=CarRent;Integrated Security=True";
                using (SqlConnection connection = new SqlConnection(connectionString))
                {
                    try
                    {
                        SqlCommand command = new SqlCommand("Select Count(*) from Car_Fuel where Fuel = '" + textBox2.Text + "'", connection);

                        connection.Open();
                        int i = (int)command.ExecuteScalar();
                        connection.Close();
                        if (i == 1) throw new Exception("Такой тип топлива уже существует");


                        command = new SqlCommand("INSERT INTO Cod_Fuel (Fuel) VALUES ('" + textBox2.Text + "')", connection);
                        connection.Open();
                        command.ExecuteNonQuery();
                        connection.Close();

                        label6.ForeColor = Color.Green;
                        label6.Visible = true;
                        label6.Text = "Новый тип топлива добавлен";
                    }
                    catch (Exception ex)
                    {
                        label6.ForeColor = Color.Red;
                        label6.Visible = true;
                        label6.Text = ex.Message;
                    }
                }
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            label6.Visible = false;
            if (textBox3.TextLength > 0)
            {
                textBox3.Text = textBox3.Text.ToLower();
                textBox3.Text = char.ToUpper(textBox3.Text[0]) + textBox3.Text.Substring(1);
                string connectionString = @"Data Source=.\SQLEXPRESS;Initial Catalog=CarRent;Integrated Security=True";
                using (SqlConnection connection = new SqlConnection(connectionString))
                {
                    try
                    {
                        SqlCommand command = new SqlCommand("Select Count(*) from Car_Marka where Marka = '" + textBox3.Text + "'", connection);

                        connection.Open();
                        int i = (int)command.ExecuteScalar();
                        connection.Close();
                        if (i == 1) throw new Exception("Такая марка уже существует");


                        command = new SqlCommand("INSERT INTO Car_Marka(Marka) VALUES ('" + textBox3.Text + "')", connection);
                        connection.Open();
                        command.ExecuteNonQuery();
                        connection.Close();

                        label6.ForeColor = Color.Green;
                        label6.Visible = true;
                        label6.Text = "Новая марка была добавлена";
                    }
                    catch (Exception ex)
                    {
                        label6.ForeColor = Color.Red;
                        label6.Visible = true;
                        label6.Text = ex.Message;
                    }
                }
            }
        }

        private void button4_Click(object sender, EventArgs e)
        {
            label6.Visible = false;
            if (textBox4.TextLength > 0)
            {
                textBox4.Text = textBox4.Text.ToLower();
                textBox4.Text = char.ToUpper(textBox4.Text[0]) + textBox4.Text.Substring(1);
                string connectionString = @"Data Source=.\SQLEXPRESS;Initial Catalog=CarRent;Integrated Security=True";
                using (SqlConnection connection = new SqlConnection(connectionString))
                {
                    try
                    {
                        SqlCommand command = new SqlCommand("Select Count(*) from Car_Transmission where Transmission = '" + textBox4.Text + "'", connection);

                        connection.Open();
                        int i = (int)command.ExecuteScalar();
                        connection.Close();
                        if (i == 1) throw new Exception("Такой тип трансмиссии уже существует");


                        command = new SqlCommand("INSERT INTO Car_Transmission(Transmission) VALUES ('" + textBox4.Text + "')", connection);
                        connection.Open();
                        command.ExecuteNonQuery();
                        connection.Close();

                        label6.ForeColor = Color.Green;
                        label6.Visible = true;
                        label6.Text = "Новый тип трансмиссии был добавлен";
                    }
                    catch (Exception ex)
                    {
                        label6.ForeColor = Color.Red;
                        label6.Visible = true;
                        label6.Text = ex.Message;
                    }
                }
            }
        }

        private void button5_Click(object sender, EventArgs e)
        {
            label6.Visible = false;
            if (textBox5.TextLength > 0)
            {
                textBox5.Text = textBox5.Text.ToLower();
                textBox5.Text = char.ToUpper(textBox5.Text[0]) + textBox5.Text.Substring(1);
                string connectionString = @"Data Source=.\SQLEXPRESS;Initial Catalog=CarRent;Integrated Security=True";
                using (SqlConnection connection = new SqlConnection(connectionString))
                {
                    try
                    {
                        SqlCommand command = new SqlCommand("Select Count(*) from Car_Type where NameType = '" + textBox5.Text + "'", connection);

                        connection.Open();
                        int i = (int)command.ExecuteScalar();
                        connection.Close();
                        if (i == 1) throw new Exception("Такой тип кузова уже существует");


                        command = new SqlCommand("INSERT INTO Car_Type(NameType) VALUES ('" + textBox5.Text + "')", connection);
                        connection.Open();
                        command.ExecuteNonQuery();
                        connection.Close();

                        label6.ForeColor = Color.Green;
                        label6.Visible = true;
                        label6.Text = "Новый тип кузова был добавлен";
                    }
                    catch (Exception ex)
                    {
                        label6.ForeColor = Color.Red;
                        label6.Visible = true;
                        label6.Text = ex.Message;
                    }
                }
            }
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            textBox1.Text = System.Text.RegularExpressions.Regex.Replace(textBox1.Text, @"[^а-яА-ЯЁё-]", "");
            textBox1.SelectionStart = textBox1.Text.Length;
        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {
            textBox2.Text = System.Text.RegularExpressions.Regex.Replace(textBox2.Text, @"[^а-яА-ЯЁё-]", "");
            textBox2.SelectionStart = textBox2.Text.Length;
        }

        private void textBox3_TextChanged(object sender, EventArgs e)
        {
            textBox3.Text = System.Text.RegularExpressions.Regex.Replace(textBox3.Text, @"[^a-zA-Z-]", "");
            textBox3.SelectionStart = textBox3.Text.Length;
        }

        private void textBox4_TextChanged(object sender, EventArgs e)
        {
            textBox4.Text = System.Text.RegularExpressions.Regex.Replace(textBox4.Text, @"[^а-яА-ЯЁё-]", "");
            textBox4.SelectionStart = textBox4.Text.Length;
        }

        private void textBox5_TextChanged(object sender, EventArgs e)
        {
            textBox5.Text = System.Text.RegularExpressions.Regex.Replace(textBox5.Text, @"[^а-яА-ЯЁё-]", "");
            textBox5.SelectionStart = textBox5.Text.Length;
        }
    }
}
