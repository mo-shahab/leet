class TrieNode 
{
public:
    bool isEnd;
    TrieNode* children[26];

    TrieNode()
    {
        isEnd = false;    
        for(int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() 
    {
        root = new TrieNode();
    }
    
    void insert(string word) 
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
        int n = word.size();
        TrieNode* parent = root;

        for(int i = 0; i < n; i++)
        {
            int val = word[i] - 'a';

            if(parent->children[val] == NULL)
            {
                return false;
            }

            parent = parent->children[val];
        }

        return parent->isEnd;
    }
    
    bool startsWith(string prefix) 
    {
        int n = prefix.size();
        TrieNode* parent = root;

        for(int i = 0; i < n; i++)
        {
            int val = prefix[i] - 'a';

            if(parent->children[val] == NULL)
            {
                return false;
            }

            parent = parent->children[val];
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */