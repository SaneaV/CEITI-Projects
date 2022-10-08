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

namespace CarRent
{
    public partial class GroupClients : UserControl
    {
        int page = 0;

        List<string> Names = new List<string>();
        List<string> Surnames = new List<string>();
        List<string> Cod = new List<string>();
        List<Label> labels = new List<Label>();
        List<PictureBox> pictureBoxes = new List<PictureBox>();

        public GroupClients()
        {
            InitializeComponent();
            button2.Visible = false;
            labels = new List<Label>() { label1, label2, label3, label4, label5,
                                                     label6, label7, label8, label9, label10,
                                                     label11, label12, label13, label14, label15,
                                                     label16, label17, label18, label19, label20};

            pictureBoxes = new List<PictureBox>() { pictureBox1, pictureBox2, pictureBox3,
                                                                     pictureBox4, pictureBox5, pictureBox6,
                                                                     pictureBox7, pictureBox8, pictureBox9,
                                                                     pictureBox10 };


            using (SqlConnection sqlConnection = new SqlConnection(@"Data Source=.\SQLEXPRESS;Initial Catalog=CarRent;Integrated Security=True"))
            {
                SqlCommand command = new SqlCommand("Select Cod_Client, Client_Name, Client_Surname From Clients", sqlConnection);
                sqlConnection.Open();

                using (SqlDataReader reader = command.ExecuteReader())
                {
                    while (reader.Read())
                    {
                        Cod.Add(reader["Cod_Client"].ToString());
                        Names.Add(reader["Client_Name"].ToString());
                        Surnames.Add(reader["Client_Surname"].ToString());
                    }
                }
                sqlConnection.Close();
            }

            foreach (var a in labels)
            {
                a.Text = "";
            }

            int index = 0;
            foreach (var a in Cod)
            {
                if (index != 10)
                {
                    pictureBoxes[index].Image = GetPhotoClient(Convert.ToInt32(a));
                    index++;
                }
                else break;

            }

            index = 0;
            foreach (var a in Names)
            {
                if (index != 20)
                {
                    labels[index].Text = a;
                    index += 2;
                }
                else break;

            }

            index = 1;
            foreach (var a in Surnames)
            {
                if (index != 21)
                {
                    labels[index].Text = a;
                    index += 2;
                }
                else break;
            }

            page = 0;
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            if (textBox1.Text.Length == 0) GroupList_Refresh();
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

        private void pictureBox12_Click(object sender, EventArgs e)
        {
            if (page == 0)
            {

            }
            else
            {
                GC.Collect();
                GC.WaitForPendingFinalizers();
                GC.Collect();
                page--;

                foreach (var a in labels)
                {
                    a.Text = "";
                }


                foreach (var a in pictureBoxes)
                {
                    a.Image = null;
                }

                int index = 0;
                foreach (var a in Cod.Skip(page * 10))
                {
                    if (index != 10)
                    {
                        pictureBoxes[index].Image = GetPhotoClient(Convert.ToInt32(a));
                        index++;
                    }
                    else break;

                }

                index = 0;
                foreach (var a in Names.Skip(page * 10))
                {
                    if (index != 20)
                    {
                        labels[index].Text = a;
                        index += 2;
                    }
                    else break;

                }

                index = 1;
                foreach (var a in Surnames.Skip(page * 10))
                {
                    if (index != 21)
                    {
                        labels[index].Text = a;
                        index += 2;
                    }
                    else break;
                }


                if (pictureBox1.Image != null)
                {
                    panel6.BorderStyle = BorderStyle.FixedSingle;
                }

                if (pictureBox2.Image != null)
                {
                    panel5.BorderStyle = BorderStyle.FixedSingle;
                }

                if (pictureBox3.Image != null)
                {
                    panel4.BorderStyle = BorderStyle.FixedSingle;
                }

                if (pictureBox4.Image != null)
                {
                    panel3.BorderStyle = BorderStyle.FixedSingle;
                }

                if (pictureBox5.Image != null)
                {
                    panel2.BorderStyle = BorderStyle.FixedSingle;
                }

                if (pictureBox6.Image != null)
                {
                    panel7.BorderStyle = BorderStyle.FixedSingle;
                }

                if (pictureBox7.Image != null)
                {
                    panel8.BorderStyle = BorderStyle.FixedSingle;
                }

                if (pictureBox8.Image != null)
                {
                    panel9.BorderStyle = BorderStyle.FixedSingle;
                }

                if (pictureBox9.Image != null)
                {
                    panel10.BorderStyle = BorderStyle.FixedSingle;
                }

                if (pictureBox10.Image != null)
                {
                    panel11.BorderStyle = BorderStyle.FixedSingle;
                }
            }
        }

        private void pictureBox11_Click(object sender, EventArgs e)
        {
            if(Cod.Count/10.0 <= page+1.0)
            {

            }
            else
            {
                GC.Collect();
                GC.WaitForPendingFinalizers();
                GC.Collect();
                page++;

                foreach (var a in labels)
                {
                    a.Text = "";
                }

                foreach (var a in pictureBoxes)
                {
                    a.Image = null;
                }

                int index = 0;
                foreach (var a in Cod.Skip(page * 10))
                {
                    if (index != 10)
                    {
                        pictureBoxes[index].Image = GetPhotoClient(Convert.ToInt32(a));
                        index++;
                    }
                    else break;

                }

                index = 0;
                foreach (var a in Names.Skip(page * 10))
                {
                    if (index != 20)
                    {
                        labels[index].Text = a;
                        index += 2;
                    }
                    else break;

                }

                index = 1;
                foreach (var a in Surnames.Skip(page * 10))
                {
                    if (index != 21)
                    {
                        labels[index].Text = a;
                        index += 2;
                    }
                    else break;
                }

                if (pictureBox1.Image != null)
                {
                    panel6.BorderStyle = BorderStyle.FixedSingle;
                }
                else
                {
                    panel6.BorderStyle = BorderStyle.None;
                }

                if (pictureBox2.Image != null)
                {
                    panel5.BorderStyle = BorderStyle.FixedSingle;
                }
                else
                {
                    panel5.BorderStyle = BorderStyle.None;
                }

                if (pictureBox3.Image != null)
                {
                    panel4.BorderStyle = BorderStyle.FixedSingle;
                }
                else
                {
                    panel4.BorderStyle = BorderStyle.None;
                }

                if (pictureBox4.Image != null)
                {
                    panel3.BorderStyle = BorderStyle.FixedSingle;
                }
                else
                {
                    panel3.BorderStyle = BorderStyle.None;
                }

                if (pictureBox5.Image != null)
                {
                    panel2.BorderStyle = BorderStyle.FixedSingle;
                }
                else
                {
                    panel2.BorderStyle = BorderStyle.None;
                }

                if (pictureBox6.Image != null)
                {
                    panel7.BorderStyle = BorderStyle.FixedSingle;
                }
                else
                {
                    panel7.BorderStyle = BorderStyle.None;
                }

                if (pictureBox7.Image != null)
                {
                    panel8.BorderStyle = BorderStyle.FixedSingle;
                }
                else
                {
                    panel8.BorderStyle = BorderStyle.None;
                }

                if (pictureBox8.Image != null)
                {
                    panel9.BorderStyle = BorderStyle.FixedSingle;
                }
                else
                {
                    panel9.BorderStyle = BorderStyle.None;
                }

                if (pictureBox9.Image != null)
                {
                    panel10.BorderStyle = BorderStyle.FixedSingle;
                }
                else
                {
                    panel10.BorderStyle = BorderStyle.None;
                }

                if (pictureBox10.Image != null)
                {
                    panel11.BorderStyle = BorderStyle.FixedSingle;
                }
                else
                {
                    panel11.BorderStyle = BorderStyle.None;
                }
            }
        }

        private void GroupList_Refresh()
        {
            Names.Clear();
            Surnames.Clear();
            Cod.Clear();
            using (SqlConnection sqlConnection = new SqlConnection(@"Data Source=.\SQLEXPRESS;Initial Catalog=CarRent;Integrated Security=True"))
            {
                SqlCommand command = new SqlCommand("Select Cod_Client, Client_Name, Client_Surname From Clients", sqlConnection);
                sqlConnection.Open();

                using (SqlDataReader reader = command.ExecuteReader())
                {
                    while (reader.Read())
                    {
                        Cod.Add(reader["Cod_Client"].ToString());
                        Names.Add(reader["Client_Name"].ToString());
                        Surnames.Add(reader["Client_Surname"].ToString());
                    }
                }
                sqlConnection.Close();
            }

            foreach (var a in labels)
            {
                a.Text = "";
            }

            foreach (var a in pictureBoxes)
            {
                a.Image = null;
            }


            int index = 0;
            foreach (var a in Cod)
            {
                if (index != 10)
                {
                    pictureBoxes[index].Image = GetPhotoClient(Convert.ToInt32(a));
                    index++;
                }
                else break;

            }

            index = 0;
            foreach (var a in Names)
            {
                if (index != 20)
                {
                    labels[index].Text = a;
                    index += 2;
                }
                else break;

            }

            index = 1;
            foreach (var a in Surnames)
            {
                if (index != 21)
                {
                    labels[index].Text = a;
                    index += 2;
                }
                else break;
            }

            page = 0;

            if (pictureBox1.Image != null)
            {
                panel6.BorderStyle = BorderStyle.FixedSingle;
            }
            else
            {
                panel6.BorderStyle = BorderStyle.None;
            }

            if (pictureBox2.Image != null)
            {
                panel5.BorderStyle = BorderStyle.FixedSingle;
            }
            else
            {
                panel5.BorderStyle = BorderStyle.None;
            }

            if (pictureBox3.Image != null)
            {
                panel4.BorderStyle = BorderStyle.FixedSingle;
            }
            else
            {
                panel4.BorderStyle = BorderStyle.None;
            }

            if (pictureBox4.Image != null)
            {
                panel3.BorderStyle = BorderStyle.FixedSingle;
            }
            else
            {
                panel3.BorderStyle = BorderStyle.None;
            }

            if (pictureBox5.Image != null)
            {
                panel2.BorderStyle = BorderStyle.FixedSingle;
            }
            else
            {
                panel2.BorderStyle = BorderStyle.None;
            }

            if (pictureBox6.Image != null)
            {
                panel7.BorderStyle = BorderStyle.FixedSingle;
            }
            else
            {
                panel7.BorderStyle = BorderStyle.None;
            }

            if (pictureBox7.Image != null)
            {
                panel8.BorderStyle = BorderStyle.FixedSingle;
            }
            else
            {
                panel8.BorderStyle = BorderStyle.None;
            }

            if (pictureBox8.Image != null)
            {
                panel9.BorderStyle = BorderStyle.FixedSingle;
            }
            else
            {
                panel9.BorderStyle = BorderStyle.None;
            }

            if (pictureBox9.Image != null)
            {
                panel10.BorderStyle = BorderStyle.FixedSingle;
            }
            else
            {
                panel10.BorderStyle = BorderStyle.None;
            }

            if (pictureBox10.Image != null)
            {
                panel11.BorderStyle = BorderStyle.FixedSingle;
            }
            else
            {
                panel11.BorderStyle = BorderStyle.None;
            }
        }


        private void button1_Click(object sender, EventArgs e)
        {
            if (textBox1.Text.Length != 0)
            {
                Names.Clear();
                Surnames.Clear();
                Cod.Clear();

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
                    SqlCommand command = new SqlCommand("Select Cod_Client, Client_Name, Client_Surname From Clients", sqlConnection);


                    if (NameSurname)
                    {
                        if (position != -1)
                            command = new SqlCommand("Select Cod_Client, Client_Name, Client_Surname From Clients Where Client_Name like '%" + firstpart + "%' or Client_Name like '%" + secondpart + "%' or Client_Surname like '%" + secondpart + "%' or Client_Surname like '%" + firstpart + "%' or Client_Adres like '%" + secondpart + "%' or Client_Adres like '%" + firstpart + "%'", sqlConnection);
                        else
                            command = new SqlCommand("Select Cod_Client, Client_Name, Client_Surname From Clients Where Client_Name like '%" + firstpart + "%' or Client_Surname like '%" + firstpart + "%' or Client_Adres like '%" + firstpart + "%'", sqlConnection);
                    }

                    if (Number)
                    {
                        command = new SqlCommand("Select Cod_Client, Client_Name, Client_Surname From Clients Where Client_PasID like '%" + firstpart + "%' or Сlient_PhoneNumber like '%" + firstpart + "%' or Client_Adres like '%" + firstpart + "%' or Client_Birthday like '%" + firstpart + "%' or Cod_Client like '%" + firstpart + "%'", sqlConnection);
                    }

                    sqlConnection.Open();
                    using (SqlDataReader reader = command.ExecuteReader())
                    {
                        while (reader.Read())
                        {
                            Cod.Add(reader["Cod_Client"].ToString());
                            Names.Add(reader["Client_Name"].ToString());
                            Surnames.Add(reader["Client_Surname"].ToString());
                        }
                    }
                    sqlConnection.Close();
                }

                foreach (var a in labels)
                {
                    a.Text = "";
                }


                foreach (var a in pictureBoxes)
                {
                    a.Image = null;
                }

                foreach (var a in labels)
                {
                    a.Text = "";
                }

                int index = 0;
                foreach (var a in Cod)
                {
                    if (index != 10)
                    {
                        pictureBoxes[index].Image = GetPhotoClient(Convert.ToInt32(a));
                        index++;
                    }
                    else break;

                }

                index = 0;
                foreach (var a in Names)
                {
                    if (index != 20)
                    {
                        labels[index].Text = a;
                        index += 2;
                    }
                    else break;

                }

                index = 1;
                foreach (var a in Surnames)
                {
                    if (index != 21)
                    {
                        labels[index].Text = a;
                        index += 2;
                    }
                    else break;
                }

                page = 0;

                if (pictureBox1.Image != null)
                {
                    panel6.BorderStyle = BorderStyle.FixedSingle;
                }
                else
                {
                    panel6.BorderStyle = BorderStyle.None;
                }

                if (pictureBox2.Image != null)
                {
                    panel5.BorderStyle = BorderStyle.FixedSingle;
                }
                else
                {
                    panel5.BorderStyle = BorderStyle.None;
                }

                if (pictureBox3.Image != null)
                {
                    panel4.BorderStyle = BorderStyle.FixedSingle;
                }
                else
                {
                    panel4.BorderStyle = BorderStyle.None;
                }

                if (pictureBox4.Image != null)
                {
                    panel3.BorderStyle = BorderStyle.FixedSingle;
                }
                else
                {
                    panel3.BorderStyle = BorderStyle.None;
                }

                if (pictureBox5.Image != null)
                {
                    panel2.BorderStyle = BorderStyle.FixedSingle;
                }
                else
                {
                    panel2.BorderStyle = BorderStyle.None;
                }

                if (pictureBox6.Image != null)
                {
                    panel7.BorderStyle = BorderStyle.FixedSingle;
                }
                else
                {
                    panel7.BorderStyle = BorderStyle.None;
                }

                if (pictureBox7.Image != null)
                {
                    panel8.BorderStyle = BorderStyle.FixedSingle;
                }
                else
                {
                    panel8.BorderStyle = BorderStyle.None;
                }

                if (pictureBox8.Image != null)
                {
                    panel9.BorderStyle = BorderStyle.FixedSingle;
                }
                else
                {
                    panel9.BorderStyle = BorderStyle.None;
                }

                if (pictureBox9.Image != null)
                {
                    panel10.BorderStyle = BorderStyle.FixedSingle;
                }
                else
                {
                    panel10.BorderStyle = BorderStyle.None;
                }

                if (pictureBox10.Image != null)
                {
                    panel11.BorderStyle = BorderStyle.FixedSingle;
                }
                else
                {
                    panel11.BorderStyle = BorderStyle.None;
                }
            }
        }

        private void panel6_Click(object sender, EventArgs e)
        {
            if (label1.Text != "")
            {
                AboutClientcs aboutClientcs = new AboutClientcs(Convert.ToInt32(Cod.ElementAt(page * 10)))
                {
                    Dock = DockStyle.Fill
                };
                this.panel1.Controls.Add(aboutClientcs);
                aboutClientcs.BringToFront();
                button2.Visible = true;
            }

        }

        private void panel5_Click(object sender, EventArgs e)
        {
            if (label3.Text != "")
            {
                AboutClientcs aboutClientcs = new AboutClientcs(Convert.ToInt32(Cod.ElementAt(page * 10 + 1)))
                {
                    Dock = DockStyle.Fill
                };
                this.panel1.Controls.Add(aboutClientcs);
                aboutClientcs.BringToFront();
                button2.Visible = true;
            }
        }

        private void panel4_Click(object sender, EventArgs e)
        {
            if (label5.Text != "")
            {
                AboutClientcs aboutClientcs = new AboutClientcs(Convert.ToInt32(Cod.ElementAt(page * 10 + 2)))
                {
                    Dock = DockStyle.Fill
                };
                this.panel1.Controls.Add(aboutClientcs);
                aboutClientcs.BringToFront();
                button2.Visible = true;
            }
        }

        private void panel3_Click(object sender, EventArgs e)
        {
            if (label7.Text != "")
            {
                AboutClientcs aboutClientcs = new AboutClientcs(Convert.ToInt32(Cod.ElementAt(page * 10 + 3)))
                {
                    Dock = DockStyle.Fill
                };
                this.panel1.Controls.Add(aboutClientcs);
                aboutClientcs.BringToFront();
                button2.Visible = true;
            }
        }

        private void panel2_Click(object sender, EventArgs e)
        {
            if (label9.Text != "")
            {
                AboutClientcs aboutClientcs = new AboutClientcs(Convert.ToInt32(Cod.ElementAt(page * 10 + 4)))
                {
                    Dock = DockStyle.Fill
                };
                this.panel1.Controls.Add(aboutClientcs);
                aboutClientcs.BringToFront();
                button2.Visible = true;
            }
        }

        private void panel7_Click(object sender, EventArgs e)
        {
            if (label11.Text != "")
            {
                AboutClientcs aboutClientcs = new AboutClientcs(Convert.ToInt32(Cod.ElementAt(page * 10 + 5)))
                {
                    Dock = DockStyle.Fill
                };
                this.panel1.Controls.Add(aboutClientcs);
                aboutClientcs.BringToFront();
                button2.Visible = true;
            }
        }

        private void panel8_Click(object sender, EventArgs e)
        {
            if (label13.Text != "")
            {
                AboutClientcs aboutClientcs = new AboutClientcs(Convert.ToInt32(Cod.ElementAt(page * 10 + 6)))
                {
                    Dock = DockStyle.Fill
                };
                this.panel1.Controls.Add(aboutClientcs);
                aboutClientcs.BringToFront();
                button2.Visible = true;
            }
        }

        private void panel9_Click(object sender, EventArgs e)
        {
            if (label15.Text != "")
            {
                AboutClientcs aboutClientcs = new AboutClientcs(Convert.ToInt32(Cod.ElementAt(page * 10 + 7)))
                {
                    Dock = DockStyle.Fill
                };
                this.panel1.Controls.Add(aboutClientcs);
                aboutClientcs.BringToFront();
                button2.Visible = true;
            }
        }

        private void panel10_Click(object sender, EventArgs e)
        {
            if (label17.Text != "")
            {
                AboutClientcs aboutClientcs = new AboutClientcs(Convert.ToInt32(Cod.ElementAt(page * 10 + 8)))
                {
                    Dock = DockStyle.Fill
                };
                this.panel1.Controls.Add(aboutClientcs);
                aboutClientcs.BringToFront();
                button2.Visible = true;
            }
        }

        private void panel11_Click(object sender, EventArgs e)
        {
            if (label9.Text != "")
            {
                AboutClientcs aboutClientcs = new AboutClientcs(Convert.ToInt32(Cod.ElementAt(page * 10 + 9)))
                {
                    Dock = DockStyle.Fill
                };
                this.panel1.Controls.Add(aboutClientcs);
                aboutClientcs.BringToFront();
                button2.Visible = true;
            }
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {
            panel6_Click(sender, e);
        }

        private void pictureBox2_Click(object sender, EventArgs e)
        {
            panel5_Click(sender, e);
        }

        private void pictureBox3_Click(object sender, EventArgs e)
        {
            panel4_Click(sender, e);
        }

        private void pictureBox4_Click(object sender, EventArgs e)
        {
            panel3_Click(sender, e);
        }

        private void pictureBox5_Click(object sender, EventArgs e)
        {
            panel2_Click(sender, e);
        }

        private void pictureBox6_Click(object sender, EventArgs e)
        {
            panel7_Click(sender, e);
        }

        private void pictureBox7_Click(object sender, EventArgs e)
        {
            panel8_Click(sender, e);
        }

        private void pictureBox8_Click(object sender, EventArgs e)
        {
            panel9_Click(sender, e);
        }

        private void pictureBox9_Click(object sender, EventArgs e)
        {
            panel10_Click(sender, e);
        }

        private void pictureBox10_Click(object sender, EventArgs e)
        {
            panel11_Click(sender, e);
        }

        private void label2_Click(object sender, EventArgs e)
        {
            panel6_Click(sender, e);
        }

        private void label1_Click(object sender, EventArgs e)
        {
            panel6_Click(sender, e);
        }

        private void label4_Click(object sender, EventArgs e)
        {
            panel4_Click(sender, e);
        }

        private void label3_Click(object sender, EventArgs e)
        {
            panel4_Click(sender, e);
        }

        private void label6_Click(object sender, EventArgs e)
        {
            panel3_Click(sender, e);
        }

        private void label5_Click(object sender, EventArgs e)
        {
            panel3_Click(sender, e);
        }

        private void label8_Click(object sender, EventArgs e)
        {
            panel2_Click(sender, e);
        }

        private void label7_Click(object sender, EventArgs e)
        {
            panel2_Click(sender, e);
        }

        private void label11_Click(object sender, EventArgs e)
        {
            panel7_Click(sender, e);
        }

        private void label12_Click(object sender, EventArgs e)
        {
            panel7_Click(sender, e);
        }

        private void label13_Click(object sender, EventArgs e)
        {
            panel8_Click(sender, e);
        }

        private void label14_Click(object sender, EventArgs e)
        {
            panel8_Click(sender, e);
        }

        private void label16_Click(object sender, EventArgs e)
        {
            panel9_Click(sender, e);
        }

        private void label15_Click(object sender, EventArgs e)
        {
            panel9_Click(sender, e);
        }

        private void label18_Click(object sender, EventArgs e)
        {
            panel10_Click(sender, e);
        }

        private void label17_Click(object sender, EventArgs e)
        {
            panel10_Click(sender, e);
        }

        private void label19_Click(object sender, EventArgs e)
        {
            panel11_Click(sender, e);
        }

        private void label20_Click(object sender, EventArgs e)
        {
            panel11_Click(sender, e);
        }

        private void button2_Click(object sender, EventArgs e)
        {
            GroupList_Refresh();
            button2.Visible = false;
        }

        private void GroupClients_Load(object sender, EventArgs e)
        {
            if (pictureBox1.Image != null)
            {
                panel6.BorderStyle = BorderStyle.FixedSingle;
            }
            else
            {
                panel6.BorderStyle = BorderStyle.None;
            }

            if (pictureBox2.Image != null)
            {
                panel5.BorderStyle = BorderStyle.FixedSingle;
            }
            else
            {
                panel5.BorderStyle = BorderStyle.None;
            }

            if (pictureBox3.Image != null)
            {
                panel4.BorderStyle = BorderStyle.FixedSingle;
            }
            else
            {
                panel4.BorderStyle = BorderStyle.None;
            }

            if (pictureBox4.Image != null)
            {
                panel3.BorderStyle = BorderStyle.FixedSingle;
            }
            else
            {
                panel3.BorderStyle = BorderStyle.None;
            }

            if (pictureBox5.Image != null)
            {
                panel2.BorderStyle = BorderStyle.FixedSingle;
            }
            else
            {
                panel2.BorderStyle = BorderStyle.None;
            }

            if (pictureBox6.Image != null)
            {
                panel7.BorderStyle = BorderStyle.FixedSingle;
            }
            else
            {
                panel7.BorderStyle = BorderStyle.None;
            }

            if (pictureBox7.Image != null)
            {
                panel8.BorderStyle = BorderStyle.FixedSingle;
            }
            else
            {
                panel8.BorderStyle = BorderStyle.None;
            }

            if (pictureBox8.Image != null)
            {
                panel9.BorderStyle = BorderStyle.FixedSingle;
            }
            else
            {
                panel9.BorderStyle = BorderStyle.None;
            }

            if (pictureBox9.Image != null)
            {
                panel10.BorderStyle = BorderStyle.FixedSingle;
            }
            else
            {
                panel10.BorderStyle = BorderStyle.None;
            }

            if (pictureBox10.Image != null)
            {
                panel11.BorderStyle = BorderStyle.FixedSingle;
            }
            else
            {
                panel11.BorderStyle = BorderStyle.None;
            }
        }
    }
}
