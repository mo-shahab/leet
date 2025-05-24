#include <bits/stdc++.h>
using namespace std;


// direction vectors
vector<int> dRow = {0, 1, 0, -1};
vector<int> dCol = {-1, 0, 1, 0};

bool isValid(vector<vector<bool>>& vis, int row, int col, int ROW, int COL)
{
    if (row < 0 || col < 0 || row >= ROW || col >= COL) return false;

    if (vis[row][col]) return false;

    return true;
}

void dfs(
    int row, int col,
    vector<vector<int>>& grid,
    vector<vector<bool>>& vis,
    int ROW, int COL)
{
    if (!isValid(vis, row, col, ROW, COL)) return;

    vis[row][col] = true;
    cout << grid[row][col] << " ";

    for (int i = 0; i < 4; i++) {
        int newRow = row + dRow[i];
        int newCol = col + dCol[i];
        dfs(newRow, newCol, grid, vis, ROW, COL);
    }
}

int main()
{
    vector<vector<int>> grid = {
        { -1, 2, 3 },
        { 0, 9, 8 },
        { 1, 0, 1 }
    };

    int ROW = grid.size();
    int COL = grid[0].size();

    vector<vector<bool>> vis(ROW, vector<bool>(COL, false));

    dfs(0, 0, grid, vis, ROW, COL);

    return 0;
}


