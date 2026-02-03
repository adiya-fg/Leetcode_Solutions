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
    long long minimumCost(vector<int>& nums, int k, int dist) {
        long long ans=LLONG_MAX;
        int n = nums.size();

        long long sum = 0;
        int firstElement = nums[0];
        multiset <int, greater<int>> currentSet;
        multiset <int> tempStore;
        for(int i=n-k+2; i<n; i++) {
            currentSet.insert(nums[i]);
            sum += nums[i];
        }
        //ans=min(ans,sum+firstElement);
        //cout<<ans<<endl;
        for(int i=n-k+1; i>0; i--) {
            //find and remove 
            if(i+dist+1<n) {
                int target = nums[i+dist+1];
                auto it = currentSet.find(target);
                if (it != currentSet.end()) {
                    currentSet.erase(it);
                    sum -= target;
                } else {
                    it = tempStore.find(target);
                    if (it != tempStore.end())
                        tempStore.erase(it);
                }
                //cout<<target<<endl;
            }
            //add new element into tempstore
            //update
            while(currentSet.size()<k-2 && tempStore.size()>0)  {
                currentSet.insert((*tempStore.begin()));
                sum += (*tempStore.begin());
                tempStore.erase(tempStore.begin());
            }
            while(tempStore.size()>0 && (*currentSet.begin())>(*tempStore.begin())) {
                int tempVal = (*currentSet.begin());
                currentSet.erase(currentSet.begin());
                sum -= tempVal;
                //add new element
                tempVal = (*tempStore.begin());
                tempStore.erase(tempStore.begin());
                sum += tempVal;
                currentSet.insert(tempVal);
            }
            tempStore.insert(nums[i]);
            ans=min(ans,(sum + nums[i] + firstElement));
            //cout<<i<<" "<<ans<<endl;
        }
        return ans;
    }
};