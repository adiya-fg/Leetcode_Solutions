class Solution {
public:
    int mod = 1e9+7;
    vector<int> adj[100001];
    vector<long long > pw;

    // build a rooted from node 1.
    int dfs(int parent, int u) {

    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
       
        
        int n = edges.size();

        // crete connections
        for(auto nodes: edges) {
            adj[nodes[0]].push_back(nodes[1]);
            adj[nodes[1]].push_back(nodes[0]);
        }

        // create rooted tree
        dfs(0,1);

        // pre process
        pw.resize(n+1,0);
        pw[0]=1;
        for(int i=1; i<=n; i++) {
            pw[i] = (pw[i-1] * 2)%mod;
        }

        long long res=1;


        return res;
    }
};