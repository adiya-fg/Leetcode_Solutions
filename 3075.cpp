
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
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long ans=0;

        sort(happiness.begin(),happiness.end());
        int cur=0;
        int n = happiness.size()-1;
        while(k--){
            if(cur>happiness[n]) break;
            ans += (happiness[n]-cur);
            n--;
            cur++;
        }
        return ans;
    }
};