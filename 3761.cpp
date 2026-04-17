class Solution {
public:

    int reverseNumber(int val){
        int res=0;
        while(val){
            res = res*10 + val%10;
            val/=10;
        }
        return res;
    }

    int findMinVal(vector<int>& nums){
       int ans=INT_MAX;
       unordered_map<int,int>mp;

       mp.clear();

       mp[nums[nums.size()-1]]=nums.size()-1;
       for(int i=nums.size()-2; i>=0; i--) {
            int val = reverseNumber(nums[i]);
            if(mp.find(val)!=mp.end()) {
                ans = min(ans,mp[val]-i);
            }
            mp[nums[i]] = i;
       }
       return ans;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        int ans=INT_MAX;
        ///reverse(nums.begin(),nums.begin());
        ans=min(ans,findMinVal(nums));
        return ((INT_MAX==ans) ? -1 : ans);
    }
};