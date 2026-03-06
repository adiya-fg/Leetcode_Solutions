class Solution {
public:
    bool checkOnesSegment(string s) {
        
        int n = s.size();
        int count=(s[0]=='1');

        for(int i=1; i<n; i++){
            if(s[i]=='1' && s[i-1]=='0') {
                count++;
            }
        }
        return (count<=1);
    }
};