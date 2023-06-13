#include <iostream>
#include <string>
#include <vector>
using namespace std;

//* Link(original) - https://leetcode.com/problems/encode-and-decode-strings/
//* Link(alternate) - https://www.lintcode.com/problem/659/

string encode(vector<string> &strs) {
    string encoded_str = "";

    for (auto s : strs) {
        int len = s.length();
        encoded_str.append(to_string(len) + "#" + s);
    }

    return encoded_str;
}

vector<string> decode(string &str) {
    vector<string> decoded_vec;
    int i = 0;

    while (i < str.length()) {
        int j = i;
        while (str[j] != '#') j++;

        int len = stoi(str.substr(i, j - i));
        string word = str.substr(j + 1, len);
        decoded_vec.push_back(word);

        i = j + 1 + len;
    }

    return decoded_vec;
}

int main() {
    vector<string> s = {"lint", "code", "love", "you"};

    string encoded_str = encode(s);
    vector<string> decoded_vec = decode(encoded_str);

    cout << "Input   : [ ";
    for (auto i : s) cout << i << ", ";
    cout << "]\n";

    cout << "Encoded : " << encoded_str << endl;
    cout << "Decoded : [ ";
    for (auto i : decoded_vec) cout << i << ", ";
    cout << "]\n\n";

    return 0;
}