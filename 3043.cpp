class Trie {
private:
    int val;
    
public:

    Trie* child[11];
    Trie(int data){
        val = data;
        for(int i=0; i<11; i++)
            child[i]=nullptr;
    }
};

class Solution {
public:
    void add_child(Trie * root, string str) {
        Trie * cur = root;
        for(char chr: str) {
            if(cur->child[chr-'0']==nullptr) {
                cur->child[chr-'0'] = new Trie(chr-'0');   
            }
            cur = cur->child[chr-'0'];
        }    
    }
    int findPrefix(Trie * root, string str) {
        Trie * cur = root;
        int res = 0;
        for(char chr: str) {
            if(cur->child[chr-'0']==nullptr) {
                return res; 
            } else {
                cur = cur->child[chr-'0'];
                res++;
            }
        }   
        return 0; 
    }

    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie * root = new Trie(0);

        for(auto &data : arr1) {
            string str_val = to_string(data);
            add_child(root,str_val);
        }        
        int ans = 0;
        for(auto &data : arr2) {
            string str_val = to_string(data);
            ans = max(findPrefix(root,str_val),ans);
        }  
        return ans;
    }
};