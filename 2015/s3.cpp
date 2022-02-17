#include <bits/stdc++.h>

using namespace std;

int main() {
    setbuf(stdout, 0);

    int g, p;
    cin >> g >> p;

    set<int> s;
    for (int i=1; i<=g; i++) {
        s.insert(i);
    }

    int ans = 0;

    for (int i=0; i<p; i++) {
        int n;
        cin >> n;

        // begin 1 end
        // 1
        // end

        if (s.empty()) {
            break;
        }

        set<int>::iterator num = s.lower_bound(n);
        if (num == s.end()) {
            num--;
            s.erase(num);
            ans++;
        } else if (*num == n) {
            s.erase(num);
            ans++;
        } else if (num != s.begin()) {
            num--;
            s.erase(num);
            ans++;
        } else {
            break;
        }
    }

    cout << ans;

    return 0;
}