#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'cavityMap' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts STRING_ARRAY grid as parameter.
 */

vector<string> cavityMap(vector<string> grid)
{
    for (int i = 1; i < grid.size()-1; ++i)
    {
        for (int k = 1; k < grid[i].size()-1; ++k)
        {
            if (grid[i][k] > grid[i-1][k] &&
                grid[i][k] > grid[i+1][k] &&
                grid[i][k] > grid[i][k-1] &&
                grid[i][k] > grid[i][k+1])
            {
                grid[i][k] = 'X';
            }
        }
    }
    
    return grid;
}
