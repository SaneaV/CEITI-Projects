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

class Node
{
private:
    Man *info;
    Node *next;
public:
    void setInfo(Man *info){this->info = info;}
    void setNext(Node *next){this->next = next;}
    Man*  getInfo(){return info;}
    Node* getNext(){return next;}

};

class List
{
    private:
       Node *bg;
    public:
        List(){bg=NULL;}
        void addData();
        void showData();
};

void List::addData()
{
   Node *cr =new Node;
   Node *prv;
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
        Node *cr;
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
