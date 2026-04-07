class Robot {
public:
    //directions

    int n , m;
    int curX = 0;
    int curY = 0;
    int curDir = 0;
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    int range[4] = {0,0,0,0};
    string pos[4] = {"North", "East", "South", "West"};

    int changeDir(int current, int newDir){
        //turn right
        if(newDir==1){
            return (current+1)%4;
        } else 
            return (current-1+4)%4;
    }

    int minVal(int x, int y){
        return ((x>y) ? y : x);
    }
    Robot(int width, int height) {
        curDir = 1; //east
        n = height;
        m = width;
        range[0] = n-1;
        range[1] = m-1;
    }
    
    void step(int num) {
        int valBefore = num;
        num = num%((n+m-2)*2);
        if(((n+m-2)*2)<=valBefore)
        {
            if(curX==curY && curX==0)
                curDir = 2;
            if(curX==m-1 && curY==0)
                curDir = 1;      
            if(curX==0 && curY==n-1)
                curDir = 3;
            if(curX==m-1 && curY==n-1)
                curDir = 0;              
        }

        //cout<<num<<" : "<<curDir<<endl;

        while(num>0){
            int newx;
            int newy;
            int steps = 0;

            if(curDir==1 || curDir==3) {
                if(curDir==1)
                    steps = minVal(num,(range[curDir]-curX));
                else 
                    steps = minVal(num,(curX-range[curDir]));
                if(steps>0){
                    newx = curX + steps*dx[curDir];
                    newy = curY;
                }
            } else {
                if(curDir==0)
                     steps = minVal(num,(range[curDir]-curY)); 
                else 
                     steps = minVal(num,(curY-range[curDir]));   
                if(steps>0){
                    newy = curY + steps*dy[curDir];
                    newx = curX;
                }
            }

            if(steps>0) {
                curX = newx;
                curY = newy;
                num-=steps;
            } else {
                curDir = changeDir(curDir,0);
            }
        }  
        //vector<int> test = getPos();
        //cout<<test[0]<<" here "<<test[1]<<" : "<<curDir<<" "<<n<<" "<<m<<endl;  
    }
    
    vector<int> getPos() {
        vector<int> ans;
        ans.push_back(curX);
        ans.push_back(curY);
        return ans;    
    }
    
    string getDir() {
        return pos[curDir];
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */