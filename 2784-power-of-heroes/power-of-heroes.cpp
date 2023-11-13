class Solution {
public:
    int mod = 1e9 + 7;
    long long exp(long long a, long long m)
    {
        a = a%mod;
        long long ans = 1;
        while(m){
            if(m%2) ans = (ans*a)%mod; 
            a = (a*a)%mod;
            m /= 2;
        }
        return ans%mod;
    }
    int sumOfPower(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long n = nums.size(), ans = 0;
        vector<long long> pre(n);
        pre[0] = exp(nums[0], 2);
        for(int i = 1; i<n; i++){
            pre[i] = (pre[i-1] + (exp(2, i)*exp(nums[i], 2))%mod)%mod;
        }
        int val = 1;
        for(int i = 0; i<n; i++){
            val = (val*2)%mod;
            long long curr = (pre[n-1]-pre[i])%mod;
            long long temp = exp(nums[i], 3);
            long long temp2 = (curr*exp(val, mod-2))%mod;
            ans = (ans + (temp + (nums[i]*temp2)%mod)%mod)%mod;
            // cout<<ans<<endl;
            if(ans < 0) ans += mod;
        }
        return ans;
    }
};