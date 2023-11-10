class Solution {
public:
    int dp[101][101], ways[101][101];
    int dx[3] = {1, 1, 0};
    int dy[3] = {0, 1, 1};
    int mod = 1e9 + 7;
    vector<int> solve(int x, int y, int n, vector<string>& board){
        if(x >= n || y>=n || board[x][y] == 'X') return {INT_MIN, 0};
        if(x == n-1 && y == n-1) return {0,1};
        if(dp[x][y] != -1)return {dp[x][y], ways[x][y]};
        int maxy = -1e6, count = 0, val = 0;
        if(board[x][y] != 'E') val = board[x][y] - '0';
        for(int i = 0; i<3; i++){
            vector<int> temp = solve(x+dx[i], y+dy[i], n, board);
            if(temp[0] + val > maxy){
                maxy = val + temp[0];
                count = temp[1];
            }
            else if(temp[0] + val == maxy){
                count = (count + temp[1])%mod;
            }
        }
        dp[x][y] = maxy;
        ways[x][y] = count;
        return {maxy, count};
    }
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        memset(dp, -1, sizeof(dp));
        memset(ways, 0, sizeof(dp));
        vector<int> ans = solve(0, 0, n, board);
        if(ans[0] < 0) return {0, 0};
        return ans;
    }
};