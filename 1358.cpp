class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans=0;
        int n = s.size();

        vector<vector<int>> dp(n+1,vector<int>(3,0));

        for(int i=1; i<=n; i++) {
            for(int j=0; j<3; j++) {
                dp[i][j] = dp[i-1][j];
            }
            dp[i][s[i-1]-'a'] = dp[i-1][s[i-1]-'a'] + 1;
        }

        for(int i=3; i<=n; i++) {
            
            int left = 1, right = i-2;
            while(left<=right){
                int mid = (left+right)>>1;
                int count = ((dp[i][0]-dp[mid-1][0])>0)+((dp[i][1]-dp[mid-1][1])>0)+((dp[i][2]-dp[mid-1][2])>0);
                if(count>=3) {
                    left = mid + 1;
                } else 
                    right = mid - 1;
            }
            ans += right;
        }

        return ans;
    }
};