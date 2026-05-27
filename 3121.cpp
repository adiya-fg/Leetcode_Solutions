class Solution {
public:
    int numberOfSpecialChars(string s) {
        vector<int> minIndex(26,-1), maxIndex(26,-1);    
        int n = s.size();
        //lower
        for(int i=0; i<n; i++) {
            if(s[i]<='Z') continue;
            //if(maxIndex[s[i]-'0']==-1)
                maxIndex[s[i]-'0']=i;    
        }
        //upper
        for(int i=0; i<n; i++) {
            if(s[i]>='a') continue;
            if(minIndex[s[i]-'0']==-1)
                minIndex[s[i]-'0']=i;    
        }
        int ans=0;
        for(int i=0; i<26; i++) {
            if(maxIndex[i]>minIndex[i] && minIndex[i]>=0) ans++;
        }
        return ans;
    }
};
