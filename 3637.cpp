class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        vector<string> states;

        int n = nums.size();
        for(int i=1; i<n; i++) {
            if(nums[i]==nums[i-1]) return false;
            if(nums[i]<nums[i-1]) {
                if(states.size()>0 && states[states.size()-1]!='inc')
                    return false;
                if(states.size()==0) states.push_back('inc');
            } else {
                if(states.size()>0 && states[states.size()-1]!='desc')
                    return false;
                if(states.size()==0) states.push_back('desc');
            }
        }
        if(states.size()!=3) return false;
        if(states[0]==states[2] && states[0]=='inc' && states[1]=='desc') return true;
        else return false;
    }
};