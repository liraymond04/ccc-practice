#include <bits/stdc++.h>

using namespace std;

int main() {
    int p = 29;
    long long q = pow(2, 43) - 1;

    // setbuf(stdout, 0);

    string needle, haystack;
    cin >> needle >> haystack;

    int n = needle.length(), m = haystack.length();

    long long precom = 1;
    for (int i=0; i<n-1; i++) {
        precom = (precom * p) % q;
    }

    vector<int> counting(26, 0), check(26, 0);
    for (int i=0; i<n; i++) {
        counting[needle[i]-'a']++;
        check[haystack[i]-'a']++;
    }

    long long hash = 0;
    for (int i=0; i<n; i++) {
        hash = (hash * p + haystack[i]) % q;
    }

    unordered_set<int> v;

    int start = 0, count = 0;
    while (start < m-n+1) {
        if (counting == check) {
            if (v.find(hash) == v.end()) {
                count++;
                v.insert(hash);
            }
        }
        if (start == m-n) break;
        check[haystack[start]-'a']--;
        check[haystack[start+n]-'a']++;
        hash = ((hash - haystack[start] * precom) * p + haystack[start+n]) % q;
        start++;
    }

    cout << count;

    return 0;
}