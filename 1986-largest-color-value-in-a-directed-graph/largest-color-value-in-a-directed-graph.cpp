class Solution {
public:
    int ans = 0;
    void dfs(int node, string& c, vector<int> adj[], vector<vector<int>>& dp, vector<int>& visited, bool& isCycle){
        if(visited[node] == 2){
            isCycle = true;
            return;
        }
        if(!visited[node]){
            visited[node] = 2;
            for(auto child: adj[node]){
                dfs(child, c, adj, dp, visited, isCycle);
                for(int i = 0; i<26; i++){
                    dp[node][i] = max(dp[node][i], dp[child][i]);
                }
            }
            visited[node] = 1;
            dp[node][c[node]-'a']++;
            ans = max(ans, dp[node][c[node]-'a']);
        }
    }
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<int> adj[n];
        for(auto x: edges){
            adj[x[0]].push_back(x[1]);
        }
        vector<vector<int>> dp(n, vector<int>(26, 0));      
        vector<int> visited(n);
        bool isCycle = false;
        for(int i = 0; i<n; i++){
            if(!visited[i]){
                dfs(i, colors, adj, dp, visited, isCycle);
            }
        }
        if(isCycle) return -1;
        return ans;
    }
};