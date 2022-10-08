#include <iostream>
#define SIZE 10

using namespace std;
class matrix
   {
      int n;
      int m;
      int a[SIZE][SIZE];
  public:
    matrix(int,int,int); //  онструктор по умолчанию без параметров
    ~matrix(){}
    void init(int);
    void input();
    void show();
   };

matrix::matrix(int n1=2, int m1=2, int val=0)
{
           n=n1;
           m=m1;
            for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                a[i][j]=val;

}
    void matrix :: init(int val)
    {


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

   matrix v(7,8,4);

   v.show();

   matrix v1;

   v1.show();

    return 0;
}
