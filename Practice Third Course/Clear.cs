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

namespace CarRent
{
    public partial class Clear : UserControl
    {
        public Clear()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            label7.Visible = true;
            SqlTransaction transaction = null;
            using (SqlConnection sqlConnection = new SqlConnection(@"Data Source=.\SQLEXPRESS;Initial Catalog=CarRent;Integrated Security=True"))
            {
                sqlConnection.Open();
                transaction = sqlConnection.BeginTransaction();
                SqlCommand command = new SqlCommand("insert into ArchiveContracts (Cod_Contract, Client, Car, Worker, DateOfOrder, FirstDayOrder,LastDayOrder, TotalPrice) Select Cod_Contract, ClientInfo, Car, Worker, DateOfOrder, FirstDayOrder, LastDayOrder, TotalPrice from ContractData where DATEDIFF(day, CONVERT(datetime, LastDayOrder, 104), CONVERT(datetime, GETDATE(), 104)) > 365", sqlConnection, transaction);
                SqlCommand command1 = new SqlCommand("delete from Contracts Where DATEDIFF(day, CONVERT(datetime, LastDayOrder, 104), CONVERT(datetime, GETDATE(), 104)) > 365", sqlConnection,transaction);

                try
                {
                    command.ExecuteNonQuery();
                    command1.ExecuteNonQuery();
                    transaction.Commit();
                    label7.ForeColor = Color.Green;
                    label7.Text = "Транзакция успешно завершена";
                }
                catch (Exception)
                {
                    transaction.Rollback();
                    label7.ForeColor = Color.Red;
                    label7.Text = "Ошибка транзанкции. Произошёл откат к прошлой точке";
                }
                finally
                {
                    sqlConnection.Close();
                }
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            label7.Visible = true;
            SqlTransaction transaction = null;
            using (SqlConnection sqlConnection = new SqlConnection(@"Data Source=.\SQLEXPRESS;Initial Catalog=CarRent;Integrated Security=True"))
            {
                sqlConnection.Open();
                transaction = sqlConnection.BeginTransaction();
                SqlCommand command = new SqlCommand("delete from Contracts Where DATEDIFF(day, CONVERT(datetime, LastDayOrder, 104), CONVERT(datetime, GETDATE(), 104)) > 365", sqlConnection, transaction);
                SqlCommand command1 = new SqlCommand("delete from Clients Where Cod_Client = (Select distinct Cod_Client From Contracts Where DATEDIFF(day,CONVERT(datetime, LastDayOrder,104),CONVERT(datetime, GETDATE(),104))>365)", sqlConnection, transaction);

                try
                {
                    command.ExecuteNonQuery();
                    command1.ExecuteNonQuery();
                    transaction.Commit();
                    label7.ForeColor = Color.Green;
                    label7.Text = "Транзакция успешно завершена";
                }
                catch (Exception)
                {
                    transaction.Rollback();
                    label7.ForeColor = Color.Red;
                    label7.Text = "Ошибка транзанкции. Произошёл откат к прошлой точке";
                }
                finally
                {
                    sqlConnection.Close();
                }
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            label7.Visible = true;
            SqlTransaction transaction = null;
            using (SqlConnection sqlConnection = new SqlConnection(@"Data Source=.\SQLEXPRESS;Initial Catalog=CarRent;Integrated Security=True"))
            {
                sqlConnection.Open();
                transaction = sqlConnection.BeginTransaction();
                SqlCommand command = new SqlCommand("delete from ArchiveWorkers", sqlConnection, transaction);

                try
                {
                    command.ExecuteNonQuery();
                    transaction.Commit();
                    label7.ForeColor = Color.Green;
                    label7.Text = "Транзакция успешно завершена";
                }
                catch (Exception)
                {
                    transaction.Rollback();
                    label7.ForeColor = Color.Red;
                    label7.Text = "Ошибка транзанкции. Произошёл откат к прошлой точке";
                }
                finally
                {
                    sqlConnection.Close();
                }
            }
        }

        private void button4_Click(object sender, EventArgs e)
        {
            label7.Visible = true;
            SqlTransaction transaction = null;
            using (SqlConnection sqlConnection = new SqlConnection(@"Data Source=.\SQLEXPRESS;Initial Catalog=CarRent;Integrated Security=True"))
            {
                sqlConnection.Open();
                transaction = sqlConnection.BeginTransaction();
                SqlCommand command = new SqlCommand("delete from ArchiveContracts", sqlConnection, transaction);

                try
                {
                    command.ExecuteNonQuery();
                    transaction.Commit();
                    label7.ForeColor = Color.Green;
                    label7.Text = "Транзакция успешно завершена";
                }
                catch (Exception)
                {
                    transaction.Rollback();
                    label7.ForeColor = Color.Red;
                    label7.Text = "Ошибка транзанкции. Произошёл откат к прошлой точке";
                }
                finally
                {
                    sqlConnection.Close();
                }
            }
        }

        private void button5_Click(object sender, EventArgs e)
        {
            label7.Visible = true;
            SqlTransaction transaction = null;
            using (SqlConnection sqlConnection = new SqlConnection(@"Data Source=.\SQLEXPRESS;Initial Catalog=CarRent;Integrated Security=True"))
            {
                sqlConnection.Open();
                transaction = sqlConnection.BeginTransaction();
                SqlCommand command = new SqlCommand("delete from ArchiveCar", sqlConnection, transaction);

                try
                {
                    command.ExecuteNonQuery();
                    transaction.Commit();
                    label7.ForeColor = Color.Green;
                    label7.Text = "Транзакция успешно завершена";
                }
                catch (Exception)
                {
                    transaction.Rollback();
                    label7.ForeColor = Color.Red;
                    label7.Text = "Ошибка транзанкции. Произошёл откат к прошлой точке";
                }
                finally
                {
                    sqlConnection.Close();
                }
            }
        }

        private void button6_Click(object sender, EventArgs e)
        {
            label7.Visible = true;
            SqlTransaction transaction = null;
            using (SqlConnection sqlConnection = new SqlConnection(@"Data Source=.\SQLEXPRESS;Initial Catalog=CarRent;Integrated Security=True"))
            {
                sqlConnection.Open();
                transaction = sqlConnection.BeginTransaction();
                SqlCommand command = new SqlCommand("delete from ArchiveClients", sqlConnection, transaction);

                try
                {
                    command.ExecuteNonQuery();
                    transaction.Commit();
                    label7.ForeColor = Color.Green;
                    label7.Text = "Транзакция успешно завершена";
                }
                catch (Exception)
                {
                    transaction.Rollback();
                    label7.ForeColor = Color.Red;
                    label7.Text = "Ошибка транзанкции. Произошёл откат к прошлой точке";
                }
                finally
                {
                    sqlConnection.Close();
                }
            }
        }
    }
}
