#include <iostream>
#include <fstream>
#include <map>

using namespace std;

int GetSize(int &Size)
{
    ifstream f("Maze.txt");
    f>>Size;
    f.close();
    return Size;
}

void FillMaze(int const Size, int** &Maze)
{
    ifstream f("Maze.txt");
    f.ignore();
    f.ignore();

    for(int i=0; i<Size; i++)
    {
        for(int j=0; j<Size; j++)
            f>>Maze[i][j];
    }
    f.close();
}

void FindStartFinish(int const Size, int** Maze, pair<int,int> &Start)
{
    for(int i=0; i<Size; i++)
        for(int j=0; j<Size; j++)
        {
            if(Maze[i][j]==-1)
            {
                Start.first = i;
                Start.second = j;
            }
        }
}

void PrintMaze(int const Size, int** const Maze)
{
    for(int i=0; i<Size; i++)
    {
        for(int j=0; j<Size; j++)
            cout<<Maze[i][j]<<" ";
        cout<<endl;
    }
}

int NumberOf = 0;
void FindExit(int const Size, int** &Maze, pair<int,int> const Start)
{
    Maze[Start.first][Start.second] = 1;

    pair<int,int> P[100];
    bool HaveSpace = false;
    bool Finish = false;
    int Hod = 0;

    int i = Start.first;
    int j = Start.second;

    while(!Finish)
    {
        HaveSpace = false;
        Hod = NumberOf;

        ///вниз
        if(Maze[i+1][j]==1 and i>=0 and j>=0 and i<Size and j<Size)
        {
            int k = i;
            Maze[k+1][j] = Maze[k][j]+1;
            HaveSpace = true;

            while(HaveSpace)
            {
                if(Maze[k-1][j]==1 and k>=0 and j>=0 and k<Size and j<Size)
                {
                    P[NumberOf].first = k;
                    P[NumberOf].second = j;
                    NumberOf++;
                }
                if(Maze[k][j-1]==1 and k>=0 and j>=0 and k<Size and j<Size)
                {
                    P[NumberOf].first = k;
                    P[NumberOf].second = j;
                    NumberOf++;
                }
                if(Maze[k][j+1]==1 and k>=0 and j>=0 and k<Size and j<Size)
                {
                    P[NumberOf].first = k;
                    P[NumberOf].second = j;
                    NumberOf++;
                }

                if(Maze[k+1][j]==0)
                {
                    HaveSpace=false;
                }
                else
                {
                    k++;
                    Maze[k+1][j] = Maze[k][j]+1;
                }

                if(Maze[k][j]==-2) Finish = true;
            }
        }

        ///вверх
        if(Maze[i-1][j]==1 and i>=0 and j>=0 and i<Size and j<Size)
        {
            int k = i;
            Maze[k-1][j] = Maze[k][j]+1;
            HaveSpace = true;

            while(HaveSpace)
            {
                if(Maze[k+1][j]==1 and k>=0 and j>=0 and k<Size and j<Size)
                {
                    P[NumberOf].first = k;
                    P[NumberOf].second = j;
                    NumberOf++;
                }
                if(Maze[k][j-1]==1 and k>=0 and j>=0 and k<Size and j<Size)
                {
                    P[NumberOf].first = k;
                    P[NumberOf].second = j;
                    NumberOf++;
                }
                if(Maze[k][j+1]==1 and k>=0 and j>=0 and k<Size and j<Size)
                {
                    P[NumberOf].first = k;
                    P[NumberOf].second = j;
                    NumberOf++;
                }

                if(Maze[k-1][j]==0)
                {
                    HaveSpace=false;
                }
                else
                {
                    k++;
                    Maze[k-1][j] = Maze[k][j]+1;
                }

                if(Maze[k][j]==-2) Finish = true;
            }
        }

        ///влево
        if(Maze[i][j-1]==1 and i>=0 and j>=0 and i<Size and j<Size)
        {
            int k = j;
            Maze[i][k-1] = Maze[i][k]+1;
            HaveSpace = true;

            while(HaveSpace)
            {
                if(Maze[i][k+1]==1 and k>=0 and i>=0 and k<Size and i<Size)
                {
                    P[NumberOf].first = i;
                    P[NumberOf].second = k;
                    NumberOf++;
                }
                if(Maze[i-1][k]==1 and k>=0 and i>=0 and k<Size and i<Size)
                {
                    P[NumberOf].first = i;
                    P[NumberOf].second = k;
                    NumberOf++;
                }
                if(Maze[i+1][k]==1 and k>=0 and i>=0 and k<Size and i<Size)
                {
                    P[NumberOf].first = i;
                    P[NumberOf].second = k;
                    NumberOf++;
                }

                if(Maze[i][k-1]==0)
                {
                    HaveSpace=false;
                }
                else
                {
                    k++;
                    Maze[i][k-1] = Maze[i][k]+1;
                }

                if(Maze[i][k]==-2) Finish = true;
            }
        }

        ///вправо
        if(Maze[i][j+1]==1 and i>=0 and j>=0 and i<Size and j<Size)
        {
            int k = j;
            Maze[i][k+1] = Maze[i][k]+1;
            HaveSpace = true;

            while(HaveSpace)
            {
                if(Maze[i][k-1]==1 and k>=0 and i>=0 and k<Size and i<Size)
                {
                    P[NumberOf].first = i;
                    P[NumberOf].second = k;
                    NumberOf++;
                }
                if(Maze[i-1][k]==1 and k>=0 and i>=0 and k<Size and i<Size)
                {
                    P[NumberOf].first = i;
                    P[NumberOf].second = k;
                    NumberOf++;
                }
                if(Maze[i+1][k]==1 and k>=0 and i>=0 and k<Size and i<Size)
                {
                    P[NumberOf].first = i;
                    P[NumberOf].second = k;
                    NumberOf++;
                }

                if(Maze[i][k+1]==0)
                {
                    HaveSpace=false;
                }
                else
                {
                    k++;
                    Maze[i][k+1] = Maze[i][k]+1;
                }

                if(Maze[i][k]==-2) Finish = true;
            }
        }

        i = P[Hod].first;
        j = P[Hod].second;
        Hod++;
    }
}

int main()
{
    setlocale(LC_ALL,"RUS");

    int Size = 0;

    pair<int,int> Start;

    Size = GetSize(Size);

    int **Maze = new int *[Size];
    for (int i=0; i<Size; i++)
        Maze[i] = new int [Size];

    FindStartFinish(Size, Maze, Start);
    FillMaze(Size, Maze);
    PrintMaze(Size, Maze);

    FindExit(Size, Maze, Start);
    cout<<endl<<endl;
    PrintMaze(Size, Maze);

    return 0;
}
