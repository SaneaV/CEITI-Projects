#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

void showMatrix(string **matrix, int rows)
{
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<rows; j++)
            cout<<matrix[i][j]<<" ";
        cout<<endl;
    }
}

string decToHexa(int dec_num)
{
    int r;
    string hexdec_num="";
    char hex[]= {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

    while(dec_num>0)
    {
        r = dec_num % 16;
        hexdec_num = hex[r] + hexdec_num;
        dec_num = dec_num/16;
    }

    return hexdec_num;
}

string **fillMatrix(string matrixString, string **matrix, int rows)
{
    int k = 0;
    for(int i=0; i<rows; i++)
        for(int j=0; j<rows; j++)
        {
            matrix[i][j] = decToHexa(matrixString[k++] - '0');
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

void deleteMatrix(string **matrix, int rows)
{
    for (int i = 0; i < rows; ++i)
        delete [] matrix[i];
    delete [] matrix;
}

/*TASKS*/
bool first(string** matrix, int rows)
{
    //a(bc)=(ab)c

    for(int a=0; a<rows; a++)
        for(int b=0; b<rows; b++)
            for(int c=0; c<rows; c++)
            {
                string p1 = matrix[b][c];
                string p2 = matrix[a][b];
                if(matrix[a][p1]!=matrix[p2][c])
                {
                    return false;
                }
            }
    return true;
}

bool second(string** matrix, int rows)
{
    //(ab)(cd)=(ac)(bd)

    for(int a=0; a<rows; a++)
        for(int b=0; b<rows; b++)
            for(int c=0; c<rows; c++)
                for(int d=0; d<rows; d++)
                {
                    string p1 = matrix[a][b];
                    string p2 = matrix[c][d];
                    string p3 = matrix[a][c];
                    string p4 = matrix[b][d];

                    if(matrix[p1][p2]!=matrix[p3][p4])
                    {
                        return false;
                    }
                }
    return true;
}

bool third(string** matrix, int rows)
{
    //(ab)(cd)=(db)(ca)

    for(int a=0; a<rows; a++)
        for(int b=0; b<rows; b++)
            for(int c=0; c<rows; c++)
                for(int d=0; d<rows; d++)
                {
                    string p1 = matrix[a][b];
                    string p2 = matrix[c][d];
                    string p3 = matrix[d][b];
                    string p4 = matrix[c][a];

                    if(matrix[p1][p2]!=matrix[p3][p4])
                    {
                        return false;
                    }
                }
    return true;
}

bool fourth(string** matrix, int rows)
{
    //(ab)(cd)=(dc)(ba)

    for(int a=0; a<rows; a++)
        for(int b=0; b<rows; b++)
            for(int c=0; c<rows; c++)
                for(int d=0; d<rows; d++)
                {
                    string p1 = matrix[a][b];
                    string p2 = matrix[c][d];
                    string p3 = matrix[d][c];
                    string p4 = matrix[b][a];

                    if(matrix[p1][p2]!=matrix[p3][p4])
                    {
                        return false;
                    }
                }
    return true;
}

bool fifth(string** matrix, int rows)
{
    //(ab)c=(cb)a

    for(int a=0; a<rows; a++)
        for(int b=0; b<rows; b++)
            for(int c=0; c<rows; c++)
            {
                string p1 = matrix[a][b];
                string p2 = matrix[c][b];
                if(matrix[p1][c]!=matrix[p2][a])
                {
                    return false;
                }
            }
    return true;
}

bool sixth(string** matrix, int rows)
{
    //(ab)c=c(ba)

    for(int a=0; a<rows; a++)
        for(int b=0; b<rows; b++)
            for(int c=0; c<rows; c++)
            {
                string p1 = matrix[a][b];
                string p2 = matrix[b][a];
                if(matrix[p1][c]!=matrix[c][p2])
                {
                    return false;
                }
            }
    return true;
}

bool seventh(string** matrix, int rows)
{
    //(ab)c=(ca)b

    for(int a=0; a<rows; a++)
        for(int b=0; b<rows; b++)
            for(int c=0; c<rows; c++)
            {
                string p1 = matrix[a][b];
                string p2 = matrix[c][a];
                if(matrix[p1][c]!=matrix[p2][b])
                {
                    return false;
                }
            }
    return true;
}

bool eight(string** matrix, int rows)
{
    //a(bc)=c(ba)

    for(int a=0; a<rows; a++)
        for(int b=0; b<rows; b++)
            for(int c=0; c<rows; c++)
            {
                string p1 = matrix[b][c];
                string p2 = matrix[b][a];
                if(matrix[a][p1]!=matrix[c][p2])
                {
                    return false;
                }
            }
    return true;
}

bool ninth(string** matrix, int rows)
{
    //a(bc)=c(ab)

    for(int a=0; a<rows; a++)
        for(int b=0; b<rows; b++)
            for(int c=0; c<rows; c++)
            {
                string p1 = matrix[b][c];
                string p2 = matrix[a][b];
                if(matrix[a][p1]!=matrix[c][p2])
                {
                    return false;
                }
            }
    return true;
}


bool eleventh(string** matrix, int rows)
{
    //(ab)c=(ac)(bc)

    for(int a=0; a<rows; a++)
        for(int b=0; b<rows; b++)
            for(int c=0; c<rows; c++)
            {
                string p1 = matrix[a][b];
                string p2 = matrix[a][c];
                string p3 = matrix[b][c];
                if(matrix[p1][c]!=matrix[p2][p3])
                {
                    return false;
                }
            }
    return true;
}

bool twelfth(string** matrix, int rows)
{
    //c(ab)=(ca)(cb)

    for(int a=0; a<rows; a++)
        for(int b=0; b<rows; b++)
            for(int c=0; c<rows; c++)
            {
                string p1 = matrix[a][b];
                string p2 = matrix[c][a];
                string p3 = matrix[c][b];
                if(matrix[c][p1]!=matrix[p2][p3])
                {
                    return false;
                }
            }
    return true;
}


bool sixteenth(string** matrix, int rows)
{
    //ab=(ac)(bc)

    for(int a=0; a<rows; a++)
        for(int b=0; b<rows; b++)
            for(int c=0; c<rows; c++)
            {
                string p1 = matrix[a][c];
                string p2 = matrix[b][c];
                if(a*b!=matrix[p1][p2])
                {
                    return false;
                }
            }
    return true;
}

bool seveteenth(string** matrix, int rows)
{
    //ab=(ca)(cb)

    for(int a=0; a<rows; a++)
        for(int b=0; b<rows; b++)
            for(int c=0; c<rows; c++)
            {
                string p1 = matrix[c][a];
                string p2 = matrix[c][b];
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

            string** matrix = new string*[rows];
            for (int i = 0; i < rows; ++i)
                matrix[i] = new string[rows];

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
            cout<<"Eleventh task: "<<eleventh(matrix, rows)<<endl;
            cout<<"Twelfth task: "<<twelfth(matrix, rows)<<endl;
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

