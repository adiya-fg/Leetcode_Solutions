class Solution {
public:
    int minOperations(string s) {

        vector<vector<int>> dp(s.size(),vector<int>(2,0));
        dp[0][0]=(s[0]!='0');
        dp[0][1]=(s[0]!='1');
        
        int n = s.size();
        for(int i=1; i<n; i++) {
            dp[i][0]=dp[i-1][1]+(s[i]!='0');
            dp[i][1]=dp[i-1][0]+(s[i]!='1');            
        }
        return min(dp[s.size()-1][0],dp[s.size()-1][1]);
    }
};

//limit is 10000
//01-0
//11-1->01
//dp[i][1],dp[i][0]-store number of operations needed to be the string is alternating.