class Solution {
public:
    int maxNumberOfBalloons(string text) {
       int res=INT_MAX;

       string str = "balloon";
       vector<int> count(26,0);

       for(char chr : text) {
            count[chr-'a']++;
       }

       for(char chr : str) {
        res = min(res, count[chr-'a']);
        if(chr=='l' || chr=='o') {
            res = min(res, count[chr-'a']/2);    
        }
       }
       return res; 
    }
};