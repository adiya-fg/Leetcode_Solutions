class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum = 0;
        int n  = nums.size();
        int last_index = n-1;

        int prevF = 0;
        for(int i=0; i<n; i++) {
            prevF += i*nums[i];
            sum += nums[i];
        }
        int ans = prevF;

        for(int i=1; i<n; i++) {
            prevF -= (n-1)*nums[last_index];
            prevF += (sum - nums[last_index--]);
            ans = max(ans,prevF);
        }
        return ans;
    }
};