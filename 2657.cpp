class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& a, vector<int>& b) {
        vector<int> ans;
        
        unordered_map<int,int> counter;
        int curCount=0;

        int n = a.size();

        for(int i=0; i<n; i++) {
           counter[a[i]]++;
           if(counter[a[i]]==2) curCount++;
           counter[b[i]]++; 
           if(counter[b[i]]==2) curCount++;
           ans.push_back(curCount);
        }
        return ans;

    }
};