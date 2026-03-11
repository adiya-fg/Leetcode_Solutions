class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        int ans=0;
        int pw = 1;
        while(n>0){
            if(n%2==0) ans+=pw;
            pw = pw*2;
            n/=2;
        }
        return ans;
    }
};