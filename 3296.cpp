class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long ans=0;
        long long  s = 0, f = 10000000000000000;
        while(s<=f){
            long long mid = (s+f)/2LL;
            //mid -it upper bound.
            long long  sum = 0;
            for(auto &val : workerTimes) {
                long long temp = (2LL*mid/(long long)val);
                //long long k = (-1.0 + sqrt(1 + work * 8)) / 2 + eps;
                long long x = (long long)sqrt(temp);
                while((x*(x+1))>temp) x--;
                sum += x;
            }
            if(sum < mountainHeight) s = mid + 1;
            else{
                ans = mid;
                f = mid - 1;
            }
        }
        return ans;
    }
};