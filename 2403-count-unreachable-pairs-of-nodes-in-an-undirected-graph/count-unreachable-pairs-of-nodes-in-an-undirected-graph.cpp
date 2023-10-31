class Solution {
public:
    void dfs(int node, vector<int> adj[], vector<bool>& visited, int &count){
        if(visited[node]) return;
        visited[node] = 1;
        count++;
        for(auto child: adj[node]){
            dfs(child, adj, visited, count);
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(auto x: edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vector<bool> visited(n, false);
        vector<int> temp;
        for(int i = 0; i<n; i++){
            int count = 0;
            if(!visited[i]){
                dfs(i, adj, visited, count);
                // cout<<count<<endl;
                temp.push_back(count);
            }
        }
        long long ans = 0;
        vector<int> sufix(temp.size(), 0);
        for(int i = temp.size()-1; i>=0; i--){
            if(i == temp.size()-1) sufix[i] = temp[i];
            else sufix[i] = sufix[i+1] + temp[i];
        }
        for(int i = 0; i<temp.size()-1; i++){
           ans += temp[i]*1LL*sufix[i+1];
        }
        return ans;
    }
};