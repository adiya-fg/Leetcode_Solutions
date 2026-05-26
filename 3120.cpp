class Solution {
public:
    int numberOfSpecialChars(string word) {
        
        //hash map
        unordered_set<int> map(word.begin(),word.end());

        int ans=0;
        for(int i='a'; i<='z'; i++) {
            if(map.count(i) && map.count(i-'a'+'A'))
                ans++;
        }
        return ans;
        
        //n=50
    }
};
