class Solution {
public:
    void insert(unordered_map<string, vector<string>> &mp, string &word)
    {
        for(int j=0;j<word.length();j++)
        {
            string key=word.substr(0,j)+"*"+word.substr(j+1);
            mp[key].push_back(word);
        }
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, vector<string>> mp;
        insert(mp, beginWord);
        for(string word:wordList)
        {
            insert(mp, word);
        }
        queue<string> q;
        q.push(beginWord);
        unordered_set<string> visited;
        int result=1;
        while(!q.empty())
        {
            int sz=q.size();
            for(int i=0;i<sz;i++)
            {
                string word=q.front();
                q.pop();
                if(word==endWord)
                    return result;
                for(int j=0;j<word.length();j++)
                {
                    string key=word.substr(0,j)+"*"+word.substr(j+1);
                    for(string y:mp[key])
                    {
                        if(visited.find(y)==visited.end())
                        {
                            visited.insert(y);
                            q.push(y);
                        }
                    }
                }
            }
            result++;
        }
        return 0;
    }
};
