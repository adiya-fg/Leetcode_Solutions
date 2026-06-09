class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long mx=nums[0];
        long long mn = nums[0];    
        for(auto &val : nums){
            mn = min(mn,val);
            mx = max(mx,val);
        }
        return (long long)(k*(mx-mn));
    }
};