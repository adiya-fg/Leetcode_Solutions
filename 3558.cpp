class Solution {
public:
    int mod = 1e9+7;
    vector<int> adj[100001];

    // finding maximum depth from the tree.
    int maxDepth(int parent, int u) {
        int res = 0;
        for(auto child: adj[u]) {
            if(child==parent) continue;
            res=max(res,(int)maxDepth(u,child));
        }
        return res+1;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
       
        
        int n = edges.size();

        auto calc = [&](long long  a, long long  b) {
            long long ans=a%mod;
            int pw = mod-2;
            while(pw){
                if(pw%2==1) {
                    ans = (ans*b)%mod;
                }
                b=(b*b)%mod;
                pw/=2;
            }    
            return ans;
        };

        for(auto nodes: edges) {
            adj[nodes[0]].push_back(nodes[1]);
            adj[nodes[1]].push_back(nodes[0]);
        }

        int path = maxDepth(0,1)-1;
        long long res=path;

        cout<<path<<endl;

        vector<long long> fact;
        fact.resize(n+1,1);

        for(int i=2; i<=n; i++) {
            fact[i] = (fact[i-1]*i)%mod;
        }

        for(int i=3; i<=path; i+=2) {
            long long a = fact[path];
            long long b = (fact[i]*fact[path-i])%mod;
            res = (res + calc(a,b))%mod;
        }

        return res;
    }
};