vector<string> cavityMap(vector<string> grid)
{
    for (int i = 1; i < grid.size()-1; ++i)
    {
        for (int k = 1; k < grid[i].size()-1; ++k)
        {
            if (grid[i][k] > grid[i - 1][k] &&
                grid[i][k] > grid[i + 1][k] &&
                grid[i][k] > grid[i][k - 1] &&
                grid[i][k] > grid[i][k + 1])
            {
                grid[i][k] = 'X';
            }
        }
    }
    
    return grid;
}
