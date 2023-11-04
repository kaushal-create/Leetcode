class Solution {
public:
    long long dp[1<<13][13];
    long long fact[13];
    bool isPossible(int a){
        int b = sqrt(a);
        return a == b*b;
    }
    long long solve(int prev, int mask, vector<int>&nums){
        if(mask == 0)return 1;
        if(prev != -1 && dp[mask][prev] != -1) return dp[mask][prev];
        long long ans = 0;
        for(int i = 0; i<nums.size(); i++){
            if(prev == -1){
                ans += solve(i, mask^(1<<i), nums);
            }
            else if((mask>>i)&1 == 1 && isPossible(nums[i] + nums[prev])){
                ans += solve(i, mask^(1<<i), nums);
            }
        }
        if(prev == -1) return ans;
        else return dp[mask][prev] = ans;
    }
    int numSquarefulPerms(vector<int>& nums) {
        int n = nums.size();
        memset(dp, -1, sizeof(dp));
        map<int, int> mp;
        for(auto x: nums) mp[x]++;
        fact[0] = 1, fact[1] = 1;
        for(int i = 2; i<=n; i++){
            fact[i] = i*1LL*fact[i-1];
        }
        int mask = (1<<n) - 1;
        long long ans = solve(-1, mask, nums);
        for(auto [x,y]: mp){
            ans = ans/fact[y];
        }
        return ans;
    }
};