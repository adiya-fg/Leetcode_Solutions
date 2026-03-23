class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        long long ans;

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<long long>>> 
            dp(n+1,vector<vector<long long>>(m+1,vector<long long >(2,LLONG_MIN)));

        dp[0][1][1]=1;

        int countZeros=0;
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                int val = grid[i-1][j-1];
                if(val==0) countZeros++;
                vector<long long> temp;
                if(dp[i-1][j][0]!=LLONG_MIN)
                    temp.push_back(dp[i-1][j][0]*val);
                if(dp[i-1][j][1]!=LLONG_MIN)
                    temp.push_back(dp[i-1][j][1]*val);
                if(dp[i][j-1][0]!=LLONG_MIN)
                    temp.push_back(dp[i][j-1][0]*val);
                if(dp[i][j-1][1]!=LLONG_MIN)    
                    temp.push_back(dp[i][j-1][1]*val);
                sort(temp.begin(),temp.end());

                if(temp[temp.size()-1]>=0)
                    dp[i][j][1] = temp[temp.size()-1];
                if(temp[0]<0)
                    dp[i][j][0] = temp[0];                    
            }
        }

        ans = max(dp[n][m][0],dp[n][m][1]);
        if(ans<0) { if(countZeros) return 0; else return -1; }
        else return ans%1000000007;
    }
};