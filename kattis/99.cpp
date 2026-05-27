#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int main() {

    int n; cin>>n;
    int ans = INT_MAX,val=0;
    for(int i=99; i<100*n; i++) {
        int diff = abs(n - i);
        if(i%100==99 && diff<=ans) {
            ans=diff;
            val = i;
        }
    }
    cout<<val;
    return 0;
}