class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int ans=0;
        
        vector<int> vals;
        vals=nums;

        while(true) {
            bool temp = true;
            int idx = 0;
            int sum = INT_MAX;
            for(int i=1; i<vals.size(); i++) {
                if(vals[i-1]>vals[i]) {
                    temp = false;
                }
                if((vals[i]+vals[i-1])<sum) {
                    idx = i-1;
                    sum = (vals[i]+vals[i-1]);
                }
            }

            if(temp) break;
            ans++;
            //cout<<sum<<" "<<idx<<" "<<vals.size()<<endl;
            vector<int> updated; updated.clear();
            for(int i=0; i<idx; i++)
                updated.push_back(vals[i]);
            updated.push_back(vals[idx]+vals[idx+1]);
            for(int i=idx+2; i<vals.size(); i++)
                updated.push_back(vals[i]);  
            vals.clear();                  
            vals = updated;
        }
        return ans;
    }
};