class Solution {
public:
    int findNext(int val, int digit, int start){
        int ans=-1;
        for(int i=start; i<=9; i++) {
            //first digit
            int temp = digit;
            bool check=true;
            int newVal=0;
            int newdigi=i;
            for(int j=1; j<=temp; j++) {
                newVal=newVal*10 + newdigi;
                if(newdigi>9) {
                    check=false; break;
                }
                newdigi++;
            }
            if(newVal>val && check && (ans==-1 || newVal<ans)) {
                ans = newVal;
            }
        }
        return ans;
    }
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;

        low--;
        while(true) {
            
            int numberofdigits = 0;
            int val=low;
            int last=0;
            while(val>0){ numberofdigits ++; last=val; val/=10; }

            val = findNext(low,numberofdigits,last);
            if(val==-1) {
                //not found
                val = findNext(low,numberofdigits+1,1);
            }
            if(val==-1) break;
            cout<<low<<endl;
            if(val>high) break;
            else {
                ans.push_back(val);
                low = val;
            }
        }
        return ans;
    }
};