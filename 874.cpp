class Solution {
public:

    //directions

    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};

    int changeDir(int current, int newDir){
        //turn right
        if(newDir==1){
            return (current+1)%4;
        } else 
            return (current-1+4)%4;
    }
    
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {

        map<pair<int,int>,bool> mp;
        
        for(auto &points : obstacles) {
            mp[make_pair(points[0],points[1])]=true;
        }
        
        int ans = 0;
        int index = 0;

        int curX = 0;
        int curY = 0;
        int curDir = 0; //facing north.

        while(index<commands.size()){
            if(commands[index]==-2) {
                curDir = changeDir(curDir,-1);
                index++;
                continue;
            }
            if(commands[index]==-1) {
                curDir = changeDir(curDir,1);
                index++;
                continue;
            }
            int steps = commands[index];
            while(steps--){
                int newx = curX + dx[curDir];
                int newy = curY + dy[curDir];
                if(mp.find(make_pair(newx,newy))==mp.end()){
                    curX = newx;
                    curY = newy;
                    ans = max(ans,curX*curX + curY*curY);
                } else break;
            }
            index++;
        }

        return ans;
    }
};