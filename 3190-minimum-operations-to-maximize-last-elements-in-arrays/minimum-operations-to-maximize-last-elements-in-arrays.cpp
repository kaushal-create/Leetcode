class Solution {
public:
    int dp[1002];
    int solve(int idx, int n, vector<int>nums1, vector<int>nums2){
        if(idx == n-1) return 0;
        int ans = 1e7;
        if(dp[idx] != -1) return dp[idx];
        if(nums1[idx] <= nums1[n-1] && nums2[idx] <= nums2[n-1]) ans = solve(idx+1, n, nums1, nums2);
        if(nums2[idx] <= nums1[n-1] && nums1[idx] <= nums2[n-1]) ans = min(ans, 1 + solve(idx+1, n, nums1, nums2));
        return dp[idx] = ans;
    }
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
       memset(dp, -1, sizeof(dp));
       int ans = solve(0, n, nums1, nums2);
       memset(dp, -1, sizeof(dp));
       swap(nums1[n-1], nums2[n-1]);
       ans = min(ans, 1 + solve(0, n, nums1, nums2));
       return ans >= 1e7 ? -1 : ans;
    }
};