class Solution {
public:
    int reverseBits(int n) {
       int ans=0;
       
       for(int i=0; i<32; i++) {
            if((1<<i)&n) {
                ans += pow(2,32-i-1);
            }
       }

       return ans;
    }
};