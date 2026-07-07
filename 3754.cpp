class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum = 0;
        long long x = 0;
        long long pw = 1;
        while(n > 0){
            int digit = n%10;
            if(digit>0) {
                x = digit*pw + x;
                sum += digit;
                pw *= 10;
            }    
            n /= 10;
        }
        return sum*x;
    }
};