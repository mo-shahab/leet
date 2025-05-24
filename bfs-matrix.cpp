#include <bits/stdc++.h>
#include <vector>

#define ROW 4;
#define COL 4;

using namespace std;

bool isValid(vector<vector<bool>>& visited, int row, int col)
{
    if(row < 0 || col < 0 || row >= ROW || col >= COL) return false;

    if(visited[row][col]) return false;

    return true;
}

void bfs(vector<vector<int>>& matrix, vector<vector<bool>>& vis, int row, int col, int n , int m)
{
    queue<pair<int, int>> q;
    q.push({row, col});
    vis[row][col] = true;

    while(!q.empty())
    {
        pair<int, int> curr = q.front();
        int row = curr.first;
        int col = curr.second;

        cout << matrix[row][col] << " ";

        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int adjx = row + dRow[i];
            int adjy = col + dCol[i];

            if(isValid(vis, adjx, adjy))
            {
                q.push({adjx, adjy});
                vis[adjx][adjy] = true;
            }
        }
    }
}

int main()
{

    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    vector<vector<bool>> visited(matrix.size(), vector<bool>(matrix[0].size(), false));
    return 0;
}
