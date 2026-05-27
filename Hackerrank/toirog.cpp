#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    cout<<"TIL HAMINGJU MED AFMAELID FORRITUNARKEPPNI FRAMHALDSSKOLANNA!"<<endl;
    return 0;
}
    long long n,l; cin>>n>>l;

    long long  ans=0;
    vector<long long>x(n,0);

    for(int i=0;i<n; i++) {
        cin>>x[i];
    }

    for(int i=0;i<n; i++) {
        long long cnt = 0;
        long long sum = 0;
        bool temp=false;
        int index = 0;
        for(int j=i+1; j<n; j++) {
            //sum += x[j];
            if(2*x[j]>=l) {
                temp = true;
                break;
            }
            cnt++;
        }
        if(!temp) {
             for(int j=0; j<n; j++) {
                //sum += x[j];
                if(2*sum>=l) {
                    temp = true;
                    break;
                }
                cnt++;
            }   
        }
        ans += cnt*(n-cnt-1);
        if(2*sum==l) {
            long long complement = n-cnt-2;
            if(complement>0) ans += complement;
        }
        //cout<<i<<" : "<<ans<<endl;
    }    
    cout<<ans/3;
    return 0;
}
