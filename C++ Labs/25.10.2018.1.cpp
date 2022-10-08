//Задача о лабиринте

#include <iostream>
#include <fstream>

using namespace std;

ifstream f("Labyrint.txt");

const int N_MAX = 2005;
const int M_MAX = 2005;

int N, M;

unsigned int StartX, StartY;
unsigned int FinishX, FinishY;

unsigned int matrice[N_MAX][M_MAX];

const int direction = 4;
const int di[direction] = {-1, 0, 1,  0};
const int dj[direction] = {0,  1, 0, -1};

void Read()
{
    f >> N >> M;
    f >> StartX >> StartY;
    f >> FinishX >> FinishY;

    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            f >> matrice[i][j];
}

bool Continue(int i, int j)
{
    if(i > N or i < 1)
        return false;
    if(j > M or j < 1)
        return false;

    if(matrice[i][j] == 1 or (i == FinishX and j == FinishY))
        return true;

    if(matrice[i][j] == 0 or matrice[i][j])
        return false;

    return true;
}

void afisare()
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
            cout << matrice[i][j] << " ";

        cout << endl;
    }
    cout << endl <<endl;
}

void Rezolvare(int i, int j, int step)
{
    if(i == FinishX and j == FinishY)
        afisare();
    else
    {
        for(int k = 0; k < direction; k++)
        {
            int i_neig = i + di[k];
            int j_neig = j + dj[k];
            if(Continue(i_neig, j_neig))
            {
                matrice[i_neig][j_neig] = step;
                Rezolvare(i_neig, j_neig, step + 1);
                matrice[i_neig][j_neig] = 0;
            }
        }
    }
}

int main()
{
    Read();
    Rezolvare(StartX, StartY, 2);
    return 0;
}
