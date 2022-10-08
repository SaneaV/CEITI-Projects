#include <iostream>
#include <fstream>

using namespace std;

int n;
char l;
int G[100][100];
int nodes[100];

void Reading()
{
    ifstream f("Graf.txt");

    f>>n;

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        {
            f>>G[i][j]>>l;
        }
    f.close();
}

void Show()
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            cout<<G[i][j]<<" ";
        cout<<endl;
    }
}

void Search(int st, int n)
{
  int r;
  cout << st + 1 << " ";
  nodes[st] = 1;
  for (r = 0; r < n; r++)
    if ((G[st][r] != 0) && (nodes[r] == 0))
      Search(r, n);
}



bool BinaryTree()
{
    int k=0;

    for(int j=0; j<n; j++)
        if(G[0][j]==1)
            k++;

    if(k<2 or k>2)
        return false;

    return true;
}

int main()
{
    setlocale(LC_ALL,"RUS");

    Reading();
    Show();
    cout<<endl<<endl;
    Search(0,n);
    cout<<endl<<endl;
    if(BinaryTree)
        cout<<"Граф является двоичным деревом";
    else
        cout<<"Граф не является деревом";
}
