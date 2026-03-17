class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;

        vector<vector<int>> pos(n,vector<int>(m,-1));


        for(int i=0; i<m; i++) {
            int lastZero = n;
            for(int j=n-1; j>=0; j--) {
                if(matrix[j][i]==0) lastZero=j;
                else pos[j][i] = lastZero;
            }
        }

        for(int i=0; i<n; i++) {
            int mn = -1;
            vector<int> temp; temp.clear();
            for(int j=0; j<m; j++) {
                if(matrix[i][j]==1) {
                    int dis = pos[i][j] - i;
                    temp.push_back(temp);
                }
            }
            sort(temp.begin(),temp.end());
            for(int j=0; j<temp.size()-1; j++) {
                ans=max(ans,temp[j]*(temp.size()-i));
            }
        }

        return ans;
    }
};