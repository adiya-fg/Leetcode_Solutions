
class Solution {
public:
    int minJumps(vector<int>& arr) {
        int ans=0;
        int n = arr.size();

        unordered_map<int,vector<int>> sets;
        vector<bool> vis(n,false);

        int index=0;
        for(auto val : arr) {
            sets[val].push_back(index);
            index++;
        }


        queue<int> Q;

        vis[0]=true;
        Q.push(0);

        while(!Q.empty()){
            int total = Q.size();
            while(total--) {
                int frontElem = Q.front();
                Q.pop();
                if(frontElem==n-1) return ans;
                int newNode = frontElem-1;
                if(newNode>=0 && newNode<n && !vis[newNode]) {
                    Q.push(newNode);
                    vis[newNode]=true;
                }
                newNode = frontElem+1;
                if(newNode>=0 && newNode<n && !vis[newNode]) {
                    Q.push(newNode);
                    vis[newNode]=true;
                }
                for(int i=0; i<sets[arr[frontElem]].size(); i++) {
                    newNode = sets[arr[frontElem]][i];
                    if(newNode==frontElem) continue;
                    if(!vis[newNode]) {
                        Q.push(newNode);
                        vis[newNode]=true;
                    }                    
                }
                sets[arr[frontElem]].clear();
            }
            ans++;
        }

        return ans;
    }
};