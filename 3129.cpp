#define mod 1000000007

class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        
        int ans = 0;
        int n = zero + one;
        int dp[201][201];

        dp[0][0]=1;
        for(int i=1; i<=200; i++) {
            dp[i][0]=1;
            for(int j=1; j<=i; j++) {
                dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%mod;
            }
        }

        for(int i=1; i<=n; i++) {
            //dp[i][k] - k number of 1s.
            for(int j=0; j<=one; j++) {
                
            }
        }

        return ans;
    }
};