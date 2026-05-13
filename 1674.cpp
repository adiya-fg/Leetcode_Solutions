class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {

        if(nums.size()<=2) return 0;
        
        int ans =  INT_MAX;
        int n = nums.size();
        int total = n/2;

        vector<int> maxVal, minVal,vals;

        unordered_map<int,int> mp;

        for(int i=0; i<n/2; i++) {
            int diff = nums[i] + nums[n-i-1];
            mp[diff]++;
            int increasedVal = max(nums[i],nums[n-i-1]) + limit;
            if(min(nums[i],nums[n-i-1])<limit)
                maxVal.push_back(increasedVal);
            int decreasedVal = min(nums[i],nums[n-i-1]) + 1;
            if(max(nums[i],nums[n-i-1])>1)
                minVal.push_back(decreasedVal);
            vals.push_back(diff);
        }

            //sort
        sort(maxVal.begin(),maxVal.end());
        sort(minVal.begin(),minVal.end());
        
        n = n/2;
        for(int i=0; i<=100000; i++) {
            //total operations for one step move
            int tempAns = total - mp[i];
            //calculate number of operations that needed for the two steps movements.
            int s = 0, f = minVal.size()-1;
            while(s<=f){
                int mid = (s+f)>>1;
                if(minVal[mid]<=i)
                    s = mid+1;
                else
                    f = mid -1;
            }
            tempAns += (minVal.size()-s);
            s = 0, f = maxVal.size()-1;
            while(s<=f){
                int mid = (s+f)>>1;
                if(maxVal[mid]>=i)
                    f = mid-1;
                else
                    s = mid+1;
            }  
            tempAns += (f+1);      
            ans = min(ans,tempAns);   
        }


        return ans;
    }
};