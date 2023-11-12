class Solution {
public:
    int dp[100003][2];
    int solve(int idx, int change, int n, vector<int>& nums1, vector<int>& nums2, int prev1, int prev2){
        if(idx == n) return 0;
        if(dp[idx][change] != -1) return dp[idx][change];
        int ans = 1e7;
        if(prev1 < nums1[idx] && prev2 < nums2[idx]) ans = solve(idx+1, 0, n, nums1, nums2, nums1[idx], nums2[idx]);
        if(prev1 < nums2[idx] && prev2 < nums1[idx]) ans = min(ans, 1 + solve(idx+1, 1, n, nums1, nums2, nums2[idx], nums1[idx]));
        return dp[idx][change] = ans;
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        memset(dp, -1, sizeof(dp));
        int n = nums1.size();
        return solve(0, 0, n, nums1, nums2, -1, -1);
    }
};