class TrieNode{
public:
    int count=0;
    TrieNode* children[26]={};
};

// MLE when extra Trie class is created
class Solution {
private:
    TrieNode root;

    void insert(string word){
        auto cur=&root;
        for(char c:word){
            int idx=c-'a';
            if(!cur->children[idx]){
                cur->children[idx]=new TrieNode();
            }
            cur->children[idx]->count+=1;
            cur=cur->children[idx];
        }
    }

    int find(string word){
        auto cur=&root;
        int ans=0;
        for(char c:word){
            int idx=c-'a';
            ans+=cur->children[idx]->count;
            cur=cur->children[idx];
        }
        return ans;
    }

public:
    vector<int> sumPrefixScores(vector<string>& words) {
        int n=words.size();
        for(int i=0;i<n;++i){
            insert(words[i]);
        }

        vector<int> ans(n);
        for(int i=0;i<n;++i){
            ans[i]=find(words[i]);
        }
        return ans;
    }
};