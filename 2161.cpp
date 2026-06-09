class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
            vector<int> less;
            vector<int> more;
            int count=0;
            for(auto &val : nums) {
                if(val<pivot) less.push_back(val);
                if(val==pivot) count++;
                if(val>pivot) more.push_back(val);

            }          
            vector<int> ans;
            for(auto &val : less) {
                ans.push_back(val);
            } 
            while(count--) {
                ans.push_back(pivot);
            }
            for(auto &val : more) {
                ans.push_back(val);
            } 
            return ans;
    }
};