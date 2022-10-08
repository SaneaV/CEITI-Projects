#include <iostream>
#include <windows.h>
#include <conio.h>
#include <cmath>

using namespace std;

class Figures
{
public:
    string Name;
    Figures(string Name)
    {
        this->Name=Name;
    }
};

class Circle : public Figures
{
private:
    int r;
public:
    void Input()
    {
        cout<<"Введите радиус: ";
        cin>>r;
    }
    float Aria()
    {
        return 3.14 * r *r;
    }
    float Perimetr()
    {
        return 3.14 * 2 *r;
    }
    void Show()
    {
        cout<<"Название фигуры: "<<Name<<endl;
        cout<<"Радиус окружности: "<<r<<endl;
        cout<<"Площадь окружности: "<<Aria()<<endl;
        cout<<"Периметр окружности: "<<Perimetr()<<endl;
    }

    Circle() : Figures("Okrujnosti")
    {
        this->r=r;
    }
};

class Triangle : public Figures
{
private:
    int a,b,c;
public:
    void Input()
    {
        cout<<"Введите три стороны: ";
        cin>>a>>b>>c;
    }
    float Aria()
    {
        float p = (a+b+c)/2.0;

        return sqrt(p*(p-a)*(p-b)*(p-c));
    }
    float Perimetr()
    {
        return a+b+c;
    }
    void Show()
    {
        cout<<"Название фигуры: "<<Name<<endl;
        cout<<"Стороны треугольника: "<<a<<" "<<b<<" "<<c<<endl;
        cout<<"Площадь треугольника: "<<Aria()<<endl;
        cout<<"Периметр треугольника: "<<Perimetr()<<endl;
    }

    Triangle () : Figures("Triangle")
    {
        this->a=a;
        this->b=b;
        this->c=c;
    }

};

class Parallelogram : public Figures
{
private:
    int a,b, alpha;
public:
    void Input()
    {
        cout<<"Введите три стороны и угол: ";
        cin>>a>>b>>alpha;
    }
    float Aria()
    {
        return a*b*sin(alpha);
    }
    float Perimetr()
    {
        return 2*(a+b);
    }
    void Show()
    {
        cout<<"Название фигуры: "<<Name<<endl;
        cout<<"Стороны параллелограмма: "<<a<<" "<<b<<" "<<alpha<<endl;
        cout<<"Площадь параллелограмма: "<<Aria()<<endl;
        cout<<"Периметр параллелограмма: "<<Perimetr()<<endl;
    }

    Parallelogram () : Figures("Paralellogram")
    {
        this->a=a;
        this->b=b;
        this->alpha=alpha;
    }

};

class Priamougolnik : public Figures
{
private:
    int a,b;
public:
    void Input()
    {
        cout<<"Введите радиус: ";
        cin>>r;
    }
    float Aria()
    {
        return 3.14 * r *r;
    }
    float Perimetr()
    {
        return 3.14 * 2 *r;
    }
    void Show()
    {
        cout<<"Название фигуры: "<<Name<<endl;
        cout<<"Стороны прямоугольника: "<<a<<" "<<b<<"90"<<endl;
        cout<<"Площадь прямоугольника: "<<Aria()<<endl;
        cout<<"Периметр прямоугольника: "<<Perimetr()<<endl;
    }

    Priamougolnik() : Figures("Priamougolnik")
    {
        this->r=r;
    }
};


int main()
{
    setlocale(LC_ALL,"RUS");

    while(true)
    {
        cout<<"1. Действия над окружностью."<<endl;
        cout<<"2. Действия над треугольниклм."<<endl;
        cout<<"3. Действия над параллелограмом."<<endl;
        cout<<"4. Действия над ромбом."<<endl;
        cout<<"5. Действия над прямоугольником."<<endl;
        cout<<"6. Действия над квадратом."<<endl;
        cout<<"Ваш выбор: ";

        if(_kbhit)
        {
            switch(getch())
            {
            case '1':
            {
                system("cls");
                Circle O;

                O.Input();
                O.Show();
                cout<<endl<<endl;


                break;
            }
            case '2':
            {
                system("cls");
                Triangle T;
                T.Input();
                T.Show();

                cout<<endl<<endl;
                break;
            }
            case '3':
            {
                system("cls");
                Parallelogram P;
                P.Input();
                P.Show();

                cout<<endl<<endl;
                break;
            }
            }
        }
    }


}
