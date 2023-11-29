#include <iostream>
#include <vector>
#include<numeric>
using namespace std;

int main()
{
    int row = 3;
    int column[] = {3, 2, 1};
    vector<vector<int>> grid(row);
    for (int i = 0; i < row; i++)
    {

        grid[i] = vector<int>(column[i]);
        for (int j = 0; j < column[i]; j++)
        {
            cin>>grid[i][j];
        }
        
    }


    for (auto v : grid)
    {
        for (auto v1 : v)
        {
            cout << v1 << " ";
        }
        cout << endl;
    }

    int sum = accumulate(grid[0].begin(),grid[0].end(),0);
    cout<<sum<<endl;

    return 0;
}
