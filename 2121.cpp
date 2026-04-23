class Solution {
public:

    vector<long long> helperFunction(vector<int>& nums) {
        vector<long long> sum;
        unordered_map<int,int> mp; 
        unordered_map<int,int> lastOccurence;
        sum.resize(nums.size(),0);
        for(int i=0; i<nums.size(); i++) {
            if(mp[nums[i]]>0) {
                sum[i] = sum[lastOccurence[nums[i]]] + 1LL*mp[nums[i]]*(i-lastOccurence[nums[i]]);
            }
            lastOccurence[nums[i]] = i;
            mp[nums[i]]++;
        }
        return sum;
    }

    vector<long long> getDistances(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ans;
        ans.resize(n,0);
        ans = helperFunction(nums);
        reverse(nums.begin(),nums.end());
        vector<long long> temp = helperFunction(nums);
        reverse(temp.begin(),temp.end());
        for(int i=0; i<n; i++) {
            ans[i] += temp[i];
        }
        return ans;
    }
};