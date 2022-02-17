#include <bits/stdc++.h>

using namespace std;

struct Friend {
    int p, w, d;
};

long long f(vector<Friend> &friends, int x) {
    long long ans = 0;
    for (Friend f : friends) {
        int dist = 0;
        if (f.p + f.d < x) {
            dist = x - (f.p + f.d);
        } else if (f.p - f.d > x) {
            dist = (f.p - f.d) - x;
        }
        ans += (long long)dist * f.w;
    }
    return ans;
}

int main() {
    // setbuf(stdout, 0);

    int n;
    cin >> n;

    vector<Friend> friends(n);

    int fmin = INT_MAX, fmax = 0;
    for (int i=0; i<n; i++) {
        int p, w, d;
        cin >> p >> w >> d;
        friends[i] = {p, w, d};
        fmin = min(fmin, p); fmax = max(fmax, p);
    }

    while (fmin < fmax) {
        int mid = (fmin + fmax) / 2;
        if (f(friends, mid) < f(friends, mid+1)) {
            fmax = mid;
        } else {
            fmin = mid + 1;
        }
    }

    cout << f(friends, fmin);

    return 0;
}