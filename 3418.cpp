class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        
        int ans=INT_MIN;
        int n = coins.size();
        int m = coins[0].size();

        vector<vector<vector<long long >>> dp(n+1,vector<vector<long long >>(m+1,vector<long long>(3,INT_MIN)));

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++) {
                if(i==1 && j==1) {
                    dp[i][j][0]=coins[i-1][j-1]; 
                    if(coins[0][0]<0)
                        dp[i][j][1] = 0;
                    continue;   
                }
                dp[i][j][0]=max(dp[i-1][j][0],dp[i][j-1][0])+coins[i-1][j-1];
                //neutralizing one cell.
                dp[i][j][1]=max(dp[i-1][j][1],dp[i][j-1][1])+coins[i-1][j-1];
                if(coins[i-1][j-1]<0) {
                    dp[i][j][1]=max(dp[i][j][1],max(dp[i-1][j][0],dp[i][j-1][0]));    
                }
                //neutralizing two cells.
                dp[i][j][2]=max(dp[i-1][j][2],dp[i][j-1][2])+coins[i-1][j-1];
                if(coins[i-1][j-1]<0) {
                    dp[i][j][2]=max(dp[i][j][2],max(dp[i-1][j][1],dp[i][j-1][1]));    
                }                
            }
        }

        if(n==m && m==1) return (coins[0][0]<0) ? 0 : coins[0][0];

        return max(max(dp[n][m][0],dp[n][m][1]),dp[n][m][2]);
    }
};