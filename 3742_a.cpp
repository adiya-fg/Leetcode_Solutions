class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int maxScore = INT_MIN;
        
        int n = grid.size();
        int m = grid[0].size();

        if(n==m && m==1) return grid[0][0];

        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(m+1,vector<int>(k+1,-1)));

        dp[1][1][0]=grid[0][0];

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(i==1 && j==1) continue;
                for(int c=0; c<=k; c++) {
                    int newCost = c-(grid[i-1][j-1]!=0);
                    int score = grid[i-1][j-1];
                    if(newCost<0) continue;
                    if(dp[i-1][j][newCost]!=-1)
                        dp[i][j][c]=max(dp[i][j][c],dp[i-1][j][newCost]+score);
                    if(dp[i][j-1][newCost]!=-1)
                        dp[i][j][c]=max(dp[i][j][c],dp[i][j-1][newCost]+score);

                    if(i==n && j==m) {
                        maxScore = max(maxScore,dp[i][j][c]);
                    }
                }
            }
        }
        return ((maxScore==INT_MIN) ? -1 : maxScore);
    }
};