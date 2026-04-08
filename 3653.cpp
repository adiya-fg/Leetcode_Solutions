#define mod 1000000007

class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        
        int ans=0;

        for(auto &q : queries) {
            
            int li = q[0];
            int ri = q[1];
            int ki = q[2];
            int vi = q[3];
            int idx = li;

            while(idx<=ri){
                nums[idx] = (1LL * nums[idx] * vi) % mod;
                idx += ki;
            }
        }

        for(auto &val : nums) {
            ans=ans^val;
        }

        return ans;
    }
};