#include <iostream>
#include <unordered_map>
using namespace std;

//* Link - https://leetcode.com/problems/implement-trie-prefix-tree/

//* SOLUTION
class TrieNode {
   public:
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord = false;

    TrieNode() {}
};

class Trie {
    TrieNode* root;

   public:
    Trie() { root = new TrieNode(); }

    void insert(string word) {
        cout << "Inserting '" << word << "' to Trie\n";
        TrieNode* current = root;

        for (auto i : word) {
            if (current->children.find(i) == current->children.end()) {
                current->children[i] = new TrieNode();
            }

            current = current->children[i];
        }

        current->isEndOfWord = true;

        cout << "Added '" << word << "' to Trie!\n\n";
    }

    bool search(string word) {
        cout << "Searching '" << word << "' in Trie\n";
        TrieNode* current = root;

        for (auto i : word) {
            if (current->children.find(i) == current->children.end())
                return false;

            current = current->children[i];
        }

        if (current->isEndOfWord)
            cout << "Word found in Trie\n\n";
        else
            cout << "Word not found in Trie\n\n";

        return current->isEndOfWord;
    }

    bool startsWith(string prefix) {
        cout << "Finding prefix '" << prefix << "' in Trie\n";

        TrieNode* current = root;

        for (auto i : prefix) {
            if (current->children.find(i) == current->children.end()) {
                cout << "Prefix not found\n\n";
                return false;
            }

            current = current->children[i];
        }

        cout << "Prefix found in Trie\n\n";

        return true;
    }
};

int main() {
    Trie* trie = new Trie();

    trie->insert("apple");

    trie->search("apple");

    trie->search("app");

    trie->startsWith("app");

    trie->insert("app");

    trie->search("app");

    return 0;
}