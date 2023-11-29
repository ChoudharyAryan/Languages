#include <iostream>
using namespace std;
class Student
{
private:
    string name;

public:
    int age;
    bool gender;

    Student()
    {
        cout << "DEFAULT CONSTRUCTOR" << endl; // DEAFULT CONSTRUCTOR
    }

    Student(string s, int a, bool g) // PARAMETERISED CONSTRUCTOR
    {
        cout << "PARAMETERISED CONSTRUCTOR" << endl;
        name = s;
        age = a;
        gender = g;
    }

    Student(Student &a)
    { // COPY CONSTRUCTOR
        cout << "COPY CONSTRUCT" << endl;
        name = a.name;  
        age = a.age;
        gender = a.gender;
    }

    bool operator==(Student &a)
    {
        if (name == a.name && age == a.age && gender == a.gender)
        {
            return true;
        }
    }   

    ~Student()
    {
        cout << "DESTRUCTR's HERE BABY" << endl;
    }

    void changename(string s)
    {
        name = s;
    }
    void printinfo()
    {
        cout << name << endl;
        cout << age << endl;
        cout << gender << endl;
    }
};

int main()
{

    Student a("ARYAN", 20, 0);
    Student b;
    Student c(a);

    if (c == a)
    {
        cout << "THE SAME" << endl;
    }
    else
    {
        cout << "NOT THE SAME";
    }

    return 0;
}
