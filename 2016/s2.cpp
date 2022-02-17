#include <bits/stdc++.h>

using namespace std;

int main() {
    setbuf(stdout, 0);

    int q;
    cin >> q;

    int n;
    cin >> n;

    vector<int> d(n), p(n);
    for (int i=0; i<n; i++) {
        cin >> d[i];
    }
    for (int i=0; i<n; i++) {
        cin >> p[i];
    }

    sort(d.begin(), d.end());
    sort(p.begin(), p.end());

    if (q == 2) {
        reverse(p.begin(), p.end());
    }

    int ans = 0;
    for (int i=0; i<n; i++) {
        ans += max(d[i], p[i]);
    }

    cout << ans;

    return 0;
}