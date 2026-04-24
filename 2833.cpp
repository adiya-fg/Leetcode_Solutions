class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int ans=0;


        int countL = 0;
        int countR = 0;
        int countUnder=0;

        for(auto &chr: moves) {
            if(chr=='L') countL++;
            else {
                if(chr=='R') countR++;
                else countUnder++;
            }
        }

        ans = countUnder + max(countL,countR)-min(countL,countR);
        return ans;
    }
};