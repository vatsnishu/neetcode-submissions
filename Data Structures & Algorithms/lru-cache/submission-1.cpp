class LRUCache {
public:
    int cap;
    unordered_map<int, list<pair<int,int>>::iterator> mp;
    list<pair<int,int>> l;
    LRUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end())
        {
            return -1;
        }
        auto it=mp[key];
        int val=it->second;
        l.erase(it);
        l.push_front({key, val});
        mp[key]=l.begin();
        return val;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end())
        {
            auto it=mp[key];
            l.erase(it);
        }
        else if(mp.size()==cap)
        {
            int keytoerase=l.back().first;
            l.pop_back();
            mp.erase(keytoerase);
        }
        l.push_front({key, value});
        mp[key]=l.begin();
    }
};
