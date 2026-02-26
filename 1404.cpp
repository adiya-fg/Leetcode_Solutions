class Solution {
public:
    int numSteps(string s) {

        int count=0;
        while(s.size()>1){
            count++;
            if(s[s.size()-1]=='0') {
                //left shift 
                s = s.substr(0,s.size()-1);
            } else {
                bool found = false;
                for(int i=s.size()-1; i>=0; i--) {
                    if(s[i]=='0') {
                        s[i] = '1'; 
                        found = true;
                        break;
                    }
                    s[i] = ((s[i]-'0')^1) + '0';
                }
                if(!found) s = '1' + s;
            }
        }
        return count;
    }
};

///1010->10/2=5=101
//divide by 2 left shift by 1 if last bit is zero
//last bit is 1 -> 1000111110-find last 0 replace it with 1 but after this 
//1001->1010->then 101-> still recuding number of bits. So that we would be reach the 1 after these operations.
