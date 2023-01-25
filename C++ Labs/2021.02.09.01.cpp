#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void showMatrix(int **matrix, int rows)
{
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<rows; j++)
            cout<<matrix[i][j]<<" ";
        cout<<endl;
    }
}

int **fillMatrix(string matrixString, int **matrix, int rows)
{
    int k = 0;
    for(int i=0; i<rows; i++)
        for(int j=0; j<rows; j++)
        {
            matrix[i][j] = matrixString[k++] - '0';
        }
    return matrix;
}

pair<string, int>ReadFromFile(string fileName, int startFrom)
{
    ifstream file;
    file.open(fileName);
    string matrixString = "";
    string line;
    int rows = 0;

    file.ignore(startFrom);

    while(getline(file,line))
    {
        if(line=="") break;
        matrixString+=line;
        rows++;
    }
    file.close();

    return make_pair(matrixString, rows);
}

void deleteMatrix(int **matrix, int rows)
{
    for (int i = 0; i < rows; ++i)
        delete [] matrix[i];
    delete [] matrix;
}

/*TASKS*/
bool first(int** matrix, int rows)
{
    //a(bc)=(ab)c

    for(int a=0; a<rows; a++)
        for(int b=0; b<rows; b++)
            for(int c=0; c<rows; c++)
            {
                int p1 = matrix[b][c];
                int p2 = matrix[a][b];
                if(matrix[a][p1]!=matrix[p2][c])
                {
                    return false;
                }
            }
    return true;
}

bool second(int** matrix, int rows)
{
    //(ab)(cd)=(ac)(bd)

    for(int a=0; a<rows; a++)
        for(int b=0; b<rows; b++)
            for(int c=0; c<rows; c++)
                for(int d=0; d<rows; d++)
                {
                    int p1 = matrix[a][b];
                    int p2 = matrix[c][d];
                    int p3 = matrix[a][c];
                    int p4 = matrix[b][d];

                    if(matrix[p1][p2]!=matrix[p3][p4])
                    {
                        return false;
                    }
                }
    return true;
}

bool third(int** matrix, int rows)
{
    //(ab)(cd)=(db)(ca)

    for(int a=0; a<rows; a++)
        for(int b=0; b<rows; b++)
            for(int c=0; c<rows; c++)
                for(int d=0; d<rows; d++)
                {
                    int p1 = matrix[a][b];
                    int p2 = matrix[c][d];
                    int p3 = matrix[d][b];
                    int p4 = matrix[c][a];

                    if(matrix[p1][p2]!=matrix[p3][p4])
                    {
                        return false;
                    }
                }
    return true;
}

bool fourth(int** matrix, int rows)
{
    //(ab)(cd)=(dc)(ba)

    for(int a=0; a<rows; a++)
        for(int b=0; b<rows; b++)
            for(int c=0; c<rows; c++)
                for(int d=0; d<rows; d++)
                {
                    int p1 = matrix[a][b];
                    int p2 = matrix[c][d];
                    int p3 = matrix[d][c];
                    int p4 = matrix[b][a];

                    if(matrix[p1][p2]!=matrix[p3][p4])
                    {
                        return false;
                    }
                }
    return true;
}

bool fifth(int** matrix, int rows)
{
    //(ab)c=(cb)a

    for(int a=0; a<rows; a++)
        for(int b=0; b<rows; b++)
            for(int c=0; c<rows; c++)
            {
                int p1 = matrix[a][b];
                int p2 = matrix[c][b];
                if(matrix[p1][c]!=matrix[p2][a])
                {
                    return false;
                }
            }
    return true;
}

bool sixth(int** matrix, int rows)
{
    //(ab)c=c(ba)

    for(int a=0; a<rows; a++)
        for(int b=0; b<rows; b++)
            for(int c=0; c<rows; c++)
            {
                int p1 = matrix[a][b];
                int p2 = matrix[b][a];
                if(matrix[p1][c]!=matrix[c][p2])
                {
                    return false;
                }
            }
    return true;
}

bool seventh(int** matrix, int rows)
{
    //(ab)c=(ca)b

    for(int a=0; a<rows; a++)
        for(int b=0; b<rows; b++)
            for(int c=0; c<rows; c++)
            {
                int p1 = matrix[a][b];
                int p2 = matrix[c][a];
                if(matrix[p1][c]!=matrix[p2][b])
                {
                    return false;
                }
            }
    return true;
}

bool eight(int** matrix, int rows)
{
    //a(bc)=c(ba)

    for(int a=0; a<rows; a++)
        for(int b=0; b<rows; b++)
            for(int c=0; c<rows; c++)
            {
                int p1 = matrix[b][c];
                int p2 = matrix[b][a];
                if(matrix[a][p1]!=matrix[c][p2])
                {
                    return false;
                }
            }
    return true;
}

bool ninth(int** matrix, int rows)
{
    //a(bc)=c(ab)

    for(int a=0; a<rows; a++)
        for(int b=0; b<rows; b++)
            for(int c=0; c<rows; c++)
            {
                int p1 = matrix[b][c];
                int p2 = matrix[a][b];
                if(matrix[a][p1]!=matrix[c][p2])
                {
                    return false;
                }
            }
    return true;
}

bool tenth(int** matrix, int rows)
{
    //aa=a; (ab)(cd)=(ac)(bd); a(ba)=(ab)a=b

    for(int a=0; a<rows; a++)
        for(int b=0; b<rows; b++)
            for(int c=0; c<rows; c++)
                for(int d=0; d<rows; d++)
                {
                    int p1 = matrix[a][b];
                    int p2 = matrix[c][d];
                    int p3 = matrix[a][c];
                    int p4 = matrix[b][d];
                    int p5 = matrix[b][a];
                    if((a*a!=a) && (matrix[p1][p2]!=matrix[p3][p4]) && (matrix[a][p5]!=matrix[p1][a]) && (matrix[p1][a]!=b))
                    {
                        return false;
                    }
                }
    return true;
}

bool eleventh(int** matrix, int rows)
{
    //(ab)c=(ac)(bc)

    for(int a=0; a<rows; a++)
        for(int b=0; b<rows; b++)
            for(int c=0; c<rows; c++)
            {
                int p1 = matrix[a][b];
                int p2 = matrix[a][c];
                int p3 = matrix[b][c];
                if(matrix[p1][c]!=matrix[p2][p3])
                {
                    return false;
                }
            }
    return true;
}

bool twelfth(int** matrix, int rows)
{
    //c(ab)=(ca)(cb)

    for(int a=0; a<rows; a++)
        for(int b=0; b<rows; b++)
            for(int c=0; c<rows; c++)
            {
                int p1 = matrix[a][b];
                int p2 = matrix[c][a];
                int p3 = matrix[c][b];
                if(matrix[c][p1]!=matrix[p2][p3])
                {
                    return false;
                }
            }
    return true;
}

bool thirteenth(int** matrix, int rows)
{
    //xe=x

    for(int x=0; x<rows; x++)
        for(int e=0; e<rows; e++)
        {
            if(x*e!=x)
            {
                return false;
            }
        }
    return true;
}

bool fourteenth(int** matrix, int rows)
{
    //ex=x

    for(int x=0; x<rows; x++)
        for(int e=0; e<rows; e++)
        {
            if(e*x!=x)
            {
                return false;
            }
        }
    return true;
}

bool fifteenth(int** matrix, int rows)
{
    //xe=ex=x

    for(int x=0; x<rows; x++)
        for(int e=0; e<rows; e++)
        {
            if((x*e!=e*x) && (e*x!=x))
            {
                return false;
            }
        }
    return true;
}

bool sixteenth(int** matrix, int rows)
{
    //ab=(ac)(bc)

    for(int a=0; a<rows; a++)
        for(int b=0; b<rows; b++)
            for(int c=0; c<rows; c++)
            {
                int p1 = matrix[a][c];
                int p2 = matrix[b][c];
                if(a*b!=matrix[p1][p2])
                {
                    return false;
                }
            }
    return true;
}

bool seveteenth(int** matrix, int rows)
{
    //ab=(ca)(cb)

    for(int a=0; a<rows; a++)
        for(int b=0; b<rows; b++)
            for(int c=0; c<rows; c++)
            {
                int p1 = matrix[c][a];
                int p2 = matrix[c][b];
                if(a*b!=matrix[p1][p2])
                {
                    return false;
                }
            }
    return true;
}

/*
cout<<endl<<"a = "<<a<<" "<<" b = "<<b<<" "<<" c = "<<c<<" "<<" d = "<<d;
cout<<endl<<"p1 = "<<p1<<" "<<" p2 = "<<p2<<" "<<" p3 = "<<p3<<" "<<" p4 = "<<p4;
cout<<endl<<"matrix["<<a<<"]["<<c<<"] = "<<matrix[a][c]<<" "<<" matrix["<<b<<"]["<<d<<"] = "<<matrix[b][d];
cout<<endl<<"matrix["<<p1<<"]["<<p2<<"] = "<<matrix[p1][p2]<<" "<<" matrix["<<p3<<"]["<<p4<<"] = "<<matrix[p3][p4]<<endl;
*/

int main()
{
    string matrixString = "";
    int rows = 0;
    int startFrom = 0;
    do
    {
        rows = 0;
        pair<string, int> p = ReadFromFile("Matrix.txt", startFrom);

        if(p.second!=0)
        {
            rows = p.second;
            matrixString = p.first;

            int** matrix = new int*[rows];
            for (int i = 0; i < rows; ++i)
                matrix[i] = new int[rows];

            matrix = fillMatrix(matrixString, matrix, rows);
            cout<<"MATRIX:"<<endl;
            showMatrix(matrix, rows);

            cout<<endl<<"TASKS:"<<endl;
            cout<<"First task: "<<first(matrix, rows)<<endl;
            cout<<"Second task: "<<second(matrix, rows)<<endl;
            cout<<"Third task: "<<third(matrix, rows)<<endl;
            cout<<"Fourth task: "<<fourth(matrix, rows)<<endl;
            cout<<"Fifth task: "<<fifth(matrix, rows)<<endl;
            cout<<"Sixth task: "<<sixth(matrix, rows)<<endl;
            cout<<"Seventh task: "<<seventh(matrix, rows)<<endl;
            cout<<"Eight task: "<<eight(matrix, rows)<<endl;
            cout<<"Ninth task: "<<ninth(matrix, rows)<<endl;
            cout<<"Tenth task: "<<tenth(matrix, rows)<<endl;
            cout<<"Eleventh task: "<<eleventh(matrix, rows)<<endl;
            cout<<"Twelfth task: "<<twelfth(matrix, rows)<<endl;
            cout<<"Thirteenth task: "<<thirteenth(matrix, rows)<<endl;
            cout<<"Fourteenth task: "<<fourteenth(matrix, rows)<<endl;
            cout<<"Fifteenth task: "<<fifteenth(matrix, rows)<<endl;
            cout<<"Sixteenth task: "<<sixteenth(matrix, rows)<<endl;
            cout<<"Seventeenth task: "<<seveteenth(matrix, rows)<<endl;
            cout<<endl<<endl;

            deleteMatrix(matrix,rows);
            startFrom += matrixString.length() + rows + 1;
        }

    }
    while(rows!=0);

    return 0;
}
