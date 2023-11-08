class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        if(n == 1) return arr[0];
        vector<int> dp1(n, 0), dp2(n, 0);
        int ans = INT_MIN;
        dp1[0] = arr[0];
        dp2[n-1] = arr[n-1];
        for(int i = 1; i<n; i++) dp1[i] = max(dp1[i-1]+arr[i], arr[i]), ans = max(ans, dp1[i]);
        for(int i = n-2; i>=0; i--) dp2[i] = max(dp2[i+1]+arr[i], arr[i]), ans= max(ans, dp2[i]);
        ans = max({ans, dp1[n-2], dp2[1]});
        for(int i = 1; i<n-1; i++){
            ans = max(ans, dp1[i-1] + dp2[i+1]);
        }
        return ans;
    }
};