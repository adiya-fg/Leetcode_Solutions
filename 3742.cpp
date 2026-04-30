class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n,vector<bool>(m,false));
        vector<vector<int>> dp(n,vector<int>(m,-1));

        priority_queue<vector<int>> Q;

        Q.push({grid[0][0],-1*(grid[0][0]!=0),0});
        vis[0][0]=true;
        int maxScore = INT_MIN;
        dp[0][0]=(grid[0][0]!=0);

        while(!Q.empty()){
            vector<int> frontVal = Q.top();
            int x = frontVal[2]/m;
            int y = frontVal[2]%m;
            int score = frontVal[0];
            int cost = -1*frontVal[1];
            if(dp[x][y]==-1 || cost<dp[x][y])
                dp[x][y] = cost;
            if(x==n-1 && y==m-1) {
                maxScore=max(maxScore,score);
            }
            Q.pop();
            if(x+1<n && ((grid[x+1][y]!=0)+cost)<=k) {
                //dp[x+1][y]=(grid[x+1][y]!=0)+cost;
                Q.push({score+grid[x+1][y],-1*((grid[x+1][y]!=0)+cost),(x+1)*m+y});
                //vis[x+1][y]=true;
            } else {
                
            }

            if(y+1<m && (dp[x][y+1]==-1 || dp[x][y+1]>((grid[x][y+1]!=0)+cost)) && ((grid[x][y+1]!=0)+cost)<=k) {
                //dp[x][y+1]=(grid[x][y+1]!=0)+cost;
                Q.push({score+grid[x][y+1],-1*((grid[x][y+1]!=0)+cost),x*m+y+1});
                //vis[x][y+1]=true;
            }
        }
        return ((maxScore==INT_MIN) ? -1 : maxScore);
    }
};