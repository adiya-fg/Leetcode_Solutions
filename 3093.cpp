class TrieNode{
public:
    int length;
    int index;  
    TrieNode* children[26];
    TrieNode(){
        length = 0;
        index = -1;
        for(int i=0; i<26; i++)
            children[i] = nullptr;
    }
};

class Solution {
private: 
    TrieNode* root;
    
    void insert(string word, int index){
        TrieNode* node = root;
        int steps = 1;
        for(char c: word){
            if(node->children[c-'a'] == nullptr)
                node->children[c-'a'] = new TrieNode();
            node = node->children[c-'a'];
            node->length = steps++;
        }
        if(node->index==-1 || node->index>index)
            node->index = index;
    }

    // update index of the node to the index of the last word 
    // that has smaller length than the current word.
    void updateIndex(TrieNode* node){
        if(node == nullptr)
            return ;

        int minL = 0;
        int minI = node->index;
        for(int i=0; i<26; i++) {
            if(node->children[i]==nullptr) continue;
            //pair<int,int> temp = 
            updateIndex(node->children[i]);
            if(minL==0 || node->children[i]->length<minL) {
                minL = node->children[i]->length;
                minI = node->children[i]->index;
            } else {
                if(node->children[i]->length==minL && node->children[i]->index>=0 && node->children[i]->index<minI) {
                    minI = node->children[i]->index;
                }    
            }
        }
        //cout<<minL+1<<minI<<endl;
        //update index
        if(node->index==-1) {
            node->length = minL;
            node->index = minI;
        }
        //return {minL+1, minI};
        return ;

    }
    
    int search(string word){
        TrieNode* node = root;
        int ans = -1;
        for(char c: word){
            if(node->children[c-'a'] == nullptr)
                break;
            node = node->children[c-'a'];
            ans = node->index;
        }
        return ans;
    }

public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        root = new TrieNode();
        int n;
        string str;
        int smallest = INT_MAX;
        int smallestIndex;

        for(int i=0; i<wordsContainer.size(); i++) {
            str = "";
            n = wordsContainer[i].size();
            for(int j=n-1; j>=0; j--)
                str += wordsContainer[i][j];
            
            insert(str, i);
            if(smallest>n) {
                smallest = n;
                smallestIndex = i;
            }
        }

        updateIndex(root);
        
        vector<int> ans;
        for(string word: wordsQuery) {
            reverse(word.begin(),word.end());
            int foundIndex = search(word);
            // if it is not found.
            if(foundIndex==-1) ans.push_back(smallestIndex);
            else ans.push_back(foundIndex);
        }
        
        return ans;   
    }
};