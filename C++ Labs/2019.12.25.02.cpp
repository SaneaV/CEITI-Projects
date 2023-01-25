#include <iostream>

using namespace std;

///Вывод результата на экран
void printSolution(int **Board, int n)
{
    int Queen = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << Board[i][j] <<" ";
            if(Board[i][j] == 1)
                Queen++;
        }
        cout << endl;
    }
    cout<<endl<<"Количество королев: "<<Queen;
}

///Проверка, королева не бьёт другую королеву на своей позиции
bool isSafe(int row, int col, int **slashCode,
            int **backslashCode, bool rowLookup[],
            bool slashCodeLookup[], bool backslashCodeLookup[])
{
    if (slashCodeLookup[slashCode[row][col]] or
            backslashCodeLookup[backslashCode[row][col]] or
            rowLookup[row])
        return false;

    return true;
}

///Рекурсивная функция для поиска решения
bool solveNQueensUtil(int **Board, int col,
                      int **slashCode, int **backslashCode, bool rowLookup[],
                      bool slashCodeLookup[], bool backslashCodeLookup[], int n)
{
    ///Граничное условие, что все короле на своих местах
    if (col >= n)
        return true;

    for (int i = 0; i < n; i++)
    {
        ///Проверка, если королева может стоять на месте Доска[i][Колонка]
        if (isSafe(i, col, slashCode, backslashCode, rowLookup,
                   slashCodeLookup, backslashCodeLookup))
        {
            ///Помещаем королеву на позицию Доска[i][Колонка]
            Board[i][col] = 1;
            rowLookup[i] = true;
            slashCodeLookup[slashCode[i][col]] = true;
            backslashCodeLookup[backslashCode[i][col]] = true;

            ///Если королеву нельзя поместить на позицию Доска[i][Колонка]
			///То возвращаем решение
            if (solveNQueensUtil(Board, col + 1, slashCode, backslashCode,
                                 rowLookup, slashCodeLookup, backslashCodeLookup,n))
                return true;

            ///Удаляем королеву с позиции Доска[i][Колонка]
            Board[i][col] = 0;
            rowLookup[i] = false;
            slashCodeLookup[slashCode[i][col]] = false;
            backslashCodeLookup[backslashCode[i][col]] = false;
        }
    }

    ///Если королев больше нельзя поместить на строке, то возвращаем False
    return false;
}

///Эта функция решает проблему N королев, используя
///Branch and Bound.
///Возвращает false, если королевы
///не может быть размещен, иначе вернёт true и
///печатает размещение королев.
bool solveNQueens(int **Board, int n)
{
    ///Дополнительная матрица
    int **slashCode = new int*[n];
    for (int i = 0; i < n; i++)
        slashCode[i] = new int[n];

    ///Дополнительная матрица
    int **backslashCode = new int*[n];
    for (int i = 0; i < n; i++)
        backslashCode[i] = new int[n];

    ///Массивы, чтобы сказать нам, какие строки заняты
    bool rowLookup[n] = { false };

    ///Держим два массива, чтобы показать, какие диагонали заняты
    bool slashCodeLookup[2 * n - 1] = { false };
    bool backslashCodeLookup[2 * n - 1] = { false };

    ///Создаём дополнительную матрицу
    for (int r = 0; r < n; r++)
        for (int c = 0; c < n; c++)
        {
            slashCode[r][c] = r + c,
                              backslashCode[r][c] = r - c + 7;
        }

    if (solveNQueensUtil(Board, 0, slashCode, backslashCode,
                         rowLookup, slashCodeLookup, backslashCodeLookup,n) == false)
    {
        cout<<"Решения не существует";
        return false;
    }

    ///Решение найдено
    printSolution(Board,n);
    return true;
}

///Функция main, где мы производим вызов всех комманд и ввод данных
int main()
{
    setlocale(LC_ALL, "RUS");

    int n;
    cout<<"Введите значение n: ";
    cin>>n;
    cout<<endl;

    int **Board = new int*[n];
    for (int i = 0; i < n; i++)
        Board[i] = new int[n];

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            Board[i][j]=0;

    solveNQueens(Board, n);

    return 1;
}
