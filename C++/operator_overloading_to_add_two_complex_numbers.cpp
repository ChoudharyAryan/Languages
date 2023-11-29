#include <iostream>
using namespace std;

class complex
{
    int real, img;

public:
    complex(int r = 0, int i = 0)
    {
        real = r;
        img = i;
    }

    complex operator+ (complex  obj) {
        complex res;
        res.real = real + obj.real;
        res.img = img+obj.img;
        cout<<real<<" "<<obj.real<<endl;
        cout<<img<<" "<<obj.img<<endl;
        return res;
    }

    void print() {
        cout<<real<<" i"<<img<<endl;
    }
};

int main()
{
    complex c1(2,4),c2(3,6);
    complex c3=c1+c2;
    c3.print();
    
    return 0;
}
