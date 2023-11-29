#include <iostream>
using namespace std;
class Student
{
public:
    string name;
    int age;
    bool gender;

    void printinfo()
    {
        cout << name << endl;
        cout << age << endl;
        cout << gender << endl;
    }
};

int main()
{
    Student arr[2];
    for (int i = 0; i < 2; i++)
    {
        cin >> arr[i].age >> arr[i].name >> arr[i].gender;
    }
    for (int i = 0; i < 2; i++)
    {
        arr[i].printinfo();
    }

    return 0;
}
