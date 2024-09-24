class TrieNode {
public:
    vector<TrieNode*> children;

    TrieNode() { children = vector<TrieNode*>(10, NULL); }
};

class Trie {
public:
    TrieNode* root;

    Trie() { root = new TrieNode(); }

    void insert(int num) {
        TrieNode* cur = root;
        string numStr = to_string(num);
        for (char digit : numStr) {
            int idx = digit - '0';
            if (!cur->children[idx]) {
                cur->children[idx] = new TrieNode();
            }
            cur = cur->children[idx];
        }
    }

    int findLongestPrefix(int num) {
        TrieNode* cur = root;
        string numStr = to_string(num);
        int longestPrefix = 0;
        for (char digit : numStr) {
            int idx = digit - '0';
            if (cur->children[idx]) {
                cur = cur->children[idx];
                ++longestPrefix;
            } else {
                break;
            }
        }
        return longestPrefix;
    }
};

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie trie;

        for (int num : arr1) {
            trie.insert(num);
        }

        int ans = 0;

        for (int num : arr2) {
            int longestPrefix = trie.findLongestPrefix(num);
            ans = max(ans, longestPrefix);
        }

        return ans;
    }
};