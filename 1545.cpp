class Solution {
public:
    int dfs(int k) {
        if(k==0) return 1;
        if(k==1) return 0;
        //find nearest 2^n to k
        int target=0;
        for(int i=0; i<20; i++) {
            if(pow(2,i)>k) {
                target = i-1;
                break;
            }    
        }
        if (pow(2,target)==k) return 1;
        else return dfs(pow(2,target) - (k- pow(2,target)))^1;
    }

    char findKthBit(int n, int k) {
        return dfs(k) + '0';
    }
};