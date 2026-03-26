class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        
        long long totalSum=0;

        for(auto &row: grid) {
            for(auto &col : row) {
                totalSum += col;
            }
        }

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<long long>> dp(n+1,vector<long long>(m+1,0));
        //dp[i][j]-store sum of all elements that lies in the rectangle (0,0) to (i,j);
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+grid[i-1][j-1];
                if(j==m || i==n) {
                    if((totalSum-dp[i][j])==dp[i][j]) {
                        return true;
                    }
                }
            }
        }

        // calculate the special case - one column or one row only.
        long long diffSum = 0;
        
        //row1
        diffSum = dp[1][m]-(totalSum-dp[1][m]);
        if(diffSum>0 && (grid[0][m-1]==diffSum || grid[0][0]==diffSum)) {
            return true;
        }
        //row n
        if(n>1) {
            diffSum = (totalSum-dp[n-1][m]) - dp[n-1][m];
            if(diffSum>0 && (grid[n-1][m-1]==diffSum || grid[n-1][0]==diffSum)) {
                return true;
            }            
        }

        //col1
        diffSum = dp[n][1] - (totalSum-dp[n][1]);
        if(diffSum>0 && (grid[0][0]==diffSum || grid[n-1][0]==diffSum)) {
            return true;
        }
        if(m>1){
            diffSum = (totalSum-dp[n][m-1])-dp[n][m-1];
            if(diffSum>0 && (grid[n-1][m-1]==diffSum || grid[0][m-1]==diffSum)) {
                return true;
            }
        }





        long long tempSum = 0;

        //only one row.
        if(n==1) {
           tempSum = 0;
            for(int j=1; j<=m; j++) {
                tempSum += grid[0][j-1];
                if( (totalSum-tempSum)==(tempSum-grid[0][0]) || (totalSum-tempSum)==(tempSum-grid[0][j-1]) )
                    return true;
            }    

           tempSum = 0;
            for(int j=m; j>=1; j--) {
                tempSum += grid[0][j-1];
                if( (totalSum-tempSum)==(tempSum-grid[0][m-1]) || (totalSum-tempSum)==(tempSum-grid[0][j-1]) )
                    return true;
            }  
        }

        //only one col.
        if(m==1) {
            tempSum = 0;
            for(int j=1; j<=n; j++) {
                tempSum += grid[j-1][0];
                if( (totalSum-tempSum)==(tempSum-grid[0][0]) || (totalSum-tempSum)==(tempSum-grid[j-1][0]) )
                    return true;
            }    

            tempSum = 0;
            for(int j=n; j>=1; j--) {
                tempSum += grid[j-1][0];
                if( (totalSum-tempSum)==(tempSum-grid[n-1][0]) || (totalSum-tempSum)==(tempSum-grid[j-1][0]) )
                    return true;
            }    
        }
        if(n==1 || m==1) return false;

        cout<<"i am here";

        // try to cut by column 
        unordered_set <long long> st; 
        //left to right
        for(int i=1; i<m; i++) {
            for(int j=1; j<=n; j++) {
                st.insert(grid[j-1][i-1]);
            }
            long long diff = dp[n][i]-(totalSum-dp[n][i]);
            if(diff<0) continue;
            if(i!=1 && st.find(diff)!=st.end()) {
                //cout<<"i found "<<diff<<endl;
                return true;
            }
        }
        //right to left
        st.clear();
        // try to cut by column
        for(int i=m; i>1; i--) {
            for(int j=1; j<=n; j++) {
                st.insert(grid[j-1][i-1]);
            }
            long long diff = (totalSum-dp[n][i-1])-dp[n][i-1];
            if(diff<0) continue;
            if(i!=m && st.find(diff)!=st.end()) {
                //cout<<"i found2 "<<diff<<endl;
                return true;
            }
        }

        cout<<"i am here 2"<<endl;

        // try to cut by row 
        st.clear();
        //left to right
        for(int i=1; i<n; i++) {
            for(int j=1; j<=m; j++) {
                st.insert(grid[i-1][j-1]);
            }
            long long diff = dp[i][m]-(totalSum-dp[i][m]);
            if(diff<0) continue;
            if(i!=1 && st.find(diff)!=st.end()) {
                return true;
            }
        }

        cout<<"i am here 3"<<endl;
        //right to left
        st.clear();
        // try to cut by column
        for(int i=n; i>1; i--) {
            for(int j=1; j<=m; j++) {
                st.insert(grid[i-1][j-1]);
            }
            long long diff = (totalSum-dp[i-1][m])-dp[i-1][m];
            if(diff<0) continue;
            if(i!=n && st.find(diff)!=st.end()) {
                 cout<<"i am here 4 "<<diff<<endl;
                return true;
            }
        }
        return false;
    }
};