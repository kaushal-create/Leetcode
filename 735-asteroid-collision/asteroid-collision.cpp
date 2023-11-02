class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        stack<vector<int>> st;
        vector<vector<int>> temp;
        for(int i = 0; i<asteroids.size(); i++){
            int x = asteroids[i];
            if(x > 0){
                st.push({i, x});
                continue;
            }
            bool flag = false;
            while(!st.empty() && st.top()[1]*x < 0 ){
                if(abs(x) == abs(st.top()[1])){
                    st.pop();
                    flag = true;
                    break;
                }
                else if(abs(x) > abs(st.top()[1])){
                    st.pop();
                }
                else {
                    break;
                }
            }
            if(!flag && st.empty()){
                temp.push_back({i, x});
            }
        }
        while(!st.empty()){
            temp.push_back(st.top());
            st.pop();
        }
        sort(temp.begin(), temp.end());
        for(auto x: temp) ans.push_back(x[1]);
        return ans;
    }
};