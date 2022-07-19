class TrieNode
{
public:
    vector<TrieNode *> children;
    bool ends_here;

    TrieNode()
    {
        children = vector<TrieNode *>(26, NULL);
        ends_here = false;
    }
};

class Trie
{
public:
    TrieNode *trie_root;

    Trie()
    {
        trie_root = new TrieNode();
    }

    void insert_reversed(string &word)
    {
        TrieNode *node = trie_root;
        char current_char;
        string::reverse_iterator it = word.rbegin();
        
        while (it != word.rend())
        {
            current_char = *it;
			
            if (!node->children[current_char - 'a'])
                node->children[current_char - 'a'] = new TrieNode();
				
            node = node->children[current_char - 'a'];			
            it++;
        }
        node->ends_here = true;
    }

    bool search_reversed(string &word)
    {
        string::reverse_iterator it = word.rbegin();
        TrieNode *node = trie_root;
        char current_char;
        
        while (it != word.rend())
        {
            current_char = *it;
            
            if (node->ends_here)
                return true;
            
            if (!node->children[current_char - 'a'])
                return false;
            
            node = node->children[current_char - 'a'];
            it++;
        }
        
        return node && node->ends_here;
    }
};

class StreamChecker
{
public:
    Trie *trie = new Trie();
    string string_stream = "";
    
    StreamChecker(vector<string> &words)
    {
        string_stream = "";
        for (string word : words)
            trie->insert_reversed(word);
    }

    bool query(char letter)
    {
        string_stream += letter;
        return trie->search_reversed(string_stream);
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */