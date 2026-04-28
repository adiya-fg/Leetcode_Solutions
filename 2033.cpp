class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        
        vector <int> nums;
        if(grid.size()==1 && grid[0].size()==1) return 0;

        auto checkPossibilty = [&]() -> bool {
            int diff;
            int min_val = grid[0][0];
            for(auto &nodes : grid) {
                for(auto &val : nodes){
                    diff = abs(val-min_val);
                    nums.push_back(val);
                    if(diff%x!=0) return false;
                }
            }
            return true;
        };


        if(checkPossibilty()==false) return -1;

        // sort
        sort(nums.begin(),nums.end());

        int n = nums.size();
        vector<int> sum;
        sum.resize(n,0);
        sum[0]=nums[0];
        for(int i=1; i<n; i++) {
            sum[i] = sum[i-1]+nums[i];
        }

        int ans = INT_MAX;

        for(int i=0; i<n; i++) {
            int diff1 = (i+1)*nums[i] - sum[i];
            diff1/=x;
            int diff2 = (sum[n-1]  - sum[i]) - (n - i - 1)*nums[i];
            diff2/=x;
            ans=min(ans,diff1+diff2);
        }       

        return ans;
    }
};