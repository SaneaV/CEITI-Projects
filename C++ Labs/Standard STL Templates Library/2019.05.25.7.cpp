///Вроде всё, могу ещё что-то показать, если надо.
///Что ещё показать?

#include <iostream>

using std::cout;
using std::endl;
using std::cin;

class Point
{
private:
    int x,y;

public:
    Point()
    {
        ///Я имею конструктор, который принимает параметры, но мне нужно создать пустой объект
        ///Можно создать конструктор по умолчанию.
        x = 0;
        y = 0;
    }

    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    Point operator + (const Point &otherPoint)
    {
        Point temp; ///Создаём временный объект

        temp.x=otherPoint.x + this->x; ///Мы будем создавать новый объект с этими значениями
        temp.y=otherPoint.y + this->y; ///Для этого мы и создаём новый объект

        return temp; ///Возвращаем его
    }

    Point &operator = (const Point &otherPoint)
    {
        ///Мы присваиваем, не создаём новый объект
        ///Point firstPoint
        ///Point secondPoint
        ///secondPoint = firstPoint
        ///Значения из firstPoint в secondPoint

        this->x = otherPoint.x;
        this->y = otherPoint.y;

        return *this;

    }
    ///ВозвращаемыеТип operator ЗНАК (const(если не меняем) &ДругойОбъект)

    void printPoint()
    {
        cout<<x<<"\t"<<y<<endl;
    }


};


int main()
{
    Point firstPoint(10, 8);
    Point secondPoint(1, 1);

    firstPoint.printPoint();
    secondPoint.printPoint();

    cout<<endl;
    cout<<"Temp point"<<endl;

    Point tempPoint;
    tempPoint = firstPoint;
    tempPoint.printPoint();

    cout<<endl;
    cout<<"Second temp point"<<endl;

    Point secondTempPoint;
    secondTempPoint = firstPoint + tempPoint;
    secondTempPoint.printPoint();


    return 0;
}
