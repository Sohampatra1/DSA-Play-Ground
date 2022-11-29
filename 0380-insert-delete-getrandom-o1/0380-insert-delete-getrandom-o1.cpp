class RandomizedSet {
public:
    unordered_map <int, int> umap;
    vector <int> v;
    RandomizedSet() {
    }
    
    bool insert(int val) 
    {
        if (umap.find(val)==umap.end()) 
        { 
            v.emplace_back(val);
            umap[val]=v.size()-1;         
            return true;
        }
        return false;
        }
    bool remove(int val) 
    {
        if (umap.find(val)==umap.end()) 
            return false;  
        int last = v.back();
        umap[last]=umap[val];
        v[umap[val]]=last;
        v.pop_back(); 
        umap.erase(val);
        return true;
    }
    
    int getRandom() {
        return v[rand()%v.size()];

    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
 