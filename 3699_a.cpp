#define N 2001
#define mod 1000000007

class Solution {
public:
	
    int inc[N], dec[N];
    long long sum_inc[101][101], sum_dec[101][101], mul[101][101], temp_mul[101][101];

    int zigZagArrays(int n, int l, int r) {
    	int ans=0;

        //initialize
        r = r - l + 1;
        l = 1;

        // build sum_inc matrix
        
        for(int i=1; i<=r; i++) {
            for(int j=1; j<=r; j++) {
                if(i<j) {
                    sum_inc[i][j]=1;
                } else {
                    sum_inc[i][j]=0;
                }
                if(i==j) mul[i][j]=1;
                else mul[i][j]=0;
            }
        }

        int power = n-1;
        while(power>0) {
            if(power%2==1) {
                for(int i=1; i<=r; i++) {
                    for(int j=1; j<=r; j++) {
                        long long temp = 0;
                        for(int k=1; k<=r; k++) {
                            temp = (temp + sum_inc[i][k]*mul[k][j])%mod;
                        }
                        temp_mul[i][j] = temp;
                    }
                }
                for(int i=1; i<=r; i++) {
                    for(int j=1; j<=r; j++) {   
                        mul[i][j] = temp_mul[i][j];
                    }
                }
            }   
            power/=2;
            for(int i=1; i<=r; i++) {
                for(int j=1; j<=r; j++) {
                    long long temp = 0;
                    for(int k=1; k<=r; k++) {
                        temp = (temp + sum_inc[i][k]*sum_inc[k][j])%mod;
                    }
                    temp_mul[i][j] = temp;
                }
            }
            for(int i=1; i<=r; i++) {
                for(int j=1; j<=r; j++) {   
                    sum_inc[i][j] = temp_mul[i][j];
                }
            }
        }


        // build sum_dec matrix
        
        for(int i=1; i<=r; i++) {
            for(int j=1; j<=r; j++) {
                if(i>j) {
                    sum_dec[i][j]=1;
                } else {
                    sum_dec[i][j]=0;
                }
                if(i==j) mul[i][j]=1;
                else mul[i][j]=0;
            }
        }

        power = n-1;
        while(power>0) {
            if(power%2==1) {
                for(int i=1; i<=r; i++) {
                    for(int j=1; j<=r; j++) {
                        long long temp = 0;
                        for(int k=1; k<=r; k++) {
                            temp = (temp + sum_dec[i][k]*mul[k][j])%mod;
                        }
                        temp_mul[i][j] = temp;
                    }
                }
                for(int i=1; i<=r; i++) {
                    for(int j=1; j<=r; j++) {   
                        mul[i][j] = temp_mul[i][j];
                    }
                }
            }   
            power/=2;
            for(int i=1; i<=r; i++) {
                for(int j=1; j<=r; j++) {
                    long long temp = 0;
                    for(int k=1; k<=r; k++) {
                        temp = (temp + sum_dec[i][k]*sum_dec[k][j])%mod;
                    }
                    temp_mul[i][j] = temp;
                }
            }
            for(int i=1; i<=r; i++) {
                for(int j=1; j<=r; j++) {   
                    sum_dec[i][j] = temp_mul[i][j];
                }
            }
        }

        for(int j=1; j<=r; j++) {
            //dec
            inc[j] = sum_dec[j][1]; 
            //inc
            dec[j] = sum_inc[1][j-1];
        }

       for(int i=1; i<=r; i++) {
            ans = (ans + inc[i])%mod;
            ans = (ans + dec[i])%mod;
       }

       return ans;
    }
};