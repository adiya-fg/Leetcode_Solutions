class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        bool res=false;
        int n = s.size();

        vector<int> f(n,0), dp(n,0);

        f[0]=1;
        for(int i=0; i<minJump; i++) {
            dp[i]=1;
        }

        for(int i=minJump; i<n; i++) {
            if(s[i]=='1') dp[i] = dp[i-1];
            else {
                int l = i-maxJump;
                int r = i-minJump;
                int total = dp[r]-((l<=0) ? 0 : dp[l-1]);
                f[i] = (total!=0);
                dp[i] = dp[i-1] + f[i];
            }
        }

        return f[n-1];
    }
};
