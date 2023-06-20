#include <iostream>
#include <unordered_map>
using namespace std;

//* Link -
//* https://leetcode.com/problems/longest-repeating-character-replacement/

//* Solution Link - https://www.youtube.com/watch?v=gqXU1UyA8pk

//* HELPERS
int maxFrequencyCharacterCount(unordered_map<char, int>& map) {
    int maxVal = 0;
    for (auto i : map) {
        maxVal = max(maxVal, i.second);
    }

    return maxVal;
}

//* SOLUTION
int characterReplacement(string s, int k) {
    int maxLength = 0;

    unordered_map<char, int> charFrequency;

    int l = 0;
    for (int r = 0; r < s.length(); r++) {
        charFrequency[s[r]]++;

        // Find count of most frequent character in current window
        int mostFreqCharCount = maxFrequencyCharacterCount(charFrequency);

        // Find if substring is valid
        while (((r - l + 1) - mostFreqCharCount) > k) {
            charFrequency[s[l]]--;
            l++;
        }

        maxLength = max(maxLength, r - l + 1);
    }

    return maxLength;
}

int optimizedCharacterReplacement(string s, int k) {
    int maxLength = 0;

    unordered_map<char, int> charFrequency;

    int l = 0, maxFreq = 0;
    for (int r = 0; r < s.length(); r++) {
        charFrequency[s[r]]++;
        maxFreq = max(maxFreq, charFrequency[s[r]]);

        // Find if substring is valid
        while (((r - l + 1) - maxFreq) > k) {
            charFrequency[s[l]]--;
            l++;
        }

        maxLength = max(maxLength, r - l + 1);
    }

    return maxLength;
}

int main() {
    string s = "AABABBA";
    int k = 1;

    cout << characterReplacement(s, k) << endl;
    cout << optimizedCharacterReplacement(s, k) << endl;

    return 0;
}