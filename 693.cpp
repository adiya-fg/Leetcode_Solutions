class Solution {
public:
    bool hasAlternatingBits(int n) {
        int lastBit = -1;
        while(n>0){
            if(lastBit==n%2) return false;
            lastBit=n%2;
            n/=2;
        }
        return true;
    }
};