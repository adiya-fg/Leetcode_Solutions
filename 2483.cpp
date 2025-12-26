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
    int bestClosingTime( string customers) {
        
        int ans=INT_MAX;
        int n = customers.size();
        vector<int> dpN(n+1,0), dpY(n+1,0);

        for(int i=n-1; i>=0; i--) {
            dpN[i]=dpN[i+1]+(customers[i]=='N');
            dpY[i]=dpY[i+1]+(customers[i]=='Y');
        }

        int countY = 0;
        set<int> setForOpen;
        int index=0;

        for(int i=0; i<=n; i++) {
            //closes at ith day

            int totalPenalty=countY;
            // if(!setForOpen.empty()) {
            //     totalPenalty = (*setForOpen.begin())-dpN[i];
            // }
            totalPenalty += dpY[i];
            //ans=min(ans,totalPenalty);
            if(ans>totalPenalty) {
                ans=totalPenalty;
                index=i;
            }
            //setForOpen.insert(countY+dpN[i]);
            countY += (customers[i]=='N');
        }
        return index;
    }
};