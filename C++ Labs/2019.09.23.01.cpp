#include <iostream>
#include <cmath>

using namespace std;

const float g=9.81;

float r, v0,xt = 8, xy = 6;

float f(float x)
{
    return x*sin(r)/cos(r)-pow(x,2)*g/(2*pow(v0,2)*pow(cos(r),2));
}


float DistPT(float x, float y)
{
    return sqrt(pow(x-xt,2)+pow(y-yt,2));
}



float DistZ()
{
    return pow(v0,2)/g*sin(2*r);
}

int main()
{
    float alfa,dz,h,x,y,t,dt;
    cout<<"v0=";
    cin>>v0;
    cout<<"alfa v gradusah=";
    cin>>alfa;
    cout<<"xt=";
    cin>>xt;
    cout<<"yt=";
    cin>>yt;
    r=M_PI*alfa/180;
    dz=DistZ();
    cout<<"dalinosti poliota="<
        x=0;
    t=2*v0*sin(r)/g;
    cout<<"vremea poliota="<
        cout<<"vvedite shag vremeni";
    cin>>dt;
    h=v0*dt*cos(r);

    while (x<=dz)
    {
        y=f(x);
        cout<<x<<
        x+=h;

    }

}
