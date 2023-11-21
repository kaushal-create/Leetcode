class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        int ans = 0;
        priority_queue<int> pq;
        for(int i = 0; i<n-1; i++){
            if(heights[i+1] > heights[i]){
                int brickReq = heights[i+1]-heights[i];
                if(bricks >= brickReq){
                    bricks -= brickReq;
                    pq.push(brickReq);
                    ans++;
                    continue;
                }
                else if((pq.empty() || brickReq > pq.top()) && ladders > 0){
                    ladders--;
                    ans++;
                    continue;
                }
                else{
                    while(!pq.empty() && ladders > 0){
                        int val = pq.top();
                        bricks += val;
                        pq.pop();
                        ladders--;
                        if(bricks >= brickReq){
                            bricks -= brickReq;
                            pq.push(brickReq);
                            ans++;
                            brickReq = 0;
                            break;
                        }
                    }
                    if(bricks < brickReq && ladders == 0)break;
                }
            }
            else ans++;
        }
        return ans;
    }
};