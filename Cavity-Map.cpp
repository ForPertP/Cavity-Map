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

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<string> grid(n);

    for (int i = 0; i < n; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    vector<string> result = cavityMap(grid);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
