#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 5;
int s[MAXN];

map<char, int> m = {
    {'S', 0},
    {'M', 1},
    {'L', 2}
};

int main() {
    setbuf(stdout, 0);
    
    int j, a;
    cin >> j >> a;

    char c;
    int n;
    for (int i=1; i<=j; i++) {
        cin >> c;
        s[i] = m[c];
    }

    int ans = 0;
    for (int i=0; i<a; i++) {
        cin >> c >> n;
        if (m[c] <= s[n]) {
            s[n] = -1;
            ans++;
        }
    }

    cout << ans;
    
    return 0;
}