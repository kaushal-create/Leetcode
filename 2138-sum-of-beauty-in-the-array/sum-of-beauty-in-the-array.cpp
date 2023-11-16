class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int ans = 0, n = nums.size();
        vector<int> premax(n), sufmin(n);
        premax[0] = nums[0];
        sufmin[n-1] = nums[n-1];
        for(int i = 1; i<n; i++) premax[i] = max(premax[i-1], nums[i]);
        for(int i = n-2; i>=0; i--) sufmin[i] = min(sufmin[i+1], nums[i]);
        for(int i = 1; i<n-1; i++){
            if(nums[i] > premax[i-1] && nums[i] < sufmin[i+1]) ans += 2;
            else if(nums[i] > nums[i-1] && nums[i] < nums[i+1]) ans += 1;
        }
        return ans;
    }
};