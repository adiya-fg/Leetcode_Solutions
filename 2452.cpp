class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        
        unordered_set<string> mp; 

        // pre process
        for(auto&str : dictionary){
            mp.insert(str);
            //mask a char
            int n = str.size();
            for(int i=0; i<n; i++) {
                int temp = str[i];
                str[i] = '*';
                mp.insert(str);
                str[i] = temp;
            }
            //mask two chars
            for(int i=0; i<n; i++) {
                for(int j=i+1; j<n; j++) {
                    int temp = str[i];
                    int last = str[j];
                    str[i] = '*';
                    str[j] = '*';
                    mp.insert(str);
                    str[i] = temp;
                    str[j] = last;
                }
            }
        }

        vector<string> ans;

        for(auto&str : queries){
            if(mp.find(str)!=mp.end()) {
                ans.push_back(str); continue;
            }
            bool findStr = false;
            //mask a char
            int n = str.size();
            for(int i=0; i<n; i++) {
                string prev = str;
                int temp = str[i];
                str[i] = '*';
                if(mp.find(str)!=mp.end()) {
                    ans.push_back(prev); 
                    findStr = true;
                    break;
                }
                str[i] = temp;
            }
            if(findStr) continue;
            //mask two chars
            for(int i=0; i<n; i++) {
                for(int j=i+1; j<n; j++) {
                    string prev = str;
                    int temp = str[i];
                    int last = str[j];
                    str[i] = '*';
                    str[j] = '*';
                    if(mp.find(str)!=mp.end()) {
                        ans.push_back(prev); 
                        findStr = true;
                        break;
                    }
                    str[i] = temp;
                    str[j] = last;
                }
                if(findStr) break;
            }
        }
        return ans;
    } 
};