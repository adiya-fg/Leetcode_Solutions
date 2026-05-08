class DSU {
private:
    vector <int> parent;
public:
    vector <int> vals;

    DSU(int n, vector<int>& nums){
        parent.resize(n,0);
        vals.resize(n,0);
        for(int i=0; i<n; i++) {
            parent[i] = i;
            vals[i] = nums[i];
        }
    }
    int findParent(int x){
        if(x==parent[x]) return x;
        else return parent[x] = findParent(parent[x]);
    }

    void merge(int i1, int i2){
        int p1 = findParent(i1);
        int p2 = findParent(i2);
        int val1 = vals[p1];
        int val2 = vals[p2];
        if(val1>val2) {
            parent[p2] = p1;
        } else {
            parent[p1] = p2;
        }
    }
};

class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        DSU sets = new DSU(n,nums);
        //find before max and after min

        int mx = 0;
        int prev_index = 0;

        for(int i=0; i<n; i++) {
            if(mx>nums[i]){
                sets.merge(prev_index,i);    
            }
            //update
            if(mx<nums[i]){
                mx = nums[i];
                prev_index = i;  
            }
        }      
        int mn = INT_MAX;
        int last_index = 0;
        for(int i=n-1; i>=0; i--) {
            if(mn<nums[i]){
                sets.merge(last_index,i);    
            }
            //update
            if(mn>nums[i]){
                mn = nums[i];
                last_index = i;  
            }
        }      
        vector <int> ans;
        for(int i=0; i<n; i++) {
            int parentID = sets.findParent(i);
            ans.push_back(sets.vals[parentID]);
        }
        return ans;
    }
};

// class Solution {
// public:
//     vector<int> maxValue(vector<int>& nums) {
//         vector<int> ans, index_max;
        
//         int n = nums.size();
        
//         ans.resize(n,0);
//         //mx.resize(n,0);
//         index_max.resize(n,0);

        
//         pair<int,int> mx[100001];
//         mx[0].first = nums[0];
//         mx[0].second = 0;
        
//         for(int i=1; i<n; i++) {
//             if(mx[i-1].first<nums[i]) {
//                 mx[i].first = nums[i];
//                 mx[i].second = i;
//             } else {
//                 mx[i].first = mx[i-1].first;
//                 mx[i].second = mx[i-1].second;
//             }
//         }

//         pair<int,int> temp[100001];

//         for(int i=0; i<n; i++) {
//             temp[i].first = nums[i];
//             temp[i].second = i;
//         }        
//         sort(temp,temp+n);
//         index_max[0] = temp[0].second;
//         for(int i=1; i<n; i++) {
//             //find lower bound
//             index_max[i] = max(index_max[i-1],temp[i].second);
//         }   

//         // for(int i=0; i<n; i++) {
//         //     cout<<mx[i].first<<" ::::::: "<<mx[i].second<<endl;
//         // }

//         int mx_val = 0;
//         for(int i=0; i<n; i++) {
//             mx_val=max(mx_val,nums[i]);

//             //find lower bound
//             int cur = i;
//             int total=10;
//             while(total--){
//                 int s = 0, f = n-1;
//                 //cout<<" :: "<<cur<<" "<<nums[cur]<<endl;
//                 while(s<=f){
//                     int mid = (s+f)>>1;
//                     if(temp[mid].first<nums[cur]) 
//                         s=mid+1;
//                     else 
//                         f = mid-1;
//                 }
//                 //if(mx[index_max[s]].first==ans[i]) break;
//                 ans[i] = max(ans[i], mx[index_max[s]].first);
//                 cur = mx[index_max[s]].second;
//                 //if(nums[cur]==nums[i]) break;
//                 //cout<<index_max[s]<<" end "<<mx[index_max[s]].second<<endl;
//             }

//             //cout<<"testing "<<i<<" "<<cur<<endl;
//             ans[i]=max(ans[i],mx_val);
//         }        

//         return ans;
//     }
// };

class Solution {
public:
    struct Item {
        int value;
        int left;
        int right;
    };

    vector<int> maxValue(const vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);

        vector<Item> stack;

        for (int i = 0; i < n; ++i) {
            Item curr = {nums[i], i, i};

            while (!stack.empty() && stack.back().value > nums[i]) {
                Item top = stack.back();
                stack.pop_back();
                curr.value = max(curr.value, top.value);
                curr.left = top.left;
            }

            stack.push_back(curr);
        }

        for (size_t i = 0; i < stack.size(); ++i) {
            for (int j = stack[i].left; j <= stack[i].right; ++j) {
                ans[j] = stack[i].value;
            }
        }

        return ans;
    }
};