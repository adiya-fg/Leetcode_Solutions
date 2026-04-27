class DisjointSet {
    private:
        vector<int> parent;

    public: 
        DisjointSet(int n, int m){
            parent.resize(n*m);
            for(int i=0; i<n*m; i++)
                parent[i] = i;
        }

        int findParent(int x) {
            if(x==parent[x]) return x;
            else return parent[x] = findParent(parent[x]);
        }

        void merge(int x, int y){
            int pX = findParent(x);
            int pY = findParent(y);
            parent[pY] = pX;
        }

};

class Solution {
public:
    //where is open gate - top,right,down,left.
    bool hasValidPath(vector<vector<int>>& grid) {
        // 1,2,3,4,5,6 
        int n = grid.size();
        int m = grid[0].size();

        DisjointSet ds(n,m);

        auto getId = [&](int x, int y) {
            return x*m+y;
        };

        auto findL = [&](int x, int y) {
            if(y>0 && (grid[x][y-1]==1 || grid[x][y-1]==4 || grid[x][y-1]==6)) {
                int id1=getId(x,y-1);
                int id2=getId(x,y);
                ds.merge(id1,id2);
            }
        };

        auto findR = [&](int x, int y) {
            if(y<m-1 && (grid[x][y+1]==1 || grid[x][y+1]==5 || grid[x][y+1]==3)) {
                int id1=getId(x,y+1);
                int id2=getId(x,y);
                ds.merge(id1,id2);
            }
        };

        auto findU = [&](int x, int y) {
            if(x>0 && (grid[x-1][y]==2 || grid[x-1][y]==3 || grid[x-1][y]==4)) {
                int id1=getId(x-1,y);
                int id2=getId(x,y);
                ds.merge(id1,id2);
            }
        };

        auto findD = [&](int x, int y) {
            if(x<n-1 && (grid[x+1][y]==2 || grid[x+1][y]==5 || grid[x+1][y]==6)) {
                int id1=getId(x+1,y);
                int id2=getId(x,y);
                ds.merge(id1,id2);
            }
        };
        
        auto connectNodes = [&](int x, int y) {
            switch (grid[x][y])
            {
                case 1: { findL(x,y); findR(x,y); break; }
                case 2: { findU(x,y); findD(x,y); break; }
                case 3: { findL(x,y); findD(x,y); break; }
                case 4: { findR(x,y); findD(x,y); break; } 
                case 5: { findL(x,y); findU(x,y); break; }
                case 6: { findU(x,y); findR(x,y); break; } 
                default: break;
            }
        };
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                connectNodes(i,j);
            }
        }

        return (ds.findParent(getId(0,0))==ds.findParent(getId(n-1,m-1)));
    }
};