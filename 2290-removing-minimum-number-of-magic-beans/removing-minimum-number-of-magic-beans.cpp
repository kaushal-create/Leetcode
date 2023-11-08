class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        int n = beans.size();
        sort(beans.begin(), beans.end());
        vector<long long> pre(n);
        pre[0] = beans[0];
        for(int i = 1; i<n; i++){
            pre[i] = pre[i-1] + beans[i]*1LL;
        }
        long long ans = 1e15;
        for(int i = 0; i<n; i++){
           ans = min(ans, pre[n-1] - ((n-i)*1LL*beans[i]));
        }
        return ans;
    }
};