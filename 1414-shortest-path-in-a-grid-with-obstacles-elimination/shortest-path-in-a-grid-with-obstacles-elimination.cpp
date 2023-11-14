class Solution {
public:
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>visited(n, vector<int>(m, -1));
        queue<vector<int>> q;
        q.push({0,0,0,k});
        while(!q.empty()){
            vector<int> temp = q.front();
            q.pop();
            if(temp[0] == n-1 && temp[1] == m-1) return temp[2];
            if(grid[temp[0]][temp[1]]){
                if(temp[3] > 0) temp[3]--;
                else continue;
            }
            if(visited[temp[0]][temp[1]]!= -1 && visited[temp[0]][temp[1]] >= temp[3]) continue;
            visited[temp[0]][temp[1]] = temp[3];
            for(int i = 0; i<4; i++){
                int x = temp[0] + dx[i], y = temp[1] + dy[i];
                if(x >= 0 && x < n && y >= 0 && y < m){
                    q.push({x, y, temp[2]+1, visited[temp[0]][temp[1]]});
                }
            }
        }
        return -1;
    }
};