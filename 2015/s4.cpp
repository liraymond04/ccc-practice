#include <bits/stdc++.h>

using namespace std;

int main() {
    long long k, n, m;
	cin >> k >> n >> m;

	vector<vector<pair<long long, pair<int, int> > > > adj;
	vector<pair<long long, long long> > path;

	for (int i=0; i<n; i++) {
		adj.push_back(vector<pair<long long, pair<int, int> > >());
		path.push_back({2147483647, 2147483647});
	}
	for (int i=0; i<m; i++) {
        long long p1, p2, t, h;
		cin >> p1 >> p2 >> t >> h;
        p1--; p2--;
		adj[p1].push_back({t, {p2, h}});
		adj[p2].push_back({t, {p1, h}});
	}

    long long a, b;
	cin >> a >> b;
    a--;
    b--;

	queue<pair<long long, pair<int, int > > > q;
	q.push({0, {a, 0}});
	long long cur = 2147483647;
	while (!q.empty()) {
		pair<long long, pair<int, int> > value = q.front();
        q.pop();

		long long t = value.first, v = value.second.first, h = value.second.second;

		if (t >= cur || h >= k) continue;
        
		if (path[v].first <= t && path[v].second <= h) {
            continue;
        } else if (path[v].first >= t) {
			path[v].first = t;
			path[v].second = h;
		}

		if (v == b) {
            cur = min(cur, t);
            continue;
        }

		for (pair<long long, pair<int, int> > c : adj[v]) {
			if (c.second.second + h >= k) continue;
			else if (c.first + t >= cur) continue;
			q.push({t + c.first, {c.second.first, c.second.second + h}});
		}
	}

	if (cur == 2147483647) {
        cout << -1 << "\n";
    } else {
        cout << cur << "\n";
    }

	return 0;
}