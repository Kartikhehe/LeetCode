class Solution {
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y){
    visited[x][y] = true;
    for(int i = 0; i<4; i++){
        int newx = x + dx[i];
        int newy = y + dy[i];
        if(newx<0 || newy<0 || newx >= grid.size() || newy >= grid[0].size()){
            continue;
        }if(!visited[newx][newy] && grid[newx][newy] == '1'){
            dfs(grid, visited, newx, newy);
        }
    }return;
}


public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int islands = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i = 0; i< m; i++){
            for(int j = 0; j<n; j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    dfs(grid, visited, i, j);
                    islands++;
                }
            }
        }return islands;
    }
};