#include<iostream>
using namespace std;
class abc {
    public:
    string name;
    int age;

    bool operator == (abc &a) {
        if (name==a.name && age==a.age)
        {
            return true;
        }
        return false;
        
    }

    int divide(int a,int b) {
        return a/b;
    }

    int divide(int a ,int b,int c) {
        return (a/b)*c;
    }

};



int main() {
    abc x;
    x.name="ARYAN";
    x.age=20;
    abc y;
    y.name="CHOUDHARY";
    y.age=19;
    if (x==y)
    {
        cout<<"SAME PERSON";
    }
    else {
        cout<<"DIFFERENT PERSON"<<endl;
    }

    cout<<x.divide(4,2,3)<<endl;



return 0;
}


