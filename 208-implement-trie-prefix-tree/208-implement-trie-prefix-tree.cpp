class Trie {
private:
    struct Node {
    private:
        char val;
        bool isLeaf;
        unordered_map<char, Node*> children;
    
    public:
        Node(char ch) {
            val = ch;
            isLeaf = false;
        }
        
        bool getVal() {
            return val;
        }
        
        void setVal(char _val) {
            val = _val;
        }
        
        bool getIsLeaf() {
            return isLeaf;
        }
        
        void setIsLeaf(bool _isLeaf) {
            isLeaf = _isLeaf;
        }
        
        unordered_map<char, Node*> getChildren() {
            return children;
        }
        
        void setChildren(unordered_map<char, Node*> _children) {
            children = _children;
        }
        
        Node* getChild(char _ch) {
            return children[_ch];
        }
        
        void setChild(char _ch) {
            children[_ch] = new Node(_ch);
        }
    };
    
    Node* createNode(char ch) {
        return new Node(ch);
    }
    
    Node *root = createNode('*');
    
public:
    void insert(string word) {
        Node *cur = root;
        for (char ch : word) {
            Node *child = cur->getChild(ch); 
            if (!child)
                cur->setChild(ch);
            cur = cur->getChild(ch);
        }
        cur->setIsLeaf(true);
    }
    
    bool search(string word) {
        Node *cur = root;
        for (char ch : word) {
            Node *child = cur->getChild(ch); 
            if (!child)
                return false;
            cur = cur->getChild(ch);
        }
        return cur->getIsLeaf();
    }
    
    bool startsWith(string prefix) {
        Node *cur = root;
        for (char ch : prefix) {
            Node *child = cur->getChild(ch); 
            if (!child)
                return false;
            cur = cur->getChild(ch);
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