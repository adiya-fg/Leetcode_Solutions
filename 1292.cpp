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
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int ans=0;

        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> dp(n+1,vector<int>(m+1,0));

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                int minVal = min(i,j);
                dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + mat[i-1][j-1];
                int cur = 1;
                while(cur<=minVal) {
                    int subSquareArea = dp[i][j] - dp[i-cur][j] - dp[i][j-cur] + dp[i-cur][j-cur];
                    if(subSquareArea<=threshold) {
                        ans = max(ans,cur);
                    }
                    cur++;
                }
            }
        }

        return ans;
    }
};