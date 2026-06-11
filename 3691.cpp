class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int l = 0, r = 1000000001;
        int x, y, diff;
        int n = nums.size();

        int dp_min[50001][17], dp_max[50001][17];
    
        vector<int> lg(n + 1, 0);
        for (int i = 2; i <= n; i++) lg[i] = lg[i / 2] + 1;

        //build RMQ
        for(int i=0; i<n; i++) {
            dp_max[i][0]=dp_min[i][0]=nums[i];
            for(int j=1; j<17 && (i-(1<<(j-1)))>=0; j++) {
                dp_max[i][j] = max(dp_max[i][j-1],dp_max[i-(1<<(j-1))][j-1]);
                dp_min[i][j] = min(dp_min[i][j-1],dp_min[i-(1<<(j-1))][j-1]);
            }
        }

        auto findDifference = [&](int L, int R) {
            if(L>=R) return 0;
            // int mn = nums[l];
            // int mx = nums[l];
            // for(int i=16; i>=0; i--) {
            //     if((r-(1<<i))>=l) {
            //         mx = max(mx,dp_max[r][i]);
            //         mn = min(mn,dp_min[r][i]);
            //         r -= (1<<i);
            //     }
            // }
            int len = R - L + 1;
            int j = lg[len];
            int mx = max(dp_max[R][j], dp_max[R - (1 << j)+1][j]);
            int mn = min(dp_min[R][j], dp_min[R - (1 << j)+1][j]);
            return mx - mn;
        };
                   
        int target = 0;
        while(l<=r) {
            int mid = (l + r) >> 1;
            //count how many subarrays thah has a value equal or more than the target.
            int count = 0;
            for(int i=0; i<n; i++) {
                x = 0, y = i;
                int temp=-1;
                while(x<=y) {
                    int midX = (x+y)>>1;
                    diff = findDifference(midX,i);
                    if(diff>=mid){ temp=midX; x=midX+1; }
                    else y = midX-1;
                }
                count += (temp+1);
                //cout<<count<<" : ";
            }
            // cout<<endl;
            // cout<<mid<<" : "<<count<<endl;
            if(count<k) {
                r = mid-1;
            } else {
                l = mid+1;
                target = mid;
            }
        }
        // l = target;
        // cout<<l<<endl;

        // found the target L value
        vector<int> vals;
        for(int i=0; i<n; i++) {
            x = 0, y = i;
            int temp = -1;
            while(x<=y) {
                int midX = (x+y)>>1;
                diff = findDifference(midX,i);
                if(diff>=target) { temp=midX; x=midX+1; }
                else y = midX-1;
            }
            for(int j=0; j<=temp; j++) {
                vals.push_back(findDifference(j,i));    
            }
        }        
        long long ans=0;
        sort(vals.begin(),vals.end());
        for(int i=vals.size()-1; i>=0 && k>0; i--) {
            ans += (long long)vals[i];
            k--;
        }
        return ans;
    }
};