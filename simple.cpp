#include<iostream>
using namespace std;
class classB;
class classA
{
    private:
    int data1;
    public:
    classA(int value1):data1(value1){}
    friend void swap(classA&, classB&);
    void getdata()
    {
        cout<<data1<<endl;
    }
};
class classB
{
    private:
    int data2;
    public:
    classB(int value2):data2(value2){}
    friend void swap(classA&, classB&);
    void getdata()
    {
        cout<<data2<<endl;
    }
};
void swap(classA& obj1, classB& obj2)
{
    int temp=obj1.data1;
    obj1.data1=obj2.data2;
    obj2.data2=temp;
}
int main()
{
    classA obj1(10);
    classB obj2(20);
    cout<<"Before swapping"<<endl;
    obj1.getdata();
    obj2.getdata();

    swap(obj1,obj2);
    cout<<"After swapping"<<endl;
    obj1.getdata();
    obj2.getdata();

    return 0;
}

