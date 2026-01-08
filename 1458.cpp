#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <climits>
#include <queue>
#include <map>
#include <unordered_map>
 
#define min(x,y) ((x<y) ? x : y)
#define max(x,y) ((x>y) ? x : y)

#define N 100001
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define INF 1000000000
 
using namespace std;


class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int mx=INT_MIN;
        int n = nums1.size();
        int m = nums2.size();

        vector<vector<int>> dp(n+1,vector<int>(m+1,0));

        for(int i=1; i<=n; i++) {    
            for(int j=1; j<=m; j++) {
                mx = max(mx,nums1[i-1]*nums2[j-1]);
            }
        }
        
        if(mx<0) return mx; 

        for(int i=1; i<=n; i++) {    
            for(int j=1; j<=m; j++) {
                dp[i][j] = max(0,nums1[i-1]*nums2[j-1]);
                dp[i][j] = max(dp[i][j],max(((i==1 || j==1) ? INT_MIN : dp[i-1][j-1]),dp[i-1][j-1]+nums1[i-1]*nums2[j-1]));

                for(int k=i-1; k>0; k--) {
                    dp[i][j]=max(dp[i][j],dp[k-1][j-1]+nums1[k-1]*nums2[j-1]);
                }
                for(int k=j-1; k>0; k--) {
                    dp[i][j]=max(dp[i][j],dp[i-1][k-1]+nums1[i-1]*nums2[k-1]);
                }
                cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
            }
        }
        return dp[n][m];
    }
};