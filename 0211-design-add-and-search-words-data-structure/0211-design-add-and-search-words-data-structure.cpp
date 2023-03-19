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
    
    bool containsKey(int ind){
        return links[ind]!=NULL;
    }
    
    TrieNode* get(char ch){
        return links[ch-'a'];
    }
    
    TrieNode* get(int ind){
        return links[ind];
    }
    
    void put(char ch,TrieNode* node){
        links[ch-'a']=node;
    }
    
    void setEnd(){
        isEnd=true;
    }
};

class WordDictionary {
public:
    TrieNode * root;
    WordDictionary() {
        root= new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* node=root;
        for(int i=0;i<word.size();++i){
            char curChar=word[i];
            if(!node->containsKey(curChar)) node->put(curChar,new TrieNode);
            node=node->get(curChar);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        return searchHelper(word.c_str(),root);
    }
    
    bool searchHelper(const char* word, TrieNode* node) {
        for (int i = 0; word[i] && node; i++) {
            char curChar=word[i];
            if (word[i] != '.') {
                node=node->get(curChar);
            } else {
                TrieNode* temp = node;
                for (int j = 0; j < 26; j++) {
                    node=temp->get(j);
                    if (searchHelper(word + i + 1, node)) {
                        return true;
                    }
                }
            }
        }
        return node!=NULL && node->isEnd;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */