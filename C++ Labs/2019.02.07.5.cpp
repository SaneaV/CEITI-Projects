#include <iostream>
#define SIZE 10

using namespace std;
class matrix
   {
      int n;
      int m;
      int a[SIZE][SIZE];
  public:
    matrix(){} //  онструктор по умолчанию без параметров
    ~matrix(){}
    void init(int);
    void input();
    void show();
   };


    void matrix :: init(int val)
    {
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                a[i][j]=val;

    }
    void matrix :: input()
    {
        cout<<"n=";
        cin>>n;
        cout<<"m=";
        cin>>m;
        cout<<"input "<<n*m<<" elements"<<endl;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                cin>>a[i][j];
    }
     void matrix :: show()
    {
        cout<<"elements: "<<endl;
        for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                cout<<a[i][j]<<" ";
                cout<<endl;
            }
    }

int main()
{

   matrix v;
   v.input();
   v.show();

    return 0;
}
