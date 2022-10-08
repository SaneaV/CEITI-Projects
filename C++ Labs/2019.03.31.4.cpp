#include<iostream>
#include<string>

using namespace std;

class Man
{
private:
    string name;
    int age;
public:
    void setName(string name){this->name=name;}
    void setAge(int age){this->age=age;}
    string getName(){return name;}
    int getAge(){return age;}
    void InputData()
    {
        cout<<"input name:"<<endl;
        cin>>name;
        cout<<"input age:"<<endl;
        cin>>age;
    }
    void showData()
    {
        cout<<name<<" "<<age<<endl;
    }
};

class List
{
private:
    Man *info;
    List *next;
    static List *bg;
public:
    void setInfo(Man *info){this->info = info;}
    void setNext(List *next){this->next = next;}
    Man*  getInfo(){return info;}
    List* getNext(){return next;}
    void addData();
    void showData();
};
  List *List::bg=NULL;



void List::addData()
{
   List *cr =new List;
   List *prv;
   Man *info = new Man;
   info->InputData();
   cr->setInfo(info);
   cr->setNext(NULL);
   if (bg==NULL) bg=cr;
      else prv->setNext(cr);
   prv=cr;
}

void List:: showData()
{
    if (bg==NULL)cout<<"empty";
    else
    {
        List *cr;
        cr=bg;
        while(cr!=NULL)
        {
            cr->getInfo()->showData();
            cr=cr->getNext();
        }
    }
}
int main()
{
    int n;
    cout<<"n=";
    cin>>n;
    List lst;
    for(int i=0;i<n;i++)
        lst.addData();

    lst.showData();

}
