
class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        int mn = n;

        // sort
        sort(nums.begin(),nums.end());

        if(n<2) return 0;

        // iterate through the list
        for(int i=1; i<n; i++) {
            // find lower bound for this index
            //lower_bound(nums.begin(),num)
            // nums[j]*m<num[i]
            int l = 0, r = i-1;
            while(l<=r){
                int mid =(l+r)/2;
                if(1LL*nums[mid]*k >= nums[i]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            if(r<0 || 1LL*nums[r]*k<nums[i]) {
                r++;
            }
            mn = min(mn, (n - i - 1) + r);
           // cout<<i<<" : "<<r<<" "<<mn<<endl;
        }
        return mn;
    }
};
//1629
//1269

class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int ans = n, right = 0;
        for (int left = 0; left < n; ++left) {
            while (right < n &&
                   nums[right] <= static_cast<long long>(nums[left]) * k) {
                ++right;
            }
            ans = min(ans, n - (right - left));
        }

        return ans;
    }
};