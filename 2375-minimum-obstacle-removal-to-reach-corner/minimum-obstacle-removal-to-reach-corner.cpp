class Solution {
public:
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> ans(n, vector<int>(m, INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>> > pq;
        pq.push({0, 0, 0});
        ans[0][0] = 0;
        while(!pq.empty()){
            auto temp = pq.top();
            pq.pop();
            if(temp[1] == n-1 && temp[2] == m-1) return temp[0];
            if(ans[temp[1]][temp[2]] < temp[0]) continue;
            for(int i = 0; i<4; i++){
                int x = temp[1] + dx[i], y = temp[2] + dy[i];
                if(x >= 0 && x < n && y >= 0 && y < m){
                    if(grid[x][y] == 1 && ans[x][y] > temp[0]+1){
                        ans[x][y] = temp[0]+1;
                        pq.push({ans[x][y], x, y});
                    }
                    else if(grid[x][y] == 0 && ans[x][y] > temp[0]){
                        ans[x][y] = temp[0];
                        pq.push({ans[x][y], x, y});
                    }
                }
            }
        }
        // return ans[n-1][m-1] == INT_MAX ? -1 : ans[n-1][m-1];
        return -1;
    }
};