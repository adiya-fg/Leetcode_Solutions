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
    int maximizeSquareArea(int n, int m, vector<int>& rows, vector<int>& cols) {

        //pre processed cache
        long long ans=-1;
        unordered_set<int> row_cache, col_cache, row_store;

        vector<int> hBars;
        hBars.push_back(1);
        for(auto &data: rows) {
            hBars.push_back(data);
        }
        hBars.push_back(n);
        sort(hBars.begin(),hBars.end());

        vector<int> vBars;
        vBars.push_back(1);
        for(auto &data: cols) {
            vBars.push_back(data);
        }
        vBars.push_back(m);

        sort(vBars.begin(),vBars.end());
        
        for(int i=1; i<hBars.size(); i++) {
            int cur = hBars[i];
            for(int j=i-1; j>=0; j--) {
                int diff = cur - hBars[j];
                row_store.insert(diff);
            }
        }

        for(int i=1; i<vBars.size(); i++) {
            int cur = vBars[i];
            //cout<<cur<<" here "<<endl;
            for(int j=i-1; j>=0; j--) {
                int diff = cur - vBars[j];
                //cout<<diff<<endl;
                if(row_store.find(diff)!=row_store.end()) {
                   ans = max(ans,diff); 
                   //cout<<"i am here"<<diff<<endl;
                }
            }            
        }      
        return (ans<0) ? ans : (1LL*ans*ans)%mod;        
    }
};