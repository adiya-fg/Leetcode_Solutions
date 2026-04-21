class Solution {
public:


    int parent[100001];

    int findParent(int x) {
        if(x==parent[x]) return x;
        else return parent[x]=findParent(parent[x]);
    }

    int minimumHammingDistance(vector<int>& source, 
        vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int ans=0;
        int n = source.size();
        
        for(int i=0; i<n; i++) {
            parent[i] = i;
        }

        for(auto &nodes : allowedSwaps){
            int x = nodes[0];
            int y = nodes[1];
            int parent1 = findParent(x);
            int parent2 = findParent(y);
            if(parent1!=parent2) {
                parent[parent2] = parent1;
            }
        }

        unordered_map<int,unordered_map<int,int>> mp;

        for(int i=0; i<n; i++) {
            int parentI = findParent(i);
            mp[parentI][source[i]]++;
        }

        //create disjoint sets using union find
        for(int i=0; i<n; i++) {
            int p = findParent(i);
            if(mp[p][target[i]]>0) {
                mp[p][target[i]]--;
            } else ans++;
        }
        return ans;
    }
};