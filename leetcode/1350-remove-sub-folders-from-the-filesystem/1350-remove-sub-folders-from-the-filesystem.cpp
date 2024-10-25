class Solution {
private:
    struct TrieNode {
        bool isEndOfFolder;
        unordered_map<string, TrieNode*> children;
        TrieNode() : isEndOfFolder(false) {}
    };

    TrieNode* root;

    void deleteTrie(TrieNode* node) {
        if (node == nullptr) return;
        for (auto& pair : node->children) {
            deleteTrie(pair.second);
        }
        delete node;
    }

public:
    Solution() : root(new TrieNode()) {}
    ~Solution() { deleteTrie(root); }

    vector<string> removeSubfolders(vector<string>& folder) {
        for (string& path : folder) {
            TrieNode* currentNode = root;
            istringstream iss(path);
            string folderName;

            while (getline(iss, folderName, '/')) {
                if (folderName.empty()) continue;
                if (currentNode->children.find(folderName) ==
                    currentNode->children.end()) {
                    currentNode->children[folderName] = new TrieNode();
                }
                currentNode = currentNode->children[folderName];
            }
            currentNode->isEndOfFolder = true;
        }

        vector<string> result;
        for (string& path : folder) {
            TrieNode* currentNode = root;
            istringstream iss(path);
            string folderName;
            bool isSubFolder = false;

            while (getline(iss, folderName, '/')) {
                if (folderName.empty()) continue;
                TrieNode* nextNode = currentNode->children[folderName];
                if (nextNode->isEndOfFolder && iss.rdbuf()->in_avail() != 0) {
                    isSubFolder = true;
                    break;
                }
                currentNode = nextNode;
            }
            if (!isSubFolder) result.push_back(path);
        }

        return result;
    }
};