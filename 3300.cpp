class Solution {
public:
    int minElement(vector<int>& nums) {
       int ans = INT_MAX;
       for(int i=0; i<nums.size(); i++){
           int temp = 0;
           while(nums[i] > 0) {
                temp += nums[i] % 10;
                nums[i] /= 10;
           }
           ans = min(ans, temp);
       }   
        return ans;
    }
};