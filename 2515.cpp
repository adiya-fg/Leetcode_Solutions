class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int ans=INT_MAX;

        for(int i=0; i<words.size(); i++) {
            if(words[i]==target) {
                if(startIndex>=i) {
                    ans = min(ans,min(startIndex-i,(int)words.size()-startIndex+i));
                } else {
                    ans = min(ans,min(i-startIndex,(int)words.size()-i+startIndex));
                }
            }
        }



        return ((ans==INT_MAX) ? -1 : ans);
    }
};