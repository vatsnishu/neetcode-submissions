class PrefixTree {
public:
    struct TrieNode
    {
        bool isleaf;
        TrieNode *children[26]; 
    };


    TrieNode * trie;
    PrefixTree() {
        trie = new TrieNode();
        for(int i=0;i<26;i++)
        {
            trie->children[i]=NULL;
        }
    }
    
    void insert(string word) {
        TrieNode *temp=trie;
        for(char c:word)
        {
            if(temp->children[c-'a'] == NULL)
            {
                temp->children[c-'a'] = new TrieNode();
            }
            temp=temp->children[c-'a'];
        }
        temp->isleaf=true;
    }
    
    bool search(string word) {
        TrieNode *temp=trie;
        for(char c:word)
        {
            if(temp->children[c-'a'] == NULL)
            {
                return false;
            }
            temp=temp->children[c-'a'];
        }
       return temp->isleaf;
    }
    
    bool startsWith(string prefix) {
        TrieNode *temp=trie;
        for(char c:prefix)
        {
            if(temp->children[c-'a'] == NULL)
            {
                return false;
            }
            temp=temp->children[c-'a'];
        }
       return true;
    }
};
