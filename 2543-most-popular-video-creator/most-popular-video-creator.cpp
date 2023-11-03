class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        map<string, long long> mp, maxy;
        map<string, string> mp2;
        long long n = creators.size(), val = 0;
        for(int i = 0; i<n; i++){
            mp[creators[i]] += views[i];
            val = max(val, mp[creators[i]]);
            if(maxy[creators[i]] <= views[i]){
                if(maxy[creators[i]] == views[i] && mp2.find(creators[i]) != mp2.end()){
                    mp2[creators[i]] = min(mp2[creators[i]], ids[i]);
                }
                else mp2[creators[i]] = ids[i];
                maxy[creators[i]] = views[i];
            }
        }
        vector<vector<string>>ans;
        for(auto [x,y]: mp){
            if(y == val){
                ans.push_back({x, mp2[x]});
            }
        }
        return ans;
    }
};