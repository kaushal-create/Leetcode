class Solution {
public:
    bool ans = false;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    void dfs(char ch, int i, int j, int pri, int prj, int m, int n, vector<vector<char>>& grid, vector<vector<bool>>& visited){
        if(i >= m || i < 0 || j>=n || j<0 || grid[i][j] != ch) return;
        if(visited[i][j]){
            ans = true;
            return;
        }
        visited[i][j] = true;
        for(int k = 0; k<4; k++){
            if(i+dx[k] != pri || j+dy[k] != prj) dfs(ch, i+dx[k], j + dy[k], i, j, m, n, grid, visited);
        }
    }
    bool containsCycle(vector<vector<char>>& grid) {
       int m = grid.size(), n = grid[0].size(); 
       vector<vector<bool>> visited(m, vector<bool>(n, false));
       for(int i = 0; i<m; i++){
           for(int j = 0; j<n; j++){
               if(!visited[i][j]) dfs(grid[i][j], i, j, -1, -1, m, n, grid, visited);
           }
       } 
       return ans;
    }
};