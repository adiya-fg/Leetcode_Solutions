#define mod 12345

class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        vector<vector<int>> ans;
        
        int n = grid.size();
        int m = grid[0].size();

        vector<int> suffix(n*m+1,1);

        for(int i=n-1; i>=0; i--) {
            for(int j=m-1; j>=0; j--) {
                int index = i*m + j;
                grid[i][j]%=mod;
                suffix[index]=(1LL*suffix[index+1]*grid[i][j])%mod;
            }
        }

        int mul = 1;
        for(int i=0; i<n; i++) {
            vector<int> temp;
            for(int j=0; j<m; j++) {
                int index = i*m + j;
                temp.push_back((1LL*suffix[index+1]*mul)%mod);
                mul=(1LL*mul*grid[i][j])%mod;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};