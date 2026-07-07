class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& nums) {
        int ans=nums.size();
        int n = nums.size();

        for(int i=0; i<n; i++) {
            bool check = false;
            for(int j=0; j<n; j++) {
                if(i==j) continue;
                if(nums[j][0]<=nums[i][0] && nums[j][1]>=nums[i][1]) {
                    check=true; break;
                }
            }
            if(check) ans--;
        }
        return ans;
    }
};