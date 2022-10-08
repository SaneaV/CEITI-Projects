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
    public partial class GroupCar : UserControl
    {
        List<string> Marka = new List<string>();
        List<string> Model = new List<string>();
        List<string> Cod = new List<string>();
        List<Label> labels = new List<Label>();
        List<PictureBox> pictureBoxes = new List<PictureBox>();
        int page;
        List<string> ListAddition = new List<string>();

        public GroupCar()
        {
            InitializeComponent();

            labels = new List<Label>() { label3, label4, label5,
                                         label6, label7, label8 };

            pictureBoxes = new List<PictureBox>() { pictureBox1, pictureBox2, pictureBox3};

            using (SqlConnection sqlConnection = new SqlConnection(@"Data Source=.\SQLEXPRESS;Initial Catalog=CarRent;Integrated Security=True"))
            {
                SqlCommand command = new SqlCommand("Select Cod_Car, Marka, Car_Model From AllInfoCar", sqlConnection);
                sqlConnection.Open();

                using (SqlDataReader reader = command.ExecuteReader())
                {
                    while (reader.Read())
                    {
                        Cod.Add(reader["Cod_Car"].ToString());
                        Marka.Add(reader["Marka"].ToString());
                        Model.Add(reader["Car_Model"].ToString());
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
                if (index != 3)
                {
                    pictureBoxes[index].Image = GetPhotoCar(Convert.ToInt32(a));
                    index++;
                }
                else break;

            }

            index = 0;
            foreach (var a in Marka)
            {
                if (index != 6)
                {
                    labels[index].Text = a;
                    index += 2;
                }
                else break;

            }

            index = 1;
            foreach (var a in Model)
            {
                if (index != 7)
                {
                    labels[index].Text = a;
                    index += 2;
                }
                else break;
            }

            page = 0;
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


        private void button8_Click(object sender, EventArgs e)
        {
            textBox1.Text = "";
            textBox4.Text = "";
            comboBox7.SelectedIndex = -1;
            comboBox8.SelectedIndex = -1;
            comboBox9.SelectedIndex = -1;
            comboBox10.SelectedIndex = -1;
            comboBox11.SelectedIndex = -1;
            comboBox12.SelectedIndex = -1;
            comboBox13.SelectedIndex = -1;

            numericUpDown6.Value = 1;
            numericUpDown5.Value = 15;

            numericUpDown3.Value = 10;
            numericUpDown4.Value = 500;

            richTextBox2.Text = "";

            GroupList_Refresh();
        }

        private void GroupCar_Load(object sender, EventArgs e)
        {
            using (SqlConnection sqlConnection = new SqlConnection(@"Data Source=.\SQLEXPRESS;Initial Catalog=CarRent;Integrated Security=True"))
            {
                SqlCommand command = new SqlCommand("Select Marka from Car_Marka", sqlConnection);
                sqlConnection.Open();

                DataTable table = new DataTable();
                DataTable table2 = new DataTable();
                SqlDataAdapter sqlDataAdapter = new SqlDataAdapter(command);
                sqlDataAdapter.Fill(table);
                comboBox13.DataSource = table;
                comboBox13.DisplayMember = "Marka";
                comboBox13.SelectedIndex = -1;

                command = new SqlCommand("Select Color from Car_Color", sqlConnection);
                table = new DataTable();
                sqlDataAdapter = new SqlDataAdapter(command);
                sqlDataAdapter.Fill(table);
                comboBox12.DataSource = table;
                comboBox12.DisplayMember = "Color";
                comboBox12.SelectedIndex = -1;

                command = new SqlCommand("Select Fuel from Car_Fuel", sqlConnection);
                table = new DataTable();
                sqlDataAdapter = new SqlDataAdapter(command);
                sqlDataAdapter.Fill(table);
                comboBox11.DataSource = table;
                comboBox11.DisplayMember = "Fuel";
                comboBox11.SelectedIndex = -1;

                command = new SqlCommand("Select Transmission from Car_Transmission", sqlConnection);
                table = new DataTable();
                sqlDataAdapter = new SqlDataAdapter(command);
                sqlDataAdapter.Fill(table);
                comboBox10.DataSource = table;
                comboBox10.DisplayMember = "Transmission";
                comboBox10.SelectedIndex = -1;

                command = new SqlCommand("Select NameType from Car_Type", sqlConnection);
                table = new DataTable();
                sqlDataAdapter = new SqlDataAdapter(command);
                sqlDataAdapter.Fill(table);
                comboBox9.DataSource = table;
                comboBox9.DisplayMember = "NameType";
                comboBox9.SelectedIndex = -1;

                command = new SqlCommand("Select NameStatus from Reference_Status", sqlConnection);
                table = new DataTable();
                sqlDataAdapter = new SqlDataAdapter(command);
                sqlDataAdapter.Fill(table);
                comboBox8.DataSource = table;
                comboBox8.DisplayMember = "NameStatus";
                comboBox8.SelectedIndex = -1;

                command = new SqlCommand("Select distinct (Additionaly) from Car_Additionaly", sqlConnection);
                table = new DataTable();
                sqlDataAdapter = new SqlDataAdapter(command);
                sqlDataAdapter.Fill(table);
                comboBox7.DataSource = table;
                comboBox7.DisplayMember = "Additionaly";
                comboBox7.SelectedIndex = -1;


                sqlConnection.Close();

            }

            if (pictureBox1.Image != null)
            {
                pictureBox1.BorderStyle = BorderStyle.FixedSingle;
                panel1.BorderStyle = BorderStyle.FixedSingle;
            }
            else
            {
                pictureBox1.BorderStyle = BorderStyle.None;
                panel1.BorderStyle = BorderStyle.None;
            }

            if (pictureBox2.Image != null)
            {
                pictureBox2.BorderStyle = BorderStyle.FixedSingle;
                panel2.BorderStyle = BorderStyle.FixedSingle;
            }
            else
            {
                pictureBox2.BorderStyle = BorderStyle.None;
                panel2.BorderStyle = BorderStyle.None;
            }

            if (pictureBox3.Image != null)
            {
                pictureBox3.BorderStyle = BorderStyle.FixedSingle;
                panel3.BorderStyle = BorderStyle.FixedSingle;
            }
            else
            {
                pictureBox3.BorderStyle = BorderStyle.None;
                panel3.BorderStyle = BorderStyle.None;
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
                foreach (var a in Cod.Skip(page * 3))
                {
                    if (index != 3)
                    {
                        pictureBoxes[index].Image = GetPhotoCar(Convert.ToInt32(a));
                        index++;
                    }
                    else break;

                }

                index = 0;
                foreach (var a in Marka.Skip(page * 3))
                {
                    if (index != 6)
                    {
                        labels[index].Text = a;
                        index += 2;
                    }
                    else break;

                }

                index = 1;
                foreach (var a in Model.Skip(page * 3))
                {
                    if (index != 7)
                    {
                        labels[index].Text = a;
                        index += 2;
                    }
                    else break;
                }

                if (pictureBox1.Image != null)
                {
                    pictureBox1.BorderStyle = BorderStyle.FixedSingle;
                    panel1.BorderStyle = BorderStyle.FixedSingle;
                }

                if (pictureBox2.Image != null)
                {
                    pictureBox2.BorderStyle = BorderStyle.FixedSingle;
                    panel2.BorderStyle = BorderStyle.FixedSingle;
                }

                if (pictureBox3.Image != null)
                {
                    pictureBox3.BorderStyle = BorderStyle.FixedSingle;
                    panel3.BorderStyle = BorderStyle.FixedSingle;
                }

            }
        }

        private void pictureBox11_Click(object sender, EventArgs e)
        {
            if ((Cod.Count / 3.0) <= (page+1.0))
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
                foreach (var a in Cod.Skip(page * 3))
                {
                    if (index != 3)
                    {
                        pictureBoxes[index].Image = GetPhotoCar(Convert.ToInt32(a));
                        index++;
                    }
                    else break;

                }

                index = 0;
                foreach (var a in Marka.Skip(page * 3))
                {
                    if (index != 6)
                    {
                        labels[index].Text = a;
                        index += 2;
                    }
                    else break;

                }

                index = 1;
                foreach (var a in Model.Skip(page * 3))
                {
                    if (index != 7)
                    {
                        labels[index].Text = a;
                        index += 2;
                    }
                    else break;
                }

                if(pictureBox1.Image!=null)
                {
                    pictureBox1.BorderStyle = BorderStyle.FixedSingle;
                    panel1.BorderStyle = BorderStyle.FixedSingle;
                }
                else
                {
                    pictureBox1.BorderStyle = BorderStyle.None;
                    panel1.BorderStyle = BorderStyle.None;
                }

                if (pictureBox2.Image != null)
                {
                    pictureBox2.BorderStyle = BorderStyle.FixedSingle;
                    panel2.BorderStyle = BorderStyle.FixedSingle;
                }
                else
                {
                    pictureBox2.BorderStyle = BorderStyle.None;
                    panel2.BorderStyle = BorderStyle.None;
                }

                if (pictureBox3.Image != null)
                {
                    pictureBox3.BorderStyle = BorderStyle.FixedSingle;
                    panel3.BorderStyle = BorderStyle.FixedSingle;
                }
                else
                {
                    pictureBox3.BorderStyle = BorderStyle.None;
                    panel3.BorderStyle = BorderStyle.None;
                }
            }
        }


        private void GroupList_Refresh()
        {
            Marka.Clear();
            Model.Clear();
            Cod.Clear();
            using (SqlConnection sqlConnection = new SqlConnection(@"Data Source=.\SQLEXPRESS;Initial Catalog=CarRent;Integrated Security=True"))
            {
                SqlCommand command = new SqlCommand("Select Cod_Car, Marka, Car_Model From AllInfoCar", sqlConnection);
                sqlConnection.Open();

                using (SqlDataReader reader = command.ExecuteReader())
                {
                    while (reader.Read())
                    {
                        Cod.Add(reader["Cod_Car"].ToString());
                        Marka.Add(reader["Marka"].ToString());
                        Model.Add(reader["Car_Model"].ToString());
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
                if (index != 3)
                {
                    pictureBoxes[index].Image = GetPhotoCar(Convert.ToInt32(a));
                    index++;
                }
                else break;

            }

            index = 0;
            foreach (var a in Marka)
            {
                if (index != 6)
                {
                    labels[index].Text = a;
                    index += 2;
                }
                else break;

            }

            index = 1;
            foreach (var a in Model)
            {
                if (index != 7)
                {
                    labels[index].Text = a;
                    index += 2;
                }
                else break;
            }

            page = 0;

            if (pictureBox1.Image != null)
            {
                pictureBox1.BorderStyle = BorderStyle.FixedSingle;
                panel1.BorderStyle = BorderStyle.FixedSingle;
            }
            else
            {
                pictureBox1.BorderStyle = BorderStyle.None;
                panel1.BorderStyle = BorderStyle.None;
            }

            if (pictureBox2.Image != null)
            {
                pictureBox2.BorderStyle = BorderStyle.FixedSingle;
                panel2.BorderStyle = BorderStyle.FixedSingle;
            }
            else
            {
                pictureBox2.BorderStyle = BorderStyle.None;
                panel2.BorderStyle = BorderStyle.None;
            }

            if (pictureBox3.Image != null)
            {
                pictureBox3.BorderStyle = BorderStyle.FixedSingle;
                panel3.BorderStyle = BorderStyle.FixedSingle;
            }
            else
            {
                pictureBox3.BorderStyle = BorderStyle.None;
                panel3.BorderStyle = BorderStyle.None;
            }
        }


        private void GetAdditionCarSearch(int rowIndexLocal)
        {
            ListAddition.Clear();
            ListAddition = new List<string>();

            SqlConnection sqlConnection = new SqlConnection(@"Data Source=.\SQLEXPRESS;Initial Catalog=CarRent;Integrated Security=True");
            {
                SqlCommand command = new SqlCommand("Select Additionaly FROM Car_Additionaly WHERE Cod_Car = '" + rowIndexLocal + "'", sqlConnection);
                sqlConnection.Open();
                SqlDataReader rd = command.ExecuteReader();

                while (rd.Read())
                {
                    ListAddition.Add(rd["Additionaly"].ToString());
                }

                sqlConnection.Close();
            }
        }

        private void button7_Click(object sender, EventArgs e)
        {
            comboBox7.SelectedIndex = -1;

            if (textBox1.TextLength > 0 || textBox4.TextLength > 0 || comboBox8.SelectedIndex != -1 || comboBox9.SelectedIndex != -1 || comboBox10.SelectedIndex != -1 ||
                comboBox11.SelectedIndex != -1 || comboBox12.SelectedIndex != -1 || comboBox13.SelectedIndex != -1 ||
                richTextBox2.TextLength > 0 || numericUpDown6.Value != 1 || numericUpDown5.Value != 15 || numericUpDown3.Value != 10 || numericUpDown4.Value != 500)
            {
                Marka.Clear();
                Model.Clear();
                Cod.Clear();

                using (SqlConnection sqlConnection = new SqlConnection(@"Data Source=.\SQLEXPRESS;Initial Catalog=CarRent;Integrated Security=True"))
                {
                    SqlCommand command = new SqlCommand("Select Cod_Car, Marka, Car_Model From AllInfoCar where Car_Gos_ID LIKE '%" + textBox1.Text + "%' and Car_model like '%" + textBox4.Text + "%' and Marka like '%" + comboBox13.Text + "%' and Color like '%" + comboBox12.Text + "%' and Fuel like '%" + comboBox11.Text + "%' and Transmission like '%" + comboBox10.Text + "%' and NameType like '%" + comboBox9.Text + "%' and Price>=" + numericUpDown3.Value + " and Price<=" + numericUpDown4.Value + " and Car_Num_Sit >=" + numericUpDown6.Value + " and Car_Num_Sit <=" + numericUpDown5.Value + " and NameStatus like '%" + comboBox8.Text + "%'", sqlConnection);

                    sqlConnection.Open();
                    SqlDataAdapter sqlDataAdapter = new SqlDataAdapter(command);
                    DataTable dtRecorder = new DataTable();
                    sqlDataAdapter.Fill(dtRecorder);
                    sqlConnection.Close();

                    if (richTextBox2.TextLength > 0 && dtRecorder.Rows.Count > 0)
                    {
                        for (int i = 0; i < dtRecorder.Rows.Count; i++)
                        {
                            GetAdditionCarSearch(Convert.ToInt32(dtRecorder.Rows[i][0]));

                            foreach (var UserAdditon in richTextBox2.Text.Split(',', '\n'))
                            {

                                if (UserAdditon != "" && UserAdditon != "," && UserAdditon != ".")
                                {
                                    if (UserAdditon[0] == ' ')
                                    {
                                        if (!ListAddition.Contains(UserAdditon.Substring(1)))
                                        {
                                            dtRecorder.Rows[i].Delete();
                                            continue;
                                        }
                                    }
                                    else
                                    {
                                        if (!ListAddition.Contains(UserAdditon))
                                        {
                                            dtRecorder.Rows[i].Delete();
                                            continue;
                                        }
                                    }
                                }

                            }
                        }
                    }
                    dtRecorder.AcceptChanges();

                    if (dtRecorder.Rows.Count > 0)
                    {
                        for (int i = 0; i < dtRecorder.Rows.Count; i++)
                        {
                            Cod.Add(Convert.ToString(dtRecorder.Rows[i][0]));
                            Marka.Add(Convert.ToString(dtRecorder.Rows[i][1]));
                            Model.Add(Convert.ToString(dtRecorder.Rows[i][2]));
                        }
                    }

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
                    if (index != 3)
                    {
                        pictureBoxes[index].Image = GetPhotoCar(Convert.ToInt32(a));
                        index++;
                    }
                    else break;

                }

                index = 0;
                foreach (var a in Marka)
                {
                    if (index != 6)
                    {
                        labels[index].Text = a;
                        index += 2;
                    }
                    else break;

                }

                index = 1;
                foreach (var a in Model)
                {
                    if (index != 7)
                    {
                        labels[index].Text = a;
                        index += 2;
                    }
                    else break;
                }

                page = 0;

                if (pictureBox1.Image != null)
                {
                    pictureBox1.BorderStyle = BorderStyle.FixedSingle;
                    panel1.BorderStyle = BorderStyle.FixedSingle;
                }
                else
                {
                    pictureBox1.BorderStyle = BorderStyle.None;
                    panel1.BorderStyle = BorderStyle.None;
                }

                if (pictureBox2.Image != null)
                {
                    pictureBox2.BorderStyle = BorderStyle.FixedSingle;
                    panel2.BorderStyle = BorderStyle.FixedSingle;
                }
                else
                {
                    pictureBox2.BorderStyle = BorderStyle.None;
                    panel2.BorderStyle = BorderStyle.None;
                }

                if (pictureBox3.Image != null)
                {
                    pictureBox3.BorderStyle = BorderStyle.FixedSingle;
                    panel3.BorderStyle = BorderStyle.FixedSingle;
                }
                else
                {
                    pictureBox3.BorderStyle = BorderStyle.None;
                    panel3.BorderStyle = BorderStyle.None;
                }
            }
        }

        private void button5_Click(object sender, EventArgs e)
        {
            if (richTextBox2.Find(comboBox7.Text) == -1)
            {
                if (richTextBox2.TextLength != 0)
                    richTextBox2.Text += ", " + comboBox7.Text;
                else
                    richTextBox2.Text += comboBox7.Text;
            }

            comboBox7.SelectedIndex = -1;
        }

        private void panel1_Click(object sender, EventArgs e)
        {
            if(label3.Text!="")
            {
                AboutCar aboutCar = new AboutCar(Convert.ToInt32(Cod.ElementAt(page * 3)))
                {
                    Dock = DockStyle.Fill
                };
                this.panel5.Controls.Add(aboutCar);
                aboutCar.BringToFront();
                pictureBox4.Visible = true;
            }
        }

        private void panel2_Click(object sender, EventArgs e)
        {
            if (label5.Text != "")
            {
                AboutCar aboutCar = new AboutCar(Convert.ToInt32(Cod.ElementAt(page * 3 + 1)))
            {
                Dock = DockStyle.Fill
            };
            this.panel5.Controls.Add(aboutCar);
            aboutCar.BringToFront();
            pictureBox4.Visible = true;
        }
        }

        private void panel3_Click(object sender, EventArgs e)
        {
            if (label7.Text != "")
            {
                AboutCar aboutCar = new AboutCar(Convert.ToInt32(Cod.ElementAt(page * 3 + 2)))
                {
                    Dock = DockStyle.Fill
                };
                this.panel5.Controls.Add(aboutCar);
                aboutCar.BringToFront();
                pictureBox4.Visible = true;
            }
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {
            panel1_Click(sender, e);
        }

        private void pictureBox2_Click(object sender, EventArgs e)
        {
            panel2_Click(sender, e);
        }

        private void pictureBox3_Click(object sender, EventArgs e)
        {
            panel3_Click(sender, e);
        }

        private void label8_Click(object sender, EventArgs e)
        {
            panel3_Click(sender, e);
        }

        private void label7_Click(object sender, EventArgs e)
        {
            panel3_Click(sender, e);
        }

        private void label3_Click(object sender, EventArgs e)
        {
            panel1_Click(sender, e);
        }

        private void label6_Click(object sender, EventArgs e)
        {
            panel2_Click(sender, e);
        }

        private void label5_Click(object sender, EventArgs e)
        {
            panel2_Click(sender, e);
        }

        private void label4_Click(object sender, EventArgs e)
        {
            panel1_Click(sender, e);
        }

        private void pictureBox4_Click(object sender, EventArgs e)
        {
            GroupList_Refresh();
            pictureBox4.Visible = false;
        }

        private void panel5_Paint(object sender, PaintEventArgs e)
        {

        }
    }
}
