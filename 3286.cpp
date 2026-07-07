class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        
        // Implement dijkstra algorithm

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n,vector<int>(m,-1));
        int dx[4] = {-1,0,0,1};
        int dy[4] = {0,-1,1,0};
        

        set<vector<int>> Q;
        Q.insert({grid[0][0],0,0});
        dp[0][0]=grid[0][0];

        while(!Q.empty()){
            vector<int> node = (*Q.begin());
            Q.erase(Q.begin());
            for(int i=0; i<4; i++) {
                int newx = node[1] + dx[i];
                int newy = node[2] + dy[i];
                // check whether the point in the grid.
                if(newx>=0 && newx<n && newy>=0 && newy<m && (dp[newx][newy]==-1 || dp[newx][newy]>(node[0]+grid[newx][newy]))){
                    dp[newx][newy]=(node[0]+grid[newx][newy]);
                    Q.insert({(node[0]+grid[newx][newy]),newx,newy});  
                }
            }
        }

        //cout<<dp[n-1][m-1]<<endl;
        return (dp[n-1][m-1]<health);      
    }
};