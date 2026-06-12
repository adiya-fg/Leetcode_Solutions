class Solution {
public:
    int MX = 17;
    int mod = 1e9+7;
    int level[100001];
    vector <int> adj[100001];
    int dp[100001][17];
    vector <long long > pw;

    // build a rooted from node 1.
    void dfs(int parent, int u, int height) {
        dp[u][0]=parent;
        level[u]=height;
        for(auto &node : adj[u]) {
            if(node==parent) continue;
            dfs(u,node,height+1);
        }
    }

    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
       
        int n = edges.size()+1;

        // create connections
        for(auto nodes: edges) {
            adj[nodes[0]].push_back(nodes[1]);
            adj[nodes[1]].push_back(nodes[0]);
        }

        // create rooted tree
        memset(dp,-1,sizeof(dp));
        dfs(0,1,1);

        //build sparse table 
        for(int i=1; i<MX; i++) {
            for(int j=1; j<=n; j++) {
                int u = dp[j][i-1];
                if(u!=-1 && dp[u][i-1]!=-1)
                    dp[j][i] = dp[u][i-1]; 
            }
        }

        // pre process
        pw.resize(n+1,0);
        pw[1]=1;
        for(int i=2; i<=n; i++) {
            pw[i] = (pw[i-1] * 2)%mod;
            //cout<<i<<" :  "<<level[i]<<endl;
        }

        vector<int> res;
        for(auto q: queries) {
            int l = q[0];
            int r = q[1];
            //cout<<l<<" : "<<r<<" : ";
            
            if(level[r]<level[l])
                swap(l,r);

            //calculate length of the path between these nodes. 
            int path = 0;
            //equalize level of these nodes.
            for(int i=MX-1; i>=0; i--) {
                if(dp[r][i]!=-1 && level[dp[r][i]]>=level[l]) {
                    r = dp[r][i];
                    path += (1<<i);
                    //cout<<" entering "<<i<<" ";
                }
            }
            //if they did not meet yet.
            if(l!=r) {
                for(int i=MX-1; i>=0; i--) {
                    if(dp[r][i]!=-1 && dp[l][i]!=-1 && dp[r][i]!=dp[l][i]) {
                        r = dp[r][i];
                        l = dp[l][i];
                        path += (1<<(i+1));
                    }
                }         
                // they would meet just after one move respectively.      
                path += 2;
                //cout<<" here ";
            }
            //cout<<path<<endl;
            if(path<n) 
                res.push_back(pw[path]);
            else 
                res.push_back(-1);
        }

        return res;
    }
};