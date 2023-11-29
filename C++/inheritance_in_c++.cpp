#include <iostream>
using namespace std;

class A
{
    private:
    int acc;
    protected:
    int backroom;

protected:
    int helloc;

public:
int fcc;
    void fn()
    {
        cout << "being inherited from A";
        
    }
};

class B : public A
{
private:
    void shell(){};

public:
    void bfn()
    {
        cout << "inheriting from B";
        cout<<fcc;
        
    };
};

class C : public B
{

    void cc() {
        
    }
};

int main()
{
    B b;
    C c;

    return 0;
}
