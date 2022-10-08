using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.Drawing.Imaging;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CarRent
{
    class Worker
    {
        public string Cod_Worker { get; set; }
        public string Login_Worker { set; get; }
        public string Password_Worker { set; get; }
        public string Name_Worker { set; get; }
        public string Surname_Worker { set; get; }
        public string Mail_Worker { set; get; }
        public int Cod_Position { set; get; }
        public string Worker_PasID { set; get; }
        public string Worker_PhoneNumber { set; get; }
        public string Worker_Adres { set; get; }
        public string Worker_Birthday { set; get; }

        public static Worker user = new Worker();

        Worker()
        {
            Cod_Worker = "0";
            Login_Worker = "";
            Password_Worker = "";
            Mail_Worker = "";
            Name_Worker = "";
            Surname_Worker = "";
            Cod_Position = 0;
            Worker_PasID = "";
            Worker_PhoneNumber = "";
            Worker_Adres = "";
            Worker_Birthday = "";
        }

        public void UpdateData()
        {
            string connectionString = @"Data Source=.\SQLEXPRESS;Initial Catalog=CarRent;Integrated Security=True";
            string sCommand = "Update Workers Set Worker_Name = '" + Name_Worker + "', Worker_Surname = '" + Surname_Worker + "'," +
                    "Worker_PasID = '" + Worker_PasID + "', Worker_PhoneNumber = '" + Worker_PhoneNumber + "'," +
                    "Worker_Adres = '" + Worker_Adres + "', Worker_Birthday = '" + Worker_Birthday +"' Where Cod_Worker = '" + Cod_Worker + "'";
            using (SqlConnection connection = new SqlConnection(connectionString))
            {
                SqlCommand command = new SqlCommand(sCommand, connection);
                connection.Open();
                command.ExecuteNonQuery();
                connection.Close();
            }
        }

        public void UpdateLogMailPas(string Login, string Password, string Mail)
        {
            string connectionString = @"Data Source=.\SQLEXPRESS;Initial Catalog=CarRent;Integrated Security=True";
            string sCommand = "Update Worker_LoginTable Set Worker_Login = '" + Login + "', Worker_Password = '" + Password + "', Worker_Mail = '" + Mail + "' Where Cod_Worker = '" + user.Cod_Worker + "'";
            using (SqlConnection connection = new SqlConnection(connectionString))
            {
                SqlCommand command = new SqlCommand(sCommand, connection);
                connection.Open();
                command.ExecuteNonQuery();
                connection.Close();
            }
        }

        public void UpdateStatus(int Cod_WorkerSelect, int status)
        {
            string connectionString = @"Data Source=.\SQLEXPRESS;Initial Catalog=CarRent;Integrated Security=True";
            string sCommand = "Update Workers Set Cod_Position = '" + status + "' Where Cod_Worker = '" + Cod_WorkerSelect + "'";
            using (SqlConnection connection = new SqlConnection(connectionString))
            {
                SqlCommand command = new SqlCommand(sCommand, connection);
                connection.Open();
                command.ExecuteNonQuery();
                connection.Close();
            }
        }

        public void GetLogPasMail()
        {
            string connectionString = @"Data Source=.\SQLEXPRESS;Initial Catalog=CarRent;Integrated Security=True";
            using (SqlConnection connection = new SqlConnection(connectionString))
            {
                SqlCommand command = new SqlCommand();
                command = new SqlCommand("SELECT Worker_Login, Worker_Password, Worker_Mail FROM Worker_LoginTable Where Cod_Worker = '"+ Cod_Worker +"'", connection);
                connection.Open();
                SqlDataReader rd = command.ExecuteReader();

                while(rd.Read())
                {
                    user.Login_Worker = rd["Worker_Login"].ToString();
                    user.Password_Worker = rd["Worker_Password"].ToString();
                    user.Mail_Worker = rd["Worker_Mail"].ToString();
                }

                connection.Close();
                
            }
        }


        public Image GetPhoto()
        {
            List<byte[]> iScreen = new List<byte[]>();
            using (SqlConnection sqlConnection = new SqlConnection(@"Data Source=.\SQLEXPRESS;Initial Catalog=CarRent;Integrated Security=True"))
            {
                string LocalUserId = Convert.ToString(Cod_Worker);
                SqlCommand command = new SqlCommand("Select ImageData From Workers Where Cod_Worker = @Cod_Worker", sqlConnection);
                sqlConnection.Open();

                SqlParameter param = new SqlParameter
                {
                    ParameterName = "@Cod_Worker",
                    Value = Worker.user.Cod_Worker,
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

        public Image GetPhoto(int Cod_WorkerSelect)
        {
            List<byte[]> iScreen = new List<byte[]>();
            using (SqlConnection sqlConnection = new SqlConnection(@"Data Source=.\SQLEXPRESS;Initial Catalog=CarRent;Integrated Security=True"))
            {
                string LocalUserId = Convert.ToString(Cod_Worker);
                SqlCommand command = new SqlCommand("Select ImageData From Workers Where Cod_Worker = @Cod_Worker", sqlConnection);
                sqlConnection.Open();

                SqlParameter param = new SqlParameter
                {
                    ParameterName = "@Cod_Worker",
                    Value = Cod_WorkerSelect,
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

        public void SetPhoto(string pPicture)
        {
            FileInfo fInfo = new FileInfo(pPicture);
                long numBytes = fInfo.Length;
                FileStream fStream = new FileStream(pPicture, FileMode.Open, FileAccess.Read);
                BinaryReader br = new BinaryReader(fStream);
            byte[] imageData = br.ReadBytes((int)numBytes);

            using (SqlConnection sqlConnection = new SqlConnection(@"Data Source=.\SQLEXPRESS;Initial Catalog=CarRent;Integrated Security=True"))
                {
                    SqlCommand command = new SqlCommand("Update Workers " +
                                                    "Set ImageData = @ImageData " +
                                                    "where Cod_Worker = @Cod_Worker", sqlConnection);

                    SqlParameter param = new SqlParameter
                    {
                        ParameterName = "@ImageData",
                        Value = (object)imageData,
                        SqlDbType = SqlDbType.Image
                    };
                    command.Parameters.Add(param);

                    param = new SqlParameter
                    {
                        ParameterName = "@Cod_Worker",
                        Value = Worker.user.Cod_Worker,
                        SqlDbType = SqlDbType.Int
                    };
                    command.Parameters.Add(param);

                    sqlConnection.Open();
                    command.ExecuteNonQuery();
                    sqlConnection.Close();
                    br.Dispose();
                }
        }

        public void ResetLogPas(int Cod_WorkerSelect)
        {
            string connectionString = @"Data Source=.\SQLEXPRESS;Initial Catalog=CarRent;Integrated Security=True";
            string sCommand = "Update Worker_LoginTable Set Worker_Login = 'user" + Cod_WorkerSelect + "', Worker_Password = '1111', Worker_Mail = '' Where Cod_Worker = '" + Cod_WorkerSelect + "'";
            using (SqlConnection connection = new SqlConnection(connectionString))
            {
                SqlCommand command = new SqlCommand(sCommand, connection);
                connection.Open();
                command.ExecuteNonQuery();
                connection.Close();
            }
        }

        public void ResetPhoto(int Cod_WorkerSelect)
        {
            FileInfo fInfo = new FileInfo(@"UserPicture.png");
            long numBytes = fInfo.Length;
            FileStream fStream = new FileStream(@"UserPicture.png", FileMode.Open, FileAccess.Read);
            BinaryReader br = new BinaryReader(fStream);
            byte[] imageData = br.ReadBytes((int)numBytes);

            using (SqlConnection sqlConnection = new SqlConnection(@"Data Source=.\SQLEXPRESS;Initial Catalog=CarRent;Integrated Security=True"))
            {
                SqlCommand command = new SqlCommand("Update Workers " +
                                                "Set ImageData = @ImageData " +
                                                "where Cod_Worker = @Cod_Worker", sqlConnection);

                SqlParameter param = new SqlParameter
                {
                    ParameterName = "@ImageData",
                    Value = (object)imageData,
                    SqlDbType = SqlDbType.Image
                };
                command.Parameters.Add(param);

                param = new SqlParameter
                {
                    ParameterName = "@Cod_Worker",
                    Value = Cod_WorkerSelect,
                    SqlDbType = SqlDbType.Int
                };
                command.Parameters.Add(param);

                sqlConnection.Open();
                command.ExecuteNonQuery();
                sqlConnection.Close();
                br.Dispose();
            }
        }

        public void ClearData()
        {
                Cod_Worker = "0";
                Login_Worker = "";
                Password_Worker = "";
                Mail_Worker = "";
                Name_Worker = "";
                Surname_Worker = "";
                Cod_Position = 0;
                Worker_PasID = "";
                Worker_PhoneNumber = "";
                Worker_Adres = "";
                Worker_Birthday = "";
        }
    }
}
