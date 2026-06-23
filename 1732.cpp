class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int cur = 0;
        int mx = 0;
        for(int val : gain) {
            cur += val;
            mx=max(mx,cur);
        }
        return mx;
    }
};