class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> vals;
        // for(auto &data: nums1)
        //     vals.insert(data);
        vals.insert(nums1.begin(),nums1.end());
        for(auto &data : nums2){
            if(vals.find(data)!=vals.end()) {
                return data;
            }
        }
        return -1;
    }
};