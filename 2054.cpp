
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
    int maxTwoEvents(vector<vector<int>>& events) {
        int res=0;
        
        sort(events.begin(),events.end());

        set<vector<int>> activeEvent;
        set<int,greater<int>> endedEvent;

        for(auto &data : events) {
            res=max(res,data[2]);
            activeEvent.insert({data[1],data[0],data[2]});
            while(!activeEvent.empty() && (*activeEvent.begin())[0]<data[0]){
                endedEvent.insert((*activeEvent.begin())[2]);
                activeEvent.erase(activeEvent.begin());
            }
            if(!endedEvent.empty()) {
                res=max(res,data[2]+(*endedEvent.begin()));
            }
        }
        return res;
    }
};