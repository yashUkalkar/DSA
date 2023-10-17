#include <iostream>
#include <unordered_map>
using namespace std;

//* Link -
//* https://leetcode.com/problems/design-add-and-search-words-data-structure/

//* SOLUTION
class TrieNode {
   public:
    TrieNode* children[26];
    bool isWord;

    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isWord = false;
    }
};

class WordDictionary {
   private:
    TrieNode* root;

    bool searchInNode(string& word, int i, TrieNode* node) {
        if (node == NULL) {
            return false;
        }
        if (i == word.size()) {
            return node->isWord;
        }
        if (word[i] != '.') {
            return searchInNode(word, i + 1, node->children[word[i] - 'a']);
        }
        for (int j = 0; j < 26; j++) {
            if (searchInNode(word, i + 1, node->children[j])) {
                return true;
            }
        }
        return false;
    }

   public:
    WordDictionary() { root = new TrieNode(); }

    void addWord(string word) {
        cout << "Adding '" << word << "' to the dictionary\n";
        TrieNode* node = root;
        int curr = 0;

        for (int i = 0; i < word.size(); i++) {
            curr = word[i] - 'a';
            if (node->children[curr] == NULL) {
                node->children[curr] = new TrieNode();
            }
            node = node->children[curr];
        }

        node->isWord = true;
        cout << "Added to dictionary\n\n";
    }

    bool search(string word) {
        cout << "Searching '" << word << "' in dictionary\n";
        TrieNode* node = root;
        bool res = searchInNode(word, 0, node);
        cout << (res ? "Word found!" : "Word not found!") << "\n\n";
        return res;
    }
};

int main() {
    WordDictionary* wordDictionary = new WordDictionary();
    wordDictionary->addWord("bad");
    wordDictionary->addWord("dad");
    wordDictionary->addWord("mad");
    wordDictionary->search("pad");  // return False
    wordDictionary->search("bad");  // return True
    wordDictionary->search(".ad");  // return True
    wordDictionary->search("b..");  // return True
    return 0;
}