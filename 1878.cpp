class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        
        vector<int> ans;

        set<int> st;

        int n = grid.size();
        int m = grid[0].size();

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                int sum = grid[i][j];
                st.insert(-sum);
                int left_col = j-1; 
                int right_col = j+1;
                int row = i-1;
                while(left_col>=0 && right_col<m && row>=0){
                    sum += grid[row][left_col];
                    sum += grid[row][right_col];
                    //check is there any rhombus
                    if(2*row>=i) {
                        int tempSum = 0;
                        int tempRow = row-1;
                        int tempL = left_col + 1;
                        int tempR = right_col - 1;
                        while(tempL<tempR){
                            tempSum += grid[tempRow][tempL++];
                            tempSum += grid[tempRow][tempR--];   
                            tempRow--;                        
                        }
                        tempSum += grid[tempRow][tempL];
                        st.insert(-1*(tempSum+sum));
                    }
                    left_col--;
                    right_col++;
                    row--;
                }
            }
        }

        int count=3;
        while(!st.empty() && count>0) {
            ans.push_back(-1*(*st.begin()));
            st.erase(st.begin());
            count--;
        }
        return ans;
    }
};