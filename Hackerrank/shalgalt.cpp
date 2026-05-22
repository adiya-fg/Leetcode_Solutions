#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

#define N 9

#define pb push_back

using namespace std;

int main() {


    int m; cin>>m;
    string ans;
    cin>>ans;

    int n; 
    cin>>n;

    vector<string> students(n);
    for(int i1=0; i1<n; i1++) {
        cin>>students[i1];
    }

    auto detectResult = [&](int i1, int i2)  {
        bool check = false;
        int countCorrect=0, countWrong = 0;
        int totalWrong=0, totalCorrect=0;
        for(int i=0; i<n; i++) {
            if(ans[i1]==students[i][i1]) {
                totalCorrect++;
                if(students[i][i1]==students[i][i2]) 
                    countCorrect++;
            } else {
                totalWrong++;
                if(students[i][i1]==students[i][i2]) 
                    countWrong++;                
            }    
        }
        return ((countCorrect>totalCorrect/2) && (countWrong>totalWrong/2));      
    };

    int res=0;
    for(int i1=0; i1<m; i1++) {
        for(int i2=i1+1; i2<m; i2++) {
            res+=detectResult(i1,i2);
        }
    }
    cout<<res<<endl;

    return 0;
}
