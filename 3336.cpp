#define N 201
#define MOD 1000000007

class Solution {
public:
    int gcd(int a, int b) {
        if(b==0) return a;
        else return gcd(b,a%b);
    }
    
    int subsequencePairCount(vector<int>& nums) {
        int ans=0;
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(N, vector<int>(N, 0)));

        vector<vector<int>> gc(N, vector<int>(N,0));

        for(int j=0; j<N; j++){
            for(int k=0; k<N; k++) {
                gc[j][k]=__gcd(j,k);
            }
        }

        int mx = 0;
        for(auto val : nums) {
            mx = max(val,mx);
        }

        dp[0][0][0]=1;
        int x,y;

        for(int i=1; i<=nums.size(); i++){
            // dp[i][0][nums[i]]=1;
            // dp[i][nums[i]][0]=1;
            for(int j=0; j<=mx; j++){
                for(int k=0; k<=mx; k++) {
                    if(dp[0][j][k]==0) continue;
                    x = gc[j][nums[i-1]];
                    y = gc[k][nums[i-1]];
                    // if not using ith value.
                    dp[1][j][k] = (dp[1][j][k]  + dp[0][j][k]) % MOD;
                    // if use the value.
                    dp[1][x][k] = (dp[1][x][k] + dp[0][j][k]) % MOD;
                    dp[1][j][y] = (dp[1][j][y] + dp[0][j][k]) % MOD;
                }
            }
                        for(int j=0; j<=mx; j++){
                for(int k=0; k<=mx; k++) {
                    dp[0][j][k]=dp[1][j][k];
                    dp[1][j][k] = 0;
                }
            }
        }

        for(int j=1; j<=mx; j++){
            ans = (ans + dp[0][j][j])%MOD;
        }

        return ans;
    }
};