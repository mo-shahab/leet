class TrieNode
{
public:
    TrieNode* children[26];
    bool isEnd;

    TrieNode()
    {
        isEnd = false;
        for(int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
    }
};

class WordDictionary 
{
public:
    TrieNode* root;
    WordDictionary() 
    {
        root = new TrieNode();
    }
    
    void addWord(string word) 
    {
        int n = word.size();
        TrieNode* parent = root;

        for(int i = 0; i < n; i++)
        {
            int val = word[i] - 'a';
            if(parent->children[val] == NULL)
            {
                parent->children[val] = new TrieNode();
            }
            parent = parent->children[val];
        }

        parent->isEnd = true;
    }
    
    bool search(string word) 
    {
        return searchHelper(word, 0, root);
    }
    
private:
    bool searchHelper(const string& word, int pos, TrieNode* node)
    {
        if (pos == word.size())
        {
            return node->isEnd;
        }
        
        char ch = word[pos];
        if (ch == '.')
        {
            for (int i = 0; i < 26; i++)
            {
                if (node->children[i] != NULL)
                {
                    if (searchHelper(word, pos + 1, node->children[i]))
                    {
                        return true;
                    }
                }
            }
            return false;
        }
        else
        {
            int idx = ch - 'a';
            if (node->children[idx] == NULL)
            {
                return false;
            }
            return searchHelper(word, pos + 1, node->children[idx]);
        }
    }
};