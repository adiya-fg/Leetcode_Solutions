
#define N 100001
#define mod 1000000007

class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        vector<int> ans;
        int n = s.size();
        vector<long long> sum(n+1,0), count(n+1,0), pw(n+1,1),digiSum(n+1,0);

        // pre processing.
        for(int i=1; i<=n; i++) {
            pw[i]=(pw[i-1]*10)%mod;
            count[i]=count[i-1]+(s[i-1]!='0');
            digiSum[i]=digiSum[i-1]+(s[i-1]-'0');
            if(s[i-1]!='0')
                sum[i] = ((10*sum[i-1])%mod + (s[i-1]-'0'))%mod;
            else 
                sum[i] = sum[i-1];
        }

        int q = queries.size();
        int t = 0;
        while(q--) {
            int l = queries[t][0]+1;
            int r = queries[t++][1]+1;
            int digits = count[r] - count[l-1];
            long long x = (sum[r] - (pw[digits]*sum[l-1])%mod + mod)%mod;
            long long digit_sum = digiSum[r]-digiSum[l-1];
            //cout<<digits<<" "<<digit_sum<<" "<<x<<endl;
            ans.push_back((1LL*x*digit_sum)%mod);
        }
        return ans;    
    }
};