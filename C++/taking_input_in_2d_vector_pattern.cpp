#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int row = 8;
    int column[] = {8, 7, 6, 5, 4, 3, 2, 1};
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

    return 0;
}
