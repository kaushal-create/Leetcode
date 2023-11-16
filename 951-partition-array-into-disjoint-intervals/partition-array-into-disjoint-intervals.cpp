class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        vector<int> premax(n), sufmin(n);
        premax[0] = nums[0];
        sufmin[n-1] = nums[n-1];
        for(int i = 1; i < n; i++) premax[i] = max(premax[i-1], nums[i]);
        for(int i = n-2; i >= 0; i--) sufmin[i] = min(sufmin[i+1], nums[i]);
        for(int i = 0; i<n; i++){
            if(premax[i] <= sufmin[i+1]) return i+1;
        }
        return -1;
    }
};