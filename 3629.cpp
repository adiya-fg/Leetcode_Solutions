class Solution {
public:
    bool isNotPrime[1000001] = {false};
    int minJumps(vector<int>& nums) {
        vector<int> prime;
        isNotPrime[1]=true;

        int smallesPrime[1000001];
        memset(smallesPrime,-1,sizeof(smallesPrime));

        smallesPrime[1]=1;
        for(int i=2; i<1000001; i+=2) {
            isNotPrime[i]=true;
            smallesPrime[i]=2;
        }

        isNotPrime[2]=false;
        for(int i=3; i<1000; i+=2) {
            if(isNotPrime[i]==false) {
                for(int j=i*i; j<1000000; j+=2*i) {
                    isNotPrime[j] = true;    
                    smallesPrime[j] = i;
                }
                smallesPrime[i] = i;
            }
        }

        for(int i=3; i<1000001; i+=2) {
            if(smallesPrime[i]==-1) {
                smallesPrime[i]=i;
            }
        }

        // for(int i=3; i<1000; i+=2)
        //     if(isNotPrime[i]==false)
        //         prime.push_back(i);

        int n = nums.size();
        queue<int>Q;
        Q.push(0);

        unordered_map<int,vector<int>> sets;

        for(int i=0; i<n; i++) {
            int node = nums[i];
            while(node>1) {
                int cur = smallesPrime[node];
                sets[cur].push_back(i);  
                while(node%cur==0) node/=cur;
            }
            if(node>1) {
              sets[node].push_back(i);  
            }
        }

        // for(int i=0; i<4; i++) {
        //     for(auto data : sets[i]) {
        //         cout<<data<<" : ";
        //     }
        //     cout<<endl;
        // }

        bool vis[1000001]={false};
        int path=0;

        while(!Q.empty()){
            int sz = Q.size();
            while(sz--) {
                int u = Q.front();
                Q.pop();
                if(u==n-1) return path;
                vis[u]=true;
                
                if(u>0 && vis[u-1]==false) {
                    Q.push(u-1);
                    vis[u-1]=true;
                }
                if(u<n-1 && vis[u+1]==false) { 
                    Q.push(u+1);
                    vis[u+1]=true;
                }

                if(isNotPrime[nums[u]]==false) {
                    for(auto val : sets[nums[u]]) {
                        if(vis[val]==false) {
                            Q.push(val);  
                            vis[val] = true;
                        }    
                    }
                    sets[nums[u]].clear();
                }
            }
            path++;
        }
        return -1;
    }   
};