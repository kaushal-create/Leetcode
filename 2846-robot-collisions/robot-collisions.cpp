class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<vector<int>> arr, temp;
        for(int i = 0; i<n; i++){
            if(directions[i] == 'L'){
                arr.push_back({positions[i], healths[i], 0, i});
            }
            else arr.push_back({positions[i], healths[i], 1, i});
        }
        sort(arr.begin(), arr.end());
        stack<int> st;
        for(int i = 0; i<n; i++){
            if(arr[i][2] == 1){
                st.push(i);
            }
            else{
                int curr = arr[i][1];
                while(!st.empty()){
                    if(arr[st.top()][1] == curr){
                        st.pop();
                        curr = 0;
                        break;
                    }
                    else if(arr[st.top()][1] < curr){
                        curr--;
                        st.pop();
                    }
                    else{
                        break;
                    }
                }
                if(st.empty() && curr > 0){
                    temp.push_back({arr[i][3], curr});
                }
                else if(curr > 0){
                    arr[st.top()][1]--;
                }
            }
        }
        while(!st.empty()){
            temp.push_back({arr[st.top()][3], arr[st.top()][1]});
            st.pop();
        }
        sort(temp.begin(), temp.end());
        vector<int> ans;
        for(auto x: temp) ans.push_back(x[1]);
        return ans;
    }
};