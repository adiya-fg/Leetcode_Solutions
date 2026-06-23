#define N 2001
#define mod 1000000007

class Solution {
public:
	int inc[N][N], dec[N][N], sum_inc[N][N], sum_dec[N][N];
    int zigZagArrays(int n, int l, int r) {
    	int ans=0;

        for(int i = 1; i <= n; i++) {
            inc[i][l]       = dec[i][r]       = 0;
            sum_inc[i][l-1] = sum_dec[i][l-1] = 0;
        }

        //initialize
       for(int i=l; i<=r; i++) {
       		inc[1][i]=1;
       		dec[1][i]=1;
       		sum_inc[1][i]=(sum_inc[1][i-1] + inc[1][i])%mod;
       		sum_dec[1][i]=(sum_dec[1][i-1] + dec[1][i])%mod;
       }

       for(int i=2; i<=n; i++) {
       		for(int j=l; j<=r; j++) {
                //inc
                if(j>l) {
                    inc[i][j] = sum_dec[i-1][j-1];
                }
                //dec
                if(j<r) {
                    dec[i][j] = (sum_inc[i-1][r] - sum_inc[i-1][j] + mod)%mod;
                }
                sum_inc[i][j] = (sum_inc[i][j-1] + inc[i][j])%mod;
                sum_dec[i][j] = (sum_dec[i][j-1] + dec[i][j])%mod;  
            }
       }

       for(int i=l; i<=r; i++) {
            ans = (ans + inc[n][i])%mod;
            ans = (ans + dec[n][i])%mod;
       }

       return ans;
    }
};