#include<bits/stdc++.h>
using namespace std;
class geeks{
    public:
        void func(int x)
        {
            cout<<"the value is  "<<x<<endl;
        }
        void func(double x)
        {
            cout<<"the value is  "<<x<<endl;
        }
        void func(int x,int y)
        {
            cout<<"the value is "<<x<<" and "<<y<<endl;
        }
};
int main()
{
    geeks obj;
    obj.func(12);
    obj.func(12.9);
    obj.func(12,21);
    return 0;
}