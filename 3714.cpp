class Solution {
public:
    int findMax(string s, int type) {
        //cout<<s<<endl;
        int ans=0;
        int count[3];
        int n = s.size();
        memset(count,0,sizeof(count));

        unordered_map <int,int> dic;

        dic.clear();

        dic[0]=-1;

        for(int i=0; i<n; i++) {
            //cout<<ans<<" header "<<endl;
            count[s[i]-'a']++;
            //a,b
            int diff1 = count[0]-count[1];
            if(type==1 && dic.find(diff1)!=dic.end()) {
                ans = max(ans,i-dic[diff1]);
                //cout<<ans<<" here1 "<<diff1<<" :: "<<dic[diff1]<<endl;
            }
            //b,c
            int diff2 = count[1]-count[2];
            if(type==2 && dic.find(diff2)!=dic.end()) {
                ans = max(ans,i-dic[diff2]);
                //cout<<ans<<" here2 "<<diff2<<endl;
            }
            //a,c
            int diff3 = count[0]-count[2];
            if(type==3 && dic.find(diff3)!=dic.end()) {
                ans = max(ans,i-dic[diff3]);
            }
            //update
            if(type==1 && dic.find(diff1)==dic.end()) {
                dic[count[0]-count[1]] = i;
            }
            if(type==2 && dic.find(diff2)==dic.end()) {
                dic[count[1]-count[2]] = i;
            }
            if(type==3 && dic.find(diff3)==dic.end()) {
                dic[count[0]-count[2]] = i;
            }
            //cout<<ans<<" "<<diff3<<" : "<<dic[count[1]-count[2]]<<endl;
        }
        //cout<<endl;
        return ans;
    }

    int longestBalanced(string s) {
        
        int ans = 1;

        // case 1: longest balance string consists of only character.
        int last = 0;
        int n = s.size();
        for(int i=1; i<n; i++) {
            if(s[last]!=s[i]) {
                ans = max(i-last,ans);
                last = i;
            }
        }
        ans = max(ans,n-last);
        // cout<<ans<<endl;
        // case 2: longest balance string consists of two character.
        // use prefix count.
        //ab
        //"cbabccbccb"
        string temp="";
        for(int i=0; i<n; i++) {
            if(s[i]!='c') temp += s[i];
            if((s[i]=='c' && temp.size()>0) || i==n-1) {
                ans=max(findMax(temp,1),ans);
                temp="";
            }
        }       
        //ac
       temp="";
        for(int i=0; i<n; i++) {
            if(s[i]!='b') temp += s[i];
            if((s[i]=='b' && temp.size()>0) || i==n-1) {
                ans=max(findMax(temp,3),ans);
                temp="";
            }
        }    
        //bc
         temp="";
        for(int i=0; i<n; i++) {
            if(s[i]!='a') temp += s[i];
            if((s[i]=='a' && temp.size()>0) || i==n-1) {
                ans=max(findMax(temp,2),ans);
                temp="";
            }
        }    

        // case 3: all charactes included int the substring
        ///
        map<pair<int,int>,int> allDict;
        allDict[make_pair(0,0)]=-1;
        int count[3];
        memset(count,0,sizeof(count));
        cout<<ans<<" here "<<endl;
        for(int i=0; i<n; i++) {
            count[s[i]-'a']++;
            if(allDict.find(make_pair(count[1]-count[0],count[2]-count[0]))!=allDict.end()) {
                ans=max(i-allDict[make_pair(count[1]-count[0],count[2]-count[0])],ans);
            }
            //update
            if(allDict.find(make_pair(count[1]-count[0],count[2]-count[0]))==allDict.end()) {
                allDict[make_pair(count[1]-count[0],count[2]-count[0])]=i;
            }
        }    
        return ans;
    }
};
//ababc