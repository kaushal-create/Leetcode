class Solution {
public:
    int dp[1<<13][13];
    vector<int> bfs(int src, int n, vector<vector<int>>& graph){
        queue<int> q;
        vector<int> dist(n, 1e9);
        dist[src] = 0;
        q.push(src);
        while(!q.empty()){
            auto atTop = q.front();
            q.pop();
            for(auto child: graph[atTop]){
                if(dist[child] > 1 + dist[atTop]){
                    dist[child] = 1 + dist[atTop];
                    q.push(child);
                }
            }
        }
        return dist;
    }
    int solve(int node, int n, int mask, vector<int> dist[]){
        if(mask == 0) return 0;
        if(dp[mask][node] != -1) return dp[mask][node];
        int ans = 1e9;
        for(int i = 0; i<n; i++){
            if(((mask>>i)&1) == 1){
                ans = min(ans, dist[node][i] + solve(i, n, mask^(1<<i), dist));
            }
        }
        return dp[mask][node] = ans;
    }
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        memset(dp, -1, sizeof(dp));
        vector<int> dist[n];
        for(int i = 0; i<n; i++){
            dist[i] = bfs(i, n, graph);
        }
        int ans = 1e9;
        for(int i = 0; i<n; i++){
            ans = min(ans, solve(i, n, (1<<n)-1, dist));
        }
        return ans;
    }
};