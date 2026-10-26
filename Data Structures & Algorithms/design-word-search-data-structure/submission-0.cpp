class WordDictionary {
public:
    class TrieNode
    {
        public:
        bool isLeaf;
        TrieNode * children[26];
        TrieNode()
        {
            isLeaf=false;
            for(int i=0;i<26;i++)
            {
                children[i]=NULL;
            }
        }
    };
    TrieNode *root;
    WordDictionary() {
        root=new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode *temp=root;
        for(char c:word)
        {
            if(temp->children[c-'a']==NULL)
            {
                temp->children[c-'a']=new TrieNode();
            }
            temp=temp->children[c-'a'];
        }
        temp->isLeaf=true;
    }
    
    bool process(string &word, int index, TrieNode *temp)
    {
        if(!temp)
            return false;
        if(index==word.size())
        {
            return temp->isLeaf;
        }
        if(word[index]=='.')
        {
            for(int i=0;i<26;i++)
            {
                if(process(word, index+1, temp->children[i]))
                {
                    return true;
                }
            }
            return false;
        }
        return process(word, index+1, temp->children[word[index]-'a']);
    }
    bool search(string word) {
        TrieNode *temp=root;
        return process(word, 0, temp);
    }
};
