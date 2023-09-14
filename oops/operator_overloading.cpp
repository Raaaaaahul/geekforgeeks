#include<bits/stdc++.h>
using namespace std;
//in cpp we can provide operators a specific meaning for a specific data type
//for example we can use + to add to numbers of data type int,float,double etc but we can also use it to concat strings 

class Complex{
    private:
        int real,imag;
    public:
        Complex(int r=0,int i=0)
        {
            real = r;
            imag = i;

        }
        Complex operator+(Complex const& obj)
        {
            Complex res;
            res.real = real + obj.real;
            res.imag = imag + obj.imag;
            return res;
        }
        void print()
        {
            cout<<real<<" + "<<imag<<"i"<<endl;
        }
};
int main()
{
    Complex c1(10,5),c2(2,5);
    Complex c3 = c1+c2;
    c3.print();
    return 0;
}