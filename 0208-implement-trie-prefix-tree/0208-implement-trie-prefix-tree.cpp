class TrieNode{
public:
    vector<TrieNode*> links;
    bool isEnd;
    TrieNode(){
        links.resize(26,NULL);
        isEnd=false;
    }
    
    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }
    
    TrieNode* get(char ch){
        return links[ch-'a'];
    }
    
    void put(char ch,TrieNode* node){
        links[ch-'a']=node;
    }
    
    void setEnd(){
        isEnd=true;
    }
};

class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root= new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node=root;
        
        for(int i=0;i<word.size();++i){
            char curChar=word[i];
            if(!node->containsKey(curChar)) node->put(curChar,new TrieNode);
            node=node->get(curChar);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        TrieNode* node=searchPrefix(word);
        return node!=NULL && node->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node=searchPrefix(prefix);
        return node!=NULL;
    }
    
    TrieNode* searchPrefix(string word){
        TrieNode* node=root;
        for(int i=0;i<word.size();++i){
            char curChar=word[i];
            if(node->containsKey(curChar)){
                node=node->get(curChar);
            }
            else{
                return NULL;
            }
        }
        return node;
    }
};


/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */