#include <iostream>

using std::cout;
using std::endl;
using std::string;
using std::to_string;

class Image
{
public:

    void GetImageInfo()
    {
        int k=0;
        for(auto i:pixels)
        {
            cout<<"The Number of pixel - "<<k++<<"\t: "<<i.GetInfo();
        }
    }

private:

    class Pixel
    {
    private:
        int red, green, blue;
    public:
        Pixel(int red, int green, int blue)
        {
            this->red = red;
            this->green = green;
            this->blue = blue;
        }

        string GetInfo()
        {
            return "\tr = "+to_string(red)+"\t green = "+to_string(green)+"\t blue = "+to_string(blue)+"\n";
        }

        ~Pixel() {};
    };

    Pixel pixels[5]
    {
        Pixel(10,4,5),
        Pixel(0,3,5),
        Pixel(11,5,5),
        Pixel(5,8,7),
        Pixel(1,4,2)
    };
};

int main()
{
    Image img;
    img.GetImageInfo();

    return 0;
}
