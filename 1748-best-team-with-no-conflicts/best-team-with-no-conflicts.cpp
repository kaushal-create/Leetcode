class Solution {
public:
    int dp[1001][1001];
    int solve(int idx, int prev, int n, vector<vector<int>>& arr){
        if(idx == n) return 0;
        if(prev != -1 && dp[idx][prev] != -1) return dp[idx][prev];
        int take = 0, non_take = 0;
        if(prev == -1 || arr[prev][1] >= arr[idx][1]){
            take += arr[idx][1] + solve(idx+1, idx, n, arr);
        }
        non_take = solve(idx+1, prev, n, arr);
        if(prev == -1) return max(take, non_take);
        return dp[idx][prev] = max(take, non_take);
    }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<vector<int>> arr;
        int n = scores.size();
        memset(dp, -1, sizeof(dp));
        for(int i = 0; i<n; i++){
            arr.push_back({ages[i], scores[i]});
        }
        sort(arr.begin(), arr.end(), greater<vector<int>>());
        return solve(0, -1, n, arr);
    }
};