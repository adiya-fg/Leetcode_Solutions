class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        
        vector<vector<int>> prevMat = mat;
        
        int n = mat.size();
        int m = mat[0].size();
        /// we need to shift matrix and check

        k = k%m;

        int tempVal;

        while(k--) {
            for(int i=0; i<n; i++) {
                if(i%2==0) {
                    tempVal = mat[i][0];
                    for(int j=0; j<m-1; j++) {
                        mat[i][j]=mat[i][j+1];
                    }
                    mat[i][m-1] = tempVal;
                } else {
                    tempVal = mat[i][m-1];
                    for(int j=m-1; j>0; j--) {
                        mat[i][j]=mat[i][j-1];
                    }
                    mat[i][0] = tempVal;                    
                }
            }
        }   
        for(int i=0; i<n; i++) {
            for(int j=0; j<m-1; j++) {
                if(mat[i][j]!=prevMat[i][j]) return false;
            }
        }       
        return true;
    }   
};