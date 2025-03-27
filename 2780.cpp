class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int res=0, count=0, target=0;

        unordered_map<int,int> mp;
        
        for(auto &val : nums){
            mp[val]++;
            if(mp[val]>count) {
                target = val;
                count = mp[val];
            }
        }
        
        mp.clear();

        int mid = target;
        for(auto &val : nums){
            mp[val]++;
            
            int prefixSize = res + 1;
            int suffixSize = nums.size()-prefixSize;

            if(mp[mid]>prefixSize/2 && (count-mp[mid])>suffixSize/2){
                return res;
            }
            res++;
        }

        return -1;
    }
};


class Solution {
public:
    int minimumIndex(std::vector<int>& nums) {
        std::unordered_map<int, int> frequencyMap;
        int dominantElement = 0;
        int dominantCount = 0;

        // Find the dominant element (most frequent) in the entire array.
        for (int num : nums) {
            frequencyMap[num]++;
            if (frequencyMap[num] > dominantCount) {
                dominantCount = frequencyMap[num];
                dominantElement = num;
            }
        }

        frequencyMap.clear();
        int prefixDominantCount = 0;

        // Iterate through the array to find the splitting index.
        for (int i = 0; i < nums.size(); ++i) {
            frequencyMap[nums[i]]++;
            if (nums[i] == dominantElement) {
                prefixDominantCount++;
            }

            int prefixSize = i + 1;
            int suffixSize = nums.size() - prefixSize;

            // Check if the dominant element is dominant in both prefix and suffix.
            if (prefixDominantCount > prefixSize / 2 && 
                (dominantCount - prefixDominantCount) > suffixSize / 2) {
                return i;
            }
        }

        return -1; // No such index found.
    }
};