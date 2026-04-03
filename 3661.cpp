class Solution {
public:
    vector<int> walls;

    int findWalls(int l, int r) {
        if(l>r) swap(l,r);
        int st = 0, fin = walls.size()-1;
        while(st<=fin){
            int mid = (st+fin)>>1;
            if(walls[mid]<l) 
                st = mid + 1;
            else 
                fin = mid - 1;
        }
        int leftIndex = st;
        st = 0, fin = walls.size()-1;
        while(st<=fin){
            int mid = (st+fin)>>1;
            if(walls[mid]>r) 
                fin = mid - 1;
            else 
                st = mid + 1;
        }           
        int rightIndex = fin;
        return ((rightIndex<leftIndex) ? 0 : rightIndex-leftIndex+1);
    };

    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls_input) {
        int ans=0;
        int n = robots.size();
        vector<int> indices(n,0);

        vector<vector<int>> dp(n,vector<int>(2,0));

        for(int i=0; i<n; i++) {
            indices[i]=i;
        }

        sort(indices.begin(),indices.end(),[&](int &x, int &y){
            return (robots[x]<robots[y]);
        });

        // testing 
        // for(int i=0; i<n; i++) {
        //     cout<<indices[i]<<" ";
        // }

        walls = walls_input;
        sort(walls.begin(),walls.end());

        //fire left
        dp[0][0]=findWalls(robots[indices[0]],robots[indices[0]]-distance[indices[0]]);
        //fire right
        if(n>1)
            dp[0][1]=findWalls(robots[indices[0]],min(robots[indices[0]]+distance[indices[0]],robots[indices[1]]-1));
        else 
            dp[0][1]=findWalls(robots[indices[0]],robots[indices[0]]+distance[indices[0]]);

        for(int i=1; i<n; i++) {
            dp[i][0] = dp[i-1][0] + 
                findWalls(robots[indices[i]],max(robots[indices[i]]-distance[indices[i]],robots[indices[i-1]]+1));
            if(robots[indices[i-1]]+distance[indices[i-1]]+1<=robots[indices[i]])
                dp[i][0] = max(dp[i][0],dp[i-1][1] + findWalls(robots[indices[i]],max(robots[indices[i]]-distance[indices[i]],
                    robots[indices[i-1]]+distance[indices[i-1]]+1)));

            if(i<n-1)
                dp[i][1] = max(dp[i-1][0],dp[i-1][1])+findWalls(robots[indices[i]],min(robots[indices[i]]+distance[indices[i]],robots[indices[i+1]]-1));
            else 
                dp[i][1] = max(dp[i-1][0],dp[i-1][1])+findWalls(robots[indices[i]],robots[indices[i]]+distance[indices[i]]);
                     
        }

        return max(dp[n-1][0],dp[n-1][1]);
    }
};