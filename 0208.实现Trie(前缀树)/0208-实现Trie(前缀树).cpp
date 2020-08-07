struct Node {
    vector<Node*> childrens;
    bool isEnd;
    Node() : childrens(26, NULL), isEnd(false) {};
};

class Trie {
public:
    Node head;

public:
    /** Initialize your data structure here. */
    Trie() {
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* pNode = &head;
        for( auto& ch : word ) {
            int iCh = ch - 'a';
            if( !pNode->childrens[iCh] ) {
                pNode->childrens[iCh] = new Node();
            }
            pNode = pNode->childrens[iCh];
        }
        pNode->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* pNode = &head;
        for( auto& ch : word ) {
            int iCh = ch - 'a';
            if( !pNode->childrens[iCh] ) {
                return false;
            }
            pNode = pNode->childrens[iCh];
        }
        return pNode->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* pNode = &head;
        for( auto& ch : prefix ) {
            int iCh = ch - 'a';
            if( !pNode->childrens[iCh] ) {
                return false;
            }
            pNode = pNode->childrens[iCh];
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