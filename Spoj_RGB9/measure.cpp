#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <iostream>

#define pb push_back
#define mp make_pair

using namespace std;

int timeToInt(string str){
    vector<string> result;
    string temp_str = "";
    for(char chr: str) {
        if(chr==':'){
            result.push_back(temp_str);
            temp_str="";    
        } else {
            temp_str += chr;
        }
    }
    result.push_back(temp_str);
    reverse(result.begin(),result.end());

    vector <int> multipler = {1,60,3600};
    int ans=0;
    for(int i=0; i<result.size(); i++) {
        ans += multipler[i]*stoi(result[i]);
    }

    return ans;
}
string timeToStr(int val){
    string ans="";
    vector <int> multipler = {1,60,3600};
    for(int i=2; i>=0; i--){
        int new_val = val/multipler[i];
        val=val%multipler[i];
        string str_val = to_string(new_val);
        if(str_val.size()<2)
            str_val = "0" + str_val;
        
            ans += str_val;
        if(i!=0) ans+=":";
    }
    return ans;
}
int main(){


    string str1,str2;
    cin>>str1>>str2;

    int val1 = timeToInt(str1);
    int val2 = timeToInt(str2);

    int days = 0;
    int one_day = 24*60*60;
    days = val2/one_day;
    val2 %= one_day;

    val1+=val2;
    while(val1>=one_day){
        val1-=one_day;
        days++;
    }

    string time_str = timeToStr(val1);
    if(days>0)
    time_str += ("+"+to_string(days)+" days");
    cout<<time_str;

    return 0;
}