#include<bits/stdc++.h>
using namespace std;
class person{
    char arr[20];
    int id;
    public:
    string name;
    //declaring function inside the class
    void printName();

    //declaring as well as defining  member function inside the class
    void getDetails()
    {
        cout<<"hell0"<<endl;
    }
};
//we can also declare member function outside of class as :
void person::printName()
{
    cout<<"rahul"<<endl;
}
int main()
{
    person p1;
    p1.getDetails();
    p1.name = "hello";
    cout<<p1.name<<endl;
    p1.printName();
    return 0;
}