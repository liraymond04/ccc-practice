#include <bits/stdc++.h>

using namespace std;

struct Station {
    int num, dist;
    friend bool operator < (const Station &a, const Station &b) {
        return a.dist > b.dist;
    }
};

vector<int> dijkstra(vector<vector<int> > &adj, int n) {
    vector<int> dist(n+1, n+1), visited(n+1, false);
    dist[n] = 0;

    priority_queue<Station> q;
    q.push({n, 0});

    while (!q.empty()) {
        Station cur = q.top();
        q.pop();

        if (visited[cur.num]) continue;
        visited[cur.num] = true;

        for (int c : adj[cur.num]) {
            if (visited[c]) continue;
            dist[c] = min(dist[cur.num] + 1, dist[c]);
            q.push({c, dist[c]});
        }
    }

    return dist;
}

int main() {
    // setbuf(stdout, 0);

    int n, w, d;
    cin >> n >> w >> d;

    vector<vector<int> > adj(n+1);
    for (int i=0; i<w; i++) {
        int a, b;
        cin >> a >> b;
        adj[b].push_back(a);
    }

    vector<int> dist = dijkstra(adj, n);

    multiset<int> times;
    vector<int> order(n+1);
    for (int i=1; i<=n; i++) {
        cin >> order[i];
        times.insert(i-1 + dist[order[i]]);
    }

    for (int i=0; i<d; i++) {
        int x, y;
        cin >> x >> y;
        times.erase(times.find(x-1 + dist[order[x]]));
        times.erase(times.find(y-1 + dist[order[y]]));
        times.insert(x-1 + dist[order[y]]);
        times.insert(y-1 + dist[order[x]]);
        swap(order[x], order[y]);
        cout << *times.begin() << "\n";
    }

    return 0;
}