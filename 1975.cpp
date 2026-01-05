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
    long long maxMatrixSum(vector<vector<int>>& matrix) {
  		long long ans=0;

  		vector<int> rows;

  		int n = matrix.size();
  		int m = matrix[0].size();
  		long long sum=0;
        int countZero=0;
        int cnt = 0;

  		for(int i=0; i<n; i++) {
  			for(int j=0; j<m; j++) {
                if(matrix[i][j]<0) { cnt++; matrix[i][j] = -1*matrix[i][j]; }
                sum += matrix[i][j];
                if(matrix[i][j]==0)countZero++;
  			}
  		}

        if(cnt%2==0 || countZero>0) return sum;
        int subMax=matrix[0][0];
  		for(int i=0; i<n; i++) {
  			for(int j=0; j<m; j++) {
                subMax=min(subMax,matrix[i][j]);
            }
        }        
        return sum-(2LL*subMax);      
    }
};