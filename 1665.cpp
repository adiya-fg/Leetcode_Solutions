class Solution {
public:

    static bool cmp(vector<int>&x1, vector<int>&x2){
        // if(x1[0]==x2[0]) {
        //     return (x1[1]>x2[1]);    
        // } else return (x1[0]<x2[0]);
        return (x1[0]+x2[1]<x2[0]+x1[1]);  
    }

    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(),tasks.end(),cmp);
        for(auto &val : tasks){
            cout<<val[0]<<" : "<<val[1]<<endl;
        }
        int f = INT_MAX, s = 0;
        while(s<=f){
            int mid = (s+f)>>1;
            bool check=true;
            int cur = mid;
            for(auto &val : tasks){
                if(cur>=val[1]){
                    cur-=val[0];
                } else {
                    check=false; break;
                }
            }
            // if(check==false){
            //     cur = mid;
            //     check=true;
            //     for(int i=tasks.size()-1; i>=0; i--){
            //         if(cur>=tasks[i][1]){
            //             cur-=tasks[i][0];
            //         } else {
            //             check=false; break;
            //         }
            //     }
            // }
            if(check)
                f = mid - 1;
            else 
                s = mid + 1;
        }
        return s;
    }
};

/*
1 : 2
2 : 4
4 : 8
*/