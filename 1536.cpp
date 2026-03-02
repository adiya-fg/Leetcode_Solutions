class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int res=-1;

        int n = grid.size();

        int mp[201];

        int rw=0;
        for(auto row_string : grid) {
            for(int i=n-1; i>=0; i--) {
                if(row_string[i]==1) {
                    mp[rw] = i;
                    break;
                }
            }
            rw++;
        }
        int total=0;
        for(int i=0; i<n; i++) {
            if(mp[i]>i) {
                //need some swap here
                bool check = false;
                for(int j=i+1; j<n; j++) {
                    if(mp[j]<=i) {
                        //shift it to ith position.
                        int index = j-1; 
                        while(index>=i) {
                            swap(mp[index],mp[index+1]);
                            total++;
                            index--;
                        }
                        check = true;
                        break;
                    }
                }
                if(!check) return -1;
            }
        }
        return total;
    }
};