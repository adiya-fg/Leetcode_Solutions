class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for(auto & val : nums) {
            vector<int> temp;
            while(val){
                temp.push_back(val%10);
                val/=10;
            }
            reverse(temp.begin(),temp.end());
            for(auto data : temp)
                ans.push_back(data);

        }
        return ans;
    }
};