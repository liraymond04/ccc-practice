#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    vector<string> p1;
    unordered_map<string, string> m;

    bool ans = true;
    cin >> n;
    for (int i=0; i<n; i++) {
        string input;
        cin >> input;
        p1.push_back(input);
    }
    for (int i=0; i<n; i++) {
        string input;
        cin >> input;
        if (m.find(input) != m.end()) {
            if (m[input] != p1[i]) { 
                ans = false;
                break;
            }
        } else {
            if (input == p1[i]) {
                ans = false;
                break;
            }
            m.insert({p1[i], input});
        }
    }

    if (ans) {
        cout << "good";
    } else {
        cout << "bad";
    }

    return 0;
}