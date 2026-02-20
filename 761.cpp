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

    // global string holder
    string ans="";
    unordered_set <string> memo;
    
    void solver(string str){
        if(ans<str) ans=str;

        if(memo.find(str)!=memo.end()) 
            return;

        memo.insert(str);
        int n = str.size();
        string tempMax = str;

        // preprocessing.
        // scan to find all possible special substrings
        vector<vector<int>> started(n,vector<int>{}), ended(n,vector<int>{});
        for(int i=0; i<n; i++) {
            int count1=0, count0=0;
            for(int j=i; j<n; j++) {
                if(str[j]=='1') count1++;
                else count0++;
                if(count1<count0) break;
                // the string is special.
                if(count0==count1) {
                    started[i].push_back(j-i+1);     
                    ended[j].push_back(j-i+1);           
                }
            }
        }

        for(int i=2; i<n; i++) {
            // create new string by swapping.
            for(int j=0; j<ended[i-1].size(); j++) {
                for(int k=0; k<started[i].size(); k++) {
                    // build new string
                    string a = str.substr(i-ended[i-1][j],ended[i-1][j]);
                    string b = str.substr(i,started[i][k]);
                    string new_str = b + a;
                    string old_str = a + b;
                    string temp = str.substr(0,i-ended[i-1][j]) + new_str + 
                        str.substr(i+started[i][k],n-(i+started[i][k]));
                    if(new_str > old_str && temp > tempMax) {
                        tempMax = temp;
                        solver(temp);
                    }
                }
            }
        }
    }

    string makeLargestSpecial(string s) {
        solver(s);
        return ans;
    }
};