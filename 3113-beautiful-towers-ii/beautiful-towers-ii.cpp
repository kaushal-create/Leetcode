class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        int n = maxHeights.size();
        vector<long long> pre(n), suf(n);
        stack<int> st;
        pre[0] = maxHeights[0];
        st.push(0);
        suf[n-1] = maxHeights[n-1];
        for(int i = 1; i<n; i++){
            while(!st.empty() && maxHeights[st.top()] > maxHeights[i]) st.pop();
            if(st.empty()) pre[i] = maxHeights[i]*1LL*(i+1);
            else pre[i] = pre[st.top()] +(i-st.top())*1LL*maxHeights[i];
            st.push(i);
        }
        while(!st.empty()) st.pop();
        st.push(n-1);
        for(int i = n-2; i>=0; i--){
            while(!st.empty() && maxHeights[st.top()] > maxHeights[i]) st.pop();
            if(st.empty()) suf[i] = maxHeights[i]*1LL*(n-i);
            else suf[i] = suf[st.top()] +(st.top()-i)*1LL*maxHeights[i];
            st.push(i);
        }
        long long ans = 0;
        for(int i = 0; i<n; i++){
            ans = max(ans, pre[i] + suf[i] - maxHeights[i]);
        }
        return ans;
    }
};