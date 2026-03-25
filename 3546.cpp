class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long totalSum=0;

        for(auto &row: grid) {
            for(auto &col : row) {
                totalSum += col;
            }
        }

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<long long>> dp(n+1,vector<long long>(m+1,0));
        //dp[i][j]-store sum of all elements that lies in the rectangle (0,0) to (i,j);
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+grid[i-1][j-1];
                if(j==m || i==n) {
                    if((totalSum-dp[i][j])==dp[i][j]) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};