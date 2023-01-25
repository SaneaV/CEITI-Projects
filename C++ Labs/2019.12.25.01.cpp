#include<iostream>

using namespace std;

const int N = 8;

//Вывод результата на экран
void printSolution(int board[N][N])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << board[i][j] <<" ";
		cout << endl;
	}
}

//Проверка, королева не бьёт другую королеву на своей позиции
bool isSafe(int row, int col, int slashCode[N][N],
	int backslashCode[N][N], bool rowLookup[],
	bool slashCodeLookup[], bool backslashCodeLookup[])
{
	if (slashCodeLookup[slashCode[row][col]] or
		backslashCodeLookup[backslashCode[row][col]] or
		rowLookup[row])
		return false;

	return true;
}

//Рекурсивная функция для поиска решения
bool solveNQueensUtil(int board[N][N], int col,
	int slashCode[N][N], int backslashCode[N][N], bool rowLookup[N],
	bool slashCodeLookup[], bool backslashCodeLookup[])
{
	//Граничное условие, что все короле на своих местах
	if (col >= N)
		return true;

	for (int i = 0; i < N; i++)
	{
		//Проверка, если королева может стоять на месте Доска[i][Колонка]
		if (isSafe(i, col, slashCode, backslashCode, rowLookup,
			slashCodeLookup, backslashCodeLookup))
		{
			//Помещаем королеву на позицию Доска[i][Колонка]
			board[i][col] = 1;
			rowLookup[i] = true;
			slashCodeLookup[slashCode[i][col]] = true;
			backslashCodeLookup[backslashCode[i][col]] = true;
			
			if (solveNQueensUtil(board, col + 1, slashCode, backslashCode,
				rowLookup, slashCodeLookup, backslashCodeLookup))
				return true;

			//Если королеву нельзя поместить на позицию Доска[i][Колонка]
			//То возвращаем решение
			//Удаляем королеву с позиции Доска[i][Колонка]
			board[i][col] = 0;
			rowLookup[i] = false;
			slashCodeLookup[slashCode[i][col]] = false;
			backslashCodeLookup[backslashCode[i][col]] = false;
		}
	}

	//Если королев больше нельзя поместить на строке, то возвращаем False
	return false;
}

//Эта функция решает проблему N королев, используя
//Branch and Bound.
//Возвращает false, если королевы
//не может быть размещен, иначе вернёт true и
//печатает размещение королев.
bool solveNQueens()
{
	int board[N][N];
	memset(board, 0, sizeof board);

	//Дополнительная матрица
	int slashCode[N][N];
	int backslashCode[N][N];

	//Массивы, чтобы сказать нам, какие строки заняты

	bool rowLookup[N] = { false };

	//Держим два массива, чтобы показать, какие диагонали заняты
	bool slashCodeLookup[2 * N - 1] = { false };
	bool backslashCodeLookup[2 * N - 1] = { false };

	//Создаём дополнительную матрицу
	for (int r = 0; r < N; r++)
		for (int c = 0; c < N; c++)
			slashCode[r][c] = r + c,
			backslashCode[r][c] = r - c + 7;

	if (solveNQueensUtil(board, 0, slashCode, backslashCode,
		rowLookup, slashCodeLookup, backslashCodeLookup) == false)
	{
		cout<<"Решения не существует";
		return false;
	}

	///Решение найдено
	printSolution(board);
	return true;
}

//Функция main, где мы производим вызов всех комманд и ввод данных
int main()
{
	setlocale(LC_ALL, "rus");

	solveNQueens(); // Вызов главной функции

	return 0;
}
