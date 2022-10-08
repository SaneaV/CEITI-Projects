#include <iostream>

using namespace std;

void Swap(int *p, int *q)
{
    int c = *p;

    *p = *q;
    *q = c;
}

int main()
{
    int n1,n2;
    int *px1 = &n1;
    int *px2 = &n2;

    cout<<"Input number (n1): ";
    cin>>n1;

    cout<<"Input number (n2): ";
    cin>>n2;

    Swap(&n1, &n2);

    cout<<endl<<endl;
    cout<<"n1 = "<<*px1<<endl;
    cout<<"n2 = "<<*px2<<endl;

    return 0;
}
