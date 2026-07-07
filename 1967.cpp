class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int ans=0;
        unordered_set<string> sets;
        for(auto val: patterns) {
            sets.insert(val);
        }
        unordered_set<string> found_str;
        //build all substrins from word.
        for(int i=0; i<word.size(); i++) {
            for(int j=1; j+i<=word.size(); j++) {
                string new_str = word.substr(i,j);
                if(sets.find(new_str)!=sets.end()) {
                    found_str.insert(new_str);
                }
            }
        }
        for(auto val: patterns) {
                if(found_str.find(val)!=found_str.end()) {
                    ans++;
                }
        }        
        return ans;   
    }
};