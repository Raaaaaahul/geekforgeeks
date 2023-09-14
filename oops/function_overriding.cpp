#include<bits/stdc++.h>
using namespace std;
//function overriding occurs when a derived class has a defination for one of the member function already in the base class
//the base class function is said to be overridden
class Parent{
    public:
        void geeks()
        {
            cout<<"parent"<<endl;
        }
};
class Child: public Parent{
    public:
        void geeks()
        {
            cout<<"child - overridden same function"<<endl;
        }

};
int main()
{
    Parent obj1;
    obj1.geeks();
    Child s;
    s.geeks();
    s.Parent::geeks();
    return 0;
}