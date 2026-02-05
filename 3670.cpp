
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

class tempstore {
    public:
        long long mx,mn,sum;
        bool state;
        int index;
    public: 
        tempstore(bool state, long long mx, long long mn, long long sum, int index) {
            this->state = state;
            this->mx=mx;
            this->mn=mn;
            this->sum=sum;
            this->index=index;
        }
};

class Solution {
public:
    long long solver(vector<int>& nums) {
       long long ans=LLONG_MIN;
        int n = nums.size();
        
        vector <tempstore> points;
        tempstore temp((nums[1]-nums[0])>0,nums[0],nums[0],nums[0],0);
        points.push_back(temp);
        
        for(int j=1; j<n-1; j++) {
            // is it turning point
            int sz = points.size();
            long long leftval = (nums[j]-nums[j-1]);
            long long rightval = (nums[j+1]-nums[j]); 
            if(leftval*rightval<0) {
                tempstore newpoint((nums[j+1]-nums[j])>0,nums[j],nums[j],nums[j],j);   
                points.push_back(newpoint);
            } else {
                points[sz-1].sum += nums[j];
                points[sz-1].mx = max(points[sz-1].mx, points[sz-1].sum);
                points[sz-1].mn = min(points[sz-1].mn, points[sz-1].sum);
            }
        }
        if(points.size()<3) return ans;
        // cout<<points.size()<<endl;
        // for(int i=0; i<points.size(); i++) {
        //     cout<<points[i].sum<<" : "<<points[i].state<<endl;
        // }
        // find answer
        for(int i=1; i<points.size()-1; i++) {
            // desc, inc, desc
            if(points[i].state==false) {
                long long subMax = 0;

                // find the left max
                long long val = nums[points[i].index-1];
                long long temp = val;
                int k = points[i].index-2;
                while(k>=points[i-1].index) {
                    temp += nums[k];
                    if(val<temp)
                        val=temp;
                    k--;
                }
                subMax += val;
                subMax += points[i].sum;
                // find the right max
                val = nums[points[i+1].index] + nums[points[i+1].index+1];
                temp = val;
                k = points[i+1].index+2;
                int right_limit = ((i+2<points.size()) ? points[i+2].index : n-1);
                while(k<=right_limit) {
                    temp += nums[k];
                    if(val<temp)
                        val=temp;
                    k++;
                }
                subMax += val;
                ans=max(ans,subMax);
            }
        }
        return ans;
    }

    long long maxSumTrionic(vector<int>& nums) {
        long long result=LLONG_MIN;
        vector<int> temp;
        int n = nums.size();
        for(int i=0; i<n; i++) {
           if(i>0 && nums[i]==nums[i-1]) {
                if(temp.size()>0) {
                    result = max(result, solver(temp));
                }
                temp.clear();
                temp.push_back(nums[i]);
                continue;
           }
           temp.push_back(nums[i]);
        }
        if(temp.size()>0) {
            result = max(result, solver(temp));
        }
        return result;
    }
};
//omg 855 / 858 testcases passed
//omg 857 / 858 testcases passed
//[0,-2,-1,-3,0,0,2,-1]