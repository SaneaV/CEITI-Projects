#include <iostream>

using std::cout;
using std::endl;
using std::string;
using std::to_string;
using std::begin;

class Pixel
    {
    private:
        int red, green, blue;
    public:

        Pixel()
        {
            red = green = blue = 0;
        }

        Pixel(int red, int green, int blue)
        {
            this->red = red;
            this->green = green;
            this->blue = blue;
        }

        string GetInfo()
        {
            return "Pixels: r = "+to_string(red)+"\t green = "+to_string(green)+"\t blue = "+to_string(blue)+"\n";
        }

        ~Pixel() {};
    };

int main()
{
    const int LENGHT = 5;

    Pixel pixels[LENGHT];

    cout<<pixels[0].GetInfo();
    pixels[0] = Pixel(1,2,3);
    cout<<pixels[0].GetInfo();


    Pixel *pixelsDinamic = new Pixel[LENGHT]
    {
        Pixel(10,4,5),
        Pixel(0,3,5),
        Pixel(11,5,5),
        Pixel(5,8,7),
        Pixel(1,4,2)
    };

    cout<<endl;

    for(int i=0;i<LENGHT;i++)
    {
        cout<<pixelsDinamic[i].GetInfo();
    }

    delete [] pixelsDinamic;

    return 0;
}

