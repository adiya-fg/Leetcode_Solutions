class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int ans=0;
        int n = nums.size();

        for(int i=0; i<n; i++) {
            int count = 0;
            int total = 0;
            for(int j=i; j>=0; j--) {
                if(nums[j]==target) count++;
                total++;
                if(total/2<count) {
                    ans++;
                }
            }
        }
        return ans;
    }
};