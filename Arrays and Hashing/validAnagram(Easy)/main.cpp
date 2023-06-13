#include <iostream>
#include <unordered_map>
using namespace std;

//* Link - https://leetcode.com/problems/valid-anagram/

bool isAnagram(string s, string t) {

    if (s.length() != t.length()) return false;

    // Check for letter occurrences
    unordered_map<char, int> smap;
    unordered_map<char, int> tmap;

    for (auto i : s) {
        if (smap.find(i) == smap.end()) {
            // Letter not found
            smap[i] = 1;
        } else
            smap[i]++;
    }
    for (auto i : t) {
        if (tmap.find(i) == tmap.end()) {
            // Letter not found
            tmap[i] = 1;
        } else
            tmap[i]++;
    }

    // Cross check letter occurrences in both maps
    for (auto i : s) {
        if (smap[i] != tmap[i]) return false;
    }

    return true;
}

int main() {
    string s = "cat";
    string t = "act";
    cout << isAnagram(s, t);
    return 0;
}