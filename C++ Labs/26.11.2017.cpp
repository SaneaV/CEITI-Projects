//���� �������
//���������� ������ �� ������������ ��������� �������
//����� ������������ ��������� �������

#include <iostream>

using namespace std;

main()
{
    setlocale (LC_ALL,"Russian");
    cout<<"������� ���������� �����: ";
    int n,m,mat[20][20];
    cin>>n;
    cout<<"������� ���������� ��������: ";
    cin>>m;

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            cout<<"������� ����� ������� ��� "<<i<<" ������� "<<j<<" �������: ";
            cin>>mat[i][j];
        }
    }

    int sc=0;
    int x[20];
    for (int i=0; i<n; i++)
    {
        int max=mat[i][0];
        sc++;//������� ���������� �����
        for (int j=0; j<n; j++)
        {
            if (max<=mat[i][j])//��������� �� ����������� ����� � ������ �������
            {
                max=mat[i][j];//����������� min ����������� �������� ������ �������
                x[i]=mat[i][j];//��������� � ���������� ������ ����������� �������� ������ �������

            }
        }
    }

    int S=0;
    for (int i=0; i<n; i++)
    {
        S+=x[i];
    }

    cout<<"����� ������������ ��������� ��� ������ ������ �������: "<<S;
}
