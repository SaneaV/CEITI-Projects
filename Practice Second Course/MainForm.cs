using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace Practic
{
    public partial class MainForm : Form
    {
        int num = 0;

        //=============================Начальные настройки элементов формы===================
        public MainForm()
        {
            InitializeComponent();
            label1.Visible = false;
            label2.Visible = false;
            label3.Visible = false;
            dataGridView2.Visible = false;
        }

        //================================================================================================================================================================
        //Действия по нажатию на кнопки формы.
        //================================================================================================================================================================

        //=============================Button1_Click=========================================
        //=============================Добавление новой территории===========================
        private void Button1_Click(object sender, EventArgs e)
        {
            label3.Visible = false;
            if (dataGridView1.Visible == false)
            {
                dataGridView1.DataSource = ReadFromFile(@"E:\Всё для колледжа\Задачи по программированию\Задачи (основные)\Проекты\Практика 2 курс (2019)\Practic\bin\Debug\Teren.in.txt");
                FillRecordNo(dataGridView1);
            }

            var sm = CreateDlgBox2();
            AddRow(sm.Item1, sm.Item2, sm.Item3, sm.Item4, sm.Item5, dataGridView1);

            label3.Visible = false;
            dataGridView2.DataSource = VisualDataGrid(dataGridView1);
            label1.Visible = true;
            dataGridView2.Visible = true;
            label1.Text = "Файл: " + "Teren.in.txt";

            ForbideRead(dataGridView2);
            FillRecordNo(dataGridView2);
            ColorGridView();
            NoSortable(dataGridView2);
            NoSizebale(dataGridView2);
            CheckZero();
        }

        //=============================Button2_Click=========================================
        //=============================Чтение из файла/Обновление информации=================
        private void Button2_Click(object sender, EventArgs e)
        {
            label3.Visible = false;
            dataGridView1.DataSource = ReadFromFile(@"E:\Всё для колледжа\Задачи по программированию\Задачи (основные)\Проекты\Практика 2 курс (2019)\Practic\bin\Debug\Teren.in.txt");
            dataGridView2.DataSource = VisualDataGrid(dataGridView1);
            label1.Visible = true;
            dataGridView2.Visible = true;
            label1.Text = "Файл: " + "Teren.in.txt";

            ForbideRead(dataGridView2);
            FillRecordNo(dataGridView2);
            ColorGridView();
            NoSortable(dataGridView2);
            NoSizebale(dataGridView2);
            CheckZero();
        }

        //=============================Button3_Click=========================================
        //=============================Удаление участка======================================
        private void Button3_Click(object sender, EventArgs e)
        {
            label3.Visible = false;
            if (dataGridView1.Visible == false)
            {
                dataGridView1.DataSource = ReadFromFile(@"E:\Всё для колледжа\Задачи по программированию\Задачи (основные)\Проекты\Практика 2 курс (2019)\Practic\bin\Debug\Teren.in.txt");
                FillRecordNo(dataGridView1);
            }

            var sm = CreateDlgBox3();
            DelRow(sm.Item1, sm.Item2, sm.Item3, sm.Item4, dataGridView1);

            label3.Visible = false;
            dataGridView2.DataSource = VisualDataGrid(dataGridView1);
            label1.Visible = true;
            dataGridView2.Visible = true;
            label1.Text = "Файл: " + "Teren.in.txt";

            ForbideRead(dataGridView2);
            FillRecordNo(dataGridView2);
            ColorGridView();
            NoSortable(dataGridView2);
            NoSizebale(dataGridView2);
            CheckZero();
        }

        //=============================Button4_Click=========================================
        //=============================Поиск минимального прямоугольника=====================
        private void Button4_Click(object sender, EventArgs e)
        {
            if (dataGridView2.Visible == false)
            {
                label3.Visible = false;
                dataGridView1.DataSource = ReadFromFile(@"E:\Всё для колледжа\Задачи по программированию\Задачи (основные)\Проекты\Практика 2 курс (2019)\Practic\bin\Debug\Teren.in.txt");
                dataGridView2.DataSource = VisualDataGrid(dataGridView1);
                label1.Visible = true;
                dataGridView2.Visible = true;
                label1.Text = "Файл: " + "Teren.in.txt";

                ForbideRead(dataGridView2);
                FillRecordNo(dataGridView2);
                ColorGridView();
                NoSortable(dataGridView2);
                NoSizebale(dataGridView2);
            }
            CheckZero();

            if (num != 0)
                label2.Text = "Минимальный треугольник: x1 = " + Convert.ToString(MinimalPream(dataGridView1, num).Item1) +
                    ", y1 = " + Convert.ToString(MinimalPream(dataGridView1, num).Item2) +
                    ", x2 = " + Convert.ToString(MinimalPream(dataGridView1, num).Item3) +
                    ", y2 = " + Convert.ToString(MinimalPream(dataGridView1, num).Item4);
            else label2.Text = "Точек не существует";
            label2.Visible = true;
        }

        //=============================Button4_Click=========================================
        //=============================Сохранение в файл=====================================
        private void Button5_Click(object sender, EventArgs e)
        {
            CheckZero();
            SaveToFile(dataGridView1, @"E:\Всё для колледжа\Задачи по программированию\Задачи (основные)\Проекты\Практика 2 курс (2019)\Practic\bin\Debug\Teren.in.txt");
        }

        //=============================Button6_Click=========================================
        //=============================Цвет самого большого участка==========================
        private void Button6_Click(object sender, EventArgs e)
        {
            if (dataGridView2.Visible == false)
            {
                label3.Visible = false;
                dataGridView1.DataSource = ReadFromFile(@"E:\Всё для колледжа\Задачи по программированию\Задачи (основные)\Проекты\Практика 2 курс (2019)\Practic\bin\Debug\Teren.in.txt");
                dataGridView2.DataSource = VisualDataGrid(dataGridView1);
                label1.Visible = true;
                dataGridView2.Visible = true;
                label1.Text = "Файл: " + "Teren.in.txt";

                ForbideRead(dataGridView2);
                FillRecordNo(dataGridView2);
                ColorGridView();
                NoSortable(dataGridView2);
                NoSizebale(dataGridView2);
            }

            ForbideRead(dataGridView2);
            FillRecordNo(dataGridView2);
            ColorGridView();
            NoSortable(dataGridView2);
            NoSizebale(dataGridView2);
            CheckZero();

            label2.Text = "Цвет самого большого участка - " + Convert.ToString(ColorArea(dataGridView2));
            label2.Visible = true;

        }

        //=============================Button7_Click=========================================
        //=============================Общая площадь всех участков===========================
        private void Button7_Click(object sender, EventArgs e)
        {
            if (dataGridView2.Visible == false)
            {
                label3.Visible = false;
                dataGridView1.DataSource = ReadFromFile(@"E:\Всё для колледжа\Задачи по программированию\Задачи (основные)\Проекты\Практика 2 курс (2019)\Practic\bin\Debug\Teren.in.txt");
                dataGridView2.DataSource = VisualDataGrid(dataGridView1);
                label1.Visible = true;
                dataGridView2.Visible = true;
                label1.Text = "Файл: " + "Teren.in.txt";

                ForbideRead(dataGridView2);
                FillRecordNo(dataGridView2);
                ColorGridView();
                NoSortable(dataGridView2);
                NoSizebale(dataGridView2);
            }
            CheckZero();

            label2.Text = "Общая площадь всех участков - " + Convert.ToString(TotalArea(dataGridView2));
            label2.Visible = true;

        }

        //=============================Button8_Click=========================================
        //=============================Создание файла с цветами определённого участка========
        private void Button8_Click(object sender, EventArgs e)
        {
            if (dataGridView2.Visible == false)
            {
                label3.Visible = false;
                dataGridView1.DataSource = ReadFromFile(@"E:\Всё для колледжа\Задачи по программированию\Задачи (основные)\Проекты\Практика 2 курс (2019)\Practic\bin\Debug\Teren.in.txt");
                dataGridView2.DataSource = VisualDataGrid(dataGridView1);
                label1.Visible = true;
                dataGridView2.Visible = true;
                label1.Text = "Файл: " + "Teren.in.txt";

                ForbideRead(dataGridView2);
                FillRecordNo(dataGridView2);
                ColorGridView();
                NoSortable(dataGridView2);
                NoSizebale(dataGridView2);
            }
            CheckZero();

            string numCp = CreateDlgBox();

            CreateFile(@"E:\Всё для колледжа\Задачи по программированию\Задачи (основные)\Проекты\Практика 2 курс (2019)\Practic\bin\Debug\ColColumn.txt", dataGridView1, numCp);
            label2.Text = "Файл был сохранён.";
            label2.Visible = true;
        }

        //=============================Button9_Click=========================================
        //=============================Сортировка входного файла по цветам===================
        private void Button9_Click(object sender, EventArgs e)
        {
            if (dataGridView2.Visible == false)
            {
                label3.Visible = false;
                dataGridView1.DataSource = ReadFromFile(@"E:\Всё для колледжа\Задачи по программированию\Задачи (основные)\Проекты\Практика 2 курс (2019)\Practic\bin\Debug\Teren.in.txt");
                dataGridView2.DataSource = VisualDataGrid(dataGridView1);
                label1.Visible = true;
                dataGridView2.Visible = true;
                label1.Text = "Файл: " + "Teren.in.txt";

                ForbideRead(dataGridView2);
                FillRecordNo(dataGridView2);
                ColorGridView();
                NoSortable(dataGridView2);
                NoSizebale(dataGridView2);
            }
            CheckZero();
            if (num != 0)
            {
                Sort(dataGridView1);
                SaveToFile(dataGridView1, @"E:\Всё для колледжа\Задачи по программированию\Задачи (основные)\Проекты\Практика 2 курс (2019)\Practic\bin\Debug\Teren.in.txt");
            }
            else label2.Text = "Файл пуст!";
        }

        //=============================Button10_Click=========================================
        //=============================Самая большая территория одного цвета==================
        private void Button10_Click(object sender, EventArgs e)
        {
            if (dataGridView2.Visible == false)
            {
                label3.Visible = false;
                dataGridView1.DataSource = ReadFromFile(@"E:\Всё для колледжа\Задачи по программированию\Задачи (основные)\Проекты\Практика 2 курс (2019)\Practic\bin\Debug\Teren.in.txt");
                dataGridView2.DataSource = VisualDataGrid(dataGridView1);
                label1.Visible = true;
                dataGridView2.Visible = true;
                label1.Text = "Файл: " + "Teren.in.txt";

                ForbideRead(dataGridView2);
                FillRecordNo(dataGridView2);
                ColorGridView();
                NoSortable(dataGridView2);
                NoSizebale(dataGridView2);
            }
            CheckZero();

            int maxElement = MaxElem(dataGridView1);

            var sm1 = FindMaxGorizontal(dataGridView2, maxElement);
            var sm2 = FindMaxVertical(dataGridView2, maxElement);
            dataGridView2.DataSource = VisualDataGrid(dataGridView1);
            FillRecordNo(dataGridView2);

            if (sm1.Item5 > sm2.Item5)
            {
                for (int i = sm1.Item2; i < sm1.Item4; i++)
                {
                    for (int j = sm1.Item1; j < sm1.Item3; j++)
                    {
                        dataGridView2.Rows[i].Cells[j].Value = -1;

                    }
                }
                ColorGridView();
                CreateFileMaxArea(@"E:\Всё для колледжа\Задачи по программированию\Задачи (основные)\Проекты\Практика 2 курс (2019)\Practic\bin\Debug\Teren.out.txt", Convert.ToString(sm1.Item5));
            }
            else if (sm1.Item5 < sm2.Item5)
            {
                for (int i = sm2.Item2; i < sm2.Item4; i++)
                {
                    for (int j = sm2.Item1; j < sm2.Item3; j++)
                    {
                        dataGridView2.Rows[i].Cells[j].Value = -1;
                    }
                }
                ColorGridView();
                CreateFileMaxArea(@"E:\Всё для колледжа\Задачи по программированию\Задачи (основные)\Проекты\Практика 2 курс (2019)\Practic\bin\Debug\Teren.out.txt", Convert.ToString(sm2.Item5));
            }
            else if (sm1.Item5 == sm2.Item5)
            {
                for (int i = sm1.Item2; i < sm1.Item4; i++)
                {
                    for (int j = sm1.Item1; j < sm1.Item3; j++)
                    {
                        dataGridView2.Rows[i].Cells[j].Value = -1;
                    }
                }

                for (int i = sm2.Item2; i < sm2.Item4; i++)
                {
                    for (int j = sm2.Item1; j < sm2.Item3; j++)
                    {
                        dataGridView2.Rows[i].Cells[j].Value = -1;
                    }
                }

                ColorGridView();
                CreateFileMaxArea(@"E:\Всё для колледжа\Задачи по программированию\Задачи (основные)\Проекты\Практика 2 курс (2019)\Practic\bin\Debug\Teren.out.txt", Convert.ToString(sm2.Item5));
            }
        }

        //=============================Button11_Click=========================================
        //=============================Выход из программы=====================================
        private void Button11_Click(object sender, EventArgs e)
        {
            CheckZero();
            Application.Exit();
        }

        //=============================Button12_Click=========================================
        //=============================Скрыть DataGridView2====================================
        private void Button12_Click(object sender, EventArgs e)
        {
            CheckZero();
            label1.Visible = false;
            label2.Visible = false;
            dataGridView2.Visible = false;
        }

        //=============================Button13_Click=========================================
        //=============================Очистка всех территорий================================
        private void Button13_Click(object sender, EventArgs e)
        {
            dataGridView1.SelectAll();
            dataGridView1.ClearSelection();
            dataGridView1.Columns.Clear();
            num = 0;
            dataGridView2.SelectAll();
            dataGridView2.ClearSelection();
            dataGridView2.Columns.Clear();
        }

        //=============================Button14_Click=========================================
        //=============================Справка================================================
        private void Button14_Click(object sender, EventArgs e)
        {
            Form fm = new FAQ();
            fm.ShowDialog();
        }

        //================================================================================================================================================================
        //Дизайн, анимация и подсказки на кнопках
        //================================================================================================================================================================

        //================================================================================================================================================================
        //Mouse Enter
        //================================================================================================================================================================

        //=============================Button1_MouseEnter=========================================
        private void Button1_MouseEnter(object sender, EventArgs e)
        {
            label3.Text = "Добавить новый участок.";
            label3.Visible = true;
        }

        //=============================Button2_MouseEnter=========================================
        private void Button2_MouseEnter(object sender, EventArgs e)
        {
            label3.Text = "Обновить участки.";
            label3.Visible = true;
        }

        //=============================Button3_MouseEnter=========================================
        private void Button3_MouseEnter(object sender, EventArgs e)
        {
            label3.Text = "Удалить участок";
            label3.Visible = true;

        }

        //=============================Button4_MouseEnter=========================================
        private void Button4_MouseEnter(object sender, EventArgs e)
        {
            label3.Text = "Координаты прямоугольника минимальной площади " + "\nсодержащего все участки";
            label3.Visible = true;

            for (int i = 0; i < 10; i++)
                button4.Location = new Point(button4.Location.X + 1, button4.Location.Y);
        }

        //=============================Button5_MouseEnter=========================================
        private void Button5_MouseEnter(object sender, EventArgs e)
        {
            label3.Text = "Сохранить участки в файл.";
            label3.Visible = true;
        }

        //=============================Button6_MouseEnter=========================================
        private void Button6_MouseEnter(object sender, EventArgs e)
        {
            label3.Text = "Культура(цвет) занимающая большую площадь из всех участков.";
            label3.Visible = true;

            for (int i = 0; i < 10; i++)
                button6.Location = new Point(button6.Location.X + 1, button6.Location.Y);
        }

        //=============================Button7_MouseEnter=========================================
        private void Button7_MouseEnter(object sender, EventArgs e)
        {
            label3.Text = "Общая площадь, занятая всему участками.";
            label3.Visible = true;

            for (int i = 0; i < 10; i++)
                button7.Location = new Point(button7.Location.X + 1, button7.Location.Y);
        }

        //=============================Button8_MouseEnter=========================================
        private void Button8_MouseEnter(object sender, EventArgs e)
        {
            label3.Text = "Создание файла Colum.in.txt со строками координат, которые\n" +
                    "соответсвуют коду цвета, введённого с клавиатуры.";
            label3.Visible = true;

            for (int i = 0; i < 10; i++)
                button8.Location = new Point(button8.Location.X + 1, button8.Location.Y);
        }

        //=============================Button9_MouseEnter=========================================
        private void Button9_MouseEnter(object sender, EventArgs e)
        {
            label3.Text = "Сортировка строк в файле по значению цвета в порядке\nвозрастания.";
            label3.Visible = true;

            for (int i = 0; i < 10; i++)
                button9.Location = new Point(button9.Location.X + 1, button9.Location.Y);
        }

        //=============================Button10_MouseEnter========================================
        private void Button10_MouseEnter(object sender, EventArgs e)
        {
            label3.Text = "Определение площади самого большого прямоугольника, \nзанятого " +
                    "культурами одного и того же цвета.";
            label3.Visible = true;

            for (int i = 0; i < 10; i++)
                button10.Location = new Point(button10.Location.X + 1, button10.Location.Y);
        }

        //=============================Button11_MouseEnter========================================
        private void Button11_MouseEnter(object sender, EventArgs e)
        {
            label3.Text = "Закрыть программу.";
            label3.Visible = true;
        }

        //=============================Button12_MouseEnter========================================
        private void Button12_MouseEnter(object sender, EventArgs e)
        {
            label3.Text = "Очистить рабочую область.";
            label3.Visible = true;
        }

        //=============================Button13_MouseEnter========================================
        private void Button13_MouseEnter(object sender, EventArgs e)
        {
            label3.Text = "Очистить таблицу.";
            label3.Visible = true;
        }

        //=============================Button14_MouseEnter========================================
        private void Button14_MouseEnter(object sender, EventArgs e)
        {
            label3.Text = "Справка.";
            label3.Visible = true;
        }

        //================================================================================================================================================================
        //Mouse Enter
        //================================================================================================================================================================

        //=============================Button1_MouseLeave=========================================
        private void Button1_MouseLeave(object sender, EventArgs e)
        {
            label3.Visible = false;
        }

        //=============================Button2_MouseLeave=========================================
        private void Button2_MouseLeave(object sender, EventArgs e)
        {
            label3.Visible = false;
        }

        //=============================Button3_MouseLeave=========================================
        private void Button3_MouseLeave(object sender, EventArgs e)
        {
            label3.Visible = false;
        }

        //=============================Button4_MouseLeave=========================================
        private void Button4_MouseLeave(object sender, EventArgs e)
        {
            label3.Visible = false;

            for (int i = 0; i < 10; i++)
                button4.Location = new Point(button4.Location.X - 1, button4.Location.Y);
        }

        //=============================Button5_MouseLeave=========================================
        private void Button5_MouseLeave(object sender, EventArgs e)
        {
            label3.Visible = false;
        }

        //=============================Button6_MouseLeave=========================================
        private void Button6_MouseLeave(object sender, EventArgs e)
        {
            label3.Visible = false;

            for (int i = 0; i < 10; i++)
                button6.Location = new Point(button6.Location.X - 1, button6.Location.Y);
        }

        //=============================Button7_MouseLeave=========================================
        private void Button7_MouseLeave(object sender, EventArgs e)
        {
            label3.Visible = false;

            for (int i = 0; i < 10; i++)
                button7.Location = new Point(button7.Location.X - 1, button7.Location.Y);
        }

        //=============================Button8_MouseLeave=========================================
        private void Button8_MouseLeave(object sender, EventArgs e)
        {
            label3.Visible = false;

            for (int i = 0; i < 10; i++)
                button8.Location = new Point(button8.Location.X - 1, button8.Location.Y);
        }

        //=============================Button9_MouseLeave=========================================
        private void Button9_MouseLeave(object sender, EventArgs e)
        {
            label3.Visible = false;

            for (int i = 0; i < 10; i++)
                button9.Location = new Point(button9.Location.X - 1, button9.Location.Y);
        }

        //=============================Button10_MouseLeave========================================
        private void Button10_MouseLeave(object sender, EventArgs e)
        {
            label3.Visible = false;

            for (int i = 0; i < 10; i++)
                button10.Location = new Point(button10.Location.X - 1, button10.Location.Y);
        }

        //=============================Button11_MouseLeave========================================
        private void Button11_MouseLeave(object sender, EventArgs e)
        {
            label3.Visible = false;
        }

        //=============================Button12_MouseLeave========================================
        private void Button12_MouseLeave(object sender, EventArgs e)
        {
            label3.Visible = false;
        }

        //=============================Button13_MouseLeave========================================
        private void Button13_MouseLeave(object sender, EventArgs e)
        {
            label3.Visible = false;
        }

        //=============================Button14_MouseLeave========================================
        private void Button14_MouseLeave(object sender, EventArgs e)
        {
            label3.Visible = false;
        }

        //================================================================================================================================================================
        //Визуальное оформление DataGridView2
        //================================================================================================================================================================

        //=============================Запрет на выделение ячеек================================
        private void DataGridView2_SelectionChanged(object sender, EventArgs e)
        {
            dataGridView2.ClearSelection();
        }

        //=============================Запрет на изменение размеров столбцов/строк===============
        private void NoSizebale(DataGridView dataGridView)
        {
            dataGridView.AllowUserToResizeColumns = false;
            dataGridView.AllowUserToResizeRows = false;
        }

        //=============================Запрет на сортировку по столбцу===========================
        private void NoSortable(DataGridView dataGridView)
        {
            int MaxElement = MaxElem(dataGridView1);

            for (int i = 0; i <= MaxElement; i++)
                dataGridView.Columns[i].SortMode = DataGridViewColumnSortMode.NotSortable;
        }

        //==================Запрет на добавление/изменение/удаление через DataGridView===========
        private void ForbideRead(DataGridView dg)
        {
            int MaxElement = MaxElem(dataGridView1);

            for (int i = 0; i < MaxElement; i++)
                for (int j = 0; j < MaxElement; j++)
                    dg.Rows[i].Cells[j].ReadOnly = true;
        }

        //==================Вывол боковых колонок DataGridView2==================================
        private void FillRecordNo(DataGridView dg)
        {
            for (int i = 0; i < dg.Rows.Count; i++)
            {
                dg.Rows[i].HeaderCell.Style.Alignment = DataGridViewContentAlignment.MiddleCenter;
                dg.Rows[i].HeaderCell.Value = (i).ToString();

            }
        }

        //==================Раскрашивание ячеек DataGridView2=====================================
        private void ColorGridView()
        {
            int MaxElement = MaxElem(dataGridView1);

            for (int i = 0; i < MaxElement; i++)
                for (int j = 0; j < MaxElement; j++)
                {
                    if (Convert.ToInt32(dataGridView2.Rows[i].Cells[j].Value) == -1)
                        dataGridView2.Rows[i].Cells[j].Style.BackColor = Color.Black;

                    else if (Convert.ToInt32(dataGridView2.Rows[i].Cells[j].Value) == 0)
                        dataGridView2.Rows[i].Cells[j].Style.BackColor = Color.White;

                    else if (Convert.ToInt32(dataGridView2.Rows[i].Cells[j].Value) == 1)
                        dataGridView2.Rows[i].Cells[j].Style.BackColor = Color.Blue;

                    else if (Convert.ToInt32(dataGridView2.Rows[i].Cells[j].Value) == 2)
                        dataGridView2.Rows[i].Cells[j].Style.BackColor = Color.Green;

                    else if (Convert.ToInt32(dataGridView2.Rows[i].Cells[j].Value) == 3)
                        dataGridView2.Rows[i].Cells[j].Style.BackColor = Color.Red;

                    else if (Convert.ToInt32(dataGridView2.Rows[i].Cells[j].Value) == 4)
                        dataGridView2.Rows[i].Cells[j].Style.BackColor = Color.Pink;

                    else if (Convert.ToInt32(dataGridView2.Rows[i].Cells[j].Value) == 5)
                        dataGridView2.Rows[i].Cells[j].Style.BackColor = Color.Purple;

                    else if (Convert.ToInt32(dataGridView2.Rows[i].Cells[j].Value) == 6)
                        dataGridView2.Rows[i].Cells[j].Style.BackColor = Color.Silver;

                    else if (Convert.ToInt32(dataGridView2.Rows[i].Cells[j].Value) == 7)
                        dataGridView2.Rows[i].Cells[j].Style.BackColor = Color.Yellow;

                    else if (Convert.ToInt32(dataGridView2.Rows[i].Cells[j].Value) == 8)
                        dataGridView2.Rows[i].Cells[j].Style.BackColor = Color.Wheat;

                    else if (Convert.ToInt32(dataGridView2.Rows[i].Cells[j].Value) == 9)
                        dataGridView2.Rows[i].Cells[j].Style.BackColor = Color.Tan;
                }
        }

        //==================Создание DataGridView2 на основе DataGridView1========================
        private DataTable VisualDataGrid(DataGridView dataGridView)
        {
            DataTable visualDataTable = new DataTable();
            int MaxElement = MaxElem(dataGridView1);

            for (int i = 0; i <= MaxElement; i++)
                visualDataTable.Columns.Add(Convert.ToString(i));

            for (int j = 0; j <= MaxElement; j++)
                visualDataTable.Rows.Add("");

            for (int i = 0; i <= MaxElement; i++)
                for (int j = 0; j <= MaxElement; j++)
                    visualDataTable.Rows[j][i] = 0;

            for (int i = 0; i < num; i++)
                for (int j = Convert.ToInt32(dataGridView.Rows[i].Cells[1].Value); j < Convert.ToInt32(dataGridView.Rows[i].Cells[3].Value); j++)
                    for (int k = Convert.ToInt32(dataGridView.Rows[i].Cells[0].Value); k < Convert.ToInt32(dataGridView.Rows[i].Cells[2].Value); k++)
                        visualDataTable.Rows[j][k] = Convert.ToInt32(dataGridView.Rows[i].Cells[4].Value);

            return visualDataTable;
        }

        //================================================================================================================================================================
        //Чтение из файла, сохранение файлов
        //================================================================================================================================================================


        //==================Чтение DataGridView1 из файла=========================================
        private DataTable ReadFromFile(string name)
        {
            DataTable dt = new DataTable();
            int nn = 0;

            try
            {
                using (StreamReader sr = new StreamReader(name))
                {
                    string line;
                    string[] ar;

                    line = sr.ReadLine();
                    num = Convert.ToInt32(line);

                    while ((line = sr.ReadLine()) != null)
                    {
                        ar = line.Split(' ');

                        for (int i = 0; i < ar.Length; i++)
                            if (nn == 0) dt.Columns.Add(Convert.ToString(i + 1));

                        dt.Rows.Add(ar);
                        nn++;
                    }
                    sr.Close();
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine("Файл не может быть прочитан:");
                Console.WriteLine(ex.Message);
            }
            return dt;
        }


        //==================Сохранение данных в файл Teren.in.txt=================================
        private void SaveToFile(DataGridView dg, String fileName)
        {
            bool flag = true;
            if (num == 0)
                flag = CreateDlgBox4();

            if (flag)
            {
                FileStream fs = new FileStream(@fileName, FileMode.Create);
                StreamWriter streamWriter = new StreamWriter(fs);

                streamWriter.Write(num);
                streamWriter.WriteLine();

                try
                {
                    for (int j = 0; j < dg.Rows.Count; j++)
                    {
                        for (int i = 0; i < dg.Rows[j].Cells.Count; i++)
                        {
                            streamWriter.Write(dg.Rows[j].Cells[i].Value);
                            if (i < dg.Rows[j].Cells.Count - 1 && j < dg.Rows.Count - 1) streamWriter.Write(" ");
                        }

                        if (j < dg.Rows.Count - 1) streamWriter.WriteLine();
                    }

                    streamWriter.Close();
                    fs.Close();

                    label2.Visible = true;
                    label2.Text = "Файл успешно сохранен";
                }
                catch
                {
                    MessageBox.Show("Ошибка при сохранении файла!");
                }
            }
        }

        //==================Создание файла со строками, соответствующими определённому цвету======
        public static void CreateFile(string fileName, DataGridView dg, string numCp)
        {
            FileStream fs = new FileStream(@fileName, FileMode.Create);
            StreamWriter streamWriter = new StreamWriter(fs);

            bool WasWritte;
            bool WasFound = false;

            try
            {
                if (numCp == "") throw new Exception("Вы ничего не ввели.");
                if (Convert.ToInt32(numCp) > 100 || Convert.ToInt32(numCp) < 0) throw new Exception("Значение цвета не входит в промежуток (1 - 100)");

                for (int j = 0; j < dg.Rows.Count; j++)
                {
                    WasWritte = false;
                    for (int i = 0; i < dg.Rows[j].Cells.Count; i++)
                    {
                        if (Convert.ToString(dg.Rows[j].Cells[4].Value) == numCp)
                        {
                            streamWriter.Write(dg.Rows[j].Cells[i].Value);

                            if (i < dg.Rows[j].Cells.Count - 1 && j < dg.Rows.Count - 1) streamWriter.Write(" ");
                            {
                                WasWritte = true;
                                WasFound = true;
                            }
                        }
                    }

                    if (WasWritte)
                        if (j < dg.Rows.Count - 1) streamWriter.WriteLine();
                }

                streamWriter.Close();
                fs.Close();

                if (WasFound)
                    MessageBox.Show("Файл успешно сохранен");
                else
                    MessageBox.Show("Участка такого цвета не найдено.\nФайл пуст!");
            }
            catch (Exception ex)
            {
                MessageBox.Show($"Ошибка: {ex.Message}\nЗначения не были сохранены.");
            }
        }

        //==================Создание файла ColColumn.txt(максимальная территория)=================
        public static void CreateFileMaxArea(string fileName, string MaxArea)
        {
            FileStream fs = new FileStream(@fileName, FileMode.Create);
            StreamWriter streamWriter = new StreamWriter(fs);

            try
            {
                streamWriter.Write(MaxArea);
                streamWriter.Close();
                fs.Close();

            }
            catch (Exception ex)
            {
                MessageBox.Show($"Ошибка: {ex.Message}\nЗначения не были сохранены.");
            }
        }


        //================================================================================================================================================================
        //Создание диалоговых окон
        //================================================================================================================================================================

        //==================Запрос на цвет территории для записи в ColColumn.txt==================
        public string CreateDlgBox()
        {
            Form Form2 = new Form
            {
                ControlBox = false,
                Text = String.Empty,
                FormBorderStyle = FormBorderStyle.FixedDialog
            };

            TextBox TextBox1 = new TextBox();
            Label label1 = new Label();
            Button btn1 = new Button();
            string str;
            TextBox1.Parent = Form2;
            label1.Parent = Form2;
            btn1.Parent = Form2;
            btn1.Text = "OK";
            label1.Text = "Введите номер: ";
            label1.Bounds = new Rectangle(13, 5, 100, 20);
            TextBox1.Bounds = new Rectangle(13, 20, 100, 20);
            btn1.Bounds = new Rectangle(25, 50, 70, 30);
            Form2.Bounds = new Rectangle(0, 0, 100, 100);
            Form2.StartPosition = FormStartPosition.CenterParent;
            btn1.DialogResult = DialogResult.OK;
            Form2.ShowDialog();
            str = TextBox1.Text;
            Form2.AcceptButton = btn1;
            return str;
        }

        //==================Запрос данных для добавления новой территории=========================
        static Tuple<string, string, string, string, string> CreateDlgBox2()
        {
            Form Form2 = new Form
            {
                ControlBox = false,
                Text = String.Empty,
                FormBorderStyle = FormBorderStyle.FixedDialog
            };

            TextBox TextBox1 = new TextBox();
            TextBox TextBox2 = new TextBox();
            TextBox TextBox3 = new TextBox();
            TextBox TextBox4 = new TextBox();
            TextBox TextBox5 = new TextBox();

            Label label1 = new Label();
            Label label2 = new Label();
            Label label3 = new Label();
            Label label4 = new Label();
            Label label5 = new Label();

            Button btn1 = new Button();

            string x1, x2;
            string y1, y2;
            string Cp;

            TextBox1.Parent = Form2;
            TextBox2.Parent = Form2;
            TextBox3.Parent = Form2;
            TextBox4.Parent = Form2;
            TextBox5.Parent = Form2;

            label1.Parent = Form2;
            label2.Parent = Form2;
            label3.Parent = Form2;
            label4.Parent = Form2;
            label5.Parent = Form2;

            btn1.Parent = Form2;
            btn1.Text = "OK";

            label1.Text = "X1:";
            label2.Text = "Y1:";
            label3.Text = "X2:";
            label4.Text = "Y2:";
            label5.Text = "Цвет(1-9):";

            label1.Bounds = new Rectangle(13, 5, 100, 20);
            TextBox1.Bounds = new Rectangle(13, 20, 100, 20);

            label2.Bounds = new Rectangle(13, 45, 100, 20);
            TextBox2.Bounds = new Rectangle(13, 60, 100, 20);

            label3.Bounds = new Rectangle(13, 85, 100, 20);
            TextBox3.Bounds = new Rectangle(13, 100, 100, 20);

            label4.Bounds = new Rectangle(13, 125, 100, 20);
            TextBox4.Bounds = new Rectangle(13, 140, 100, 20);

            label5.Bounds = new Rectangle(13, 165, 100, 20);
            TextBox5.Bounds = new Rectangle(13, 180, 100, 20);

            btn1.Bounds = new Rectangle(25, 220, 70, 30);
            Form2.Bounds = new Rectangle(0, 0, 70, 275);

            Form2.StartPosition = FormStartPosition.CenterParent;
            btn1.DialogResult = DialogResult.OK;
            Form2.ShowDialog();

            x1 = TextBox1.Text;
            y1 = TextBox2.Text;
            x2 = TextBox3.Text;
            y2 = TextBox4.Text;
            Cp = TextBox5.Text;

            Form2.AcceptButton = btn1;

            return Tuple.Create<string, string, string, string, string>(x1, y1, x2, y2, Cp);
        }

        //==================Запрос данных для удаления территории=================================
        static Tuple<string, string, string, string> CreateDlgBox3()
        {
            Form Form2 = new Form
            {
                ControlBox = false,
                Text = String.Empty,
                FormBorderStyle = FormBorderStyle.FixedDialog
            };

            TextBox TextBox1 = new TextBox();
            TextBox TextBox2 = new TextBox();
            TextBox TextBox3 = new TextBox();
            TextBox TextBox4 = new TextBox();

            Label label1 = new Label();
            Label label2 = new Label();
            Label label3 = new Label();
            Label label4 = new Label();

            Button btn1 = new Button();

            string x1, x2;
            string y1, y2;

            TextBox1.Parent = Form2;
            TextBox2.Parent = Form2;
            TextBox3.Parent = Form2;
            TextBox4.Parent = Form2;

            label1.Parent = Form2;
            label2.Parent = Form2;
            label3.Parent = Form2;
            label4.Parent = Form2;

            btn1.Parent = Form2;
            btn1.Text = "OK";

            label1.Text = "X1:";
            label2.Text = "Y1:";
            label3.Text = "X2:";
            label4.Text = "Y2:";

            label1.Bounds = new Rectangle(13, 5, 100, 20);
            TextBox1.Bounds = new Rectangle(13, 20, 100, 20);

            label2.Bounds = new Rectangle(13, 45, 100, 20);
            TextBox2.Bounds = new Rectangle(13, 60, 100, 20);

            label3.Bounds = new Rectangle(13, 85, 100, 20);
            TextBox3.Bounds = new Rectangle(13, 100, 100, 20);

            label4.Bounds = new Rectangle(13, 125, 100, 20);
            TextBox4.Bounds = new Rectangle(13, 140, 100, 20);

            btn1.Bounds = new Rectangle(25, 220, 70, 30);
            Form2.Bounds = new Rectangle(0, 0, 70, 275);

            Form2.StartPosition = FormStartPosition.CenterParent;
            btn1.DialogResult = DialogResult.OK;
            Form2.ShowDialog();

            x1 = TextBox1.Text;
            y1 = TextBox2.Text;
            x2 = TextBox3.Text;
            y2 = TextBox4.Text;

            Form2.AcceptButton = btn1;

            return Tuple.Create<string, string, string, string>(x1, y1, x2, y2);
        }

        //==================Запрос на сохранение файла, если num==0 ==============================
        public bool CreateDlgBox4()
        {
            Form Form2 = new Form
            {
                ControlBox = false,
                Text = String.Empty,
                FormBorderStyle = FormBorderStyle.FixedDialog
            };

            Label label1 = new Label();
            Label label2 = new Label();
            Label label3 = new Label();
            bool flag = false;

            Button btn1 = new Button();
            Button btn2 = new Button();

            label1.Parent = Form2;
            label2.Parent = Form2;
            label3.Parent = Form2;

            btn1.Parent = Form2;
            btn2.Parent = Form2;

            btn1.Text = "Да";
            btn2.Text = "Нет";

            label1.Text = "Все поля пусты.";
            label2.Text = "Файл будет пуст.";
            label3.Text = "Продолжить?";

            label1.Bounds = new Rectangle(13, 5, 100, 20);
            label2.Bounds = new Rectangle(13, 23, 100, 20);
            label3.Bounds = new Rectangle(13, 41, 100, 20);

            btn1.Bounds = new Rectangle(0, 70, 55, 30);
            btn2.Bounds = new Rectangle(74, 70, 55, 30);

            Form2.Bounds = new Rectangle(0, 0, 100, 110);
            Form2.StartPosition = FormStartPosition.CenterParent;

            btn1.DialogResult = DialogResult.OK;
            btn2.DialogResult = DialogResult.Cancel;

            btn1.Click += new EventHandler(myhandler);

            void myhandler(object sender, EventArgs e)
            {
                flag = true;
            }

            Form2.ShowDialog();

            return flag;
        }


        //================================================================================================================================================================
        //Функции проверок, возврата данных.
        //================================================================================================================================================================

        //==================Проверка: если num==0 ================================================
        private bool Check()
        {
            if (num == 0)
            {
                FileStream fs = new FileStream(@"E:\Всё для колледжа\Задачи по программированию\Задачи (основные)\Проекты\Практика 2 курс (2019)\Practic\bin\Debug\Teren.in.txt", FileMode.Create);
                StreamWriter streamWriter = new StreamWriter(fs);

                streamWriter.Write("1");
                streamWriter.WriteLine();
                streamWriter.Write("0 0 0 0 0");

                streamWriter.Close();
                fs.Close();

                dataGridView1.DataSource = ReadFromFile(@"E:\Всё для колледжа\Задачи по программированию\Задачи (основные)\Проекты\Практика 2 курс (2019)\Practic\bin\Debug\Teren.in.txt");
                return true;

            }
            return false;
        }

        //==================Возврат максимального элемента DataGridView1===========================
        private int MaxElem(DataGridView dataGridView)
        {
            int maxE = 0;

            for (int j = 0; j < dataGridView.Rows.Count; j++)
            {
                int Tx2 = Convert.ToInt32(dataGridView.Rows[j].Cells[2].Value);
                int Ty2 = Convert.ToInt32(dataGridView.Rows[j].Cells[3].Value);

                if (Tx2 > maxE) maxE = Tx2;
                if (Ty2 > maxE) maxE = Ty2;
            }
            return ++maxE;
        }

        //==================Проверка на нулевые координаты=========================================
        private void CheckZero()
        {
            int LocalNum=0;
            string[] ar = { "1", "1", "1", "1", "1"};

            try
            {
                using (StreamReader sr = new StreamReader(@"E:\Всё для колледжа\Задачи по программированию\Задачи (основные)\Проекты\Практика 2 курс (2019)\Practic\bin\Debug\Teren.in.txt"))
                {
                    string line;

                    line = sr.ReadLine();
                    LocalNum = Convert.ToInt32(line);

                    line = sr.ReadLine();
                    ar = line.Split(' ');

                    sr.Close();
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine("Файл не может быть прочитан:");
                Console.WriteLine(ex.Message);
            }

            if(LocalNum==1)
            {
                if(ar[0]=="0" && ar[1]=="0" && ar[2]=="0" && ar[3]=="0" && ar[4]=="0")
                {
                    FileStream fs = new FileStream(@"E:\Всё для колледжа\Задачи по программированию\Задачи (основные)\Проекты\Практика 2 курс (2019)\Practic\bin\Debug\Teren.in.txt", FileMode.Create);
                    StreamWriter streamWriter = new StreamWriter(fs);

                    streamWriter.Write("0");
                    streamWriter.WriteLine();

                    streamWriter.Close();
                    fs.Close();
                }
            }
        }

        //================================================================================================================================================================
        //Основные функции
        //================================================================================================================================================================

        //==================Добавление новой территории===========================================
        private void AddRow(string x1, string y1, string x2, string y2, string Cp, DataGridView dataGridView)
        {
            int MaxElement = MaxElem(dataGridView1);

            try
            {
                if (x1 == "" && y1 == "" && x2 == "" && y2 == "" && Cp == "")
                    throw new Exception("Вы ничего не ввели!");

                if (x1 == "" || y1 == "" || x2 == "" || y2 == "" || Cp == "")
                    throw new Exception("Одно из значений не заполнено");

                if (x1 == x2 || y1 == y2)
                    throw new Exception("Значения x1, x2 или y1=y2 равны между собой!");

                int LocalX1 = Convert.ToInt32(x1);
                int LocalY1 = Convert.ToInt32(y1);
                int LocalX2 = Convert.ToInt32(x2);
                int LocalY2 = Convert.ToInt32(y2);
                int LocalCp = Convert.ToInt32(Cp);
                bool WasFound = true;

                if (LocalX1 > LocalX2 || LocalY1 > LocalY2)
                {
                    if (LocalX1 > LocalX2)
                    {
                        int temp;
                        temp = LocalX1;
                        LocalX1 = LocalX2;
                        LocalX2 = temp;
                    }

                    if (LocalY1 > LocalY2)
                    {
                        int temp;
                        temp = LocalY1;
                        LocalY1 = LocalY2;
                        LocalY2 = temp;
                    }

                    MessageBox.Show("Координаты были введены неверно.\nПрограмма всё исправила!");
                }

                if (LocalX1 < 0 || LocalX1 > 1000000000 ||
                    LocalY1 < 0 || LocalY1 > 1000000000 ||
                    LocalX2 < 0 || LocalX2 > 1000000000 ||
                    LocalY2 < 0 || LocalY2 > 1000000000)
                    throw new Exception("Одно из значений не входит в промежуток (0 - 1000000000)");

                if (LocalCp > 100 || LocalCp < 0)
                    throw new Exception("Значение цвета не входит в промежуток (1 - 100)");

                bool ErrorZeroPoint = Check();

                if (!(LocalX1 > MaxElement && LocalX2 > MaxElement && LocalY1 > MaxElement && LocalY2 > MaxElement))
                {
                    for (int i = 0; i < MaxElement && WasFound; i++)
                    {
                        for (int j = 0; j < MaxElement && WasFound; j++)
                        {
                            if (LocalX1 <= j && j < LocalX2 && LocalY1 <= i && i < LocalY2)
                            {
                                if (Convert.ToInt32(dataGridView2.Rows[i].Cells[j].Value) == 0)
                                    WasFound = true;
                                else WasFound = false;
                            }
                        }
                    }
                }

                if (WasFound)
                {
                    DataTable dt = (DataTable)(dataGridView.DataSource);
                    DataRow newRow = dt.NewRow();

                    num++;
                    newRow[0] = Convert.ToString(LocalX1);
                    newRow[1] = Convert.ToString(LocalY1);
                    newRow[2] = Convert.ToString(LocalX2);
                    newRow[3] = Convert.ToString(LocalY2);
                    newRow[4] = Cp;

                    dt.Rows.InsertAt(newRow, dt.Rows.Count);

                    if (ErrorZeroPoint)
                    {
                        dataGridView.Rows.RemoveAt(0);
                        num--;
                    }
                }
                else throw new Exception("Прямоугольники пересекаются!");
            }
            catch (Exception ex)
            {
                MessageBox.Show($"Ошибка: {ex.Message}\nЗначения не были добавлены.");
            }
        }

        //==================Удаление участка======================================================
        private void DelRow(string x1, string y1, string x2, string y2, DataGridView dataGridView)
        {
            int MaxElement = MaxElem(dataGridView);

            try
            {
                if (x1 == "" && y1 == "" && x2 == "" && y2 == "")
                    throw new Exception("Вы ничего не ввели!");

                if (x1 == "" || y1 == "" || x2 == "" || y2 == "")
                    throw new Exception("Одно из значений не заполнено");

                if (x1 == x2 || y1 == y2)
                    throw new Exception("Значения x1, x2 или y1=y2 равны между собой!");

                int LocalX1 = Convert.ToInt32(x1);
                int LocalY1 = Convert.ToInt32(y1);
                int LocalX2 = Convert.ToInt32(x2);
                int LocalY2 = Convert.ToInt32(y2);
                bool WasFound = true;

                if (LocalX1 > LocalX2 || LocalY1 > LocalY2)
                {
                    if (LocalX1 > LocalX2)
                    {
                        int temp;
                        temp = LocalX1;
                        LocalX1 = LocalX2;
                        LocalX2 = temp;
                    }

                    if (LocalY1 > LocalY2)
                    {
                        int temp;
                        temp = LocalY1;
                        LocalY1 = LocalY2;
                        LocalY2 = temp;
                    }

                    MessageBox.Show("Координаты были введены неверно.\nПрограмма всё исправила!");
                }

                if (LocalX1 < 0 || LocalX1 > 1000000000 ||
                    LocalY1 < 0 || LocalY1 > 1000000000 ||
                    LocalX2 < 0 || LocalX2 > 1000000000 ||
                    LocalY2 < 0 || LocalY2 > 1000000000)
                    throw new Exception("Одно из значений не входит в промежуток (0 - 1000000000)");


                for (int i = 0; i < MaxElement && WasFound; i++)
                {
                    for (int j = 0; j < MaxElement && WasFound; j++)
                    {
                        if (Convert.ToInt32(dataGridView.Rows[i].Cells[0].Value) == LocalX1
                            && Convert.ToInt32(dataGridView.Rows[i].Cells[1].Value) == LocalY1
                            && Convert.ToInt32(dataGridView.Rows[i].Cells[2].Value) == LocalX2
                            && Convert.ToInt32(dataGridView.Rows[i].Cells[3].Value) == LocalY2)
                        {
                            dataGridView.Rows.RemoveAt(i);
                            WasFound = false;
                            num--;
                        }
                    }
                }

                if (WasFound) throw new Exception("Прямоугольник по вашим данным не найден");
                else MessageBox.Show("Прямоугольник был удалён!");
            }
            catch (Exception ex)
            {
                MessageBox.Show($"Ошибка: {ex.Message}\nЗначения не были удалены.");
            }
        }

        //==================Строит прямоугольник минимальной площади==============================
        static Tuple<int, int, int, int> MinimalPream(DataGridView dataGridView, int numOf)
        {
            int x1 = 1000000000, y1 = 1000000000, x2 = 0, y2 = 0;

            for (int i = 0; i < numOf; i++)
            {
                if (Convert.ToInt32(dataGridView.Rows[i].Cells[0].Value) < x1) x1 = Convert.ToInt32(dataGridView.Rows[i].Cells[0].Value);
                if (Convert.ToInt32(dataGridView.Rows[i].Cells[1].Value) < y1) y1 = Convert.ToInt32(dataGridView.Rows[i].Cells[1].Value);
                if (Convert.ToInt32(dataGridView.Rows[i].Cells[2].Value) > x2) x2 = Convert.ToInt32(dataGridView.Rows[i].Cells[2].Value);
                if (Convert.ToInt32(dataGridView.Rows[i].Cells[3].Value) > y2) y2 = Convert.ToInt32(dataGridView.Rows[i].Cells[3].Value);
            }

            return Tuple.Create<int, int, int, int>(x1, y1, x2, y2);
        }

        //==================Находит общую площадь всех прямоугольников============================
        private int TotalArea(DataGridView dataGridView)
        {
            int Area = 0;
            int MaxElement = MaxElem(dataGridView1);

            for (int i = 0; i < MaxElement; i++)
            {
                for (int j = 0; j < MaxElement; j++)
                {
                    if (Convert.ToInt32(dataGridView.Rows[i].Cells[j].Value) != 0)
                        Area++;
                }
            }
            return Area;
        }

        //==================Цвет участка с самой большой площадью=================================
        private int ColorArea(DataGridView dataGridView)
        {
            int[] Area = new int[100];
            int max = 0;
            int maxValue = 0;
            int MaxElement = MaxElem(dataGridView1);

            for (int i = 0; i < 100; i++)
                Area[i] = 0;

            for (int i = 0; i < MaxElement; i++)
                for (int j = 0; j < MaxElement; j++)
                {
                    if (Convert.ToInt32(dataGridView.Rows[i].Cells[j].Value) != 0)
                        Area[Convert.ToInt32(dataGridView.Rows[i].Cells[j].Value)]++;
                }

            for (int i = 0; i < 100; i++)
                if (Area[i] > maxValue)
                {
                    max = i;
                    maxValue = Area[i];
                }

            return max;
        }

        //==================Сортировка цветов в порядке возрастания===============================
        private void Sort(DataGridView dataGridView)
        {
            DataGridViewColumn newColumn = dataGridView.Columns[4];
            dataGridView.Sort(newColumn, ListSortDirection.Ascending);
        }

        //================================================================================================================================================================
        //Основное задание
        //================================================================================================================================================================

        //==================Поиск максимальной территории горизонтально===========================
        static Tuple<int, int, int, int, int> FindMaxGorizontal(DataGridView dataGridView, int maxElement)
        {
            int Value;

            int firstX, secondX;
            int firstY, secondY = 0;

            int k = -1;

            int[,] Matrix = new int[1000, 4];
            int[] Arr = new int[1000];

            bool Continue;
            bool Midle;

            for (int i = 0; i < maxElement; i++)
                for (int j = 0; j < maxElement; j++)
                {
                    Continue = true;
                    Midle = true;
                    if (Convert.ToInt32(dataGridView.Rows[i].Cells[j].Value) != 0)
                    {

                        if (j == 0)
                            Midle = true;
                        else
                        if (Convert.ToInt32(dataGridView.Rows[i].Cells[j].Value) == Convert.ToInt32(dataGridView.Rows[i].Cells[j - 1].Value))
                            Midle = false;

                        if (Midle)
                        {
                            k++;
                            Value = Convert.ToInt32(dataGridView.Rows[i].Cells[j].Value);

                            int TempIndex = j + 1;
                            firstX = j;
                            firstY = i;

                            while (Convert.ToInt32(dataGridView.Rows[i].Cells[TempIndex].Value) == Value)
                                TempIndex++;

                            secondX = TempIndex;

                            while (Continue)
                                for (int p = firstY; Continue; p++)
                                {
                                    for (int q = firstX; q < secondX; q++)
                                        if (Convert.ToInt32(dataGridView.Rows[p].Cells[q].Value) != Value)
                                            Continue = false;
                                    secondY = p;
                                }

                            Matrix[k, 0] = firstX;
                            Matrix[k, 1] = firstY;
                            Matrix[k, 2] = secondX;
                            Matrix[k, 3] = secondY;

                            Arr[k] = (secondX - firstX) * (secondY - firstY);
                        }
                    }
                }

            int max = 0;
            int index = 0;

            for (int i = 0; i < Arr.Length; i++)
                if (Arr[i] > max)
                {
                    max = Arr[i];
                    index = i;
                }

            return Tuple.Create<int, int, int, int, int>(Matrix[index, 0], Matrix[index, 1], Matrix[index, 2], Matrix[index, 3], max);
        }

        //==================Поиск максимальной территории вертикально=============================
        static Tuple<int, int, int, int, int> FindMaxVertical(DataGridView dataGridView, int maxElement)
        {
            int Value;

            int firstX, secondX = 0;
            int firstY, secondY;

            int k = -1;

            int[,] Matrix = new int[1000, 4];
            int[] Arr = new int[1000];

            bool Continue;
            bool Midle;

            for (int i = 0; i < maxElement; i++)
                for (int j = 0; j < maxElement; j++)
                {
                    Continue = true;
                    Midle = true;
                    if (Convert.ToInt32(dataGridView.Rows[i].Cells[j].Value) != 0)
                    {
                        if (i == 0)
                            Midle = true;
                        else
                            if (Convert.ToInt32(dataGridView.Rows[i - 1].Cells[j].Value) == Convert.ToInt32(dataGridView.Rows[i].Cells[j].Value))
                            Midle = false;

                        if (Midle)
                        {
                            k++;
                            Value = Convert.ToInt32(dataGridView.Rows[i].Cells[j].Value);

                            int TempIndex = i + 1;
                            firstX = j;
                            firstY = i;

                            while (Convert.ToInt32(dataGridView.Rows[TempIndex].Cells[j].Value) == Value)
                                TempIndex++;

                            secondY = TempIndex;

                            while (Continue)
                                for (int p = firstX; Continue; p++)
                                {
                                    for (int q = firstY; q < secondY; q++)
                                        if (Convert.ToInt32(dataGridView.Rows[q].Cells[p].Value) != Value)
                                            Continue = false;
                                    secondX = p;
                                }

                            Matrix[k, 0] = firstX;
                            Matrix[k, 1] = firstY;
                            Matrix[k, 2] = secondX;
                            Matrix[k, 3] = secondY;

                            Arr[k] = (secondX - firstX) * (secondY - firstY);
                        }
                    }
                }

            int max = 0;
            int index = 0;

            for (int i = 0; i < Arr.Length; i++)
                if (Arr[i] > max)
                {
                    max = Arr[i];
                    index = i;
                }

            return Tuple.Create<int, int, int, int, int>(Matrix[index, 0], Matrix[index, 1], Matrix[index, 2], Matrix[index, 3], max);
        }

    }
}
