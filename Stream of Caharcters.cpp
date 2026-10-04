

class StreamChecker {
    struct TrieNode {
        int next[26];
        bool isWord;

        TrieNode() : isWord(false) {
            for (int &child : next) {
                child = -1;
            }
        }
    };

    vector<TrieNode> trie{};
    string stream{};
    int maxWordLength{0};

public:
    StreamChecker(vector<string>& words) {
        trie.emplace_back();

        for (const string& word : words) {
            maxWordLength = max(maxWordLength, static_cast<int>(word.size()));

            int node = 0;
            for (auto it = word.rbegin(); it != word.rend(); ++it) {
                int index = *it - 'a';
                if (trie[node].next[index] == -1) {
                    trie[node].next[index] = static_cast<int>(trie.size());
                    trie.emplace_back();
                }
                node = trie[node].next[index];
            }
            trie[node].isWord = true;
        }
    }
    
    bool query(char letter) {
        stream.push_back(letter);
        if (stream.size() > static_cast<size_t>(maxWordLength)) {
            stream.erase(stream.begin());
        }

        int node = 0;
        for (auto it = stream.rbegin(); it != stream.rend(); ++it) {
            int index = *it - 'a';
            if (trie[node].next[index] == -1) {
                return false;
            }

            node = trie[node].next[index];
            if (trie[node].isWord) {
                return true;
            }
        }

        return false;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
