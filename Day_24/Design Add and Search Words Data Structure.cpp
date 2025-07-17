class WordDictionary
{
private:
    struct TrieNode
    {
        TrieNode *children[26] = {nullptr};
        bool isEnd = false;
    };

    TrieNode *root;

    bool dfs(string &word, int index, TrieNode *node)
    {
        if (!node)
            return false;
        if (index == word.size())
            return node->isEnd;

        char c = word[index];
        if (c == '.')
        {
            for (int i = 0; i < 26; ++i)
            {
                if (dfs(word, index + 1, node->children[i]))
                {
                    return true;
                }
            }
            return false;
        }
        else
        {
            return dfs(word, index + 1, node->children[c - 'a']);
        }
    }

public:
    WordDictionary() { root = new TrieNode(); }

    void addWord(string word)
    {
        TrieNode *node = root;
        for (char c : word)
        {
            int i = c - 'a';
            if (!node->children[i])
            {
                node->children[i] = new TrieNode();
            }
            node = node->children[i];
        }
        node->isEnd = true;
    }

    bool search(string word) { return dfs(word, 0, root); }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */