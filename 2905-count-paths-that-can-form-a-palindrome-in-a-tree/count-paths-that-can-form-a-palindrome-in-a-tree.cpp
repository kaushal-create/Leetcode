class Solution {
public:
    map<int,int> mp;
    void dfs(int node, int mask, vector<int> adj[], string& str){
        mp[mask]++;
        for(auto child: adj[node]){
            cout<<child<<" "<<(str[child]-'a')<<endl;
            dfs(child, mask^(1<<(str[child]-'a')), adj, str);
        }
    }
    long long countPalindromePaths(vector<int>& parent, string s) {
        int n = parent.size();
        vector<int> adj[n];
        for(int i = 1; i<n; i++){
            adj[parent[i]].push_back(i);
        }
        dfs(0, 0, adj, s);
        long long ans = 0;
        for(auto [x,y]: mp){
            ans += y*1LL*(y-1);
            for(int i = 0; i<26; i++){
                if(mp.find(x^(1<<i)) != mp.end()) ans += y*1LL*mp[x^(1<<i)];
            }
        }
        return ans/2;
    }
};