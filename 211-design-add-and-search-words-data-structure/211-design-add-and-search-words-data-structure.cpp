class TrieNode{
private:
    bool isWord;
    vector<TrieNode*> nextNodesVect;
public:
    TrieNode() : nextNodesVect(26, nullptr){
        isWord = false;
    }
    bool getIsWord(){
        return isWord;
    }
    void setIsWord(bool wordState){
        isWord = wordState;
    }
    void setNodeOfChar(char wordChar){
        TrieNode* newNode = new TrieNode();
        nextNodesVect[wordChar - 'a'] = newNode;
    }
    TrieNode* getNodeOfChar(char wordChar){
        return nextNodesVect[wordChar - 'a'];
    }
};


class WordDictionary {
private:
    TrieNode* rootNodePtr;
public:
    WordDictionary() {
        rootNodePtr = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* travPtr = rootNodePtr;
        for (int i = 0; i < word.size(); i++){
            if (travPtr->getNodeOfChar(word[i]) == nullptr){
                travPtr->setNodeOfChar(word[i]);
            }
            travPtr = travPtr->getNodeOfChar(word[i]);
        }
        travPtr->setIsWord(true);
    }
    
    bool search(string word) {
        return searchDFS(word, 0, rootNodePtr);
    }
    
    bool searchDFS(string& word, int idx, TrieNode* travPtr){
        if (travPtr == nullptr){
            return false;
        }
        if (idx == word.size()){
            if (travPtr->getIsWord()){
               return true; 
            } else{
                return false;
            }
        }
        if (word[idx] == '.'){      
            for (int c = 'a'; c <= 'z'; c++){
                if (searchDFS(word, idx+1, travPtr->getNodeOfChar(c))){
                    return true;
                }
            }
            return false;
        }
        return searchDFS(word, idx+1, travPtr->getNodeOfChar(word[idx]));
    }
};
/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */