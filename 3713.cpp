class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int ans=0;
        int char_count[26];

        for(int i=0; i<n; i++) {
            memset(char_count,0,sizeof(char_count));
            for(int j=i; j<n; j++) {
                char_count[s[j]-'a']++;
                // check whether exits the balanced substring.
                int target=char_count[s[j]-'a'];
                bool check=true;
                for(int k=0; k<26; k++) {
                    if(char_count[k]>0 && char_count[k]!=target) {
                        check=false; break;
                    }
                }
                if(check) {
                    ans = max(ans,j-i+1);
                }
            }
        }
        return ans;
    }
};