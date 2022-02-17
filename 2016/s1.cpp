#include <bits/stdc++.h>

using namespace std;

int main() {
    setbuf(stdout, 0);

    string s1, s2;
    cin >> s1 >> s2;

    map<char, int> counts;
    unordered_set<char> chars;
    bool anagram = false;
    int ast = 0;

    for (int i=0; i<s1.length(); i++) {
        counts[s1[i]]++;
        chars.insert(s1[i]);
    }
    for (int i=0; i<s2.length(); i++) {
        if (s2[i] == '*') {
            ast++;
            continue;
        }

        if (chars.find(s2[i]) == chars.end()) {
            cout << "N";
            return 0;
        }

        if (counts.find(s2[i]) == counts.end()) {
            continue;
        }
        counts[s2[i]]--;
        if (counts[s2[i]] == 0) {
            counts.erase(s2[i]);
        }
    }

    if (counts.size() == 0) {
        cout << "A";
        return 0;
    }

    int c = 0;
    for (pair<char, int> cur : counts) {
        c += cur.second;
    }

    if (c == ast) {
        cout << "A";
    } else {
        cout << "N";
    }

    return 0;
}