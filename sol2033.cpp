class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {


        int ans=0;
        
            //min(n*t/x-sum/x)
        int n = 0;
        int sum = 0;
        int mn=grid[0][0];
        int mx=grid[0][0];


        vector<int> nums;


        for(auto rows : grid){
            for(auto cell : rows){
                mn=min(mn,cell);
                mx=max(mx,cell);
                sum+=cell;
                n++;
                nums.push_back(cell);
            }
        }

        if(n<=1) return 0;

        // //find
        bool found=true;
        // int idx=0;
        // for(int i=mn-x; i<=mx+x; i++) {
        //     if((n*i)%x==0 && ((i*n)/x)>(sum/x)){
        //         found=true;
        //         idx=i;
        //         break;
        //     }
        // }

        // cout<<idx<<endl;

        // if(found)
        //     for(auto rows : grid){
        //         for(auto cell : rows){
        //             if((idx-cell)%x!=0) {
        //                 found=false; break;
        //             }
        //             ans += (fabs)(idx-cell)/x;
        //         }
        //     }

        sort(nums.begin(),nums.end());

        int mid = n/2; //5-2,4-2,

        cout<<nums[mid]<<endl;

            for(auto rows : grid){
                for(auto cell : rows){
                    if((nums[mid]-cell)%x!=0) {
                        ans=-1; break;
                    }
                    ans += (fabs)(nums[mid]-cell)/x;
                }
                if(ans==-1) break;
            }


        return ans;
        
    }
};