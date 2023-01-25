#include <stdio.h>  // �������� ������� �����-������
#include <math.h>   // �������� �������������� �������
#include <stdlib.h> // �������� ������� malloc � free
#include <locale.h>
#include <iostream>

using namespace std;

// �������� ������� ���������� �������
// � ������������ ����.
// ������� ���������� ���� �������
int gaussMethod(
    int m,          // ����� ����� �������
    int n,          // ����� �������� �������
    double *a,      // ����� ������� ��������� �������
    double eps      // �������� ����������
);

int main() {
    int m, n, i, j, rank;
    double *a;
    double eps, det;

    setlocale(LC_ALL, "Russian");

    cout<<"������� ������� ������� n: ";
    cin>>n;
    cout<<"������� ������� ������� m: ";
    cin>>m;

    // ����������� ������ ��� �������� �������
    a = (double *) malloc(m * n * sizeof(double));

    cout<<"������� �������� �������:\n";
    for (i = 0; i < m; ++i) {
        for (j = 0; j < n; ++j) {
            // ������ ������� � ��������� i, j
            cout<<"Matrix["<<i<<"]["<<j<<"]: ";
            cin>>a[i*n + j];
        }
    }

    cout<<"������� �������� ���������� eps: ";
    cin>>eps;

    // �������� ����� ������
    rank = gaussMethod(m, n, a, eps);

    // �������� ����������� �������
    cout<<"����������� ��� �������:\n";
    for (i = 0; i < m; ++i) {
        // �������� i-� ������ �������
        for (j = 0; j < n; ++j) {
            printf(         // ������ %10.3lf �������� 10
                "%10.3lf ", // ������� �� ������ �����,
                a[i*n + j]  // 3 ����� ����� �����
            );
        }
        cout<<"\n";   // ��������� ������
    }

    // �������� ���� �������
    printf("���� ������� = %d\n", rank);

    if (m == n) {
        // ��� ���������� ������� ��������� � ��������
        //     �� ������������
        det = 1.0;
        for (i = 0; i < m; ++i) {
            det *= a[i*n + i];
        }
       printf("������������ ������� = %.3lf\n", det);
    }

    free(a);    // ����������� ������
    return 0;   // �������� ���������� ���������
}

// ���������� ������������ �������
// � ������������ ���� ������� ������ � �������
// ������������� ������������ �������� � �������.
// ������� ���������� ���� �������
int gaussMethod(
    int m,          // ����� ����� �������
    int n,          // ����� �������� �������
    double *a,      // ����� ������� ��������� �������
    double eps      // �������� ����������
) {
    int i, j, k, l;
    double r;

    i = 0; j = 0;
    while (i < m && j < n) {
        // ���������: ����� ������� � �������� 0..j-1
        //   ��� �������� � ������������ ����, � ������
        //   � �������� i-1 �������� ��������� ��-�
        //   � ������� � �������, ������� ��� j

        // ���� ������������ ������� � j-� �������,
        // ������� � i-� ������
        r = 0.0;
        for (k = i; k < m; ++k) {
            if (fabs(a[k*n + j]) > r) {
                l = k;      // �������� ����� ������
                r = fabs(a[k*n + j]); // � ����. ��-�
            }
        }
        if (r <= eps) {
            // ��� �������� j-�� ������� �� ����������
            // �������� �� ����������� eps.
            // ������� �������, ������� � i-� ������
            for (k = i; k < m; ++k) {
                a[k*n + j] = 0.0;
            }
            ++j;      // �������� ������ �������
            continue; // ��������� � ��������� ��������
        }

        if (l != i) {
            // ������ ������� i-� � l-� ������
            for (k = j; k < n; ++k) {
                r = a[i*n + k];
                a[i*n + k] = a[l*n + k];
                a[l*n + k] = (-r); // ������ ���� ������
            }
        }

        // �����������: fabs(a[i*n + k]) > eps

        // �������� j-� �������, ������� �� ������ i+1,
        // �������� ����. �������������� ������� ����
        for (k = i+1; k < m; ++k) {
            r = (-a[k*n + j] / a[i*n + j]);

            // � k-� ������ ���������� i-�, ���������� �� r
            a[k*n + j] = 0.0;
            for (l = j+1; l < n; ++l) {
                a[k*n + l] += r * a[i*n + l];
            }
        }

        ++i; ++j;   // ��������� � ���������� ������
    }

    return i; // ���������� ����� ��������� �����
}
