class Solution {
public:
    int countBinarySubstrings(string s) {
        int res=0;

        int n = s.size();
        vector<vector<int>> last_occur(n+1, vector<int>(2,0));

        for(int i=1; i<=n; i++) {
            int cur = s[i-1]-'0';
            if(last_occur[i-1][cur^1]>0) {
                //might be a possible substring
                int len = i - last_occur[i-1][cur^1]; 
                int sub_len = (i-len) - last_occur[i-len][cur];
                if(sub_len>=len) {
                    res++;
                }
            }  
            last_occur[i][cur] = i;
            last_occur[i][cur^1] = last_occur[i-1][cur^1]; 
            //cout<<i<<" : "<<res<<endl;
        }
        return res;
    }
};