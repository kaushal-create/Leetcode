class Solution {
public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        vector<vector<int>> dp(n, vector<int>(n, 1e8));
        for(auto x: edges){
            dp[x[0]-1][x[1]-1] = 1;
            dp[x[1]-1][x[0]-1] = 1;
        }
        vector<int> ans(n-1);
        for(int k = 0; k<n; k++){
            for(int i = 0; i<n; i++){
                for(int j = 0; j<n; j++){
                    dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]);
                }
            }
        }
        for(int i = 0; i<(1<<n); i++){
            int node = 0, edge = 0, dist = 0;
            for(int j = 0; j<n; j++){
                if(((i>>j)&1) == 1){
                    for(int k = j+1; k<n; k++){
                        if(((i>>k)&1) == 1 && k != j){
                            edge += dp[j][k] == 1;
                            dist = max(dist, dp[j][k]);   
                        }
                    }
                    node++;
                }
            }
            // cout<<node<<" "<<edge<<endl;
            if(node-1 == edge && dist > 0) ans[dist-1]++;
        }
        return ans;
    }
};