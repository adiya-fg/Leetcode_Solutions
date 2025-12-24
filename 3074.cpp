
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
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int totalApple=0;
        for(auto&val : apple) {
            totalApple+=val;
        }
        sort(capacity.begin(),capacity.end());
        int ans=0;
        for(int i=capacity.size()-1; i>=0; i--) {
            totalApple-=capacity[i];
            ans++;
            if(totalApple<=0) break;
        }
        return ans;
    }
};