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
#include <unordered_set>

#define min(x,y) ((x<y) ? x : y)
#define max(x,y) ((x>y) ? x : y)

#define N 50001
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define INF 1000000000
 
using namespace std;

class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int ans=1;

        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());

        //pre processed cache
        unordered_set<int> row_cache, col_cache, row_store;

        for(auto &data : hBars) {
            row_cache.insert(data);
        }

        row_store.insert(1);
        for(auto &data : hBars) {
            int cur = data;
            while(cur>0 && row_cache.find(cur)!=row_cache.end()) {
                row_store.insert(data-cur+2);
                cur--;
            }
        }

        for(auto &data : vBars) {
            col_cache.insert(data);
        }

        for(auto &data : vBars) {
            int cur = data; 
            while(cur>0 && col_cache.find(cur)!=col_cache.end() && row_store.find(data-cur+2)!=row_store.end()) {
                int temp_ans = data-cur+2;
                ans = max(ans,temp_ans*temp_ans);
                cur--;
            }
        }

        return ans;
    }
};