п»ї#include<iostream>

using namespace std;

const int N = 8;

///Р’С‹РІРѕРґ СЂРµР·СѓР»СЊС‚Р°С‚Р° РЅР° СЌРєСЂР°РЅ
void printSolution(int board[N][N])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << board[i][j] <<" ";
		cout << endl;
	}
}

///РџСЂРѕРІРµСЂРєР°, РєРѕСЂРѕР»РµРІР° РЅРµ Р±СЊС‘С‚ РґСЂСѓРіСѓСЋ РєРѕСЂРѕР»РµРІСѓ РЅР° СЃРІРѕРµР№ РїРѕР·РёС†РёРё
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

///Р РµРєСѓСЂСЃРёРІРЅР°СЏ С„СѓРЅРєС†РёСЏ РґР»СЏ РїРѕРёСЃРєР° СЂРµС€РµРЅРёСЏ
bool solveNQueensUtil(int board[N][N], int col,
	int slashCode[N][N], int backslashCode[N][N], bool rowLookup[N],
	bool slashCodeLookup[], bool backslashCodeLookup[])
{
	///Р“СЂР°РЅРёС‡РЅРѕРµ СѓСЃР»РѕРІРёРµ, С‡С‚Рѕ РІСЃРµ РєРѕСЂРѕР»Рµ РЅР° СЃРІРѕРёС… РјРµСЃС‚Р°С…
	if (col >= N)
		return true;

	for (int i = 0; i < N; i++)
	{
		///РџСЂРѕРІРµСЂРєР°, РµСЃР»Рё РєРѕСЂРѕР»РµРІР° РјРѕР¶РµС‚ СЃС‚РѕСЏС‚СЊ РЅР° РјРµСЃС‚Рµ Р”РѕСЃРєР°[i][РљРѕР»РѕРЅРєР°]
		if (isSafe(i, col, slashCode, backslashCode, rowLookup,
			slashCodeLookup, backslashCodeLookup))
		{
			///РџРѕРјРµС‰Р°РµРј РєРѕСЂРѕР»РµРІСѓ РЅР° РїРѕР·РёС†РёСЋ Р”РѕСЃРєР°[i][РљРѕР»РѕРЅРєР°]
			board[i][col] = 1;
			rowLookup[i] = true;
			slashCodeLookup[slashCode[i][col]] = true;
			backslashCodeLookup[backslashCode[i][col]] = true;
			
			if (solveNQueensUtil(board, col + 1, slashCode, backslashCode,
				rowLookup, slashCodeLookup, backslashCodeLookup))
				return true;

			///Р•СЃР»Рё РєРѕСЂРѕР»РµРІСѓ РЅРµР»СЊР·СЏ РїРѕРјРµСЃС‚РёС‚СЊ РЅР° РїРѕР·РёС†РёСЋ Р”РѕСЃРєР°[i][РљРѕР»РѕРЅРєР°]
			///РўРѕ РІРѕР·РІСЂР°С‰Р°РµРј СЂРµС€РµРЅРёРµ

			///РЈРґР°Р»СЏРµРј РєРѕСЂРѕР»РµРІСѓ СЃ РїРѕР·РёС†РёРё Р”РѕСЃРєР°[i][РљРѕР»РѕРЅРєР°]
			board[i][col] = 0;
			rowLookup[i] = false;
			slashCodeLookup[slashCode[i][col]] = false;
			backslashCodeLookup[backslashCode[i][col]] = false;
		}
	}

	///Р•СЃР»Рё РєРѕСЂРѕР»РµРІ Р±РѕР»СЊС€Рµ РЅРµР»СЊР·СЏ РїРѕРјРµСЃС‚РёС‚СЊ РЅР° СЃС‚СЂРѕРєРµ, С‚Рѕ РІРѕР·РІСЂР°С‰Р°РµРј False
	return false;
}

///Р­С‚Р° С„СѓРЅРєС†РёСЏ СЂРµС€Р°РµС‚ РїСЂРѕР±Р»РµРјСѓ N РєРѕСЂРѕР»РµРІ, РёСЃРїРѕР»СЊР·СѓСЏ
///Branch and Bound.
///Р’РѕР·РІСЂР°С‰Р°РµС‚ false, РµСЃР»Рё РєРѕСЂРѕР»РµРІС‹
///РЅРµ РјРѕР¶РµС‚ Р±С‹С‚СЊ СЂР°Р·РјРµС‰РµРЅ, РёРЅР°С‡Рµ РІРµСЂРЅС‘С‚ true Рё
///РїРµС‡Р°С‚Р°РµС‚ СЂР°Р·РјРµС‰РµРЅРёРµ РєРѕСЂРѕР»РµРІ.
bool solveNQueens()
{
	int board[N][N];
	memset(board, 0, sizeof board);

	///Р”РѕРїРѕР»РЅРёС‚РµР»СЊРЅР°СЏ РјР°С‚СЂРёС†Р°
	int slashCode[N][N];
	int backslashCode[N][N];

	///РњР°СЃСЃРёРІС‹, С‡С‚РѕР±С‹ СЃРєР°Р·Р°С‚СЊ РЅР°Рј, РєР°РєРёРµ СЃС‚СЂРѕРєРё Р·Р°РЅСЏС‚С‹
	bool rowLookup[N] = { false };

	///Р”РµСЂР¶РёРј РґРІР° РјР°СЃСЃРёРІР°, С‡С‚РѕР±С‹ РїРѕРєР°Р·Р°С‚СЊ, РєР°РєРёРµ РґРёР°РіРѕРЅР°Р»Рё Р·Р°РЅСЏС‚С‹
	bool slashCodeLookup[2 * N - 1] = { false };
	bool backslashCodeLookup[2 * N - 1] = { false };

	///РЎРѕР·РґР°С‘Рј РґРѕРїРѕР»РЅРёС‚РµР»СЊРЅСѓСЋ РјР°С‚СЂРёС†Сѓ
	for (int r = 0; r < N; r++)
		for (int c = 0; c < N; c++)
			slashCode[r][c] = r + c,
			backslashCode[r][c] = r - c + 7;

	if (solveNQueensUtil(board, 0, slashCode, backslashCode,
		rowLookup, slashCodeLookup, backslashCodeLookup) == false)
	{
		cout<<"Р РµС€РµРЅРёСЏ РЅРµ СЃСѓС‰РµСЃС‚РІСѓРµС‚";
		return false;
	}

	///Р РµС€РµРЅРёРµ РЅР°Р№РґРµРЅРѕ
	printSolution(board);
	return true;
}

///Р¤СѓРЅРєС†РёСЏ main, РіРґРµ РјС‹ РїСЂРѕРёР·РІРѕРґРёРј РІС‹Р·РѕРІ РІСЃРµС… РєРѕРјРјР°РЅРґ Рё РІРІРѕРґ РґР°РЅРЅС‹С…
int main()
{
	setlocale(LC_ALL, "rus");

	solveNQueens(); // Р’С‹Р·РѕРІ РіР»Р°РІРЅРѕР№ С„СѓРЅРєС†РёРё

	return 0;
}
