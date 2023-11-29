#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool sortion(int n,int m);


int main() {
vector<int> v;
for (int i = 0; i < 10; i++)
{
    v.push_back(10-i);
}
for (int i = 0; i < 10; i++)
{
    cout<<v[i]<<endl;
}

sort(v.begin(),v.end(),sortion);
for (int i = 0; i < 10; i++)
{
    cout<<v[i]<<endl;
}


return 0;
}

bool sortion(int n,int m) {
    return (n<m);
}


