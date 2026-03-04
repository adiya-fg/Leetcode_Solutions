class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int ans=0;
        int n = mat.size();
        int m  = mat[0].size();

        vector<int> sumRow(n,0);
        vector<int> sumCol(m,0);

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                sumRow[i] += mat[i][j];
                sumCol[j] += mat[i][j];
            }
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(mat[i][j] && sumRow[i]+sumCol[j]==2) {
                    ans++;
                }
            }
        }
        return ans;
    }
};