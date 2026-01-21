
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
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        
        for(auto &val : nums) {
            int temp = val;
            int x = 0, y= 0;
            int mul = 1;

            if(val==2) {
                ans.push_back(-1); continue;
            }
            
            vector<int> bits; 
            bits.clear();
            while(temp>0) {
                bits.push_back( temp%2 );
                temp /= 2;
            }
            bool check = false;
            int tempData = val;
            for(int i=1; i<bits.size(); i++) {
                if(bits[i-1]==1 && bits[i]==1) {
                    bits[i] = 1; check=true; 
                    tempData -= pow(2,i-1);
                    //cout<<i<<" here "<<tempData<<endl;
                } else {
                    bits[i-1] = 0; break;
                }
            }
            ans.push_back(tempData-1);
        }
        
        return ans;
    }
};