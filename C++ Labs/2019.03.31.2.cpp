#include<iostream>
#include<string>

using namespace std;

class Man
{
private:
    string name;
    int age;
public:
    void setName(string name)
    {
        this->name=name;
    }
    void setAge(int age)
    {
        this->age=age;
    }
    string getName()
    {
        return name;
    }
    int getAge()
    {
        return age;
    }
    virtual void InputData()
    {
        cout<<"input name:"<<endl;
        cin>>name;
        cout<<"input age:"<<endl;
        cin>>age;
    }
    virtual void showData()
    {
        cout<<name<<" "<<age<<" ";
    }
};


template <typename T>
class Node
{
private:
    T *info;
    Node *next;

public:
    void setInfo(T *info)
    {
        this->info = info;
    }
    void setNext(Node *next)
    {
        this->next = next;
    }
    T*  getInfo()
    {
        return info;
    }
    Node* getNext()
    {
        return next;
    }

};

template <typename T>
class List
{
private:
    Node<T> *bg;
public:
    List()
    {
        bg=NULL;
    }
    Node<T>* getBegin()
    {
        return bg;
    }

    void addData()
    {


        Node<T> *cr =new Node<T>;
        Node<T> *prv;

        Man *info= new Man;

        info->InputData();
        cr->setInfo(info);
        cr->setNext(NULL);
        if (bg==NULL) bg=cr;
        else prv->setNext(cr);
        prv=cr;

    }

    void  showData()
    {
        if (bg==NULL)cout<<"empty";
        else
        {
            Node<T> *cr;
            cr=bg;
            while(cr!=NULL)
            {
                cr->getInfo()->showData();
                cr=cr->getNext();
            }
        }
    }

};
int main()
{
    int ch;
    List<Man> lst;
    do
    {
        cout<<"1 - Create"<<endl<<endl;
        cout<<"2 - Show"<<endl<<endl;

        cout<<"0 - Exit"<<endl<<endl;
        cout<<"Your choice: ";
        cin>>ch;
        switch(ch)
        {
        case 1:
        {
            if (lst.getBegin()!=NULL) cout<<"List already exist!!!"<<endl;
            else
            {
                int n;
                cout<<"n=";
                cin>>n;

                for(int i=0; i<n; i++)
                    lst.addData();
            }
            break;
        }
        case 2:
        {
            lst.showData();
            break;
        }
        }
    }
    while(ch!=0);
}

