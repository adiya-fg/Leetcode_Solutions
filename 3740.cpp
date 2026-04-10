class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int ans = INT_MAX;
        int n = nums.size();

        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                for(int k=j+1; k<n; k++) {
                    if(nums[i]==nums[j] && nums[k]==nums[j]) {
                        int temp = (j-i)+(k-j)+(k-i);
                        ans = min(ans,temp);
                    }
                }
            }
        }

        return ((ans==INT_MAX) ? -1 : ans);
    }
};