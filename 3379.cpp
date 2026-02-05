
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
#define INF 1000000000

using namespace std;

class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        vector<int> result;
        result = nums;

        /// set a to b, a = b;
        int n = nums.size();
        for(int i=0; i<n; i++){
            //if(nums[i]==0) result[i] = 0;
            // int new_index;
            // if( nums[i]>0 ) {
            //     //right move
            //     new_index = (i + nums[i])%n; //0,1,2,3 4->0
            //     result[i] = nums[new_index];
            // } else {
            //     //left move
            //     new_index = (i - (abs(nums[i]))%n + n)%n;
            //     result[i] = nums[new_index];
            // }
            result[i] = nums[((i + nums[i]) % n + n) % n];
            //cout<<i<<" : "<<new_index<<endl;
        }
        return result;
    }
};