class Solution {
public:
    int dp[1<<14][15];
    int mod = 1e9 + 7;
    int solve(int mask, int prev, vector<int>& nums){
        if(mask == 0) return 1;
        if(prev != -1 && dp[mask][prev] != -1) return dp[mask][prev];
        int ans = 0;
        for(int i = 0; i<nums.size(); i++){
            if(((mask>>i)&1) == 1){
                if(prev == -1) ans = (ans + solve(mask^(1<<i), i, nums))%mod;
                else if(nums[prev]%nums[i] == 0 || nums[i]%nums[prev] == 0){
                    ans = (ans + solve(mask^(1<<i), i, nums))%mod;
                }
            }
        }
        if(prev == -1) return ans%mod;
        return dp[mask][prev] = ans%mod;
    }
    int specialPerm(vector<int>& nums) {
        int n = nums.size();
        memset(dp, -1, sizeof(dp));
        int mask = (1<<n)-1;
        return solve(mask, -1, nums);
    }
};