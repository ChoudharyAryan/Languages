#include <iostream>
using namespace std;
class employe
{
private:
    int salary;

public:
    void setsalary(int s)
    {
        salary = s;
    }

    int getsalary()
    {
        return salary;
    }
};

int main()
{
    employe a;
    a.setsalary(1000000);
    cout << a.getsalary();
    return 0;
}
