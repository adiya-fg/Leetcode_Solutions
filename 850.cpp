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

#define N 50001
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define INF 1000000000
 
using namespace std;

class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        set<int>xset;
        vector<vector<int>> events;
        unordered_map<int,int> index;
        for(auto &data: rectangles) {
            int x1 = data[0];
            int y1 = data[1];
            int x2 = data[2];
            int y2 = data[3];
            xset.insert(x1);
            xset.insert(x2);
            vector<int> tempData;
            tempData.push_back(y1);
            tempData.push_back(1);
            tempData.push_back(x1);
            tempData.push_back(x2);
            events.push_back(tempData);
            tempData.clear();
            tempData.push_back(y2);
            tempData.push_back(-1);
            tempData.push_back(x1);
            tempData.push_back(x2);
            events.push_back(tempData);
        }
        int n = xset.size();
        vector<int> val, actualIndex;
        val.resize(n+1,0);
        actualIndex.resize(n+1,0);

        int cur = 0;
        while(!xset.empty()){
            index[(*xset.begin())] = cur;
            actualIndex[cur] = (*xset.begin());
            xset.erase(xset.begin());
            cur++;
        }

        sort(events.begin(),events.end());
        //scan line by line.
        int prevY = 0;
        long long ans = 0;
        for(auto &data : events){
            int y       = data[0];
            int delta   = data[1];
            int xl      = data[2];
            int xr      = data[3];
            int width = y - prevY; //width
            //cout<<y<<" : "<<width<<endl;
            //find summation value current data
            long long sum = 0;
            for(int i=0; i<n-1; i++) {
                if(val[i]>0){
                    //cout<<"here"<<endl;
                    sum = (sum +  1LL*width*(actualIndex[i+1]-actualIndex[i]))%mod;
                }
            }
            ans = (ans + sum)%mod;
            //update here;
            int indexL = index[xl];
            int indexR = index[xr];
            for(int i=indexL; i<indexR; i++) {
                val[i] += delta;
            }
            prevY = y;
        }
        return ans;
    }
};