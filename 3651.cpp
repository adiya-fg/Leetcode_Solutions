class Solution {
public:
    vector<int> temp;
    int totalWaviness(int num1, int num2) {
        int ans=0;
        for(int i=num1; i<=num2; i++) {
            int val = i;
            temp.clear();
            while(val>0) {
                temp.push_back(val%10);
                if(temp.size()>2) {
                    int n = temp.size();
                    if((temp[n-2]>temp[n-3] && temp[n-2]>temp[n-1]) || (temp[n-2]<temp[n-3] && temp[n-2]<temp[n-1])) ans++;
                }
                val/=10;
            }
        }
        return ans;
    }
};