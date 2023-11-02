class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        set<int> st;
        int ans = INT_MAX;
        for(int i = 0; i<nums.size(); i++){
            if(i < x) continue;
            st.insert(nums[i-x]);
            auto idx = st.lower_bound(nums[i]);
            if(idx == st.end()) idx--;
            ans = min(ans, abs(nums[i]-*idx));
            if(idx != st.begin()){
                ans = min(ans, abs(nums[i]-*(--idx)));
            }
        }
        return ans;
    }
};