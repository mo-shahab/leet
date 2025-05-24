#include <bits/stdc++.h>
#include <vector>

#define ROW 3
#define COL 3

using namespace std;

int dRow[] = {0, 1, 0, -1};
int dCol[] = {-1, 0, 1, 0};

bool isValid(vector<vector<bool>>& vis, int row, int col)
{
    if(row < 0 || col < 0 || row >= ROW || col >= COL) return false;

    if(vis[row][col]) return false;

    return true;
}

void dfs(vector<vector<int>>& matrix, vector<vector<bool>>& vis, int row, int col, int n, int m)
{
    stack<pair<int, int>> st;
    st.push({row, col});
    
    while(!st.empty())
    {
        pair<int, int> curr = st.top();
        st.pop();

        int row = curr.first;
        int col = curr.second;

        if(!isValid(vis, row, col)) continue;

        vis[row][col] = true;

        cout << matrix[row][col] << " ";

        for(int i = 0; i < 4; i++)
        {
            int adjx = row + dRow[i];
            int adjy = col + dCol[i];
            st.push({adjx, adjy});
        }
    }
}

int main()
{
    vector<vector<int>> matrix = {
        {-1, 2, 3},
        {0, 9, 8},
        {1, 0, 1}
    };

    vector<vector<bool>> visited(matrix.size(), vector<bool>(matrix[0].size(), false));

    dfs(matrix, visited, 0, 0, matrix.size(), matrix[0].size());

    return 0;
}
