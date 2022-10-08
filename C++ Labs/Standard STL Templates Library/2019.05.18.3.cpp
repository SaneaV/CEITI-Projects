#include <iostream>

class Cap
{
public:
    std::string getColor()
    {
        return color;
    }
private:
    std::string color = "red";
};

class Model
{
public:
    void inspectModel()
    {
        std::cout<<"The model has a beautiful "<<cap.getColor()<<" cap!"<<std::endl;
    }

private:
    Cap cap;
};

class Human
{
public:
    void Think()
    {
        myBrain.Think();
    }

    void InspectTheCap()
    {
        std::cout<<"I inspect my "<<cap.getColor()<<" cap!"<<std::endl;
    }

private:
    class Brain
    {
    public:
        void Think()
        {
            std::cout<<"I think!"<<std::endl;
        }
    };

    Brain myBrain;
    Cap cap;

};



int main()
{

    Human human;
    Model model;

    human.Think();
    human.InspectTheCap();
    model.inspectModel();
    return 0;
}
