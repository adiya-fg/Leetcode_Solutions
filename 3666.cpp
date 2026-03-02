class Solution {
public:
    int minOperations(string s, int k) {
        int res=-1;
        int n = s.size();
        int count1 = 0;
        for(int i=0; i<n; i++) {
            count1 += (s[i]=='1');
        }
        int count0 = n - count1;
        if(count0%k==0) return count0/k;

        // solve this problem with Djisktra Algorithm

        int z = count0;

        set<vector<int>> Q;
        Q.insert({0,z});

        //cout<<n<<" : "<<z<<endl;

        vector <bool> vis;
        vis.resize(n+1,false);
        
        while(!Q.empty()) {
            
            int steps = (*Q.begin())[0];
            int u = (*Q.begin())[1];
            if(u==0) return steps;
            if(vis[u]==true) {
                Q.erase(Q.begin()); 
                continue;
            }
            vis[u]=true;

            //cout<<u<<" : "<<steps<<endl;
            //create new connections
            int x2=min(k,u);
            int x1=max(0,k-n+u);
            for(int i=x1; i<=x2; i++) {
                int temp = (k+u-2*i);
                if(temp<0) break;
                if(temp<=n && vis[temp]==false) {
                    Q.insert({steps+1,temp});
                }
            }
            //erase already visited nodes

            while(!Q.empty() && vis[(*Q.begin())[1]]) {
                Q.erase(Q.begin());
            }
        }
        return  res;
    }
};


class Solution {
public:
    int minOperations(string s, int k) {
        int n = s.size();
        int zeros = 0;
        for (char c : s) zeros += (c == '0');

        if (zeros % k == 0) return zeros / k;

        vector<int> dist(n + 1, -1);
        queue<int> q;

        dist[zeros] = 0;
        q.push(zeros);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            if (u == 0) return dist[u];

            int i_min = k - (n - u);
            if(i_min<0) i_min = 0;
            int i_max = u;
            if(i_max>=k) i_max = k;

            for (int i = i_min; i <= i_max; i++) {
                int v = u + k - 2 * i;
                if (v >= 0 && v <= n && dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }

        return -1;
    }
};