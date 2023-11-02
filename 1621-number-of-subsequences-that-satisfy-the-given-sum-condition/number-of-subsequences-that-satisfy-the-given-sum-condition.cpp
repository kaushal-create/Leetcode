class Solution {
public:
    int mod = 1e9 + 7;
    int exp(int a, int m) {
        a = a%mod;
        int ans = 1;
        while(m){
            if(m%2) {
                ans = (ans*1LL*a)%mod;
            }
            a = (a*1LL*a)%mod;
            m /= 2;
        }
        return ans;
    }
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] <= target){
                int idx = upper_bound(nums.begin()+i, nums.end(), target-nums[i]) - nums.begin();
                // cout<<idx<<endl;
                idx--;
                if(idx-i > 0) ans = (ans + exp(2, idx-i))%mod;
                else if (2*nums[i] <= target) ans++;
            }
        }
        return ans;
    }
};