class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int ans=0;

        set<int> eventSet, oddSet;
        int n = nums.size();

        for(int i=0; i<n; i++) {
            for(int j=i; j<n; j++) {
                if(nums[j]%2) odd.insert(nums[j]);
                else eventSet.insert(nums[j]);
                if(odd.size()==even.size()) {
                    ans = max(ans, j-i+1);
                }
            }
        }
        return ans;
    }
};