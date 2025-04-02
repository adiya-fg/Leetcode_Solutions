class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans=0;

        int n=nums.size();

        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                for(int k=j+1; k<n; k++) {
                    ans=max(ans,(long long)(nums[i]-nums[j])*nums[k]);
                }    
            }
        }
 
        return ans;
    }
};

//best solution

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftMax(n), rightMax(n);
        for (int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i - 1], nums[i - 1]);
            rightMax[n - 1 - i] = max(rightMax[n - i], nums[n - i]);
        }
        long long res = 0;
        for (int j = 1; j < n - 1; j++) {
            res = max(res, (long long)(leftMax[j] - nums[j]) * rightMax[j]);
        }
        return res;
    }
};