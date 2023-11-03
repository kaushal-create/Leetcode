class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        set<int> st;
        int ans = 0, n = nums.size();
        for(int i = 0; i<n; i++){
            int flip_cnt = st.size();
            nums[i] = nums[i]^(flip_cnt%2);
            if(nums[i] == 0){
                int nextPos = i + k - 1;
                if(nextPos >= n){
                    return -1;
                }
                ans++;
                st.insert(nextPos);
            }
            if(st.count(i)) st.erase(i);
        }
        return ans;
    }
};