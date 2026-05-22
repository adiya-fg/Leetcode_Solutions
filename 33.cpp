class Solution {
public:
    int search(vector<int>& nums, int target) {
        int index=0;
        for(auto val : nums) {
            if(val==target) return index;
            index++;
        }
        return -1;
    }
};