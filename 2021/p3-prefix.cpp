#include <bits/stdc++.h>

using namespace std;

struct Friend {
    int p, w, d;
};

bool cmp1(Friend a, Friend b) {
    return (a.p + a.d) < (b.p + b.d);
}

bool cmp2(Friend a, Friend b) {
    return (a.p - a.d) < (b.p - b.d);
}

int main() {
    // setbuf(stdout, 0);

    int n;
    cin >> n;

    vector<Friend> friends(n);
    vector<int> edges;

    for (int i=0; i<n; i++) {
        int p, w, d;
        cin >> p >> w >> d;
        friends[i] = {p, w, d};
        edges.push_back(p-d);
        edges.push_back(p+d);
    }

    sort(friends.begin(), friends.end(), cmp1);
    sort(edges.begin(), edges.end());

    vector<long long> left(n*2, 0);
    long long w_accum = 0, cur = 0;
    for (int i=1; i<n*2; i++) {
        while (cur < n && friends[cur].p + friends[cur].d < edges[i]) {
            w_accum += friends[cur].w;
            cur++;
        }
        left[i] = left[i-1] + w_accum * (edges[i] - edges[i-1]);
    }

    sort(friends.begin(), friends.end(), cmp2);
    
    vector<long long> right(n*2, 0);
    w_accum = 0; cur = n-1;
    for (int i=n*2-2; i>=0; i--) {
        while (cur >= 0 && friends[cur].p - friends[cur].d > edges[i]) {
            w_accum += friends[cur].w;
            cur--;
        }
        right[i] = right[i+1] + w_accum * (edges[i+1] - edges[i]);
    }

    long long ans = LONG_LONG_MAX;
    for (int i=0; i<n*2; i++) {
        ans = min(ans, left[i] + right[i]);
    }

    cout << ans;

    return 0;
}