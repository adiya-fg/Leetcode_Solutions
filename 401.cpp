class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> res;
        
        for(int i=0; i<12; i++) {
            for(int j=0; j<60; j++) {
                //count total bits
                int count = 0;
                int val = i;
                while(val>0) {
                    count+=(val%2==1);
                    val/=2;
                }
                val = j;
                while(val>0) {
                    count+=(val%2==1);
                    val/=2;
                }
                if(count==turnedOn) {
                    string tempAns = to_string(i)+":";
                    if(j<10) tempAns += "0";
                    tempAns += to_string(j);
                    res.push_back(tempAns);
                }
            }
        }

        return res;
    }
};