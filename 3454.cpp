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

    double check(double total, double midVal, vector<vector<int>>& squares) {
        double bottom = 0.0;
        for(int i=0; i<squares.size(); i++) {
            if(midVal>squares[i][1]) {
                bottom += ((double)min(midVal-squares[i][1],(double)squares[i][2])*squares[i][2]);
            }
        }   
        return ( bottom  >=  total/2.0);
    }

    double separateSquares(vector<vector<int>>& squares) {
        

        double ans=0.00;
        double left = 0;
        double max_y = 0;
        int n = squares.size();

        double total=0;
        for(int i=0; i<n; i++) {
            total += (double)squares[i][2]*squares[i][2];
            max_y = (double)max(max_y, (double)squares[i][1] + squares[i][2]);
        }

        double right = max_y;
        double eps = 1e-5;

        while(abs(right - left)>eps) {
            double mid = (left + right) / 2;    
            if(check(total,mid,squares)) {
                right = mid;
            } else {
                left = mid;
            }
        }

        return right;

    }
};