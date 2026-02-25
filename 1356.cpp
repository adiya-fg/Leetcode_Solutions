class Solution {
public:

    static countOne(int val) {
        int res=0;
        while(val>0) {
            res += val%2;
            val/=2;
        }
        return res;
    }

    static cmp(int x, int y) {
        int countX=countOne(x);
        int countY=countOne(y);
        if(countX==countY) return (x<=y);
        else return (countX<countY);
    }

    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),cmp);    
        return arr;
    }
};